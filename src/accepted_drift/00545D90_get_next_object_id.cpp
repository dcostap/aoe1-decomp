// VA: 00545D90 RGE_Game_World::get_next_object_id (62B)
// PDB source: World.cpp lines 3636-3651
// __thiscall, no params, returns long.
// For-loop form.

#define NULL 0
class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x68];
    int next_object_id;                     // +0x68
    char gap_6C[0x04];                      // +0x6C
    int scenario_object_id;                 // +0x70
    unsigned char scenario_object_flag;     // +0x74
    char gap_75[0x13];                      // +0x75-0x87
    RGE_Static_Object** objectsValue;       // +0x88
    char gap_8C[0x04];                      // +0x8C-0x8F
    int maxNumberObjectsValue;              // +0x90

    long get_next_object_id();
};

// ACCEPTED_DRIFT: 52/62 bytes exact (84%). Remaining 14B diff:
// - Prologue: max→edx instead of max→eax (lea edx,[eax-1] vs dec edx)
//   VC5 register allocator prefers edx for maxNumberObjectsValue.
// - cmp+push order: `cmp edx,eax; push esi` vs `push esi; cmp eax,edx`
//   (swap operands → different branch condition encoding: jl vs jg, jge vs jle)
// Loop body (reload→slot_check→advance→bound_check→store→loop) is identical.
// All field offsets, field accesses, memory effects match. Semantically equivalent.

long RGE_Game_World::get_next_object_id() {
    if (!this->scenario_object_flag) {
        int bound = this->maxNumberObjectsValue - 1;
        if (this->next_object_id <= bound) {
            for (; this->next_object_id <= bound &&
                   this->objectsValue[this->next_object_id] != NULL;
                 this->next_object_id++) {}
        }
        int result = this->next_object_id;
        this->next_object_id = result + 1;
        return result;
    }
    return this->scenario_object_id;
}
