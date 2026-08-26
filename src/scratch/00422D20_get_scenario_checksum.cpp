long RGE_Base_Game::get_scenario_checksum(char* scenario_name) {
    RGE_Scenario_Header* hdr = this->get_scenario_header(scenario_name, 0);
    if (!hdr) return 0;
    unsigned long checksum = hdr->checksum;
    delete hdr;
    return checksum;
}
