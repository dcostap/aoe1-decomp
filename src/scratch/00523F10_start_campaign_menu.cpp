// VA: 00523F10 TRIBE_Game::start_campaign_menu (274 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, create campaign screen, set panel, play music

extern void* operator_new(unsigned int size);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern void TRIBE_Game_shutdown_video_system(void* self);
extern int TMusic_System_play_track(void* sys, int track, int a, int b);
extern int TMusic_System_play_file(void* sys, const char* file, int a, int b);

extern void* panel_system;

int TRIBE_Game_start_campaign_menu(void* self)
{
    // EH frame via FS:[0] expected
    // local_4 = -1 (EH state)
    
    if (*(int*)((char*)self + 0xC00))
        TRIBE_Game_shutdown_video_system(self);
    
    void* screen = operator_new(0x4CC);
    if (!screen)
        return 0;
    
    // Call TRIBE_Screen_Campaign_Selection constructor
    // ...
    
    // local_4 = -1
    
    if (*(int*)((char*)screen + 0xD8)) {
        // Call vtable[0] with 1
        (*(void(**)(void*, int))(*(int**)screen))(screen, 1);
        return 0;
    }
    
    TPanelSystem_setCurrentPanel(panel_system, "Campaign Selection Screen");
    // vtable call at this+0x0C(2)
    (*(void(**)(void*, int))(*(int**)self + 3))(self, 2);
    
    void* musicSys = *(void**)((char*)self + 0x64);
    if (musicSys && !*(int*)((char*)self + 0xC1C)) {
        unsigned char musicType = *(unsigned char*)((char*)musicSys + 0x104);
        if (musicType == 1)
            TMusic_System_play_track(musicSys, 2, 0, 0);
        else if (musicType == 2)
            TMusic_System_play_file(musicSys, "open.mid", 0, 0);
        else if (musicType == 3)
            TMusic_System_play_file(musicSys, "open.wav", 0, 0);
        *(int*)((char*)self + 0xC1C) = 1;
    }
    
    return 1;
}
