// VA: 00430C30, RGE_Combat_Object::moveTo, 286 bytes
// Source: com_obj.cpp lines 884-923
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

class RGE_Static_Object;

class RGE_Game_World {
public:
    char pad_00[0x88];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class RGE_Action_List {
public:
    uchar have_action();
    void* get_action();
    void delete_list();
};

class RGE_Action {
public:
    // vtable pointer at +0x00 from compiler
    short action_type;     // +0x04
    char gap_06[2];        // +0x06
    void* obj;             // +0x08
    char state;            // +0x0C
    char gap_0D[3];        // +0x0D
    void* target_obj;      // +0x10
    void* target_obj2;     // +0x14
    int targetID;          // +0x18
    int target2ID;         // +0x1C
    float target_x;        // +0x20
    float target_y;        // +0x24
    float target_z;        // +0x28
    float timer;           // +0x2C
    void* task;            // +0x30
    void* sub_actions;     // +0x34
    void* sprite;          // +0x38
    char subActionValue;   // +0x3C
    char gap_3D[3];        // +0x3D

    virtual ~RGE_Action();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual short func18();     // slot 6 at vtable +0x18
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
    virtual RGE_Static_Object* func4C();  // slot 19 at vtable +0x4C
};

class RGE_Action_Move_To : public RGE_Action {
public:
    int pad_40;  // 4 bytes at +0x40, total size 0x44
    RGE_Action_Move_To(void* obj, RGE_Static_Object* target, float param_2, void* sprite);
};

struct VTable208Proxy {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7C();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8C();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9C();
    virtual void sA0();
    virtual void sA4();
    virtual void sA8();
    virtual void sAC();
    virtual void sB0();
    virtual void sB4();
    virtual void sB8();
    virtual void sBC();
    virtual void sC0();
    virtual void sC4();
    virtual void sC8();
    virtual void sCC();
    virtual void sD0();
    virtual void sD4();
    virtual void sD8();
    virtual void sDC();
    virtual void sE0();
    virtual void sE4();
    virtual void sE8();
    virtual void sEC();
    virtual void sF0();
    virtual void sF4();
    virtual void sF8();
    virtual void sFC();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10C();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11C();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12C();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13C();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14C();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15C();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16C();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17C();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18C();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19C();
    virtual void s1A0();
    virtual void s1A4();
    virtual void s1A8();
    virtual void s1AC();
    virtual void s1B0();
    virtual void s1B4();
    virtual void s1B8();
    virtual void s1BC();
    virtual void s1C0();
    virtual void s1C4();
    virtual void s1C8();
    virtual void s1CC();
    virtual void s1D0();
    virtual void s1D4();
    virtual void s1D8();
    virtual void s1DC();
    virtual void s1E0();
    virtual void s1E4();
    virtual void s1E8();
    virtual void s1EC();
    virtual void s1F0();
    virtual void s1F4();
    virtual void s1F8();
    virtual void s1FC();
    virtual void s200();
    virtual void s204();
    virtual void call208(void* arg);  // slot 130 at vtable +0x208
};

class RGE_Combat_Object {
public:
    void* vtable_ptr;           // +0x00
    char gap_04[4];             // +0x04
    void* field_08;             // +0x08
    void* field_0C;             // +0x0C
    char gap_10[0x184 - 0x10];
    RGE_Action_List* actions;   // +0x184

    int moveTo(int param_1, float param_2, int param_3);
};

int RGE_Combat_Object::moveTo(int param_1, float param_2, int param_3)
{
    void* worldField;
    RGE_Static_Object* obj;
    void* field8;
    RGE_Action* action;
    RGE_Action_Move_To* moveAction;
    void* sprite;

    worldField = *(void**)((char*)this->field_0C + 0x3C);
    obj = ((RGE_Game_World*)worldField)->object(param_1);

    if (obj == 0)
        return 0;

    if (param_3 == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->func4C() == obj) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->func18() == 1)
                    goto success;
            }
        }
    }

    field8 = this->field_08;
    {
        void* sp = *(void**)((char*)field8 + 0xC0);
        if (sp != 0)
            sprite = sp;
        else
            sprite = *(void**)((char*)field8 + 0xBC);
    }
    moveAction = new RGE_Action_Move_To(this, obj, param_2, sprite);
    if (moveAction == 0)
        return 0;

    this->actions->delete_list();
    ((VTable208Proxy*)this)->call208(moveAction);

success:
    return 1;
}
