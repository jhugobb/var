#include "point.h"

Point::Point() {
        x(0);
        y(0);
        z(0);
}
Point::Point(double dx, double dy, double dz) {
        x(dx);
        y(dy);
        z(dz);
}

Vector Point::operator-(Point& u) {
	Vector result(m_x-u.x(), m_y-u.y(), m_z-u.z());

	return result;
}
