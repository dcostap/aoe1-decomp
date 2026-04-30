// VA: 00460940 userDefinedWaypoint (35B)
// Returns pointer into waypoint array, each element 12 bytes (3 * 4)
// Remaining 9-byte diff (25%): VC5 reverses LEA/MOV order in the address math
// (LEA EDX,[EAX+EAX*2]/MOV EAX,[ECX+0x168] vs MOV EDX,[ECX+0x168]/LEA EAX,[EAX+EAX*2])
// Both sequences are semantically identical with same register pressure.

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Moving_Object {
public:
    char gap_00[0x168];
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;

    XYZBYTEPoint* userDefinedWaypoint(int param_1);
};

XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int param_1) {
    if (param_1 < 0 || param_1 >= numberUserDefinedWaypointsValue) return 0;
    XYZBYTEPoint* result = userDefinedWaypoints + param_1;
    return result;
}
