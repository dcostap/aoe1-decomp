// STATUS: blocked
// BLOCKER: constructor-side layout is understood, but VC5 still drifts in destructor prologue/local setup and the palette cleanup loop register allocation
// NOTE: panel-list teardown and palette cleanup semantics match; remaining mismatch is codegen/register-shape only
// Retry 2026-05-20 assigned pass:
// try 1: revalidated inherited source: exact size 162 but broad 135 positional diff, first mismatch at prologue (sub esp,8 vs push ecx).
// try 2: removed volatile delete_object/count; rebuilt shrank to 160B and still used sub esp,8 / stack DeleteObject thunk, not original push-ecx + EBX thunk.
// try 3: direct DeleteObject call without function-pointer local; still 160B sub-esp family.
// try 4: nonvolatile delete_object with volatile count; exact-size 162 and improved to 55 positional / 17 edit, but still wrong sub esp,8, EBX zero-register, and stack-held thunk.
// try 5: for-loop over palette entries; 160B sub-esp family.
// try 6: while(count-- != 0) palette loop; 160B sub-esp family.
// try 7: rewrote whole destructor naturally with direct this instead of self/declaration block; no improvement, still sub esp,8.
// try 8: declared DeleteObject as extern const function pointer instead of dllimport; no change.
// try 9: register delete_object local; no change, compiler still stored thunk in stack local and used EBX as zero.
// try 10: made zero stores depend on DeleteObject return local to try forcing xor eax after call; optimized back to EBX-zero stack-thunk family.
// GIVEUP: best exact-size source is try 4-style 55 positional / 17 edit. Remaining drift is structural prologue/local/register allocation: original uses one push-ecx local, EBX=DeleteObject thunk, and EAX zeroed after each call; rebuilt insists on sub esp,8, EBX=zero, and stack-held thunk. Not proposing accepted_drift because prologue and palette loop register topology differ broadly.

extern "C" void __cdecl free(void* ptr);
#ifndef AOE1_PANEL_CONTEXT_H
extern "C" int (__stdcall* const DeleteObject)(void* object);

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    void* field_14;
    void* field_18;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    int palette_ids[10];
    int prevCurrentChildValue;
    int ImeEnabled;
    int field_AC4;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    void restore_system_colors(void);
    void EnableIME(void);
    ~TPanelSystem(void);
};
#endif

#endif
TPanelSystem::~TPanelSystem(void) {
    this->restore_system_colors();

    PanelNode* panel_list = this->panelListValue;
    if (panel_list != 0) {
        PanelNode* node = panel_list->next_node;
        if (node != panel_list) {
            do {
                node = node->next_node;
                TPanel* panel = node->prev_node->panel;
                if (panel != 0) {
                    delete panel;
                }
                free(node->prev_node);
            } while (node != this->panelListValue);
        }
        free(this->panelListValue);
        this->panelListValue = 0;
    }

    int (__stdcall* delete_object)(void*) = DeleteObject;
    for (int i = 0; i < 10; i++) {
        void** palette_entry = &this->palette[i];
        if (*palette_entry) {
            delete_object(*palette_entry);
            *palette_entry = 0;
            this->palette_file[i][0] = 0;
            this->palette_use_count[i] = 0;
            this->palette_ids[0] = 0;
        }
    }

    this->EnableIME();
}
