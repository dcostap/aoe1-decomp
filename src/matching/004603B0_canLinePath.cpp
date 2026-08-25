// VA: 004603B0 RGE_Moving_Object::canLinePath
// move_obj.cpp:2600-2655
// The canonical RGE_Moving_Object and XYPoint declarations live in
// include/move_obj_context.h. The PDB-decorated reference surface is used.
// Standalone owner checkpoint: 442-byte owner.

#include <math.h>

extern float DAT_00570B48;

int RGE_Moving_Object::canLinePath(const XYPoint& a, const XYPoint& b,
                                   float maxDistance, XYPoint& result,
                                   int terrain) {
    int lastX;
    int lastY;
    float xDistance;
    float yDistance;
    int startX = a.x;
    int endX = b.x;
    int startY = a.y;
    int endY = b.y;

    xDistance = (float)(endX - startX);
    yDistance = (float)(endY - startY);

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
    x = (float)startX;
    y = (float)startY;

    for (; i < numSteps; ++i) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if (tileX != lastX || tileY != lastY) {
                lastX = tileX;
                lastY = tileY;
                if (this->passableTile(x, y, terrain) == 0) {
                    result.x = tileX;
                    result.y = tileY;
                    return 0;
                }

                if ((float)sqrt(((float)b.x - x) * ((float)b.x - x) +
                                ((float)b.y - y) * ((float)b.y - y)) <=
                    maxDistance) {
                    return 1;
                }
            }
    }

    return 1;
}
