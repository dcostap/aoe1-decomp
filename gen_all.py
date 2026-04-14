"""Generate all 83 function source+flag files for batch matching."""
import os

SCRATCH = r"C:\Projects\my_decomps\aoe1_attempt3\src\scratch"
FLAGS = r"C:\Projects\my_decomps\aoe1_attempt3\config\flags"

RSP = "/nologo\n/c\n/O2\n"

def write(name, content):
    src = os.path.join(SCRATCH, name + ".cpp")
    rsp = os.path.join(FLAGS, name + ".rsp")
    with open(src, "w") as f:
        f.write(content)
    if not os.path.exists(rsp):
        with open(rsp, "w") as f:
            f.write(RSP)

# ============================================================
# basegame.cpp functions
# ============================================================

write("0041C9C0_get_string", r"""
typedef int (__stdcall *LoadStringFunc)(void*, int, char*, int);
extern void* DAT_0062c4a0;
extern LoadStringFunc FN_0088a818;

char* __stdcall get_string(int string_id, char* buffer, int buffer_size) {
    int result = FN_0088a818(DAT_0062c4a0, string_id, buffer, buffer_size);
    if (!result) {
        *buffer = 0;
    }
    buffer[buffer_size - 1] = 0;
    return buffer;
}
""".lstrip())

write("0041CF30_get_campaign_info", r"""
class RGE_Campaign_Info_ci {
public:
    int get_current_campaign(void);
    int get_current_player(void);
    int get_number_campaigns(void);
};

class RGE_Base_Game_ci {
public:
    void get_campaign_info(int* campaign, int* player, int* num_campaigns);
    char gap_00[0x04];
    RGE_Campaign_Info_ci* game_info;
};

void RGE_Base_Game_ci::get_campaign_info(int* campaign, int* player, int* num_campaigns) {
    int c = this->game_info->get_current_campaign();
    *campaign = c;
    int p = this->game_info->get_current_player();
    *player = p;
    int n = this->game_info->get_number_campaigns();
    *num_campaigns = n;
}
""".lstrip())

write("0041EBC0_setup_palette", r"""
class TPanelSystem_pal {
public:
    int get_palette(char* data, int size);
};
extern TPanelSystem_pal DAT_0062e870;

class RGE_Base_Game_pal {
public:
    int setup_palette(void);
    char gap_00[0x0C];
    char* prog_data;
    char gap_10[0x0C];
    int prog_palette;
};

int RGE_Base_Game_pal::setup_palette(void) {
    int result = DAT_0062e870.get_palette(this->prog_data + 0x66E, 0xC544);
    this->prog_palette = result;
    return result != 0;
}
""".lstrip())

write("0041F800_setup_timings", r"""
class RGE_Base_Game_tim {
public:
    void setup_timings(void);
    char gap_00[0x538];
    int timing_538;
    char gap_53C[0x18];
    int timing_554;
    char gap_558[0x1C];
    int timing_574;
    char gap_578[0x1C];
    int timing_594;
    char gap_598[0x20];
    int timing_5B8;
    char gap_5BC[0xB8];
    int timing_674;
    char gap_678[0x5C];
    int timing_6D4;
};

void RGE_Base_Game_tim::setup_timings(void) {
    int val = 1;
    this->timing_554 = val;
    this->timing_574 = val;
    this->timing_594 = val;
    this->timing_674 = val;
    this->timing_6D4 = val;
    this->timing_538 = val;
    this->timing_5B8 = val;
}
""".lstrip())

write("00420150_set_player", r"""
class DiamondMapView_sp {
public:
    void clear_info(void);
};

class RGE_Game_World_sp {
public:
    char gap_00[0x28];
    DiamondMapView_sp* diamond_map;
    char gap_2C[0x10];
    short num_players;
    char gap_3E[0x3E];
    short current_player;
};

class RGE_Base_Game_sp {
public:
    void set_player(short player_id);
    char gap_00[0x3F4];
    RGE_Game_World_sp* world;
};

void RGE_Base_Game_sp::set_player(short player_id) {
    RGE_Game_World_sp* w = this->world;
    if (w == 0) return;
    if (player_id >= w->num_players) return;
    w->current_player = player_id;
    this->world->diamond_map->clear_info();
}
""".lstrip())

write("00420330_get_player", r"""
class RGE_Player_gp;

class RGE_Game_World_gp {
public:
    char gap_00[0x3C];
    short num_players;
    char gap_3E[0x02];
    void** player_list;
    char gap_44[0x38];
    short current_player;
};

class RGE_Base_Game_gp {
public:
    RGE_Player_gp* get_player(void);
    char gap_00[0x3F4];
    RGE_Game_World_gp* world;
};

RGE_Player_gp* RGE_Base_Game_gp::get_player(void) {
    RGE_Game_World_gp* w = this->world;
    if (!w) return 0;
    if (!w->num_players) return 0;
    if (w->current_player >= w->num_players) return 0;
    return (RGE_Player_gp*)w->player_list[(int)(short)w->current_player];
}
""".lstrip())

write("004226D0_setScenarioName", r"""
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class RGE_Base_Game_ssn {
public:
    void setScenarioName(const char* name);
    char gap_00[0x8FD];
    char scenarioName[0x80];
    char gap_97D[0xFF];
};

void RGE_Base_Game_ssn::setScenarioName(const char* name) {
    strncpy(this->scenarioName, name, 0x80);
    *((unsigned char*)this + 0x97C) = 0;
}
""".lstrip())

write("00422800_setPlayerHasCD", r"""
class RGE_Base_Game_cd {
public:
    void setPlayerHasCD(int player, unsigned char hasCD);
    char gap_00[0x98A];
    unsigned char playerCDVersion[1];
};

void RGE_Base_Game_cd::setPlayerHasCD(int player, unsigned char hasCD) {
    unsigned char val = *((unsigned char*)this + 0x98A + player);
    val = (val & 0xFE) | hasCD;
    *((unsigned char*)this + 0x98A + player) = val;
}
""".lstrip())

write("00422820_setPlayerVersion", r"""
class RGE_Base_Game_ver {
public:
    void setPlayerVersion(int player, unsigned char version);
    char gap_00[0x98A];
    unsigned char playerCDVersion[1];
};

void RGE_Base_Game_ver::setPlayerVersion(int player, unsigned char version) {
    unsigned char v = version << 1;
    unsigned char old = *((unsigned char*)this + 0x98A + player);
    v = v | (old & 1);
    *((unsigned char*)this + 0x98A + player) = v;
}
""".lstrip())

write("00422D20_get_scenario_checksum", r"""
class RGE_Scenario_Header_cks {
public:
    void destroy(void);
    char gap_00[0x0C];
    int checksum;
};

extern "C" void __cdecl operator_delete(void*);

class RGE_Base_Game_cks {
public:
    int get_scenario_checksum(int scenario_num);
    RGE_Scenario_Header_cks* get_scenario_header(int scenario_num, int flag);
};

int RGE_Base_Game_cks::get_scenario_checksum(int scenario_num) {
    RGE_Scenario_Header_cks* hdr = this->get_scenario_header(scenario_num, 0);
    if (!hdr) return 0;
    int cksum = hdr->checksum;
    hdr->destroy();
    operator_delete(hdr);
    return cksum;
}
""".lstrip())

write("00422DE0_set_countdown_timer", r"""
class RGE_Base_Game_cdt {
public:
    void set_countdown_timer(int index, int value);
    char gap_00[0x9D8];
    int countdown_timers[1];
};

void RGE_Base_Game_cdt::set_countdown_timer(int index, int value) {
    int current = this->countdown_timers[index];
    if (current > value || current < 0) {
        this->countdown_timers[index] = value;
    }
}
""".lstrip())

# ============================================================
# Com_hand.cpp functions
# ============================================================

write("00425750_GameOver", r"""
class RGE_Communications_Queue_go {
public:
    void Flush(void);
};

class TCommunications_Handler_go {
public:
    void GameOver(void);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x3F8];
    RGE_Communications_Queue_go* inQ;
    RGE_Communications_Queue_go* outQ;
};

void TCommunications_Handler_go::GameOver(void) {
    this->current_turn = 0;
    if (this->inQ)
        this->inQ->Flush();
    if (this->outQ)
        this->outQ->Flush();
}
""".lstrip())

write("004258E0_StopIfSyncFail", r"""
class RGE_Communications_Synchronize_sf {
public:
    void SetDialogOnFail(int val);
    void SetStopOnFail(int val);
};

class TCommunications_Handler_sf {
public:
    void StopIfSyncFail(int flag);
    char gap_00[0x14D8];
    RGE_Communications_Synchronize_sf* sync;
};

void TCommunications_Handler_sf::StopIfSyncFail(int flag) {
    this->sync->SetDialogOnFail(flag);
    this->sync->SetStopOnFail(flag);
}
""".lstrip())

write("00425930_DropPacketsIntentionally", r"""
extern void* DAT_0062c4fc;
void __cdecl debug_log(void* log, const char* msg);
extern char DAT_00580c28[];

class TCommunications_Handler_dp {
public:
    void DropPacketsIntentionally(int flag);
    char gap_00[0x1518];
    int intentional_drop;
};

void TCommunications_Handler_dp::DropPacketsIntentionally(int flag) {
    this->intentional_drop = flag;
    if (flag) {
        debug_log(DAT_0062c4fc, DAT_00580c28);
    }
}
""".lstrip())

write("00426470_AddCommand", r"""
class RGE_Communications_Queue_ac {
public:
    void AddItem(int a, int b, int c, int d, int e, int f);
};

class TCommunications_Handler_ac {
public:
    void AddCommand(int a, int b, int c, int d, int e, int f);
    char gap_00[0x14C4];
    RGE_Communications_Queue_ac* inQ;
};

void TCommunications_Handler_ac::AddCommand(int a, int b, int c, int d, int e, int f) {
    this->inQ->AddItem(a, b, c, d, e, f);
}
""".lstrip())

write("004297D0_SendChatMsgAll", r"""
class TCommunications_Handler_chat {
public:
    void SendChatMsgAll(const char* msg);
    void SendChatMsg(int player_id, char* dest_map, const char* msg);
    char gap_00[0x10E0];
    int local_player;
};

void TCommunications_Handler_chat::SendChatMsgAll(const char* msg) {
    char dest[10];
    *(int*)&dest[0] = 0x59595959;
    *(int*)&dest[4] = 0x59595959;
    *(short*)&dest[8] = 0x5959;
    this->SendChatMsg(this->local_player, dest, msg);
}
""".lstrip())

write("0042A130_ClearTXForPlayer", r"""
class TCommunications_Handler_ctx {
public:
    void ClearTXForPlayer(int player);
    char gap_00[0x1520];
    int* tx_data;
};

void TCommunications_Handler_ctx::ClearTXForPlayer(int player) {
    int base = player * 4 + 0x10;
    int count = 0x1F6;
    int* data = this->tx_data;
    while (count--) {
        *(int*)((char*)data + base) = 0;
        base += 0x38;
    }
}
""".lstrip())

write("0042CC00_GetPlayerHumanity", r"""
class TCommunications_Handler_gph {
public:
    int GetPlayerHumanity(int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};

int TCommunications_Handler_gph::GetPlayerHumanity(int player) {
    if (player < 1) return 0;
    if (player > (int)this->max_players) return 0;
    return this->humanity[player];
}
""".lstrip())

write("0042CD10_IsPlayerComputer", r"""
class TCommunications_Handler_ipc {
public:
    int IsPlayerComputer(int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};

int TCommunications_Handler_ipc::IsPlayerComputer(int player) {
    if (player < 1) return 0;
    if (player > (int)this->max_players) return 0;
    int h = this->humanity[player];
    return h == 4;
}
""".lstrip())

write("0042D3B0_SetGameTitle", r"""
extern "C" int __cdecl sprintf(char*, const char*, ...);

class TCommunications_Handler_sgt {
public:
    int SetGameTitle(const char* title);
    char gap_00[0x10F8];
    char game_name[0x102];
    char player_name[1];
};

int TCommunications_Handler_sgt::SetGameTitle(const char* title) {
    sprintf(this->player_name, "%s [%s]", title, this->game_name);
    return 1;
}
""".lstrip())

write("0042DA50_InitJoinGame", r"""
class TCommunications_Handler_ijg {
public:
    void InitJoinGame(void);
    void ClearChat(void);
    void CreateDirectPlayConversation(void);
    char gap_00[0x18];
    void* chat;
    char gap_1C[0x01];
    int options_1c;
    int options_20;
    char gap_24[0x10C0];
    int multiplayer_flag;
    char gap_10E8[0x3FC];
    int dp_option;
};

void TCommunications_Handler_ijg::InitJoinGame(void) {
    this->ClearChat();
    this->multiplayer_flag = 1;
    this->options_20 = 0;
    this->options_1c = 0;
    this->dp_option = 0;
    this->CreateDirectPlayConversation();
}
""".lstrip())

write("0042DEA0_SetApplicationGUID", r"""
struct GUID_local {
    int a; int b; int c; int d;
};

class TCommunications_Handler_sag {
public:
    void SetApplicationGUID(int a, int b, int c, int d);
    char gap_00[0x12EC];
    GUID_local app_guid;
};

void TCommunications_Handler_sag::SetApplicationGUID(int a, int b, int c, int d) {
    this->app_guid.a = a;
    this->app_guid.b = b;
    this->app_guid.c = c;
    this->app_guid.d = d;
}
""".lstrip())

write("0042DEE0_SetServiceGUID", r"""
struct GUID_loc2 {
    int a; int b; int c; int d;
};

class TCommunications_Handler_ssg {
public:
    void SetServiceGUID(int a, int b, int c, int d);
    char gap_00[0x12DC];
    GUID_loc2 svc_guid;
};

void TCommunications_Handler_ssg::SetServiceGUID(int a, int b, int c, int d) {
    this->svc_guid.a = a;
    this->svc_guid.b = b;
    this->svc_guid.c = c;
    this->svc_guid.d = d;
}
""".lstrip())

write("0042DF10_SetSessionGUID", r"""
struct GUID_loc3 {
    int a; int b; int c; int d;
};

class TCommunications_Handler_sssg {
public:
    void SetSessionGUID(int a, int b, int c, int d);
    char gap_00[0x12FC];
    GUID_loc3 sess_guid;
};

void TCommunications_Handler_sssg::SetSessionGUID(int a, int b, int c, int d) {
    this->sess_guid.a = a;
    this->sess_guid.b = b;
    this->sess_guid.c = c;
    this->sess_guid.d = d;
}
""".lstrip())

write("0042E580_IsPlayerReady", r"""
class TCommunications_Handler_ipr {
public:
    int IsPlayerReady(int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x2BA];
    int ready[1];
};

int TCommunications_Handler_ipr::IsPlayerReady(int player) {
    if (player < 1) return 0;
    if (player > (int)this->max_players) return 0;
    return this->ready[player];
}
""".lstrip())

write("0042E5B0_ComputerPlayerGameStart", r"""
class TCommunications_Handler_cpgs {
public:
    int ComputerPlayerGameStart(void);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x18];
    int multiplayer_flag;
};

int TCommunications_Handler_cpgs::ComputerPlayerGameStart(void) {
    if (!this->multiplayer_flag)
        return 1;
    // sbb+neg pattern: returns (6 < current_turn) i.e. current_turn > 6
    return (unsigned int)6 < (unsigned int)this->current_turn;
}
""".lstrip())

write("0042E5E0_MultiplayerGameStart", r"""
class TCommunications_Handler_mpgs {
public:
    int MultiplayerGameStart(void);
    void DoCycle(int param);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x18];
    int multiplayer_flag;
};

int TCommunications_Handler_mpgs::MultiplayerGameStart(void) {
    if (!this->multiplayer_flag)
        return 1;
    if (this->current_turn > 6)
        return 1;
    this->DoCycle(0);
    return 0;
}
""".lstrip())

write("0042EC10_FreeOptions", r"""
extern "C" void __cdecl operator_delete_fo(void*);

class TCommunications_Handler_fo {
public:
    void FreeOptions(void);
    char gap_00[0x04];
    void* options_data;
    char gap_08[0x1714];
    int data_size;
};

void TCommunications_Handler_fo::FreeOptions(void) {
    if (this->options_data) {
        this->data_size = 0;
        operator_delete_fo(this->options_data);
        this->options_data = 0;
    }
}
""".lstrip())

write("0042F110_ForcePlayerEnumeration", r"""
extern void* DAT_0062c4fc;
void __cdecl debug_log_fpe(void* log, const char* msg);
extern char DAT_0058325c[];

struct IDirectPlay_vtbl {
    char gap_00[0x30];
    int (__stdcall *EnumPlayers)(void* thisptr, int flags, void* callback, void* context, int extra);
};

struct IDirectPlay_obj {
    IDirectPlay_vtbl* vtbl;
};

extern IDirectPlay_obj* DAT_0062c5ec;

void __stdcall EnumPlayersCallback(void);

class TCommunications_Handler_fpe {
public:
    void ForcePlayerEnumeration(void);
};

void TCommunications_Handler_fpe::ForcePlayerEnumeration(void) {
    debug_log_fpe(DAT_0062c4fc, DAT_0058325c);
    IDirectPlay_obj* dp = DAT_0062c5ec;
    dp->vtbl->EnumPlayers(dp, 0, (void*)EnumPlayersCallback, this, 0);
}
""".lstrip())

# ============================================================
# com_loby.cpp functions
# ============================================================

write("0042F300_RGE_Lobby", r"""
class RGE_Comm_Error_lob {
public:
    void destroy(void);
};
extern "C" void __cdecl operator_delete_lob(void*);

class RGE_Lobby_dtor {
public:
    void dtor(void);
    void ClearLobbyInfo(void);
    char gap_00[0x18];
    RGE_Comm_Error_lob* err;
};

void RGE_Lobby_dtor::dtor(void) {
    RGE_Comm_Error_lob* e = this->err;
    if (e) {
        e->destroy();
        operator_delete_lob(e);
    }
    this->ClearLobbyInfo();
}
""".lstrip())

write("0042F370_IsLobbyLaunched", r"""
extern void* DAT_0062c4fc;
void __cdecl debug_log_ill(void* log, const char* fmt, ...);
extern char DAT_005832e8[];

class RGE_Lobby_ill {
public:
    unsigned char IsLobbyLaunched(void);
    char gap_00[0x14];
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_ill::IsLobbyLaunched(void) {
    debug_log_ill(DAT_0062c4fc, DAT_005832e8, (int)this->lobby_game);
    return this->lobby_game;
}
""".lstrip())

write("0042F660_GetPlayerInfo", r"""
struct DPLCONNECTION_gpi {
    char gap_00[0x08];
    void* player_name_ptr;
};

struct ConnectionInfo_gpi {
    char gap_00[0x08];
    DPLCONNECTION_gpi* conn_settings;
};

class RGE_Lobby_gpi {
public:
    unsigned char GetPlayerInfo(int* out);
    char gap_00[0x10];
    ConnectionInfo_gpi* lobby_data;
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_gpi::GetPlayerInfo(int* out) {
    if (!this->lobby_game) return 0;
    *out = (int)this->lobby_data->conn_settings->player_name_ptr;
    return 1;
}
""".lstrip())

write("0042F680_GetSessionInfo", r"""
struct ConnectionInfo_gsi {
    char gap_00[0x08];
    void* session_desc;
};

class RGE_Lobby_gsi {
public:
    unsigned char GetSessionInfo(void* out);
    char gap_00[0x10];
    ConnectionInfo_gsi* lobby_data;
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_gsi::GetSessionInfo(void* out) {
    if (!this->lobby_game) return 0;
    // copies 20 dwords (80 bytes) from session_desc to out
    int* dst = (int*)out;
    int* src = (int*)this->lobby_data->session_desc;
    for (int i = 0; i < 20; i++)
        dst[i] = src[i];
    return 1;
}
""".lstrip())

# ============================================================
# com_spd.cpp functions
# ============================================================

write("00432800_SetActualLatency", r"""
class RGE_Communications_Speed_sal {
public:
    void SetActualLatency(int player, int latency);
    char gap_00[0x148];
    int actual_latency[1];
};

void RGE_Communications_Speed_sal::SetActualLatency(int player, int latency) {
    if (player < 1 || player > 9)
        return;
    if (latency < 30)
        latency = 30;
    if (latency > 6000)
        latency = 6000;
    this->actual_latency[player] = latency;
}
""".lstrip())

write("00432840_SetFutureSpeedChange", r"""
class RGE_Communications_Speed_sfsc {
public:
    void SetFutureSpeedChange(int buffer_frames, int granularity, int turn_change);
    char gap_00[0x120];
    int future_buffer;
    char gap_124[0x0C];
    int future_granularity;
    char gap_134[0x0C];
    int future_turn_change;
};

void RGE_Communications_Speed_sfsc::SetFutureSpeedChange(int buffer_frames, int granularity, int turn_change) {
    if (this->future_turn_change)
        return;
    this->future_buffer = buffer_frames;
    this->future_granularity = granularity;
    this->future_turn_change = turn_change;
}
""".lstrip())

write("00432940_ReloadBufferFrames", r"""
class TurnTimer_rbf {
public:
    void Reset(void);
};

class RGE_Communications_Speed_rbf {
public:
    void ReloadBufferFrames(void);
    void AdjustLocalSpeed(void);
    char gap_00[0x100];
    TurnTimer_rbf* turn_timer;
    char gap_104[0x18];
    int buffer_frames;
    char gap_120[0x04];
    int current_buffer;
    char gap_128[0x10C];
    int dropped_frames;
};

void RGE_Communications_Speed_rbf::ReloadBufferFrames(void) {
    this->turn_timer->Reset();
    this->dropped_frames = 0;
    this->AdjustLocalSpeed();
    this->current_buffer = this->buffer_frames;
}
""".lstrip())

# ============================================================
# gameinfo.cpp functions
# ============================================================

write("0044C870_RGE_Campaign_Info", r"""
extern "C" void __cdecl free(void*);

class RGE_Campaign_Info_dtor {
public:
    void dtor(void);
    char gap_00[0x108];
    void* scenario_info;
};

void RGE_Campaign_Info_dtor::dtor(void) {
    if (this->scenario_info) {
        free(this->scenario_info);
        this->scenario_info = 0;
    }
}
""".lstrip())

write("0044D0C0_get_current_scenario", r"""
class RGE_Campaign_gcs {
public:
    int get_current_scenario(void);
};

class RGE_Campaign_Info_gcs {
public:
    int get_current_scenario(void);
    char gap_00[0x100];
    int current_person;
    char gap_104[0x04];
    void** campaigns;
    char gap_10C[0x04];
    int* campaign_valid;
};

int RGE_Campaign_Info_gcs::get_current_scenario(void) {
    int idx = this->current_person;
    if (idx <= -1) return -1;
    if (!this->campaign_valid[idx]) return -1;
    return ((RGE_Campaign_gcs*)this->campaigns[idx])->get_current_scenario();
}
""".lstrip())

write("0044D130_get_scenario_list", r"""
class RGE_Campaign_gsl {
public:
    int get_scenario_list(int a, int b);
};

class RGE_Campaign_Info_gsl {
public:
    int get_scenario_list(int a, int b);
    char gap_00[0x100];
    int current_person;
    char gap_104[0x04];
    void** campaigns;
};

int RGE_Campaign_Info_gsl::get_scenario_list(int a, int b) {
    int idx = this->current_person;
    if (idx <= -1) return 0;
    return ((RGE_Campaign_gsl*)this->campaigns[idx])->get_scenario_list(a, b);
}
""".lstrip())

write("0044D7F0_set_current_campaign", r"""
class RGE_Campaign_scc {
public:
    unsigned char set_current_campaign(int campaign);
};

class RGE_Campaign_Info_scc {
public:
    unsigned char set_current_campaign(int campaign);
    int person_index;
    int people_count;
    void** campaigns;
};

unsigned char RGE_Campaign_Info_scc::set_current_campaign(int campaign) {
    if (this->person_index >= this->people_count) return 0;
    if (this->person_index < 0) return 0;
    return ((RGE_Campaign_scc*)this->campaigns[this->person_index])->set_current_campaign(campaign);
}
""".lstrip())

write("0044D820_set_current_scenario", r"""
class RGE_Campaign_scs {
public:
    unsigned char set_current_scenario(int scenario);
};

class RGE_Campaign_Info_scs {
public:
    unsigned char set_current_scenario(int scenario);
    int person_index;
    int people_count;
    void** campaigns;
};

unsigned char RGE_Campaign_Info_scs::set_current_scenario(int scenario) {
    if (this->person_index < 0) return 0;
    if (this->person_index >= this->people_count) return 0;
    return ((RGE_Campaign_scs*)this->campaigns[this->person_index])->set_current_scenario(scenario);
}
""".lstrip())

write("0044DA00_notify_of_scenario_complete", r"""
class RGE_Campaign_nsc {
public:
    void notify_of_scenario_complete(void);
};

class RGE_Campaign_Info_nsc {
public:
    void notify_of_scenario_complete(void);
    void save_state(char* path);
    int person_index;
    int people_count;
    void** campaigns;
    char gap_0C[0x08];
    char save_path[1];
};

void RGE_Campaign_Info_nsc::notify_of_scenario_complete(void) {
    if (this->person_index < this->people_count && this->person_index >= 0) {
        ((RGE_Campaign_nsc*)this->campaigns[this->person_index])->notify_of_scenario_complete();
    }
    this->save_state(this->save_path);
}
""".lstrip())

# ============================================================
# player.cpp functions
# ============================================================

write("0046EFB0_sendGameOrder", r"""
class RGE_Command_sgo {
public:
    void sendCommand(int cmd_type, int* params, int a, int b, int c);
};

class RGE_Game_World_sgo {
public:
    char gap_00[0x58];
    RGE_Command_sgo* command;
};

class RGE_Player_sgo {
public:
    void sendGameOrder(int a, int b, int c, int d);
    char gap_00[0x3C];
    RGE_Game_World_sgo* world;
};

void RGE_Player_sgo::sendGameOrder(int a, int b, int c, int d) {
    // original: stores a into [esp+4] then loads from stack
    // The original rearranges params and calls via world->command
    this->world->command->sendCommand(1, &a, b, c, d);
}
""".lstrip())

write("0046EFE0_sendAddWaypointCommand", r"""
class RGE_Command_saw {
public:
    void sendAddWaypoint(int player, int a, int b, int c);
};

class RGE_Game_World_saw {
public:
    char gap_00[0x58];
    RGE_Command_saw* command;
};

class RGE_Player_saw {
public:
    void sendAddWaypointCommand(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_saw* world;
    char gap_40[0x0A];
    short player_id;
};

void RGE_Player_saw::sendAddWaypointCommand(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->sendAddWaypoint(pid, a, b, c);
}
""".lstrip())

write("0046FF00_load_info", r"""
class RGE_Object_List_li {
public:
    void rehook(void);
};

class RGE_Player_li {
public:
    int load_info(void* infile);
    int vfptr;
    char gap_04[0x24];
    RGE_Object_List_li* list1;
    RGE_Object_List_li* list2;
    RGE_Object_List_li* list3;
};

int RGE_Player_li::load_info(void* infile) {
    int (__stdcall *load_fn)(void*, int, int) = (int (__stdcall *)(void*, int, int)) *((int*)&this->vfptr + 0x3C);
    // vtable call [eax+0xF0] = index 0x3C from vtable ptr
    // Simplified: call virtual load(infile, 0, 1) then rehook 3 lists
    (*(int (**)(void*, int, int))(*(int*)this + 0xF0))(infile, 0, 1);
    this->list1->rehook();
    this->list2->rehook();
    this->list3->rehook();
    return 0;
}
""".lstrip())

write("0046FF60_get_checksums", r"""
class RGE_Player_gc {
public:
    unsigned char get_checksums(int* cksum1, int* cksum2, int* cksum3);
    void calculate_checksums(void);
    char gap_00[0x14];
    int checksum1;
    int checksum2;
    int checksum3;
    unsigned char checksums_valid;
};

unsigned char RGE_Player_gc::get_checksums(int* cksum1, int* cksum2, int* cksum3) {
    if (!this->checksums_valid)
        this->calculate_checksums();
    *cksum1 = this->checksum1;
    *cksum2 = this->checksum2;
    *cksum3 = this->checksum3;
    return 1;
}
""".lstrip())

write("004700B0_new_attribute_num", r"""
class RGE_Player_nan {
public:
    void new_attribute_num(short attrib, float value);
    char gap_00[0x4C];
    short num_attributes;
    char gap_4E[0x02];
    float* attributes;
};

void RGE_Player_nan::new_attribute_num(short attrib, float value) {
    if (attrib < 0) return;
    if (attrib >= this->num_attributes) return;
    this->attributes[(int)attrib] = value;
}
""".lstrip())

write("004700D0_add_attribute_num", r"""
class RGE_Player_aan {
public:
    void add_attribute_num(short attrib, float value, int unused);
    char gap_00[0x4C];
    short num_attributes;
    char gap_4E[0x02];
    float* attributes;
};

void RGE_Player_aan::add_attribute_num(short attrib, float value, int unused) {
    if (attrib < 0) return;
    if (attrib >= this->num_attributes) return;
    this->attributes[(int)attrib] += value;
}
""".lstrip())

write("00470180_update_dopplegangers", r"""
class RGE_Doppleganger_Creator_ud {
public:
    void update(void);
};
extern RGE_Doppleganger_Creator_ud* DAT_0062e660;

class RGE_Object_List_ud {
public:
    void poll_objects(void);
};

class RGE_Visible_Map_ud {
public:
    void update_visible(void);
};

class RGE_Player_ud {
public:
    void update_dopplegangers(void);
    char gap_00[0x30];
    RGE_Object_List_ud* doppleganger_list;
    char gap_34[0x0C];
    RGE_Visible_Map_ud* visible_map;
};

void RGE_Player_ud::update_dopplegangers(void) {
    if (DAT_0062e660)
        DAT_0062e660->update();
    this->doppleganger_list->poll_objects();
    this->visible_map->update_visible();
}
""".lstrip())

write("004714C0_unselect_area", r"""
class RGE_Player_ua {
public:
    void unselect_area(void);
    char gap_00[0x120];
    short sel_x1;
    short sel_y1;
    short sel_x2;
    short sel_y2;
};

void RGE_Player_ua::unselect_area(void) {
    this->sel_x1 = -1;
    this->sel_y1 = -1;
    this->sel_x2 = -1;
    this->sel_y2 = -1;
}
""".lstrip())

write("004714E0_ungroup_objects", r"""
class RGE_Static_Object_uo {
public:
    char gap_00[0x37];
    unsigned char group_id;
};

class RGE_Player_uo {
public:
    void ungroup_objects(void);
    char gap_00[0x134];
    RGE_Static_Object_uo* selected_objects[25];
    char gap_198[0x04];
    short num_selected;
};

void RGE_Player_uo::ungroup_objects(void) {
    int count = 0;
    int i = 0;
    while (count < (int)this->num_selected) {
        if (i >= 25) break;
        RGE_Static_Object_uo* obj = this->selected_objects[i];
        if (obj != 0) {
            count++;
            obj->group_id = 0;
        }
        i++;
    }
}
""".lstrip())

write("004719D0_command_create_group", r"""
class RGE_Command_ccg {
public:
    void command_create_group(int player, int a, int b, int c, int d);
};

class RGE_Game_World_ccg {
public:
    char gap_00[0x58];
    RGE_Command_ccg* command;
};

class RGE_Player_ccg {
public:
    unsigned char command_create_group(int a, int b, int c, int d);
    char gap_00[0x3C];
    RGE_Game_World_ccg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_ccg::command_create_group(int a, int b, int c, int d) {
    int pid = (int)this->player_id;
    this->world->command->command_create_group(pid, a, b, c, d);
    return 1;
}
""".lstrip())

write("00471A00_command_add_to_group", r"""
class RGE_Command_catg {
public:
    void command_add_to_group(int player, int a, int b, int c);
};

class RGE_Game_World_catg {
public:
    char gap_00[0x58];
    RGE_Command_catg* command;
};

class RGE_Player_catg {
public:
    unsigned char command_add_to_group(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_catg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_catg::command_add_to_group(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_add_to_group(pid, a, b, c);
    return 1;
}
""".lstrip())

write("00471A30_command_remove_from_group", r"""
class RGE_Command_crfg {
public:
    void command_remove_from_group(int player, int a, int b);
};

class RGE_Game_World_crfg {
public:
    char gap_00[0x58];
    RGE_Command_crfg* command;
};

class RGE_Player_crfg {
public:
    unsigned char command_remove_from_group(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_crfg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_crfg::command_remove_from_group(int a, int b) {
    int pid = (int)this->player_id;
    this->world->command->command_remove_from_group(pid, a, b);
    return 1;
}
""".lstrip())

write("00471A70_command_resign", r"""
class RGE_Command_cr {
public:
    void command_resign(int player, int a, int b);
};

class RGE_Game_World_cr {
public:
    char gap_00[0x58];
    RGE_Command_cr* command;
};

class RGE_Player_cr {
public:
    unsigned char command_resign(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_cr* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4C[0x34];
    unsigned char game_over;
};

unsigned char RGE_Player_cr::command_resign(int a, int b) {
    if (this->game_over) return 0;
    int pid = (int)this->player_id;
    this->world->command->command_resign(pid, a, b);
    return 1;
}
""".lstrip())

write("00471E40_RGE_Tile_List", r"""
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

class RGE_Tile_List_ctor {
public:
    RGE_Tile_List_ctor* ctor(int max_tiles);
    int max_count;
    int field_04;
    int field_08;
    int field_0C;
    void* tiles;
};

RGE_Tile_List_ctor* RGE_Tile_List_ctor::ctor(int max_tiles) {
    this->tiles = calloc(max_tiles, 8);
    this->max_count = max_tiles;
    this->field_04 = 0;
    this->field_08 = 0;
    this->field_0C = 0;
    return this;
}
""".lstrip())

# ============================================================
# Sounddrv.cpp functions
# ============================================================

write("004BC5A0_TSound_Driver", r"""
class TSound_Driver_ctor {
public:
    TSound_Driver_ctor* ctor(int device, int config);
    void init_vars(void);
    void init_system(int device, int config);
};

TSound_Driver_ctor* TSound_Driver_ctor::ctor(int device, int config) {
    this->init_vars();
    this->init_system(device, config);
    return this;
}
""".lstrip())

write("004BC980_handle_messages", r"""
void __cdecl process_sound_messages(int a, int b, int c, int d);

class TSound_Driver_hm {
public:
    int handle_messages(int a, int b, int c, int d);
    unsigned char ready;
};

int TSound_Driver_hm::handle_messages(int a, int b, int c, int d) {
    if (!this->ready) return 0;
    process_sound_messages(a, b, c, d);
    return 0;
}
""".lstrip())

write("004BC9F0_play_list", r"""
class TDigital_pl {
public:
    void play(void);
};

class TSound_Driver_pl {
public:
    void play_list(void);
    char gap_00[0x298];
    TDigital_pl* sounds[256];
    char gap_698[0x00];
    int num_sounds;
};

void TSound_Driver_pl::play_list(void) {
    int count = this->num_sounds;
    if (count <= 0) return;
    for (int i = 0; i < count; i++) {
        this->sounds[i]->play();
    }
}
""".lstrip())

write("004BCC80_TDigital", r"""
class TSound_Driver_td;

class TDigital_ctor {
public:
    TDigital_ctor* ctor(TSound_Driver_td* owner);
    void init_vars(void);
    char gap_00[0x04];
    TSound_Driver_td* parent;
    char gap_08[0x14];
    int volume;
    int pitch;
    int pan;
    int loop_flag;
};

TDigital_ctor* TDigital_ctor::ctor(TSound_Driver_td* owner) {
    this->init_vars();
    this->parent = owner;
    this->volume = *(int*)((char*)owner + 0x1C);
    this->pitch = *(int*)((char*)owner + 0x20);
    this->pan = *(int*)((char*)owner + 0x24);
    this->loop_flag = *(int*)((char*)owner + 0x28);
    return this;
}
""".lstrip())

write("004BCCC0_init_vars", r"""
class TDigital_iv {
public:
    void init_vars(void);
    int field_00;
    int field_04;
    unsigned char field_08;
    unsigned char field_09;
    unsigned char field_0A;
    char gap_0B[0x21];
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

void TDigital_iv::init_vars(void) {
    this->field_00 = 0;
    this->field_04 = 0;
    this->field_08 = 0;
    this->field_09 = 0;
    this->field_0A = 0;
    this->field_2C = 0;
    this->field_30 = 0;
    this->field_34 = 0;
    this->field_38 = 0;
    this->field_1C = 0;
    this->field_20 = 0;
    this->field_24 = 0;
    this->field_28 = 0;
}
""".lstrip())

write("004BD490_stop", r"""
struct IDirectSoundBuffer_vtbl_st {
    char gap_00[0x48];
    int (__stdcall *Stop)(void* thisptr);
};

struct IDirectSoundBuffer_st {
    IDirectSoundBuffer_vtbl_st* vtbl;
};

class TDigital_stop {
public:
    void stop(void);
    int dsound_driver;
    TDigital_stop* parent;
    unsigned char loaded;
    char gap_09[0x23];
    int field_2C;
    int field_30;
    IDirectSoundBuffer_st* buffer;
};

void TDigital_stop::stop(void) {
    TDigital_stop* p = this;
    while (p->parent)
        p = p->parent;
    if (!p->dsound_driver) return;
    if (!*(unsigned char*)p->dsound_driver) return;
    if (!p->loaded) return;
    if (!p->buffer) return;
    p->buffer->vtbl->Stop(p->buffer);
}
""".lstrip())

write("004BD4E0_set_volume", r"""
struct IDirectSoundBuffer_vtbl_sv {
    char gap_00[0x3C];
    int (__stdcall *SetVolume)(void* thisptr, int volume);
};

struct IDirectSoundBuffer_sv {
    IDirectSoundBuffer_vtbl_sv* vtbl;
};

class TDigital_sv {
public:
    void set_volume(int volume);
    int dsound_driver;
    TDigital_sv* parent;
    unsigned char loaded;
    char gap_09[0x13];
    int volume_field;
    char gap_20[0x14];
    IDirectSoundBuffer_sv* buffer;
};

void TDigital_sv::set_volume(int volume) {
    TDigital_sv* p = this->parent;
    this->volume_field = volume;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetVolume(p->buffer, volume);
}
""".lstrip())

write("004BD510_set_pitch", r"""
struct IDirectSoundBuffer_vtbl_sp {
    char gap_00[0x44];
    int (__stdcall *SetFrequency)(void* thisptr, int freq);
};

struct IDirectSoundBuffer_sp {
    IDirectSoundBuffer_vtbl_sp* vtbl;
};

class TDigital_sp {
public:
    void set_pitch(int freq);
    int dsound_driver;
    TDigital_sp* parent;
    unsigned char loaded;
    char gap_09[0x17];
    int pitch_field;
    char gap_24[0x10];
    IDirectSoundBuffer_sp* buffer;
};

void TDigital_sp::set_pitch(int freq) {
    TDigital_sp* p = this->parent;
    this->pitch_field = freq;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetFrequency(p->buffer, freq);
}
""".lstrip())

write("004BD540_set_pan", r"""
struct IDirectSoundBuffer_vtbl_pan {
    char gap_00[0x40];
    int (__stdcall *SetPan)(void* thisptr, int pan);
};

struct IDirectSoundBuffer_pan {
    IDirectSoundBuffer_vtbl_pan* vtbl;
};

class TDigital_pan {
public:
    void set_pan(int pan);
    int dsound_driver;
    TDigital_pan* parent;
    unsigned char loaded;
    char gap_09[0x1B];
    int pan_field;
    char gap_28[0x0C];
    IDirectSoundBuffer_pan* buffer;
};

void TDigital_pan::set_pan(int pan) {
    TDigital_pan* p = this->parent;
    this->pan_field = pan;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetPan(p->buffer, pan);
}
""".lstrip())

# ============================================================
# tplayer.cpp functions
# ============================================================

write("00512BF0_tech_cost", r"""
class Tech_Tree_tc {
public:
    void tech_cost(int a, int b, int c, int d, int e, int f, int g);
};

class TRIBE_Player_tc {
public:
    void tech_cost(int a, int b, int c, int d, int e, int f, int g);
    char gap_00[0x220];
    Tech_Tree_tc* tech_tree;
};

void TRIBE_Player_tc::tech_cost(int a, int b, int c, int d, int e, int f, int g) {
    this->tech_tree->tech_cost(a, b, c, d, e, f, g);
}
""".lstrip())

write("00513720_command_building_make_tech", r"""
class RGE_Master_Static_Object_cbmt {
public:
    char gap_00[0x04];
    unsigned char master_type;
};

class RGE_Static_Object_cbmt {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object_cbmt* master;
};

class RGE_Command_cbmt {
public:
    void command_make_tech(RGE_Static_Object_cbmt* building, int tech_id);
};

class RGE_Game_World_cbmt {
public:
    char gap_00[0x58];
    RGE_Command_cbmt* command;
};

class TRIBE_Player_cbmt {
public:
    unsigned char command_building_make_tech(int tech_id);
    char gap_00[0x3C];
    RGE_Game_World_cbmt* world;
    char gap_40[0xF0];
    RGE_Static_Object_cbmt* selected_building;
};

unsigned char TRIBE_Player_cbmt::command_building_make_tech(int tech_id) {
    RGE_Static_Object_cbmt* b = this->selected_building;
    if (!b) return 0;
    if (b->master->master_type != 0x50) return 0;
    this->world->command->command_make_tech(b, tech_id);
    return 1;
}
""".lstrip())

write("00513840_command_trade_attribute", r"""
class RGE_Command_cta {
public:
    void command_trade_attribute(int a, int player, int b);
};

class RGE_Game_World_cta {
public:
    char gap_00[0x58];
    RGE_Command_cta* command;
};

class TRIBE_Player_cta {
public:
    unsigned char command_trade_attribute(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_cta* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char TRIBE_Player_cta::command_trade_attribute(int a, int b) {
    int pid = (int)this->player_id;
    this->world->command->command_trade_attribute(a, pid, b);
    return 1;
}
""".lstrip())

write("00513920_command_building_make_obj", r"""
class RGE_Master_Static_Object_cbmo {
public:
    char gap_00[0x04];
    unsigned char master_type;
};

class RGE_Static_Object_cbmo {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object_cbmo* master;
};

class RGE_Command_cbmo {
public:
    void command_make_obj(RGE_Static_Object_cbmo* building, int obj_id);
};

class RGE_Game_World_cbmo {
public:
    char gap_00[0x58];
    RGE_Command_cbmo* command;
};

class TRIBE_Player_cbmo {
public:
    unsigned char command_building_make_obj(int obj_id);
    char gap_00[0x3C];
    RGE_Game_World_cbmo* world;
    char gap_40[0xF0];
    RGE_Static_Object_cbmo* selected_building;
};

unsigned char TRIBE_Player_cbmo::command_building_make_obj(int obj_id) {
    RGE_Static_Object_cbmo* b = this->selected_building;
    if (!b) return 0;
    if (b->master->master_type != 0x50) return 0;
    this->world->command->command_make_obj(b, obj_id);
    return 1;
}
""".lstrip())

write("00513DA0_tech_abling", r"""
class Tech_Tree_tab {
public:
    void enable_tech(int tech_id);
    void disable_tech(int tech_id);
};

class TRIBE_Player_tab {
public:
    void tech_abling(int tech_id, unsigned char enable);
    char gap_00[0x220];
    Tech_Tree_tab* tech_tree;
};

void TRIBE_Player_tab::tech_abling(int tech_id, unsigned char enable) {
    if (enable) {
        this->tech_tree->enable_tech(tech_id);
    } else {
        this->tech_tree->disable_tech(tech_id);
    }
}
""".lstrip())

write("00514660_objectAvailable", r"""
class RGE_Master_Static_Object_oa {
public:
    char gap_00[0x52];
    unsigned char available;
};

class TRIBE_Player_oa {
public:
    int objectAvailable(int obj_id);
    char gap_00[0x24];
    RGE_Master_Static_Object_oa** master_objects;
};

int TRIBE_Player_oa::objectAvailable(int obj_id) {
    RGE_Master_Static_Object_oa* m = this->master_objects[obj_id];
    if (m && m->available)
        return 1;
    if (obj_id == 0x6D)
        return 1;
    return 0;
}
""".lstrip())

write("005146B0_researchEverAvailable", r"""
class Tech_Tree_rea {
public:
    short get_state(int tech_id);
};

class TRIBE_Player_rea {
public:
    int researchEverAvailable(int tech_id);
    char gap_00[0x220];
    Tech_Tree_rea* tech_tree;
};

int TRIBE_Player_rea::researchEverAvailable(int tech_id) {
    short state = this->tech_tree->get_state(tech_id);
    if (state == 3) return 0;
    if (state == (short)0xFFFF) return 0;
    return 1;
}
""".lstrip())

write("00514FB0_strategicNumber", r"""
class StrategyAIModule_sn {
public:
    int strategicNumber(int index);
};

class AIModule_sn {
public:
    char gap_00[0x1146C];
    StrategyAIModule_sn strategy;
};

class TRIBE_Player_sn {
public:
    int strategicNumber(int index);
    char gap_00[0x238];
    AIModule_sn* ai_module;
};

int TRIBE_Player_sn::strategicNumber(int index) {
    if (!this->ai_module) return -1;
    return ((StrategyAIModule_sn*)((char*)this->ai_module + 0x1146C))->strategicNumber(index);
}
""".lstrip())

write("00515040_sendAICommand", r"""
class AIModule_sac {
public:
    int sendCommand(int a, int b, int c, int d, int e);
};

class TRIBE_Player_sac {
public:
    int sendAICommand(int a, int b, int c, int d, int e);
    char gap_00[0x238];
    AIModule_sac* ai_module;
};

int TRIBE_Player_sac::sendAICommand(int a, int b, int c, int d, int e) {
    if (!this->ai_module) return 0;
    return this->ai_module->sendCommand(a, b, c, d, e);
}
""".lstrip())

write("005151C0_registerBuild", r"""
class BuildAIModule_rb {
public:
    void registerBuild(int a, int b);
};

class AIModule_rb {
public:
    char gap_00[0x104];
    BuildAIModule_rb build_ai;
};

class TRIBE_Player_rb {
public:
    void registerBuild(int a, int b);
    char gap_00[0x238];
    AIModule_rb* ai_module;
};

void TRIBE_Player_rb::registerBuild(int a, int b) {
    if (!this->ai_module) return;
    ((BuildAIModule_rb*)((char*)this->ai_module + 0x104))->registerBuild(a, b);
}
""".lstrip())

write("005151F0_trainUnit", r"""
class RGE_Command_tu {
public:
    void command_make(int player, int a, int b, int c);
};

class RGE_Game_World_tu {
public:
    char gap_00[0x58];
    RGE_Command_tu* command;
};

class TRIBE_Player_tu {
public:
    void trainUnit(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_tu* world;
    char gap_40[0x0A];
    short player_id;
};

void TRIBE_Player_tu::trainUnit(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_make(pid, a, b, c);
}
""".lstrip())

write("00515220_cancelTrain", r"""
class BuildAIModule_ct {
public:
    void cancelTrain(int a, int b, int c, int d);
};

class AIModule_ct {
public:
    char gap_00[0x104];
    BuildAIModule_ct build_ai;
};

class TRIBE_Player_ct {
public:
    void cancelTrain(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_ct* ai_module;
};

void TRIBE_Player_ct::cancelTrain(int a, int b, int c, int d) {
    if (!this->ai_module) return;
    ((BuildAIModule_ct*)((char*)this->ai_module + 0x104))->cancelTrain(a, a, b, c);
}
""".lstrip())

write("00515250_registerTrain", r"""
class BuildAIModule_rt {
public:
    void registerTrain(int a, int b, int c, int d);
};

class AIModule_rt {
public:
    char gap_00[0x104];
    BuildAIModule_rt build_ai;
};

class TRIBE_Player_rt {
public:
    void registerTrain(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_rt* ai_module;
};

void TRIBE_Player_rt::registerTrain(int a, int b, int c, int d) {
    if (!this->ai_module) return;
    ((BuildAIModule_rt*)((char*)this->ai_module + 0x104))->registerTrain(a, a, b, c);
}
""".lstrip())

write("00515280_research", r"""
class RGE_Command_rsr {
public:
    void command_research(int player, int a, int b, int c);
};

class RGE_Game_World_rsr {
public:
    char gap_00[0x58];
    RGE_Command_rsr* command;
};

class TRIBE_Player_rsr {
public:
    void research(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_rsr* world;
    char gap_40[0x0A];
    short player_id;
};

void TRIBE_Player_rsr::research(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_research(pid, a, b, c);
}
""".lstrip())

write("005152B0_cancelResearch", r"""
class BuildAIModule_crs {
public:
    void cancelResearch(int a, int b, int c, int d);
};

class AIModule_crs {
public:
    char gap_00[0x104];
    BuildAIModule_crs build_ai;
};

class TRIBE_Player_crs {
public:
    void cancelResearch(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_crs* ai_module;
};

void TRIBE_Player_crs::cancelResearch(int a, int b, int c, int d) {
    if (!this->ai_module) return;
    ((BuildAIModule_crs*)((char*)this->ai_module + 0x104))->cancelResearch(a, a, b, c);
}
""".lstrip())

write("005152E0_registerResearch", r"""
class BuildAIModule_rrs {
public:
    void registerResearch(int a, int b, int c);
};

class AIModule_rrs {
public:
    char gap_00[0x104];
    BuildAIModule_rrs build_ai;
};

class TRIBE_Player_rrs {
public:
    void registerResearch(int a, int b, int c);
    char gap_00[0x238];
    AIModule_rrs* ai_module;
};

void TRIBE_Player_rrs::registerResearch(int a, int b, int c) {
    if (!this->ai_module) return;
    ((BuildAIModule_rrs*)((char*)this->ai_module + 0x104))->registerResearch(a, b, c);
}
""".lstrip())

write("005192F0_trackUnitGather", r"""
class TacticalAIModule_tug {
public:
    void trackUnitGather(int a, int b, int c);
};

class AIModule_tug {
public:
    char gap_00[0x1146C];
    TacticalAIModule_tug tactical;
};

class TRIBE_Player_tug {
public:
    void trackUnitGather(int a, int b, int c);
    char gap_00[0x238];
    AIModule_tug* ai_module;
};

void TRIBE_Player_tug::trackUnitGather(int a, int b, int c) {
    if (!this->ai_module) return;
    ((TacticalAIModule_tug*)((char*)this->ai_module + 0x1146C))->trackUnitGather(a, b, c);
}
""".lstrip())

write("00519D10_load_master_object", r"""
int __stdcall TRIBE_Player_load_master_object_impl(int a, int b, int c, int d, int e);

class TRIBE_Player_lmo {
public:
    int load_master_object(int a, int b, int c, int d, int e);
};

int TRIBE_Player_lmo::load_master_object(int a, int b, int c, int d, int e) {
    return TRIBE_Player_load_master_object_impl(a, b, c, d, e);
}
""".lstrip())

print("All 83 files created.")
