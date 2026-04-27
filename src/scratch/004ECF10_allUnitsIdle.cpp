// VA: 004ECF10 allUnitsIdle (199B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    
    int allUnitsIdle(int a1);
};

int TribeAICommand::allUnitsIdle(int a1) {
    int val = field_1C;
    int* list = (int*)val;
    if (list == (int*)-1) return 1;
    if (a1) return field_1C;
    return 0;
}
