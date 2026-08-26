#include "../../include/aiuaimod_context.h"

extern int __cdecl debug_rand(char* param_1, int param_2);

int UnitAIModule::closestUndiscoveredTile(int* param_1, int* param_2, int param_3) {
    RGE_Static_Object* object;
    RGE_Visible_Map* visible;
    RGE_Map* map;
    unsigned char currentZone;
    int bestDistance;
    int currX;
    int currY;
    int searchRadius;
    int lowX;
    int highX;
    int highY;
    int lowY;
    int x;
    int y;
    int distance;

    if (this->currentOrderValue == 0x2C1) {
        if (this->currentTargetXValue != -1.0f) {
            if (this->currentTargetYValue != -1.0f) {
                return 0;
            }
        }
    }

    object = this->objectValue;
    bestDistance = -1;
    currX = (int)object->world_x;
    currY = (int)object->world_y;
    searchRadius = (int)object->master_obj->los + 3;
    lowX = (int)(object->world_x - (float)searchRadius);
    highX = (int)(object->world_x + (float)searchRadius);
    lowY = (int)(object->world_y - (float)searchRadius);
    highY = (int)(object->world_y + (float)searchRadius);
    map = object->owner->world->map;
    visible = object->owner->visible;

    if (lowX < 0) {
        lowX = 0;
    }
    if (highX > map->map_width - 1) {
        highX = map->map_width - 1;
    }
    if (lowY < 0) {
        lowY = 0;
    }
    if (highY > map->map_height - 1) {
        highY = map->map_height - 1;
    }

    const int randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xB2E) % 3;
    currentZone = this->objectValue->currentZone();

    for (y = lowY; y <= highY; ++y) {
        for (x = lowX; x <= highX; ++x) {
            if (this->visibleStatus(visible, x, y) == 0) {
                if (currentZone == this->objectValue->lookupZone(x, y)) {
                    if (this->objectValue->passableTile((float)x, (float)y, 0) != 0) {
                        if ((param_3 == 0) || (this->inWaypointQueue(x, y) == 0)) {
                            distance = (x - currX) * (x - currX) + (y - currY) * (y - currY);
                            if (this->currentTargetXValue != -1.0f) {
                                distance =
                                    (x - (int)this->currentTargetXValue) * (x - (int)this->currentTargetXValue) +
                                    distance +
                                    (y - (int)this->currentTargetYValue) * (y - (int)this->currentTargetYValue);
                            }
                            if ((bestDistance == -1) || (bestDistance + randSelect > distance)) {
                                bestDistance = distance;
                                *param_1 = x;
                                *param_2 = y;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bestDistance != -1) {
        XYZPoint point;

        object = this->objectValue;
        point.x = *param_1;
        point.y = *param_2;
        point.z = (int)object->world_z;
        return object->canPathPoint(point, object->master_obj->los - 1.0f,
                                    -1, (float*)&param_1, 0, -1, -1);
    }

    return 0;
}
