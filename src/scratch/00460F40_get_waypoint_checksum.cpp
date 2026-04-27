// VA: 00460F40 get_waypoint_checksum
// move_obj.cpp lines 3173-3183, 119 bytes
// RGE_Moving_Object::get_waypoint_checksum()

struct Waypoint {
    float x, y, z;          // 0x00-0x0B
    unsigned char facet;     // 0x0C
    unsigned char pad[3];
};

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0xC8];
    Waypoint* pathValue;          // +0xC8  (+0xA4+0x24)
    int maxSizeValue;             // +0xCC
    int currentSizeValue;         // +0xD0
    int currentWaypointValue;     // +0xD4
    
    int get_waypoint_checksum();
};

int RGE_Moving_Object::get_waypoint_checksum() {
    float sum = 0.0f;
    int savedIndex = currentWaypointValue;
    int count = currentSizeValue;
    int i;
    
    currentWaypointValue = 0;  /* initToStart */
    
    if (count > 0) {
        for (i = 0; i < count; i++) {
            Waypoint* wp = &pathValue[currentWaypointValue];
            sum += wp->y + wp->x;
            currentWaypointValue++;  /* moveToNextWaypoint */
        }
    }
    
    currentWaypointValue = savedIndex;  /* restore */
    return (int)sum;
}
