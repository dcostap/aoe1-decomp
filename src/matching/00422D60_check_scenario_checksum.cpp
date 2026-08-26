

unsigned char RGE_Base_Game::check_scenario_checksum(char* filename, long expected) {
    long cs = this->get_scenario_checksum(filename);
    if (cs != 0 && cs == expected) return 1;
    return 0;
}
