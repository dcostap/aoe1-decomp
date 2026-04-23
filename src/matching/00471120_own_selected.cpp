class RGE_Player;
class RGE_Static_Object {
public:
    char gap_00[0xC];
    RGE_Player* owner;
};

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;

    int own_selected();
};

// tried the decompiler-style do/while; VC5 pulled the loop condition into the wrong basin
// next probe: simple while loop with the count check first, matching the asm's compare order
int RGE_Player::own_selected()
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
            if (this->sel_list[sVar1]->owner == this)
                return 1;
        }
        sVar1 = sVar1 + 1;
    }

    return 0;
}
