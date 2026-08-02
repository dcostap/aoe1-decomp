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
// - Current bytes are exact after masking the nine direct-call relocations. The
//   checker still reports those relocations as mismatches because the original
//   executable labels each overloaded ostream member only as operator<< while
//   the object necessarily carries the exact MSVC symbols (??6ostream@@...).

class ostream {
public:
    void* vbptr;
    int flags;

    ostream& operator<<(const char* s);
    ostream& operator<<(double d);
    ostream& operator<<(int val);
};

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
        out->flags = 1;
        out = &out->operator<<((double)value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].y;
        out->flags = 1;
        out = &out->operator<<((double)value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].z;
        out->flags = 1;
        out = &(out->operator<<((double)value) << ", ");
        os << (int)path.pathValue[i].facetToNextWaypoint << ") ";
    }
    return os;
}
