#ifndef AOE1_PATH_CONTEXT_H
#define AOE1_PATH_CONTEXT_H

// Compiler-facing context for the original C:\\msdev\\work\\age1_x1\\Path.cpp
// module.  Path has no virtual base in this source module and occupies 0x34
// bytes.  The wrapper includes the owners in PDB address and line order.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* value);

struct Waypoint {
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

    Path(int max_size);
    int growMaxSize(int new_maximum) {
        if (new_maximum == 0) {
            return maxSizeValue += maxSizeValue;
        } else {
            return maxSizeValue += new_maximum;
        }
    }
    void setMaxSize(int new_maximum) {
        if (new_maximum == 0 || maxSizeValue <= new_maximum) {
            if (new_maximum == 0) {
                maxSizeValue += maxSizeValue;
            } else {
                maxSizeValue += new_maximum;
            }
            Waypoint* new_path = (Waypoint*)operator_new(maxSizeValue * 16);
            for (int i = 0; i < currentSizeValue; i++) {
                new_path[i].x = pathValue[i].x;
                new_path[i].y = pathValue[i].y;
                new_path[i].z = pathValue[i].z;
                new_path[i].facetToNextWaypoint = pathValue[i].facetToNextWaypoint;
            }
            if (pathValue != 0) {
                operator_delete(pathValue);
            }
            pathValue = new_path;
        }
    }
    Path& operator=(const Path& other);
    int insertAtEnd(Waypoint wp);
    ~Path();
    Path operator+(const Path& other) const;

    int operator==(const Path& other) const;
    int insertAtCurrent(const Waypoint& wp);
    int contains(const Waypoint& wp) const;
    void killPath();
    const int maxNumberOfWaypoints() const;
    const int numberOfWaypoints() const;
    unsigned long timeStamp() const;
    void setTimeStamp(unsigned long value);
    float length() const;
    const Waypoint& start() const;
    const Waypoint& goal() const;
    const Waypoint* waypoint(int index) const;
    Waypoint* currentWaypoint() const;
    const int currentWaypointNumber() const;
    void setCurrentWaypointNumber(int value);
    const Waypoint* nextWaypoint() const;
    const Waypoint* previousWaypoint() const;
    const Waypoint* firstWaypoint() const;
    const Waypoint* lastWaypoint() const;
    void initToStart();
    void initToEnd();
    int moveToNextWaypoint();
    int moveToLastWaypoint();
    float distanceToNextWaypoint() const;
};

#endif
