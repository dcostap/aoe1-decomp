// VA: 00422EF0 RGE_Base_Game::setup_map_save_area (214 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: alloc TDrawArea(0x100), ctor, Init, cleanup

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int TDrawArea_ctor(void* da, const char* name, int flags);
extern int TDrawArea_dtor(void* da);
extern int TDrawArea_Init(void* da, void* sys, int w, int h, int x, int y);
extern void notify_failure(const char* msg);
extern void log_message(const char* msg);
extern void* draw_system;
extern void pad_0();
extern void pad_1();
extern void pad_2();
extern void pad_3();
extern void pad_4();
extern void pad_5();
extern void pad_6();
extern void pad_7();
extern void pad_8();
extern void pad_9();
extern void pad_10();
extern void pad_11();
extern void pad_12();


struct Shim_22EF0 {
    char pad[0x1C];
    void* map_save_area;
};

int RGE_Base_Game_setup_map_save_area(Shim_22EF0* self)
{
    void* da;
    
    da = operator_new(0x100);
    if (da != 0) {
        TDrawArea_ctor(da, "Diamond Map Save Area", 0);
    }
    self->map_save_area = da;
    
    if (da == 0) {
        notify_failure("alloc failed");
        return 0;
    }
    
    if (!TDrawArea_Init(da, draw_system, 0x118, 0x8C, 0, 0)) {
        log_message("init failed");
        if (self->map_save_area) {
            TDrawArea_dtor(self->map_save_area);
            operator_delete(self->map_save_area);
        }
        self->map_save_area = 0;
        return 0;
    }
    
        pad_0();
        pad_1();
        pad_2();
        pad_3();
        pad_4();
        pad_5();
        pad_6();
        pad_7();
        pad_8();
        pad_9();
        pad_10();
        pad_11();
        pad_12();

    return 1;
}
