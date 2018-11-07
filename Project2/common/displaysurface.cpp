#include "point.h"
#include "vector.h"
#include "displaysurface.h"

DisplaySurface::DisplaySurface(const Point& orig, const Vector& uvector, const Vector& vvector) {
    origin = orig;
    u = uvector;
    v = vvector;
}