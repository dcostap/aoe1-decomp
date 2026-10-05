#ifndef AOE1_POINT_H
#define AOE1_POINT_H

class XYZ {
  public:
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int a, int b, int c);

    void rotateXYByFacet(const XYZ& refPoint, XYZ& rPoint, unsigned char facet);

    XYZ& operator=(const XYZ& p);
    XYZ operator+(const XYZ& p) const;
    XYZ operator-(const XYZ& p) const;
};

typedef char point_xyz_size_check[(sizeof(XYZ) == 0x0C) ? 1 : -1];

int __cdecl operator==(const XYZ& one, const XYZ& two);
int __cdecl operator!=(const XYZ& one, const XYZ& two);

#endif
