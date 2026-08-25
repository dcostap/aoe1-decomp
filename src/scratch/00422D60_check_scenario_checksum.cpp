

unsigned char RGE_Base_Game::check_scenario_checksum(const char* filename, unsigned long expected) {
    unsigned long cs = this->get_checksum(filename);
    if (cs != 0 && cs == expected) return 1;
    return 0;
}
