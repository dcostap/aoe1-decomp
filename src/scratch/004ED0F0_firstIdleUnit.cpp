// VA: 004ED0F0 firstIdleUnit (127B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    
    int firstIdleUnit(int a1);
};

int TribeAICommand::firstIdleUnit(int a1) {
    int* list = (int*)field_1C;
    if (list) {
        if (a1) {
            return (int)list;
        }
    }
    return -1;
}
