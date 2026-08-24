// 00442100 RGE_Doppleganger_Creator::RGE_Doppleganger_Creator
// first pass: ctor allocates four arrays and lazily opens DD log file.

#ifndef DPL_OBJ_SHARED_CONTEXT
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern void* DDlogf;

class RGE_Doppleganger_Creator {
public:
    void* player;
    int maxCount;
    int activeCount;
    int* objects;
    int* mapAddresses;
    int* lastMapValue;
    int* objectIds;

    RGE_Doppleganger_Creator(void* player, int count);
};
#endif

#ifdef DPL_OBJ_SHARED_CONTEXT
RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Player* player, int count)
#else
RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(void* player, int count)
#endif
{
    this->objects = (int*)calloc(count, 4);
    this->mapAddresses = (int*)calloc(count, 4);
    this->lastMapValue = (int*)calloc(count, 4);
    this->objectIds = (int*)calloc(count, 4);
    this->maxCount = count;
    this->activeCount = 0;
    this->player = player;
    if (DDlogf == 0) {
        DDlogf = fopen("c:\\aoedoppl.txt", "w");
    }
}
