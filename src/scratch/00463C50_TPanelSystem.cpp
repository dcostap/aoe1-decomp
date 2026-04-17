// STATUS: blocked
// BLOCKER: constructor-side layout is understood, but VC5 still drifts in destructor prologue/local setup and the palette cleanup loop register allocation
// NOTE: panel-list teardown and palette cleanup semantics match; remaining mismatch is codegen/register-shape only

extern "C" void __cdecl free(void* ptr);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

class TPanel {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
};

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

TPanelSystem::~TPanelSystem(void) {
    TPanelSystem* self;
    PanelNode* panel_list;
    PanelNode* node;
    void** palette_entry;
    char (*palette_file_entry)[260];
    int (__stdcall* volatile delete_object)(void*);
    volatile int count;

    self = this;
    self->restore_system_colors();
    panel_list = self->panelListValue;
    if (panel_list != 0) {
        node = panel_list->next_node;
        if (node != panel_list) {
            do {
                node = node->next_node;
                if (node->prev_node->panel != 0) {
                    node->prev_node->panel->scalar_deleting_destructor(1);
                }
                free(node->prev_node);
            } while (node != self->panelListValue);
        }
        free(self->panelListValue);
        self->panelListValue = 0;
    }
    delete_object = DeleteObject;
    palette_entry = self->palette;
    palette_file_entry = self->palette_file;
    count = 10;
    do {
        if (*palette_entry != 0) {
            delete_object(*palette_entry);
            *palette_entry = 0;
            (*palette_file_entry)[0] = 0;
            *(int*)((char*)palette_entry + 0xA50) = 0;
            self->palette_ids[0] = 0;
        }
        palette_entry++;
        palette_file_entry++;
        count--;
    } while (count != 0);
    self->EnableIME();
}
