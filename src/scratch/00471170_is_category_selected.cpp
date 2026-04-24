// attempt 1: prologue order differs, loop uses dword instead of short
// attempt 2: short return + do-while, better but reg order still differs
// attempt 3: int loop counters + do-while, reg allocation still different
// left in scratch: original has specific short-register usage (bx=sel_count, di=category,
// dx=loop counter, si=match counter) and prologue order
// (push ebx; mov bx,[ecx+19Ch]; push esi; push edi) that VC5 doesn't replicate
// behavior fully correct: iterates sel_list, checks master_obj->id == category
// remaining gap: codegen basin not found, prologue and register choices differ

class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[0x19];
    char gap_198[4];
    short sel_count;

    int is_category_selected(short category);
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Static_Object* master_obj;
    char gap_0c[0x4];
    short id;
};

int RGE_Player::is_category_selected(short category) {
    int i = 0;
    int matches = 0;
    do {
        if (matches >= sel_count) return 0;
        RGE_Static_Object* obj = sel_list[i];
        if (obj != 0) {
            matches++;
            if (obj->master_obj->id == category) return 1;
        }
        i++;
    } while (i < 0x19);
    return 0;
}
