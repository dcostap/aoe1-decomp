struct PurgeParams_0040E7C0 {
    char data[0x4C];
    void execute();
};

class AIModule {
public:
    int purgeCallbacksWithID(PurgeParams_0040E7C0 p);
};

int AIModule::purgeCallbacksWithID(PurgeParams_0040E7C0 p) {
    p.execute();
    return 0;
}
