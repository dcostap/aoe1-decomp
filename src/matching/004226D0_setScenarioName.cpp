extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void RGE_Base_Game::setScenarioName(char* name) {
    strncpy(this->scenarioName_, name, 0x80);
    *((unsigned char*)this + 0x97C) = 0;
}
