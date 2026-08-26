// VA: 0044DF80 InfluenceMap::InfluenceMap(int,int,unsigned char)
// Binary anchor. Use natural memset (VC5 inlines to the original rep stosd/stosb)
// and spell row setup as guarded do/while with i++ before offset += xSize.
// The grouped TU supplies the canonical virtual InfluenceMap surface.
#include <string.h>
void* __cdecl operator_new(unsigned int size);
#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap { int vfptr,xSizeValue,ySizeValue,xReferencePointValue,yReferencePointValue; unsigned char* valueValue; unsigned char** rowValue; InfluenceMap(int,int,unsigned char); };
#endif
InfluenceMap::InfluenceMap(int xSize, int ySize, unsigned char fillValue)
    : xSizeValue(xSize),
      xReferencePointValue(0), yReferencePointValue(0) {
    this->ySizeValue = ySize;
    int total = ySize * xSize;
    this->valueValue = (unsigned char*)operator_new(total);
    memset(this->valueValue, fillValue, total);
    this->rowValue = (unsigned char**)operator_new(this->ySizeValue * 4);
    if (this->rowValue) {
        int i = 0;
        int offset = 0;
        if (i < this->ySizeValue) {
            do {
                this->rowValue[i] = this->valueValue + offset;
                i++;
                offset += this->xSizeValue;
            } while (i < this->ySizeValue);
        }
    }
}
