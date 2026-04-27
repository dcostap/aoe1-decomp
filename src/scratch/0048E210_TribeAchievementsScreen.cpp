// VA: 0048E210 ~TribeAchievementsScreen (493 B)
// PDB source: scr_ach.cpp
// Packet-grounded: cleanup sub-panels, free arrays, base dtor

extern void operator_delete(void* p);
extern void free(void* p);
extern void TTextPanel_dtor(void* p);
extern void TShape_dtor(void* p);
extern long TPanel_dtor(void* self);
extern void TPanelSystem_destroyPanel(void* ps, const char* name);
extern unsigned long panel_system;

struct Shim_dtor_E210 {
    char gap00[4];
    int field_4;                // +0x04
    char gap08[0x5A8 - 0x08];
    void* player_names[9];     // +0x5A8
    char gap5CC[0x5D4 - 0x5CC];
    int array_count;           // +0x5D4
    char gap5D8[4];
    int array_extra_count;     // +0x5DC
    char gap5E0[0x5F0 - 0x5E0];
    void* win_decal;           // +0x5F0
    char gap5F4[0x604 - 0x5F4];
    int panel_list_count;      // +0x604
    void* panel_list;          // +0x608
    void* extra_list;          // +0x60C
    char gap610[0x618 - 0x610];
    int some_count;            // +0x618
    void* some_array;          // +0x61C
};

long TribeAchievementsScreen_dtor(Shim_dtor_E210* self, int flags)
{
    // Cleanup player name panels
    int i;
    for (i = 0; i < 9; i++) {
        if (self->player_names[i]) {
            TTextPanel_dtor(self->player_names[i]);
            operator_delete(self->player_names[i]);
            self->player_names[i] = 0;
        }
    }
    
    // Free panel arrays (accessed via pointer math for field consistency)
    int panelCount = *(int*)((char*)self + 0x604);
    void* panelList = *(void**)((char*)self + 0x608);
    if (panelList) {
        for (i = 0; i < panelCount; i++) {
            void* panel = ((void**)panelList)[i];
            if (panel) {
                TShape_dtor(panel);
                operator_delete(panel);
            }
        }
        free(panelList);
    }
    
    int extraCount = *(int*)((char*)self + 0x5DC);
    void* extraList = *(void**)((char*)self + 0x5D8);
    if (extraList) {
        for (i = 0; i < extraCount; i++) {
            void* panel = ((void**)extraList)[i];
            if (panel) {
                TShape_dtor(panel);
                operator_delete(panel);
            }
        }
        free(extraList);
    }
    
    int someCount = *(int*)((char*)self + 0x618);
    void* someArr = *(void**)((char*)self + 0x61C);
    if (someArr) {
        operator_delete(someArr);
    }
    
    // Destroy decal shape
    if (self->win_decal) {
        TShape_dtor(self->win_decal);
        operator_delete(self->win_decal);
        self->win_decal = 0;
    }
    
    // Destroy panel from system
    TPanelSystem_destroyPanel((void*)&panel_system, "Achievements Screen");
    
    // Call base destructor
    TPanel_dtor(self);
    
    // Handle deleting destructor flag
    if (flags & 1)
        operator_delete(self);
    
    return flags ? (long)self : 1;
}
