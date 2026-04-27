// VA: 00460B70 removeUserDefinedWaypoint
// move_obj.cpp lines 2914-2935, 125 bytes
// RGE_Moving_Object::removeUserDefinedWaypoint(int)

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x164];
    char* waypoints;    // +0x168
    int wpCount;        // +0x16C
    
    void removeUserDefinedWaypoint(int index);
};

void RGE_Moving_Object::removeUserDefinedWaypoint(int index) {
    int i;
    
    if (index < 0 || index >= wpCount) return;
    
    for (i = 0; i < wpCount && i < index; i++) {
        /* find position */
    }
    
    for (; i < wpCount; i++) {
        if (i) {
            waypoints[i * 3 - 3] = waypoints[i * 3];
            waypoints[i * 3 - 2] = waypoints[i * 3 + 1];
            waypoints[i * 3 - 1] = waypoints[i * 3 + 2];
        }
    }
    
    wpCount--;
}
