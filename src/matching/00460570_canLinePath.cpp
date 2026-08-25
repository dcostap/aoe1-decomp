// VA: 00460570 RGE_Moving_Object::canLinePath
// The canonical RGE_Moving_Object declaration lives in
// include/move_obj_context.h. This is the integer-coordinate overload.
// Standalone owner checkpoint: 414-byte owner.

#include <math.h>

extern float DAT_00570B48;

int RGE_Moving_Object::canLinePath(int x1, int y1, int x2, int y2,
                                   float maxDistance, int terrain) {
    int lastX;
    int lastY;
    float xDistance = (float)(x2 - x1);
    float yDistance = (float)(y2 - y1);

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
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;

    x = (float)x1;
    y = (float)y1;

    for (i = 0; i < numSteps; ++i) {
        x += xStep;
        y += yStep;
        int tileX = (int)x;
        int tileY = (int)y;

        if (tileX != lastX || tileY != lastY) {
            lastX = tileX;
            lastY = tileY;
            if (this->passableTile(x, y, terrain) == 0) {
                return 0;
            }

            if ((float)sqrt(((float)x2 - x) * ((float)x2 - x) +
                            ((float)y2 - y) * ((float)y2 - y)) <=
                maxDistance) {
                return 1;
            }
        }

    }

    return 1;
}
