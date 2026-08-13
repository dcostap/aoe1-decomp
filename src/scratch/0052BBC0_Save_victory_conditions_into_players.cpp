// 0052BBC0 T_Scenario::Save_victory_conditions_into_players
// tscenaro.cpp:795-938
//
// Attempt log:
// - initial decompiler-shaped source was 50 bytes short, used a 0x14 frame, and
//   called the wrong victory-condition helpers in the late dispatch.
// - canonical reconstruction below uses the period class/record ownership:
//   Victory_StartInfo, SP_Victory_Info[16][12], the scenario world/player
//   surfaces, and the real overloaded RGE_Victory_Conditions methods.
// - the original reuses the now-dead parameter home as the row's x1 lookup
//   offset; keep that source-level lifetime only after the typed baseline check.
// - correcting the late dispatch to add_create/add_tech and the three
//   add_destroy overloads aligned all 37 ordered call sites.
// - a diagnostic AttribType cursor reached 224 differing bytes and 88.63%
//   exact-block coverage, but was not retained: named SP_Victory_Info fields
//   are the canonical living source.  The raw dynamic-stride variant was
//   rejected because it regressed to 741 differing bytes.
// - final typed candidate remains structurally close (frame 0x10, 37/37
//   calls); residual drift is VC5 stack-home/order and tail/register coloring.
// - a fresh natural typed row cursor (`&sp_victory[row][0]` plus increment)
//   widened the frame to 0x14 and lost early blocks; it was rolled back.
// - matching the donor's trailing SP_Victory_Info padding as integer gaps did
//   not change emitted code; using condition->x1 for the rectangle calls was
//   natural but changed the frame to 0x0C and widened the structural drift, so
//   it was rolled back.
// - removing the local AttribType copy and testing the named field directly
//   was a codegen duplicate; the cursor stayed at +0x1AD8, so it was rolled back.
// - an isolated typed AttribType cursor, with natural player selection and
//   named float fields retained, moved the cursor to +0x1AD0 and improved the
//   diff to 224 bytes with 92.58% exact-block coverage; it remains diagnostic
//   pointer arithmetic, so the clean named-field source was restored.
// - a hybrid cursor using typed AttribType values but named tail fields emitted
//   the same 224-byte result as the prior cursor probe; it was restored.

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;

extern const double DAT_00577330;

class RGE_Victory_Conditions {
public:
    void destroy_all();

    unsigned char add_explore(unsigned char group, long amount, unsigned char ally_flag);
    unsigned char add_attributes(unsigned char group, long attribute, long amount,
                                 unsigned char ally_flag);
    unsigned char add_capture(unsigned char group, RGE_Static_Object* object,
                              unsigned char ally_flag);
    unsigned char add_bring(unsigned char group, RGE_Static_Object* object,
                            RGE_Static_Object* target);
    unsigned char add_bring(unsigned char group, RGE_Static_Object* object,
                            float x0, float y0, float x1, float y1);
    unsigned char add_create(unsigned char group, long object_type, long amount,
                             unsigned char ally_flag);
    unsigned char add_create(unsigned char group, long object_type, long amount,
                             float x0, float y0, float x1, float y1,
                             unsigned char ally_flag);
    unsigned char add_tech(unsigned char group, long technology);
    unsigned char add_destroy(unsigned char group, long object_type,
                              RGE_Player* player);
    unsigned char add_destroy(unsigned char group, long object_type, long amount,
                              RGE_Player* player);
    unsigned char add_destroy(unsigned char group, RGE_Player* player);
    unsigned char add_destroy(unsigned char group, RGE_Static_Object* object);
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x30];
    RGE_Victory_Conditions* victory;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();

    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Timeline;
class TPicture;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int object_id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    unsigned char victory_conquest;
    char player_name[16][0x100];
    char pad_100d[3];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
    char temp_text_1[0xE0];
    char temp_text_2[0xE0];
    char temp_text_3[0xE0];
    char* build_list[16];
    char* city_plan[16];
    char* ai_rules[16];
    unsigned char* build_list_file[16];
    unsigned char* city_plan_file[16];
    unsigned char* ai_rules_file[16];
    int build_list_file_size[16];
    int city_plan_file_size[16];
    int ai_rules_file_size[16];
    char cine_pre_game[0xE0];
    char cine_victory[0xE0];
    char cine_loss[0xE0];
    char mission_bmp[0xE0];
    float version;
    int player_posture[16];
    int pl_type[16];
    int pl_civilization[16];
    int pl_active[16];
    TPicture* mission_picture;
};

struct Player_Start_Info {
    int gold;
    int wood;
    int food;
    int stone;
};

struct Victory_StartInfo {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};

struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    RGE_Static_Object* obj;
    RGE_Static_Object* dest_obj;
};

struct Friendliness {
    int attitude[16];
};

class T_Scenario : public RGE_Scenario {
public:
    virtual ~T_Scenario();

    Player_Start_Info player_info[16];
    Victory_StartInfo victory;
    SP_Victory_Info sp_victory[16][12];
    Friendliness Opponent[16];
    int AlliedVictory[16];
    int victory_all_flag;
    int is_multi_player_flag;
    int which_player;
    char DisabledTechnology[0x500];
    int ScenarioOptions[3];
    int PlayerAge[16];
    int mp_victory_type;
    int victory_score;
    int victory_time;

    void SaveAttributesIntoPlayers();
    void Save_victory_conditions_into_players(int save_attrs);
};

void T_Scenario::Save_victory_conditions_into_players(int save_attrs) {
    if (save_attrs != 0) {
        this->SaveAttributesIntoPlayers();
    }

    RGE_Game_World* world = this->world;
    int one = 1;
    for (int player = one; player < (int)world->player_num; ++player) {
        world->players[player]->victory->destroy_all();
        world = this->world;
    }

    if (this->mp_victory_type == 4) {
        if (this->victory_all_flag != 0) {
            world = this->world;
            for (int player = one; player < (int)world->player_num; ++player) {
                RGE_Victory_Conditions* conditions = world->players[player]->victory;
                if (this->victory.MP_Exploration != 0) {
                    conditions->add_explore(8, this->victory.MP_Exploration, one);
                }
                if (this->victory.MP_Ruins != 0) {
                    conditions->add_attributes(8, 14, this->victory.MP_Ruins, one);
                }
                if (this->victory.MP_Artifacts != 0) {
                    conditions->add_attributes(8, 7, this->victory.MP_Artifacts, one);
                }
                if (this->victory.MP_Discoveries != 0) {
                    conditions->add_attributes(8, 13, this->victory.MP_Discoveries, 0);
                }
                if (this->victory.MP_Gold != 0) {
                    conditions->add_attributes(8, 3, this->victory.MP_Gold, one);
                }
                world = this->world;
            }
        }

        if (this->victory_all_flag == 0) {
            world = this->world;
            for (int player = one; player < (int)world->player_num; ++player) {
                RGE_Victory_Conditions* conditions = world->players[player]->victory;
                if (this->victory.MP_Exploration != 0) {
                    conditions->add_explore(8, this->victory.MP_Exploration, one);
                }
                if (this->victory.MP_Ruins != 0) {
                    conditions->add_attributes(9, 14, this->victory.MP_Ruins, one);
                }
                if (this->victory.MP_Artifacts != 0) {
                    conditions->add_attributes(10, 7, this->victory.MP_Artifacts, one);
                }
                if (this->victory.MP_Discoveries != 0) {
                    conditions->add_attributes(11, 13, this->victory.MP_Discoveries, 0);
                }
                if (this->victory.MP_Gold != 0) {
                    conditions->add_attributes(12, 3, this->victory.MP_Gold, one);
                }
                world = this->world;
            }
        }
    }

    int row = 0;
    world = this->world;
    if ((int)world->player_num - 1 <= 0) {
        return;
    }

    save_attrs = 0x72;
    do {
        RGE_Victory_Conditions* conditions =
            this->world->players[row + 1]->victory;
        int condition_index = 0;
        do {
            SP_Victory_Info* condition = &this->sp_victory[row][condition_index];
            int type = condition->VictoryType;
            if (type != 0) {
                if (type == 4) {
                    int attribute = condition->AttribType;
                    if (attribute == 6) {
                        conditions->add_explore(1, condition->Amount, 1);
                    } else if (attribute == 4) {
                        conditions->add_attributes(1, 11, condition->Amount, 0);
                    } else if (attribute == 3) {
                        conditions->add_attributes(1, 0, condition->Amount, 0);
                    } else if (attribute == 2) {
                        conditions->add_attributes(1, 2, condition->Amount, 0);
                    } else if (attribute == 1) {
                        conditions->add_attributes(1, 1, condition->Amount, 0);
                    } else if (attribute == 0) {
                        conditions->add_attributes(1, 3, condition->Amount, 0);
                    } else if (attribute == 5) {
                        conditions->add_attributes(1, 6, condition->Amount, 0);
                    }
                } else if (type == 6) {
                    conditions->add_attributes(1, condition->AttribType,
                                               condition->Amount, 0);
                } else if (type == 5) {
                    conditions->add_capture(1,
                                            this->get_object_pointer(condition->obj_ID), 1);
                } else if (type == 3) {
                    if (this->get_object_pointer(condition->dest_obj_ID) != 0) {
                        conditions->add_bring(
                            1,
                            this->get_object_pointer(condition->obj_ID),
                            this->get_object_pointer(condition->dest_obj_ID));
                    } else {
                        conditions->add_bring(
                            1,
                            this->get_object_pointer(condition->Amount),
                            this->sp_victory[row][condition_index].x1,
                            condition->y1, condition->x2, condition->y2);
                    }
                } else if (type == 2) {
                    if (condition->x2 > DAT_00577330) {
                        conditions->add_create(
                            1, condition->ObjType, condition->Amount,
                            this->sp_victory[row][condition_index].x1,
                            condition->y1, condition->x2, condition->y2, 0);
                    } else {
                        conditions->add_create(1, condition->ObjType,
                                                condition->Amount, 0);
                    }
                } else if (type == 7) {
                    conditions->add_tech(1, condition->AttribType);
                } else if (type == 1) {
                    if (condition->ObjType != 0 && condition->AllFlag != 0) {
                        conditions->add_destroy(1, condition->ObjType,
                                                (RGE_Player*)0);
                    } else if (condition->PlayerID != 0) {
                        if (condition->ObjType != 0) {
                            conditions->add_destroy(
                                1, condition->ObjType, condition->Amount,
                                this->world->players[condition->PlayerID]);
                        } else {
                            conditions->add_destroy(
                                1, this->world->players[condition->PlayerID]);
                        }
                    } else if (this->get_object_pointer(condition->obj_ID) != 0) {
                        conditions->add_destroy(
                            1, this->get_object_pointer(condition->obj_ID));
                    }
                }
            }
            ++condition_index;
        } while (condition_index < 12);

        save_attrs += 12;
        ++row;
        world = this->world;
    } while (row < (int)world->player_num - 1);
}
