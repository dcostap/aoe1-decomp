class PointMaker {
public:
    void DeleteArrays(void);
    void SetDefaultValues(void);
    char gap_00[0x1024];
    void* ProbArray;
    void* PlacementArray;
    void DeleteMasks(void);

    ~PointMaker();
};

PointMaker::~PointMaker() {
    DeleteArrays();
    SetDefaultValues();
    this->ProbArray = 0;
    this->PlacementArray = 0;
    DeleteMasks();
}
