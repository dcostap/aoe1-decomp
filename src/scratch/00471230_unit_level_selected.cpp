// attempt 1: control flow layout different, vtable offset wrong
// attempt 2: goto across init, compile error
// attempt 3: while loop, VC5 optimized to test bx,bx
// attempt 4: same optimization issue
// attempt 5: do-while with inner return, same test bx,bx optimization
// left in scratch: VC5 optimizes "j starts at 0, j>=sel_count" to "test bx,bx; jle"
// original has explicit "cmp di,bx; jge" — source shape not found

class RGE_Master_Object {
public:
    char gap_00[0x8F];
    unsigned char unit_level;
};

class RGE_Static_Object {
public:
    void* _vftable;
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

unsigned char RGE_Player::unit_level_selected() {
    unsigned char u = 0;
    short i = 0, j = 0;
    do {
        if (j >= sel_count) return u;
        RGE_Static_Object* p = sel_list[i];
        if (p != 0) {
            if (j != 0 && p->master_obj->unit_level != u) return 0;
            j++;
            u = p->master_obj->unit_level;
        }
        i++;
    } while (i < 25);
    return u;
}
