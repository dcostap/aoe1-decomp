// 004C7F50 TRIBE_Building_Object::TRIBE_Building_Object (t_b_obj.cpp:57-76, 311B)
// 7-param constructor with SEH, unique_build_id param, conditional setup + set_task.
//
// Left in scratch: Rebuilt is 304 bytes (no SEH frame + operator new/delete dead code)
// vs original 311 bytes (with SEH). The SEH frame (__except_handler3 FS:[0]) in the
// original is ~39 bytes (prologue ~18B, epilogue ~8B, .text$x/.xdata$x ~13B) but VC5
// 11.00.7022 with /GX does not generate it for this function despite it being a
// constructor with an initializer list calling a base constructor.
//
// SEH trigger mystery: popupOKDialog (00469F30) gets FS:[0] SEH via `new TMessageDialog()`
// expression (operator new + constructor call chain). Our constructor uses an initializer
// list to call TRIBE_Combat_Object2(mb, player, x, y, z, 0) but VC5 doesn't treat this
// as needing EH cleanup. Calling operator new directly even with volatile guard also
// doesn't trigger SEH. The SEH likely requires the actual class hierarchy with virtual
// destructors or base class members with nontrivial destructors.
//
// All field offsets confirmed correct from original asm:
//   +0x08 = object template pointer  [eax+10=type, eax+DC=task_id]
//   +0x0C = owner (RGE_Player*)      [ecx+40=doppleganger_creator]
//   +0x38 = world_x (float)
//   +0x3C = world_y (float)
//   +0x1C8 = production_queue
//   +0x1CC = production_queue_size
//   +0x1CE = production_queue_count
//   +0x1D0 = production_queue_enabled = 1
//   +0x1D4 = production_queue_actions
//   +0x1D8 = production_queue_change_flag
//   +0x1D9 = production_queue_auto_paused
//   +0x1DA = production_queue_need_attr = -1
//   +0x1E0 = unique_build_id (set from param_6)
//   +0x1E8 = DoppleInstalled (init 0, then set from add_doppleganger_check)
//   +0x1EC..+0x200 = PriorMap1-3, PriorTurn1-3 (zeroed at end)
//   vtable = 0x574778
//   base ctor TRIBE_Combat_Object(this, mb, player, x, y, z, 0)
//   setup(mb, player, x, y, z) if flag != 0
//   set_task(template.task) if template.type == 0x114
//   DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(...)
// FLAGS: /nologo /c /O2 /Oy /GX

struct RGE_Doppleganger_Creator2 {
    int add_doppleganger_check(void* obj, unsigned long* rmOffset);
};

struct RGE_Player2 {
    char _pad_00[0x40];
    RGE_Doppleganger_Creator2* doppleganger_creator; // +0x40
};

struct TRIBE_Combat_Object2 {
    char _pad_00[0x1C8];

    TRIBE_Combat_Object2(void* mb, RGE_Player2* player,
                         float x, float y, float z, int zero);
    void setup(void* mb, RGE_Player2* player,
               float x, float y, float z);
    void set_task(short task_id);
};

extern int unified_map_offsets[];

struct TRIBE_Building_Object2 : TRIBE_Combat_Object2 {
    char _pad_1C8[0x1E0 - 0x1C8];
    int unique_build_id;            // +0x1E0
    char _pad_1E4[4];               // +0x1E4
    int DoppleInstalled;            // +0x1E8
    int PriorMap1;                  // +0x1EC
    int PriorMap2;                  // +0x1F0
    int PriorMap3;                  // +0x1F4
    int PriorTurn1;                 // +0x1F8
    int PriorTurn2;                 // +0x1FC
    int PriorTurn3;                 // +0x200

    TRIBE_Building_Object2(void* mb, RGE_Player2* player,
                           float f1, float f2, float f3,
                           int unique_id, int do_setup);
};

void* __cdecl operator new(size_t s);

TRIBE_Building_Object2::TRIBE_Building_Object2(void* mb, RGE_Player2* player,
                                                float f1, float f2, float f3,
                                                int unique_id, int do_setup)
    : TRIBE_Combat_Object2(mb, player, f1, f2, f3, 0)
{
    unique_build_id = unique_id;

    *(int*)((char*)this + 0x1C8) = 0;
    *(short*)((char*)this + 0x1CC) = 0;
    *(short*)((char*)this + 0x1CE) = 0;
    *(unsigned char*)((char*)this + 0x1D0) = 1;
    *(int*)((char*)this + 0x1D4) = 0;
    *(unsigned char*)((char*)this + 0x1D8) = 0;
    *(unsigned char*)((char*)this + 0x1D9) = 0;
    *(short*)((char*)this + 0x1DA) = -1;
    *(int*)((char*)this + 0x1E8) = 0;

    *(void***)this = (void**)0x574778;

    if (do_setup) {
        setup(mb, player, f1, f2, f3);
    }

    void* templ = *(void**)((char*)this + 0x08);
    if (*(short*)((char*)templ + 0x10) == 0x114) {
        set_task(*(short*)((char*)templ + 0xDC));
    }

    int row = (int)*(float*)((char*)this + 0x3C);
    int col = (int)*(float*)((char*)this + 0x38);
    RGE_Player2* own = *(RGE_Player2**)((char*)this + 0x0C);
    DoppleInstalled = own->doppleganger_creator->add_doppleganger_check(
        this, (unsigned long*)(unified_map_offsets[row] + col * 4));

    PriorMap1 = 0;
    PriorMap2 = 0;
    PriorMap3 = 0;
    PriorTurn1 = 0;
    PriorTurn2 = 0;
    PriorTurn3 = 0;
}
