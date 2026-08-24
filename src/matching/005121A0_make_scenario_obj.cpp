// 005121A0 TRIBE_Player::make_scenario_obj
// tplayer.cpp lines 356-380
// Fresh 2026-05-19: replace stub with packet-derived virtual factory logic.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object_Type;
class RGE_Static_Object;
class TRIBE_Building_Object;

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Static_Object_Type** object_types; // +0x24
};

class RGE_Static_Object_Type {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual RGE_Static_Object* make_scenario_obj(RGE_Player* player, float x, float y, float z); // +0x18
    unsigned char object_group; // +0x04 (data layout for type records)
};

class RGE_Static_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void action_ge7(); // +0x68
    virtual void action_3to6(); // +0x6C
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void action_range(float f); // +0xB4
    char gap_04[4];
    RGE_Static_Object_Type* type; // +0x08
    char gap_0C[0x35 - 0x0C];
    unsigned char field_35;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    unsigned char build(float amount);
};

class TRIBE_Player : public RGE_Player {
public:
    RGE_Static_Object* make_scenario_obj(float x, float y, float z, short type_id, unsigned char mode, float amount);
};
#endif

extern "C" long __cdecl _ftol();

RGE_Static_Object* TRIBE_Player::make_scenario_obj(float x, float y, float z, short type_id, unsigned char mode, float amount)
{
    RGE_Static_Object* obj = 0;
    RGE_Static_Object_Type* type = this->object_types[type_id];
    if (type) {
        obj = type->make_scenario_obj(this, x, y, z);
        if (mode >= 7) {
            obj->action_ge7();
        }
        else if (mode > 2) {
            obj->action_3to6();
        }
        else {
            unsigned char group = obj->type->object_group;
            if (group > 0x1E && group < 0x5A) {
                obj->action_range(amount);
            }
            else {
                obj->field_35 = (unsigned char)(int)amount;
            }
        }
        if (this->object_types[type_id]->object_group == 0x50 && mode == 2) {
            ((TRIBE_Building_Object*)obj)->build(10000.0f);
        }
    }
    return obj;
}
