#include "roscli.h"

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <fstream>
#include <string>
#include <streambuf>
#include <chrono>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

/*cam, lidar, gps, cam_ip, last_bag_date, curr_sens, last_bag_loc;*/
void rosCLI::init() {
    system ("mkdir recordings; mkdir config");
    //cam read from file
    std::ifstream camIp_str("config/cam_ip.odot");
    std::string cam_ip_buf((std::istreambuf_iterator<char>(camIp_str)),
                     std::istreambuf_iterator<char>());
    cam_ip = cam_ip_buf.c_str();
    qDebug() << "CAMMMMM PIPIP: "<< cam_ip;
    system ("cat config/cam_ip.odot");

    //last bag deets read from file
    std::ifstream lb_date_str("/config/bag_time.odot");
    std::string lb_date_buf((std::istreambuf_iterator<char>(lb_date_str)),
                     std::istreambuf_iterator<char>());
    last_bag_date = lb_date_buf.c_str();


    std::ifstream lb_loc_str("/config/bag_loc.odot");
    std::string lb_loc_buf((std::istreambuf_iterator<char>(lb_loc_str)),
                     std::istreambuf_iterator<char>());
    last_bag_loc = lb_loc_buf.c_str();

    std::ifstream lb_dat_str("time.odot");
    std::string lbd((std::istreambuf_iterator<char>(lb_dat_str)),
                     std::istreambuf_iterator<char>());
    last_bag_date = lbd.c_str();

    // #FIXME DO ROS CHECK
    bool stat_cam = true;
    bool stat_lidar = true;
    bool stat_gps = true;

    if(stat_cam) cam = "Valid";
    else cam = "invalid";

    if(stat_lidar) lidar = "Valid";
    else lidar = "invalid";

    if(stat_gps) gps = "Valid";
    else gps = "invalid";


    if (stat_cam && stat_gps && stat_lidar) curr_sens = "UP and RUNNING";
    else curr_sens = "Sensor Issue";

    char buff[1025];
    snprintf (buff, 1025, "recordings/%s", bag_name.c_str());
    last_bag_loc = buff;

    emit cs_change();
}


using namespace std;
#include <time.h>
#include <stdio.h>

string time()
{
    time_t _tm =time(NULL );

    struct tm * curtime = localtime ( &_tm );
    return asctime(curtime);
}

rosCLI::rosCLI(QObject *parent) :
QObject(parent) {}

void rosCLI::startSensors(QString txt) {

    this->init();

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
    system(buffer);
}

void rosCLI::startRecord(QString txt) {

    char buffer[1025];

        bag_name = get_name();
        snprintf (buffer, 1025, "cd recordings; mkdir recordings/%s; mv recordings/latest/* recordings/older/.; cd recordings/%s; rosbag record -a &", bag_name.c_str(), bag_name.c_str());
        system (buffer);

    recording = true;
    qDebug() << "Successful: " << buffer;
    qDebug() << "Successful: " << txt;
    this->init();

}

void rosCLI::stopRecord(QString txt) {

    char buffer[1025] = "rosnode kill -a";
    system (buffer);

    recording = false;


    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
#include <string.h>
    std::time_t ct = std::time(0);
    char* cc = ctime(&ct);
    cc[strlen(cc)-1] = '\0';


    char buf[1000];
    //buf[strlen(buf)] = ' ';
    last_bag_date = cc;
    snprintf (buf, 1000, "rm -rf time.odot; echo %s >> time.odot", cc);
    qDebug() << buf;
    system(buf);
    this->init();
}

void rosCLI::pause_resume_Record(QString txt) {

    if (flip == (-1)) {
    //resume
        char buffer[1025];
        startSensors(txt);
        snprintf (buffer, 1, "cd recordings/%s; rosbag record -a &", bag_name.c_str());
        system (buffer);
        qDebug() << "[RESUME] Successful: " << txt << " | CMD: " << buffer;
        flip *= (-1);
    }

    if (flip == 1) {
    //pause
        char Pbuffer[1025] = "rosnode kill -a";
        system (Pbuffer);
        qDebug() << "[PAUSE] Successful: " << txt << " | CMD: " << Pbuffer;
        flip *= (-1);
    }
}

void rosCLI::setIP(QString txt) {

    QByteArray ba = txt.toLocal8Bit();
    char* buf = ba.data();
    std::string ip (buf);

    char buffer[1025];
    snprintf( buffer, 1025, "rm config/cam_ip.odot; echo \"%s\"  >> config/cam_ip.odot", ip.c_str());
    system(buffer);
    qDebug() << "Successful: [IP] " << buffer;
    cam_ip = ip.c_str();
    this->init();
}

void rosCLI::openRecordFiles(QString txt) {

    char buffer[1025];
    snprintf ( buffer, 1025, "cd recordings/%s; nautilus .", bag_name.c_str());
    system(buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::deleteLastRecording(QString txt) {

    char buffer[1025];

    snprintf ( buffer, 1025, "rm -rf recordings/%s", bag_name.c_str());
    system(buffer);

    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}
