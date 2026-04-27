// VA: 00417960 askForHelp (493B)
// aiuaimod.cpp

int game_player_count = 0;
int game_player_list = 0;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    virtual int method_DC(int a1, int a2);
    virtual void method_184(int a1, int a2, int a3, int a4);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    void askForHelp();
};

int __cdecl sub_00545D30(int a1);
int __cdecl sub_0041A0D0(int a1);

void UnitAIModule::askForHelp() {
    method_20();
    
    // Scan for allies to request help from
    for (int i = 0; i < game_player_count; i++) {
        int player = *(int*)(game_player_list + i * 8);
        int obj = sub_0041A0D0(player);
        if (obj && sub_00545D30(obj)) {
            method_184(player, 0, 0, 0);
        }
    }
}
