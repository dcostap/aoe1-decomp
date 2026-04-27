// VA: 00415A10 mostDangerousEnemy (188B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    virtual int method_50(int a1);
    char gap4[0x4];
    void* field_08;
    
    int mostDangerousEnemy();
};

int __cdecl sub_0041A0D0(int a1);

int UnitAIModule::mostDangerousEnemy() {
    method_20();
    
    int bestEnemy = -1;
    int count = game_player_count;
    
    for (int i = 0; i < count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        if (sub_0041A0D0(player)) {
            // Check if this is a valid target
            int* objInfo = *(int**)((char*)field_08 + 0x0C);
            int val = *(int*)((char*)objInfo + 8);
            bestEnemy = player;
        }
    }
    
    return bestEnemy;
}
