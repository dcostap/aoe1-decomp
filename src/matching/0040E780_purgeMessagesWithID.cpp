struct PurgeParams_0040E780 {
    char data[0x4C];
    void execute();
};

class AIModule {
public:
    int purgeMessagesWithID(PurgeParams_0040E780 p);
};

int AIModule::purgeMessagesWithID(PurgeParams_0040E780 p) {
    p.execute();
    return 0;
}
