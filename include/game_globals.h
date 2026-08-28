#pragma once
// Generated once by tools\generate_working_scaffold.py.
// After the first scaffold pass, this file becomes editable project source.
// Only globals with one conservative inferred type are auto-emitted here.

#include <windows.h>
#include <stdio.h>
#include "game_types.h"

class IDirectPlay3;
class ResFileHdr;
class TDebuggingLog;
class DriveInformation;
class TChat;
class TCommunications_Handler;
class TRegistry;
class TSound_Driver;

struct COMM_DEBUG_PING {
    unsigned char Command;
    unsigned char Reserved[3];
    unsigned long Timestamp;
    unsigned long Turn;
};

extern unsigned char comm_rate_initialized;
extern unsigned long comm_last_rate_update;
extern unsigned long comm_last_rx_bytes;
extern unsigned long comm_last_tx_bytes;
extern unsigned long comm_last_dump_time;
extern unsigned long comm_last_sent_time;
extern char* comm_receive_message;
extern unsigned long comm_receive_base;
extern unsigned long comm_drop_count;
extern unsigned long comm_resent_bytes;
extern unsigned long comm_resend_last_time;
extern unsigned long comm_highest_acknowledged_turn;
extern int comm_resend_min_delay;
extern int comm_resend_latency_base;
extern float comm_resend_rate_limit;
extern unsigned char comm_messages_initialized;
extern COMM_DEBUG_PING comm_debug_ping;
extern COMM_DEBUG_PING comm_ping_packet;
extern unsigned char guid_format_positions[20];
extern unsigned short guid_hex_digits[16];
extern char comm_enum_buffer[0x100];
extern char comm_info_buffers[0x700];
extern char g_status_buffer[0x20];
extern unsigned long comm_ping_sequence_turn;
extern unsigned char comm_ping_sequence;
extern char ready_player_buffer[64];
extern char ready_player_template[64];
extern char com_hand_source_path[];

// PDB type 0x18A9 names this 25-record table at 00587258.
struct TRIBE_Cliff_Higher_Check_Record {
    float from_angle1;
    float to_angle1;
    float from_angle2;
    float to_angle2;
    float line_x1;
    float line_y1;
    float line_x2;
    float line_y2;
};

typedef char tribe_cliff_higher_check_record_size_check[
    (sizeof(TRIBE_Cliff_Higher_Check_Record) == 0x20) ? 1 : -1];

// World.cpp process globals. PDB storage and type records prove this surface.
extern long world_update_counter;
extern int computerPlayerSetup[13];
extern FILE* DVlogf;
extern int debug_random_on;
extern int debug_timeGetTime_on;
extern int debug_timeGetTime_cnt;
extern int debug_timeGetTime_time;
extern int all_cp;
extern int logStatusOn;
extern int do_fixed_update;
extern long fixed_update_time;
extern float save_game_version;
extern int allow_user_commands;

// BaseGame process globals. The executable stores these values at the named
// addresses. The types follow their direct uses in BaseGame and its clients.
extern HINSTANCE basegame_instance;
extern HMODULE StringTable;
extern TRegistry* Regs;
extern TSound_Driver* sound_driver;
extern TChat* chat;
extern TCommunications_Handler* comm;
extern DriveInformation* driveInfo;
extern HWND AppWnd;
extern RGE_Base_Game* rge_base_game;
extern int system_ignore_size_messages;
extern int basegame_is_active;
extern int MouseCursorInChildContol;
extern HWND save_active_wnd;
extern int do_restore_palette;
extern unsigned long restore_palette_timer;
extern int restore_mouse_after_paint;
extern "C" HCURSOR last_mouse_cursor;

// 0056E0B8 [.rdata]
extern float DAT_0056e0b8;
// 0056E0CC [.rdata]
extern float DAT_0056e0cc;
// 0056E0D0 [.rdata]
extern float DAT_0056e0d0;
// 0056E138 [.rdata]
extern double DAT_0056e138;
// 0056E1A0 [.rdata]
extern float DAT_0056e1a0;
// 0056E1A4 [.rdata]
extern float DAT_0056e1a4;
// 0056E1A8 [.rdata]
extern float DAT_0056e1a8;
// 0056E210 [.rdata]
extern float DAT_0056e210;
// 0056E278 [.rdata]
extern float DAT_0056e278;
// 0056E290 [.rdata]
extern double DAT_0056e290;
// 0056E318 [.rdata]
extern double DAT_0056e318;
// 0056E380 [.rdata]
extern float DAT_0056e380;
// 0056E388 [.rdata]
extern double DAT_0056e388;
// 0056E390 [.rdata]
extern float DAT_0056e390;
// 0056E394 [.rdata]
extern float DAT_0056e394;
// 0056E400 [.rdata]
extern float DAT_0056e400;
// 0056E418 [.rdata]
extern double DAT_0056e418;
// 0056E63C [.rdata]
extern float DAT_0056e63c;
// 0056E640 [.rdata]
extern float DAT_0056e640;
// 0056E644 [.rdata]
extern float DAT_0056e644;
// 0056E648 [.rdata]
extern float DAT_0056e648;
// 0056E6C0 [.rdata]
extern double DAT_0056e6c0;
// 0056E6C8 [.rdata]
extern float DAT_0056e6c8;
// 0056E6CC [.rdata]
extern float DAT_0056e6cc;
// 0056E784 [.rdata]
extern float DAT_0056e784;
// 0056E788 [.rdata]
extern float DAT_0056e788;
// 0056E80C [.rdata]
extern float DAT_0056e80c;
// 0056E810 [.rdata]
extern float DAT_0056e810;
// 0056EBB8 [.rdata]
extern float DAT_0056ebb8;
// 0056EBBC [.rdata]
extern float DAT_0056ebbc;
// 0056EBC0 [.rdata]
extern float DAT_0056ebc0;
// 0056EBC4 [.rdata]
extern float DAT_0056ebc4;
// 0056EBC8 [.rdata]
extern float DAT_0056ebc8;
// 0056EBD0 [.rdata]
extern float DAT_0056ebd0;
// 0056EBD4 [.rdata]
extern float DAT_0056ebd4;
// 0056EBD8 [.rdata]
extern float DAT_0056ebd8;
// 0056EBDC [.rdata]
extern float DAT_0056ebdc;
// 0056EBE0 [.rdata]
extern float DAT_0056ebe0;
// 0056EBE4 [.rdata]
extern float DAT_0056ebe4;
// 0056EBE8 [.rdata]
extern float DAT_0056ebe8;
// 0056EBEC [.rdata]
extern float DAT_0056ebec;
// 0056EBF4 [.rdata]
extern float DAT_0056ebf4;
// 0056EBF8 [.rdata]
extern float DAT_0056ebf8;
// 0056EC00 [.rdata]
extern double DAT_0056ec00;
// 0056EC08 [.rdata]
extern double DAT_0056ec08;
// 0056EE00 [.rdata]
extern float DAT_0056ee00;
// 0056EE78 [.rdata]
extern double DAT_0056ee78;
// 0056EE80 [.rdata]
extern float DAT_0056ee80;
// 0056EE88 [.rdata]
extern double DAT_0056ee88;
// 0056F014 [.rdata]
extern float DAT_0056f014;
// 0056F018 [.rdata]
extern float DAT_0056f018;
// 0056F020 [.rdata]
extern float DAT_0056f020;
// 0056F028 [.rdata]
extern double DAT_0056f028;
// 0056F030 [.rdata]
extern float DAT_0056f030;
// 0056F034 [.rdata]
extern float DAT_0056f034;
// 0056F210 [.rdata]
extern float DAT_0056f210;
// 0056F218 [.rdata]
extern unsigned char DAT_0056f218;
// 0056F230 [.rdata]
extern const unsigned char u_0123456789ABCDEF_0056f230[2];
// 0056F498 [.rdata]
extern float DAT_0056f498;
// 0056F49C [.rdata]
extern float DAT_0056f49c;
// 0056F4A0 [.rdata]
extern double DAT_0056f4a0;
// 0056F4A8 [.rdata]
extern float DAT_0056f4a8;
// 0056F4AC [.rdata]
extern float DAT_0056f4ac;
// 0056F4B0 [.rdata]
extern double DAT_0056f4b0;
// 0056F4B8 [.rdata]
extern float DAT_0056f4b8;
// 0056F4BC [.rdata]
extern float DAT_0056f4bc;
// 0056F4D8 [.rdata]
extern double DAT_0056f4d8;
// 0056F4E0 [.rdata]
extern double DAT_0056f4e0;
// 0056F4E8 [.rdata]
extern float DAT_0056f4e8;
// 0056F4F4 [.rdata]
extern float DAT_0056f4f4;
// 0056F4F8 [.rdata]
extern float DAT_0056f4f8;
// 0056F4FC [.rdata]
extern float DAT_0056f4fc;
// 0056F500 [.rdata]
extern float DAT_0056f500;
// 0056F5FC [.rdata]
extern float DAT_0056f5fc;
// 0056F604 [.rdata]
extern float DAT_0056f604;
// 0056F608 [.rdata]
extern float DAT_0056f608;
// 0056F740 [.rdata]
extern float DAT_0056f740;
// 0056F744 [.rdata]
extern float DAT_0056f744;
// 0056F748 [.rdata]
extern float DAT_0056f748;
// 0056F74C [.rdata]
extern float DAT_0056f74c;
// 0056F880 [.rdata]
extern float DAT_0056f880;
// 0056F884 [.rdata]
extern float DAT_0056f884;
// 0056F888 [.rdata]
extern double DAT_0056f888;
// 0056F890 [.rdata]
extern float DAT_0056f890;
// 0056F894 [.rdata]
extern float DAT_0056f894;
// 00570418 [.rdata]
extern float DAT_00570418;
// 00570440 [.rdata]
extern float DAT_00570440;
// 00570484 [.rdata]
extern float DAT_00570484;
// 00570500 [.rdata]
extern float DAT_00570500;
// 00570504 [.rdata]
extern float DAT_00570504;
// 00570508 [.rdata]
extern double DAT_00570508;
// 00570510 [.rdata]
extern double DAT_00570510;
// 00570518 [.rdata]
extern float DAT_00570518;
// 00570610 [.rdata]
extern float DAT_00570610;
// 00570614 [.rdata]
extern float DAT_00570614;
// 00570618 [.rdata]
extern float DAT_00570618;
// 0057061C [.rdata]
extern float DAT_0057061c;
// 00570620 [.rdata]
extern double DAT_00570620;
// 00570628 [.rdata]
extern float DAT_00570628;
// 0057062C [.rdata]
extern float DAT_0057062c;
// 00570630 [.rdata]
extern float DAT_00570630;
// 00570634 [.rdata]
extern float DAT_00570634;
// 00570638 [.rdata]
extern double DAT_00570638;
// 00570648 [.rdata]
extern double DAT_00570648;
// 00570654 [.rdata]
extern unsigned int DAT_00570654;
// 0057065C [.rdata]
extern unsigned int DAT_0057065c;
// 00570664 [.rdata]
extern unsigned int DAT_00570664;
// 0057066C [.rdata]
extern unsigned int DAT_0057066c;
// 005706A8 [.rdata]
extern float DAT_005706a8;
// 005706AC [.rdata]
extern float DAT_005706ac;
// 005706B0 [.rdata]
extern float DAT_005706b0;
// 005706B4 [.rdata]
extern float DAT_005706b4;
// 005706C0 [.rdata]
extern double DAT_005706c0;
// 005706D0 [.rdata]
extern double DAT_005706d0;
// 005706D8 [.rdata]
extern double DAT_005706d8;
// 005706E8 [.rdata]
extern float DAT_005706e8;
// 005706EC [.rdata]
extern float DAT_005706ec;
// 00570930 [.rdata]
extern float DAT_00570930;
// 00570934 [.rdata]
extern float DAT_00570934;
// 00570938 [.rdata]
extern float DAT_00570938;
// 0057093C [.rdata]
extern float DAT_0057093c;
// 00570940 [.rdata]
extern float DAT_00570940;
// 00570B40 [.rdata]
extern double DAT_00570b40;
// 00570B48 [.rdata]
extern float DAT_00570b48;
// 00570B4C [.rdata]
extern float DAT_00570b4c;
// 00570B50 [.rdata]
extern float DAT_00570b50;
// 00570B54 [.rdata]
extern float DAT_00570b54;
// 00570B58 [.rdata]
extern float DAT_00570b58;
// 00570B5C [.rdata]
extern float DAT_00570b5c;
// 00570B60 [.rdata]
extern float DAT_00570b60;
// 00570B64 [.rdata]
extern float DAT_00570b64;
// 00570B68 [.rdata]
extern double DAT_00570b68;
// 00570B70 [.rdata]
extern double DAT_00570b70;
// 00570B78 [.rdata]
extern float DAT_00570b78;
// 00570B7C [.rdata]
extern float DAT_00570b7c;
// 00570B80 [.rdata]
extern float DAT_00570b80;
// 00570B84 [.rdata]
extern float DAT_00570b84;
// 00570B88 [.rdata]
extern float DAT_00570b88;
// 00570B90 [.rdata]
extern double DAT_00570b90;
// 00570B98 [.rdata]
extern double DAT_00570b98;
// 00570BA0 [.rdata]
extern float DAT_00570ba0;
// 00570BA8 [.rdata]
extern float DAT_00570ba8;
// 00570BB0 [.rdata]
extern double DAT_00570bb0;
// 00570BB8 [.rdata]
extern double DAT_00570bb8;
// 00570BC0 [.rdata]
extern float DAT_00570bc0;
// 00570BC8 [.rdata]
extern double DAT_00570bc8;
// 00570BD0 [.rdata]
extern double DAT_00570bd0;
// 00570BD8 [.rdata]
extern float DAT_00570bd8;
// 00570BE0 [.rdata]
extern double DAT_00570be0;
// 00570BF0 [.rdata]
extern double DAT_00570bf0;
// 00570BFC [.rdata]
extern float DAT_00570bfc;
// 00570C00 [.rdata]
extern double DAT_00570c00;
// 00570C20 [.rdata]
extern float DAT_00570c20;
// 00570C24 [.rdata]
extern float DAT_00570c24;
// 00570C28 [.rdata]
extern float DAT_00570c28;
// 00570C30 [.rdata]
extern float DAT_00570c30;
// 00570E40 [.rdata]
extern float DAT_00570e40;
// 00570E48 [.rdata]
extern float DAT_00570e48;
// 00570E4C [.rdata]
extern float DAT_00570e4c;
// 00570E50 [.rdata]
extern float DAT_00570e50;
// 00570E54 [.rdata]
extern float DAT_00570e54;
// 00570E58 [.rdata]
extern float DAT_00570e58;
// 00570E5C [.rdata]
extern float DAT_00570e5c;
// 00570E60 [.rdata]
extern float DAT_00570e60;
// 00570E64 [.rdata]
extern float DAT_00570e64;
// 00570E68 [.rdata]
extern float DAT_00570e68;
// 00570E6C [.rdata]
extern float DAT_00570e6c;
// 00570E70 [.rdata]
extern float DAT_00570e70;
// 00570E74 [.rdata]
extern float DAT_00570e74;
// 00570E78 [.rdata]
extern double DAT_00570e78;
// 00570E80 [.rdata]
extern double DAT_00570e80;
// 00570E88 [.rdata]
extern float DAT_00570e88;
// 00570E90 [.rdata]
extern float DAT_00570e90;
// 00570E98 [.rdata]
extern double DAT_00570e98;
// 00570EA0 [.rdata]
extern double DAT_00570ea0;
// 00570EA8 [.rdata]
extern double DAT_00570ea8;
// 00570EB0 [.rdata]
extern double DAT_00570eb0;
// 00570EB8 [.rdata]
extern double DAT_00570eb8;
// 00570EC0 [.rdata]
extern float DAT_00570ec0;
// 00570EC4 [.rdata]
extern float DAT_00570ec4;
// 00570EC8 [.rdata]
extern float DAT_00570ec8;
// 00571CE8 [.rdata]
extern float DAT_00571ce8;
// 00571E4C [.rdata]
extern float DAT_00571e4c;
// 00571E50 [.rdata]
extern float DAT_00571e50;
// 00571E54 [.rdata]
extern float DAT_00571e54;
// 00571E58 [.rdata]
extern float DAT_00571e58;
// 00571E5C [.rdata]
extern float DAT_00571e5c;
// 00571E60 [.rdata]
extern float DAT_00571e60;
// 00571E70 [.rdata]
extern double DAT_00571e70;
// 00571E78 [.rdata]
extern double DAT_00571e78;
// 00571E80 [.rdata]
extern double DAT_00571e80;
// 00571EA8 [.rdata]
extern float DAT_00571ea8;
// 00571EAC [.rdata]
extern float DAT_00571eac;
// 00571EB0 [.rdata]
extern double DAT_00571eb0;
// 00571EB8 [.rdata]
extern double DAT_00571eb8;
// 00571EC0 [.rdata]
extern float DAT_00571ec0;
// 00571ED0 [.rdata]
extern double DAT_00571ed0;
// 00571EDC [.rdata]
extern float DAT_00571edc;
// 00571F20 [.rdata]
extern double DAT_00571f20;
// 00571F28 [.rdata]
extern float DAT_00571f28;
// 00571F30 [.rdata]
extern double DAT_00571f30;
// 00571F38 [.rdata]
extern double DAT_00571f38;
// 00571F40 [.rdata]
extern double DAT_00571f40;
// 00571F48 [.rdata]
extern float DAT_00571f48;
// 00571F4C [.rdata]
extern float DAT_00571f4c;
// 00571F50 [.rdata]
extern float DAT_00571f50;
// 00571F54 [.rdata]
extern float DAT_00571f54;
// 00572138 [.rdata]
extern float DAT_00572138;
// 00572140 [.rdata]
extern double DAT_00572140;
// 00572148 [.rdata]
extern double DAT_00572148;
// 00572150 [.rdata]
extern double DAT_00572150;
// 00572158 [.rdata]
extern float DAT_00572158;
// 00572160 [.rdata]
extern double DAT_00572160;
// 00572168 [.rdata]
extern double DAT_00572168;
// 00572170 [.rdata]
extern double DAT_00572170;
// 00572178 [.rdata]
extern float DAT_00572178;
// 0057217C [.rdata]
extern float DAT_0057217c;
// 00572968 [.rdata]
extern float DAT_00572968;
// 00572970 [.rdata]
extern double DAT_00572970;
// 00572978 [.rdata]
extern float DAT_00572978;
// 0057297C [.rdata]
extern float DAT_0057297c;
// 00572CE0 [.rdata]
extern float DAT_00572ce0;
// 00572CE4 [.rdata]
extern float DAT_00572ce4;
// 00572CE8 [.rdata]
extern float DAT_00572ce8;
// 00572CEC [.rdata]
extern float DAT_00572cec;
// 00572CF0 [.rdata]
extern float DAT_00572cf0;
// 00572CF4 [.rdata]
extern float DAT_00572cf4;
// 00572CF8 [.rdata]
extern float DAT_00572cf8;
// 00573AE8 [.rdata]
extern float DAT_00573ae8;
// 00573AEC [.rdata]
extern float DAT_00573aec;
// 00573AF0 [.rdata]
extern float DAT_00573af0;
// 00573AF8 [.rdata]
extern double DAT_00573af8;
// 00574524 [.rdata]
extern float DAT_00574524;
// 00574528 [.rdata] double zero used by RGE_Sprite::update.
extern double DAT_00574528;
// 00574718 [.rdata]
extern double DAT_00574718;
// 00574724 [.rdata]
extern float DAT_00574724;
// 00574728 [.rdata]
extern float DAT_00574728;
// 0057472C [.rdata]
extern float DAT_0057472c;
// 00574730 [.rdata]
extern float DAT_00574730;
// 00574734 [.rdata]
extern float DAT_00574734;
// 00574738 [.rdata]
extern float DAT_00574738;
// 0057473C [.rdata]
extern float DAT_0057473c;
// 00574740 [.rdata]
extern float DAT_00574740;
// 00574744 [.rdata]
extern float DAT_00574744;
// 00574748 [.rdata]
extern float DAT_00574748;
// 0057474C [.rdata]
extern float DAT_0057474c;
// 00574750 [.rdata]
extern float DAT_00574750;
// 00574758 [.rdata]
extern double DAT_00574758;
// 00574764 [.rdata]
extern float DAT_00574764;
// 00574768 [.rdata]
extern float DAT_00574768;
// 0057476C [.rdata]
extern float DAT_0057476c;
// 00574770 [.rdata]
extern float DAT_00574770;
// 00574774 [.rdata]
extern float DAT_00574774;
// 005749E0 [.rdata]
extern float DAT_005749e0;
// 005749E8 [.rdata]
extern double DAT_005749e8;
// 005749F0 [.rdata]
extern float DAT_005749f0;
// 005749F4 [.rdata]
extern float DAT_005749f4;
// 005749F8 [.rdata]
extern double DAT_005749f8;
// 00574A00 [.rdata]
extern double DAT_00574a00;
// 00574A08 [.rdata]
extern float DAT_00574a08;
// 00574A0C [.rdata]
extern float DAT_00574a0c;
// 00574A10 [.rdata]
extern double DAT_00574a10;
// 00574A18 [.rdata]
extern float DAT_00574a18;
// 00574C78 [.rdata]
extern float DAT_00574c78;
// 00574C7C [.rdata]
extern float DAT_00574c7c;
// 00574C80 [.rdata]
extern float DAT_00574c80;
// 00574C88 [.rdata]
extern double DAT_00574c88;
// 00574C90 [.rdata]
extern float DAT_00574c90;
// 00574C94 [.rdata]
extern float DAT_00574c94;
// 00574C98 [.rdata]
extern float DAT_00574c98;
// 00574C9C [.rdata]
extern float DAT_00574c9c;
// 00574CA0 [.rdata]
extern float DAT_00574ca0;
// 00574CA4 [.rdata]
extern float DAT_00574ca4;
// 00574CA8 [.rdata]
extern double DAT_00574ca8;
// 00574F08 [.rdata]
extern double DAT_00574f08;
// 00574F14 [.rdata]
extern float DAT_00574f14;
// 00574F78 [.rdata]
extern float DAT_00574f78;
// 00574FF0 [.rdata]
extern double DAT_00574ff0;
// 00574FF8 [.rdata]
extern float DAT_00574ff8;
// 00574FFC [.rdata]
extern float DAT_00574ffc;
// 00575000 [.rdata]
extern float DAT_00575000;
// 00575004 [.rdata]
extern float DAT_00575004;
// 00575070 [.rdata]
extern double DAT_00575070;
// 0057507C [.rdata]
extern float DAT_0057507c;
// 005750E0 [.rdata]
extern float DAT_005750e0;
// 005750E8 [.rdata]
extern double DAT_005750e8;
// 00575150 [.rdata]
extern float DAT_00575150;
// 00575168 [.rdata]
extern double DAT_00575168;
// 0057518C [.rdata]
extern float DAT_0057518c;
// 00575190 [.rdata]
extern float DAT_00575190;
// 00575198 [.rdata]
extern float DAT_00575198;
// 0057519C [.rdata]
extern float DAT_0057519c;
// 005751A0 [.rdata]
extern float DAT_005751a0;
// 00575268 [.rdata]
extern float DAT_00575268;
// 0057526C [.rdata]
extern float DAT_0057526c;
// 00575270 [.rdata]
extern double DAT_00575270;
// 00575278 [.rdata]
extern float DAT_00575278;
// 0057527C [.rdata]
extern float DAT_0057527c;
// 00575348 [.rdata]
extern float DAT_00575348;
// 00575358 [.rdata]
extern float DAT_00575358;
// 0057535C [.rdata]
extern float DAT_0057535c;
// 00575360 [.rdata]
extern float DAT_00575360;
// 00575368 [.rdata]
extern double DAT_00575368;
// 00575370 [.rdata]
extern float DAT_00575370;
// 005753D8 [.rdata]
extern float DAT_005753d8;
// 0057548C [.rdata]
extern float DAT_0057548c;
// 00575490 [.rdata]
extern float DAT_00575490;
// 00575494 [.rdata]
extern float DAT_00575494;
// 00575498 [.rdata]
extern float DAT_00575498;
// 00575550 [.rdata]
extern float DAT_00575550;
// 00575554 [.rdata]
extern float DAT_00575554;
// 00575558 [.rdata]
extern float DAT_00575558;
// 0057555C [.rdata]
extern float DAT_0057555c;
// 00575560 [.rdata]
extern float DAT_00575560;
// 00575564 [.rdata]
extern float DAT_00575564;
// 00575568 [.rdata]
extern float DAT_00575568;
// 0057556C [.rdata]
extern float DAT_0057556c;
// 00575570 [.rdata]
extern float DAT_00575570;
// 00575574 [.rdata]
extern float DAT_00575574;
// 00575578 [.rdata]
extern float DAT_00575578;
// 0057557C [.rdata]
extern float DAT_0057557c;
// 00575580 [.rdata]
extern float DAT_00575580;
// 00575584 [.rdata]
extern float DAT_00575584;
// 00575588 [.rdata]
extern float DAT_00575588;
// 0057558C [.rdata]
extern float DAT_0057558c;
// 00575590 [.rdata]
extern float DAT_00575590;
// 00575594 [.rdata]
extern float DAT_00575594;
// 00575598 [.rdata]
extern double DAT_00575598;
// 005755A0 [.rdata]
extern double DAT_005755a0;
// 005755A8 [.rdata]
extern double DAT_005755a8;
// 005755B0 [.rdata]
extern float DAT_005755b0;
// 005755B4 [.rdata]
extern float DAT_005755b4;
// 005755B8 [.rdata]
extern float DAT_005755b8;
// 005755BC [.rdata]
extern float DAT_005755bc;
// 005755C0 [.rdata]
extern float DAT_005755c0;
// 00575618 [.rdata]
extern float DAT_00575618;
// 0057561C [.rdata]
extern float DAT_0057561c;
// 00575634 [.rdata]
extern float DAT_00575634;
// 00575690 [.rdata]
extern float DAT_00575690;
// 005756E0 [.rdata]
extern float DAT_005756e0;
// 005756E4 [.rdata]
extern float DAT_005756e4;
// 005756E8 [.rdata]
extern float DAT_005756e8;
// 005756EC [.rdata]
extern float DAT_005756ec;
// 005756F0 [.rdata]
extern float DAT_005756f0;
// 005756F4 [.rdata]
extern float DAT_005756f4;
// 005756F8 [.rdata]
extern float DAT_005756f8;
// 005756FC [.rdata]
extern float DAT_005756fc;
// 00575700 [.rdata]
extern float DAT_00575700;
// 00575708 [.rdata]
extern double DAT_00575708;
// 00575710 [.rdata]
extern float DAT_00575710;
// 00575714 [.rdata]
extern float DAT_00575714;
// 00575718 [.rdata]
extern float DAT_00575718;
// 0057571C [.rdata]
extern float DAT_0057571c;
// 00575720 [.rdata]
extern float DAT_00575720;
// 00575724 [.rdata]
extern float DAT_00575724;
// 00575728 [.rdata]
extern float DAT_00575728;
// 0057572C [.rdata]
extern float DAT_0057572c;
// 00575730 [.rdata]
extern float DAT_00575730;
// 00575734 [.rdata]
extern float DAT_00575734;
// 00575738 [.rdata]
extern float DAT_00575738;
// 0057573C [.rdata]
extern float DAT_0057573c;
// 00575740 [.rdata]
extern float DAT_00575740;
// 00575744 [.rdata]
extern float DAT_00575744;
// 00575748 [.rdata]
extern float DAT_00575748;
// 0057574C [.rdata]
extern float DAT_0057574c;
// 00575750 [.rdata]
extern float DAT_00575750;
// 00575754 [.rdata]
extern float DAT_00575754;
// 00575758 [.rdata]
extern float DAT_00575758;
// 0057575C [.rdata]
extern float DAT_0057575c;
// 00575760 [.rdata]
extern float DAT_00575760;
// 00575764 [.rdata]
extern float DAT_00575764;
// 00575768 [.rdata]
extern float DAT_00575768;
// 00575770 [.rdata]
extern double DAT_00575770;
// 00575778 [.rdata]
extern float DAT_00575778;
// 0057577C [.rdata]
extern float DAT_0057577c;
// 00575780 [.rdata]
extern float DAT_00575780;
// 00575784 [.rdata]
extern float DAT_00575784;
// 005758B0 [.rdata]
extern float DAT_005758b0;
// 005758B4 [.rdata]
extern float DAT_005758b4;
// 005758B8 [.rdata]
extern float DAT_005758b8;
// 005758BC [.rdata]
extern float DAT_005758bc;
// 005758C0 [.rdata]
extern float DAT_005758c0;
// 005758C4 [.rdata]
extern float DAT_005758c4;
// 005758C8 [.rdata]
extern float DAT_005758c8;
// 005758CC [.rdata]
extern float DAT_005758cc;
// 005758D0 [.rdata]
extern float DAT_005758d0;
// 005758D4 [.rdata]
extern float DAT_005758d4;
// 005758D8 [.rdata]
extern float DAT_005758d8;
// 005758DC [.rdata]
extern float DAT_005758dc;
// 005758E0 [.rdata]
extern float DAT_005758e0;
// 005758E4 [.rdata]
extern float DAT_005758e4;
// 00576540 [.rdata]
extern float DAT_00576540;
// 00576544 [.rdata]
extern float DAT_00576544;
// 00576551 [.rdata]
extern const char s_NOMUTE_00576551[7];
// 00576570 [.rdata]
extern float DAT_00576570;
// 00576574 [.rdata]
extern float DAT_00576574;
// 00576578 [.rdata]
extern double DAT_00576578;
// 005766C0 [.rdata]
extern float DAT_005766c0;
// 005766C8 [.rdata]
extern double DAT_005766c8;
// 005766D0 [.rdata]
extern float DAT_005766d0;
// 005766D8 [.rdata]
extern double DAT_005766d8;
// 005766E0 [.rdata]
extern float DAT_005766e0;
// 005766F8 [.rdata]
extern float DAT_005766f8;
// 0057677C [.rdata]
extern float DAT_0057677c;
// 00576818 [.rdata]
extern float DAT_00576818;
// 0057681C [.rdata]
extern float DAT_0057681c;
// 00576820 [.rdata]
extern float DAT_00576820;
// 00576824 [.rdata]
extern float DAT_00576824;
// 00576828 [.rdata]
extern float DAT_00576828;
// 0057682C [.rdata]
extern float DAT_0057682c;
// 00576830 [.rdata]
extern double DAT_00576830;
// 00576838 [.rdata]
extern double DAT_00576838;
// 00576840 [.rdata]
extern float DAT_00576840;
// 00576848 [.rdata]
extern double DAT_00576848;
// 00576850 [.rdata]
extern double DAT_00576850;
// 00576858 [.rdata]
extern float DAT_00576858;
// 00576860 [.rdata]
extern double DAT_00576860;
// 00576868 [.rdata]
extern float DAT_00576868;
// 0057686C [.rdata]
extern float DAT_0057686c;
// 00576D88 [.rdata]
extern float DAT_00576d88;
// 00576D8C [.rdata]
extern float DAT_00576d8c;
// 00576D98 [.rdata]
extern double DAT_00576d98;
// 00576DA0 [.rdata]
extern float DAT_00576da0;
// 00576DA4 [.rdata]
extern float DAT_00576da4;
// 00576DA8 [.rdata]
extern float DAT_00576da8;
// 00576DAC [.rdata]
extern float DAT_00576dac;
// 00576DB0 [.rdata]
extern double DAT_00576db0;
// 00576DB8 [.rdata]
extern float DAT_00576db8;
// 00576EA0 [.rdata]
extern float DAT_00576ea0;
// 005770B0 [.rdata]
extern float DAT_005770b0;
// 005770B4 [.rdata]
extern float DAT_005770b4;
// 005770B8 [.rdata]
extern float DAT_005770b8;
// 005770C0 [.rdata]
extern double DAT_005770c0;
// 005772F0 [.rdata]
extern double DAT_005772f0;
// 005772F8 [.rdata]
extern double DAT_005772f8;
// 00577318 [.rdata]
extern float DAT_00577318;
// 0057731C [.rdata]
extern float DAT_0057731c;
// 00577320 [.rdata]
extern float DAT_00577320;
// 00577324 [.rdata]
extern float DAT_00577324;
// 00577328 [.rdata]
extern float DAT_00577328;
// 0057732C [.rdata]
extern float DAT_0057732c;
// 00577330 [.rdata]
extern double DAT_00577330;
// 00577338 [.rdata]
extern float DAT_00577338;
// 0057733C [.rdata]
extern float DAT_0057733c;
// 00577450 [.rdata]
extern float DAT_00577450;
// 00577558 [.rdata]
extern float DAT_00577558;
// 00577560 [.rdata]
extern float DAT_00577560;
// 00577564 [.rdata]
extern float DAT_00577564;
// 00577568 [.rdata]
extern float DAT_00577568;
// 0057756C [.rdata]
extern float DAT_0057756c;
// 00577570 [.rdata]
extern float DAT_00577570;
// 00577574 [.rdata]
extern float DAT_00577574;
// 00577578 [.rdata]
extern float DAT_00577578;
// 00577580 [.rdata]
extern float DAT_00577580;
// 00577588 [.rdata]
extern float DAT_00577588;
// 00577590 [.rdata]
extern double DAT_00577590;
// 0057759C [.rdata]
extern float DAT_0057759c;
// 005775A0 [.rdata]
extern float DAT_005775a0;
// 005776B4 [.rdata]
extern float DAT_005776b4;
// 005776B8 [.rdata]
extern float DAT_005776b8;
// 005776BC [.rdata]
extern float DAT_005776bc;
// 005776C0 [.rdata]
extern float DAT_005776c0;
// 005776C4 [.rdata]
extern float DAT_005776c4;
// 005776C8 [.rdata]
extern float DAT_005776c8;
// 005776D0 [.rdata]
extern double DAT_005776d0;
// 005776D8 [.rdata]
extern double DAT_005776d8;
// 005776E0 [.rdata]
extern float DAT_005776e0;
// 005777E8 [.rdata]
extern float DAT_005777e8;
// 00577900 [.rdata]
extern float DAT_00577900;
// 00577904 [.rdata]
extern float DAT_00577904;
// 00577908 [.rdata]
extern float DAT_00577908;
// 00577A10 [.rdata]
extern float DAT_00577a10;
// 00577A14 [.rdata]
extern float DAT_00577a14;
// 00577A1C [.rdata]
extern float DAT_00577a1c;
// 00577A20 [.rdata]
extern double DAT_00577a20;
// 00577A30 [.rdata]
extern unsigned int DAT_00577a30;
// 00577A88 [.rdata]
extern double DAT_00577a88;
// 00577A90 [.rdata]
extern double DAT_00577a90;
// 00577B20 [.rdata]
extern double DAT_00577b20;
// 00577B28 [.rdata]
extern const char s_t_00577b28[26];
// 00577B40 [.rdata]
extern const char s_t_00577b40[2];
// 00577B58 [.rdata]
extern const char s_0_00577b58[6];
// 00577B5C [.rdata]
extern const char s_0_00577b5c[2];
// 00577BDA [.rdata]
extern const char s_nMonTueWedThuFriSat_00577bda[20];
// 00577BF2 [.rdata]
extern const char s_nFebMarAprMayJunJulAugSepOctNovD_00577bf2[35];
// 00577CD8 [.rdata]
extern double DAT_00577cd8;
// 00578010 [.rdata]
extern const char s_AN_00578010[7];
// 00578014 [.rdata]
extern const char s_AN_00578014[3];
// 00578018 [.rdata]
extern const char s_F_00578018[6];
// 0057801C [.rdata]
extern const char s_F_0057801c[2];
// 00578020 [.rdata]
extern const char s_D_00578020[6];
// 00578024 [.rdata]
extern const char s_D_00578024[2];
// 00578028 [.rdata]
extern const char s_AN_00578028[7];
// 0057802C [.rdata]
extern const char s_AN_0057802c[3];
// 0057803C [.rdata]
extern unsigned int DAT_0057803c;
// 00578084 [.rdata]
extern unsigned int DAT_00578084;
// 00578094 [.rdata]
extern unsigned int DAT_00578094;
// 0057A808 [.rdata]
extern unsigned int DAT_0057a808;
// 0057F075 [.data]
extern unsigned char DAT_0057f075;
// 0057F09D [.data]
extern unsigned char DAT_0057f09d;
// 0057F0B5 [.data]
extern unsigned char DAT_0057f0b5;
// 0057F0DD [.data]
extern const char s_oveNoSearch_0057f0dd[12];
// 0057F0ED [.data]
extern const char s_nvalidated_0057f0ed[11];
// 0057F101 [.data]
extern unsigned char DAT_0057f101;
// 0057F149 [.data]
extern unsigned char DAT_0057f149;
// 0057F299 [.data]
extern unsigned char DAT_0057f299;
// 0057F351 [.data]
extern unsigned char DAT_0057f351;
// 0057F405 [.data]
extern const char s_engeful_0057f405[8];
// 0057F411 [.data]
extern const char s_assive_0057f411[7];
// 0057F419 [.data]
extern const char s_riendly_0057f419[8];
// 0057F425 [.data]
extern const char s_efensive_0057f425[9];
// 0057F431 [.data]
extern const char s_ompassionate_0057f431[13];
// 0057F441 [.data]
extern const char s_ggressive_0057f441[10];
// 0057F509 [.data]
extern unsigned char DAT_0057f509;
// 0057F50B [.data]
extern const char s_etAliveCount_0057f50b[13];
// 0057F519 [.data]
extern unsigned char DAT_0057f519;
// 0057F51B [.data]
extern const char s_etHitPoints_0057f51b[12];
// 0057F529 [.data]
extern unsigned char DAT_0057f529;
// 0057F531 [.data]
extern unsigned char DAT_0057f531;
// 0057F539 [.data]
extern unsigned char DAT_0057f539;
// 0057F53B [.data]
extern const char s_ackSavedTarget_0057f53b[15];
// 0057F555 [.data]
extern unsigned char DAT_0057f555;
// 0057F55D [.data]
extern unsigned char DAT_0057f55d;
// 0057F55F [.data]
extern const char s_ediate_0057f55f[7];
// 0057F569 [.data]
extern unsigned char DAT_0057f569;
// 0057F56B [.data]
extern const char s_lOfGroup_0057f56b[9];
// 0057F575 [.data]
extern unsigned char DAT_0057f575;
// 0057F577 [.data]
extern const char s_thOfGroup_0057f577[10];
// 0057F585 [.data]
extern unsigned char DAT_0057f585;
// 0057F587 [.data]
extern const char s_el2EnemySighted_0057f587[16];
// 0057F599 [.data]
extern unsigned char DAT_0057f599;
// 0057F59B [.data]
extern const char s_el1EnemySighted_0057f59b[16];
// 0057F5AD [.data]
extern unsigned char DAT_0057f5ad;
// 0057F5AF [.data]
extern const char s_ageToAnyGroup_0057f5af[14];
// 0057F5C1 [.data]
extern unsigned char DAT_0057f5c1;
// 0057F5C3 [.data]
extern const char s_ageToGroup_0057f5c3[11];
// 0057F5D1 [.data]
extern unsigned char DAT_0057f5d1;
// 0057F5D3 [.data]
extern const char s_lthLost_0057f5d3[8];
// 0057F5DD [.data]
extern unsigned char DAT_0057f5dd;
// 0057F5E5 [.data]
extern unsigned char DAT_0057f5e5;
// 0057F5ED [.data]
extern unsigned char DAT_0057f5ed;
// 0057F5F5 [.data]
extern unsigned char DAT_0057f5f5;
// 0057F605 [.data]
extern unsigned char DAT_0057f605;
// 0057F60D [.data]
extern unsigned char DAT_0057f60d;
// 0057F60F [.data]
extern const char s_igger_0057f60f[6];
// 0057F62D [.data]
extern unsigned char DAT_0057f62d;
// 0057F649 [.data]
extern unsigned char DAT_0057f649;
// 0057F665 [.data]
extern unsigned char DAT_0057f665;
// 0057F66D [.data]
extern unsigned char DAT_0057f66d;
// 0057F66F [.data]
extern const char s_berGroups_0057f66f[10];
// 0057F67D [.data]
extern unsigned char DAT_0057f67d;
// 0057F67F [.data]
extern const char s_getType_0057f67f[8];
// 0057F689 [.data]
extern unsigned char DAT_0057f689;
// 0057F68B [.data]
extern const char s_getChar_0057f68b[8];
// 0057F695 [.data]
extern unsigned char DAT_0057f695;
// 0057F697 [.data]
extern const char s_elligence_0057f697[10];
// 0057F6A5 [.data]
extern unsigned char DAT_0057f6a5;
// 0057F6A7 [.data]
extern const char s_thPercentage_0057f6a7[13];
// 0057F6B5 [.data]
extern unsigned char DAT_0057f6b5;
// 0057F6B7 [.data]
extern const char s_stGroup_0057f6b7[8];
// 0057F6C1 [.data]
extern unsigned char DAT_0057f6c1;
// 0057F6C9 [.data]
extern unsigned char DAT_0057f6c9;
// 0057F6CB [.data]
extern const char s_rflow_0057f6cb[6];
// 0057F6D5 [.data]
extern unsigned char DAT_0057f6d5;
// 0057F6DD [.data]
extern unsigned char DAT_0057f6dd;
// 0057F6DF [.data]
extern const char s_Units_0057f6df[6];
// 0057F6F1 [.data]
extern unsigned char DAT_0057f6f1;
// 0057F6F3 [.data]
extern const char s_Units_0057f6f3[6];
// 0057F705 [.data]
extern unsigned char DAT_0057f705;
// 0057F707 [.data]
extern const char s_yType_0057f707[6];
// 0057F711 [.data]
extern unsigned char DAT_0057f711;
// 0057F71D [.data]
extern unsigned char DAT_0057f71d;
// 0057F721 [.data]
extern unsigned char DAT_0057f721;
// 0057F729 [.data]
extern unsigned char DAT_0057f729;
// 0057F731 [.data]
extern unsigned char DAT_0057f731;
// 0057F739 [.data]
extern unsigned char DAT_0057f739;
// 0057F73B [.data]
extern const char s_tionary_0057f73b[8];
// 00580265 [.data]
extern unsigned char DAT_00580265;
// 00580267 [.data]
extern const char s_ate_Session_00580267[12];
// 00580499 [.data]
extern const char s_ILE_NOT_FOUND_00580499[14];
// 005804B1 [.data]
extern const char s_nknow_Error_005804b1[12];
// 00582911 [.data]
extern const char s_lient_00582911[6];
// 00582981 [.data]
extern const char s_ptional_Information_00582981[20];
// 005832C0 [.data]
extern unsigned int DAT_005832c0;
// 005832C8 [.data]
extern unsigned short DAT_005832c8;
// 005832CA [.data]
extern unsigned char DAT_005832ca;
// 005837C6 [.data]
extern unsigned char DAT_005837c6;
// 005841E4 [.data]
extern unsigned char DAT_005841e4;
// 005841E5 [.data]
extern unsigned char DAT_005841e5;
// 005841E6 [.data]
extern unsigned char DAT_005841e6;
// 005841E8 [.data]
extern unsigned int DAT_005841e8;
// 00584351 [.data]
extern unsigned char DAT_00584351;
// 00584353 [.data]
extern const char s_ignDialog_00584353[10];
// 00584371 [.data]
extern unsigned char DAT_00584371;
// 00584373 [.data]
extern const char s_tartDialog_00584373[11];
// 00584395 [.data]
extern unsigned char DAT_00584395;
// 00584397 [.data]
extern const char s_tGameDialog_00584397[12];
// 005843A5 [.data]
extern unsigned char DAT_005843a5;
// 005843A7 [.data]
extern const char s_tAndLoadDialog_005843a7[15];
// 005843E5 [.data]
extern unsigned char DAT_005843e5;
// 005843E7 [.data]
extern const char s_Dialog_005843e7[8];
// 005843F1 [.data]
extern unsigned char DAT_005843f1;
// 005843F3 [.data]
extern const char s_n_Dialog_005843f3[9];
// 00584612 [.data]
extern unsigned char DAT_00584612;
// 00584A39 [.data]
extern const char s_cursors_00584a39[8];
// 00584A45 [.data]
extern const char s_alette_00584a45[7];
// 00584A4D [.data]
extern const char s_ppIcon_00584a4d[7];
// 00584EB5 [.data]
extern unsigned char DAT_00584eb5;
// 00584EB7 [.data]
extern const char s_ialog_00584eb7[6];
// 00584EC1 [.data]
extern unsigned char DAT_00584ec1;
// 00584EC3 [.data]
extern const char s_NoDialog_00584ec3[9];
// 00584ECD [.data]
extern unsigned char DAT_00584ecd;
// 00584ECF [.data]
extern const char s_NoCancelDialog_00584ecf[15];
// 00584F24 [.data]
extern unsigned int DAT_00584f24;
// 00585524 [.data]
extern unsigned int DAT_00585524;
// 0058552C [.data]
extern const char s_vawxmi_0058552c[8];
// 00585F85 [.data]
extern unsigned char DAT_00585f85;
// 00585F87 [.data]
extern const char s_rain_List_Dialog_00585f87[17];
// 00585F99 [.data]
extern unsigned char DAT_00585f99;
// 00585F9B [.data]
extern const char s_ect_List_Dialog_00585f9b[16];
// 00586089 [.data]
extern const char s_cr10_00586089[5];
// 005860D9 [.data]
extern unsigned char DAT_005860d9;
// 005860DB [.data]
extern const char s_d_Dialog_005860db[9];
// 005860E5 [.data]
extern unsigned char DAT_005860e5;
// 005860E7 [.data]
extern const char s_cel_Dialog_005860e7[11];
// 00586305 [.data]
extern const char s_gA640_00586305[6];
// 005863B5 [.data]
extern unsigned char DAT_005863b5;
// 005863B7 [.data]
extern const char s_seProgramDialog_005863b7[16];
// 00586589 [.data]
extern unsigned char DAT_00586589;
// 0058658B [.data]
extern const char s_hInfo_0058658b[6];
// 0058659D [.data]
extern unsigned char DAT_0058659d;
// 0058659F [.data]
extern const char s_turesInfo_0058659f[10];
// 005865AD [.data]
extern unsigned char DAT_005865ad;
// 005865AF [.data]
extern const char s_tInfo3_005865af[7];
// 005865C5 [.data]
extern unsigned char DAT_005865c5;
// 005865C7 [.data]
extern const char s_tInfo2_005865c7[7];
// 005865DD [.data]
extern unsigned char DAT_005865dd;
// 005865DF [.data]
extern const char s_tInfo1_005865df[7];
// 005865F5 [.data]
extern unsigned char DAT_005865f5;
// 005865F7 [.data]
extern const char s_narioEditorInfo_005865f7[16];
// 00586609 [.data]
extern unsigned char DAT_00586609;
// 0058660B [.data]
extern const char s_o2Screen_0058660b[9];
// 00586621 [.data]
extern unsigned char DAT_00586621;
// 00586623 [.data]
extern const char s_o1Screen_00586623[9];
// 0058662D [.data]
extern unsigned char DAT_0058662d;
// 0058662F [.data]
extern const char s_thMatch_0058662f[8];
// 0058664D [.data]
extern unsigned char DAT_0058664d;
// 0058664F [.data]
extern const char s_domMap_0058664f[7];
// 005866A5 [.data]
extern unsigned char DAT_005866a5;
// 005866A7 [.data]
extern const char s_firm_Dialog_005866a7[12];
// 00586739 [.data]
extern unsigned char DAT_00586739;
// 0058673B [.data]
extern const char s_rt_Zone_0058673b[8];
// 00586745 [.data]
extern unsigned char DAT_00586745;
// 00586747 [.data]
extern const char s_t_Error_00586747[8];
// 00586751 [.data]
extern unsigned char DAT_00586751;
// 00586753 [.data]
extern const char s_e_Error_00586753[8];
// 005867E9 [.data]
extern unsigned char DAT_005867e9;
// 005867EB [.data]
extern const char s_k_Dialog_005867eb[9];
// 00586809 [.data]
extern unsigned char DAT_00586809;
// 0058680B [.data]
extern const char s_e_Settings_Screen_0058680b[18];
// 00586C65 [.data]
extern unsigned char DAT_00586c65;
// 00586C67 [.data]
extern const char s_Name_Dialog_00586c67[13];
// 00586CF9 [.data]
extern unsigned char DAT_00586cf9;
// 00586CFB [.data]
extern const char s_SaveDialog_00586cfb[11];
// 00586D09 [.data]
extern unsigned char DAT_00586d09;
// 00586D0B [.data]
extern const char s_nSaveDialog_00586d0b[12];
// 00586D19 [.data]
extern unsigned char DAT_00586d19;
// 00586D1B [.data]
extern const char s_tSaveDialog_00586d1b[12];
// 00587258 [.data]
extern TRIBE_Cliff_Higher_Check_Record TRIBE_Cliff_Higher_Check_Table[25];
// 00587A55 [.data]
extern unsigned char DAT_00587a55;
// 00587A5D [.data]
extern unsigned char DAT_00587a5d;
// 00587A65 [.data]
extern unsigned char DAT_00587a65;
// 00587A6D [.data]
extern unsigned char DAT_00587a6d;
// 00587A75 [.data]
extern unsigned char DAT_00587a75;
// 00587A7D [.data]
extern unsigned char DAT_00587a7d;
// 0058AF79 [.data]
extern unsigned char DAT_0058af79;
// 0058AF7B [.data]
extern const char s_domGameSpecialized_0058af7b[19];
// 0058BA3C [.data]
extern unsigned int DAT_0058ba3c;
// 0058BBDD [.data]
extern unsigned char DAT_0058bbdd;
// 0058BFB1 [.data]
extern unsigned char DAT_0058bfb1;
// 0058BFCD [.data]
extern unsigned char DAT_0058bfcd;
// 0058BFD5 [.data]
extern unsigned char DAT_0058bfd5;
// 0058BFD7 [.data]
extern const char s_ECTOBJ_0058bfd7[7];
// 0058BFE1 [.data]
extern unsigned char DAT_0058bfe1;
// 0058BFED [.data]
extern unsigned char DAT_0058bfed;
// 0058C001 [.data]
extern unsigned char DAT_0058c001;
// 0058C015 [.data]
extern unsigned char DAT_0058c015;
// 0058C029 [.data]
extern unsigned char DAT_0058c029;
// 0058C039 [.data]
extern unsigned char DAT_0058c039;
// 0058C04D [.data]
extern unsigned char DAT_0058c04d;
// 0058C05D [.data]
extern unsigned char DAT_0058c05d;
// 0058C07D [.data]
extern unsigned char DAT_0058c07d;
// 0058C089 [.data]
extern unsigned char DAT_0058c089;
// 0058C099 [.data]
extern unsigned char DAT_0058c099;
// 0058C0AD [.data]
extern unsigned char DAT_0058c0ad;
// 0058C0B9 [.data]
extern unsigned char DAT_0058c0b9;
// 0058C0C5 [.data]
extern unsigned char DAT_0058c0c5;
// 0058C0D1 [.data]
extern unsigned char DAT_0058c0d1;
// 0058C0DD [.data]
extern unsigned char DAT_0058c0dd;
// 0058C0E9 [.data]
extern unsigned char DAT_0058c0e9;
// 0058C0F5 [.data]
extern unsigned char DAT_0058c0f5;
// 0058C101 [.data]
extern unsigned char DAT_0058c101;
// 0058C10D [.data]
extern unsigned char DAT_0058c10d;
// 0058C121 [.data]
extern unsigned char DAT_0058c121;
// 0058C12D [.data]
extern unsigned char DAT_0058c12d;
// 0058C13D [.data]
extern unsigned char DAT_0058c13d;
// 0058C155 [.data]
extern unsigned char DAT_0058c155;
// 0058C169 [.data]
extern unsigned char DAT_0058c169;
// 0058C17D [.data]
extern unsigned char DAT_0058c17d;
// 0058C1A1 [.data]
extern unsigned char DAT_0058c1a1;
// 0058C1C1 [.data]
extern unsigned char DAT_0058c1c1;
// 0058C1D5 [.data]
extern unsigned char DAT_0058c1d5;
// 0058C1F1 [.data]
extern unsigned char DAT_0058c1f1;
// 0058C209 [.data]
extern unsigned char DAT_0058c209;
// 0058C26D [.data]
extern unsigned char DAT_0058c26d;
// 0058C335 [.data]
extern const char s_tandard_0058c335[8];
// 0058C3B5 [.data]
extern unsigned char DAT_0058c3b5;
// 0058CDE4 [.data]
extern unsigned int DAT_0058cde4;
// 0058CDE8 [.data]
extern unsigned int DAT_0058cde8;
// 0058CDEC [.data]
extern unsigned int DAT_0058cdec;
// 0058E884 [.data]
extern unsigned int DAT_0058e884;
// 0058E888 [.data]
extern unsigned int DAT_0058e888;
// 0058E88C [.data]
extern unsigned int DAT_0058e88c;
// 0058EC21 [.data]
extern unsigned char DAT_0058ec21;
// 0058EC29 [.data]
extern unsigned char DAT_0058ec29;
// 0058EF30 [.data]
extern unsigned char DAT_0058ef30;
// 0058EF42 [.data]
extern unsigned char DAT_0058ef42;
// 0058EF48 [.data]
extern unsigned short DAT_0058ef48;
// 0058F148 [.data]
extern unsigned char DAT_0058f148;
// 0058F248 [.data]
extern unsigned char DAT_0058f248;
// 0058F347 [.data]
extern unsigned char DAT_0058f347;
// 0058F547 [.data]
extern unsigned char DAT_0058f547;
// 0058F747 [.data]
extern unsigned char DAT_0058f747;
// 0058F948 [.data]
extern unsigned char DAT_0058f948;
// 0058F9C8 [.data]
extern unsigned char DAT_0058f9c8;
// 0058FA48 [.data]
extern unsigned short DAT_0058fa48;
// 0058FB54 [.data]
extern unsigned int DAT_0058fb54;
// 0058FB58 [.data]
extern unsigned int DAT_0058fb58;
// 0058FB5C [.data]
extern unsigned int DAT_0058fb5c;
// 0058FBF8 [.data]
extern unsigned int DAT_0058fbf8;
// 0058FBFC [.data]
extern unsigned int DAT_0058fbfc;
// 0058FC00 [.data]
extern unsigned int DAT_0058fc00;
// 0058FC04 [.data]
extern unsigned int DAT_0058fc04;
// 0058FC08 [.data]
extern unsigned int DAT_0058fc08;
// 00591BF8 [.data]
extern unsigned int DAT_00591bf8;
// 00591C18 [.data]
extern unsigned int DAT_00591c18;
// 00591C24 [.data]
extern unsigned int DAT_00591c24;
// 00591DA3 [.data]
extern unsigned char DAT_00591da3;
// 00591DDF [.data]
extern unsigned char DAT_00591ddf;
// 00591DE0 [.data]
extern unsigned char DAT_00591de0;
// 00591DE3 [.data]
extern unsigned char DAT_00591de3;
// 00591E1F [.data]
extern unsigned char DAT_00591e1f;
// 00591E28 [.data]
extern unsigned int DAT_00591e28;
// 00591E2C [.data]
extern unsigned int DAT_00591e2c;
// 00591E30 [.data]
extern unsigned int DAT_00591e30;
// 00591E38 [.data]
extern unsigned int DAT_00591e38;
// 00591E3C [.data]
extern unsigned int DAT_00591e3c;
// 00591E40 [.data]
extern unsigned int DAT_00591e40;
// 00591E58 [.data]
extern unsigned int DAT_00591e58;
// 005920CC [.data]
extern unsigned char DAT_005920cc;
// 005920DB [.data]
extern unsigned char DAT_005920db;
// 005922F0 [.data]
extern unsigned char DAT_005922f0;
// 005922F8 [.data]
extern unsigned int DAT_005922f8;
// 0059232C [.data]
extern unsigned int DAT_0059232c;
// 00592330 [.data]
extern unsigned int DAT_00592330;
// 00592334 [.data]
extern unsigned int DAT_00592334;
// 00592338 [.data]
extern unsigned char DAT_00592338;
// 00592339 [.data]
extern unsigned char DAT_00592339;
// 0059233A [.data]
extern unsigned char DAT_0059233a;
// 005923E4 [.data]
extern unsigned int DAT_005923e4;
// 0059241C [.data]
extern unsigned int DAT_0059241c;
// 00592424 [.data]
extern unsigned int DAT_00592424;
// 00592428 [.data]
extern unsigned int DAT_00592428;
// 00592458 [.data]
extern unsigned int DAT_00592458;
// 00592558 [.data]
extern double DAT_00592558;
// 00592568 [.data]
extern double DAT_00592568;
// 0059257C [.data]
extern unsigned int DAT_0059257c;
// 00592584 [.data]
extern unsigned int DAT_00592584;
// 00592588 [.data]
extern unsigned int DAT_00592588;
// 005925A4 [.data]
extern unsigned int DAT_005925a4;
// 00592600 [.data]
extern unsigned int DAT_00592600;
// 00592610 [.data]
extern unsigned int DAT_00592610;
// 00592820 [.data]
extern unsigned int DAT_00592820;
// 00592824 [.data]
extern unsigned int DAT_00592824;
// 005B2164 [.data] BaseGame Shift-key state.
extern unsigned int basegame_shift_key_down;
// 005B2368 [.data] BaseGame key message.
extern unsigned int basegame_key_message;
// 005B2370 [.data] BaseGame key parameter.
extern unsigned int basegame_key_parameter;
// 0062C49C [.data]
extern unsigned char DAT_0062c49c;
// 0062C4B4 [.data] BaseGame Alt-key state.
extern unsigned int basegame_alt_key_down;
// 0062C4BC [.data] BaseGame Control-key state.
extern unsigned int basegame_control_key_down;
// 0062C4FC [.data] shared debug log pointer.
extern TDebuggingLog* L;
// 0062C558 [.data]
extern unsigned int DAT_0062c558;
// 0062C578 [.data] BaseGame palette restore time.
extern unsigned int basegame_palette_restore_time;
// 0062C57C [.data] BaseGame palette restore flag.
extern unsigned int basegame_palette_restore_pending;
// Shared DirectPlay interface pointer.
extern IDirectPlay3* direct_play_interface;
// Shared DirectPlay player identifier.
extern unsigned long local_player_dpid;
// 0062CF68 [.data]
extern unsigned int DAT_0062cf68;
// 0062D208 [.data]
extern unsigned int DAT_0062d208;
// 0062D20C [.data]
extern unsigned int DAT_0062d20c;
// 0062D230 [.data]
extern unsigned int DAT_0062d230;
// 0062E64C [.data]
extern unsigned int DAT_0062e64c;
// 0062E658 [.data]
extern unsigned int DAT_0062e658;
// 0062E65C [.data]
extern unsigned int DAT_0062e65c;
// 0086B240 [.data]
extern unsigned int DAT_0086b240;
// 0086B244 [.data]
extern unsigned int DAT_0086b244;
// 0086B24C [.data]
extern unsigned char DAT_0086b24c;
// 0086B254 [.data]
extern ResFileHdr* DAT_0086b254;
// 0086B25C [.data]
extern unsigned int DAT_0086b25c;
// 0086B260 [.data]
extern unsigned int DAT_0086b260;
// 0086B264 [.data]
extern unsigned char DAT_0086b264;
// 0086B268 [.data]
extern unsigned int DAT_0086b268;
// 0086B26C [.data]
extern unsigned int DAT_0086b26c;
// 0086B270 [.data]
extern unsigned int DAT_0086b270;
// 0086B274 [.data]
extern unsigned int DAT_0086b274;
// 0086B278 [.data]
extern unsigned int DAT_0086b278;
// 0086B27C [.data]
extern unsigned int DAT_0086b27c;
// 0086B280 [.data]
extern unsigned int DAT_0086b280;
// 0086B294 [.data]
extern unsigned int DAT_0086b294;
// 0086B298 [.data]
extern unsigned int DAT_0086b298;
// 0086B29C [.data]
extern unsigned int DAT_0086b29c;
// 0086B2AC [.data]
extern float DAT_0086b2ac;
// 0086B2B0 [.data]
extern unsigned char DAT_0086b2b0;
// 0086B2B1 [.data]
extern unsigned char DAT_0086b2b1;
// 0086B2B2 [.data]
extern unsigned char DAT_0086b2b2;
// 0086B2B3 [.data]
extern unsigned char DAT_0086b2b3;
// 0086B6B0 [.data]
extern unsigned char DAT_0086b6b0;
// 0086B6B1 [.data]
extern unsigned char DAT_0086b6b1;
// 0086B6B2 [.data]
extern unsigned char DAT_0086b6b2;
// 0086B6B3 [.data]
extern unsigned char DAT_0086b6b3;
// 0086BAB0 [.data]
extern unsigned int DAT_0086bab0;
// 0086BC08 [.data]
extern float DAT_0086bc08;
// 0086BC8C [.data]
extern unsigned int DAT_0086bc8c;
// 0086BCA0 [.data]
extern unsigned char DAT_0086bca0;
// 0086BCAC [.data]
extern unsigned int DAT_0086bcac;
// 0086BCD0 [.data]
extern unsigned char DAT_0086bcd0;
// 0086BE04 [.data]
extern unsigned int DAT_0086be04;
// 0087D4A6 [.data]
extern unsigned short DAT_0087d4a6;
// 0087D4A8 [.data]
extern unsigned short DAT_0087d4a8;
// 0087D4AA [.data]
extern unsigned short DAT_0087d4aa;
// 0087D4B0 [.data]
extern unsigned short DAT_0087d4b0;
// 0087D7CC [.data]
extern unsigned int DAT_0087d7cc;
// 0087D7D0 [.data]
extern unsigned int DAT_0087d7d0;
// 0087D7D4 [.data]
extern unsigned int DAT_0087d7d4;
// 0087D7D8 [.data]
extern unsigned int DAT_0087d7d8;
// 0087D7E4 [.data]
extern unsigned int DAT_0087d7e4;
// 0087D7E8 [.data]
extern unsigned int DAT_0087d7e8;
// 0087D7F0 [.data]
extern unsigned int DAT_0087d7f0;
// 0087D80C [.data]
extern unsigned int DAT_0087d80c;
// 0087D810 [.data]
extern unsigned int DAT_0087d810;
// 0087D814 [.data]
extern unsigned int DAT_0087d814;
// 0087D818 [.data]
extern unsigned int DAT_0087d818;
// 0087D81C [.data]
extern unsigned int DAT_0087d81c;
// 0087D820 [.data]
extern unsigned int DAT_0087d820;
// 0087D824 [.data]
extern unsigned int DAT_0087d824;
// 0087D828 [.data]
extern unsigned int DAT_0087d828;
// 0088680C [.data]
extern unsigned int DAT_0088680c;
// 00886C1C [.data]
extern unsigned int DAT_00886c1c;
// 00886C20 [.data]
extern unsigned int DAT_00886c20;
// 00886C28 [.data]
extern unsigned int DAT_00886c28;
// 00886C2C [.data]
extern unsigned int DAT_00886c2c;
// 00886C30 [.data]
extern unsigned int DAT_00886c30;
// 00886C34 [.data]
extern unsigned int DAT_00886c34;
// 00886C38 [.data]
extern unsigned int DAT_00886c38;
// 00886C40 [.data]
extern unsigned int DAT_00886c40;
// 00886C44 [.data]
extern unsigned int DAT_00886c44;
// 00886C48 [.data]
extern unsigned int DAT_00886c48;
// 00886C60 [.data]
extern unsigned int DAT_00886c60;
// 00886C6C [.data]
extern unsigned int DAT_00886c6c;
// 00886C70 [.data]
extern unsigned int DAT_00886c70;
// 00886CEC [.data]
extern unsigned int DAT_00886cec;
// 00886CF0 [.data]
extern unsigned int DAT_00886cf0;
// 00886CF8 [.data]
extern unsigned int DAT_00886cf8;
// 00887178 [.data]
extern unsigned int DAT_00887178;
// 008875F8 [.data]
extern unsigned int DAT_008875f8;
// 00887600 [.data]
extern unsigned int DAT_00887600;
// 00887A80 [.data]
extern unsigned int DAT_00887a80;
// 00887A84 [.data]
extern unsigned int DAT_00887a84;
// 00887A88 [.data]
extern unsigned int DAT_00887a88;
// 00887A90 [.data]
extern unsigned int DAT_00887a90;
// 00887A94 [.data]
extern unsigned int DAT_00887a94;
// 00887A98 [.data]
extern unsigned int DAT_00887a98;
// 00887A9C [.data]
extern unsigned int DAT_00887a9c;
// 00887B1C [.data]
extern unsigned int DAT_00887b1c;
// 00887B24 [.data]
extern unsigned int DAT_00887b24;
// 00887FA8 [.data]
extern unsigned int DAT_00887fa8;
// 00887FE2 [.data]
extern unsigned short DAT_00887fe2;
// 00887FE4 [.data]
extern unsigned int DAT_00887fe4;
// 00887FE6 [.data]
extern unsigned short DAT_00887fe6;
// 00887FEA [.data]
extern unsigned short DAT_00887fea;
// 00887FEC [.data]
extern unsigned int DAT_00887fec;
// 00887FF0 [.data]
extern unsigned int DAT_00887ff0;
// 0088805C [.data]
extern unsigned int DAT_0088805c;
// 00888060 [.data]
extern unsigned char DAT_00888060;
// 00888064 [.data]
extern unsigned int DAT_00888064;
// 00888068 [.data]
extern unsigned char DAT_00888068;
// 00888074 [.data]
extern unsigned int DAT_00888074;
// 00888080 [.data]
extern unsigned int DAT_00888080;
// 008880CC [.data]
extern unsigned short DAT_008880cc;
// 008880CE [.data]
extern unsigned short DAT_008880ce;
// 008880D0 [.data]
extern unsigned short DAT_008880d0;
// 008880DC [.data]
extern unsigned int DAT_008880dc;
// 00888120 [.data]
extern unsigned short DAT_00888120;
// 00888122 [.data]
extern unsigned short DAT_00888122;
// 00888134 [.data]
extern unsigned int DAT_00888134;
// 00888138 [.data]
extern unsigned int DAT_00888138;
// 00888284 [.data]
extern unsigned int DAT_00888284;
// 00888298 [.data]
extern unsigned int DAT_00888298;
// 0088829C [.data]
extern unsigned int DAT_0088829c;
// 008882A8 [.data]
extern double DAT_008882a8;
// 008882C0 [.data]
extern unsigned int DAT_008882c0;
// 008882D8 [.data]
extern unsigned int DAT_008882d8;
// 008883E8 [.data]
extern unsigned int DAT_008883e8;
// 008883F0 [.data]
extern unsigned short DAT_008883f0;
// 008883F2 [.data]
extern unsigned char DAT_008883f2;
// 00888424 [.data]
extern unsigned int DAT_00888424;
// 00888430 [.data]
extern unsigned int DAT_00888430;
// 00888434 [.data]
extern unsigned int DAT_00888434;
// 00888438 [.data]
extern unsigned int DAT_00888438;
// 0088843C [.data]
extern unsigned int DAT_0088843c;
// 00888448 [.data]
extern unsigned int DAT_00888448;
// 008884E4 [.data]
extern unsigned int DAT_008884e4;
// 0088C000 [THIS_DAT]
extern unsigned int DAT_0088c000;
// 0088C004 [THIS_DAT]
extern unsigned int DAT_0088c004;
// 0088C008 [THIS_DAT]
extern unsigned int DAT_0088c008;
// 0088C00C [THIS_DAT]
extern unsigned int DAT_0088c00c;
// 0088C010 [THIS_DAT]
extern unsigned int DAT_0088c010;
// 0088C014 [THIS_DAT]
extern unsigned int DAT_0088c014;
// 0088C018 [THIS_DAT]
extern unsigned int DAT_0088c018;
// 0088C01C [THIS_DAT]
extern unsigned int DAT_0088c01c;
// 0088C020 [THIS_DAT]
extern unsigned int DAT_0088c020;
// 0088C024 [THIS_DAT]
extern unsigned int DAT_0088c024;
// 0088C028 [THIS_DAT]
extern unsigned int DAT_0088c028;
// 0088C02C [THIS_DAT]
extern unsigned int DAT_0088c02c;
// 0088C038 [THIS_DAT]
extern unsigned int DAT_0088c038;
// 0088C03C [THIS_DAT]
extern unsigned int DAT_0088c03c;
// 0088C040 [THIS_DAT]
extern unsigned int DAT_0088c040;
// 0088C044 [THIS_DAT]
extern unsigned int DAT_0088c044;
// 0088C054 [THIS_DAT]
extern unsigned int DAT_0088c054;
// 0088C058 [THIS_DAT]
extern unsigned int DAT_0088c058;
// 0088C080 [THIS_DAT]
extern unsigned int DAT_0088c080;
// 0088C084 [THIS_DAT]
extern unsigned int DAT_0088c084;
// 0088C088 [THIS_DAT]
extern unsigned int DAT_0088c088;
// 0088C08C [THIS_DAT]
extern unsigned int DAT_0088c08c;
