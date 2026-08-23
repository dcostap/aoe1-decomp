// attempt log:
// first pass: direct loop over the three attribute slots with raw offsets and the owner vcall
// second pass: align the status/value offsets to the packet's odd mixed index/offset walk and use a raw owner vcall surface
// third pass: swap the attribute-id address expression so VC5 can land the base/index registers in the packet order
// fourth pass: separate the attribute pointer into a named temp to bias the final [reg+reg] encoding
// fifth pass: tried pointer-index spellings instead of byte-offset math to see if VC5 flips the register order on the type load; it moved away from the target basin
// paused here: the remaining mismatch is a single register-order byte on the attr-id load, and the natural byte-offset form is the closest lead
// target shape: for each slot, require status 1..2 and type >= 0, then call owner vfunc +0x78 with (type, value, 0)

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x6A];
    short attribute_type_held[3];
    int attribute_amount_held[3];
    unsigned char attribute_flag[3];
};

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(short attr_id, int value, int zero);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;

    void give_attribute_to_owner(void);
};

#endif

void RGE_Static_Object::give_attribute_to_owner(void) {
    int i = 0;
    int local_4 = 0x6A;
    int value_offset = 0x70;

    do {
        RGE_Master_Static_Object* master = this->master_obj;
        unsigned char status = *(unsigned char*)((char*)master + 0x88 + i);
        if (status >= 1 && status <= 2) {
            short* attr_ptr = (short*)((char*)master + local_4);
            short attr_id = *attr_ptr;
            if (attr_id >= 0) {
                int value = *(int*)((char*)master + value_offset);
                this->owner->vf78(attr_id, value, 0);
            }
        }
        i++;
        local_4 += 2;
        value_offset += 4;
    } while (value_offset < 0x7C);
}
