#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1024];
    char* PlacementArray;
    char* RetrieveMap();
};
#endif

char* PointMaker::RetrieveMap() { return this->PlacementArray; }
