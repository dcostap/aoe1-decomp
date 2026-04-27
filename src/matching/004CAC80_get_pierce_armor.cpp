// attempt log:
// first pass: direct typed locals and a straightforward loop over the master table
// check 1: compiled smaller than expected; VC5 preferred a tighter loop and fewer reloads than the original
// check 2 candidate: switch to direct member accesses and recompute the table base each trip to mirror the asm reloads

class RGE_Master_Combat_Object {
public:
    char gap_00[0x102];
    short unit_count;
    short* pierce_table;
    char gap_108[0x58];
    short pierce_armor;
};

class TRIBE_Combat_Object {
public:
    char gap_00[8];
    RGE_Master_Combat_Object* master_obj;

    void get_pierce_armor(short& out_armor, short& out_other);
};

void TRIBE_Combat_Object::get_pierce_armor(short& out_armor, short& out_other) {
    out_armor = 0;

    int index = 0;
    if (*(short*)((char*)this->master_obj + 0x102) > 0) {
        do {
            short* entry = *(short**)((char*)this->master_obj + 0x104) + index * 2;
            if (entry[0] == 3 && entry[1] > out_armor) {
                out_armor = entry[1];
            }
            index++;
        } while (index < *(short*)((char*)this->master_obj + 0x102));
    }

    out_other = *(short*)((char*)this->master_obj + 0x160);
}
