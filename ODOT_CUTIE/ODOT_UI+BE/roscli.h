
#ifndef HELLOCPP_H
#define HELLOCPP_H

#include <QObject>
#include <string.h>
#include <iostream>


class rosCLI : public QObject
{

Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString cam READ get_c NOTIFY cs_change)
    Q_PROPERTY(QString lidar READ get_l NOTIFY cs_change)
    Q_PROPERTY(QString gps READ get_g NOTIFY cs_change)
    Q_PROPERTY(QString cam_ip READ get_cip NOTIFY cs_change)
    Q_PROPERTY(QString last_bag_date READ get_lbd NOTIFY cs_change)
    Q_PROPERTY(QString curr_sens READ get_cs NOTIFY cs_change)
    Q_PROPERTY(QString last_bag_loc READ get_lbl NOTIFY cs_change)

//cam, lidar, gps, cam_ip, last_bag_date, curr_sens = "YES", last_bag_loc

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
public: QString cam, lidar, gps, cam_ip, last_bag_date, curr_sens, last_bag_loc;

    QString get_c() { return cam;}
    QString get_l() { return lidar;}
    QString get_g() { return gps;}
    QString get_cip() { return cam_ip;}
    QString get_lbd() { return last_bag_date;}
    QString get_cs() { return curr_sens;}
    QString get_lbl() { return last_bag_loc;}


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
Q_INVOKABLE void init();
Q_INVOKABLE void startSensors(QString txt);
Q_INVOKABLE void startRecord(QString txt);
Q_INVOKABLE void stopRecord(QString txt);
Q_INVOKABLE void pause_resume_Record(QString txt);
Q_INVOKABLE void setIP(QString txt);
Q_INVOKABLE void openRecordFiles(QString txt);
Q_INVOKABLE void deleteLastRecording(QString txt);

void set_name(char* name) { bag_name = name; }

signals:
    void textChanged(const QString & text);
    void cs_change();
private:
    QString mText;
    std::string bag_name;
public slots:

};

#endif
