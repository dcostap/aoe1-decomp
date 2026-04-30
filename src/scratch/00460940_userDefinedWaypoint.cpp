// VA: 00460940 userDefinedWaypoint (35B)
// move_obj.cpp

#pragma pack(push, 1)
struct XYZBYTEPoint {
    char x, y, z;
};
#pragma pack(pop)

class RGE_Moving_Object {
public:
    char gap_00[0x168];
    XYZBYTEPoint* waypoints;      // +0x168
    int numberWaypoints;          // +0x16C

    XYZBYTEPoint* userDefinedWaypoint(int index);
};

XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int index) {
    if (index < 0 || index >= this->numberWaypoints) return 0;
    return this->waypoints + index;
}
