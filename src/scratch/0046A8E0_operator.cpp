// VA: 0046A8E0 Path::operator+(const Path& other) const
// Path.cpp lines 70-77
// 253 bytes — UDT return with EH frame

void* __cdecl operator_new(unsigned int size);

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

    Path(int max_size);
    void insertAtEnd(const Waypoint& wp);
    ~Path();
    Path operator+(const Path& other) const;
};

Path Path::operator+(const Path& other) const {
    Path newPath = Path(maxSizeValue + other.maxSizeValue);
    newPath.timeStampValue = 0;
    if (currentSizeValue > 0) {
        for (int i = 0; i < currentSizeValue; i++) {
            newPath.insertAtEnd(pathValue[i]);
        }
    }
    if (other.currentSizeValue > 0) {
        int offset = newPath.currentSizeValue * 16;
        for (int i = 0; i < other.currentSizeValue; i++) {
            newPath.insertAtEnd(*(Waypoint*)((char*)other.pathValue + offset));
            offset += 16;
        }
    }
    newPath.timeStampValue = 1;
    return newPath;
}
