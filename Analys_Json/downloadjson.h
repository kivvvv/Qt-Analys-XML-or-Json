#ifndef DOWNLOADJSON_H
#define DOWNLOADJSON_H
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

#include <QSysInfo>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <cstdlib>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <iostream>
using namespace std;


struct Geometry{

    double Coordinates[5][2];
    QString Type;

};

struct Feature_list{

    QString Helipad;
};

struct Type_top{

    struct Feature_list feature_list;
    double Match;
    QString Name;

};
struct Properties{
    double Angle;
    double landmarks[30][2];
    double Length;
    QString old_type;
    double Score;
    QString sub_objects;
    QString type;
    double type_list[10];
    struct Type_top type_top[5];
    double width;
};


struct Features{
    struct Geometry geometry;
    struct Properties properties;
    QString Type;
};



class DownloadJson
{
public:
    DownloadJson();

    void ReadJson();

};

#endif // DOWNLOADJSON_H
