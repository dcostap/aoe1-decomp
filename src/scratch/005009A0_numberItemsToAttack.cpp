// VA: 005009A0 numberItemsToAttack (133B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xD30];
    int field_D34;
    
    int numberItemsToAttack();
};

void* __cdecl operator_new(unsigned size);

int TribeAICommand::numberItemsToAttack() {
    int val = field_D34;
    val--;
    if (val < 0) {
        int* ptr = (int*)operator_new(4);
        if (ptr) {
            *ptr = 0;
        }
    }
    return val;
}
