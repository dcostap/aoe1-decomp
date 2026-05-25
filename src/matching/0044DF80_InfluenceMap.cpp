// VA: 0044DF80 InfluenceMap::InfluenceMap(int,int,unsigned char)
// Exact MATCH. Key fixes: use natural memset (VC5 inlines to original rep stosd/stosb)
// and spell row setup as guarded do/while with i++ before offset += xSize.
#include <string.h>
void* __cdecl operator_new(unsigned int size);
struct InfluenceMap { int vfptr,xSize,ySize,xRef,yRef; unsigned char* value; unsigned char** row; InfluenceMap(int,int,unsigned char); };
InfluenceMap::InfluenceMap(int xSize, int ySize, unsigned char fillValue) {
    this->ySize = ySize;
    int total = ySize * xSize;
    this->xSize = xSize;
    this->xRef = 0;
    this->yRef = 0;
    this->vfptr = 0x00570444;
    this->value = (unsigned char*)operator_new(total);
    memset(this->value, fillValue, total);
    this->row = (unsigned char**)operator_new(this->ySize * 4);
    if (this->row) {
        int i = 0;
        int offset = 0;
        if (i < this->ySize) {
            do {
                this->row[i] = this->value + offset;
                i++;
                offset += this->xSize;
            } while (i < this->ySize);
        }
    }
}
