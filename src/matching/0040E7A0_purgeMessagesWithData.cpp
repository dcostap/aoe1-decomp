struct PurgeParams_0040E7A0 {
    char data[0x54];
    void execute();
};

class AIModule {
public:
    int purgeMessagesWithData(PurgeParams_0040E7A0 p);
};

int AIModule::purgeMessagesWithData(PurgeParams_0040E7A0 p) {
    p.execute();
    return 0;
}
