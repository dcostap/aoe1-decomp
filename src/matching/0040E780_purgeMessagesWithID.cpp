// VA: 0040E780 purgeMessagesWithID (14 bytes)
// PDB: aimodule.cpp:718-736
// Binary evidence: the by-value AIModuleID is 0x48 bytes. The trailing int is
// unused. Scope exit calls the direct AIModuleID destructor and returns zero.
// Exact after matching the vptr-bearing object size and the destructor ABI.

class AIModuleID {
public:
    virtual ~AIModuleID();
    char data[0x44];
};

class AIModule {
public:
    int purgeMessagesWithID(AIModuleID p, int id);
};

int AIModule::purgeMessagesWithID(AIModuleID p, int id) {
    return 0;
}
