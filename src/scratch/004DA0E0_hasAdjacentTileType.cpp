// VA: 004DA0E0 TribeInformationAIModule::hasAdjacentTileType(int,int,int)
// PDB: taiinfmd.cpp lines 1853-1894 (141 bytes, 59 asm lines)
// Retry 2026-05-19 (10 honest tries):
// - Initial scratch reloaded terrain inside loop and compiled broad mismatch (>90% positional).
// - Added typed md/aiPlayer/world/terrain chain and cached Terrain* before the loop; this recovered the original prologue/registers through the switch dispatch.
// - Best natural for-loop/switch with shared post-switch check is exact-sized and has first 40 bytes matching; 58.1560% positional but only 14.1844% edit diff. Remaining mismatch is switch case block placement: rebuilt emits the case increment/decrement blocks inline before the shared bounds check, while original places those tiny case bodies after the main fail/success epilogues and jumps back to the shared check.
// - Tried explicit goto/shared-check labels and moving the check into switch/default/case bodies. Duplicating the check produced closer block placement but changed register allocation (EBP loop index vs original EDI, param_3 in EDI vs original EBP) and still mismatched.
// - Tried while/goto and for-loop forms; original's `switch` jump table plus out-of-line case bodies remains sticky.
// GIVEUP: no accepted_drift proposal. Although behavior is understood, drift changes switch table targets/block layout and some register allocation, not a localized benign difference.
// Retry 2026-05-19/20 assigned pass:
// - Revalidated baseline/default: exact size 141B, first 40 bytes match, 58.1560% positional / 14.1844% edit; only real shape issue remains inline case bodies vs original out-of-line case bodies after epilogues.
// - Added `default: goto check` and explicit shared `check:` label in the switch to encourage out-of-line case layout; VC5 emitted identical code to baseline.
// - /Ob0 flag probe emitted identical code to baseline; flag removed.
// - /O1 probe forced EBP-frame/broad different basin (93.6170% positional), rejected and flag removed.
// - Reviewed accepted_drift possibility again: not suitable because jump table targets/block layout differ and branch distances/epilogue placement shift, despite understood behavior.
// Left in scratch: default flags, same best baseline. Remaining blocker is VC5 switch case block placement.

struct Terrain {
    char gap0[8];
    int width;
    int height;
    char gap10[0x8d8c - 0x10];
    unsigned char** rows;
};
struct WorldA { char gap[0x28]; Terrain* terrain; };
struct AiPlayer { char gap[0x3c]; WorldA* worlda; };
struct MD { char gap[0x1256c]; AiPlayer* aiPlayer; };

struct TribeInformationAIModule {
    char gap[0x100];
    MD* md;
    int hasAdjacentTileType(int x, int y, int type);
};

int TribeInformationAIModule::hasAdjacentTileType(int param_1, int param_2, int param_3) {
    Terrain* terrain = this->md->aiPlayer->worlda->terrain;
    int x = param_1;
    int y = param_2;

    for (int i = 0; i < 8; i++) {
        switch (i) {
        case 0:
            x = param_1;
            y = param_2;
            x--;
        case 7:
            y--;
            break;
        default:
            goto check;
        case 1:
        case 2:
            x++;
            break;
        case 3:
        case 4:
            y++;
            break;
        case 5:
        case 6:
            x--;
            break;
        }

check:
        if (x >= 0 && y >= 0 && x <= terrain->width - 1 && y <= terrain->height - 1) {
            unsigned char* row = terrain->rows[y];
            int xx = x + x * 2;
            int tile = row[xx * 8 + 5] & 0x1f;
            if (tile == param_3)
                return 1;
        }
    }

    return 0;
}
