// STATUS: almost_matched
// CLASS: register-allocation-swap (eax/edx)
// RISK: low
// WHY: VC5 deterministically assigns eax to world ptr and edx to param,
//      but original has them swapped. This causes and-edx-imm32 (6B) vs
//      and-eax-imm32 (5B), a 1-byte encoding difference. 20+ source
//      variants and 10+ flag combinations all produce the same register
//      assignment. Likely a peephole optimization difference in the
//      original compiler build that prefers eax for AND-with-immediate.
// NEXT: Revisit if a compiler patch/version change fixes register preference,
//       or if TU-level context (compiling with other player.cpp functions)
//       changes the register allocator behavior.
// FLAGS: config\flags\004705A0_set_color_table.rsp

struct RGE_Game_World {
    char gap_00[0x64];
    int* color_tables;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0xC8];
    int color_table;

    void set_color_table(unsigned char param);
};

void RGE_Player::set_color_table(unsigned char param) {
    color_table = world->color_tables[param];
}
