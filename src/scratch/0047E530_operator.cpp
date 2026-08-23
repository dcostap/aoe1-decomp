// VA: 0047E530 XYZ::operator+ (point.cpp:70-73, 75 bytes)
// Default flags.
//
// The original creates a temporary via XYZ(int,int,int) ctor
// then copies to hidden return storage pointer.
//
// Attempts:
// Probe 1: named temp ctor init without game_globals include -> 36%; VC5 hoisted this->z before stack alloc.
// Probe 2-3: temp vars, expr reorder -> same 36%
// Variant lab (5 variants, 4 axes - ctor_temp, assign_temp, return_direct, this_first/other_first):
//   all ctor_temp variants stayed in same 36% group without include context.
// Added game_globals include context: scheduling matched exactly. MATCH.

#include "../../include/game_globals.h"

class XYZ {
public:
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int x, int y, int z);
    XYZ operator+(const XYZ& other) const;
};

XYZ XYZ::operator+(const XYZ& other) const {
    XYZ tmp(xValue + other.xValue, yValue + other.yValue, zValue + other.zValue);
    return tmp;
}
