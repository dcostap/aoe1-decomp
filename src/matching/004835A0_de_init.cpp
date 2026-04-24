// attempt 1: compile error, wrong world type
// attempt 2: fix world type

class RGE_RMM_Database_Controller;
class RGE_Random_Map_Module;
class RGE_Map;

class RGE_RMM_Database_Controller {
public:
    char gap_00[0x8];
    void** world;
    char gap_0C[0x24];
    int map_type;
    int map_seed;
    int number_of_players;

    void destroy_shared_resources();
    void update_map_info(RGE_Map* map);
    unsigned char de_init();
};

void operator delete(void* p);

class RGE_Random_Map_Module {
public:
    ~RGE_Random_Map_Module();
};

unsigned char RGE_RMM_Database_Controller::de_init() {
    this->map_type = 0;
    this->map_seed = -1;
    this->number_of_players = 0;
    while (world != 0) {
        RGE_Random_Map_Module* p = (RGE_Random_Map_Module*)*world;
        if (p != 0) {
            p->~RGE_Random_Map_Module();
            operator delete(p);
        }
    }
    destroy_shared_resources();
    update_map_info(0);
    return 0;
}
