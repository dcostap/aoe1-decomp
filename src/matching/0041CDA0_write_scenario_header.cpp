void rge_write_uncompressed(int file, void* data, int size);
void operator delete(void*);

class RGE_World { public: char pad[0x5C]; int header_info; };
void RGE_Base_Game::write_scenario_header(int file) {
    int header_size;
    RGE_Scenario_Header* header = this->new_scenario_header(this->world->header_info);
    if (header != 0) {
        header->write(file);
        header->~RGE_Scenario_Header();
        operator delete(header);
    } else {
        header_size = 0;
        rge_write_uncompressed(file, &header_size, 4);
    }
}
