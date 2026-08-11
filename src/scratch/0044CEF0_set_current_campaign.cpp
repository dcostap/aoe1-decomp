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
// - left in scratch: canonical natural source; remaining drift is the VC5 EH
//   return-tail layout (original shared cleanup versus rebuilt duplicated
//   cleanup), not an unresolved campaign ownership or call-set issue. Keep
//   /O2 /Oy /GX; no productive source lead remains in this bounded pass.

#include <string.h>

void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

struct RGE_Campaign {
    char* get_name(void);
    long scenario_number(void);
};

struct RGE_Campaign_Info {
    char name[256];          // +0x000
    int current_scenario;    // +0x100
    int scenario_num;        // +0x104
    char* scenario_info;     // +0x108
    int last_scenario;       // +0x10C
    RGE_Campaign* campaign;  // +0x110

    RGE_Campaign_Info(RGE_Campaign* camp);
    unsigned char verify_campaign_name(char* name);
};

struct RGE_Person_Info {
    char name[256];                   // +0x000
    int current_campaign;             // +0x100
    int campaign_info_num;            // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108
    int campaign_num;                 // +0x10C
    RGE_Campaign** campaigns;         // +0x110

    unsigned char set_current_campaign(long index);
};

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
