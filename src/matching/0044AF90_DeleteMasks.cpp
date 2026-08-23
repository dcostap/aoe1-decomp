// first pass: delete the four mask pointers in order from the PointMaker tail
// if this misses, the remaining mismatch is likely only the surrounding prolog/epilog register choice

#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0xFA8];
    void* Mask_2x2;
    void* Mask_3x3;
    void* Mask_4x4;
    void* Mask_5x5;

    void DeleteMasks(void);
};
#endif

void PointMaker::DeleteMasks(void) {
    operator delete(this->Mask_2x2);
    operator delete(this->Mask_3x3);
    operator delete(this->Mask_4x4);
    operator delete(this->Mask_5x5);
}
