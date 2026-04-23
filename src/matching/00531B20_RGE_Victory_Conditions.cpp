class RGE_Player;
class RGE_Victory_Entry;
class RGE_Victory_Point_Entry;

class RGE_Victory_Conditions {
public:
    void** vftable;
    int field_4;
    int field_8;
    void* field_C;
    char field_10;
    char gap_11[3];
    int field_14;
    int field_18;
    int field_1C;

    void destroy();
    void sub(RGE_Victory_Entry* entry);
    void sub_point(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::destroy() {
    RGE_Victory_Entry* entry = (RGE_Victory_Entry*)this->field_4;
    this->vftable = (void**)0x005775A8;
    while (entry != 0) {
        this->sub(entry);
        entry = (RGE_Victory_Entry*)this->field_4;
    }

    RGE_Victory_Point_Entry* point = (RGE_Victory_Point_Entry*)this->field_14;
    while (point != 0) {
        this->sub_point(point);
        point = (RGE_Victory_Point_Entry*)this->field_14;
    }

    this->field_8 = 0;
    this->field_18 = 0;
    this->field_10 = 0;
    this->field_C = 0;
}
