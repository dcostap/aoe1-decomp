// VA: 00449260 RGE_Effects::RGE_Effects(char* path)
// effects.cpp lines 68-129
// 478 bytes

// Attempt log:
// - Baseline retained the canonical 0x2C RGE_Effect / 0x0C command layout and
//   natural fscanf/calloc loops, but used a hand-written vtable field and the
//   command counter as the first %hd destination (552-byte output, extra scan).
// - Restored the period virtual RGE_Effects surface, reused the incoming path
//   home for the command opcode scan, kept a typed command pointer across the
//   inner fscanf, and used the positive effect-list guard.  The inner do-loop
//   still peeled into a duplicate scan, so the retained form is a top-tested
//   short loop (probe 003: 464-byte output, 85.45% shape).
// - Kept the positive fopen guard and opposite initial fscanf predicate so the
//   successful parse path falls through and the null/error paths are late.  A
//   separate fclose in each initial-fscanf arm restores all ten call sites.
//   Best current reconstruction is probe 009: 481-byte output, 100% ordered
//   call alignment, 97.60% shape, 241 strict differing bytes.
// - Tried a function-scope inner counter with the explicit do-loop (probe 010);
//   VC5 peeled/duplicated the scan and regressed to 526 bytes.  Restored the
//   probe-009 clean-source form before validation.
// - Tested the guarded infinite-loop form with a post-increment termination
//   test (probe 012); it added a duplicate fscanf, grew to 526 bytes, and was
//   restored.  The top-tested loop remains the best CFG.
// - Tried a natural early return for fopen failure to test conditional ESI
//   lifetime; it removed the late fclose call and worsened to 451 bytes, so it
//   was restored.
// - Remaining localized codegen gap: VC5 saves ESI in the prologue instead of
//   conditionally at the fopen-success edge, and loads effect_list_num into DX
//   before the inner guard where the oracle compares the field directly.  The
//   named ownership, widths, calls, CFG, and stack frame are otherwise aligned.
// - Reversed the inner bound to `effect_list_num > sVar7`; this is a natural
//   field-first spelling and restored the oracle's direct field compare.  It
//   reduced the strict diff from 241 to 47 bytes and the size gap to 1 byte.
// - Direct effect-list indexing, a typed count pointer, do-while spelling,
//   counter reset, donor declaration order, and function-scope command pointer
//   were tested.  The direct index/count-pointer/do-while forms regressed;
//   declaration order, reset, and command scope were emitted-code duplicates.
// - Best current source keeps the field-first top-tested loop.  Remaining
//   drift is conditional ESI save/restore and the loop back-edge compare
//   encoding; calls, frame, CFG count, and all named layout accesses align.
// - Normalized the command scan to its real short local. The former path-home
//   reuse passed a char** to %hd and was codegen scaffolding, not valid source.

#include <stdio.h>
#include <stdlib.h>

void convert_us(char* s);

struct RGE_Effect_Command {
    unsigned char command; unsigned char _pad_0;
    short change_num1; short change_num2; short change_num3; float change_amount;
};

struct RGE_Effect {
    short id; char name[31]; unsigned char _pad_0;
    short string_table_id; short effect_list_num;
    unsigned char _pad_1[2]; RGE_Effect_Command* effect_list;
};

class RGE_Player;

struct RGE_Effects {
    RGE_Effect* effects; long effect_num;
    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);
    RGE_Effects(char* path);
};

RGE_Effects::RGE_Effects(char* path) {
    int local_4, index, count;

    FILE* fp = fopen(path, "r");
    if (fp != 0) {
        long* pNum = &effect_num;
        if (fscanf(fp, "%d %d", pNum, &local_4) != -1) {
            effects = (RGE_Effect*)calloc(*pNum, 0x2C);
            for (count = 0; count < local_4; count++) {
                short sVar7 = 0;
                fscanf(fp, "%d", &index);
                if (fscanf(fp, "%s %hd", effects[index].name, &effects[index].effect_list_num) == -1) break;
                effects[index].id = (short)index;
                if (effects[index].effect_list_num > 0) {
                    effects[index].effect_list = (RGE_Effect_Command*)calloc(effects[index].effect_list_num, 0x0C);
                    if (effects[index].effect_list_num > 0) {
                        while (effects[index].effect_list_num > sVar7) {
                            RGE_Effect_Command* command = &effects[index].effect_list[sVar7];
                            short command_num;
                            if (fscanf(fp, "%hd %hd %hd %hd %f", &command_num, &command->change_num1, &command->change_num2, &command->change_num3, &command->change_amount) == -1) break;
                            sVar7++;
                            command->command = (unsigned char)command_num;
                        }
                    }
                } else {
                    effects[index].effect_list = 0;
                }
                convert_us(effects[index].name);
            }
            fclose(fp);
        } else {
            *pNum = 0;
            effects = 0;
            fclose(fp);
        }
    } else {
        effect_num = 0;
        effects = 0;
    }
}
