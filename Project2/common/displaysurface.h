#ifndef DISP_SUR
#define DISP_SUR

#include "point.h"
#include "vector.h"



class DisplaySurface {
    public:
        DisplaySurface(const Point& orig, const Vector& uvector, const Vector& vvector);
        Point origin;
        Vector u,v;
};

#endif