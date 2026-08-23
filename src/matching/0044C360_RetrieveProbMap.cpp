#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1020];
    char* ProbArray;
    char* RetrieveProbMap();
};
#endif

char* PointMaker::RetrieveProbMap() { return this->ProbArray; }
