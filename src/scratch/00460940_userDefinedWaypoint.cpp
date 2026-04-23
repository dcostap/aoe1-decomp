// tried a 3-byte point layout and several term orders; compiler still flips the base-load / scale sequence
// remaining gap is a small codegen-family difference in the success-path address math
class XYZBYTEPoint {
public:
    char data[3];
};

class RGE_Moving_Object {
public:
    char gap_00[0x168];
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;

    XYZBYTEPoint* userDefinedWaypoint(int param_1);
};

XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int param_1) {
    if ((param_1 >= 0) && (param_1 < this->numberUserDefinedWaypointsValue)) {
        int offset = param_1 + param_1 + param_1;
        return (XYZBYTEPoint*)((char*)this->userDefinedWaypoints + offset);
    }
    return 0;
}
