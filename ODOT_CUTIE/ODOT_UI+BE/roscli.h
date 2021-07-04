
#ifndef HELLOCPP_H
#define HELLOCPP_H

#include <QObject>
#include <string.h>
#include <iostream>


class rosCLI : public QObject
{

Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:

    int flip = 1;

    QString text() const{
        return mText;
    }

    std::string get_name () const {
        QByteArray ba = mText.toLocal8Bit();
        char* buf = ba.data();
        std::string bag_name (buf);
        return bag_name;
    }

    void setText(const QString &text){
        if(text == mText)
            return;
        mText = text;
        emit textChanged(mText);
    }

    bool recording = false;

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
Q_INVOKABLE void stopRecord(QString txt);
Q_INVOKABLE void pause_resume_Record(QString txt);
Q_INVOKABLE void setIP_CAMERA(QString txt);
Q_INVOKABLE void openRecordFiles(QString txt);
Q_INVOKABLE void deleteLastRecording(QString txt);

void set_name(char* name) { bag_name = name; }

signals:
    void textChanged(const QString & text);
private:
    QString mText;
    std::string bag_name;
public slots:

};

#endif
