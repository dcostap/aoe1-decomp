// VA: 00501190 selectBestCommander (196B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    int selectBestCommander(int a1, int a2);
};

int TribeAICommand::selectBestCommander(int a1, int a2) {
    int result = -1;
    if (a1 == a2) {
        result = a1;
    }
    field_8 = result;
    return result;
}
