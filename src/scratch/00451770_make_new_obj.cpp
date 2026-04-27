// VA: 00451770 RGE_Master_Missile_Object::make_new_obj
// PDB source: m_mi_obj.cpp

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
    void* __fastcall RGE_Missile_Object_ctor(void* _this, void* master, void* player, float x, float y, float z, int flag);
    void* __fastcall RGE_Game_World_recycle(void* world, int type);
}

struct RGE_Master_Missile_Object {
    char gap[0x154];
    int make_new_obj(void* player, float x, float y, float z);
};

// This is virtual function, but for matching we only need the body
int __fastcall make_new_obj_wrap(void* obj, void* _this, void* player, float x, float y, float z);

int RGE_Master_Missile_Object::make_new_obj(void* player, float x, float y, float z)
{
    if (*(char*)((char*)this + 0xA4)) {
        void* world = *(void**)((char*)player + 0x3C);
        void* obj = RGE_Game_World_recycle(world, (unsigned char)*(char*)((char*)this + 0x04));
        if (obj) {
            void* vt = *(void**)obj;
            make_new_obj_wrap(obj, this, player, x, y, z);
            return (int)obj;
        }
    }
    
    void* new_obj = operator_new(0x1C8);
    if (new_obj) {
        return (int)RGE_Missile_Object_ctor(new_obj, this, player, x, y, z, 1);
    }
    return 0;
}
