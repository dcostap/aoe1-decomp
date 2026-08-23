#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0x0FD0];
    int MaxBranchFlag;
    char gap_0FD4[0x44];
    int MaxNumberOfBranchLevels;

    void SetMaxNumberOfBranchLevels(int param);
};
#endif

void PointMaker::SetMaxNumberOfBranchLevels(int param) {
    MaxBranchFlag = 1;
    MaxNumberOfBranchLevels = param;
}
