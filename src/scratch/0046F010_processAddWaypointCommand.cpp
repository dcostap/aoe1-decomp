// tried the direct object lookup plus a 3-byte waypoint cursor loop; mismatch stayed in the push/register basin
// tried a local function-pointer call and a direct vtable expression; the remaining gap is the exact thiscall-style indirect call shape

class RGE_Static_Object;
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

struct XYZBYTEPoint {
    char bytes[3];
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;

    void processAddWaypointCommand(int object_id, XYZBYTEPoint* waypoints, int count);
};

class RGE_Static_Object {
public:
    void** vftable;
};

void RGE_Player::processAddWaypointCommand(int object_id, XYZBYTEPoint* waypoints, int count) {
    RGE_Static_Object* object = this->world->object(object_id);
    if (object != 0 && count > 0) {
        do {
            ((void (*)(RGE_Static_Object*, XYZBYTEPoint*, int))object->vftable[111])(object, waypoints, 1);
            waypoints++;
            count--;
        } while (count != 0);
    }
}
