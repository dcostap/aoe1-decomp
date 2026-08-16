struct PurgeParams_0040E7D0 {
    char data[0x4C];
    void execute();
};

class AIModule {
public:
    int purgeCallbacksWithPriorityBelow(PurgeParams_0040E7D0 p);
};

int AIModule::purgeCallbacksWithPriorityBelow(PurgeParams_0040E7D0 p) {
    p.execute();
    return 0;
}
