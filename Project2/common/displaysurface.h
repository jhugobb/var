#ifndef displaysurface_h
#define displaysurface_h

#include "../common/point.h"

class DisplaySurface {
    private:
        Point m_origin;
        Vector m_u;
        Vector m_v;
        
    public:
        DisplaySurface(const Point& orig, const Vector& uvector, const Vector& vvector);
        inline Point origin() {return m_origin;};
        inline Vector u() {return m_u;};
        inline Vector v() {return m_v;};
        
        inline void ori(const Point& orig) { m_origin=orig;};
        inline void v_u(const Vector& uvector) { m_u=uvector;};
        inline void v_v(const Vector& vvector) { m_v=vvector;};
        
};

#endif /* displaysurface_h */
