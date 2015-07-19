#include "modelloader.h"
#include <QDebug>
#include <QRegularExpression>
namespace cgl {
ModelLoader::ModelLoader(const QString &filename)
{

    load(filename);

}

ModelLoader::ModelLoader()
{

}

void ModelLoader::load(const QString &filename)
{
    mFile.setFileName(filename);

    QList<QVector3D> vData;  // vertex Data
    QList<QVector2D> vtData; // texture Data
    QList<QVector3D> vnData; // Normal Data



    if (mFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&mFile);

        //------- Load All v,vn, vt data in temp list

        while (!stream.atEnd()) {

            QString line = stream.readLine();

            // Load Vertex position DATA
            if (line.startsWith("v "))
            {
                QStringList split = line.split(" ");
                if (split.size() == 4) {
                    float x = split.at(1).toFloat();
                    float y = split.at(2).toFloat();
                    float z = split.at(3).toFloat();
                    vData.append(QVector3D(x,y,z));
                }
            }
            // Load Texture position DATA
            if (line.startsWith("vt "))
            {
                QStringList split = line.split(" ");
                if (split.size() == 3) {
                    float tx = split.at(1).toFloat();
                    float ty = split.at(2).toFloat();
                    vtData.append(QVector2D(tx,ty));
                }
            }

            // Load Normal position DATA
            if (line.startsWith("vn "))
            {
                QStringList split = line.split(" ");
                if (split.size() == 4) {
                    float nx = split.at(1).toFloat();
                    float ny = split.at(2).toFloat();
                    float nz = split.at(3).toFloat();
                    vnData.append(QVector3D(nx,ny,nz));
                }
            }
        }


        qDebug()<<"Coord count "<<vData.size();
        qDebug()<<"normal count "<<vnData.size();
        qDebug()<<"texture count "<<vtData.size();


        //--------------------------------------------
        //------- Load All Face
        // Currenly load only face like  : index1 index2 index 4 ....

        mVertices.clear();

        stream.seek(0); // restart reading from the beginning

        QRegularExpression full("^f(\\s\\d+/\\d+/\\d+){3}");
        QRegularExpression simple("^f(\\s\\d+){3,5}");


        while (!stream.atEnd()) {

            QString line = stream.readLine();
            if (line.startsWith("f "))
            {

                // For simple definition f1 f2 f3
               if (simple.match(line).hasMatch()){
                   QStringList split = line.split(" ");
                   //remove f caracater + space
                   line = line.remove(0,2);
                   foreach (QString n, line.split(" "))
                   {
                       int faceIndex = n.toInt();
                       mVertices.append(vData.at(faceIndex-1));
                   }
               }

               // For complexe f1/t1/n1 f2/t2/n2
               if (full.match(line).hasMatch()){
                   qDebug()<<line;
                   QStringList split = line.split(" ");
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

                          QVector3D coord   = vData.at(vindex-1);
                          QVector3D normal  = vnData.at(vnindex-1);
                          QVector2D texture = vtData.at(vtindex-1);


                          mVertices.append(Vertex(coord, normal, texture, Qt::red));


                      }
                   }
               }

            }
        }
    }

}

const QVector<Vertex> &ModelLoader::vertices() const
{
   return mVertices;
}


} // End namespace
