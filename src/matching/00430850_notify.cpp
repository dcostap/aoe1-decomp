#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class UnitAIModule {
public:
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

class RGE_Player {
public:
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4C();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5C();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6C();
    virtual void slot_70();
    virtual void slot_74();
    virtual void slot_78();
    virtual void slot_7C();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual void slot_8C();
    virtual void slot_90();
    virtual void slot_94();
    virtual void slot_98();
    virtual void slot_9C();
    virtual void slot_A0();
    virtual void slot_A4();
    virtual void slot_A8();
    virtual void slot_AC();
    virtual void slot_B0();
    virtual void slot_B4();
    virtual void slot_B8();
    virtual void slot_BC();
    virtual void slot_C0();
    virtual void slot_C4();
    virtual void slot_C8();
    virtual void slot_CC();
    virtual void slot_D0();
    virtual void slot_D4();
    virtual void slot_D8();
    virtual void slot_DC();
    virtual void slot_E0();
    virtual void slot_E4();
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

class RGE_Combat_Object {
public:
    int id;
    void* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x38];
    unsigned char object_state;
    unsigned char gap_49[0x2B];
    UnitAIModule* unitAIValue;

    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};
#endif

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (object_state == 2) {
        if (unitAIValue != 0) {
            if (unitAIValue->notify(param_1, param_2, param_3, param_4, param_5, param_6) != 0) {
                return;
            }
        }
        if (param_3 != 0x2BB) {
            owner->notify(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
}
