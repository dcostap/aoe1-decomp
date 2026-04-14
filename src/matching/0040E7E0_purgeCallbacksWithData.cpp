struct PurgeParams_0040E7E0 {
    char data[0x54];
    void execute();
};

class AIModule {
public:
    int purgeCallbacksWithData(PurgeParams_0040E7E0 p);
};

int AIModule::purgeCallbacksWithData(PurgeParams_0040E7E0 p) {
    p.execute();
    return 0;
}
