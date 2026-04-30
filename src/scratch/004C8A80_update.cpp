// 004C8A80 TRIBE_Building_Object::update()
// Source: t_b_obj.cpp lines 402-455
// Size: 241 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 TU-context drift (virtual dispatch calling convention)
//
// Attempt log:
// Probe 1: TRIBE_Combat_Object methods had stub bodies, pushed code
// Probe 2: extern __stdcall — wrong calling convention
// Probe 3: extern base class members without bodies — no stub issue, FPU too complex
// Probe 4: single expression FPU — 64.7% edit diff, push ecx vs sub esp,8
// Probe 5: minimize locals, add ftol — 13.7% edit diff, 222/241 match
// Probe 6: (short)result for signed jge — 13.3% edit diff, 223/241 match
//
// Key findings:
// - Field offsets correct: ptr_10(+0x10), ptr_08(+0x08), field_35(+0x35)
//   status_field(+0x48), build_pts(+0x1DC), PriorMap[123](+0x1EC/0xF0/0xF4)
//   PriorTurn[123](+0x1F8/0xFC/0x200), prior_map_val(+0x1B8)
// - FPU: fild(some_short_int) → fmul build_pts → fidiv max_val → __ftol
// - FPU comparison: fild(max_val) → fcomp build_pts → fnstsw/test ah,41h
// - Use `push ecx` for 1 local = 4 bytes
// - External: world_update_counter at [886C10h]
// - Forward-declared base methods: TRIBE_Combat_Object::update (004CA5F0h),
//   empty_production_queue (004C9D20h), update_production_queue (004C9DA0h)
// - ((short)result < some_short) → cmp cx, di; jge (signed)
//   ((unsigned short)result < some_short) → cmp cx, di; jae (unsigned)
//
// Remaining drift (32 edit bytes, VC5 TU-context):
// - Virtual call vtable[0x5C] uses __cdecl (push esi; add esp,8) instead
//   of __thiscall (mov ecx, esi) — can't match without full class vtable
// - Jump offsets cascade (+2 bytes from virtual call cleanup)
// - movsx ecx,di before movsx edx,[ebx+15Ah] (instruction scheduling)

extern unsigned long world_update_counter;

struct TRIBE_Combat_Object {
    unsigned char update();
    void empty_production_queue();
    void update_production_queue();
};

struct TRIBE_Building_Object {
    char vtable_ptr[4];           // +0x00
    char pad_04[0x08 - 0x04];
    void* ptr_08;                 // +0x08
    char pad_0C[0x10 - 0x0C];
    void* ptr_10;                 // +0x10
    char pad_14[0x35 - 0x14];
    unsigned char field_35;       // +0x35
    char pad_36[0x48 - 0x36];
    unsigned char status_field;   // +0x48
    char pad_49[0x1B8 - 0x49];
    unsigned long prior_map_val;  // +0x1B8
    char pad_1BC[0x1DC - 0x1BC];
    float build_pts;              // +0x1DC
    char pad_1E0[0x1EC - 0x1E0];
    unsigned long PriorMap1;      // +0x1EC
    unsigned long PriorMap2;      // +0x1F0
    unsigned long PriorMap3;      // +0x1F4
    long PriorTurn1;              // +0x1F8
    long PriorTurn2;              // +0x1FC
    long PriorTurn3;              // +0x200

    unsigned char update();
};

unsigned char TRIBE_Building_Object::update()
{
    if (status_field == 0) {
        unsigned char result = (unsigned char)(
            (long)((float)(int)*(short*)((char*)ptr_10 + 0x60) * build_pts / *(short*)((char*)ptr_08 + 0x15A))
        );

        if ((short)result < *(short*)((char*)ptr_10 + 0x60) && result != field_35)
            field_35 = result;

        if ((float)*(short*)((char*)ptr_08 + 0x15A) <= build_pts) {
            ((void (*)(TRIBE_Building_Object*, int))(((void***)this)[0][0x5C / 4]))(this, 2);
        }
    }

    PriorMap3 = PriorMap2;
    PriorMap2 = PriorMap1;
    PriorTurn3 = PriorTurn2;
    PriorTurn2 = PriorTurn1;
    PriorTurn1 = (long)world_update_counter;

    unsigned char base_result = ((TRIBE_Combat_Object*)this)->update();

    if (status_field > 2) {
        ((TRIBE_Combat_Object*)this)->empty_production_queue();
        PriorMap1 = prior_map_val;
    } else {
        ((TRIBE_Combat_Object*)this)->update_production_queue();
        PriorMap1 = prior_map_val;
    }

    return base_result;
}
