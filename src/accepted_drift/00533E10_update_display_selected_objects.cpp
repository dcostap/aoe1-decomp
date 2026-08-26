// VA: 00533E10 RGE_View::update_display_selected_objects
// view.cpp:711-759
// ACCEPTED_DRIFT 2026-05-20 Boss: exact size; reviewed nonzero diff as behavior-equivalent register allocation/encoding drift in the selected-object update loop. Control flow, calls, stack, memory targets, loop bounds, list-size updates, object lookup, and selected-bit effects are preserved; remaining differences are object/elapsed register coloring and equivalent byte RMW vs direct and/or encodings with shifted branch displacements.
// 
// Attempt log (~10 probes):
// v0: struct-based entry, if-else-if-else — far off (prolog, pointer math, shared tail)
// v1: char* base+offset, do-while — better prolog, but add ecx,10h optimization
// v2: goto approach — first 32 bytes matching, rest alloc-basin drift
// v3: raw ptr arithmetic — prolog + test jle now matching
// v4: if (max>0) + inner offset decl — prolog perfect (push ebp; push esi; ...xor ebp, ebp; test ecx; jle)
// v5: goto with function-scope vars — prolog push ebx/ebp/esi
// v6: Ghidra-style else-if(bit8) pattern + shared tail — 80% matching
// v7: else-if(!(elapsed & 0x100)) with goto for set-flag-jump — 130/162 matching
// Fresh pass 2026-05-19:
// v8: hoisted obj initializer and elapsed declaration; no codegen change.
// v9: explicit objects-array local; no codegen change.
// v10: compound |= / &= selected updates; no codegen change.
// v11: selected byte pointer locals; no codegen change.
// v12: compute elapsed before object lookup; worsened badly to 149/162 positional and prologue drift; rolled back.
// 
// Remaining diff (32 bytes, ~20%): register allocation swap
//   - obj in edi instead of edx (mov edi,[edi+edx*4] vs mov edx,[edi+edx*4])
//   - elapsed in edx instead of edi (mov edx,eax vs mov edi,eax)
//   - test dh,1 instead of test edi,100h (same test, different reg)
//   - RMW for selected instead of direct and/or [mem] — consequence of reg alloc
//   - All jump offsets differ slightly due to encoding
// 
// This is benign VC5 register scheduling drift. Behavior and structure match.
// Parked in scratch.
// Retry 2026-05-20 Boss pass: revalidated baseline (162B, 33.3333% positional,
// 20.3704% edit, first mismatch +33). Tried 15 more probes: raw selected byte
// lvalues, explicit object-index/objects-array locals, computing elapsed before
// object lookup, char* entry/void* object raw addressing, reversed timeout compare,
// positive `elapsed & 0x100` test shape, /O2 without /Oy, /Ox, /Oa, /Og, /O1,
// volatile selected field, register elapsed, register obj, and split entry declaration.
// None changed the core allocation basin; volatile selected slightly improved metrics
// (32.7160% positional / 19.7531% edit) but only by changing byte-store lowering and
// was not kept. Baseline remains the cleanest behavior-equivalent source.
// ACCEPTED_DRIFT proposal: same control flow, calls, stack, memory targets, loop bounds,
// list-size updates, object lookups, and selected-bit effects. Remaining bytes are
// register allocation/encoding drift (object in EDI vs original EDX, elapsed in EDX vs
// original EDI, `test dh,1` vs `test edi,100h`, and read/modify/write selected byte vs
// direct `and/or [obj+36],cl`), with branch displacements shifted by those encodings.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Static_Object {
public:
    unsigned char gap_00[0x36];
    unsigned char selected;
};

class RGE_World {
public:
    unsigned char gap_00[0x88];
    RGE_Static_Object** objectsValue;
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void release_mouse();
    virtual void set_focus(int);
    virtual void redraw(int mode);

    unsigned char gap_04[0xF8];
    RGE_World* world;                 // +0xFC
    unsigned char gap_100[0x254];
    int* dispSelList;                 // +0x354
    int dispSelListSize;              // +0x358
    int dispSelListMax;               // +0x35C

    void update_display_selected_objects(void);
};
#endif

void RGE_View::update_display_selected_objects(void) {
    unsigned long curTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x2CB);
    int i = 0;

    if (this->dispSelListMax <= 0)
        return;

    {
        int offset = 0;

        do {
            int* entry = (int*)((unsigned char*)this->dispSelList + offset);
            if (entry[0]) {
                RGE_Static_Object* obj;
                obj = this->world->objectsValue[entry[1]];
                if (obj == 0) {
                    entry[0] = 0;
                    this->dispSelListSize = this->dispSelListSize - 1;
                } else {
                    unsigned long elapsed = curTime - (unsigned long)entry[2];
                    if (elapsed > (unsigned long)entry[3]) {
                        entry[0] = 0;
                        this->dispSelListSize = this->dispSelListSize - 1;
                    } else if (!(elapsed & 0x100)) {
                        obj->selected = obj->selected | ((unsigned char)entry[4]);
                        goto next_entry;
                    }
                    obj->selected = obj->selected & ~((unsigned char)entry[4]);
                }
            }
next_entry:
            ++i;
            offset += 0x14;
        } while (i < this->dispSelListMax);
    }
}
