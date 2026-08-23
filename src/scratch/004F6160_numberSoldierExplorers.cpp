extern int __stdcall soldierExplorerFunc(int val);

class TribeTacticalAIModule {
public:
    int numberSoldierExplorers();
};

int TribeTacticalAIModule::numberSoldierExplorers() {
    return soldierExplorerFunc(0x66);
}
