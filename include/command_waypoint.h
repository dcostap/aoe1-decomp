#ifndef AOE1_COMMAND_WAYPOINT_H
#define AOE1_COMMAND_WAYPOINT_H

// Shared three-byte waypoint record owned by Command.cpp.
struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

typedef char command_xyzbytepoint_size_check[
    (sizeof(XYZBYTEPoint) == 0x03) ? 1 : -1];

#endif
