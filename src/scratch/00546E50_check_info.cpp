// zone_map.cpp:272-294, 90 bytes
// attempt 1: 47.8%, fcomp qword [0] vs [577A20h], wrong field offsets
// attempt 2: 66.7%, >= 0.0 wrong polarity
// attempt 3: 65.6%, fixed offsets but fcomp [0] still wrong
// attempt 4: inline asm forbidden, back to C source
// attempt 5: 86.7%, raw pointers worse
// attempt 6: 47.8%, same as attempt 1
// BEST: 47.8% (attempts 1,6). FPU loop shape mostly correct.
// BLOCKER: VC5 uses fcomp qword [0] (inline zero) while original uses
//   fcomp qword [577A20h] (global double constant). This changes jump polarity
//   (jne vs je) in the FPU status test branch. Also: class field offsets wrong
//   ([ecx+4] vs [ecx+514h]).
extern double g_zero_double;

class RGE_Zone_Map {
public:
    float* terrain_passability_rules;
    int terrain_passability_rules_num;

    RGE_Zone_Map* check_info(float* input, long count);
};

RGE_Zone_Map* RGE_Zone_Map::check_info(float* input, long count) {
    if (count != terrain_passability_rules_num) {
        return 0;
    }
    for (int i = 0; i < terrain_passability_rules_num; i++) {
        if (input[i] > 0.0) {
            if (terrain_passability_rules[i] <= 0.0) {
                return 0;
            }
        } else if (terrain_passability_rules[i] > 0.0) {
            return 0;
        }
    }
    return this;
}
