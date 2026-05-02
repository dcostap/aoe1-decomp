// RGE_Master_Action_Object::make_new_obj
// VA: 0044F5A0 (201 bytes, EH-framed)
// Factory function that creates a new action object

#include <stdlib.h>

class RGE_Master_Action_Object {
public:
    char gap_00[0x04];
    unsigned char byte_04;      // +0x04
    char gap_05[0x9B];
    unsigned char byte_A0;      // +0xA0
    char gap_A1[0x03];
    unsigned char byte_A4;      // +0xA4
    
    void* make_new_obj(void* player, float x, float y, float z);
    void* sub_alloc_00445758(void* player);  // helper
};

void* __cdecl operator_new(size_t size);

void* RGE_Master_Action_Object::make_new_obj(void* player, float x, float y, float z) {
    if (byte_A4 != 0) {
        unsigned char b = byte_04;
        void* obj = sub_alloc_00445758(player);
        if (obj != 0) {
            void** vtable = *(void***)obj;
            ((void(__thiscall*)(void*, void*, int, void*, void*, float, float, float, float))vtable[1])(obj, this, 1, player, 0, x, y, z, 0.0f);
            return obj;
        }
        return 0;
    }
    
    void* obj = operator_new(0x194);
    if (obj != 0) {
        ((void(__thiscall*)(void*, void*, int, void*, float, float, float, float))0x00443E21)(obj, this, 1, player, x, y, z, 0.0f);
        return obj;
    }
    return 0;
}
