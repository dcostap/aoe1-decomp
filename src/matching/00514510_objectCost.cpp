// 00514510 TRIBE_Player::objectCost
// first pass: local shorts passed to obj_cost, then three ResourceItem increments.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class ResourceItem {
public:
    void incrementValue(int type, int amount);
};

class TRIBE_Player {
public:
    void obj_cost(short object_id, char** unused, short* inv2, short* amt2, short* inv3, short* amt3, short* inv1, short* amt1, float factor);
    void objectCost(int object_id, int param_2, ResourceItem* item, int param_4);
};
#endif

void TRIBE_Player::objectCost(int object_id, int param_2, ResourceItem* item, int param_4) {
    short inv1;
    short amt1;
    short inv2;
    short amt2;
    short inv3;
    short amt3;

    this->obj_cost((short)object_id, 0, &inv2, (short*)&object_id, &inv3, &amt3, &amt1, &inv1, 1.0f);
    item->incrementValue(inv2, (short)object_id);
    item->incrementValue(inv3, amt3);
    item->incrementValue(amt1, inv1);
}
