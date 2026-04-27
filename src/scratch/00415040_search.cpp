// VA: 00415040 search (224B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_DC(int a1, int a2);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    void search();
};

int __cdecl sub_00545D30(int a1);

void UnitAIModule::search() {
    if (field_30 == -1) {
        method_DC(-1, 0);
    }
    
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int result = sub_00545D30(player);
        if (result) {
            break;
        }
    }
}
