#include "roscli.h"

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

rosCLI::rosCLI(QObject *parent) :
QObject(parent) {}

void rosCLI::startSensors(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
    system(buffer);
}

void rosCLI::startRecord(QString txt) {

    char buffer[1025];

        bag_name = get_name();
        snprintf (buffer, 1025, "cd /recordings; mkdir /recordings/%s; mv /recordings/latest/* /recordings/older/.; cd /recordings/%s; rosbag record -a &", bag_name.c_str(), bag_name.c_str());
        system (buffer);

    recording = true;
    qDebug() << "Successful: " << buffer;
    qDebug() << "Successful: " << txt;
}

void rosCLI::stopRecord(QString txt) {

    char buffer[1025] = "rosnode kill -a";
    system (buffer);

    recording = false;

    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::pause_resume_Record(QString txt) {

    if (flip == (-1)) {
    //resume
        char buffer[1025];
        startSensors(txt);
        snprintf (buffer, 1025, "cd /recordings/%s; rosbag record -a &", bag_name.c_str());
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

void rosCLI::setIP_CAMERA(QString txt) {
//UMP
    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::openRecordFiles(QString txt) {

    char buffer[1025];
    snprintf ( buffer, 1025, "cd /recordings/%s; nautilus .", bag_name.c_str());
    system(buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::deleteLastRecording(QString txt) {

    char buffer[1025];

    snprintf ( buffer, 1025, "rm -rf /recordings/%s", bag_name.c_str());
    system(buffer);

    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}
