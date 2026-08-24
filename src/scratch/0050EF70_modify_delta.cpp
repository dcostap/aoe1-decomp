// first pass: special-case attribute 0x64, otherwise forward to the base implementation
// for the 0x64 path, walk the three 6-byte entries starting at +0x14A and add the floored delta to the amount field

#ifndef TM_CO_OB_SHARED_CONTEXT
class TRIBE_Master_Combat_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};
#endif

struct BuildInventoryEntry {
    short amount;
    unsigned char enabled;
    char gap_3[3];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    char gap_04[0x146];
    BuildInventoryEntry build_inventory[3];

    virtual void modify_delta(float value, unsigned char attribute);
};

void TRIBE_Master_Building_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 0x64) {
        TRIBE_Master_Combat_Object::modify_delta(value, attribute);
        return;
    }

    BuildInventoryEntry* entry = build_inventory;
    int remaining = 3;

    do {
        if (entry->enabled != 0) {
            entry->amount = entry->amount + (short)value;
        }
        ++entry;
    } while (--remaining != 0);
}
