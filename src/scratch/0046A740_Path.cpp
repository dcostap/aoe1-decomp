// VA: 0046A740 Path::Path(int max_size)
// Path.cpp lines 36-44
// 162 bytes

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct Waypoint {
    float x;  // +0x00
    float y;  // +0x04
    float z;  // +0x08
    unsigned char facetToNextWaypoint; // +0x0C
};

struct Path {
    int timeStampValue;         // +0x00
    float startValue[3];        // +0x04 (x, y, z)
    int gap_10;
    float goalValue[3];
    int gap_20;         // +0x14 (x, y, z)
    Waypoint* pathValue;        // +0x24
    int maxSizeValue;           // +0x28
    int currentSizeValue;       // +0x2C
    int currentWaypointValue;   // +0x30

    Path(int max_size);
};

Path::Path(int max_size) {
    timeStampValue = 0;
    pathValue = 0;
    maxSizeValue = 0;
    currentSizeValue = 0;
    currentWaypointValue = 0;
    startValue[0] = 0;
    startValue[1] = 0;
    startValue[2] = 0;
    goalValue[0] = 0;
    goalValue[1] = 0;
    goalValue[2] = 0;
    if (max_size == 0 || max_size < 0) return;
    maxSizeValue = max_size;
    Waypoint* new_path = (Waypoint*)operator_new(max_size * 16);
    int i;
    for (i = 0; i < currentSizeValue; i++) {
        Waypoint* src = &pathValue[i];
        new_path[i] = *src;
    }
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
    pathValue = new_path;
}
