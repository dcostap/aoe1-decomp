// 004642C0 TPanelSystem::get_palette
// Panel.cpp:490-532 (155 asm lines, 443 bytes)
//
// Attempt log:
// baseline: canonical palette arrays and natural filename/cache source; frame and
// prologue family match, but VC5 duplicates strupr in the sprintf/copy arms.
// normalized-name alias and self alias emitted the same code; reverse branch order worsened CFG.
// assigning the strupr return removed the extra call but added a 4-byte frame and broad drift.
// a separate non-null uppercasing guard aligned call count but changed the prologue; rolled back.
// explicit common uppercase goto was optimized back to the duplicated-call basin.
// named TPanelSystem owner/list prefix preserves canonical 0x1C palette ownership; emitted code unchanged.
// left unresolved: original has one common strupr call and exact inline two-byte compare scheduling;
// the worker's pre-audit cursor candidate retained the exact frame/call family
// but had a 48-byte structural drift.
// Main-agent audit removed cross-member cursor arithmetic and the stack-window
// `file_name + 4` artifact. Canonical arrays and ordinary filename construction
// are retained instead of the prior metric-oriented compiler basin. Final
// audited check: 492/443 bytes, 0x10C frame, 5/4 calls, 423-byte diff.
// Session sa-d5b4d7ca-r1: a post-construction non-null strupr guard restored
// call-count parity but changed the prologue and widened structural drift.
// Explicit normalize/lookup labels compiled back to the duplicated-call basin.
// A normalized_name return alias forced a 0x114 frame and broad drift; rolled
// back. The canonical source remains the best reconstruction.
// Combined the id and filename cache-hit tests into one short-circuit condition;
// this restored the original shared increment/return island and cut the diff to 386.
// Reversed the outer null-name test; this restored one common strupr call, exact
// size, and exact call order, cutting the diff to 179.
// Made the occupied palette arm fall through and the empty-slot arm cold; the
// loop from +74 to the epilogue is now byte-exact and the diff is 88.
// A label-based null arm produced the same bytes and was rolled back to natural
// structured source. Remaining drift is the early outer branch block only.
// Combined a non-null-first filename arm with the current loop shape; it added
// a second strupr call and widened the build to 456 bytes. Restored clean source.
// Session sa-80d2dd80-r1: natural baseline is 443 bytes, 0x10C frame, and four
// aligned calls with an 88-byte early null-branch CFG drift. Positive outer-arm
// spellings consistently add one strupr call and 13 bytes. Explicit labels,
// switch syntax, separate guards, and numeric or unary predicate spellings did
// not improve it. The reviewed full TPanelSystem tail layout widened drift;
// the compact touched-field surface remains authoritative.
// Session sa-e0eb4345-r1 revisit: split complementary guards produced 339-byte
// drift; positive outer/goto forms stayed in the 456-byte, 5-call basin; reversed
// inner predicate produced 395-byte drift. Restored the pinned natural source.

#include <string.h>
#include <stdio.h>

extern "C" void* __cdecl ReadPalette(char*, long, int);

class TPanel;
struct PanelNode;

class TPanelSystem {
public:
    TPanel* mouse_owner;
    TPanel* keyboard_owner;
    TPanel* modal_panel;
    TPanel* current_panel;
    PanelNode* panel_list;
    int number_active_panels;
    TPanel* previous_current_child;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];

    void* get_palette(char* param_1, long param_2);
};

void* TPanelSystem::get_palette(char* param_1, long param_2)
{
    char file_name[260];

    if (param_1 == 0) {
        file_name[0] = 0;
    } else {
        if (strchr(param_1, '.') == 0) {
            sprintf(file_name, "%s.pal", param_1);
        } else {
            strcpy(file_name, param_1);
        }
        strupr(file_name);
    }

    int found = -1;
    int i;

    for (i = 0; i < 10; i++) {
        if (this->palette[i] != 0) {
            if ((param_2 != -1 && this->palette_id[i] == param_2) ||
                strcmp(this->palette_file[i], file_name) == 0) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }
        } else if (found == -1) {
            found = i;
        }
    }

    if (found == -1) return 0;

    this->palette[found] = ReadPalette(file_name, param_2, 1);
    if (this->palette[found] == 0) return 0;

    this->palette_use_count[found]++;
    strcpy(this->palette_file[found], file_name);
    this->palette_id[found] = param_2;
    return this->palette[found];
}
