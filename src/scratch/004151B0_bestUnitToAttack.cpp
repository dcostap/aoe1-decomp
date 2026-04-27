// VA: 004151B0 bestUnitToAttack (2136B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    char gap4[0x4];
    void* field_08;
    
    int bestUnitToAttack();
};

int __cdecl sub_00545CB0(int a1);

int UnitAIModule::bestUnitToAttack() {
    method_20();
    
    int best = -1;
    
    // Evaluate all enemy units for attack priority
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int* objList = *(int**)((char*)field_08 + 0x0C);
        if (objList) {
            int objInfo = *(int*)((char*)objList + 0x3C);
            if (objInfo) {
                int result = sub_00545CB0(objInfo);
                if (result) {
                    best = player;
                }
            }
        }
    }
    
    return best;
}
