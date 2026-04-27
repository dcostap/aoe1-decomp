// VA: 00451DF0 RGE_Master_Moving_Object::make_new_obj
// PDB source: m_mo_obj.cpp

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
    void* __fastcall RGE_Moving_Object_ctor(void* _this, void* master, void* player, float x, float y, float z, int flag);
    void* __fastcall RGE_Game_World_recycle(void* world, int type);
}

struct RGE_Master_Moving_Object {
    char gap[0xD8];
    void* make_new_obj(void* player, float x, float y, float z);
};

void* RGE_Master_Moving_Object::make_new_obj(void* player, float x, float y, float z)
{
    if (*(char*)((char*)this + 0xA4)) {
        void* world = *(void**)((char*)player + 0x3C);
        void* obj = RGE_Game_World_recycle(world, (unsigned char)*(char*)((char*)this + 0x04));
        if (obj) {
            void* vt = *(void**)obj;
            ((void(__fastcall*)(void*, void*, void*, float, float, float))((void**)vt)[1])(obj, this, player, x, y, z);
            return obj;
        }
    }
    
    void* new_obj = operator_new(0x180);
    if (new_obj) {
        return RGE_Moving_Object_ctor(new_obj, this, player, x, y, z, 1);
    }
    return 0;
}
