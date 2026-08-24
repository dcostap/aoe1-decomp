// VA: 0044CEF0 RGE_Person_Info::set_current_campaign(long)
// 337 bytes, EH-framed (/GX)
//
// Attempt log:
// - baseline: named RGE_Person_Info/RGE_Campaign_Info ownership, typed search,
//   calloc/memcpy growth, and C++ new construction; rebuilt body matches the
//   original call set through the constructor tail but emits three EH returns
//   (375 bytes versus the 337-byte oracle).
// - probes: positive/nested guards, shared result/goto labels, hoisted locals,
//   and the known destructor declaration all kept the same 77-byte mismatch.
// - follow-up probes: decompiler-shaped do/while introduced two extra calls;
//   /O1 and /Os destroyed the matching intrinsic/ABI basin; int/signed-char
//   result locals, named/function-scope new pointers, explicit label order, and
//   uVar1-style call-result reuse all emitted the same 375-byte body.
// - probe 031: initialized a uchar result and used a natural positive guard;
//   this removed the EH handler relocation, changed the prologue, and widened
//   positional drift to 307 bytes, so it was restored.
// - probe 034: combined an initialized uchar result with a natural positive
//   guard and one done label; this also widened positional drift to 307 bytes
//   despite a closer size, so it was restored.
// - follow-up probes 039/040/041/044/045: an outer result-setting arm, /Ob0,
//   <stdlib.h>, /G5, and /Og all reproduced the same 375-byte body and 77-byte
//   mismatch; none changed the shared EH-tail CFG.
// - probe 042: replacing the match goto with break plus a post-loop test
//   reduced size to 360 but destroyed the exact body blocks and widened the
//   positional diff to 276 bytes, so it was restored.
// - probe 046: a full decompiler-style result assignment and explicit do-loop
//   added duplicate get_name/verify calls and widened the diff to 304 bytes,
//   so it was restored.
// - matching pass: defining the binary-supported RGE_Campaign_Info destructor
//   in this translation unit selected the original shared EH return tail.
//   The target then matched at 337 bytes; reviewed 255-byte name fields also
//   preserved the match. Keep /O2 /Oy /GX.

#include <string.h>

#ifndef GAMEINFO_SHARED_CONTEXT
void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

struct RGE_Campaign {
    char* get_name(void);
    long scenario_number(void);
};

struct RGE_Campaign_Info {
    char name[255];          // +0x000
    unsigned char name_pad;  // +0x0FF
    int current_scenario;    // +0x100
    int scenario_num;        // +0x104
    char* scenario_info;     // +0x108
    int last_scenario;       // +0x10C
    RGE_Campaign* campaign;  // +0x110

    RGE_Campaign_Info(RGE_Campaign* camp);
    ~RGE_Campaign_Info();
    unsigned char verify_campaign_name(char* name);
};

struct RGE_Person_Info {
    char name[255];                   // +0x000
    unsigned char name_pad;            // +0x0FF
    int current_campaign;             // +0x100
    int campaign_info_num;            // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108
    int campaign_num;                 // +0x10C
    RGE_Campaign** campaigns;         // +0x110

    unsigned char set_current_campaign(long index);
};
#endif

#ifndef GAMEINFO_SHARED_CONTEXT
RGE_Campaign_Info::~RGE_Campaign_Info() {
    if (scenario_info != 0) {
        free(scenario_info);
        scenario_info = 0;
    }
}
#endif

unsigned char RGE_Person_Info::set_current_campaign(long index) {
    // Bounds check
    if (index < 0 || index >= campaign_num || campaigns[index] == 0) {
        return 0;
    }
    
    // Search for matching campaign info
    for (int i = 0; i < campaign_info_num; i++) {
        if (campaign_info[i]->verify_campaign_name(campaigns[index]->get_name())) {
            current_campaign = i;
            return 1;
        }
    }
    
    // No match found - allocate new campaign info entry
    RGE_Campaign_Info** newlist = (RGE_Campaign_Info**)calloc(campaign_info_num + 1, 4);
    if (campaign_info != 0) {
        memcpy(newlist, campaign_info, campaign_info_num * 4);
    }
    free(campaign_info);
    campaign_info = newlist;
    
    // Use C++ new expression for EH frame generation
    campaign_info[campaign_info_num] = new RGE_Campaign_Info(campaigns[index]);
    current_campaign = campaign_info_num;
    campaign_info_num++;
    return 1;
}
