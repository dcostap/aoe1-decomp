// VA: 0040E360 ~AIModule (57B)
// Exact source recovery: keep the inline AIModuleID storage opaque to AIModule
// cleanup, then use a qualified destructor call. This preserves the proven
// +4 address and binds the direct AIModuleID destructor target.

struct _iobuf;
extern int __cdecl fclose(_iobuf*);

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
};

class AIModule {
public:
    virtual ~AIModule();
    char idValue[0x48];          // at +4
    char gap_4C[0x50];
    int logCommonHistoryValue;   // at +0x9C

    ~AIModule();
};
#endif

extern _iobuf* DAT_00592A44;
AIModule::~AIModule() {
    if (logCommonHistoryValue != 0 && DAT_00592A44 != 0) {
        fclose(DAT_00592A44);
        DAT_00592A44 = 0;
    }
}
