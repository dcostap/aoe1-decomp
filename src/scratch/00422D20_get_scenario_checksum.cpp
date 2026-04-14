class RGE_Scenario_Header_cks {
public:
    void destroy(void);
    char gap_00[0x0C];
    int checksum;
};

extern "C" void __cdecl operator_delete(void*);

class RGE_Base_Game_cks {
public:
    int get_scenario_checksum(int scenario_num);
    RGE_Scenario_Header_cks* get_scenario_header(int scenario_num, int flag);
};

int RGE_Base_Game_cks::get_scenario_checksum(int scenario_num) {
    RGE_Scenario_Header_cks* hdr = this->get_scenario_header(scenario_num, 0);
    if (!hdr) return 0;
    int cksum = hdr->checksum;
    hdr->destroy();
    operator_delete(hdr);
    return cksum;
}
