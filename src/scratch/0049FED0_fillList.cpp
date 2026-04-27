// VA: 0049FED0 fillList (461B)
// scr_mp.cpp lines 370-410
// Has EH frame + alloca stack, needs /GX

class TCommunications_Services {
public:
    virtual ~TCommunications_Services();
};

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TribeMPStartupScreen : public TScreenPanel {
public:
    char gap4[0x494];
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    
    void fillList();
};

extern int* rge_base_game;
extern void __cdecl get_player_list(int* services, int filter);
extern int __cdecl enumerate_players(int filter);

void TribeMPStartupScreen::fillList() {
    // Clear the list
    void* list = (void*)field_498;
    // Clear list contents
    
    // Create communications services
    TCommunications_Services* services = new TCommunications_Services();
    
    if (enumerate_players(1)) {
        // Get player count
        // Loop through players and add to list
        int i;
        for (i = 0; i < 10; i++) {
            // Get player name from game
            // Add to list
        }
    }
    
    if (enumerate_players(1)) {
        // More processing
    }
    
    delete services;
}
