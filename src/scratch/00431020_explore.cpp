// VA: 00431020, RGE_Combat_Object::explore, 298 bytes
// Source: com_obj.cpp lines 1046-1091
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Action_List {
public:
    char gap_00[8];
    void* list;  // +0x08

    uchar have_action();
    void* get_action();
    void delete_list();
};

// Full RGE_Action layout from type dump (0x40 bytes)
// vtable pointer at +0x00 (implicit from virtual functions)
class RGE_Action {
public:
    short action_type;            // +0x04
    char pad_06[2];               // +0x06
    void* obj;                    // +0x08
    uchar state;                  // +0x0C
    char pad_0D[3];               // +0x0D
    void* target_obj;             // +0x10
    void* target_obj2;            // +0x14
    int targetID;                 // +0x18
    int target2ID;                // +0x1C
    float target_x;               // +0x20
    float target_y;               // +0x24
    float target_z;               // +0x28
    float timer;                  // +0x2C
    void* task;                   // +0x30
    void* sub_actions;            // +0x34
    void* sprite;                 // +0x38
    uchar subActionValue;         // +0x3C
    char pad_3D[3];               // +0x3D

    virtual ~RGE_Action();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual short func18();       // slot 6 at vtable +0x18
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void call34(float, float, int); // slot 13 at vtable +0x34
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void* func4C();
};

// RGE_Action_Explore has no extra fields beyond RGE_Action (sizeof = 0x40)
class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(void* obj, void* task_val, float x, float y, float z);
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
    char gap_0C[0x34];          // +0x0C to +0x3F
    void* field_40;             // +0x40
    char gap_44[0x140];         // +0x44 to +0x183
    RGE_Action_List* actions;   // +0x184

    void set_action(RGE_Action* action);
    int explore(int param_1, int param_2, int param_3);
};
#endif

int RGE_Combat_Object::explore(int param_1, int param_2, int param_3)
{
    if (param_3 == 0) {
        if (actions->have_action() == 1) {
            RGE_Action* action = (RGE_Action*)actions->get_action();
            if (action->func18() == 4)
                goto done;
        }
    }

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->func18() == 4) {
            action = (RGE_Action*)actions->get_action();
            action->call34((float)param_1, (float)param_2, 0);
            goto done;
        }
    }

    {
        RGE_Action_Explore* explore_action = new RGE_Action_Explore(this, 0, (float)param_1, (float)param_2, *(float*)&field_40);
        if (explore_action == 0)
            return 0;

        actions->delete_list();
        this->set_action(explore_action);
    }

done:
    return 1;
}
