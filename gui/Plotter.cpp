#include "Plotter.h"
#include <qmath.h>
#include <QDebug>
#include <vector>

Plotter::Plotter()
    : m_count(0)
{
    m_data.resize(500000 * 6);

//    QVector3D v1(0.0f,-0.25f,0.05f);
//    QVector3D v2(0.0f,0.25f,0.05f);


//    for(int i=0; i<500; i++){
//        QVector3D temp((2500 - qrand()%5000)*.0001f,(2500 - qrand()%5000)*.0001f,(2500 - qrand()%5000)*.0001f);
//        addCube(temp,0.01250f);
//    }

//    int count = 0;
//    while(count<500){
//        qreal x = (2500 - qrand()%5000)*.0001f;
//        qreal y = (2500 - qrand()%5000)*.0001f;
//        qreal z = (2500 - qrand()%5000)*.0001f;
//        if(x*x+y*y+z*z > .01f)
//            continue;
//        QVector3D temp(x,y,z);
//        addCube(temp,0.01250f);
//        count++;
//    }

    std::vector<std::vector<int>> arr = read_uint8_data("/home/david/columbiaCS/ultrasound/ultrasound-qt/gui/data");
    auto m = two_d_array_to_matrix(arr);
    std::vector<Eigen::MatrixXd> res = cart_to_polar(m);
    Eigen::MatrixXd x_axis = res[0];
    Eigen::MatrixXd y_axis = res[1];
    Eigen::MatrixXd values = res[2];
    qInfo() << x_axis.size();
    qInfo() << y_axis.size();
    qInfo() << values.size();

    int n=0;
    while(n < values.size())
    {

        int i = n/250;
        int j = n%250;
        qInfo() << j << "," << i;
        qInfo() << x_axis(i,j);
        qInfo() << y_axis(i,j);
        qInfo() << (values(i,j)-60)/4 -2;
        QVector3D temp(1.5*y_axis(i,j)/1000.0, -1.5*x_axis(i,j)/1000.0 - .25, 0 );
//        QVector3D temp(1.5*y_axis(i,j)/1000.0, -1.5*x_axis(i,j)/1000.0 - .25, (values(i,j)-60)/4 -2 );
        addCube(temp, 0.00625f);
//        qInfo() << "lol";
        ++n;
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
