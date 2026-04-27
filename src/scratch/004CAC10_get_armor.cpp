// first pass: mirror the sibling armor helper with direct reloads and the max-by-type-4 scan
// if this sticks, the remaining work is likely just the precise local/register shape around the loop reloads
class RGE_Master_Combat_Object;

class TRIBE_Combat_Object {
public:
    char pad_00[8];
    RGE_Master_Combat_Object* master_obj;

    void get_armor(short& out_armor, short& out_other);
};

class RGE_Master_Combat_Object {
public:
    char pad_00[0x100];
    unsigned char base_armor;
    char pad_101[0x1];
    short entry_count;
    short* entry_table;
    char pad_108[0x34];
    short orig_armor;
};

void TRIBE_Combat_Object::get_armor(short& out_armor, short& out_other) {
    int index = 0;
    out_armor = this->master_obj->base_armor;
    short zero = out_armor;
    zero -= zero;
    if (this->master_obj->entry_count > zero) {
        do {
            short* entry = (short*)((char*)this->master_obj->entry_table + index * 4);
            if (entry[0] == 4 && entry[1] > out_armor) {
                out_armor = entry[1];
            }
            index = index + 1;
        } while (index < this->master_obj->entry_count);
    }
    out_other = this->master_obj->orig_armor;
}
