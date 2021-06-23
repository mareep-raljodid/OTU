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

    QByteArray ba = txt.toLocal8Bit();
    set_name(ba.data());
    char buffer[1025];
    if ((bag_name = "") || (bag_name == NULL)){
        snprintf (buffer, 1025, "cd /recordings; mkdir /recordings/latest; mv /recordings/latest/* /recordings/older/.; cd /recordings/latest; rosbag record -a &");
        system (buffer);
    }

    else {
        snprintf (buffer, 1025, "cd /recordings; mkdir /recordings/%s; mv /recordings/latest/* /recordings/older/.; cd /recordings/%s; rosbag record -a &", bag_name, bag_name);
        system (buffer);
    }
    recording = true;
    qDebug() << "Successful: " << buffer;
}

void rosCLI::stopRecord(QString txt) {

    char buffer[1025] = "rosnode kill -a";
    system (buffer);

    recording = false;

    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::resumeRecord(QString txt) {

    char buffer[1025];
    snprintf (buffer, 1025, "cd /recordings/%s; rosbag record -a &", bag_name);
    system (buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::pauseRecord(QString txt) {

    char buffer[1025] = "rosnode kill -a";
    system (buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::setIP_CAMERA(QString txt) {
//UMP
    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::openRecordFiles(QString txt) {

    char buffer[1025];
    snprintf ( buffer, 1025, "cd /recordings/%s; nautilus .", bag_name);
    system(buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::deleteLastRecording(QString txt) {

    char buffer[1025];
    if ((bag_name != "") || (bag_name != NULL))
        snprintf ( buffer, 1025, "rm -rf /recordings/%s", bag_name);
    else
         snprintf ( buffer, 1025, "rm -rf /recordings/latest", bag_name);

    system(buffer);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}
