// quick-win attempt log:
// first pass missed the prolog because of extra spill temps and a reshaped vtable call
// next probe removed the cached pointer/temp locals, then a fixed-3 loop; mismatch moved
// to the prolog/load basin: original starts with push ecx/push ebx/push ebp/push esi/push edi,
// while VC5 still emits a small stack frame and different counter register choices
class RGE_Master_Static_Object {
public:
    char gap_00[0x6A];
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    char gap_7E[0xA];
    unsigned char attribute_flag[3];
};

class RGE_Player {
public:
    void* vtable_ptr;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    char gap_04[0x4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;

    void take_attribute_from_owner(void);
};

typedef void (__cdecl *TPlayerAttributeFn)(RGE_Player*, short, float, int);

void RGE_Static_Object::take_attribute_from_owner(void) {
    short attr;
    for (int i = 0; i < 3; ++i) {
        if ((this->master_obj->attribute_flag[i] == 2) &&
            (attr = this->master_obj->attribute_type_held[i], -1 < attr)) {
            ((TPlayerAttributeFn)(*(void ***)this->owner)[30])(this->owner, attr, -this->master_obj->attribute_amount_held[i], 0);
        }
    }
}
