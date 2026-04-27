// VA: 0046AB60 Path::insertAtCurrent(const Waypoint& wp)
// Path.cpp lines 113-139
// 167 bytes

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

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

    int insertAtCurrent(const Waypoint& wp);
};

int Path::insertAtCurrent(const Waypoint& wp) {
    if (currentSizeValue > 1000) return 0;
    Waypoint* new_path = (Waypoint*)operator_new((currentSizeValue + 1) * 16);
    new_path[0] = wp;
    for (int i = 0; i < currentSizeValue; i++) {
        new_path[i + 1] = pathValue[i];
    }
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
    pathValue = new_path;
    currentSizeValue++;
    return 1;
}
