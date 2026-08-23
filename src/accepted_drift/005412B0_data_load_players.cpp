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
// Full canonical World.cpp context emits the same reviewed bytes. It does not
// change the remaining register schedule.

#include <stdio.h>
#include <stdlib.h>
#include "../../include/world_scenario_context.h"

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
                this->data_load_players_type((short)type, (short)id, fp);
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
