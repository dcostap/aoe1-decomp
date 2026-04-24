// attempt 1: size matches (86), but total mismatch at offset 0 (VC5 uses ebp for this, doesn't push ecx first)
// attempt 2: same structure, same mismatch at offset 0
// Left in scratch: benign prologue/register drift, behavior correct

class RGE_Player {
public:
    void set_attribute(short attrId, float amount, int param);
};

class RGE_Master_Object {
public:
    char gap_00[0x88];
    unsigned char attrLevel;
};

class TRIBE_Building_Object {
public:
    RGE_Master_Object* master_obj;
    RGE_Player* owner;

    void take_building_attribute_from_owner();
};

void TRIBE_Building_Object::take_building_attribute_from_owner() {
    int edi = 0;
    int ebp = 0x6A;
    int esi = 0x70;
    do {
        if (master_obj->attrLevel + edi > 3) {
            short attrVal = *(short*)(ebp + (int)master_obj);
            if (attrVal > 0) {
                float attrF = *(float*)(esi + (int)master_obj);
                owner->set_attribute(attrVal, -attrF, 0);
            }
        }
        esi += 4;
        edi++;
        ebp += 2;
    } while (esi < 0x7C);
}
