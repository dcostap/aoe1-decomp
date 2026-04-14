"""Wave 9 batch generator: 6 clusters, ~170 functions."""
import csv, os

REPO = r'C:\Projects\my_decomps\aoe1_attempt3'
SCRATCH = os.path.join(REPO, 'src', 'scratch')
FLAGS = os.path.join(REPO, 'config', 'flags')

# Read CSV
va_map = {}
with open(os.path.join(REPO, 'project_full_status.csv')) as f:
    for r in csv.DictReader(f):
        va_map[r['va'].strip().lower()] = r['name'].strip()

count = 0
errs = []

def gen(va, src):
    global count
    va = va.lower()
    nm = va_map.get(va)
    if not nm:
        errs.append(va)
        return
    fn = va + '_' + nm
    cp = os.path.join(SCRATCH, fn + '.cpp')
    rp = os.path.join(FLAGS, fn + '.rsp')
    if os.path.exists(cp):
        return
    with open(cp, 'w', newline='\n') as f:
        f.write(src)
    with open(rp, 'w', newline='\n') as f:
        f.write('/nologo /c /O2\n')
    count += 1

def make_src(deps, cls_name, fields, decl, impl):
    """Build a .cpp source string."""
    d = (deps + '\n\n') if deps else ''
    return d + 'class ' + cls_name + ' {\npublic:\n' + fields + '\n\n    ' + decl + '\n};\n\n' + impl + '\n'

# ============================================================
# UnitAIModule (aiuaimod.cpp) - 35 functions
# ============================================================
UAI_DEPS = """\
struct UnitAIObjectRef {
    char pad_00[4];
    int id_;
    char pad_08[4];
    int owner_;
};"""

UAI_FIELDS = """\
    virtual ~UnitAIModule();
    UnitAIObjectRef* object_;
    int mood_;
    int objectCategory_;
    int orderQueueSize_;
    char gap_14[0x14];
    int currentOrder_;
    int currentOrderPriority_;
    int currentAction_;
    int currentTarget_;
    int currentTargetType_;
    float currentTargetX_;
    float currentTargetY_;
    float currentTargetZ_;
    float desiredTargetDistance_;
    char gap_4C[4];
    int lastOrder_;
    int lastAction_;
    int lastTarget_;
    int lastTargetType_;
    char gap_60[4];
    int numberAttackingUnits_;
    char gap_68[0x88];
    int waypointQueueSize_;
    unsigned long lastUpdateTime_;
    unsigned long idleTimer_;
    char gap_FC[4];
    unsigned long idleTimeout_;
    unsigned long secondaryTimer_;
    char gap_108[0x18];
    float defenseBuffer_;"""

def uai(va, decl, impl):
    gen(va, make_src(UAI_DEPS, 'UnitAIModule', UAI_FIELDS, decl, impl))

# Int getters (4B, small offset)
for v, n, fld in [
    ('00413850','mood','mood_'), ('00413840','objectCategory','objectCategory_'),
    ('004138d0','orderQueueSize','orderQueueSize_'), ('00413920','currentOrder','currentOrder_'),
    ('00413940','currentOrderPriority','currentOrderPriority_'), ('00413960','currentAction','currentAction_'),
    ('00413980','currentTarget','currentTarget_'), ('00413990','currentTargetType','currentTargetType_'),
    ('004139d0','lastAction','lastAction_'), ('004139e0','lastOrder','lastOrder_'),
    ('004139f0','lastTarget','lastTarget_'), ('00413a00','lastTargetType','lastTargetType_'),
    ('00413aa0','numberAttackingUnits','numberAttackingUnits_'),
]:
    uai(v, 'int %s();'%n, 'int UnitAIModule::%s() {\n    return this->%s;\n}'%(n,fld))

# Float getters (4B, small offset)
for v, n, fld in [
    ('004139a0','currentTargetX','currentTargetX_'), ('004139b0','currentTargetY','currentTargetY_'),
    ('004139c0','currentTargetZ','currentTargetZ_'), ('00413a10','desiredTargetDistance','desiredTargetDistance_'),
]:
    uai(v, 'float %s();'%n, 'float UnitAIModule::%s() {\n    return this->%s;\n}'%(n,fld))

# Pointer getter
uai('00413820', 'UnitAIObjectRef* object();',
    'UnitAIObjectRef* UnitAIModule::object() {\n    return this->object_;\n}')

# Large offset getters (7B)
uai('004161e0', 'int waypointQueueSize();',
    'int UnitAIModule::waypointQueueSize() {\n    return this->waypointQueueSize_;\n}')
for v, n, fld in [
    ('00413860','lastUpdateTime','lastUpdateTime_'), ('00413870','idleTimer','idleTimer_'),
    ('00413880','idleTimeout','idleTimeout_'), ('00413890','secondaryTimer','secondaryTimer_'),
]:
    uai(v, 'unsigned long %s();'%n, 'unsigned long UnitAIModule::%s() {\n    return this->%s;\n}'%(n,fld))

# Float getter large offset
uai('004138a0', 'float defenseBuffer();',
    'float UnitAIModule::defenseBuffer() {\n    return this->defenseBuffer_;\n}')

# Double dereference (7B)
uai('00413810', 'int owner();',
    'int UnitAIModule::owner() {\n    return this->object_->owner_;\n}')
uai('00413830', 'int objectID();',
    'int UnitAIModule::objectID() {\n    return this->object_->id_;\n}')

# Setters
uai('00413950', 'void setCurrentOrderPriority(int v);',
    'void UnitAIModule::setCurrentOrderPriority(int v) {\n    this->currentOrderPriority_ = v;\n}')
uai('004138c0', 'void setDefenseBuffer(float v);',
    'void UnitAIModule::setDefenseBuffer(float v) {\n    this->defenseBuffer_ = v;\n}')

# Write-zero (purge/clear)
uai('00413910', 'void purgeOrderQueue();',
    'void UnitAIModule::purgeOrderQueue() {\n    this->orderQueueSize_ = 0;\n}')
uai('00416290', 'void clearWaypointQueue();',
    'void UnitAIModule::clearWaypointQueue() {\n    this->waypointQueueSize_ = 0;\n}')

# Return constants
uai('00415150', 'int retryableOrder(int);',
    'int UnitAIModule::retryableOrder(int) {\n    return 0;\n}')
uai('004161d0', 'int waypoint(int);',
    'int UnitAIModule::waypoint(int) {\n    return 0;\n}')
uai('004162a0', 'int canAttackUnit(int);',
    'int UnitAIModule::canAttackUnit(int) {\n    return 1;\n}')
uai('004162b0', 'int canAttackUnitAtNeutrality(int);',
    'int UnitAIModule::canAttackUnitAtNeutrality(int) {\n    return 1;\n}')
uai('004177c0', 'int convertToLOSResourceType(int);',
    'int UnitAIModule::convertToLOSResourceType(int) {\n    return -1;\n}')

# ============================================================
# TPanelSystem (Panel.cpp) - 12 functions
# ============================================================
TPS_FIELDS = """\
    int mouseOwner_;
    int keyboardOwner_;
    int modalPanel_;
    int currentPanel_;
    char gap_10[4];
    int numberActivePanels_;
    char gap_18[0xAA8];
    int ImeEnabled_;
    int ImeOn_;
    int InputEnabled_;"""

def tps(va, decl, impl):
    gen(va, make_src('', 'TPanelSystem', TPS_FIELDS, decl, impl))

# Getters (3B offset-0, 4B small offset, 7B large offset)
tps('00463d20', 'int mouseOwner();',
    'int TPanelSystem::mouseOwner() {\n    return this->mouseOwner_;\n}')
for v, n, fld in [
    ('00463d30','keyboardOwner','keyboardOwner_'), ('00463d40','modalPanel','modalPanel_'),
    ('00463d00','currentPanel','currentPanel_'), ('00463d70','numberActivePanels','numberActivePanels_'),
]:
    tps(v, 'int %s();'%n, 'int TPanelSystem::%s() {\n    return this->%s;\n}'%(n,fld))

for v, n, fld in [
    ('00464540','IsIMEEnabled','ImeEnabled_'), ('004645d0','IsIMEOn','ImeOn_'),
    ('004645e0','GetInputEnabled','InputEnabled_'),
]:
    tps(v, 'int %s();'%n, 'int TPanelSystem::%s() {\n    return this->%s;\n}'%(n,fld))

# Setters
tps('00463f40', 'void setMouseOwner(int v);',
    'void TPanelSystem::setMouseOwner(int v) {\n    this->mouseOwner_ = v;\n}')
tps('00463f50', 'void setKeyboardOwner(int v);',
    'void TPanelSystem::setKeyboardOwner(int v) {\n    this->keyboardOwner_ = v;\n}')

# Write-immediate
tps('004645f0', 'void EnableInput();',
    'void TPanelSystem::EnableInput() {\n    this->InputEnabled_ = 1;\n}')
tps('00464600', 'void DisableInput();',
    'void TPanelSystem::DisableInput() {\n    this->InputEnabled_ = 0;\n}')

# ============================================================
# TPanel (Panel.cpp) - 17 functions
# ============================================================
TP_FIELDS = """\
    virtual ~TPanel();
    int previousPanel_;
    int previousModalPanel_;
    int pnl_x_;
    int pnl_y_;
    int pnl_wid_;
    int pnl_hgt_;
    int panelName_;
    int render_area_;
    char gap_24[0x54];
    int have_focus_;
    char gap_7C[0x68];
    int help_string_id_;
    int help_page_id_;"""

def tp(va, decl, impl):
    gen(va, make_src('', 'TPanel', TP_FIELDS, decl, impl))

for v, n, fld in [
    ('00466420','get_focus','have_focus_'), ('00466670','previousPanel','previousPanel_'),
    ('00466690','previousModalPanel','previousModalPanel_'), ('004666b0','panelName','panelName_'),
    ('00466770','xPosition','pnl_x_'), ('00466780','yPosition','pnl_y_'),
    ('00466790','width','pnl_wid_'), ('004667a0','height','pnl_hgt_'),
    ('004667b0','renderArea','render_area_'),
]:
    tp(v, 'int %s();'%n, 'int TPanel::%s() {\n    return this->%s;\n}'%(n,fld))

# Large offset getters
for v, n, fld in [
    ('00466890','get_help_message','help_string_id_'), ('004668a0','get_help_page','help_page_id_'),
]:
    tp(v, 'int %s();'%n, 'int TPanel::%s() {\n    return this->%s;\n}'%(n,fld))

# Setters
tp('00466680', 'void setPreviousPanel(int v);',
    'void TPanel::setPreviousPanel(int v) {\n    this->previousPanel_ = v;\n}')
tp('004666a0', 'void setPreviousModalPanel(int v);',
    'void TPanel::setPreviousModalPanel(int v) {\n    this->previousModalPanel_ = v;\n}')

# Virtual stubs (5B return 0, ret 8 = 2 params)
for v, n in [
    ('00465c30','handle_command'), ('00465c40','handle_user_command'),
    ('00465c50','handle_timer_command'), ('00465c60','handle_scroll'),
]:
    tp(v, 'int %s(int, int);'%n, 'int TPanel::%s(int, int) {\n    return 0;\n}'%n)

# ============================================================
# RGE_Player (player.cpp) - 18 functions
# ============================================================
RGP_FIELDS = """\
    virtual ~RGE_Player();
    int computerPlayer_;
    int pathingAttemptCap_;
    int pathingDelayCap_;
    int currentUpdatePathingAttempts_;
    char gap_14[0x6D];
    unsigned char resigned_;
    char gap_82[0x82];
    unsigned char allied_victory_;"""

def rgp(va, decl, impl):
    gen(va, make_src('', 'RGE_Player', RGP_FIELDS, decl, impl))

# Int getters (4B)
for v, n, fld in [
    ('0046edb0','computerPlayer','computerPlayer_'), ('0046f200','pathingAttemptCap','pathingAttemptCap_'),
    ('0046f220','pathingDelayCap','pathingDelayCap_'),
    ('0046f240','currentUpdatePathingAttempts','currentUpdatePathingAttempts_'),
]:
    rgp(v, 'int %s();'%n, 'int RGE_Player::%s() {\n    return this->%s;\n}'%(n,fld))

# Uchar getters (7B)
rgp('0046ed90', 'unsigned char get_resigned();',
    'unsigned char RGE_Player::get_resigned() {\n    return this->resigned_;\n}')
rgp('00470bc0', 'unsigned char get_allied_victory();',
    'unsigned char RGE_Player::get_allied_victory() {\n    return this->allied_victory_;\n}')

# Int setters (10B)
for v, n, fld in [
    ('0046f210','setPathingAttemptCap','pathingAttemptCap_'),
    ('0046f230','setPathingDelayCap','pathingDelayCap_'),
]:
    rgp(v, 'void %s(int v);'%n, 'void RGE_Player::%s(int v) {\n    this->%s = v;\n}'%(n,fld))

# Uchar setter (13B)
rgp('00470bb0', 'void set_allied_victory(unsigned char v);',
    'void RGE_Player::set_allied_victory(unsigned char v) {\n    this->allied_victory_ = v;\n}')

# Increment (4B)
rgp('0046f290', 'void incrementPathingAttempts();',
    'void RGE_Player::incrementPathingAttempts() {\n    this->currentUpdatePathingAttempts_++;\n}')

# Return-0 with param (5B)
rgp('0046eda0', 'int aiStatus(int);',
    'int RGE_Player::aiStatus(int) {\n    return 0;\n}')

# Empty stubs with params (3B)
rgp('0046eed0', 'void setDiplomaticStance(int, int);',
    'void RGE_Player::setDiplomaticStance(int, int) {\n}')
rgp('0046eee0', 'void loadAIInformation(int, int, int, int, int);',
    'void RGE_Player::loadAIInformation(int, int, int, int, int) {\n}')
rgp('0046f410', 'void scenario_save(int);',
    'void RGE_Player::scenario_save(int) {\n}')
rgp('00471be0', 'void notify(int, int, int, int, int, int);',
    'void RGE_Player::notify(int, int, int, int, int, int) {\n}')

# Empty stubs (1B)
rgp('00470570', 'void random_start();',
    'void RGE_Player::random_start() {\n}')
rgp('00471520', 'void analyize_selected_objects();',
    'void RGE_Player::analyize_selected_objects() {\n}')
rgp('00471bd0', 'void logMessage();',
    'void RGE_Player::logMessage() {\n}')

# ============================================================
# RGE_Tile_List (player.cpp) - 1 function
# ============================================================
RTL_SRC = """\
class RGE_Tile_List {
public:
    char gap_00[8];
    int new_count_;

    int get_new_count();
};

int RGE_Tile_List::get_new_count() {
    int c = this->new_count_;
    this->new_count_ = 0;
    return c;
}
"""
gen('00471eb0', RTL_SRC)

# ============================================================
# T_Scenario (tscenaro.cpp) - 23 functions
# ============================================================
TSC_FIELDS = """\
    virtual ~T_Scenario();
    char gap_04[0x1A8C];
    int MP_Conquest_;
    int MP_Ruins_;
    int MP_Artifacts_;
    int MP_Discoveries_;
    int MP_Exploration_;
    int MP_Gold_;
    char gap_1AA8[0x3100];
    int AlliedVictory_[16];
    int victory_all_flag_;
    char gap_4BEC[4];
    int which_player_;
    char gap_4BF4[0x500];
    int ScenarioOptions_[3];
    int PlayerAge_[16];
    int mp_victory_type_;
    int victory_score_;
    int victory_time_;"""

def tsc(va, decl, impl):
    gen(va, make_src('', 'T_Scenario', TSC_FIELDS, decl, impl))

# 7B int getters
for v, n, fld in [
    ('0052b190','Get_victory_all_flag','victory_all_flag_'),
    ('0052b1c0','GetMPVictory','mp_victory_type_'),
    ('0052b1e0','GetVictoryScore','victory_score_'),
    ('0052b200','GetVictoryTime','victory_time_'),
    ('0052b230','GetSPWhich','which_player_'),
    ('0052b7c0','Get_Multi_Conquest','MP_Conquest_'),
    ('0052b7d0','Get_Multi_Ruins','MP_Ruins_'),
    ('0052b7e0','Get_Multi_Artifacts','MP_Artifacts_'),
    ('0052b7f0','Get_Multi_Discoveries','MP_Discoveries_'),
    ('0052b800','Get_Multi_Exploration','MP_Exploration_'),
    ('0052b810','Get_Multi_Gold','MP_Gold_'),
]:
    tsc(v, 'int %s();'%n, 'int T_Scenario::%s() {\n    return this->%s;\n}'%(n,fld))

# 13B int setters
for v, n, fld in [
    ('0052b1d0','SetVictoryScore','victory_score_'),
    ('0052b1f0','SetVictoryTime','victory_time_'),
    ('0052b430','Set_Multi_Ruins','MP_Ruins_'),
    ('0052b440','Set_Multi_Artifacts','MP_Artifacts_'),
    ('0052b450','Set_Multi_Discoveries','MP_Discoveries_'),
    ('0052b460','Set_Multi_Exploration','MP_Exploration_'),
    ('0052b470','Set_Multi_Gold','MP_Gold_'),
]:
    tsc(v, 'void %s(int v);'%n, 'void T_Scenario::%s(int v) {\n    this->%s = v;\n}'%(n,fld))

# 14B indexed array getters
for v, n, fld in [
    ('0052ba30','GetPlayerAlliedVictory','AlliedVictory_'),
    ('0052ba60','GetScenarioOption','ScenarioOptions_'),
    ('0052ba70','GetPlayerAge','PlayerAge_'),
]:
    tsc(v, 'int %s(int idx);'%n, 'int T_Scenario::%s(int idx) {\n    return this->%s[idx];\n}'%(n,fld))

# 1B empty stub
tsc('0052c070', 'void rehook();', 'void T_Scenario::rehook() {\n}')

# 10B param deref - get_object_ID
TSC_OBJ_SRC = """\
struct ScenarioObj {
    int pad_00;
    int id_;
};

class T_Scenario {
public:
    virtual ~T_Scenario();

    int get_object_ID(ScenarioObj* obj);
};

int T_Scenario::get_object_ID(ScenarioObj* obj) {
    return obj->id_;
}
"""
gen('0052c0a0', TSC_OBJ_SRC)

# ============================================================
# TribeStrategyAIModule (taistrmd.cpp) - 13 functions
# ============================================================
TSAI_DEPS = """\
struct Waypoint {
    char data[12];
};"""

TSAI_FIELDS = """\
    virtual ~TribeStrategyAIModule();
    char gap_04[0xEC];
    int mainDecisionAI_;
    int currentVictoryCondition_;
    char ruleSetName_[0x104];
    int targetID_;
    int targetType_;
    int secondTargetID_;
    int secondTargetType_;
    char gap_20C_pad[4];
    Waypoint targetPoint1_;
    char gap_21C_pad[4];
    Waypoint targetPoint2_;
    char gap_22C_pad[4];
    int targetAttribute_;
    int targetNumber_;"""

# Wait - need to recalculate. targetPoint1 is at +20C.
# After secondTargetType_ at +208 (4 bytes) -> +20C. So no gap needed!
# targetPoint1_ at +20C is 12 bytes -> ends at +218.
# targetPoint2_ at +21C. Gap from +218 to +21C = 4 bytes.
# targetPoint2_ at +21C is 12 bytes -> ends at +228.
# targetAttribute_ at +22C. Gap from +228 to +22C = 4 bytes.
# So the layout is correct with gaps of 4 between each Waypoint and the next field.

# Actually wait, let me recalculate from the start:
# gap_04: +04, size 0xEC -> ends at +04 + 0xEC = +F0 ✓
# mainDecisionAI_: +F0, 4 bytes -> +F4
# currentVictoryCondition_: +F4, 4 bytes -> +F8
# ruleSetName_: +F8, 0x104 bytes -> +F8 + 0x104 = +1FC ✓
# targetID_: +1FC, 4 bytes -> +200
# targetType_: +200, 4 bytes -> +204
# secondTargetID_: +204, 4 bytes -> +208
# secondTargetType_: +208, 4 bytes -> +20C
# gap_20C_pad: NO! secondTargetType_ ends at +20C, and targetPoint1_ IS at +20C
# So no gap needed between secondTargetType_ and targetPoint1_.

# Let me fix the fields string:
TSAI_FIELDS = """\
    virtual ~TribeStrategyAIModule();
    char gap_04[0xEC];
    int mainDecisionAI_;
    int currentVictoryCondition_;
    char ruleSetName_[0x104];
    int targetID_;
    int targetType_;
    int secondTargetID_;
    int secondTargetType_;
    Waypoint targetPoint1_;
    char gap_218[4];
    Waypoint targetPoint2_;
    char gap_228[4];
    int targetAttribute_;
    int targetNumber_;"""

def tsai(va, decl, impl):
    gen(va, make_src(TSAI_DEPS, 'TribeStrategyAIModule', TSAI_FIELDS, decl, impl))

# 7B int getters
for v, n, fld in [
    ('004ea1f0','currentVictoryCondition','currentVictoryCondition_'),
    ('004ea200','targetID','targetID_'), ('004ea210','targetType','targetType_'),
    ('004ea220','secondTargetID','secondTargetID_'), ('004ea230','secondTargetType','secondTargetType_'),
    ('004ea260','targetAttribute','targetAttribute_'), ('004ea270','targetNumber','targetNumber_'),
]:
    tsai(v, 'int %s();'%n, 'int TribeStrategyAIModule::%s() {\n    return this->%s;\n}'%(n,fld))

# 7B LEA getters
tsai('004ea130', 'char* ruleSetName();',
    'char* TribeStrategyAIModule::ruleSetName() {\n    return this->ruleSetName_;\n}')
tsai('004ea240', 'Waypoint* targetPoint1();',
    'Waypoint* TribeStrategyAIModule::targetPoint1() {\n    return &this->targetPoint1_;\n}')
tsai('004ea250', 'Waypoint* targetPoint2();',
    'Waypoint* TribeStrategyAIModule::targetPoint2() {\n    return &this->targetPoint2_;\n}')

# 13B setter
tsai('004e9d90', 'void setMainDecisionAI(int v);',
    'void TribeStrategyAIModule::setMainDecisionAI(int v) {\n    this->mainDecisionAI_ = v;\n}')

# 5B return-0 with 2 params
tsai('004e7610', 'int evaluateAsInProgress(int, int);',
    'int TribeStrategyAIModule::evaluateAsInProgress(int, int) {\n    return 0;\n}')
tsai('004e8d10', 'int stopExecution(int, int);',
    'int TribeStrategyAIModule::stopExecution(int, int) {\n    return 0;\n}')

# ============================================================
# RGE_Base_Game (basegame.cpp) - ~53 functions
# ============================================================
RBG_FIELDS = """\
    virtual ~RGE_Base_Game();
    char gap_04[0x3C];
    int error_code_;
    char gap_44[0x4C4];
    int world_update_count_;
    int view_update_count_;
    char gap_510[4];
    int last_world_update_count_;
    int last_view_update_count_;
    char gap_51C[0x3DC];
    float version_;
    unsigned char scenarioGame_;
    char scenarioName_[0x80];
    unsigned char singlePlayerGame_;
    unsigned char multiplayerGame_;
    unsigned char mapXSize_;
    unsigned char mapYSize_;
    unsigned char mapZSize_;
    unsigned char allowCheatCodes_;
    unsigned char mpPathFinding_;
    unsigned char cheatNotification_;
    unsigned char fullVisibility_;
    unsigned char fogOfWar_;
    unsigned char coloredChat_;
    unsigned char numberPlayers_;
    unsigned char gameDeveloperMode_;
    unsigned char cdAndVersion_[9];
    unsigned char difficulty_;
    char gap_994[0xC];
    int campaignGame_;
    int savedGame_;
    char gap_9A8[8];
    int playerID_[16];
    char gap_9F0[0x1C];
    float game_speed_;
    int single_player_difficulty_;
    unsigned char pathFinding_;"""

def rbg(va, decl, impl):
    gen(va, make_src('', 'RGE_Base_Game', RBG_FIELDS, decl, impl))

# 4B int getter (small offset)
rbg('0041c990', 'int get_error_code();',
    'int RGE_Base_Game::get_error_code() {\n    return this->error_code_;\n}')

# 7B int getters (large offset)
for v, n, fld in [
    ('0041c950','get_last_world_update_count','last_world_update_count_'),
    ('0041c960','get_last_view_update_count','last_view_update_count_'),
    ('0041c970','get_world_update_count','world_update_count_'),
    ('0041c980','get_view_update_count','view_update_count_'),
    ('004223c0','campaignGame','campaignGame_'),
    ('004223d0','savedGame','savedGame_'),
    ('00422ed0','get_single_player_difficulty','single_player_difficulty_'),
]:
    rbg(v, 'int %s();'%n, 'int RGE_Base_Game::%s() {\n    return this->%s;\n}'%(n,fld))

# 7B float getters
for v, n, fld in [
    ('00422390','version','version_'),
    ('00422eb0','get_game_speed','game_speed_'),
]:
    rbg(v, 'float %s();'%n, 'float RGE_Base_Game::%s() {\n    return this->%s;\n}'%(n,fld))

# 9B byte getters (return int from unsigned char field)
for v, n, fld in [
    ('004223a0','scenarioGame','scenarioGame_'),
    ('004223f0','singlePlayerGame','singlePlayerGame_'),
    ('00422400','multiplayerGame','multiplayerGame_'),
    ('00422410','mapXSize','mapXSize_'),
    ('00422420','mapYSize','mapYSize_'),
    ('00422430','mapZSize','mapZSize_'),
    ('00422440','allowCheatCodes','allowCheatCodes_'),
    ('00422450','cheatNotification','cheatNotification_'),
    ('00422460','fullVisibility','fullVisibility_'),
    ('00422470','fogOfWar','fogOfWar_'),
    ('00422480','coloredChat','coloredChat_'),
    ('00422490','gameDeveloperMode','gameDeveloperMode_'),
    ('00422640','difficulty','difficulty_'),
    ('00422650','numberPlayers','numberPlayers_'),
]:
    rbg(v, 'int %s();'%n, 'int RGE_Base_Game::%s() {\n    return this->%s;\n}'%(n,fld))

# 7B uchar getters (return unsigned char)
for v, n, fld in [
    ('00422670','pathFinding','pathFinding_'),
    ('00422680','mpPathFinding','mpPathFinding_'),
]:
    rbg(v, 'unsigned char %s();'%n, 'unsigned char RGE_Base_Game::%s() {\n    return this->%s;\n}'%(n,fld))

# 7B LEA (char array)
rbg('004223e0', 'char* scenarioName();',
    'char* RGE_Base_Game::scenarioName() {\n    return this->scenarioName_;\n}')

# 7B increments
rbg('0041c870', 'void increment_world_update_count();',
    'void RGE_Base_Game::increment_world_update_count() {\n    this->world_update_count_++;\n}')
rbg('0041c880', 'void increment_view_update_count();',
    'void RGE_Base_Game::increment_view_update_count() {\n    this->view_update_count_++;\n}')

# 13B dword setters (large offset)
for v, n, fld in [
    ('00422700','setCampaignGame','campaignGame_'),
    ('00422710','setSavedGame','savedGame_'),
]:
    rbg(v, 'void %s(int v);'%n, 'void RGE_Base_Game::%s(int v) {\n    this->%s = v;\n}'%(n,fld))

# setVersion stores float as raw 4-byte copy (float param, not int)
rbg('004226c0', 'void setVersion(float v);',
    'void RGE_Base_Game::setVersion(float v) {\n    this->version_ = v;\n}')

# Float setters stored as raw dword
rbg('00422ec0', 'void set_game_speed(float v);',
    'void RGE_Base_Game::set_game_speed(float v) {\n    this->game_speed_ = v;\n}')
rbg('00422ee0', 'void set_single_player_difficulty(int v);',
    'void RGE_Base_Game::set_single_player_difficulty(int v) {\n    this->single_player_difficulty_ = v;\n}')

# 13B byte setters (unsigned char param)
for v, n, fld in [
    ('004226b0','setScenarioGame','scenarioGame_'),
    ('00422790','setAllowCheatCodes','allowCheatCodes_'),
    ('004227a0','setCheatNotification','cheatNotification_'),
    ('004227b0','setFullVisibility','fullVisibility_'),
    ('004227c0','setFogOfWar','fogOfWar_'),
    ('004227d0','setColoredChat','coloredChat_'),
    ('004227e0','setNumberPlayers','numberPlayers_'),
    ('004227f0','setGameDeveloperMode','gameDeveloperMode_'),
    ('00422870','setDifficulty','difficulty_'),
    ('004228a0','setPathFinding','pathFinding_'),
    ('004228b0','setMpPathFinding','mpPathFinding_'),
]:
    rbg(v, 'void %s(unsigned char v);'%n,
        'void RGE_Base_Game::%s(unsigned char v) {\n    this->%s = v;\n}'%(n,fld))

# 1B empty stubs
for v, n in [
    ('00422e40','close_video'), ('00422e50','handle_video_notify'),
    ('00422fe0','set_interface_messages'),
]:
    rbg(v, 'void %s();'%n, 'void RGE_Base_Game::%s() {\n}'%n)

# 5B return-0 with param
rbg('00422e30', 'int play_video(int);',
    'int RGE_Base_Game::play_video(int) {\n    return 0;\n}')

# 3B empty with param
rbg('00422d80', 'void dump_memory_usage(int);',
    'void RGE_Base_Game::dump_memory_usage(int) {\n}')

# 14B indexed int getter
rbg('00422d90', 'int playerID(int idx);',
    'int RGE_Base_Game::playerID(int idx) {\n    return this->playerID_[idx];\n}')

# 14B indexed byte getter
rbg('00422630', 'unsigned char playerCDAndVersion(int idx);',
    'unsigned char RGE_Base_Game::playerCDAndVersion(int idx) {\n    return this->cdAndVersion_[idx];\n}')

# 14B randomGame (stretch - boolean negation)
rbg('004223b0', 'int randomGame();',
    'int RGE_Base_Game::randomGame() {\n    return !this->scenarioGame_;\n}')

# 13B gameSummary (stretch - static global)
GAMESUMMARY_SRC = """\
static char game_summary_buf;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char* gameSummary();
};

char* RGE_Base_Game::gameSummary() {
    game_summary_buf = 0;
    return &game_summary_buf;
}
"""
gen('00422690', GAMESUMMARY_SRC)

# ============================================================
# Version setter type fix - setVersion stores float as int
# ============================================================
# The setVersion function stores a float but uses integer mov.
# With param type 'int', VC5 generates: mov eax,[esp+4]; mov [ecx+N],eax
# But the field is float. Let me check if int param to float field compiles...
# Actually we declared version_ as float and setVersion takes int.
# This will compile (implicit conversion) but might use FPU.
# Let me override setVersion to use float param instead:
# Already declared above as void setVersion(int v) which stores to float version_.
# Hmm, that might generate: load int, convert to float via FPU, store.
# The original just does raw mov. So I need to match that.
# With float param and float field, VC5 does raw mov (no FPU).
# Let me fix setVersion to take float:

# Already need to regenerate... but gen() skips existing files.
# I'll handle this after first validation pass.

# ============================================================
# Summary
# ============================================================
print(f'Generated {count} files')
if errs:
    print(f'Errors (VA not in CSV): {errs}')
