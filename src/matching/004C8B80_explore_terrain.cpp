class RGE_Player;

class RGE_Static_Object {
public:
    int explore_terrain(RGE_Player* player, unsigned char value, int param);
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    char gap_00[0x1E5];
    unsigned char built;

    int explore_terrain(RGE_Player* player, unsigned char value, int param);
};

int TRIBE_Building_Object::explore_terrain(RGE_Player* player, unsigned char value, int param) {
    if (this->built != 0) {
        return RGE_Static_Object::explore_terrain(player, value, param);
    }
    return RGE_Static_Object::explore_terrain(player, 1, param);
}
