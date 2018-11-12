#include "vector.h"
#include "cmath"

Vector::Vector() {
        vx(0);
        vy(0);
        vz(0);
}
Vector::Vector(const Vector& v) {
        vx(v.m_x);
        vy(v.m_y);
        vz(v.m_z);
}
Vector::Vector(double dx, double dy, double dz) {
        vx(dx);
        vy(dy);
        vz(dz);
}

float Vector::norm() {
	return sqrt(m_x*m_x + m_y * m_y + m_z * m_z);
}
void Vector::normalize() {
	float norm = this->norm();
	m_x /= norm;
	m_y /= norm;
	m_z /= norm;
}
Vector Vector::crossProduct(Vector& v) {
	Vector w(0,0,0);
	w.vx(m_y * v.vz() - m_z * v.vy());
	w.vy(m_z * v.vx() - m_x * v.vz());
	w.vz(m_x * v.vy() - m_y * v.vx());
	return w;
}

Vector Vector::operator-(Vector& u) {
	Vector result(m_x-u.vx(), m_y-u.vy(), m_z-u.vz());

	return result;
}
