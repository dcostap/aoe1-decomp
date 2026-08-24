#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    unsigned char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    void* vftable;
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Animated_Object {
public:
    virtual void base_vf00();
    void release_being_worked_on(RGE_Static_Object* target);
};

class RGE_Combat_Object : public RGE_Animated_Object {
public:
    int value_4;
        virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08();
    virtual void slot_09();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual void slot_29();
    virtual void slot_30();
    virtual void slot_31();
    virtual void slot_32();
    virtual void slot_33();
    virtual void slot_34();
    virtual void slot_35();
    virtual void slot_36();
    virtual void slot_37();
    virtual void slot_38();
    virtual void slot_39();
    virtual void slot_40();
    virtual void slot_41();
    virtual void slot_42();
    virtual void slot_43();
    virtual void slot_44();
    virtual void slot_45();
    virtual void slot_46();
    virtual void slot_47();
    virtual void slot_48();
    virtual void slot_49();
    virtual void slot_50();
    virtual void slot_51();
    virtual void slot_52();
    virtual void slot_53();
    virtual void slot_54();
    virtual void slot_55();
    virtual void slot_56();
    virtual void slot_57();
    virtual void slot_58();
    virtual void slot_59();
    virtual void slot_60();
    virtual void slot_61();
    virtual void slot_62();
    virtual void slot_63();
    virtual void slot_64();
    virtual void slot_65();
    virtual void slot_66();
    virtual void slot_67();
    virtual void slot_68();
    virtual void slot_69();
    virtual void slot_70();
    virtual void slot_71();
    virtual void slot_72();
    virtual void slot_73();
    virtual void slot_74();
    virtual void slot_75();
    virtual void slot_76();
    virtual void slot_77();
    virtual void slot_78();
    virtual void slot_79();
    virtual void slot_80();
    virtual void vf148(int target_id, int self_value_4, int command_id, int object_group, int zero1, int zero2);
    virtual void release_being_worked_on(RGE_Static_Object* target);
};
#endif

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* target) {
    RGE_Animated_Object::release_being_worked_on(target);
    if (target->id >= 0) {
        vf148(target->id, value_4, 0x2BB, target->master_obj->object_group, 0, 0);
    }
}
