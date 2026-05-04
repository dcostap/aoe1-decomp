class RGE_Master_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
};

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;

    int is_group_selected(short group);
};

int RGE_Player::is_group_selected(short group)
{
    short sVar1;
    short sVar2;

    sVar1 = 0;
    sVar2 = 0;
    while (sVar1 < 0x19) {
        if (sVar2 >= this->sel_count)
            return 0;
        if (this->sel_list[sVar1] != 0) {
            sVar2 = sVar2 + 1;
            if (this->sel_list[sVar1]->master_obj->object_group == group)
                return 1;
        }
        sVar1 = sVar1 + 1;
    }

    return 0;
}
