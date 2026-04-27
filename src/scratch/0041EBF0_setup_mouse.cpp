// VA: 0041EBF0 RGE_Base_Game::setup_mouse (270 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: registry check custom mouse mode, alloc TMousePointer, setup, mouse_off

extern int RegSetInt(void* registry, int val, const char* key, int data);
extern int RegGetInt(void* registry, int def, const char* key);
extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int TMousePointer_ctor(void* mp, int custom_type);
extern int TMousePointer_setup(void* mp, int custom_mouse, void* draw_area, void* cursor_file, int max_w, int max_h);
extern void mouse_off(void* self);
extern void get_system_info(void* info);
extern int system_flags(int flag);
extern int check_driver(int driver);
extern void init_input(int mode);
extern void load_cursor(int id);
extern int check_fullscreen(void* info);
extern void set_resolution(int w, int h);
extern void register_mouse(void* mp);
extern void log_mouse_init(const char* msg);
extern void reset_cursor(void);
extern void apply_settings(void);

struct Shim_1EBF0 {
    void* vtable;              // +0x00
    char p4[0x0C - 4];
    void* prog_info;           // +0x0C
    char p10[0x4C - 0x10];
    void* draw_area;           // +0x4C
    char p50[4];
    int custom_mouse;          // +0x54
    char p58[0x1AC - 0x58];
    void* registry;            // +0x1AC
    char p1B0[0x1C0 - 0x1B0];
    void* mouse_pointer;       // +0x1C0
};

int RGE_Base_Game_setup_mouse(Shim_1EBF0* self)
{
    int custom_type;
    int result;
    void* mp;
    
    custom_type = RegGetInt(self->registry, 0, "Custom Mouse");
    
    if (custom_type == -1) {
        RegSetInt(self->registry, 0, "Custom Mouse", 0);
        custom_type = 0;
    }
    
    if (custom_type == 1) {
        // pass 1 as custom type
    } else if (custom_type == 2) {
        self->custom_mouse = 0;
    } else {
        custom_type = 0;
    }
    
    mp = operator_new(0x254);
    if (mp) {
        TMousePointer_ctor(mp, custom_type);
    }
    self->mouse_pointer = mp;
    
    if (!mp)
        return 0;
    
    get_system_info(self->prog_info);
    system_flags(custom_type);
    check_driver(custom_type + 1);
    init_input(custom_type);
    load_cursor(custom_type);
    check_fullscreen(self->prog_info);
    set_resolution(0, 0);
    register_mouse(mp);
    log_mouse_init("mouse setup");
    reset_cursor();
    apply_settings();
    
    result = TMousePointer_setup(
        mp,
        self->custom_mouse,
        self->draw_area,
        (void*)((int)self->prog_info + 0x773),
        0xC738,
        10);
    
    if (!result)
        return 0;
    
    mouse_off(self);
    return 1;
}
