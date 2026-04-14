struct PurgeParams_0040E770 {
    char data[0x48];
    void execute();
};

class AIModule {
public:
    int purgeMessages(PurgeParams_0040E770 p);
};

int AIModule::purgeMessages(PurgeParams_0040E770 p) {
    p.execute();
    return 0;
}
