// VA: 0046F050 RGE_Player::sendPlayCommand(int,int,int)
// Baseline reconstruction: send the command through the player's AI playbook,
// then serialize the selected object ids for the selected-unit command.
// Attempt log:
// - Natural typed reconstruction reached the correct 0x64 frame, 5 calls, and 237-byte boundary.
// - Corrected the playbook lookup from param_2 to param_3; this reduced the strict diff to 7 bytes.
// - Tried loop/declaration/register/layout/context variants; all retained the same 7-byte register-coloring drift.
// - Remaining drift is vtable register EBP versus EBX and loop counter EBX versus EBP; no opaque codegen scaffold retained.
// - Tried a natural indexed selected-list loop; VC5 canonicalized it to the same 7-byte output.
// - Corrected the proven unsigned-char return widths of the v_c4/v_d0 command slots; caller output stayed unchanged.
// Fresh bounded pass:
// - Restored the donor-backed RGE_Player virtual ABI and canonical 0x220 layout; emitted code stayed unchanged.
// - Header-context (6), declaration-order (4), and loop-form (4) labs each collapsed to the same 237-byte/7-byte group.
// - Hoisted AIPlay/object declarations, used a receiver alias, and hinted the selected-list cursor; all stayed unchanged.
// - Early loop-counter initialization stayed unchanged; function-scope selectedCount initialization worsened to 241 bytes and was restored.
// - Final clean candidate remains the natural typed reconstruction; unresolved drift is the isolated EBP/EBX coloring swap at 7 bytes.
// Shutdown follow-up (wave21-player-01):
// - Exact-donor void/nonvirtual surface probe was unchanged and restored.
// - Scoped selected locals and counter-first/top-level initialization probes were unchanged and restored.
// - Final source remains the pinned canonical typed reconstruction; drift is still the isolated EBP/EBX coloring swap.
// Managed bounded pass (sa3834ca36_r1):
// - register-qualified counter, scalar/array declaration order, and loop-init ordering all emitted the same 7-byte drift.
// - A focused width lab over the 25-count and selected-count locals produced one 237-byte/7-byte group; narrow count variants lost invariants.
// - Reordering selected-id store versus selected-count increment was unchanged.
// - Proven polymorphic RGE_Game_World and AIPlayBook donor surfaces, plus a partial first-call receiver alias, were unchanged.
// - Restored this clean natural typed source; no compiler-steering variant is retained. Remaining drift is still EBP vtable versus EBX loop counter.
// Bounded pass (orch-0046F050-D):
// - Diff is exactly 7 single-byte register-byte differences: EBP vtable cache vs EBX 25-loop counter swapped
//   (mov ebp,[esi]/call [ebp+..]/mov ebx,19h/dec ebx positions); every other byte, call, frame, and CFG equal.
// - Exact sibling donor 0046F140 (5-arg sendPlayCommand, matching) caches the vtable in EDI; shared
//   send_signal 12-arg virtual surface confirmed at slot 0x30. Real RGE_Player surface: 0x30=sendUnitAIOrder,
//   0xC4=command_create_group(int,int*,int,float), 0xD0=command_destroy_group(int); this 3-arg overload is at
//   vtable slot 0x50 (5-arg at 0x4C). Local stub slot offsets already align.
// - Remaining untried leads: (1) full real 84-slot vtable surface with sendPlayCommand at 0x50 (00435020 lesson:
//   full class surface can alter VC5 coloring); (2) indexed sel_list[i] loop so the countdown counter becomes
//   strength-reduced IR rather than a source local; (3) top-level n + do/while(--n) with nonvirtual definition,
//   mirroring the 0046F010/0046F140 donor shapes that put vtable-derived pointers in EBP and counters in EBX.
// Focused ABI pass (orch2-46F050-abi):
// - Replaced the dummy prefix with the inventory RGE_Player order through the real +0x50 overload,
//   including float sendUnitAIOrder parameters and the real group-command declarations.
// - The focused ABI surface compiled to the same 237-byte function and 7-byte register-coloring drift;
//   retained the real declarations because they are the canonical class evidence.
// Focused ABI/expression pass (close-46F050-r1):
// - Added the exact-donor command tail after +0xD0; no emitted movement, then restored.
// - Retested an indexed selected-list loop and a top-level do/while counter with the real ABI; both
//   stayed at the same 7-byte group, as did a typed player-reference alias.
// - Void group-command return declarations, a register-qualified first argument, and natural id
//   promotion were neutral. Direct selectedUnits[selectedCount] storage worsened to 16 bytes.
// - Clean source remains the natural typed reconstruction. The only drift is the proven EBP vtable /
//   EBX 25-count register swap at seven bytes.

class AIPlay;
class AIPlayBook { public: AIPlay* play(int id); };
class RGE_Game_World { public: char gap_00[0xA0]; AIPlayBook* playbook; };
struct XYZBYTEPoint;

class RGE_Static_Object {
public:
    virtual void vf00();
    int id;
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);
    virtual void loadAIInformation(char* a, char* b, char* c, int d, int e);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e,
                                 float f, float g, float h, float i,
                                 int j, int k, int l);
    virtual void processAIOrder(int a, int b, int c, int d, int e,
                                float f, float g, float h, float i,
                                int j, int k, int l);
    virtual void kickAI(int reason);
    virtual int strategicNumber(int number);
    virtual void sendGameOrder(RGE_Static_Object* object, RGE_Static_Object* target,
                               float x, float y);
    virtual void sendAddWaypointCommand(int count, XYZBYTEPoint* points, int flags);
    virtual void processAddWaypointCommand(int count, XYZBYTEPoint* points, int flags);
    virtual void sendPlayCommand(int a, int* b, int c, int d, int e);
    virtual void sendPlayCommand(int a, int b, int c);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int type);
    virtual void trackUnitGather(int a, int b, int c);
    virtual RGE_Static_Object* make_scenario_obj(float x, float y, float z, short id,
                                                 unsigned char type, float rotation);
    virtual void scenario_save(int file_handle);
    virtual void scenario_load(int file_handle, long* data, float version);
    virtual void scenario_postsave(int file_handle);
    virtual void scenario_postload(int file_handle, long* data, float version);
    virtual void load(int file_handle);
    virtual void add_attribute_num(short attribute, float amount, unsigned char flag);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file_handle);
    virtual void save2(int file_handle);
    virtual void save_info(int file_handle);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long type, float x, float y, float z, int id);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int a, int* b, int* c);
    virtual unsigned char command_make_move(RGE_Static_Object* object, float x, float y);
    virtual unsigned char command_make_work(RGE_Static_Object* object, float x, float y);
    virtual unsigned char command_make_do(RGE_Static_Object* object, float x, float y);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short type, float x, float y, float z);
    virtual unsigned char command_add_attribute(int attribute, float amount);
    virtual unsigned char command_give_attribute(int player, int attribute, float amount);
    virtual unsigned char command_formation(int formation);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int a, int* p, int count, float flag);
    virtual unsigned char command_add_to_group(int a, int b, float flag);
    virtual unsigned char command_remove_from_group(int a, int b);
    virtual unsigned char command_destroy_group(int a);

    char gap_04[0x38];
    RGE_Game_World* world;      // +0x3C
    char gap_40[0x0A];
    short id;                   // +0x4A
    char gap_4C[0xE8];
    RGE_Static_Object* sel_list[25]; // +0x134

};

void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3)
{
    int selectedUnits[25];
    int selectedCount;
    int* selectedUnit;
    RGE_Static_Object** source;

    this->command_destroy_group(param_1);
    AIPlay* play = this->world->playbook->play(param_3);
    if (play == 0) {
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d7, -1, -1,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }

    selectedCount = 0;
    selectedUnit = selectedUnits;
    source = this->sel_list;
    for (int n = 25; n != 0; ++source, --n) {
        RGE_Static_Object* object = *source;
        if (object != 0) {
            ++selectedCount;
            *selectedUnit = object->id;
            ++selectedUnit;
        }
    }

    if (selectedCount != 0) {
        this->command_create_group(param_1, selectedUnits, selectedCount, 2.0f);
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d6, param_2, param_3,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
    }
}
