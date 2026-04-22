class RGE_Static_Object_uo {
public:
    char gap_00[0x37];
    unsigned char selected_group;
};

class RGE_Player_uo {
public:
    void ungroup_objects(void);
    char gap_00[0x134];
    RGE_Static_Object_uo* sel_list[25];
    char gap_198[0x04];
    short sel_count;
};

void RGE_Player_uo::ungroup_objects(void) {
    RGE_Static_Object_uo** ppObj;
    int i;
    int count;
    RGE_Static_Object_uo* obj;

    i = 0;
    count = 0;
    ppObj = this->sel_list;
    while (i < 0x19) {
        if (count >= this->sel_count)
            break;
        obj = *ppObj;
        if (obj != 0) {
            count = count + 1;
            obj->selected_group = 0;
        }
        i = i + 1;
        ppObj = ppObj + 1;
    }
}
