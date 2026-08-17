// VA: 004A8A60 TRIBE_Screen_Sed::create_drop_down
// PDB: scr_sed.cpp:594-831
// Baseline: period-plausible typed reconstruction from the exact field/type
// dumps and the original scr_sed.cpp control-flow bands.
// Attempt log:
// 1 baseline: typed field ownership, natural dropdown branches, strcpy, and
//   direct typed helper calls; frame/calls matched, size was 24 bytes short.
// 2 separate height guards were a codegen duplicate; nested negative B4 guard
//   put the late equality tail in the original order.
// 3-4 ordered the 96-height address tests as observed (+73C,+7CC,+894,+740).
// 5 direct set_line(3) arms were diagnostic but changed broad tail structure;
//   rolled back. Assignment-order variant was neutral.
// 6 direct per-arm set_line calls recovered literal pushes/common tail merging;
//   calls stayed 87/87 and structural coverage rose substantially.
// 7 tech enumeration uses separate index and proven 0x3C byte offset; direct
//   global tech-count reload produced the correct register/loop family.
// 8 moving the offset initialization inside the positive count guard improved
//   the tech setup by 21 bytes and left the best current source.
// 9 bitmap-before-AVI source reorder was worse; rolled back.
// 10 binary audit corrected the static-object header (+8 name, +0C string id)
//   and the bitmap directory (the shared empty-string object at 592A40).
// 11 a positive cinematic_input+3 bitmap arm moved the bitmap handler before
//   the victory-object block while retaining the natural first-three AVI test.
// 12 declaring the victory-object loop index before player/count setup moved
//   xor ebp before the world/player loads, resolving the whole structural gap.
// 13-15 canonical Tech_Tree array and address-term/local probes were neutral.
// 16 restored the typed Tech_Tree array source after those equivalent probes.
// 17-19 reversed integer address terms, register-qualified offset, and a
//   per-iteration typed tree local were neutral and were rolled back.
// 20 an 8-case focused address-expression lab collapsed to one invariant
//   one-byte SIB basin; no case produced the original base/index encoding.
// 21 replacing the sparse Tech_Tree gap with the canonical Tech_Entry field
//   ownership from exact TRIBE_Tech donors; test whether the full type surface
//   changes the equivalent tech string_id address encoding (neutral).
// 22 natural address-term and local-lifetime variant lab (12 forms) all kept
//   the same [edi+edx+2A] SIB; short-array scaling changed the loop and was
//   rejected. A second 10-form lifetime lab likewise found no SIB change.
// 23 recompute the byte offset from the post-increment index instead of using
//   the running offset update; test whether VC5 keeps the solved loop while
//   treating the tree pointer as the SIB base (neutral).
// 24 loop-family lab (7 natural indexed/cursor forms) lost the solved frame or
//   remained in the same SIB basin; owner-surface lab (8 forms) was likewise
//   neutral. Index spellings including reversed subscript all normalized to
//   [edi+edx+2A].
// 25 period-plausible long versus int offset type was neutral; restore int.
// 26 normalize the byte cursor as a typed Tech_Entry record pointer so offset
//   is semantically used rather than retained as a codegen-only dead alias.
// 27-32 focused labs covered address term order, local ownership/lifetime,
//   loop-family, owner-chain, and indexed-subscript spellings; every
//   invariant-preserving form stayed in the same one-byte SIB basin.
// 33-34 long-offset and typed-cursor checks were neutral; current source keeps
//   canonical Tech_Entry ownership and the proven byte cursor. Remaining drift
//   is only original [edx+edi+2A] versus rebuilt [edi+edx+2A].
// 35-53 source-gate continuation: replaced the raw 592A40 address with the
// named exact-bank s_592A40 object and replaced generic panel slots with the
// named first six TPanel methods. Twenty focused typed pointer, lvalue,
// declaration-scope, stride, owner-chain, and register probes kept the same
// one-byte SIB basin, except for two rejected structural/helper forms.
// Best current source: exact size/frame/calls/CFG and 2233/2234 bytes equal;
// remaining drift is one localized equivalent SIB byte at tech string_id load
// ([edi+edx+2A] rebuilt vs [edx+edi+2A] original).
// ACCEPTED_DRIFT: independent readiness audit proved these two five-byte MOVSX
// encodings compute the same EDX+EDI+0x2A address with identical live values,
// length, flags, reads, CFG, and all 87 call identities. Twenty-plus focused
// natural probes and 53 lab variants exhausted the stable canonical source basin.

#include <string.h>

class TDrawArea;
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);

    char gap_04[0xD8 - 0x04];
    int error_code;
    char gap_DC[0xF4 - 0xDC];

    void set_z_order(unsigned char mode, short z_order);
    char* get_string(int string_id);
};

class TDropDownPanel : public TPanel {
public:
    int append_line(long string_id, long value);
    int append_line(char* text, long value);
    void empty_list();
    void set_sorted(int sorted);
    void set_line(long line);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];

    virtual int create_drop_down(TPanel* parent, TDropDownPanel** out,
                                 long x, long y, long width, long height,
                                 long list_width, long list_height, long font);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[3];
    char* name;
    short string_id;
    char gap_0E[0x4E - 0x0E];
    unsigned char hide_in_scenario_editor;
};

class RGE_Player {
public:
    char gap_00[0x22];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x104 - 0x44];
};

struct Tech_Entry {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short civilization;
    short full_tech_mode;
    unsigned char button_location;
    char gap_27;
    short button_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    char gap_06[2];
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
};

class RGE_Prog_Info {
public:
    char gap_00[0x102B];
    char ai_dir[0x105];
    char avi_dir[0x105];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string_extended(int, long, char*, int);
    virtual char* get_string(long string_id, char* buffer, int length);

    char gap_04[0x0C - 0x04];
    RGE_Prog_Info* prog_info;
    char gap_10[0x3F4 - 0x10];
    TRIBE_World* world;
};

extern RGE_Base_Game* rge_base_game;

extern char s_592A40[];

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x528 - 0x478];
    TDropDownPanel* default_terrain_drop;
    char gap_52C[0x530 - 0x52C];
    TDropDownPanel* map_size_drop;
    char gap_534[0x538 - 0x534];
    TDropDownPanel* map_style_drop;
    char gap_53C[0x5B4 - 0x53C];
    TDropDownPanel* player_list;
    TDropDownPanel* player_number_list;
    TDropDownPanel* player_advance_civilization_drop;
    char gap_5C0[0x5F8 - 0x5C0];
    TDropDownPanel* player_setting_drop[2];
    TDropDownPanel* BuildList;
    TDropDownPanel* CityLayout;
    TDropDownPanel* AiRules;
    char gap_60C[0x618 - 0x60C];
    TDropDownPanel* unit_player_list;
    char gap_61C[0x700 - 0x61C];
    TDropDownPanel* victory_time;
    char gap_704[0x734 - 0x704];
    TDropDownPanel* victory_drop_down;
    TDropDownPanel* victory_object_list;
    TDropDownPanel* victory_player_list;
    TDropDownPanel* victory_enemy_player_list;
    TDropDownPanel* victory_attribute_list;
    TDropDownPanel* victory_ages_list;
    TDropDownPanel* victory_tech_list;
    char gap_750[0x7B4 - 0x750];
    TDropDownPanel* cinematic_input[4];
    char gap_7C4[0x7CC - 0x7C4];
    TDropDownPanel* options_player_list;
    char gap_7D0[0x894 - 0x7D0];
    TDropDownPanel* Diplomacy_player_list;
    char gap_898[0x928 - 0x898];
    TRIBE_World* world;

    int MakeFileList(TDropDownPanel* panel, char* directory, char* extension,
                     unsigned char add_none, unsigned char add_random);
    int create_drop_down(TPanel* parent, TDropDownPanel** out);
};

int TRIBE_Screen_Sed::create_drop_down(TPanel* parent, TDropDownPanel** out)
{
    long height;

    if (out == &this->victory_object_list ||
        out == &this->victory_attribute_list ||
        out == &this->victory_ages_list ||
        out == &this->victory_tech_list ||
        out == &this->BuildList ||
        out == &this->CityLayout ||
        out == &this->AiRules ||
        out == &this->victory_time) {
        height = 0xDC;
        goto create;
    }
    if (out != &this->victory_drop_down) {
        if (out == this->cinematic_input ||
            out == this->cinematic_input + 1 ||
            out == this->cinematic_input + 2 ||
            out == this->cinematic_input + 3 ||
            out == &this->default_terrain_drop ||
            out == &this->map_size_drop ||
            out == &this->map_style_drop) {
            height = 0xAA;
            goto create;
        }
        if (out == &this->player_advance_civilization_drop ||
            out == &this->player_list ||
            out == &this->player_number_list ||
            out == &this->unit_player_list ||
            out == &this->victory_player_list ||
            out == &this->options_player_list ||
            out == &this->Diplomacy_player_list ||
            out == &this->victory_enemy_player_list) {
            height = 0x96;
            goto create;
        }
        height = 0x82;
    } else {
        height = 0xB4;
    }

create:

    if (this->TEasy_Panel::create_drop_down(parent, out, height, 100, 0, 0,
                                             height, 0x16, 10) == 0) {
        return 0;
    }

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    (*out)->empty_list();

    TDropDownPanel** list;

    list = &this->map_size_drop;
    if (out == list) {
        (*list)->append_line(0x2973, 0);
        (*list)->append_line(0x2974, 0);
        (*list)->append_line(0x2975, 0);
        (*list)->append_line(0x2976, 0);
        (*list)->append_line(0x2977, 0);
        (*list)->append_line(0x2978, 0);
        (*list)->set_line(3);
        goto done;
    } else {
        list = &this->map_style_drop;
        if (out == list) {
            (*list)->append_line(0x296A, 0);
            (*list)->append_line(0x296B, 0);
            (*list)->append_line(0x296C, 0);
            (*list)->append_line(0x296D, 0);
            (*list)->append_line(0x296E, 0);
            (*list)->append_line(0x296F, 0);
            (*list)->append_line(0x2970, 0);
            (*list)->append_line(0x2971, 0);
            (*list)->append_line(0x2972, 0);
            (*list)->set_line(3);
            goto done;
        } else {
            list = &this->player_number_list;
            if (out == list) {
                int i = 0;
                do {
                    (*list)->append_line(i + 0x2877, 0);
                    i++;
                } while (i < 8);
                (*list)->set_line(0);
                goto done;
            } else {
                list = &this->victory_enemy_player_list;
                if (out == list) {
                    int i = 0;
                    do {
                        (*list)->append_line(i + 0x2877, 0);
                        i++;
                    } while (i < 8);
                    (*list)->set_line(0);
                    goto done;
                } else {
                    list = &this->victory_attribute_list;
                    if (out == list) {
                        (*list)->append_line(0x2882, 0x2B);
                        (*list)->append_line(0x2883, 0x29);
                        (*list)->append_line(0x2884, 0x2C);
                        (*list)->append_line(0x2886, 0x28);
                        (*list)->append_line(0x2887, 0x15);
                        (*list)->append_line(0x2888, 0x14);
                        (*list)->append_line(0x2889, 0x25);
                        (*list)->set_line(0);
                        goto done;
                    } else {
                        list = &this->default_terrain_drop;
                        if (out == list) {
                            (*list)->append_line(0x297D, 0);
                            (*list)->append_line(0x297E, 0);
                            (*list)->append_line(0x297F, 0);
                            (*list)->append_line(0x2980, 0);
                            (*list)->append_line(0x2981, 0);
                            (*list)->append_line(0x2982, 0);
                            (*list)->append_line(0x2983, 0);
                            (*list)->append_line(0x2984, 0);
                            (*list)->append_line(0x2985, 0);
                            (*list)->set_line(0);
                            goto done;
                        } else {
                            list = this->player_setting_drop;
                            if (out == list) {
                                (*list)->append_line(0x27E3, 0);
                                (*list)->append_line(0x27E4, 0);
                                (*list)->set_line(0);
                                goto done;
                            } else {
                                list = &this->victory_drop_down;
                                if (out == list) {
                                    (*list)->append_line(0x2851, 0);
                                    (*list)->append_line(0x2852, 0);
                                    (*list)->append_line(0x2853, 0);
                                    (*list)->append_line(0x2854, 0);
                                    (*list)->append_line(0x2855, 0);
                                    (*list)->append_line(0x2856, 0);
                                    (*list)->append_line(0x2857, 0);
                                    (*list)->append_line(0x2858, 0);
                                    (*list)->append_line(0x2859, 0);
                                    (*list)->append_line(0x285A, 0);
                                    (*list)->append_line(0x285B, 0);
                                    (*list)->append_line(0x285C, 0);
                                    (*list)->append_line(0x285D, 0);
                                    (*list)->append_line(0x285E, 0);
                                    (*list)->append_line(0x285F, 0);
                                    (*list)->append_line(0x2860, 0);
                                    (*list)->append_line(0x2861, 0);
                                    (*list)->append_line(0x2862, 0);
                                    (*list)->append_line(0x284F, 0);
                                    (*list)->set_line(0);
                                    goto done;
                                } else {
                                    list = this->player_setting_drop + 1;
                                    if (out == list) {
                                        (*list)->append_line(0x27F7, 0);
                                        (*list)->append_line(0x27F8, 0);
                                        (*list)->append_line(0x27F9, 0);
                                        (*list)->append_line(0x27FA, 0);
                                        (*list)->append_line(0x27FB, 0);
                                        (*list)->append_line(0x27FC, 0);
                                        (*list)->append_line(0x27FD, 0);
                                        (*list)->append_line(0x27FE, 0);
                                        (*list)->append_line(0x27FF, 0);
                                        (*list)->append_line(0x2800, 0);
                                        (*list)->append_line(0x2801, 0);
                                        (*list)->append_line(0x2802, 0);
                                        (*list)->append_line(0x2806, 0);
                                        (*list)->append_line(0x2807, 0);
                                        (*list)->append_line(0x2809, 0);
                                        (*list)->append_line(0x2808, 0);
                                        (*list)->set_line(0);
                                        goto done;
                                    } else {
                                        list = &this->victory_ages_list;
                                        if (out == list) {
                                            (*list)->append_line(0x1069, 0);
                                            (*list)->append_line(0x106A, 0);
                                            (*list)->append_line(0x106B, 0);
                                            (*list)->append_line(0x106C, 0);
                                            (*list)->set_line(0);
                                            goto done;
                                        } else {
                                            list = &this->victory_tech_list;
                                            if (out == list) {
                                                this->victory_tech_list->set_sorted(1);
                                                int i = 0;
                                                if (rge_base_game->world->tech->tech_tree_num > 0) {
                                                    int offset = 0;
                                                    do {
                                                        Tech_Entry* tree = rge_base_game->world->tech->tech_tree;
                                                        Tech_Entry* entry = (Tech_Entry*)((char*)tree + offset);
                                                        char* text = this->get_string(
                                                            entry->string_id);
                                                        if (text != 0 && *text != 0) {
                                                            (*list)->append_line(text, i);
                                                        }
                                                        i++;
                                                        offset += 0x3C;
                                                    } while (i < rge_base_game->world->tech->tech_tree_num);
                                                }
                                                (*list)->set_line(0);
                                                goto done;
                                            } else {
                                                if (out == &this->AiRules) {
                                                    this->MakeFileList(this->AiRules,
                                                        rge_base_game->prog_info->ai_dir,
                                                        (char*)".per", 0, 1);
                                                    (*out)->set_line(0);
                                                    goto done;
                                                } else {
                                                    list = &this->BuildList;
                                                    if (out == list) {
                                                        this->MakeFileList(*list,
                                                            rge_base_game->prog_info->ai_dir,
                                                            (char*)".ai", 1, 1);
                                                        (*out)->set_line(0);
                                                        goto done;
                                                    } else {
                                                        list = &this->CityLayout;
                                                        if (out == list) {
                                                            this->MakeFileList(*list,
                                                                rge_base_game->prog_info->ai_dir,
                                                                (char*)".cty", 1, 0);
                                                            (*out)->set_line(0);
                                                            goto done;
                                                        } else {
                                                            if (out == this->cinematic_input ||
                                                                out == this->cinematic_input + 1 ||
                                                                out == this->cinematic_input + 2) {
                                                                this->MakeFileList(*out,
                                                                    rge_base_game->prog_info->avi_dir,
                                                                    (char*)".avi", 1, 0);
                                                                (*out)->set_line(0);
                                                                goto done;
                                                            } else {
                                                                if (out == this->cinematic_input + 3) {
                                                                    this->MakeFileList(*out,
                                                                        s_592A40,
                                                                        (char*)".bmp", 1, 0);
                                                                    (*out)->set_line(0);
                                                                    goto done;
                                                                } else {
                                                                    list = &this->victory_object_list;
                                                                    if (out != list) {
                                                                        goto done;
                                                                    }

                                                                    this->victory_object_list->set_sorted(1);
                                                                    this->victory_object_list->empty_list();

                                                                    int i = 0;
                                                                    RGE_Player* player = this->world->players[1];
                                                                    int count = player->master_object_num;
                                                                    if (count > 0) {
                                                                        char str[256];
                                                                        do {
                                                                            RGE_Master_Static_Object* object = player->master_objects[i];
                                                                            if (object != 0 && object->hide_in_scenario_editor == 0) {
                                                                                if (object->string_id > 0) {
                                                                                    rge_base_game->get_string(object->string_id, str, 0x100);
                                                                                } else {
                                                                                    strcpy(str, object->name);
                                                                                }
                                                                                this->victory_object_list->append_line(str, i);
                                                                            }
                                                                            i++;
                                                                        } while (i < count);
                                                                    }
                                                                    this->victory_object_list->set_line(0);
                                                                    goto done;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

done:
    return this->error_code == 0;
}
