// VA: 00524AF0 TRIBE_Game::show_ai (636 B)
// PDB source: tribegam.cpp
// Packet-grounded: display AI debug overlay with player AI state

extern int sprintf(char* buf, const char* fmt, ...);

int debug_show_ai;  // 0x86BCE4
int debug_ai_panel; // 0x86BCE8

void TRIBE_Game_show_ai(void* self)
{
    // Check AI debug mode
    // ...
    
    // Get player count
    int numPlayers = 8;
    
    // For each player, format AI state string
    // sprintf with AI module name, state, target, etc.
    
    // Display via draw system
    // ...
}
