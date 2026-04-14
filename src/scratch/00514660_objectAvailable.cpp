class RGE_Master_Static_Object_oa {
public:
    char gap_00[0x52];
    unsigned char available;
};

class TRIBE_Player_oa {
public:
    int objectAvailable(int obj_id);
    char gap_00[0x24];
    RGE_Master_Static_Object_oa** master_objects;
};

int TRIBE_Player_oa::objectAvailable(int obj_id) {
    RGE_Master_Static_Object_oa* m = this->master_objects[obj_id];
    if (m && m->available)
        return 1;
    if (obj_id == 0x6D)
        return 1;
    return 0;
}
