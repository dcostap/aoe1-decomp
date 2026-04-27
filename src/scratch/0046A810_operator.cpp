// VA: 0046A810 operator<<(ostream&, const Path&)
// Path.cpp lines 57-65
// 206 bytes

struct ostream {
    int field_0;
    int flags;
};

ostream* __cdecl ostream_puts(ostream* os, const char* s);
ostream* __cdecl ostream_putdouble(ostream* os, double d);
ostream* __cdecl ostream_putint(ostream* os, int val);

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

struct Path {
    int timeStampValue;
    float startValue[3];
    int gap_10;
    float goalValue[3];
    int gap_20;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};

ostream& __cdecl operator<<(ostream& os, const Path& path) {
    for (int i = 0; i < path.currentSizeValue; i++) {
        ostream_puts(&os, "(");
        os.flags = 1;
        ostream_putdouble(&os, (double)path.pathValue[i].x);
        ostream_puts(&os, ", ");
        os.flags = 1;
        ostream_putdouble(&os, (double)path.pathValue[i].y);
        ostream_puts(&os, ", ");
        os.flags = 1;
        ostream_putdouble(&os, (double)path.pathValue[i].z);
        ostream_puts(&os, ") ");
        ostream_putint(&os, path.pathValue[i].facetToNextWaypoint);
    }
    return os;
}
