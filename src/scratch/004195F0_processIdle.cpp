// attempt 1: full vtable (36 slots), .text 80 instead of 82
// attempt 2-3: minimal class, still 80
// attempt 4: if/else if/else structure, still 80
// attempt 5: early return guards, still 80
// attempt 6: match original control flow (no else), still 80
// attempt 7: include stdlib.h, still 80
// attempt 8: unsigned char return/params, still 80
// attempt 9: expanded conditions + /G5, still 80
// attempt 10: /GX, still 80
// attempt 11: /Od, still 80
// attempt 12: unused local var, still 80
// left in scratch: VC5 consistently compiles to 80 bytes regardless of source shape/flags
// behavior fully correct: param==1 guard -> vtable call -> cmp 8 -> return 6
// fallthrough: vtable call(1,0,0) -> cmp -1 -> vtable call -> cmp 1 -> return 6, else return 5
// remaining gap: 2-byte size deficit, codegen basin not found after 12 meaningful attempts

class UnitAIModule {
public:
    int get_type();
    int find_unit(int, int, int);
    int do_stuff(int, int);

    int processIdle(int param);
};

int UnitAIModule::processIdle(int param) {
    if (param == 1) {
        int type = get_type();
        if (type == 8) return 6;
    }
    int idx = find_unit(1, 0, 0);
    if (idx != -1) {
        int result = do_stuff(idx, 1);
        if (result == 1) return 6;
    }
    return 5;
}
