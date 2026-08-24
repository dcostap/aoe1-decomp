#ifndef ACT_OBJ_CONTEXT_H
class RGE_Master_Static_Object;
class RGE_Player;

class RGE_Moving_Object {
public:
    void recycle_in_to_game(RGE_Master_Static_Object* master_obj, RGE_Player* player, float x, float y, float z);
};

class RGE_Action_Object {
public:
    char gap_00[0x180];
    unsigned char waiting;

    void recycle_in_to_game(RGE_Master_Static_Object* master_obj, RGE_Player* player, float x, float y, float z);
};
#endif

void RGE_Action_Object::recycle_in_to_game(RGE_Master_Static_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    ((RGE_Moving_Object*)this)->RGE_Moving_Object::recycle_in_to_game(master_obj, player, x, y, z);
    this->waiting = 0;
}
