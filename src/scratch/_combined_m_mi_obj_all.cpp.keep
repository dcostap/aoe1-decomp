// VA multiple: m_mi_obj.cpp TU
// 00451530 RGE_Master_Missile_Object (constructor)
// 00451620 setup
// 004516C0 setup (file-based)
// 00451770 make_new_obj
// 004519A0 save

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
    void rge_read(int fd, void* buf, int size);
    int fscanf(void* file, const char* fmt, ...);
    void* __cdecl operator_new(size_t size);
}

// RGE_Master_Missile_Object class layout (0x154 bytes total)
class RGE_Master_Combat_Object {
public:
    // +0x000: vtable (4 bytes)
    // +0x004..+0x148: inherited fields (0x144 bytes from RGE_Master_Combat_Object chain)
    char gap_004_to_148[0x144]; // placeholder for inherited fields
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    // Fields discovered from asm:
    // +0x004: field_04 (byte) - set to 0x3C in setup
    // +0x0A4: recycle_flag (byte) - set to 1 in file-based setup
    // +0x148: missile_type (byte)
    // +0x149: targetting_type (byte)
    // +0x14A: missile_hit_info (byte)
    // +0x14B: missile_die_info (byte)
    // +0x14C: area_effect_specials (byte)
    // +0x150: ballistics_ratio (float)
    
    // Constructor
    RGE_Master_Missile_Object();
    // Setup overloads
    int setup(int param_1, void** param_2, void** param_3);
    int setup(void* param_1, void** param_2, void** param_3, short param_4);
    // Virtual methods
    void save(int fd);
    void* make_new_obj(void* player, float x, float y, float z);
};

// Forward declarations for base class constructors/methods
extern "C" void __fastcall RGE_Master_Combat_Object_ctor(void* _this, void* a, void* b, void* c, short d, int e);
extern "C" int __fastcall RGE_Master_Combat_Object_setup_int(void* _this, int a, void* b, void* c);
extern "C" int __fastcall RGE_Master_Combat_Object_setup_file(void* _this, void* a, void* b, void* c, short d);
extern "C" void __fastcall RGE_Master_Combat_Object_save(void* _this, int fd);

extern "C" void* __fastcall RGE_Missile_Object_ctor(void* _this, void* master, void* player, float x, float y, float z, int flag);

extern "C" void* __fastcall RGE_Game_World_recycle(void* world, int type);

extern void* rge_base_game;  // 0x62C574

// ========== 00451530 Constructor ==========
// __thiscall RGE_Master_Missile_Object(void* file, void** sprites, void** sounds, short sprite_type, int do_setup)
RGE_Master_Missile_Object::RGE_Master_Missile_Object()
{
}

// ========== 00451620 setup (int-based) ==========
// Called from constructor when active (do_setup != 0)
int RGE_Master_Missile_Object::setup(int param_1, void** param_2, void** param_3)
{
    RGE_Master_Combat_Object_setup_int(this, param_1, param_2, param_3);
    
    *(char*)((char*)this + 0x04) = 0x3C;
    
    rge_read(param_1, (char*)this + 0x148, 1);
    rge_read(param_1, (char*)this + 0x149, 1);
    rge_read(param_1, (char*)this + 0x14A, 1);
    rge_read(param_1, (char*)this + 0x14B, 1);
    rge_read(param_1, (char*)this + 0x14C, 1);
    rge_read(param_1, (char*)this + 0x150, 4);
    
    return 1;
}

// ========== 004516C0 setup (file-based) ==========
int RGE_Master_Missile_Object::setup(void* param_1, void** param_2, void** param_3, short param_4)
{
    RGE_Master_Combat_Object_setup_file(this, param_1, param_2, param_3, param_4);
    
    *(char*)((char*)this + 0x0A4) = 1;
    *(char*)((char*)this + 0x04) = 0x3C;
    
    // fscanf(file, "%hd %hd %hd %hd %hd %f", ...)
    short vals[5];
    float fval;
    fscanf(param_1, "%hd %hd %hd %hd %hd %f",
        &vals[0], &vals[1], &vals[2], &vals[3], &vals[4], &fval);
    
    *(char*)((char*)this + 0x149) = (char)(vals[3] & 0xFF);   // targetting_type
    *(char*)((char*)this + 0x14A) = (char)(vals[2] & 0xFF);   // missile_hit_info
    *(char*)((char*)this + 0x14B) = (char)(vals[1] & 0xFF);   // missile_die_info
    *(char*)((char*)this + 0x14C) = (char)(vals[0] & 0xFF);   // area_effect_specials
    *(char*)((char*)this + 0x148) = (char)(vals[4] & 0xFF);   // missile_type (from fscanf as %hd, stored wherever)
    
    // Note: the fscanf stores sequentially on the stack:
    // [esp+0Ah] = local_2 = first short scanned (missile_type)
    // ...
    // The actual field mapping is complex due to stack layout
    
    return 1;
}

// ========== 00451770 make_new_obj ==========
// Virtual: tries to recycle, else allocates new RGE_Missile_Object
void* RGE_Master_Missile_Object::make_new_obj(void* player, float x, float y, float z)
{
    if (*(char*)((char*)this + 0x0A4)) {
        void* world = *(void**)((char*)player + 0x3C); // player->world
        void* obj = RGE_Game_World_recycle(world, *(char*)((char*)this + 0x04));
        if (obj) {
            // Call setup virtual through vtable
            void* vt = *(void**)obj;
            ((void(__fastcall*)(void*, void*, void*, float, float, float))((void**)vt)[1])(obj, this, player, x, y, z);
            return obj;
        }
    }
    
    // Fall through: allocate new missile
    void* new_obj = operator_new(0x1C8);
    if (new_obj) {
        return RGE_Missile_Object_ctor(new_obj, this, player, x, y, z, 1);
    }
    return 0;
}

// ========== 004519A0 save ==========
void RGE_Master_Missile_Object::save(int fd)
{
    RGE_Master_Combat_Object_save(this, fd);
    
    rge_write(fd, (char*)this + 0x148, 1);
    rge_write(fd, (char*)this + 0x149, 1);
    rge_write(fd, (char*)this + 0x14A, 1);
    rge_write(fd, (char*)this + 0x14B, 1);
    rge_write(fd, (char*)this + 0x14C, 1);
    rge_write(fd, (char*)this + 0x150, 4);
}
