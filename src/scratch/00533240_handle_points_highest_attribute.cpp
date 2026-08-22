// RGE_Victory_Conditions::handle_points_highest_attribute
// VA: 00533240
// victory.cpp
// Attempt log:
// - Baseline: reconstructed from scratch (previous scratch source was a decompiler-shaped
//   wrong reconstruction: reversed threshold direction, invented max-scan loop, invented
//   trailing ftol). Modeled on exact sibling handle_points_attribute_first (00533180):
//   same RGE_Player/RGE_Game_World/RGE_Victory_Point_Entry/RGE_Victory_Conditions surface.
// - Binary semantics: val = ftol(player->attributes[entry->attribute]); curr_amount =
//   (float)val; best starts at entry->points; if val < entry->amount then best = 0
//   else scan players[1..num-1]: if any other player's attribute > curr_amount -> best = 0
//   (break), if == curr_amount -> best = entry->curr_points; finally if best != curr_points
//   award delta to tot_victory_points and store best.
// - Probe 3 changed the indexed for-loop to a guarded do/while with direct repeated attribute
//   reads; size gap fell from 36 to 18 bytes and the FPU compare family moved closer.
// - Probe 4 restored the binary `other > curr_amount` operand order and branch-local id; shape
//   improved to 63.22% with the expected fcomp/test-ah-41 sequence.
// - Probe 5 named the proven attribute offset and world owner; best emitted reconstruction was
//   197 differing bytes, 69.14% shape, but frame stayed 0xC versus the original 0x10.
// - Probes 6-12 tested same-TU aliases, register hints, a split cursor, short id width, a self
//   alias, and a points-field pointer. They were duplicate, neutral, or worse; no ABI/call/CFG
//   defect was found. Left in scratch: structural/register allocation gap (original spills this,
//   curr_amount, id, and count; best rebuild spills only this/attribute-related temporaries).
// - Main-agent audit restored polymorphic player/world/victory ownership;
//   emitted code is unchanged.
// - Constructor/TU context probe: the recovered four-slot victory surface,
//   polymorphic world/player surfaces, and named point-entry id/group fields
//   are canonical but emitted the same structural candidate. The remaining
//   blocker is the original four-dword local window versus the natural 0xC frame.
// - Fresh pass: an entry alias/int-width spelling was codegen-neutral. A four-dword
//   aggregate with direct attribute expressions improved to diff 141 but added an
//   implausible 0x18 frame; scalar top-level count/current locals improved to
//   diff 139 (75.61% shape, 0xC frame, 22.22% blocks). A self alias was
//   codegen-neutral and was removed during main-agent source audit.
// - A preheader cursor plus tail increment regressed to diff 178; decompiler-style
//   top-level declarations regressed to the prior diff 197 basin. Declaration versus
//   assignment initialization of self was neutral. Remaining gap is the original
//   four-dword local/register allocation window; calls and CFG are aligned.
// - Fresh worker pass: exact-sibling player/entry aliases regressed to diff 216 and were
//   restored. A narrow volatile id local is binary-supported by the observed stack reload;
//   it forced the 0x10 frame and improved diagnostic diff to 132 with 87.65% shape, but
//   changed the early register colors and made the function one byte too long. Named player,
//   named attribute, self-alias, address-taken nonvolatile id, and while/preheader variants
//   were neutral, duplicate, or worse (diff 139-219). Restored the clean scalar candidate.
// - Pause lead: the remaining blocker is source/register allocation for the original id and
//   current stack homes. Calls, relocation identity, and CFG counts are aligned.
// - Follow-up worker: direct repeated player-id access and direct player->world access,
//   both matching exact victory.cpp sibling idioms, were codegen-neutral. A preheader plus
//   tail pointer increment and a for-loop increment clause regressed structural parity
//   (diff 191/190); an isolated player local reproduced the prior diff-216 basin. Restored
//   the clean scalar candidate. No new natural structural lead remains in these axes.
// - tu-victory-533240 probe: kept a typed player owner only after the point-entry update, so the
//   same owner feeds world and id in the sibling-backed loop. VC5 emitted the unchanged 221-byte,
//   139-byte-diff group; the original 0x10 local window and four stack homes remain unresolved.
// - Short player-id local, threshold-fail no-op, scoped player-count declaration, and split
//   best declaration probes were tested. The short and no-op forms regressed structure;
//   the scoped-count and split-best forms were codegen duplicates. Restored the clean scalar
//   source; the original four-slot local window remains the blocker.
// - Shard E follow-up: period-plausible long locals were codegen-neutral; delayed best
//   assignment regressed diff 153. Nested non-greater control flow, function-scope loop/value
//   declarations, and an inner current initializer were duplicate or neutral. Restored the
//   validated natural scalar source. No new structural lead; the original id spill and frame
//   remain unresolved.
// - Reassessment: direct player/world ownership, a distinct points local, exact-sibling
//   non-polymorphic player/world declarations, and function-scope owner declarations were
//   duplicate codegen. A bottom-increment cursor reproduced the older diff-191 basin.
//   The original parameter-home best, four-slot frame, and spilled id remain unresolved.
// - Canonical-structure follow-up: direct this->player->world/id ownership was codegen-neutral;
//   reversing the equivalent loop condition changed only branch bytes. Initializing the cursor
//   as world->players + 1, and split base/cursor locals, regressed to 175/178-byte differences;
//   a persistent dual cursor reproduced the prior 191-byte basin. Restored the clean scalar
//   do/while source. Target pointer base/cursor colors and spilled id remain open.
// - Revisit pass: natural while, preheader-plus-do/while, single-cursor, and dual-cursor
//   update forms reproduced the known 191/178-byte basins. A short id widened the drift to
//   181 bytes. A 32-variant natural declaration/order lab produced only the existing 221-byte
//   groups; no variant had the target 0x10 frame or 230-byte size. Restored the clean scalar
//   source. The unresolved evidence remains the target's separate player-array base/cursor
//   registers and spilled player id.
// - Revisit pass 2: completed 20 additional natural probes across typed aliases, declaration
//   scopes, pointer ownership, cursor initialization, and loop forms. Entry aliases, points
//   field pointers, long widths, pointer TU surfaces, and positive guards were neutral or worse.
//   A top-tested while loop improved diagnostic shape to 78.05% but kept the 139-byte diff.
//   A preheader single-cursor form reached the target 0x10 frame but changed this to EBX and
//   widened structural drift to 163 bytes. A typed diagnostic that reused entry as an integer
//   accumulator widened drift to 189 bytes and is not retained. Restored the pinned natural
//   scalar source; the target's parameter-home val reuse, spilled id, and base/cursor colors
//   remain unresolved.
// - TU-only audit: 20 further probes kept the clean 221-byte / 0xC-frame source. A 4096-variant
//   period-standard-header sweep, plus Windows headers, ambient declarations, the repository
//   type/global headers, canonical list and class surfaces, full victory method declarations,
//   point-dispatch context, neighboring point-handler order, declaration order, protected
//   access, period typedefs, PDB `node` naming, and supported VC5 flag families were neutral or
//   worse. Default `/O2 /Oy` remains the only supported flag basin. The original four-slot local
//   window is not caused by recoverable TU context in this source model.
// - Object audit: FPO confirms a real 0x10 local frame, not hidden ABI, SEH, inline code, or a
//   boundary error. The extra word holds a spilled player id. The oracle also reuses the node
//   parameter home for the converted value and result. PDB local records are incomplete, but
//   no natural source form recovered those choices. The volatile frame diagnostic stays rejected.
// - Source-gate audit: replaced narrow class gaps and incomplete world slots with the named
//   donor-header fields and virtual methods. Restored `amount` and `next` on the point entry,
//   and typed the victory-list pointers. The rebuilt bytes stayed at the clean 221-byte,
//   139-byte-diff baseline, so this ownership cleanup does not explain the codegen gap.
// - Natural frame/home follow-up: tested 21 evidence-led source forms after the ownership
//   cleanup. Long `points`/`amount` locals, declaration scopes and orders, direct owner reads,
//   typed indexed and cursor scans, loop forms, and assignment order were neutral or worse.
//   The natural scalar source remains the clean candidate. No volatile, gap, fake aggregate,
//   address alias, or forced parameter-home form was retained. Final validation is 221 bytes,
//   139-byte diff, 0xC frame versus the original 230 bytes and 0x10 frame.
// - Independent PDB audit: DIA lists only this, node, points, and amount for this function.
//   points and amount both use VFRAME +8, which is the incoming node home at function entry.
//   DIA reports no live ranges, hidden locals, or inline frames. The complete point-entry UDT
//   is 0x1C bytes with amount, points, curr_points, curr_attribute_amount, and next at +8,+C,
//   +10,+14,+18. The sibling 00533180 has points at VFRAME -4 and amount at +8; sibling
//   00533330 has amount at +8. These donors support the scalar fields and parameter-home reuse,
//   but they do not support a new alias or forced home in this target.
// - Independent follow-up: 20 natural probes tested PDB-named widths, implicit conversions,
//   declaration order and scope, guard polarity, threshold operand order, owner expressions,
//   loop-local pointer ownership, and current-member storage. All forms were neutral or worse.
//   Restored the pinned scalar source. Final clean metrics remain 221 bytes, 139-byte diff,
//   0xC frame versus the original 230 bytes and 0x10 frame.
// - Accepted-drift audit: do not promote this candidate. The original has a
//   0x10 frame, while the rebuild has a 0x0C frame at the ftol call. Thus the
//   helper receives a different stack and exception context. The x87 compare
//   predicates and point effects otherwise align, but that observable call
//   context keeps this function in scratch.
// - sa-5b56772e-r1 extended pass: a 96-variant structural lab covered declaration
//   order, store timing, count scope, id scope, and natural/indexed/preincrement
//   scans. It produced four groups: the clean 221-byte/139-diff group, 208-byte
//   loop regressions at 178/191 diff, and no size/frame/call-set eligible variant.
//   A 144-variant id-home lab added normal, volatile, and address-alias ids. It
//   produced no eligible variant; volatile id gave 231 bytes, 90.12% shape, 63%
//   exact blocks, and 130-byte diff when current was initialized before best.
//   This remains diagnostic scaffolding and is rejected by source policy.
// - Further donor-led probes mirrored exact victory.cpp current-player cursor
//   ownership, direct players+1 initialization, const base/cursor types, long
//   amount/result locals, member-current rereads, and function-scope id storage.
//   These stayed neutral or returned the 178-byte loop basin. The original
//   protected IA decorated member access was restored from the target symbol;
//   it does not change body bytes but makes owner identity exact. The natural
//   clean body remains 221 bytes, 139-byte diff, 0xC versus 0x10 frame.
// - Final donor sweep tested the handle_explore explicit walker with while,
//   direct players+1 with do/while, register-qualified players, and a const
//   id reference. The walker and direct cursor forms returned the 178-byte
//   basin; register and reference forms duplicated the 139-byte group. No
//   natural form improved the frame, first divergence, or exact-block result.

class RGE_Game_World;
class RGE_Victory_Entry;
class RGE_Victory_Conditions;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Master_Player;
class RGE_Sprite;
class RGE_Sound;
class RGE_Map;
class RGE_Effects;
class RGE_Command;
class RGE_Scenario;
class RGE_Player_Info;
class TSound_Driver;
class TCommunications_Handler;
class RGE_Object_Node;
class XYZBYTEPoint;
struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                                float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                   unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char pad_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char pad_49;
    short id;
    short attribute_num;
    unsigned char pad_4E[2];
    float* attributes;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char pad_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    unsigned char pad_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    unsigned char pad_36[2];
    RGE_Sprite** sprites;
    short player_num;
    unsigned char pad_3E[2];
    RGE_Player** players;
};

class RGE_Victory_Point_Entry {
public:
    unsigned char command; unsigned char state; unsigned char id; unsigned char group;
    long attribute; long amount; long points; long curr_points;
    float curr_attribute_amount;
    RGE_Victory_Point_Entry* next;
};
class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);
    RGE_Victory_Entry* victory_list;
    long list_num;
    RGE_Player* player;
    unsigned char victory;
    unsigned char pad_11[3];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num; long tot_victory_points;
protected:
    void handle_points_highest_attribute(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* entry) {
    int num;
    float current;
    if (entry->state == 0) {
        int val = (int)this->player->attributes[entry->attribute];
        int best = entry->points;
        current = (float)val;
        entry->curr_attribute_amount = current;
        RGE_Player* player = this->player;
        RGE_Game_World* world = player->world;
        RGE_Player** players = world->players;
        if (val < entry->amount) {
            best = 0;
        } else {
            num = world->player_num;
            int i = 1;
            if (1 < num) {
                int my_id = player->id;
                do {
                    ++players;
                    if (i != my_id) {
                        if ((*players)->attributes[entry->attribute] > current) {
                            best = 0;
                            break;
                        }
                        if ((*players)->attributes[entry->attribute] == current) {
                            best = entry->curr_points;
                        }
                    }
                    ++i;
                } while (i < num);
            }
        }
        if (best != entry->curr_points) {
            this->tot_victory_points += best - entry->curr_points;
            entry->curr_points = best;
        }
    }
}
