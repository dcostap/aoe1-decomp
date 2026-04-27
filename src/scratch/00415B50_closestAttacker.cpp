// VA: 00415B50 closestAttacker (328B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    char gap4[0x4];
    void* field_08;
    
    int closestAttacker();
};

int __cdecl sub_0041A0D0(int a1);

int game_player_count = 0;
int game_player_list = 0;

int UnitAIModule::closestAttacker() {
    method_20();
    
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int result = sub_0041A0D0(player);
        if (result) {
            // This is a potential attacker
            return player;
        }
    }
    
    return -1;
}
