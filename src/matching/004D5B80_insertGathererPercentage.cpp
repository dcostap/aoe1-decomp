struct TribeBuildMD {
    char gap_00[0xF0];
    void* player;
};

class BuildAIModule {
public:
    int insertItem(void* player, int a, int b, int c, int d, int e, int f);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_00[0x5BC];
    TribeBuildMD* md;

    int insertGathererPercentage(int a, int b, int c);
};

int TribeBuildAIModule::insertGathererPercentage(int a, int b, int c) {
    return insertItem(this->md->player, a, 1, 6, b, 1, c);
}
