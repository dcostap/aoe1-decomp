// 00524530 TRIBE_Game::load_db_files
// Source: tribegam.cpp lines 1850-1879
// Attempt log:
// initial: packet-modeled local TRIBE_Game/RGE_Game_World layout and natural source.
// fixed: avoid non-polymorphic base subobject (+4 this adjustment); declare input methods on local TRIBE_Game.

class RGE_Game_World {
public:
    virtual void _d0();  virtual void _d1();  virtual void _d2();  virtual void _d3();
    virtual void _d4();  virtual void _d5();  virtual void _d6();  virtual void _d7();
    virtual void _d8();  virtual void _d9();  virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void destroyGameData(int flag);        // +0xA0
    virtual void _d41(); virtual void _d42();
    virtual char load_db_files(char* file1, char* file2); // +0xAC
};

class RGE_Prog_Info {
public:
    char gap_00[0xF3];
    char db_path[0x105];
    char game_data_file[1];
};

class TRIBE_Game {
public:
    virtual void _d0();  virtual void _d1();  virtual void _d2();  virtual void _d3();
    virtual void _d4();  virtual void _d5();  virtual void _d6();  virtual void _d7();
    virtual void _d8();  virtual void _d9();  virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void _d40(); virtual void _d41(); virtual void _d42(); virtual void _d43();
    virtual void _d44();
    virtual RGE_Game_World* createGameWorld(); // +0xB4

    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x3E4];
    RGE_Game_World* world;

    void disable_input();
    void enable_input();
    void show_status_message(int string_id, char* param_2, long param_3);
    void close_status_message();
    int load_db_files();
};

int TRIBE_Game::load_db_files()
{
    this->disable_input();
    this->show_status_message(0x44d, 0, -1);

    int result = 0;
    if (this->world != 0) {
        this->world->destroyGameData(1);
        this->world = 0;
    }

    this->world = this->createGameWorld();
    if (this->world != 0) {
        if (this->world->load_db_files(this->prog_info->game_data_file,
                                       this->prog_info->db_path)) {
            result = 1;
        }
        if (this->world != 0) {
            this->world->destroyGameData(1);
        }
        this->world = 0;
    }

    this->close_status_message();
    this->enable_input();
    return result;
}
