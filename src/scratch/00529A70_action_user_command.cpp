// 00529A70 TRIBE_Game::action_user_command
// tribegam.cpp
// Attempt log:
// try 1: broad reconstruction from packet: /GX framed user command dispatch, quit/wait-screen commands, chat/taunt/create-message paths, observe/view selection commands.
// try 2: modeled /GX EH frame and two 256-byte local buffers msg/temp.
// try 3: modeled gameMode==3 command switch around 0x17A8..0x17B7 with quit/destroyPanel/currentPanel send paths.
// try 4: modeled gameMode 4/5/6 gate and second command switch around 0x17A2..0x17B0.
// try 5: modeled status/current-player update path for 0x17A2 including update_ui and current-panel send.
// try 6: modeled chat/message creation path: chat_mode, clear/popup, globals 0x62C560/0x62C564, Dialog new, panel send, sounds, sprintf/build_message, panel destroy.
// try 7: modeled chat previous/next/send text paths and selected-player observe path with temp string and log.
// try 8: fixed compile issues: removed explicit operator new declaration, avoided __thiscall cast, corrected stub padding, and split invalid comma/! expression.
// try 9: /GX and default both compile to .text 1072B vs original 1135B; /GX retained because original has EH registration/local object state.
// try 10: reviewed missing size: exact switch table density, dialog constructor/new EH shape, panel-system call surface, sound/global branches, and selected-player name/log sequence.
// try 11: current source remains size-short by 63B and no full diff is available.
// left in scratch: broad behavior is modeled but command-switch topology, dialog/EH local-object shape, panel-system call ordering, and selected-player message path are incomplete. No accepted_drift: no localized full diff.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void __cdecl Log(void*, const char*, ...);
extern void* L;
extern int g_in_message;
extern int g_in_chat;
extern int* g_seenObjects;

class Panel { public: void destroy(const char*); void* current(); void send(int,int,int,int); };
class Comm { public: int ready(); void post(int,int,int,int); };
class Chat { public: void print(const char*); void clear(const char*); void prev(); void next(); void sendText(const char*); };
class Player { public: char gap[0x40]; void** objects; char gap44[0x38]; short selected; char gap7e[0x44]; const char* name; };
class Scenario { public: char gap[0x40]; Player** players; char gap44[0x58-0x44]; void* map; };
class Dialog { public: Dialog(const char*, const char*, void*, int); };
extern Panel panel_system;
extern int sound_stop(void*);
extern void sound_update();

class TRIBE_Game {
public:
    void* vtbl; char gap04[0x18c-4]; Comm* comm; char gap190[0x1b0-0x190]; int gameMode;
    char gap1b4[0x3f4-0x1b4]; Scenario* scenario; char gap3f8[0xc24-0x3f8]; Chat* chat;
    int action_user_command(unsigned long cmd, unsigned long arg);
    void quit_game(); void close_dialog(); void set_pause(int); void chat_mode(int); void command_mode(int); void update_ui(); void popup(const char*); int getPlayerIndex(unsigned long); int getLocalPlayer(); void build_message(const char*); void show_status(int);
};

int TRIBE_Game::action_user_command(unsigned long cmd, unsigned long arg) {
    char msg[256];
    char temp[256];
    if (gameMode == 3) {
        switch (cmd) {
        case 0x17a8:
        case 0x17a9:
        case 0x17aa:
            quit_game();
            panel_system.destroy((const char*)0x586C2C);
            panel_system.destroy((const char*)0x586218);
            if (panel_system.current()) panel_system.send(0x25c9,0,0x1c2,100);
            return 1;
        case 0x17b7:
        case 0x17ac:
            close_dialog();
            set_pause(1);
            quit_game();
            panel_system.destroy((const char*)0x586C2C);
            panel_system.destroy((const char*)0x586218);
            if (panel_system.current()) panel_system.send(0x25c9,0,0x1c2,100);
            return 1;
        default: return 1;
        }
    }
    if (gameMode != 4 && gameMode != 5 && gameMode != 6) return 1;
    switch (cmd) {
    case 0x17a2:
        if (!chat) return 1;
        scenario->players[scenario->players[0]->selected]->objects[0];
        update_ui();
        if (panel_system.current()) panel_system.send(0x25c9,0,0x1c2,100);
        return 1;
    case 0x17a4:
        if (chat) { chat_mode(2); chat->clear((const char*)0x58C410); }
        popup((const char*)0x58C400);
        if (g_in_message) return 1;
        if (!g_in_chat) {
            g_in_chat = 1;
            if (comm->ready()) scenario->map = 0;
            return 1;
        }
        if (!g_in_message) {
            unsigned long p = arg;
            if (!comm->ready()) return 1;
            g_in_chat = 1; g_in_message = 1;
            Dialog* d = new Dialog((const char*)0x588BD0,(const char*)0x592A40,0,-1);
            panel_system.send(0,(int)0x588BD0,0,0);
            show_status(1);
            if (L) { sound_stop(L); sound_update(); }
            sprintf(msg,(const char*)0x588BC0,comm->ready());
            build_message(msg);
            update_ui();
            if (panel_system.current()) panel_system.send(0x966,0,0x1c2,100);
            panel_system.destroy((const char*)0x588BD0);
        }
        return 1;
    case 0x17a5: if (chat) chat->prev(); return 1;
    case 0x17a6: if (chat) chat->next(); return 1;
    case 0x17a7: if (chat) { chat_mode(2); chat->sendText((const char*)arg); } return 1;
    case 0x17b0: {
        int p = getPlayerIndex(arg);
        if (p == scenario->players[0]->selected) return 1;
        if (!chat || p <= 0 || g_seenObjects[p]) return 1;
        chat_mode(2);
        ((void (*)(TRIBE_Game*,char*,int,int))(*(void***)this)[8])(this,temp,0x4c1,0x100);
        sprintf(msg,(const char*)0x58C3DC, scenario->players[p]->name);
        chat->print(msg);
        Log(L,(const char*)0x58C3DC, scenario->players[p]->name);
        return 1;
    }
    default:
        return 1;
    }
}
