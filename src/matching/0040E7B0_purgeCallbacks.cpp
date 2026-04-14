struct PurgeParams_0040E7B0 {
    char data[0x48];
    void execute();
};

class AIModule {
public:
    int purgeCallbacks(PurgeParams_0040E7B0 p);
};

int AIModule::purgeCallbacks(PurgeParams_0040E7B0 p) {
    p.execute();
    return 0;
}
