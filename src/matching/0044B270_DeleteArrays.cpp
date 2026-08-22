#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0x1024];
    char* ProbArray;
    char* PlacementArray;

    void DeleteArrays(void);
};
#endif

void DeleteArrays(PointMaker* this_); // not used

void PointMaker::DeleteArrays(void) {
    if (this->ProbArray != 0) {
        operator delete(this->ProbArray);
    }
    if (this->PlacementArray != 0) {
        operator delete(this->PlacementArray);
    }
    this->ProbArray = 0;
    this->PlacementArray = 0;
}
