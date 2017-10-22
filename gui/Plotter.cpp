#include "Plotter.h"
#include <qmath.h>
#include <QDebug>
#include <vector>

Plotter::Plotter()
    : m_count(0)
{
    m_data.resize(2500 * 6);

    QVector3D v1(0.0f,-0.25f,0.05f);
    QVector3D v2(0.0f,0.25f,0.05f);


    for(int i=0; i<50; i++){
        QVector3D temp((25 - qrand()%50)*.01f,(25 - qrand()%50)*.01f,(25 - qrand()%50)*.01f);
        addCube(temp,0.025f);
    }


//    addCube(v1,0.25f);
//    addCube(v2,0.25f);

}

void Plotter::add(const QVector3D &v, const QVector3D &n)
{
    GLfloat *p = m_data.data() + m_count;
    *p++ = v.x();
    *p++ = v.y();
    *p++ = v.z();
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    m_count += 6;
}

void Plotter::addTriangle(const QVector3D &v1, const QVector3D &v2, const QVector3D &v3)
{
    QVector3D n = QVector3D::normal(v2-v1, v3-v1);
//    qInfo() << n.x() << "\t" << n.y() << "\t" << n.z();
    add(v1,n);
    add(v2,n);
    add(v3,n);
}

void Plotter::addCube(const QVector3D &v, GLfloat sideLength)
{
    std::vector<QVector3D> cubePoints = makeCubePoints(v,sideLength);

    //Front
    addTriangle(cubePoints[0],cubePoints[1],cubePoints[2]);
    addTriangle(cubePoints[2],cubePoints[3],cubePoints[0]);

    //Back
    addTriangle(cubePoints[4],cubePoints[6],cubePoints[5]);
    addTriangle(cubePoints[6],cubePoints[4],cubePoints[7]);

    //Top
    addTriangle(cubePoints[2],cubePoints[6],cubePoints[3]);
    addTriangle(cubePoints[3],cubePoints[6],cubePoints[7]);

    //Bottom
    addTriangle(cubePoints[0],cubePoints[4],cubePoints[1]);
    addTriangle(cubePoints[1],cubePoints[4],cubePoints[5]);

    //Right
    addTriangle(cubePoints[1],cubePoints[6],cubePoints[2]);
    addTriangle(cubePoints[5],cubePoints[6],cubePoints[1]);

    //Left
    addTriangle(cubePoints[0],cubePoints[3],cubePoints[4]);
    addTriangle(cubePoints[3],cubePoints[7],cubePoints[4]);
}

std::vector<QVector3D> Plotter::makeCubePoints(QVector3D v, GLfloat sideLength){
    std::vector<QVector3D> cubePoints;
    GLfloat half = sideLength/2;

    cubePoints.push_back(v+QVector3D(-half,half,-half));
    cubePoints.push_back(v+QVector3D(half,half,-half));
    cubePoints.push_back(v+QVector3D(half,-half,-half));
    cubePoints.push_back(v+QVector3D(-half,-half,-half));

    cubePoints.push_back(v+QVector3D(-half,half,half));
    cubePoints.push_back(v+QVector3D(half,half,half));
    cubePoints.push_back(v+QVector3D(half,-half,half));
    cubePoints.push_back(v+QVector3D(-half,-half,half));

    return cubePoints;
}
