
#ifndef HELLOCPP_H
#define HELLOCPP_H

#include <QObject>

class rosCLI : public QObject
{
Q_OBJECT
public:

/*************************************************************************/
/************************** HARD WIRED PATH VARS  ************************/

    char* ss_path            = "../config/startSensors.launch";
    char* ss_packageName     = "ODOT";

    /*char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";
    char* ss_path = "";*/

/*************************************************************************/

explicit rosCLI(QObject *parent = 0);
Q_INVOKABLE void startSensors(QString txt);
Q_INVOKABLE void startRecord(QString txt);
Q_INVOKABLE void startRecord_NAMED(QString txt);
Q_INVOKABLE void stopRecord(QString txt);
Q_INVOKABLE void pauseRecord(QString txt);
Q_INVOKABLE void setIP_CAMERA(QString txt);
Q_INVOKABLE void openRecordFiles(QString txt);
Q_INVOKABLE void deleteLastRecording(QString txt);


signals:

public slots:

};

#endif
