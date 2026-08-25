// attempt 1: control flow layout different, vtable offset wrong
// attempt 2: goto across init, compile error
// attempt 3: while loop, VC5 optimized to test bx,bx
// attempt 4: same optimization issue
// attempt 5: do-while with inner return, same test bx,bx optimization
// exact basin: a counted `for (; i < 25; i++)` loop with the `j >= sel_count` guard at the top preserves the original `cmp di,bx; jge` instead of collapsing to `test bx,bx; jle`
#ifndef PLAYER_GROUPED_TU
class RGE_Master_Object {
public:
    char gap_00[0x8F];
    unsigned char unit_level;
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x4];
    RGE_Master_Object* master_obj;
};

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    char gap_198[0x4];
    short sel_count;

    unsigned char unit_level_selected();
};
#endif

unsigned char RGE_Player::unit_level_selected() {
    unsigned char u = 0;
    short i = 0, j = 0;
    for (; i < 25; i++) {
        if (j >= sel_count) return u;
        RGE_Static_Object* p = sel_list[i];
        if (p != 0) {
            if (j != 0 && p->master_obj->unit_level != u) return 0;
            j++;
            u = p->master_obj->unit_level;
        }
    }
    return u;
}
