// 00533EC0 RGE_View::display_object_selection
// Source: view.cpp lines 765-804
// Attempt log:
// initial: 87% diff — missing vtable pointer, wrong field offsets.
// added virtuals to RGE_View: offsets correct, remaining diff 48%.
// split i to function scope, do-while loop: diff dropped to 15 edit bytes.
// tried swapping slot/key order; removing key local; function-scope slot init.
// Round2: tried stack-load forcing variants for param_4 (slot before key, declaration init,
// volatile key/slot/both, pointer alias, char* arithmetic, extra temp). All stayed in the
// same 163-byte shifted form: VC5 uses mov edi,ebp instead of original stack reload.
// ACCEPTED_DRIFT_CANDIDATE: exact size; remaining diff is localized register reuse of
// param_4 for slot initialization, shifting subsequent code by 2 bytes. Behavior/memory/calls match.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

#ifndef RGE_VIEW_SHARED_CONTEXT
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

    char gap_04[0x350];
    int* dispSelList;       // +0x354
    int dispSelListSize;    // +0x358
    int dispSelListMax;     // +0x35C

    void display_object_selection(int param_1, int param_2, int param_3, int param_4);
};
#endif

void RGE_View::display_object_selection(int param_1, int param_2, int param_3, int param_4)
{
    int found = 0;
    int i = 0;
    int* slot;

    if (this->dispSelListMax > 0) {
        int key = param_4;
        slot = (int*)param_4;
        int offset = 0;

        do {
            int* entry = (int*)((char*)this->dispSelList + offset);
            if (*entry == 0) {
                found = 1;
                slot = entry;
            } else if (key != 0 && entry[4] == key) {
                entry[2] -= entry[3];
            }
            i++;
            offset += 0x14;
        } while (i < this->dispSelListMax);
    } else {
        slot = (int*)param_4;
    }

    if (found) {
        *slot = 1;
        slot[1] = param_1;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x31d);
        slot[2] = now;
        slot[3] = param_2;
        slot[4] = param_3;
        this->dispSelListSize++;
    }
}
