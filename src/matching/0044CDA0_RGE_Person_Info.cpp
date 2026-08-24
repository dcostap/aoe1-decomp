// gameinfo.cpp:313-324, 106 bytes
// attempt 1: destructor with campaign_info array cleanup
#ifndef GAMEINFO_SHARED_CONTEXT
extern void __cdecl operator_delete(void*);
extern void __cdecl free(void*);

class RGE_Campaign_Info {
public:
    virtual void vf00();
    ~RGE_Campaign_Info();
};

class RGE_Person_Info {
public:
    char gap_00[0x104];
    int campaign_info_num;     // +0x104
    RGE_Campaign_Info** campaign_info;  // +0x108

    ~RGE_Person_Info();
};
#endif

RGE_Person_Info::~RGE_Person_Info() {
    if (campaign_info != 0) {
        for (int i = 0; i < campaign_info_num; i++) {
            RGE_Campaign_Info* ci = campaign_info[i];
            if (ci != 0) {
                ci->~RGE_Campaign_Info();
                operator_delete(ci);
            }
        }
        free(campaign_info);
        campaign_info = 0;
        campaign_info_num = 0;
    }
}
