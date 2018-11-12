#include "../common/displaysurface.h"
#include "matrix.h"


Matrix viewingMatrix(const DisplaySurface& display, const Point& eye) {
	DisplaySurface surface = display;
	Vector a = surface.u();
	a.normalize();
	Vector b = surface.v();
	b.normalize();
	Vector c = a.crossProduct(b);
	Matrix m(3, 3, 1);
	m.mat[0][0] = a.vx();
	m.mat[0][1] = a.vy();
	m.mat[0][2] = a.vz();
	
	m.mat[1][0] = b.vx();
	m.mat[1][1] = b.vy();
	m.mat[1][2] = b.vz();

	m.mat[2][0] = c.vx();
	m.mat[2][1] = c.vy();
	m.mat[2][2] = c.vz();
	Point cero(0,0,0);
	Point pEye= eye;
	Vector vEye = pEye.operator-(cero);
	Vector o2 = m.operator*(vEye);
	o2.vx(-o2.vx());
	o2.vy(-o2.vy());
	o2.vz(-o2.vz());
	Matrix m2(4, 4, 1);
	m2.mat[0][0] = a.vx();
	m2.mat[0][1] = a.vy();
	m2.mat[0][2] = a.vz();
	m2.mat[0][3] = o2.vx();
	m2.mat[1][0] = b.vx();
	m2.mat[1][1] = b.vy();
	m2.mat[1][2] = b.vz();
	m2.mat[1][3] = o2.vy();
	m2.mat[2][0] = c.vx();
	m2.mat[2][1] = c.vy();
	m2.mat[2][2] = c.vz();
	m2.mat[2][3] = o2.vz();
	m2.mat[3][0] = 0;
	m2.mat[3][1] = 0;
	m2.mat[3][2] = 0;
	m2.mat[3][3] = 1;
	return m2;
};


int main(){

	Point eyePosition(50, 20, 100);
	DisplaySurface front(Point(-150, -150, -150), Vector(300, 0, 0), Vector(0, 300, 0));
	DisplaySurface left(Point(-150, -150, 150), Vector(0, 0, -300), Vector(0, 300, 0));
	DisplaySurface right(Point(150, -150, -150), Vector(0, 0, 300), Vector(0, 300, 0));
	DisplaySurface floor(Point(-150, -150, 150), Vector(300, 0, 0), Vector(0, 0, -300)); 

	Matrix frontM = viewingMatrix(front, eyePosition);
	Matrix leftM = viewingMatrix(left, eyePosition);
	Matrix rightM = viewingMatrix(right, eyePosition);
	Matrix floorM = viewingMatrix(floor, eyePosition);

	frontM.print();
	leftM.print();
	rightM.print();
	floorM.print();


}
