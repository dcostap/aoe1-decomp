// VA: 00415CA0 closestObject (420B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    char gap4[0x4];
    void* field_08;
    
    int closestObject(int objType);
};

int __cdecl sub_00545D30(int a1);
int __cdecl sub_0041A0D0(int a1);

int UnitAIModule::closestObject(int objType) {
    method_20();
    
    int bestObj = -1;
    
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int obj = sub_0041A0D0(player);
        if (obj) {
            int objInfo = sub_00545D30(obj);
            if (objInfo) {
                // Check type and distance
                bestObj = obj;
                break;
            }
        }
    }
    
    return bestObj;
}
