// Attempt log for 004D3B20 TribeBuildAIModule::loadBuildList
// try 1: helper addRequired collapsed out of function; too small 272B.
// try 2: inline three repeated add-if-missing blocks; exact size but offsets 4 low due empty base layout.
// try 3: give BuildAIModule a dummy vptr/base word so offsets land; first mismatch now loop shape (pointer-walk vs indexed).
// try 4: declare array pointer volatile to discourage pointer-walk strength reduction; no change.
// try 5: make loop index volatile; worsened from offset 0, rolled back.
// try 6: use local array pointer variable in each scan; no improvement.
// try 7: /O1 flag probe; too small 544B, rolled back.
// try 8: /Oy- flag probe; worse from offset 0, rolled back.
// try 9: /GX flag probe; unchanged, rolled back.
// try 10: reviewed repeated helper vs inline; inline required for size, helper collapses to 272B.
// BLOCKER: exact 565B size with inline repeated source, but scan/copy loops are in a different VC5 basin: original uses count in ECX, max in EDX, indexed [arr+eax*4]; rebuilt uses extra max test/pointer-walk and shifted block sizes. Broad loop-shape diff remains, not accepted_drift-safe.

typedef unsigned int uint;
void* operator new(uint size);
void operator delete(void* ptr);
class RGE_Player;
class BuildAIModule { public: void* vtable_ptr; int loadBuildList(char*, RGE_Player*); };
class TribeBuildAIModule : public BuildAIModule { public: char gap_004[0x5ac - 4]; int* arr; int count; char gap_5b4[4]; int max; int loadBuildList(char* filename, RGE_Player* player); };

int TribeBuildAIModule::loadBuildList(char* filename, RGE_Player* player)
{
    int i;
    int* nv;
    int newMax;

    i = 0;
    if (this->count > 0) {
        int* p = this->arr;
        do {
            if (i >= this->max) break;
            if (p[i] == 0x46) goto found46;
            i++;
        } while (i < this->count);
    }
    if (this->count > this->max - 1) {
        newMax = this->count + 1;
        nv = (int*)operator new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->max > 0) {
                do { if (i >= newMax) break; i++; nv[i-1] = this->arr[i-1]; } while (i < this->max);
            }
            operator delete((void*)this->arr); this->arr = nv; this->max = newMax;
        }
    }
    this->arr[this->count] = 0x46;
    this->count++;
found46:
    i = 0;
    if (this->count > 0) {
        int* p = this->arr;
        do { if (i >= this->max) break; if (p[i] == 0x67) goto found67; i++; } while (i < this->count);
    }
    if (this->count > this->max - 1) {
        newMax = this->count + 1;
        nv = (int*)operator new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->max > 0) { do { if (i >= newMax) break; i++; nv[i-1] = this->arr[i-1]; } while (i < this->max); }
            operator delete((void*)this->arr); this->arr = nv; this->max = newMax;
        }
    }
    this->arr[this->count] = 0x67;
    this->count++;
found67:
    i = 0;
    if (this->count > 0) {
        int* p = this->arr;
        do { if (i >= this->max) break; if (p[i] == 0x44) goto found44; i++; } while (i < this->count);
    }
    if (this->count > this->max - 1) {
        newMax = this->count + 1;
        nv = (int*)operator new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->max > 0) { do { if (i >= newMax) break; i++; nv[i-1] = this->arr[i-1]; } while (i < this->max); }
            operator delete((void*)this->arr); this->arr = nv; this->max = newMax;
        }
    }
    this->arr[this->count] = 0x44;
    this->count++;
found44:
    return BuildAIModule::loadBuildList(filename, player);
}
