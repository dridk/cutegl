#include "modelloader.h"
#include <QDebug>
#include <QRegularExpression>
namespace cgl {

//===================================================================
ModelLoader::ModelLoader(const QString &filename)
{

    load(filename);

}

//===================================================================
ModelLoader::ModelLoader()
{

}

//===================================================================
void ModelLoader::load(const QString &filename)
{
    mFile.setFileName(filename);

    mVertices.clear();

    mVData.clear();
    mVnData.clear();
    mVtData.clear();

    QRegularExpression vReg("^v\\s{1,5}");
    QRegularExpression vtReg("^vt\\s{1,5}");
    QRegularExpression vnReg("^vn\\s{1,5}");

    if (mFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&mFile);

        //------- Load All v,vn, vt data in temp list

        while (!stream.atEnd()) {

            QString line = stream.readLine();

            // Load Vertex position DATA
            if (vReg.match(line).hasMatch())
            {
                line = line.remove(vReg);
                QStringList split = line.split(" ");
                if (split.size() == 3) {
                    float x = split.at(0).toFloat();
                    float y = split.at(1).toFloat();
                    float z = split.at(2).toFloat();

                    mVData.append(QVector3D(x,y,z));
                }
            }
            // Load Texture position DATA
            if (vtReg.match(line).hasMatch())
            {
                line = line.remove(vtReg);

                QStringList split = line.split(" ");
                if (split.size() == 2) {
                    float tx = split.at(0).toFloat();
                    float ty = split.at(1).toFloat();
                    mVtData.append(QVector2D(tx,ty));
                }
            }

            // Load Normal position DATA
            if (vnReg.match(line).hasMatch())
            {
                line = line.remove(vnReg);
                QStringList split = line.split(" ");
                if (split.size() == 3) {
                    float nx = split.at(0).toFloat();
                    float ny = split.at(1).toFloat();
                    float nz = split.at(2).toFloat();
                    mVnData.append(QVector3D(nx,ny,nz));
                }
            }
        }


        qDebug()<<Q_FUNC_INFO<<"Coord count "<<mVData.size();
        qDebug()<<Q_FUNC_INFO<<"normal count "<<mVnData.size();
        qDebug()<<Q_FUNC_INFO<<"texture count "<<mVtData.size();



        //--------------------------------------------
        //------- Load All Face
        // Currenly load only face like  : index1 index2 index 4 ....


        stream.seek(0); // restart reading from the beginning

        QRegularExpression fullExp("^f(\\s\\d+/\\d+/\\d+){3}");
        QRegularExpression simpleExp("^f(\\s\\d+){3,5}");
        QRegularExpression noTextExp("^f(\\s\\d+//\\d+){3,5}");


        while (!stream.atEnd()) {

            QString line = stream.readLine();
            if (line.startsWith("f"))
            {

                //------ For simple definition f1 f2 f3----------
                if (simpleExp.match(line).hasMatch()){
                    //remove f caracater + space
                    line = line.remove(0,2);
                    foreach (QString n, line.split(" "))
                    {
                        int faceIndex = n.toInt();
                        mVertices.append(mVData.at(faceIndex-1));
                    }
                }

                // -------For complexe f1/t1/n1 f2/t2/n2----------
                if (fullExp.match(line).hasMatch()){
                    //remove f caracater + space
                    line = line.remove(0,2);
                    foreach (QString n, line.split(" "))
                    {
                        QStringList sub = n.split("/");
                        if (sub.size() == 3)
                        {
                            int vindex =  sub.at(0).toInt();
                            int vtindex = sub.at(1).toInt();
                            int vnindex = sub.at(2).toInt();

                            QVector3D coord   = mVData.at(vindex-1);
                            QVector2D texture = mVtData.at(vtindex-1);
                            QVector3D normal  = mVnData.at(vnindex-1);
                            Vertex vertex(coord, texture, normal);
                            vertex.setColor(Qt::red);
                            mVertices.append(vertex);
                        }
                    }
                }
                // -------No texture  f1//n1 f2//n2----------
                if (noTextExp.match(line).hasMatch()){

                    //remove f caracater + space
                    line = line.remove(0,2);


                    foreach (QString n, line.split(" "))
                    {
                        QStringList sub = n.split("//");

                        if (sub.size() == 2)
                        {
                            int vindex =  sub.at(0).toInt() - 1;
                            int vnindex = sub.at(1).toInt() - 1;

                            QVector3D coord   = mVData.at(vindex);
                            QVector3D normal  = mVnData.at(vnindex);
                            Vertex vertex;
                            vertex.setPos(coord);
                            vertex.setNormal(normal);
                            mVertices.append(vertex);
                        }
                    }
                }
            }
        }
    }
}

}


