// VA: 0046AB60 Path::insertAtCurrent(const Waypoint& wp)
// Path.cpp lines 113-139
// 167 bytes
// MATCHED 2026-05-21: aggregate Waypoint assignment compiled to a wrong stack-home/
// saved-register basin and copied the trailing dword. Explicit field copies, with the
// final narrow byte member copied as a byte, recover the original EBP=new_path / EDI=index
// loop and exact byte sequence.

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
    new_path[0].x = wp.x;
    new_path[0].y = wp.y;
    new_path[0].z = wp.z;
    new_path[0].facetToNextWaypoint = wp.facetToNextWaypoint;
    for (int i = 0; i < currentSizeValue; i++) {
        new_path[i + 1].x = pathValue[i].x;
        new_path[i + 1].y = pathValue[i].y;
        new_path[i + 1].z = pathValue[i].z;
        new_path[i + 1].facetToNextWaypoint = pathValue[i].facetToNextWaypoint;
    }
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
    pathValue = new_path;
    currentSizeValue++;
    return 1;
}
