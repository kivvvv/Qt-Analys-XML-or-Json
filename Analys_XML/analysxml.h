#ifndef ANALYSXML_H
#define ANALYSXML_H


#include <QDir>
#include <QFile>


#include <QStringList>
#include <QDomNode>
#include <QDomNodeList>
#include <QDomDocument>
#include <QDomElement>
#include <QTextCodec>
#include <QDir>


#include <QFile>
#include <QTextStream>
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

struct FireRange{

    double Range[4][2];
    double Center[2];

};


struct ROOT{

    struct FireRange firerange[5];

};



struct DBASetting{

    double Version;

    struct ROOT root;

};

class AnalysXml
{
public:
    AnalysXml();

    void ReadXml();
};

#endif // ANALYSXML_H
