// VA: 0046A810 operator<<(ostream&, const Path&)
// Path.cpp lines 57-65
// 206 bytes
//
// ATTEMPT LOG:
// - Replaced free ostream helper stubs with the real C++ ostream member overloads.
// - Restored the binary-observed chained z/comma and facet/closing-text calls.
// - Carried the returned ostream pointer through the coordinate output and loaded
//   the single float temporary before setting x_floatused; this reproduces all 61
//   instruction shapes and the original frame/register topology.
// - Normalized the proven class layouts (ostream vbptr, padded Waypoint records,
//   and Path's Waypoint subobjects) without changing emitted code.
// - Fresh ABI probe: replaced the local ostream stub/manual float-flag stores
//   with VC5's period <iostream.h> ostream surface and its natural inline float
//   overload. The body remains 206 bytes/61 instructions and byte-identical
//   after relocation masking, proving the remaining mismatch is not caused by
//   the local stub or float source spelling.
// - Current bytes are exact after masking the nine direct-call relocations. The
//   checker still reports those relocations as mismatches because the original
//   executable labels each overloaded ostream member only as operator<< while
//   the object necessarily carries the exact MSVC symbols (??6ostream@@...).

#include <iostream.h>

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};

ostream& __cdecl operator<<(ostream& os, const Path& path) {
    for (int i = 0; i < path.currentSizeValue; i++) {
        ostream* out = &os;
        float value;
        out = &out->operator<<("(");
        value = path.pathValue[i].x;
        out = &out->operator<<(value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].y;
        out = &out->operator<<(value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].z;
        out = &(out->operator<<(value) << ", ");
        os << (int)path.pathValue[i].facetToNextWaypoint << ") ";
    }
    return os;
}
