// VA: 0046AC10 Path::insertAtEnd(const Waypoint& wp)
// Path.cpp lines 144-153
// 205 bytes

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

    int insertAtEnd(const Waypoint& wp);
};

int Path::insertAtEnd(const Waypoint& wp) {
    if (currentSizeValue == maxSizeValue) {
        maxSizeValue += maxSizeValue;
        Waypoint* new_path = (Waypoint*)operator_new(maxSizeValue * 16);
        for (int i = 0; i < currentSizeValue; i++) {
            new_path[i] = pathValue[i];
        }
        if (pathValue != 0) {
            operator_delete(pathValue);
        }
        pathValue = new_path;
    }
    pathValue[currentSizeValue].x = wp.x;
    pathValue[currentSizeValue].y = wp.y;
    pathValue[currentSizeValue].z = wp.z;
    pathValue[currentSizeValue].facetToNextWaypoint = wp.facetToNextWaypoint;
    currentSizeValue++;
    return 1;
}
