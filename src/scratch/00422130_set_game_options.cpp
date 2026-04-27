// VA: 00422130 RGE_Base_Game::set_game_options (297 B)
// PDB source: basegame.cpp
// Packet-grounded: write all game options from RGE_Game_Options struct

extern void setVersion(void* self, float v);
extern void setScenarioGame(void* self, int v);
extern void setScenarioName(void* self, const char* name);
extern void setSinglePlayerGame(void* self, int v);
extern void setMultiplayerGame(void* self, int v);
extern void setMapSize(void* self, int x, int y, int z);
extern void setAllowCheatCodes(void* self, int v);
extern void setCheatNotification(void* self, int v);
extern void setFullVisibility(void* self, int v);
extern void setFogOfWar(void* self, int v);
extern void setColoredChat(void* self, int v);
extern void setNumberPlayers(void* self, int v);
extern void setGameDeveloperMode(void* self, int v);
extern void setDifficulty(void* self, int v);
extern void setMpPathFinding(void* self, unsigned char v);
extern void setPlayerCDAndVersion(void* self, int idx, unsigned char v);
extern void setPlayerTeam(void* self, int idx, int v);

void RGE_Base_Game_set_game_options(void* self, char* opt)
{
    int i;
    
    setVersion(self, *(float*)opt);
    setScenarioGame(self, (unsigned char)opt[4]);
    setScenarioName(self, opt + 5);
    setSinglePlayerGame(self, (unsigned char)opt[0x85]);
    setMultiplayerGame(self, (unsigned char)opt[0x86]);
    setMapSize(self, (unsigned char)opt[0x87], (unsigned char)opt[0x88], (unsigned char)opt[0x89]);
    setAllowCheatCodes(self, (unsigned char)opt[0x8A]);
    setCheatNotification(self, (unsigned char)opt[0x8C]);
    setFullVisibility(self, (unsigned char)opt[0x8D]);
    setFogOfWar(self, (unsigned char)opt[0x8E]);
    setColoredChat(self, (unsigned char)opt[0x8F]);
    setNumberPlayers(self, (unsigned char)opt[0x90]);
    setGameDeveloperMode(self, (unsigned char)opt[0x91]);
    setDifficulty(self, (unsigned char)opt[0x9B]);
    setMpPathFinding(self, (unsigned char)opt[0x8B]);
    
    for (i = 0; i < 9; i++) {
        setPlayerCDAndVersion(self, i, (unsigned char)opt[0x92 + i]);
        setPlayerTeam(self, i, (unsigned char)opt[0x9C + i]);
    }
}
