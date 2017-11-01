#ifndef LOGO_H
#define LOGO_H

#include <qopengl.h>
#include <QVector>
#include <QVector3D>
#include "data_converter.h"

class Plotter
{
public:
    Plotter();
    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 6; }

private:
    void quad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4);
    void extrude(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void add(const QVector3D &v, const QVector3D &n);
    void addTriangle(const QVector3D &v1, const QVector3D &v2, const QVector3D &v3);
    std::vector<QVector3D> makeCubePoints(QVector3D v, GLfloat sideLength);
    void addCube(const QVector3D &v, GLfloat sideLength);
//    void plotPoints()

    QVector<GLfloat> m_data;
    int m_count;
};

#endif // LOGO_H
