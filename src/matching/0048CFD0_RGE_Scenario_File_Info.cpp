// sceninfo.cpp:67-80, 110 bytes
// attempt 1: 85.5%, ret at start
// attempt 2: 85.5%, pointer math
// attempt 3: 87.3%, extern save call
// attempt 4: 78.2%, extern header dtor
// attempt 5: 82.7%, natural loop worse
// BEST: 78.2%. BLOCKER: save() called via push esi/call eax,
//   base pointer reloaded each iteration, register allocation differs.
//   No EH frame needed. Core logic (save call, loop with dtor+delete,
//   free+null) all correct.
#ifndef AOE1_SCENINFO_TU_CONTEXT
class RGE_Scenario_Header {
public:
    ~RGE_Scenario_Header();
};

extern void __cdecl free(void*);
extern void __cdecl operator_delete(void*);

class RGE_Scenario_File_Info {
public:
    char gap_00[0x104];
    int scenario_num;       // +0x104
    void* scenarios;        // +0x108

    void save();

    ~RGE_Scenario_File_Info();
};
#endif

RGE_Scenario_File_Info::~RGE_Scenario_File_Info() {
    save();
    if (scenario_num > 0) {
        for (int i = 0; i < scenario_num; i++) {
            RGE_Scenario_Header* hdr = *(RGE_Scenario_Header**)((char*)scenarios + i * 0x10C + 4);
            if (hdr != 0) {
                hdr->~RGE_Scenario_Header();
                operator_delete(hdr);
            }
        }
        free(scenarios);
        scenarios = 0;
        scenario_num = 0;
    }
}
