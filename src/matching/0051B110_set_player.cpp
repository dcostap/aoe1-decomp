#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class RGE_Static_Object;

class TRIBE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* object_130;
};

class TRIBE_Panel_Object {
public:
    char gap_00[0x110];
    TRIBE_Player* player;

    void set_object(RGE_Static_Object* object);
    void set_player(TRIBE_Player* player);
};
#endif

void TRIBE_Panel_Object::set_player(TRIBE_Player* player) {
    this->player = player;
    if (player != 0) {
        set_object(player->object_130);
        return;
    }
    set_object(0);
}
