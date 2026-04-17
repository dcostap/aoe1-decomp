class RGE_Player;

class RGE_Master_Combat_Object {
public:
    void* vtable_ptr;
    unsigned char gap_04[0x11C];
    float speed_of_attack;
};

class RGE_Action_Object {
public:
    virtual void recycle_in_to_game(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;
    unsigned char gap_0C[0x188];
    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;

    virtual void recycle_in_to_game(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z);
};

void RGE_Combat_Object::recycle_in_to_game(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    int i;
    float attack_timer_local;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::recycle_in_to_game(master_obj, player, x, y, z);
    attack_timer_local = this->master_obj->speed_of_attack;
    attack_timer = attack_timer_local;
}
