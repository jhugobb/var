#ifndef point_h
#define point_h

#include "../common/vector.h"

class Point {
    private:
        double m_x;
        double m_y;
        double m_z;
    public:
		Point();
        Point(double x, double y, double z);
        
        inline double x() {return m_x;};
        inline double y() {return m_y;};
        inline double z() {return m_z;};
        
        inline void x(double x) { m_x=x;};
        inline void y(double y) { m_y=y;};
        inline void z(double z) { m_z=z;};
        
        Vector operator-(Point& u);
};

#endif /* point_h */
