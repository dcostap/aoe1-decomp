#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_Player {
public:
    char gap_00[0x24];
    void* obj_table;
    char gap_28[0x28];
    float* resource_cost_table;

    void reimburse_obj_cost(short obj_idx);
};

struct CostInfo {
    short res_id;
    short amount;
    unsigned char flag;
    char pad;
};

struct ObjInfo {
    char gap_00[4];
    unsigned char kind;
    char gap_05[0x143];
    CostInfo cost[3];
};
#endif

void TRIBE_Player::reimburse_obj_cost(short obj_idx) {
    ObjInfo* obj = ((ObjInfo**)obj_table)[obj_idx];
    CostInfo* p;
    int i;

    if (obj->kind < 0x46)
        return;
    p = obj->cost;
    i = 3;
    do {
        if (p->res_id >= 0) {
            if (p->flag != 0) {
                this->resource_cost_table[p->res_id] += (float)p->amount;
            }
        }
        p = (CostInfo*)((char*)p + 6);
        i--;
    } while (i != 0);
}
