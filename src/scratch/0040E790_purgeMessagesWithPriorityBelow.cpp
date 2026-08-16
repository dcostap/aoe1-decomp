struct PurgeParams_0040E790 {
    char data[0x4C];
    void execute();
};

class AIModule {
public:
    int purgeMessagesWithPriorityBelow(PurgeParams_0040E790 p);
};

int AIModule::purgeMessagesWithPriorityBelow(PurgeParams_0040E790 p) {
    p.execute();
    return 0;
}
