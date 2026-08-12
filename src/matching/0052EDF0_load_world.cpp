// VA: 0052EDF0 TRIBE_World::load_world (314 B)
// PDB source: tworld.cpp
// Packet-grounded: base load_world, version-checked field reads
//   field_108 (victory_type, int, read if ver >= 5.6)
//   field_10C (artifact_count, int), field_110 (ruin_count, int, read if ver >= 5.3)
//   field_114 (countdown_victory, byte), field_118 (countdown_clock, float, read if ver >= 5.4)
//   field_11C (score_displayed, byte, read if ver >= 6.6)
//   field_11D (controllingComputerPlayer, byte, read if ver >= 6.97)
// Attempt log:
// - Replaced the free base shim with the typed RGE_Game_World base call and
//   restored the proven vtable surface; this aligned all eight direct calls.
// - Positive version-read guards recover the original inline-read/cold-zero
//   CFG and 96% instruction-shape similarity.  A direct base-load guard also
//   removes the decompiler-only result local and reaches the 315-byte basin.
// - A scoped zero local was codegen-neutral and was removed.  Remaining drift
//   is the VC5 callee-save basin: rebuilt saves EBX at entry, while the oracle
//   shrink-wraps push/pop EBX around the first version gate (known SIB/shift
//   consequences); no ABI, call-set, or field-layout uncertainty remains.
// sequential pass: donor stdlib context, explicit zero reuse, ground-truth
// world-tail/member ownership, real destructor surfaces, explicit cdecl, and
// an explicit base-result zero comparison were all neutral or regressed.  The
// clean typed source remains the best 315B basin; the remaining structural gap
// is the entry EBX save versus the oracle's late push/pop EBX schedule.
// - The ordinary C++ rge_read declaration preserved the typed call ABI and
//   restored all 18 call relocations. Negative guards improved the prologue but
//   inverted the original branch blocks. The first gate's cold zero label keeps
//   the observed read-before-zero order and late EBX lifetime; this is exact.

// Same-TU load donors use the ordinary C++ rge_read declaration.
void rge_read(int handle, void* buf, int size);

extern float save_game_version;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual unsigned char load_world(int handle);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_004[0x100];
    void* tech;
    int victory_type;          // +0x108
    int artifact_count;        // +0x10C
    int ruin_count;            // +0x110
    unsigned char countdown_victory; // +0x114
    char gap_115[3];
    float countdown_clock;     // +0x118
    unsigned char score_displayed; // +0x11C
    unsigned char controllingComputerPlayer; // +0x11D

    virtual unsigned char load_world(int handle);
};

unsigned char TRIBE_World::load_world(int handle)
{
    if (!RGE_Game_World::load_world(handle))
        return 0;

    // Version-checked conditional reads
    if (save_game_version >= 5.6f) {
        rge_read(handle, &this->victory_type, 4);
    } else {
        goto victory_zero;
    }
    goto victory_done;
victory_zero:
    this->victory_type = 0;
victory_done:;
    
    if (save_game_version >= 5.3f) {
        rge_read(handle, &this->artifact_count, 4);
        rge_read(handle, &this->ruin_count, 4);
    } else {
        this->artifact_count = 0;
        this->ruin_count = 0;
    }
    
    if (save_game_version >= 5.4f) {
        rge_read(handle, &this->countdown_victory, 1);
        rge_read(handle, &this->countdown_clock, 4);
    } else {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    }
    
    if (save_game_version >= 6.6f) {
        rge_read(handle, &this->score_displayed, 1);
    } else {
        this->score_displayed = 0;
    }

    if (save_game_version >= 6.97f) {
        rge_read(handle, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 2;
    }

    return 1;
}
