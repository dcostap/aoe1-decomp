// attempt log:
// first pass: direct field updates around the queue-need test and action-list delete call
// second pass: switch to raw offsets for the 0x1C8/0x1CE/0x1D4/0x1D8 layout so VC5 stops inventing a shifted surface
// third pass: introduce an explicit zero carrier so the prolog can keep the original ebx/push-zero shape
// fourth pass: make the zero carrier data-dependent so VC5 keeps it live instead of folding it away
// fifth pass: tried volatile/local-table variants to recover the original prolog size, but VC5 either stayed 1 byte short or wandered to a much larger basin
// paused here: the remaining issue is prolog/zero-carrier code-size drift, not the cleanup semantics
// target shape: adjust the global count table when need_attr==4, reset need_attr, clear count, delete_list, bump change flag

class RGE_Action_List {
public:
    void delete_list();
};

struct RGE_Base_Game {
    char gap_00[0xA34];
    int* production_count_table;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Building_Object {
public:
    void empty_production_queue();
};

void TRIBE_Building_Object::empty_production_queue() {
    char* self = (char*)this;
    int* table = rge_base_game->production_count_table;
    int zero = 0;
    short need_attr = *(short*)(self + 0x1DA);
    if (need_attr != (short)-1) {
        if (need_attr == 4) {
            int index = *(short*)(self + 0x4A);
            table[index] -= 1;
        }
        *(short*)(self + 0x1DA) = (short)-1;
    }

    *(short*)(self + 0x1CE) = (short)zero;
    ((RGE_Action_List*)(*(void**)(self + 0x1D4)))->delete_list();
    *(unsigned char*)(self + 0x1D8) = (unsigned char)(*(unsigned char*)(self + 0x1D8) + 1);
}
