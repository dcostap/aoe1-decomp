// 00409430 TribeBuildAIModule::loadBuildList
// aibldmod.cpp
// Attempt log:
// try 1: broad reconstruction from packet: copy filename, open/parse build-list file, create build items.
// try 2: modeled VC5 constructor-like EH context with /GX because original has EH registration and operator-new state for BuildItem allocations.
// try 3: modeled filename copy to this+0x1A4 via strncpy(...,0x3F), empty/default filename rejection, and initial log/open path.
// try 4: modeled local stack buffers line/token/label around 260 bytes each, matching original's large 0x168 frame only approximately.
// try 5: modeled file open/read loop with getline(line,0x100,file), comment line check for `//`, sscanf dispatch, and command switch.
// try 6: modeled command cases mapping to build item type 0/1/2/3/4/5/6 and optional extra-field sscanf.
// try 7: modeled duplicate seen-id scan at +0x5AC/+0x5B0/+0x5B8 for type 0 entries.
// try 8: modeled object-rules lookup adjustment only as a placeholder; exact unit-def size/range and float fields remain missing.
// try 9: modeled BuildItem allocation (0xB0), constructor-like args, list linking at +0x6C/+0x70, buildCount increment, and setName call.
// try 10: fixed VC5 compile issues: removed explicit operator-new declaration and scoped loop variable to avoid goto crossing initialization.
// try 11: /GX and default flags both compile to .text 1008B vs original 1015B; left default rsp because /GX did not improve size. No full byte diff available.
// left in scratch: broad parser/allocator behavior exists, but exact local/EH/object surfaces and rule lookup are unresolved; rebuilt is 7B size-short. No accepted_drift: no comparable localized diff.

#include <string.h>
#include <stdio.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl sscanf(const char*, const char*, ...);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" void __cdecl free(void*);

class BuildItem { public: char gap[0xB0]; BuildItem(int,int,float,float,int,int,int,int,int,int,int,int,int,int,int); void setName(char*); };
class LineFile { public: int getline(char*, int, void*); };
class TribeBuildAIModule {
public:
    char gap0[0xF0];
    char listHook[0x70];    // +f0 roughly
    void* tail;             // +160
    char gap164[0x1A0-0x164];
    int buildCount;         // +1a0
    char fileName[0x40];    // +1a4
    char gap1e4[0x5AC-0x1E4];
    int* seenIds; int seenCount; char gap5b4[4]; int seenCap;

    int loadBuildList(const char* name, void* rules, int, int, int);
    void log(const char*, ...);
    void clearBuildList();
};

int TribeBuildAIModule::loadBuildList(const char* name, void* rules, int p3, int p4, int p5) {
    char line[260];
    char token[260];
    char label[260];
    char c1,c2;
    int id, count, type, extra;
    float x,y;
    void* file;
    char* p;

    strncpy(fileName, name, 0x3f);
    if (strcmp(fileName, (const char*)0x57F350) == 0 || !name || !*name) return 0;
    log((const char*)0x57F328, name);
    sprintf(line, (const char*)0x57F324, name);
    file = (void*)sscanf(line, (const char*)0x57F320);
    if (!file) { log((const char*)0x57F308); return 0; }
    log((const char*)0x57F2D8);
    if (buildCount > 0) clearBuildList();
    buildCount = 0;

    while (((LineFile*)file)->getline(line, 0x100, 0)) {
        x = y = 1.5f;
        id = -1;
        if (sscanf(line, (const char*)0x57F2D0, &c2, &c1) == 2 && c2 == '/' && c1 == '/') continue;
        count = 1; type = 0; extra = 0;
        if (sscanf(line, (const char*)0x57F2C0, &c1, &id, &count, &x, &y, &extra, &type) < 2) continue;
        switch (c1) {
        case '0': type = 0; break;
        case '1': sscanf(line, (const char*)0x57F2A8, &extra); type = 0; break;
        case '2': type = 1; break;
        case '3': type = 4; break;
        case '4': type = 2; break;
        case '5': sscanf(line, (const char*)0x57F2A8, &extra); type = 2; break;
        case '6': type = 3; break;
        case '7': type = 5; break;
        case '8': type = 6; break;
        default: continue;
        }
        if (type == 0) {
            for (int i=0;i<seenCount && i<seenCap;i++) if (seenIds[i] == id) goto next;
        }
        if ((type == 0 || type == 2) && id >= 0) {
            // rules lookup would adjust x/y from object data
        }
        {
            int k;
            for (k=0; k<count; ++k) {
                BuildItem* item = new BuildItem(type, buildCount, 1, 0, id, (int)x, (int)y, extra, -1, -1, -1, 0, 0, 0, 0);
                if (item) {
                    ++buildCount;
                    *(void**)((char*)item+0x6c) = &listHook;
                    *(void**)((char*)item+0x70) = tail;
                    *(void**)((char*)tail+0x6c) = item;
                    tail = item;
                    item->setName(token);
                }
            }
        }
next: ;
    }
    free(file);
    if (strcmp(name, (const char*)0x57F2A0) == 0) return 0;
    return 1;
}
