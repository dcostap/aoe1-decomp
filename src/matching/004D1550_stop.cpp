// 004D1550 TRIBE_Action_Make_Obj::stop
// Size: 150 bytes

#ifndef TACT_MOB_SHARED_CONTEXT
extern void* rge_base_game;

class TRIBE_Player {
public:
    void reimburse_obj_cost(short obj_id);
    char gap_04[0x46];
    short player_id; // +0x4A
};
class RGE_Base_Game_Hack {
public:
    virtual ~RGE_Base_Game_Hack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void slot16(int a, int b, int c, int d, int e); // slot 16 (0x40)
};

class PlayerVTableHack {
public:
    virtual ~PlayerVTableHack();
    // 49 filler methods to reach slot 82
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void vE4(); virtual void vE8(); virtual void vEC(); virtual void vF0();
    virtual void vF4(); virtual void vF8(); virtual void vFC(); virtual void v100();
    virtual void v104(); virtual void v108(); virtual void v10C(); virtual void v110();
    virtual void v114(); virtual void v118(); virtual void v11C(); virtual void v120();
    virtual void v124(); virtual void v128(); virtual void v12C(); virtual void v130();
    virtual void v134(); virtual void v138(); virtual void v13C(); virtual void v140();
    virtual void v144();
    virtual void slot82(int a, int b, int c, int d, int e, int f); // slot 82 (0x148)
};

class ObjectHack {
public:
    virtual ~ObjectHack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void vE4(); virtual void vE8(); virtual void vEC(); virtual void vF0();
    virtual void vF4(); virtual void vF8(); virtual void vFC(); virtual void v100();
    virtual void v104(); virtual void v108(); virtual void v10C(); virtual void v110();
    virtual void v114(); virtual void v118(); virtual void v11C(); virtual void v120();
    virtual void v124(); virtual void v128(); virtual void v12C(); virtual void v130();
    virtual void v134(); virtual void v138(); virtual void v13C(); virtual void v140();
    virtual void v144();
    virtual void slot148(int a, int b, int c, int d, int e, int f); // slot 82 (0x148)
};


class TRIBE_Action_Make_Obj_Base {
public:
    virtual ~TRIBE_Action_Make_Obj_Base();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58();
    virtual void slot23(int a); // slot 23 (0x5C)
};

class TRIBE_Action_Make_Obj : public TRIBE_Action_Make_Obj_Base {
public:
    int stop();
    char gap_04[4];
    void* obj;              // +0x08
    char field_0C;           // +0x0C
    char gap_0D[0x33];       // +0x0D to +0x3F
    short obj_id;           // +0x40
    char gap_42[6];          // +0x42 to +0x47
    int unique_id;           // +0x48
    char pre_paid;           // +0x4C
};
#endif

int TRIBE_Action_Make_Obj::stop() {
    void* obj_field_0C = *(void**)((char*)this->obj + 0x0C);
    int field_04 = *(int*)((char*)this->obj + 4);

    // Debug log via vtable slot 0xE4 (__cdecl, caller cleans)
    (*(void(__cdecl*)(void*, const char*, int, int, int))(
        *(int*)(*(int*)obj_field_0C + 0xE4)))(
        obj_field_0C, (const char*)0x587788,
        (int)this->obj_id, field_04, this->unique_id);

    if (this->field_0C != 1) {
        ((TRIBE_Action_Make_Obj_Base*)this)->slot23(1);
        if (!this->pre_paid) {
            ((TRIBE_Player*)(*(void**)((char*)this->obj + 0x0C)))->reimburse_obj_cost(this->obj_id);
        }
    }

#ifdef TACT_MOB_SHARED_CONTEXT
    ((RGE_Base_Game_Hack*)rge_base_game)->display_message(0x67,
#else
    ((RGE_Base_Game_Hack*)rge_base_game)->slot16(0x67,
#endif
        *(short*)(*(int*)((char*)this->obj + 0x0C) + 0x4A),
        (int)this->obj_id, 0, 0);

    {
        int f04 = *(int*)((char*)this->obj + 4);
        ((ObjectHack*)this->obj)->slot148(f04, f04, 0x1F9, 0x26B, 0, 0);
    }

    return 1;
}
