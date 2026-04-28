// VA: 00533E10 RGE_View::update_display_selected_objects
// view.cpp:711-759
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

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

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
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void redraw(int mode);

    unsigned char gap_04[0xF8];
    RGE_World* world;                 // +0xFC
    unsigned char gap_100[0x254];
    int* dispSelList;                 // +0x354
    int dispSelListSize;              // +0x358
    int dispSelListMax;               // +0x35C

    void update_display_selected_objects(void);
};

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
