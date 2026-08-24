// CombatRuleSystem::loadRules (004D6910, 386 bytes, taicrule.cpp lines 35-74)
//
// Attempt log:
// 1-3: temp[256], frame 0x100 (too small by 0x10), all offsets cascaded -> 66%
// 4:   char temp[272] -> frame 0x110 correct, temp at [esp+18h] -> 66%
// 5:   || shared epilogue (strcmp(...)==0 || !filename) -> 5.7% 
// 6-8: padding vars, struct approach for offset fix -> no improvement
// 9:   split locals line[256]+named parse vars -> 3.1%
// VL:  variant_lab 8 variants, G0000 (4) best=3.1%.
//      Axes: local_order=vars_after_line, memset_form=direct, store_form=direct_this
//      Variant V000000 (representative). Remaining diff: lea edi scheduling
//      (lea edi after mov ecx/mov eax for memset). Irreducible VC5 heuristic.
// STATUS: unresolved, best at 3.1%. All real codegen diffs (relocs already masked).
//
// Translation-unit context pass: taicrule.cpp owns five normal functions in
// PDB order 004D68D0, 004D6900, 004D6910, 004D6AA0, and 004D6AB0.  The local
// CombatRuleSystem declaration in include/taicrule_context.h proves the
// 0x9C8 object and +0x04 rating table.  The complete wrapper in
// src/taicrule_tu.cpp compiles with config/flags/default.rsp.  Its four exact
// owners and the generated scalar deleting destructor match.  loadRules stays
// observed accepted drift: 12 positional bytes differ at the memset setup.

#include "../../include/game_globals.h"
#include <string.h>
#include <stdio.h>

#ifndef AOE1_TAICRULE_CONTEXT_H
class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int loadRules(char* filename);
};
#endif

int CombatRuleSystem::loadRules(char* filename)
{
    char line[256]; FILE* f; int a,b,c; char c1,c2;

    if (strcmp(filename, "NONE") == 0 || !filename) {
        return 0;
    }

    sprintf(line, "%s", filename);
    f = fopen(line, "r");
    if (!f)
        return 0;

    memset((char*)this + 4, '2', 2500);

    while (fgets(line, 256, f)) {
        sscanf(line, "%c%c", &c1, &c2);
        if (c1 == '/' && c2 == '/')
            continue;
        sscanf(line, "%d %d %d", &c, &a, &b);
        if (c < 0 || c >= 50)
            continue;
        ((char*)this + 4)[a + c * 50] = (char)b;
    }

    fclose(f);
    if (strstr(filename, ".tmp"))
        unlink(filename);
    return 1;
}
