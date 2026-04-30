// VA: 004C58C0 more_room (19B, stat_obj.cpp)
// Returns 1 if objects->number_of_objects < master_obj->obj_max
//
// Original asm:
//   mov eax,[ecx+24h]           ; objects
//   mov ecx,[ecx+8]             ; master_obj (reuses ecx register)
//   movzx dx,byte [ecx+2Ch]     ; obj_max
//   cmp [eax+8],dx              ; compare objects->count with obj_max
//   setl al                     ; result
//   ret
//
// Left in scratch: VC5 evaluates master_obj before objects (wrong register reuse),
// adds xor ecx,ecx (dead register), and truncates setl al + ret.
// All source variants produce same code.

class RGE_Object_List {
public:
    char gap_00[8];
    short number_of_objects; // +0x08
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x2C];
    unsigned char obj_max; // +0x2C
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x18];
    RGE_Object_List* objects; // +0x24

    unsigned char more_room();
};

unsigned char RGE_Static_Object::more_room() {
    return this->objects->number_of_objects < (short)(unsigned short)this->master_obj->obj_max;
}
