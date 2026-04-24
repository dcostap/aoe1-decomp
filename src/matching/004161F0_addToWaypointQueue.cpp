struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

class UnitAIModule {
public:
    char gap_00[0x70];
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;

    int addToWaypointQueue(int param_1, int param_2);
};

int UnitAIModule::addToWaypointQueue(int param_1, int param_2) {
    if (this->waypointQueueSizeValue >= 8) {
        this->waypointQueueSizeValue = 0;
    }
    this->waypointQueue[this->waypointQueueSizeValue].x = (float)param_1;
    this->waypointQueue[this->waypointQueueSizeValue].y = (float)param_2;
    this->waypointQueueSizeValue = this->waypointQueueSizeValue + 1;
    return 1;
}
