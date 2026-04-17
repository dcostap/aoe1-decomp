class RGE_Static_Object;
class RGE_Player;
class Visible_Unit_Manager;

extern "C" Visible_Unit_Manager* VisibleUnitManager;

class RGE_Master_Static_Object {
public:
    unsigned char gap_00[0x14];
    short object_group;
};

class RGE_Player {
public:
    unsigned char gap_00[0x4A];
    short id;
};

class Visible_Unit_Manager {
public:
    void Update_Unit_Info(int object_id, int player_id, int world_x, int world_y, int object_group, unsigned long unified_map_value, int zero, void* vur_ptrs);
};

class RGE_Base_Object {
public:
    virtual void enter_obj(RGE_Static_Object* obj);
};

class RGE_Combat_Object : public RGE_Base_Object {
public:
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x10];
    RGE_Static_Object* inside_obj;
    unsigned char gap_24[0x14];
    float world_x;
    float world_y;
    unsigned char gap_40[0x154];
    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;

    virtual void enter_obj(RGE_Static_Object* obj);
};

void RGE_Combat_Object::enter_obj(RGE_Static_Object* obj) {
    RGE_Base_Object::enter_obj(obj);
    if (inside_obj != 0) {
        if (id >= 0) {
            VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
            Unified_Map_Value = 0;
        }
    }
}
