
#include <QtGui/QMatrix4x4>
#include <math.h>
#include <iostream>

#include "../common/point.h"
#include "../common/displaysurface.h"
#include "../common/vector.h"

using namespace std;

QMatrix4x4 projectionMatrix(const DisplaySurface& display, const Point& eye, float znear, float zfar) {
    float near = znear;
    float far = zfar;

    QMatrix4x4 result = QMatrix4x4();
    result.setToIdentity();

    QVector3D du = QVector3D(display.u.x, display.u.y, display.u.z);
    QVector3D dv = QVector3D(display.v.x, display.v.y, display.v.z);

    float aspectRatio =du.length()/dv.length();
    float fov = 130 * M_PI / 180; // The vertical human eye fov is 130º, but we want it in radians
    result.perspective(130, aspectRatio, 1, 1000);

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
    QMatrix4x4 matrixLeft = projectionMatrix(left, eye, znear, zfar);
    QMatrix4x4 matrixRight = projectionMatrix(right, eye, znear, zfar);
    QMatrix4x4 matrixRight = projectionMatrix(floor, eye, znear, zfar);

    cout << matrixFront.data << endl;

    return 0;
}