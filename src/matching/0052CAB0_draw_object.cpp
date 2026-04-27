// VA: 0052CAB0 draw_object
// tvw_dmap.cpp lines 79-95

// Match journey:
// attempt 1: `!(flash_on) - 1` -> setne/neg basin, 50%
// attempt 2: ternary ? 0xFF : 0 -> sbb eax,eax not sbb al,al, 53%
// attempt 3: unsigned char mask -> same sbb eax,eax
// attempt 4: signed char mask -> back to setne/neg
// attempt 5: raw negate -> neg but no sbb
// attempt 6: inline ternary as param -> completely different control flow
// attempt 7: double-bang + char -> setne/neg
// variant lab r1: 22 variants, 10 groups, best=G0000 (not_int, offset 9)
// variant lab r2: 22 variants, 19 groups, EXACT MATCH in neg_equals2!
//   winning shape: if/else with explicit (unsigned char) casts on literals

class RGE_Static_Object;

class RGE_Diamond_Map {
public:
    void draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5);
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    char gap_000[0x15C];
    int draw_objects_mode;
    char gap_160[0x10];
    int flash_on;                   // +0x170

    void draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5);
};

void TRIBE_Diamond_Map_View::draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5) {
    if (this->draw_objects_mode == 4) {
        if (this->flash_on) {
            param_3 = (unsigned char)((0x57) - 1);
        } else {
            param_3 = (unsigned char)(0 - 1);
        }
    }
    ((RGE_Diamond_Map*)this)->draw_object(param_1, param_2, param_3, param_4, param_5);
}
