class RGE_Static_Object_uo {
public:
    char gap_00[0x37];
    unsigned char group_id;
};

class RGE_Player_uo {
public:
    void ungroup_objects(void);
    char gap_00[0x134];
    RGE_Static_Object_uo* selected_objects[25];
    char gap_198[0x04];
    short num_selected;
};

void RGE_Player_uo::ungroup_objects(void) {
    int count = 0;
    int i = 0;
    while (count < (int)this->num_selected) {
        if (i >= 25) break;
        RGE_Static_Object_uo* obj = this->selected_objects[i];
        if (obj != 0) {
            count++;
            obj->group_id = 0;
        }
        i++;
    }
}
