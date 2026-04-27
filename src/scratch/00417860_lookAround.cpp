// VA: 00417860 lookAround (190B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void method_20();
    char gap4[0x4];
    void* field_08;
    
    void lookAround();
};

int __cdecl sub_00545D30(int a1);

void UnitAIModule::lookAround() {
    method_20();
    
    int* objData = *(int**)((char*)field_08 + 4);
    int* objInfo = *(int**)((char*)field_08 + 0x0C);
    
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int result = sub_00545D30(player);
        if (result && *(unsigned char*)(result + 0x48) <= 2) {
        }
    }
}
