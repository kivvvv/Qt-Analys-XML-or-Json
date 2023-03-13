#include "analysxml.h"

AnalysXml::AnalysXml()
{

}

void AnalysXml::ReadXml(){

    struct DBASetting dbasetting;

    QFile file("C:/Users/kiWi/Desktop/12.xml"); //所在文件相对路径、绝对路径、资源路径都行

    if(!file.open(QFile::ReadOnly)){

        qDebug()<<"打开失败";
        return ;


    }else{
        qDebug()<<"打开成功";
    }

    QDomDocument doc;

    if(!doc.setContent(&file))
    {
        file.close();

        qDebug()<<"XML文件格式错误，应为UTF-8文件";

        return;
    }
    file.close();

    //获取第一个节点,即DBASetting节点
    QDomElement DBASetting = doc.documentElement();

    qDebug()<<DBASetting.nodeName();

    //DBASetting下的第一个子节点，即为Version节点或者Root节点
    QDomNode firstNode = DBASetting.firstChild();

    while (!firstNode.isNull()){

        QDomElement element=firstNode.toElement();

        if (!element.isNull())
        {
            qDebug()<<"  "<<element.tagName();        //Version或者ROOT

            if(element.tagName()=="Version"){

                dbasetting.Version=element.text().toDouble();

                qDebug()<<"    "<<dbasetting.Version;
                //qDebug()<<"    "<<element.text().toDouble();

            }
            else if(element.tagName()=="ROOT"){

                //qDebug()<<element.tagName();  //ROOT

                QDomNode FireRange = firstNode.firstChild();//FireRange节点
                QDomElement element_firerange=FireRange.toElement();

                QDomNodeList nodeList = firstNode.childNodes();//FireRang节点的个数

                //qDebug()<<nodeList.size();

                for(int i=0;i<nodeList.size();i++){

                    if(element_firerange.tagName()=="FireRange"){

                        qDebug()<<"    "<<element_firerange.tagName();  //FireRange

                        QDomNode RangeNode = element_firerange.firstChild();//Range或者Center节点

                        while(!RangeNode.isNull()){

                            QDomElement element_rangenode=RangeNode.toElement();

                            qDebug()<<"      "<<element_rangenode.tagName(); //Range或者center

                            if(element_rangenode.tagName()=="Range"){

                                //获取range对应的所有文本
                                QString str1 = element_rangenode.text();

                                //对文本数据进行提取
                                QString upper_left = str1.section(";",0,0); //左上
                                QString lower_left = str1.section(";",1,1); //左下
                                QString lower_right = str1.section(";",2,2); //右下
                                QString upper_right = str1.section(";",3,3); //右上

                                QString upper_left_x = upper_left.section(",",0,0); //左上X坐标
                                QString upper_left_y = upper_left.section(",",1,1); //左上Y坐标
                                double UL_x = upper_left_x.trimmed().toDouble();
                                double UL_y = upper_left_y.trimmed().toDouble();
                                dbasetting.root.firerange[i].Range[0][0]=UL_x;
                                dbasetting.root.firerange[i].Range[0][1]=UL_y;

                                QString lower_left_x = lower_left.section(",",0,0); //左下X坐标
                                QString lower_left_y = lower_left.section(",",1,1); //左下Y坐标
                                double LL_x = lower_left_x.trimmed().toDouble();
                                double LL_y = lower_left_y.trimmed().toDouble();
                                dbasetting.root.firerange[i].Range[1][0]=LL_x;
                                dbasetting.root.firerange[i].Range[1][1]=LL_y;

                                QString lower_right_x = lower_right.section(",",0,0); //右下X坐标
                                QString lower_right_y = lower_right.section(",",1,1); //右下Y坐标
                                double LR_x = lower_right_x.trimmed().toDouble();
                                double LR_y = lower_right_y.trimmed().toDouble();
                                dbasetting.root.firerange[i].Range[2][0]=LR_x;
                                dbasetting.root.firerange[i].Range[2][1]=LR_y;

                                QString upper_right_x = upper_right.section(",",0,0); //右上X坐标
                                QString upper_right_y = upper_right.section(",",1,1); //右上Y坐标
                                double UR_x = upper_right_x.trimmed().toDouble();
                                double UR_y = upper_right_y.trimmed().toDouble();
                                dbasetting.root.firerange[i].Range[3][0]=UR_x;
                                dbasetting.root.firerange[i].Range[3][1]=UR_y;

                                qDebug()<<"        "<<dbasetting.root.firerange[i].Range[0][0]<<","<<dbasetting.root.firerange[i].Range[0][1];
                                //qDebug()<<"        "<<UL_x<<","<<UL_y;

                                qDebug()<<"        "<<dbasetting.root.firerange[i].Range[1][0]<<","<<dbasetting.root.firerange[i].Range[1][1];
                                //qDebug()<<"        "<<LL_x<<","<<LL_y;

                                qDebug()<<"        "<<dbasetting.root.firerange[i].Range[2][0]<<","<<dbasetting.root.firerange[i].Range[2][1];
                                //qDebug()<<"        "<<LR_x<<","<<LR_y;

                                qDebug()<<"        "<<dbasetting.root.firerange[i].Range[3][0]<<","<<dbasetting.root.firerange[i].Range[3][1];
                                //qDebug()<<"        "<<UR_x<<","<<UR_y;


                            }else if(element_rangenode.tagName()=="Center"){


                                //获取Center文本String
                                QString str1 = element_rangenode.text();


                                //对文本数据进行提取
                                QString pre = str1.section(",",0,0);
                                QString after = str1.section(",",1,1);

                                double x = pre.trimmed().toDouble();
                                double y = after.trimmed().toDouble();

                                dbasetting.root.firerange[i].Center[0]=x;
                                dbasetting.root.firerange[i].Center[1]=y;

                                qDebug() <<"        "<<dbasetting.root.firerange[i].Center[0] ;
                                //qDebug() <<"        "<< x;

                                qDebug() <<"        "<<dbasetting.root.firerange[i].Center[1] ;
                                //qDebug() <<"        "<< y;


                                //qDebug()<<s;

                            }

                            RangeNode=RangeNode.nextSibling();

                        }

                    }

                }

            }

        }


        firstNode = firstNode.nextSibling();
    }

}
