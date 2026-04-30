// 005412B0 data_load_players (World.cpp:539-564)
// PDB source: World.cpp (RGE_Game_World::data_load_players)
//
// Attempt log:
// a1: goto-based; wrong reg alloc, missing vtable call. 176/197b.
// a2: virtual funcs in RGE_Game_World; vtable call matches, extra push ebx+offset shift.
// a3: separate helper struct for vtable call; same issue.
// a4: scoped ebx locals inside fp!=NULL block; no change.
// a5: removed helper struct; still has push ebx (not struct-caused).
// a6: this->vtable before fopen; extra push ebp too.
// a7: self=this at start; push ecx for local self.
// a8: param_1 slot reuse for count; virtual funcs. 12.7% diff.
// a9: no mpn pointer; direct access. Same push ebx.
// a10: do-while loop; different structure, worse match.
// a11: separate virtual struct; same 12.7% diff.
//
// Remaining diff (12.7% positional, 6% edit): pure VC5 register scheduling.
// - Original: push esi; push edi at entry; push ebx only after fp==NULL check.
// - Rebuilt:  push ebx; push esi; push edi at entry (ebx pushed unconditionally).
// Function body from offset 8 onward byte-for-byte matches original.
// Vtable call (this->data_load_players_type) pattern matches exactly.
//
// Parked: register scheduling difference cannot be resolved with source changes.
// TU context (World.cpp including RGE_Game_World.h with virtual declarations)
// would likely resolve, but single-function compilation lacks that context.

#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Player;

struct RGE_Game_World {
    void* vtable;                       // +0x00
    char _gap_04[0x40];                // +0x04-0x43
    short master_player_num;           // +0x44
    char _pad_46[2];                   // +0x46-0x47
    RGE_Master_Player** master_players; // +0x48

    unsigned char data_load_players(char* param_1);
};

// Helper struct to generate correct __thiscall vtable dispatch at slot 7
struct RGE_Game_World_Call {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void data_load_players_type(short type, short id, FILE* fp);
};

unsigned char RGE_Game_World::data_load_players(char* param_1) {
    FILE* fp;
    int type;
    int id;

    fp = fopen(param_1, "r");
    if (fp == NULL)
        goto done;

    if (fscanf(fp, "%hd %hd", &this->master_player_num, (short*)&param_1) != -1) {
        this->master_players = (RGE_Master_Player**)calloc(this->master_player_num, 4);
        for (short i = 0; i < *(short*)&param_1; i++) {
            if (fscanf(fp, "%hd %hd", &type, &id) != -1) {
                ((RGE_Game_World_Call*)this)->data_load_players_type((short)type, (short)id, fp);
            }
        }
        fclose(fp);
        return 1;
    }

    this->master_player_num = 0;
    this->master_players = (RGE_Master_Player**)0;
    fclose(fp);

done:
    return 1;
}
