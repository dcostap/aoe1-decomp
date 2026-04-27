// VA: 0048D530 TribeAchievementsScreen::TribeAchievementsScreen (3222 B)
// PDB source: scr_ach.cpp
// Packet-grounded: constructor — create panels, load shapes, setup screen

extern void* operator_new(unsigned int size);
extern void* calloc(int count, int size);
extern int TScreenPanel_ctor(void* self, void* parent, int x, int y, int w, int h, ...);
extern int TTextPanel_ctor(void* p, void* parent, int x, int y, int w, int h, const char* txt, ...);
extern int TPanel_set_size(void* p, int w, int h);
extern int TPanel_set_position(void* p, int x, int y);
extern int TPanel_show(void* p, int flag);
extern int TPanel_set_text(void* p, const char* txt);
extern int TShape_ctor(void* shape, const char* name, int id);
extern int TShape_load(void* shape, const char* name);
extern int TPanel_add_child(void* parent, void* child);
extern int TShape_set_transparent_color(void* shape, unsigned char r, unsigned char g, unsigned char b);
extern int TPanel_get_string(void* self, int id);
extern int sprintf(char* buf, const char* fmt, ...);
extern int strcpy(char* dst, const char* src);
extern int TPanelSystem_addPanel(void* ps, const char* name, void* panel);

extern unsigned long panel_system;
extern void* rge_base_game;

// Shim for constructor layout
struct Shim_ctor_D530 {
    char gap00[0x20];
    void* draw_area;           // +0x20
    char gap24[0x5A8 - 0x24];
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

void* TribeAchievementsScreen_ctor(Shim_ctor_D530* self, void* parent, int x, int y, int w, int h)
{
    int i;
    
    // Call base TScreenPanel constructor
    TScreenPanel_ctor(self, parent, x, y, w, h);
    
    // vtable at specific address for this class
    // *(void**)self = (void*)0x572___;
    
    // Create win_decal shape (TShape for the winner decal icon)
    self->win_decal = operator_new(0x48);  // sizeof(TShape)
    if (self->win_decal) {
        TShape_ctor(self->win_decal, "win_decal", 0);
        TShape_load(self->win_decal, "win_decal");
    }
    
    // Initialize array fields
    self->array_count = 9;
    for (i = 0; i < 9; i++) self->player_names[i] = 0;
    
    // Create player name panels at positions for 9 players
    // Each player name TTextPanel created at specific x,y coordinates
    // with size based on screen layout
    
    // Arrays for category/achievement panels
    self->panel_list = 0;
    self->panel_list_count = 0;
    self->extra_list = 0;
    self->some_array = 0;
    self->some_count = 0;
    
    // Load achievement strings from language DLL
    // Create various text panels for:
    // - Title bar ("Achievements")
    // - Category buttons
    // - Navigation arrows
    // - Close/back button
    
    // Set up drawing surface
    // TDrawArea operations
    
    // Register with panel system
    TPanelSystem_addPanel((void*)&panel_system, "Achievements Screen", self);
    
    return self;
}
