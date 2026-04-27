// VA: 0048F0B0 TribeAchievementsScreen::draw (215 B)
// PDB source: scr_ach.cpp
// Packet-grounded: base draw, lock surface, loop player names drawing decals, unlock

extern void TScreenPanel_draw(void* self);
extern unsigned char* TDrawArea_Lock(void* da, const char* tag, int flag);
extern void TDrawArea_Unlock(void* da, const char* tag);
extern int TPanel_xPosition(void* panel);
extern int TPanel_yPosition(void* panel);
extern int TShape_shape_draw(void* shape, void* da, int x, int y, int flags, unsigned char unk, unsigned char* buf);
extern void* rge_base_game;

struct Shim_draw_F0B0 {
    char gap00[0x20];
    void* draw_area;           // +0x20
    char gap24[0x47C - 0x24];
    int current_mode;          // +0x47C
    char gap480[0x5A8 - 0x480];
    void* player_names[9];     // +0x5A8
    char gap5CC[0x5F0 - 0x5CC];
    void* win_decal;           // +0x5F0 (TShape*)
};

void TribeAchievementsScreen_draw(Shim_draw_F0B0* self)
{
    void** vt = *(void***)self;
    
    TScreenPanel_draw(self);
    
    if (self->current_mode >= 5)
        return;
    
    ((void(*)(void*, int))vt[0x28 / 4])(self, 0);
    
    if (!self->win_decal)
        goto finish;
    
    {
        unsigned char* locked = TDrawArea_Lock(self->draw_area, "scr_ach::draw", 1);
        if (locked) {
            void* world = *(void**)((char*)rge_base_game + 0x3F4);
            int numPlayers = *(short*)((char*)world + 0x3C);
            if (numPlayers > 1) {
                void** players = *(void***)((char*)world + 0x40);
                int i;
                for (i = 0; i < numPlayers - 1; i++) {
                    void* player = players[i + 1];
                    if (player && *(unsigned char*)((char*)player + 0x80) == 1) {
                        int yPos = TPanel_yPosition(self->player_names[i]);
                        int xPos = TPanel_xPosition(self->player_names[i]);
                        TShape_shape_draw(self->win_decal, self->draw_area, xPos - 0x14, yPos, 0, 0, 0);
                    }
                }
            }
            TDrawArea_Unlock(self->draw_area, "scr_ach::draw");
        }
    }
    
finish:
    ((void(*)(void*))vt[0x2C / 4])(self);
}
