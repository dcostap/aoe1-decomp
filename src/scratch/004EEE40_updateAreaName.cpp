// VA: 004EEE40 updateAreaName (160B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xE18];
    int field_E1C;
    
    const char* updateAreaName();
};

const char* TribeAICommand::updateAreaName() {
    int idx = field_E1C;
    if (idx > 0x15) return (const char*)0x58839C;
    if (idx == 1) return (const char*)0x58838C;
    return (const char*)0x58839C;
}
