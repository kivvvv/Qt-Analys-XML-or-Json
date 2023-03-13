#include "downloadjson.h"

DownloadJson::DownloadJson()
{

}


void DownloadJson::ReadJson(){

    struct Features features[15];


    QFile file( QDir::homePath() + "/Desktop/gf2-hxh-clip.json" );
    if ( !file.open( QIODevice::ReadWrite ) ) {
        qDebug() << "文件打开失败!\n";
        exit( 1 );
    }
    qDebug() << "文件打开成功\n";

    QJsonParseError jsonParserError;
    QJsonDocument   jsonDocument =
        QJsonDocument::fromJson( file.readAll(), &jsonParserError );

    if ( !jsonDocument.isNull() && jsonParserError.error == QJsonParseError::NoError ) {
        qDebug() << "文件解析成功\n";
        QJsonObject jsonObject=jsonDocument.object();
        if(jsonObject.contains("features") && jsonObject.value("features").isArray()){
            QJsonArray jsonArray01=jsonObject.value("features").toArray();

            for(int i=0;i<jsonArray01.size();i++){

                qDebug() << "features["<<i<<"]:";

                if (jsonArray01[i].isObject()){

                    QJsonObject jsonObjectFeatures=jsonArray01[i].toObject();

                    if(jsonObjectFeatures.contains("geometry")){

                        QJsonObject jsonObjectGeometry=jsonObjectFeatures.value("geometry").toObject();

                        qDebug() << "  geometry:";

                        if(jsonObjectGeometry.contains("coordinates") && jsonObjectGeometry.value("coordinates").isArray()){

                            QJsonArray jsonArray02=jsonObjectGeometry.value("coordinates").toArray();

                            qDebug() << "    coordinates:";

                            for(int j=0;j<jsonArray02.size();j++){

                                features[i].geometry.Coordinates[j][0]=jsonArray02[j][0].toDouble();
                                features[i].geometry.Coordinates[j][1]=jsonArray02[j][1].toDouble();


                                qDebug() << "    coordinates["<<j<<"]:";
                                qDebug()<<"      "<< features[i].geometry.Coordinates[j][0];
                                qDebug()<<"      "<< features[i].geometry.Coordinates[j][1];


                            }
                        }
                        if(jsonObjectGeometry.contains("type")&&jsonObjectGeometry.value( "type" ).isString()){

                            features[i].geometry.Type = jsonObjectGeometry.value( "type" ).toString();
                            qDebug() << "    type:" << features[i].geometry.Type;

                        }

                    }

                    if(jsonObjectFeatures.contains("properties")){//财产，所有权

                        QJsonObject jsonObjectProperties=jsonObjectFeatures.value("properties").toObject();

                        qDebug() << "  properties:";

                        if(jsonObjectProperties.contains("angle") && jsonObjectProperties.value("angle").isDouble()){

                            features[i].properties.Angle=jsonObjectProperties.value( "angle" ).toDouble();

                             qDebug() << "    angle:" << features[i].properties.Angle;

                        }

                        if(jsonObjectProperties.contains("landmarks") && jsonObjectProperties.value("landmarks").isArray()){

                            QJsonArray jsonArray03=jsonObjectProperties.value("landmarks").toArray();
                            for(int j=0;j<jsonArray03.size();j++){

                                features[i].properties.landmarks[j][0]=jsonArray03[j][0].toDouble();
                                features[i].properties.landmarks[j][1]=jsonArray03[j][1].toDouble();


                                qDebug() << "    landmarks["<<j<<"]:";
                                qDebug()<<"      "<< features[i].properties.landmarks[j][0];
                                qDebug()<<"      "<< features[i].properties.landmarks[j][1];

                            }
                        }
                        if(jsonObjectProperties.contains("length") && jsonObjectProperties.value("length").isDouble()){

                            features[i].properties.Length=jsonObjectProperties.value( "length" ).toDouble();


                            qDebug() << "    length:" << features[i].properties.Length;

                        }

                        if(jsonObjectProperties.contains("old_type")&&jsonObjectProperties.value( "old_type" ).isString()){

                            features[i].properties.old_type=jsonObjectProperties.value( "old_type" ).toString();

                            qDebug() << "    old_type:" << features[i].properties.old_type;

                        }

                        if(jsonObjectProperties.contains("score") && jsonObjectProperties.value("score").isDouble()){


                            features[i].properties.Score=jsonObjectProperties.value( "score" ).toDouble();

                            qDebug() << "    score:" << features[i].properties.Score;


                        }

                        if(jsonObjectProperties.contains("sub_objects") ){

                            QJsonValue value = jsonObjectProperties.value("sub_objects");

                            if(QJsonValue(value).isNull()){

                                qDebug() << "    sub_objects:null";

                            }
                            else{
                                features[i].properties.sub_objects=jsonObjectProperties.value( "sub_objects" ).toString();
                                qDebug() << "    sub_objects:" << features[i].properties.sub_objects;

                            }

                        }

                        if(jsonObjectProperties.contains("type")&&jsonObjectProperties.value( "type" ).isString()){

                            features[i].properties.type=jsonObjectProperties.value( "type" ).toString();

                            qDebug() << "    type:" << features[i].properties.type;

                        }

                        if(jsonObjectProperties.contains("type_list") && jsonObjectProperties.value("type_list").isArray()){
                            qDebug() << "    type_list:";

                            QJsonArray jsonArray_type_list=jsonObjectProperties.value("type_list").toArray();

                            for(int j_type_list=0;j_type_list<jsonArray_type_list.size();j_type_list++){

                                if ( jsonArray_type_list[ j_type_list ].isObject()){



                                    QJsonObject jsonObjectType_list = jsonArray_type_list[j_type_list].toObject();

                                    if(jsonObjectType_list.contains("ship_CG,ship_DDG,ship_LCS,ship_FF") &&
                                            jsonObjectType_list.value("ship_CG,ship_DDG,ship_LCS,ship_FF").isDouble()){
                                        features[i].properties.type_list[0]=
                                                jsonObjectType_list.value( "ship_CG,ship_DDG,ship_LCS,ship_FF" ).toDouble();


                                        qDebug() << "      ship_CG,ship_DDG,ship_LCS,ship_FF:" << features[i].properties.type_list[j_type_list];

                                    }
                                    if(jsonObjectType_list.contains("ship_LSD") &&
                                            jsonObjectType_list.value("ship_LSD").isDouble()){

                                        features[i].properties.type_list[1]=
                                                jsonObjectType_list.value( "ship_LSD" ).toDouble();

                                        qDebug() << "      ship_LSD:" << features[i].properties.type_list[1];

                                    }
                                    if(jsonObjectType_list.contains("ship") &&
                                            jsonObjectType_list.value("ship").isDouble()){

                                        features[i].properties.type_list[2]=
                                                jsonObjectType_list.value( "ship" ).toDouble();

                                        qDebug() << "      ship:" <<  features[i].properties.type_list[2];

                                    }
                                    if(jsonObjectType_list.contains("ship_AO") &&
                                            jsonObjectType_list.value("ship_AO").isDouble()){

                                        features[i].properties.type_list[3]=
                                                jsonObjectType_list.value( "ship_AO" ).toDouble();

                                        qDebug() << "      ship_AO:" << features[i].properties.type_list[3];
                                    }
                                    if(jsonObjectType_list.contains("ship_B") &&
                                            jsonObjectType_list.value("ship_B").isDouble()){

                                        features[i].properties.type_list[4]=
                                                jsonObjectType_list.value( "ship_B" ).toDouble();

                                        qDebug() << "      ship_B:" << features[i].properties.type_list[4];

                                    }
                                    if(jsonObjectType_list.contains("ship_SS") &&
                                            jsonObjectType_list.value("ship_SS").isDouble()){

                                        features[i].properties.type_list[5]=
                                                jsonObjectType_list.value( "ship_SS" ).toDouble();

                                        qDebug() << "      ship_SS:" << features[i].properties.type_list[5];

                                    }
                                    if(jsonObjectType_list.contains("ship_HS") &&
                                            jsonObjectType_list.value("ship_HS").isDouble()){

                                        features[i].properties.type_list[6]=
                                                jsonObjectType_list.value( "ship_HS" ).toDouble();

                                        qDebug() << "      ship_HS:" << features[i].properties.type_list[6];


                                    }
                                    if(jsonObjectType_list.contains("ship_CV") &&
                                            jsonObjectType_list.value("ship_CV").isDouble()){

                                        features[i].properties.type_list[7]=
                                                jsonObjectType_list.value( "ship_CV" ).toDouble();

                                        qDebug() << "      ship_CV:" << features[i].properties.type_list[7];

                                    }
                                    if(jsonObjectType_list.contains("ship_CS") &&
                                            jsonObjectType_list.value("ship_CS").isDouble()){

                                        features[i].properties.type_list[8]=
                                                jsonObjectType_list.value( "ship_CS" ).toDouble();

                                        qDebug() << "      ship_CS:" << features[i].properties.type_list[8];

                                    }
                                    if(jsonObjectType_list.contains("ship_LHA") &&
                                            jsonObjectType_list.value("ship_LHA").isDouble()){

                                        features[i].properties.type_list[9]=
                                                jsonObjectType_list.value( "ship_LHA" ).toDouble();

                                        qDebug() << "      ship_LHA:" << features[i].properties.type_list[9];

                                    }

                                }

                            }


                            if(jsonObjectProperties.contains("type_top") && jsonObjectProperties.value("type_top").isArray()){
                                qDebug() << "    type_top:" ;

                                QJsonArray jsonArray_type_top=jsonObjectProperties.value("type_top").toArray();

                                for(int j_type_top=0;j_type_top<jsonArray_type_top.size();j_type_top++){

                                    qDebug()<<"      {";

                                    if ( jsonArray_type_top[ j_type_top ].isObject()){


                                        QJsonObject jsonObjectType_top = jsonArray_type_top[j_type_top].toObject();

                                        if(jsonObjectType_top.contains("feature_list")&&jsonObjectType_top.value("feature_list").isObject()){

                                            qDebug() << "      feature_list:";
                                            QJsonObject jsonObjectFeature_list = jsonObjectType_top.value("feature_list").toObject();
                                            if(jsonObjectFeature_list.contains("helipad")&&jsonObjectFeature_list.value("helipad").isString()){

                                                features[i].properties.type_top[j_type_top].feature_list.Helipad=
                                                        jsonObjectFeature_list.value( "helipad" ).toString();

                                                qDebug() << "        helipad:" << features[i].properties.type_top[j_type_top].feature_list.Helipad;


                                            }

                                        }
                                        if(jsonObjectType_top.contains("match")&&jsonObjectType_top.value("match").isDouble()){\

                                            features[i].properties.type_top[j_type_top].Match=jsonObjectType_top.value( "match" ).toDouble();

                                            qDebug() << "      match:" << features[i].properties.type_top[j_type_top].Match;

                                        }

                                        if(jsonObjectType_top.contains("name")&&jsonObjectType_top.value("name").isString()){

                                            features[i].properties.type_top[j_type_top].Name=jsonObjectType_top.value( "name" ).toString();

                                            qDebug() << "      name:" << features[i].properties.type_top[j_type_top].Name;

                                        }
                                    }

                                    qDebug()<<"      }";
                                }

                           }

                            if(jsonObjectProperties.contains("width") && jsonObjectProperties.value("width").isDouble()){

                                features[i].properties.width=jsonObjectProperties.value( "width" ).toDouble();

                                qDebug() << "    width:" << features[i].properties.width;

                            }



                        }



                    }


                    if(jsonObjectFeatures.contains("type")&&jsonObjectFeatures.value("type").isString()){

                        features[i].Type=jsonObjectFeatures.value("type").toString();

                        qDebug() << "  type:"<<features[i].Type;

                    }

                }

            }
        }


    }

    //qDebug() << "sdad"<<features[9].geometry.Coordinates[0][0];

    file.close();
    qDebug() << "按任意键退出程序\n";

    return;

}
