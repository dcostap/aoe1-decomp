#ifndef AOE1_XYZ_POINT_H
#define AOE1_XYZ_POINT_H

// Original function symbols encode pointers and values with the struct tag.
// CodeView records the complete type as a class, so keep both source facts.
struct XYZPoint;
class XYZPoint {
public:
    int x;
    int y;
    int z;
};

typedef char xyz_point_size_check[
    (sizeof(XYZPoint) == 0x0C) ? 1 : -1];

#endif
