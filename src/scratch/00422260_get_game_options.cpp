// VA: 00422260 RGE_Base_Game::get_game_options (296 B)
// PDB source: basegame.cpp
// Packet-grounded: read all game options into RGE_Game_Options struct

extern float version(void* self);
extern int scenarioGame(void* self);
extern char* scenarioName(void* self);
extern int singlePlayerGame(void* self);
extern int multiplayerGame(void* self);
extern int mapXSize(void* self);
extern int mapYSize(void* self);
extern int mapZSize(void* self);
extern int allowCheatCodes(void* self);
extern int cheatNotification(void* self);
extern int fullVisibility(void* self);
extern int fogOfWar(void* self);
extern int coloredChat(void* self);
extern int numberPlayers(void* self);
extern int gameDeveloperMode(void* self);
extern int difficulty(void* self);
extern unsigned char mpPathFinding(void* self);
extern unsigned char playerCDAndVersion(void* self, int idx);
extern int playerTeam(void* self, int idx);

void RGE_Base_Game_get_game_options(void* self, char* opt)
{
    char* name;
    int i;
    int len;
    
    *(float*)opt = version(self);
    opt[4] = (char)scenarioGame(self);
    
    name = scenarioName(self);
    for (len = 0; name[len]; len++)
        opt[5 + len] = name[len];
    opt[5 + len] = 0;
    
    opt[0x85] = (char)singlePlayerGame(self);
    opt[0x86] = (char)multiplayerGame(self);
    opt[0x87] = (char)mapXSize(self);
    opt[0x88] = (char)mapYSize(self);
    opt[0x89] = (char)mapZSize(self);
    opt[0x8A] = (char)allowCheatCodes(self);
    opt[0x8C] = (char)cheatNotification(self);
    opt[0x8D] = (char)fullVisibility(self);
    opt[0x8E] = (char)fogOfWar(self);
    opt[0x8F] = (char)coloredChat(self);
    opt[0x90] = (char)numberPlayers(self);
    opt[0x91] = (char)gameDeveloperMode(self);
    opt[0x9B] = (char)difficulty(self);
    opt[0x8B] = (char)mpPathFinding(self);
    
    for (i = 0; i < 9; i++) {
        opt[0x92 + i] = (char)playerCDAndVersion(self, i);
        opt[0x9C + i] = (char)playerTeam(self, i);
    }
}
