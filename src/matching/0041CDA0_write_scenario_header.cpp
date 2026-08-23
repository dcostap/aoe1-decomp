void rge_write_uncompressed(int file, void* data, int size);
void operator delete(void*);
#ifndef BASEGAME_GROUPED_TU
class RGE_Scenario_Header { public: virtual void vf00(); virtual void write(int file); ~RGE_Scenario_Header(); };
class RGE_World { public: char pad[0x5C]; int header_info; };
class RGE_Base_Game { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void* new_scenario_header(void*);
    char pad_04[0x3F4-4]; RGE_World* world;
    void write_scenario_header(int file);
};
#endif
void RGE_Base_Game::write_scenario_header(int file) {
    int header_size;
    RGE_Scenario_Header* header = (RGE_Scenario_Header*)this->new_scenario_header((void*)this->world->header_info);
    if (header != 0) {
        header->write(file);
        header->~RGE_Scenario_Header();
        operator delete(header);
    } else {
        header_size = 0;
        rge_write_uncompressed(file, &header_size, 4);
    }
}
