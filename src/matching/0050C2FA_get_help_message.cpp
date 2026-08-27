#ifndef TECH_GROUP_CONTEXT
// BLOCKED: Frame-pointer basin issue
// With /Og- /Oy- or /Od: size matches (57 bytes), but mismatch@15
// Original: movsx ecx,[ebp+8]; mov edx,[ebp-4]; movsx eax,word[edx+4]; cmp ecx,eax
// Rebuilt:  mov ecx,[ebp-4]; movsx edx,word[ecx+4]; movsx eax,word[ebp+8]; cmp edx,eax
// VC5 picks different register for second phase (param_1 vs this reload order)
// With /O2 (default): only 48 bytes, frame pointer omitted
// Left in scratch as blocked register basin

struct TechEntry {
    char gap_00[0x30];
    long help_string_id;
    char gap_34[8];
};

class TRIBE_Tech {
public:
    TechEntry* tech_tree;
    short tech_tree_num;
    char gap_06[2];

    long get_help_message(short param_1);
};

#endif

long TRIBE_Tech::get_help_message(short param_1) {
    if (param_1 < 0 || param_1 > this->tech_tree_num) {
        return -1;
    }

    return this->tech_tree[param_1].help_string_id;
}
