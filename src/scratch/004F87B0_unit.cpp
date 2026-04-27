// VA: 004F87B0 unit (1071B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xF4];
    int field_F8;
    
    void unit();
};

void TribeAICommand::unit() {
    int count = field_F8;
    if (count <= 0) return;
    field_F8 = 0;
}
