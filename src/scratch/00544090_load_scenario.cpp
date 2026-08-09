// VA: 00544090 RGE_Game_World::load_scenario
// PDB source: World.cpp lines 2393-2465
//
// Attempt log:
// - The initial draft had the right version dispatch and virtual slots but
//   used raw absolute-address macros, fastcall shims, and a misnamed final
//   get-campaign call.  It was 442 bytes with one extra direct call.
// - The executable proves the scenario-version words are external rdata
//   values, the base-game pointer is the typed global, and the file APIs use
//   the same int-returning declarations as the exact scenario-header donors.
// - The remaining source shape follows the nested version chain: the 1.02
//   handler is shared with the 1.03 path, while later handlers jump over the
//   chain to one common success tail and failures remain cold at the end.
// - Typed-global/nested, source-ordered, and late-version negative/positive
//   guard variants all settled in the same 443-byte VC5 basin.  The current
//   candidate has 16/17 ordered calls and a localized three-byte size excess:
//   VC5 places one near jump around the cold failure block where the original
//   uses a short jump.  No raw-address or register-forcing scaffolding remains.

extern int world_update_counter;

extern int version_101;
extern int version_102;
extern int version_103;
extern int version_104;
extern int version_105;
extern int version_106;
extern int version_107;
extern int version_108;
extern int version_109;
extern int version_110;
extern int version_111;

extern int rge_read_uncompressed(int handle, void* buffer, int count);
extern int rge_close(int handle);
extern void* malloc(int size);
extern int free(void* pointer);

class RGE_Player_Info {
};

class RGE_Base_Game {
public:
    int campaign_open_scenario();
    void get_campaign_info(int* campaign, int* player, int* scenario_count);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Game_World {
public:
    virtual void stub_00();  virtual void stub_04();  virtual void stub_08();  virtual void stub_0C();
    virtual void stub_10();  virtual void stub_14();  virtual void stub_18();  virtual void stub_1C();
    virtual void stub_20();  virtual void stub_24();  virtual void stub_28();  virtual void stub_2C();
    virtual void stub_30();  virtual void stub_34();  virtual void stub_38();  virtual void stub_3C();
    virtual void stub_40();  virtual void stub_44();  virtual void stub_48();  virtual void stub_4C();
    virtual void stub_50();  virtual void stub_54();  virtual void stub_58();  virtual void stub_5C();
    virtual void stub_60();  virtual void stub_64();  virtual void stub_68();  virtual void stub_6C();
    virtual void stub_70();
    virtual void stub_74();
    virtual void stub_78();
    virtual void load_scenario1(int file, RGE_Player_Info& info);
    virtual void load_scenario2(int file, RGE_Player_Info& info);
    virtual void load_scenario3(int file, RGE_Player_Info& info);
    virtual void load_scenario4(int file, RGE_Player_Info& info);
    virtual void load_scenario5(int file, RGE_Player_Info& info);
    virtual void load_scenario6(int file, RGE_Player_Info& info);
    virtual void load_scenario7(int file, RGE_Player_Info& info);
    virtual void load_scenario8(int file, RGE_Player_Info& info);
    virtual void stub_9C();
    virtual void stub_A0();
    virtual void stub_A4();
    virtual void setup_player_colors(RGE_Player_Info& info);
    virtual void stub_AC();

    char gap_04[0xA0];
    int campaign;
    int campaign_player;
    int campaign_scenario;

    unsigned char load_scenario(RGE_Player_Info& info);
};

unsigned char RGE_Game_World::load_scenario(RGE_Player_Info& info) {
    int header_size;
    int version;
    int file;

    world_update_counter = 0;
    file = rge_base_game->campaign_open_scenario();
    if (file == -1) {
        goto cleanup;
    }

    rge_read_uncompressed(file, &header_size, 4);

    if (header_size == version_101) {
        this->load_scenario1(file, info);
        goto success;
    }

    if (header_size == version_102) {
        goto shared_80;
    }

    if (header_size == version_103) {
        rge_read_uncompressed(file, &version, 4);
        if (version > 0) {
            void* buffer = malloc(version);
            if (buffer == 0) {
                goto fail;
            }
            rge_read_uncompressed(file, buffer, version);
            free(buffer);
        }
        goto shared_80;
    }

    if (header_size == version_104) {
        this->load_scenario3(file, info);
        goto success;
    }
    if (header_size == version_105) {
        this->load_scenario4(file, info);
        goto success;
    }
    if (header_size == version_106) {
        this->load_scenario5(file, info);
        goto success;
    }
    if (header_size == version_107) {
        this->load_scenario6(file, info);
        goto success;
    }
    if (header_size == version_108) {
        this->load_scenario7(file, info);
        goto success;
    }
    if (header_size == version_109 ||
        header_size == version_110 ||
        header_size == version_111) {
        this->load_scenario8(file, info);
        goto success;
    } else {
        goto fail;
    }

shared_80:
    this->load_scenario2(file, info);
    goto success;

success:
    this->setup_player_colors(info);
    rge_base_game->get_campaign_info(&this->campaign,
                                     &this->campaign_player,
                                     &this->campaign_scenario);
    return 1;

fail:
    rge_close(file);
cleanup:
    return 0;
}
