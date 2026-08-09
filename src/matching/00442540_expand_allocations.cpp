// VA: 00442540 expand_allocations
// PDB source: dpl_obj.cpp
// Size: 315 bytes (correct)
// Attempt log:
// - Prior attempts across: extern vs intrinsic memcpy, variable scope/order, temp vars,
//   calloc argument patterns. All produce correct-size 315B but the register allocation
//   for calloc 1's "new_size" argument differs:
//     Original: mov edx,[ebx+4]; ... mov eax,edx; mov [ebx+4],edx; push eax
//     Rebuilt before the final probe: mov eax,[ebx+4]; ... push eax; mov [ebx+4],eax
// - Final source-shape probe: direct `allocated_size += grow_size` followed by
//   `calloc(this->allocated_size, 4)` restores the original store/push schedule and
//   matches all 315 bytes. This is the natural period source form.

extern "C" void* __cdecl memcpy(void* dst, const void* src, int size);
#pragma intrinsic(memcpy)

extern "C" void* __cdecl calloc(int num, int size);
extern "C" void  __cdecl free(void* ptr);

struct FILE;
extern int __cdecl fprintf(FILE* stream, const char* format, ...);

extern FILE* DDlogf;

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    int world_time;  // +0x04
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;  // +0x3C
    char gap_40[0x0A];
    short id;  // +0x4A
};

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;          // +0x00
    int allocated_size;         // +0x04
    int active_size;            // +0x08
    void** Objects;             // +0x0C
    void** Map_Addresses;       // +0x10
    void*  Last_Map_Value;      // +0x14
    int*   Object_ids;          // +0x18

    void expand_allocations(int grow_size);
};

void RGE_Doppleganger_Creator::expand_allocations(int grow_size)
{
    if (DDlogf != 0) {
        fprintf(DDlogf, "RESIZE (@%d) p=%d  grow=%d\n",
            this->owner->world->world_time,
            (int)this->owner->id,
            grow_size);
    }

    this->allocated_size += grow_size;

    void* r0 = calloc(this->allocated_size, 4);
    void* r1 = calloc(this->allocated_size, 4);
    void* r2 = calloc(this->allocated_size, 4);
    void* r3 = calloc(this->allocated_size, 4);

    memcpy(r0, this->Objects, this->active_size * 4);
    memcpy(r1, this->Map_Addresses, this->active_size * 4);
    memcpy(r2, this->Last_Map_Value, this->active_size * 4);
    memcpy(r3, this->Object_ids, this->active_size * 4);

    free(this->Objects);
    free(this->Map_Addresses);
    free(this->Last_Map_Value);
    free(this->Object_ids);

    this->Objects = (void**)r0;
    this->Map_Addresses = (void**)r1;
    this->Last_Map_Value = r2;
    this->Object_ids = (int*)r3;
}
