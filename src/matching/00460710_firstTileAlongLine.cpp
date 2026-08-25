// VA: 00460710 RGE_Moving_Object::firstTileAlongLine
// PDB owner: move_obj.cpp:2719-2771
// The canonical map, player, moving-object, and point layouts live in
// include/move_obj_context.h. The inherited passableTile ABI is named there.
// Current source is the paused natural line scan; calls and frame are aligned.

#include <math.h>

extern float DAT_00570B48;

int RGE_Moving_Object::firstTileAlongLine(const XYPoint& a,
                                           const XYPoint& b,
                                           XYPoint& result,
                                           int terrain1, int terrain2,
                                           int checkTerrain) {
    int lastX;
    int lastY;
    float xDistance = (float)(b.x - a.x);
    float yDistance = (float)(b.y - a.y);

    if ((xDistance == DAT_00570B48) &&
        (yDistance == DAT_00570B48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;
    RGE_Map* map;
    unsigned char tileType;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    lastY = -999;
    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;
    x = (float)a.x;
    y = (float)a.y;
    map = this->owner->world->map;

    while (i < numSteps) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if ((tileX != lastX) || (tileY != lastY)) {
                lastX = tileX;
                lastY = tileY;
                tileType = map->get_terrain((short)tileX, (short)tileY);
                if (((int)tileType == terrain1 ||
                     (int)tileType == terrain2) &&
                    (checkTerrain == 1)) {
                    if (this->passableTile(x, y, 0) == 1) {
                        result.x = tileX;
                        result.y = tileY;
                        return 1;
                    }
                }
            }

        ++i;
    }

    return 0;
}
