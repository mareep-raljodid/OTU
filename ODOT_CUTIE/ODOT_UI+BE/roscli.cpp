#include "roscli.h"
#include <QDebug>

rosCLI::rosCLI(QObject *parent) :
QObject(parent) {}

void rosCLI::startSensors(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
    system(buffer);
}

void rosCLI::startRecord(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::startRecord_NAMED(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::stopRecord(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::pauseRecord(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::setIP_CAMERA(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::openRecordFiles(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}

void rosCLI::deleteLastRecording(QString txt) {

    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", ss_packageName, ss_path);
    qDebug() << "Successful: " << txt << " | CMD: " << buffer;
}
