
#include <QtGui/QMatrix4x4>
#include <math.h>
#include <iostream>

#include "../common/point.h"
#include "../common/displaysurface.h"
#include "../common/vector.h"

using namespace std;

QMatrix4x4 projectionMatrix(const DisplaySurface& display, const Point& eye, float znear, float zfar) {
    float left, right, top, bottom;
    
    float near = znear;
    float far = zfar;

    QMatrix4x4 result = QMatrix4x4();

    QVector3D e = QVector3D(eye.x, eye.y, eye.z);

    QVector3D u = QVector3D(display.u.x, display.u.y, display.u.z);
    float sideDistance =u.length()/2;
    u.normalize();

    QVector3D v = QVector3D(display.v.x, display.v.y, display.v.z);
    float vertDistance = v.length()/2;
    v.normalize();
    
    QVector3D n = QVector3D(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(), u.x() * v.y() - u.y() * v.x());
    n.normalize();

    // Dot products needed
    float uDOTe = QVector3D::dotProduct(u, e);
    float vDOTe = QVector3D::dotProduct(v, e);
    float nDOTe = QVector3D::dotProduct(n, e);

    // Calculating the distances of the display-dependent frustum
    left=-near*(sideDistance+uDOTe)/(sideDistance+nDOTe);
    right=near*(sideDistance-uDOTe)/(sideDistance+nDOTe);
    top=-near*(vertDistance+vDOTe)/(vertDistance+ nDOTe);
    bottom=near*(vertDistance-vDOTe)/(vertDistance+nDOTe);

    cout << left << " " << right << " " << top << " " << bottom << " " << near << " " << far << endl;

    // Based on the openGL projection matrix
    result(0,0) = 2*near/(right-left);
    result(0,1) = 0;
    result(0,2) = (right+left)/(right-left);
    result(0,3) = 0;
    
    result(1,0) = 0;
    result(1,1) = 2*near/(bottom-top);
    result(1,2) = (top+bottom)/(bottom-top);
    result(1,3) = 0;

    result(2,0) = 0;
    result(2,1) = 0;
    result(2,2) = -(far+near)/(far-near);
    result(2,3) = - 2*far*near/(far-near);

    result(3,0) = 0;
    result(3,1) = 0;
    result(3,2) = -1;
    result(3,3) = 0;

    return result;
}



int main(int argc, char *argv[]) {
    // args: eye.x eye.y eye.z znear zfar
    double eye_x = stod(argv[1]);
    double eye_y = stod(argv[2]);
    double eye_z = stod(argv[3]);
    Point eye(eye_x, eye_y, eye_z);

    double znear = stod(argv[4]);
    double zfar = stod(argv[5]);

    DisplaySurface front(Point(-150, -150, -150), Vector(300, 0, 0), Vector(0, 300, 0));
    DisplaySurface left(Point(-150, -150, -150), Vector(0, 0, -300), Vector(0, 300, 0));
    DisplaySurface right(Point(-150, -150, -150), Vector(0, 0, 300), Vector(0, 300, 0));
    DisplaySurface floor(Point(-150, -150, -150), Vector(300, 0, 0), Vector(0, 0, -300));

    QMatrix4x4 matrixFront = projectionMatrix(front, eye, znear, zfar);
    
    for (int i = 0; i<4; i++) {
         for (int j = 0; j<4; j++) {
             cout << matrixFront(i,j) << "     ";
        }
        cout << endl;
    }

    QMatrix4x4 matrixLeft = projectionMatrix(left, eye, znear, zfar);
    
    for (int i = 0; i<4; i++) {
         for (int j = 0; j<4; j++) {
             cout << matrixLeft(i,j) << "     ";
        }
        cout << endl;
    }

    QMatrix4x4 matrixRight = projectionMatrix(right, eye, znear, zfar);
    
    for (int i = 0; i<4; i++) {
         for (int j = 0; j<4; j++) {
             cout << matrixRight(i,j) << "     ";
        }
        cout << endl;
    }

    QMatrix4x4 matrixDown = projectionMatrix(floor, eye, znear, zfar);
    
    for (int i = 0; i<4; i++) {
         for (int j = 0; j<4; j++) {
             cout << matrixDown(i,j) << "     ";
        }
        cout << endl;
    }

    return 0;
}