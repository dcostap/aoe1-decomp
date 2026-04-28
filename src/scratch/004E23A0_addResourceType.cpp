// 004E23A0 TribeInformationAIModule::addResourceType
// Size: 145 bytes

void* operator new(unsigned int size);
void operator delete(void* ptr);

class TribeInformationAIModule {
public:
    char gap_00[0x4C8];

    void addResourceType(int param_1, int param_2);
};

void TribeInformationAIModule::addResourceType(int param_1, int param_2) {
    int* new_arr;
    int i;

    new_arr = (int*)operator new(
        4 + 4 * (*(int*)((char*)this + 0x4CC + param_1 * 4)));
    i = 0;
    if (*(int*)((char*)this + 0x4CC + param_1 * 4) > 0) {
        do {
            i++;
            new_arr[i - 1] = *(int*)(*(int*)((char*)this + 0x4C8 + param_1 * 4) + (i - 1) * 4);
        } while (i < *(int*)((char*)this + 0x4CC + param_1 * 4));
    }
    new_arr[i] = param_2;

    {
        int* old_arr = *(int**)((char*)this + 0x4C8 + param_1 * 4);
        if (old_arr != 0) {
            operator delete(old_arr);
        }
    }
    *(int**)((char*)this + 0x4C8 + param_1 * 4) = new_arr;
    (*(int*)((char*)this + 0x4CC + param_1 * 4))++;
}
