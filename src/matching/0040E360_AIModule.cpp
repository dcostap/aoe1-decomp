// VA: 0040E360 ~AIModule (57B)
// Exact source recovery: keep the inline AIModuleID storage opaque to AIModule
// cleanup, then use a qualified destructor call. This preserves the proven
// +4 address and binds the direct AIModuleID destructor target.

struct _iobuf;
extern int __cdecl fclose(_iobuf*);

class AIModuleID {
public:
    virtual ~AIModuleID();
};

class AIModule {
public:
    void* vtable;
    char idValue[0x48];          // at +4
    char gap_4C[0x50];
    int logCommonHistoryValue;   // at +0x9C

    ~AIModule();
};

extern _iobuf* DAT_00592A44;
extern void* AIModule_vtable;

AIModule::~AIModule() {
    vtable = &AIModule_vtable;
    if (logCommonHistoryValue != 0 && DAT_00592A44 != 0) {
        fclose(DAT_00592A44);
        DAT_00592A44 = 0;
    }
    ((AIModuleID*)&this->idValue)->AIModuleID::~AIModuleID();
}
