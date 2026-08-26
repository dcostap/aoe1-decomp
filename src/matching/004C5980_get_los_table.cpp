#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct LOSTBL;

class RGE_Visible_Map {
public:
    LOSTBL* get_los_table(int distance, int diagonal);
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_00[0x4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;

    virtual LOSTBL* get_los_table(void);
};
#endif

// BINARY NOTE: LOSTBL is a struct in the original decorated return type.
LOSTBL* RGE_Static_Object::get_los_table(void) {
    if (this->owner == 0) {
        return 0;
    }
    return this->owner->visible->get_los_table((int)this->master_obj->los, 0);
}
