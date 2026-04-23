class PointMaker {
public:
    char gap_00[0x1024];
    void* ProbArray;
    void* PlacementArray;

    void SetDefaultValues(void);
    void MakeArrays(void);
    void CreateMasks(void);
    PointMaker();
};

PointMaker::PointMaker() {
    this->ProbArray = 0;
    this->PlacementArray = 0;
    SetDefaultValues();
    MakeArrays();
    CreateMasks();
}
