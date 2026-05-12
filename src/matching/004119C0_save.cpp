// VA: 004119C0 ResearchAIModule::save(int)
// PDB source: airchmod.cpp lines 95-129
// attempt 1: direct decompiler-shaped save using strcpy/strlen local buffer and list sentinel; implicit vptr shifted fields/local buffer by +4.
// attempt 2: explicit vptr and buffer start spelling to match observed +0x148/+0x14C fields and stack window.
// attempt 3: first module name write recomputes strlen at call site; stored length is not reused there.
// attempt 4: explicit loop label so bottom only compares item to sentinel; VC5 still combined bottom item==end/null exit.
// attempt 5: integer sentinel compare did not change the combined bottom guard.
// attempt 6: try ordinary while loop spelling.

extern "C" int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);

void rge_write(int file, void* data, int size);

class ResourceItem {
public:
    int value(int index);
};

class TechnologyItem {
public:
    TechnologyItem* prev; // +0
    TechnologyItem* next; // +4
    int id();
    char* name();
    ResourceItem* resourceCost();
};

class ResearchAIModule {
public:
    void* vptr;
    char gap_004[0xF0];
    TechnologyItem sentinel;      // +0xF4 (next at +0xF8)
    char gap_FC[0x4C];
    int techTreeLengthValue;      // +0x148
    char techTreeNameValue[260];  // +0x14C

    int save(int file);
};

int ResearchAIModule::save(int file)
{
    int tempInt;
    char tempString[257];

    rge_write(file, &this->techTreeLengthValue, 4);

    strcpy(tempString, this->techTreeNameValue);
    tempInt = strlen(tempString);
    rge_write(file, &tempInt, 4);
    rge_write(file, tempString, strlen(tempString));

    TechnologyItem* item = this->sentinel.next;
    TechnologyItem* end = &this->sentinel;
    while (item != end) {
        if (item == 0) {
            return 1;
        }
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(file, &tempInt, 4);
        rge_write(file, tempString, tempInt);
        tempInt = item->id();
        rge_write(file, &tempInt, 4);
        ResourceItem* cost = item->resourceCost();
        int i = 0;
        do {
            tempInt = cost->value(i);
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < 4);
        item = item->next;
    }

    return 1;
}
