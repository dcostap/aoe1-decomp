// VA: 0040E360 ~AIModule (57B)

struct _iobuf;
extern int __cdecl fclose(_iobuf*);

class AIModule_ID {
public:
    void dtor();
};

class AIModule {
public:
    char gap_00[4];
    AIModule_ID idValue;         // at +4
    char gap_08[0x94];
    int logCommonHistoryValue;   // at +0x9C

    ~AIModule();
};

extern _iobuf* DAT_00592A44;

AIModule::~AIModule() {
    *(int*)this = 0x56E930;
    if (logCommonHistoryValue != 0 && *(int*)0x592A44 != 0) {
        fclose(*(_iobuf**)0x592A44);
        *(int*)0x592A44 = 0;
    }
    this->idValue.dtor();
}
