#pragma once
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <cstdint>
#include <cstddef>
#include <ddraw.h>
#include <dsound.h>
#include <mmsystem.h>  // MMIOINFO and mmio* APIs
#include <mmiscapi.h>  // MMCKINFO (some SDKs expose it here)

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char byte;

static_assert(sizeof(void*) == 4, "Build must be 32-bit (x86) to match the binary layout.");

#pragma once
#include <stdint.h>

// FORWARD DECLARATIONS
typedef struct AttackMemory AttackMemory;
typedef struct AttackState AttackState;
typedef struct Attribute_Cost Attribute_Cost;
typedef struct BITMAPINFO256 BITMAPINFO256;
typedef struct BYTEPoint BYTEPoint;
typedef struct Blit_Queue_Entry Blit_Queue_Entry;
typedef struct BuildRes_id_node BuildRes_id_node;
typedef struct BuildRes_type_node BuildRes_type_node;
typedef struct BuildingLot BuildingLot;
typedef struct CHECKSUMARRAY CHECKSUMARRAY;
typedef struct COMMPLAYEROPTIONS COMMPLAYEROPTIONS;
typedef struct DClipInfo_Node DClipInfo_Node;
typedef struct DIDEVCAPS DIDEVCAPS;
typedef struct DIDEVICEINSTANCEA DIDEVICEINSTANCEA;
typedef struct DIDEVICEOBJECTDATA DIDEVICEOBJECTDATA;
typedef struct DIDEVICEOBJECTINSTANCEA DIDEVICEOBJECTINSTANCEA;
typedef struct DIPROPHEADER DIPROPHEADER;
typedef struct DPCAPS DPCAPS;
typedef struct DPCHAT_u_8 DPCHAT_u_8;
typedef struct DPCHAT DPCHAT;
typedef struct DPCOMPOUNDADDRESSELEMENT DPCOMPOUNDADDRESSELEMENT;
typedef struct DPCREDENTIALS_u_8 DPCREDENTIALS_u_8;
typedef struct DPCREDENTIALS_u_16 DPCREDENTIALS_u_16;
typedef struct DPCREDENTIALS_u_12 DPCREDENTIALS_u_12;
typedef struct DPCREDENTIALS DPCREDENTIALS;
typedef struct DPLAPPINFO_u_20 DPLAPPINFO_u_20;
typedef struct DPLAPPINFO DPLAPPINFO;
typedef struct DPLCONNECTION DPLCONNECTION;
typedef struct DPNAME_u_8 DPNAME_u_8;
typedef struct DPNAME_u_12 DPNAME_u_12;
typedef struct DPNAME DPNAME;
typedef struct DPSECURITYDESC_u_8 DPSECURITYDESC_u_8;
typedef struct DPSECURITYDESC_u_12 DPSECURITYDESC_u_12;
typedef struct DPSECURITYDESC DPSECURITYDESC;
typedef struct DPSESSIONDESC DPSESSIONDESC;
typedef struct DPSESSIONDESC2_u_52 DPSESSIONDESC2_u_52;
typedef struct DPSESSIONDESC2_u_48 DPSESSIONDESC2_u_48;
typedef struct DPSESSIONDESC2 DPSESSIONDESC2;
typedef struct DisplaySelectedObjRec DisplaySelectedObjRec;
typedef struct DrawAreaNode DrawAreaNode;
typedef struct FlicHead FlicHead;
typedef struct FloatHeap FloatHeap;
typedef struct FrameHead FrameHead;
typedef struct Friendliness Friendliness;
typedef struct GroupingStruct GroupingStruct;
typedef struct ICINFO ICINFO;
typedef struct IDirectDraw IDirectDraw;
typedef struct IDirectDraw2 IDirectDraw2;
typedef struct IDirectDrawClipper IDirectDrawClipper;
typedef struct IDirectDrawPalette IDirectDrawPalette;
typedef struct IDirectDrawSurface IDirectDrawSurface;
typedef struct IDirectDrawSurface3 IDirectDrawSurface3;
typedef struct IDirectInputA IDirectInputA;
typedef struct IDirectInputDeviceA IDirectInputDeviceA;
typedef struct IDirectPlay IDirectPlay;
typedef struct IDirectPlay2 IDirectPlay2;
typedef struct IDirectPlay3 IDirectPlay3;
typedef struct IDirectPlayLobby IDirectPlayLobby;
typedef struct IDirectPlayLobby2 IDirectPlayLobby2;
typedef struct IDirectSound IDirectSound;
typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IUnknown IUnknown;
typedef struct Item_Avail Item_Avail;
typedef struct LINEINFO LINEINFO;
typedef struct LOSTBL LOSTBL;
typedef struct List_Info List_Info;
typedef struct MGP_FloatHeap MGP_FloatHeap;
typedef struct MSGFORMAT_ACKNOWLEDGE_GUARANTEED MSGFORMAT_ACKNOWLEDGE_GUARANTEED;
typedef struct MSGFORMAT_ALL_DONE MSGFORMAT_ALL_DONE;
typedef struct MSGFORMAT_CHAT MSGFORMAT_CHAT;
typedef struct MSGFORMAT_CHECKSUM MSGFORMAT_CHECKSUM;
typedef struct MSGFORMAT_HEADER_GUARANTEED MSGFORMAT_HEADER_GUARANTEED;
typedef struct MSGFORMAT_KILL_PLAYER MSGFORMAT_KILL_PLAYER;
typedef struct MSGFORMAT_LATENCY MSGFORMAT_LATENCY;
typedef struct MSGFORMAT_MISSING_PLAYER MSGFORMAT_MISSING_PLAYER;
typedef struct MSGFORMAT_ONTURN MSGFORMAT_ONTURN;
typedef struct MSGFORMAT_RESEND MSGFORMAT_RESEND;
typedef struct MSGFORMAT_SETREADYOPTIONS MSGFORMAT_SETREADYOPTIONS;
typedef struct MSGFORMAT_SPEEDCHANGE MSGFORMAT_SPEEDCHANGE;
typedef struct Map_Stack Map_Stack;
typedef struct MouseClickInfo MouseClickInfo;
typedef struct NotifyEvent NotifyEvent;
typedef struct ObjectMemory ObjectMemory;
typedef struct OldUnitData OldUnitData;
typedef struct OldUnitData2 OldUnitData2;
typedef struct OrderEvent OrderEvent;
typedef struct Ov_Sprite_Draw_Rec Ov_Sprite_Draw_Rec;
typedef struct PAL_TABLE PAL_TABLE;
typedef struct PLAYER_SCORE PLAYER_SCORE;
typedef struct PanelNode PanelNode;
typedef struct XYPoint XYPoint;
typedef struct PlacementState PlacementState;
typedef struct PlayerName PlayerName;
typedef struct Player_Start_Info Player_Start_Info;
typedef struct PrimaryPt PrimaryPt;
typedef struct Production_Queue_Record Production_Queue_Record;
typedef struct PtToPt PtToPt;
typedef struct QuadrantLog QuadrantLog;
typedef struct RGE_Action_Node RGE_Action_Node;
typedef struct RGE_Active_Sprite_Node RGE_Active_Sprite_Node;
typedef struct RGE_Armor_Weapon_Info RGE_Armor_Weapon_Info;
typedef struct RGE_TOB_Picts RGE_TOB_Picts;
typedef struct RGE_Border_Set RGE_Border_Set;
typedef struct RGE_Campaign_Header RGE_Campaign_Header;
typedef struct RGE_Check_Node RGE_Check_Node;
typedef struct RGE_Cliffs_Hot_Spots RGE_Cliffs_Hot_Spots;
typedef struct RGE_Cliffs_Info RGE_Cliffs_Info;
typedef struct RGE_Command_AI_Order RGE_Command_AI_Order;
typedef struct RGE_Command_Add_Attribute RGE_Command_Add_Attribute;
typedef struct RGE_Command_Add_To_Group RGE_Command_Add_To_Group;
typedef struct XYZBYTEPoint XYZBYTEPoint;
typedef struct RGE_Command_Add_Waypoint RGE_Command_Add_Waypoint;
typedef struct RGE_Command_Create RGE_Command_Create;
typedef struct RGE_Command_Create_Group RGE_Command_Create_Group;
typedef struct RGE_Command_Destroy_Group RGE_Command_Destroy_Group;
typedef struct RGE_Command_Formation RGE_Command_Formation;
typedef struct RGE_Command_Give_Attribute RGE_Command_Give_Attribute;
typedef struct RGE_Command_Group_AI_Order RGE_Command_Group_AI_Order;
typedef struct RGE_Command_Group_Waypoint RGE_Command_Group_Waypoint;
typedef struct RGE_Obj_Info RGE_Obj_Info;
typedef struct RGE_Command_Order RGE_Command_Order;
typedef struct RGE_Command_Pause RGE_Command_Pause;
typedef struct RGE_Command_Remove_From_Group RGE_Command_Remove_From_Group;
typedef struct RGE_Command_Resign RGE_Command_Resign;
typedef struct RGE_Command_Stop RGE_Command_Stop;
typedef struct RGE_Damage_Sprite_Info RGE_Damage_Sprite_Info;
typedef struct RGE_Effect RGE_Effect;
typedef struct RGE_Effect_Command RGE_Effect_Command;
typedef struct RGE_Elevation_Data RGE_Elevation_Data;
typedef struct RGE_Elevation_Data_Entry RGE_Elevation_Data_Entry;
typedef struct RGE_Elevation_Hot_Spots RGE_Elevation_Hot_Spots;
typedef struct RGE_Elevation_Info_Line RGE_Elevation_Info_Line;
typedef struct RGE_Elevation_Info RGE_Elevation_Info;
typedef struct RGE_Font RGE_Font;
typedef struct RGE_Game_Options RGE_Game_Options;
typedef struct RGE_Info_Line RGE_Info_Line;
typedef struct RGE_Land_Data RGE_Land_Data;
typedef struct RGE_Land_Data_Entry RGE_Land_Data_Entry;
typedef struct RGE_Land_Info_Line RGE_Land_Info_Line;
typedef struct RGE_Land_Info RGE_Land_Info;
typedef struct RGE_Land_Point_Info_Line RGE_Land_Point_Info_Line;
typedef struct RGE_Map_Data RGE_Map_Data;
typedef struct RGE_Object_Data RGE_Object_Data;
typedef struct RGE_Terrain_Data RGE_Terrain_Data;
typedef struct RGE_Map_Data_Entry RGE_Map_Data_Entry;
typedef struct RGE_Map_Gen_Info RGE_Map_Gen_Info;
typedef struct RGE_Map_Image_Line RGE_Map_Image_Line;
typedef struct RGE_Map_Tile_Row RGE_Map_Tile_Row;
typedef struct RGE_Object_Data_Entry RGE_Object_Data_Entry;
typedef struct RGE_Object_Info_Line RGE_Object_Info_Line;
typedef struct RGE_Object_Info RGE_Object_Info;
typedef struct RGE_Object_Node RGE_Object_Node;
typedef struct RGE_Pick_Info RGE_Pick_Info;
typedef struct RGE_Pick_Obj_Info RGE_Pick_Obj_Info;
typedef struct RGE_Picture_List RGE_Picture_List;
typedef struct RGE_Player_Info RGE_Player_Info;
typedef struct RGE_Prog_Info RGE_Prog_Info;
typedef struct RGE_Random_Map_Module_List RGE_Random_Map_Module_List;
typedef struct RGE_SPick_Info RGE_SPick_Info;
typedef struct RGE_Scenario_File_Entry RGE_Scenario_File_Entry;
typedef struct RGE_Scenario_Info RGE_Scenario_Info;
typedef struct RGE_Scenario_Offset RGE_Scenario_Offset;
typedef struct RGE_Shallows_Info_Line RGE_Shallows_Info_Line;
typedef struct RGE_Shallows_Info RGE_Shallows_Info;
typedef struct RGE_Sound_Info RGE_Sound_Info;
typedef struct RGE_Sound_List RGE_Sound_List;
typedef struct RGE_Terrain_Data_Entry RGE_Terrain_Data_Entry;
typedef struct RGE_Terrain_Hot_Spots RGE_Terrain_Hot_Spots;
typedef struct RGE_Terrain_Info_Line RGE_Terrain_Info_Line;
typedef struct RGE_Terrain_Info RGE_Terrain_Info;
typedef struct RGE_Tile RGE_Tile;
typedef struct RGE_Tile_List_Node RGE_Tile_List_Node;
typedef struct RGE_Tile_Set RGE_Tile_Set;
typedef struct RGE_Tile_Size RGE_Tile_Size;
typedef struct RGE_Time_Entry RGE_Time_Entry;
typedef struct RGE_Timing_Info RGE_Timing_Info;
typedef struct RGE_Victory_Entry RGE_Victory_Entry;
typedef struct RGE_Victory_Point_Entry RGE_Victory_Point_Entry;
typedef struct ResFileHdr ResFileHdr;
typedef struct ResourceMemory ResourceMemory;
typedef struct SEs SEs;
typedef struct SLhape_File_Header SLhape_File_Header;
typedef struct SNDOBJ SNDOBJ;
typedef struct SP_Victory_Info SP_Victory_Info;
typedef struct SPs SPs;
typedef struct Shape_File_Header Shape_File_Header;
typedef struct Shape_Header Shape_Header;
typedef struct Shape_Info Shape_Info;
typedef struct Shape_Offsets Shape_Offsets;
typedef struct Special_Events Special_Events;
typedef struct TRANSINFO TRANSINFO;
typedef struct TRIBE_Cliff_Info TRIBE_Cliff_Info;
typedef struct TRIBE_Command_Attack_Ground TRIBE_Command_Attack_Ground;
typedef struct TRIBE_Command_Build TRIBE_Command_Build;
typedef struct TRIBE_Command_Build_Wall TRIBE_Command_Build_Wall;
typedef struct TRIBE_Command_Cancel_Build TRIBE_Command_Cancel_Build;
typedef struct TRIBE_Command_Explore TRIBE_Command_Explore;
typedef struct TRIBE_Command_Game TRIBE_Command_Game;
typedef struct TRIBE_Command_Give_Attribute TRIBE_Command_Give_Attribute;
typedef struct TRIBE_Command_Make TRIBE_Command_Make;
typedef struct TRIBE_Command_Queue TRIBE_Command_Queue;
typedef struct TRIBE_Command_Repair TRIBE_Command_Repair;
typedef struct TRIBE_Command_Research TRIBE_Command_Research;
typedef struct TRIBE_Command_Trade_Attribute TRIBE_Command_Trade_Attribute;
typedef struct TRIBE_Command_Unload TRIBE_Command_Unload;
typedef struct TRIBE_Game_Options TRIBE_Game_Options;
typedef struct TRIBE_History_Entry TRIBE_History_Entry;
typedef struct TRIBE_History_Events TRIBE_History_Events;
typedef struct TRIBE_Master_Cliff_Info TRIBE_Master_Cliff_Info;
typedef struct TRIBE_Zone_High_Score_Info TRIBE_Zone_High_Score_Info;
typedef struct TRIBE_Zone_Player_Info TRIBE_Zone_Player_Info;
typedef struct TRIBE_Zone_Map_Info TRIBE_Zone_Map_Info;
typedef struct TRIBE_Zone_Info TRIBE_Zone_Info;
typedef struct Tech_Player_Tree Tech_Player_Tree;
typedef struct Tech_Tree Tech_Tree;
typedef struct TextNode TextNode;
typedef struct Tile_BlackEdge_Table Tile_BlackEdge_Table;
typedef struct Tile_FogEdge_Table Tile_FogEdge_Table;
typedef struct Trade_Avail Trade_Avail;
typedef struct UnitData UnitData;
typedef struct VC_LOG VC_LOG;
typedef struct VISIBLE_RESOURCE_REC VISIBLE_RESOURCE_REC;
typedef struct VISIBLE_UNIT_PTR VISIBLE_UNIT_PTR;
typedef struct VISIBLE_UNIT_REC VISIBLE_UNIT_REC;
typedef struct VSpanMiniList VSpanMiniList;
typedef struct VSpan_Node VSpan_Node;
typedef struct Victory_StartInfo Victory_StartInfo;
typedef struct WSAData WSAData;
typedef struct Waypoint Waypoint;
typedef struct XYZPoint XYZPoint;
typedef struct Zone_Queue Zone_Queue;
typedef struct combined_options combined_options;
typedef struct waveformat_tag waveformat_tag;
typedef struct pcmwaveformat_tag pcmwaveformat_tag;
typedef struct rdlg_list_info rdlg_list_info;
typedef struct res_file_type_info res_file_type_info;
typedef struct resfile_header resfile_header;
typedef struct resfile_id_dir_node resfile_id_dir_node;
typedef struct resfile_type_dir_node resfile_type_dir_node;
typedef struct tMIXERCONTROLDETAILS_u_12 tMIXERCONTROLDETAILS_u_12;
typedef struct tMIXERCONTROLDETAILS tMIXERCONTROLDETAILS;
typedef struct tMIXERCONTROLDETAILS_UNSIGNED tMIXERCONTROLDETAILS_UNSIGNED;
typedef struct tWAVEFORMATEX tWAVEFORMATEX;
typedef struct tm tm;

// ENUMS
enum Action : unsigned int {
    OK = 0,
    Cancel = 1,
    Other = 2,
};

enum Action : unsigned int {
    ActionSelect = 1,
};

enum ActionType : unsigned int {
    ActionSelect = 1,
    ActionDown = 2,
    ActionUp = 3,
    ActionRightSelect = 4,
    ActionRightDown = 5,
    ActionRightUp = 6,
};

enum ActionType : unsigned int {
    ActionItem = 0,
    ActionList = 1,
    ActionValue = 2,
};

enum ActionType : unsigned int {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};

enum ActionType : unsigned int {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};

enum ActionType : unsigned int {
    ActionItem = 1,
    ActionLand = 2,
    ActionSelect = 3,
};

enum ActionType : unsigned int {
    ActionObjectChanged = 1,
};

enum ActionType : unsigned int {
    ActionUp = 0,
    ActionDown = 1,
    ActionPrior = 2,
    ActionNext = 3,
    ActionPosition = 4,
    ActionEnd = 5,
    ActionChange = 6,
};

enum ActionType : unsigned int {
    ActionDone = 1,
};

enum Age : unsigned int {
    DefaultAge = 0,
    NomadAge = 1,
    StoneAge = 2,
    ToolAge = 3,
    BronzeAge = 4,
    IronAge = 5,
};

enum Alignment : unsigned int {
    AlignCenter = 0,
    AlignLeft = 1,
    AlignRight = 2,
    AlignTop = 3,
    AlignBottom = 4,
    AlignHorizontalScroll = 5,
    AlignWordwrap = 6,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};

enum BrushSize : unsigned int {
    BrushSizeNone = 0,
    BrushSizeVerySmall = 1,
    BrushSizeSmall = 2,
    BrushSizeMedium = 3,
    BrushSizeLarge = 4,
    BrushSizeXLarge = 5,
};

enum ButtonType : unsigned int {
    Normal = 1,
    Radio = 2,
    State = 3,
};

enum COMMMESSAGES : unsigned int {
    COMM_PAUSE = 6050,
    COMM_RESUME = 6051,
    COMM_UPDATE_PLAYERS = 6052,
    COMM_UPDATE_CHAT = 6053,
    COMM_UPDATE_PARAMS = 6054,
    COMM_LAUNCH_GAME = 6055,
    COMM_CANCEL_GAME = 6056,
    COMM_HOST_EXITED = 6057,
    COMM_PLAYER_KICKED = 6058,
    COMM_NO_NEW_PLAYERS = 6059,
    COMM_FATAL_ERROR = 6060,
    COMM_CONNECTED = 6061,
    COMM_NO_LINK = 6062,
    COMM_CLIENT_IS_SLOW = 6063,
    COMM_SYNC_ERROR = 6064,
    COMM_HOST_CHANGED = 6065,
    COMM_PLAYER_DROPPED = 6066,
    COMM_OTHER_PLAYER_DROPPED = 6067,
    COMM_PLAYER_RESIGNED = 6068,
    COMM_PLAYER_DEFEATED = 6069,
    COMM_PLAYER_BAD_VERSION = 6070,
    COMM_PLAYER_SERVICE_ERROR = 6071,
    COMM_PLAYER_ID_SET = 6072,
    COMM_HOST_BUSY = 6073,
    COMM_LOBBY_TIMEOUT = 6074,
    COMM_SHARED_DATA_SENT = 6075,
    COMM_NO_OTHER_HUMANS = 6076,
    COMM_PLAYER_NOT_RESPONDING = 6077,
    COMM_UNKNOWN = 6078,
};

enum COMMSPEEDS : unsigned int {
    SPEED_OKAY = 0,
    SPEED_FASTER = 1,
    SPEED_SLOWER = 2,
};

enum COMMSTATES : unsigned int {
    COMM_STATE_ERROR = 1,
    COMM_STATE_INITIALIZE = 2,
    COMM_STATE_JOINNOW = 3,
    COMM_STATE_PAUSE = 4,
    COMM_STATE_RUNNING = 5,
    COMM_STATE_FINISHED = 6,
};

enum COMMSTATUS : unsigned int {
    UNINITIALIZED = 0,
    INITIALIZED = 1,
    SINGLE_PLAYER = 2,
    MULTIPLAYER_RESET = 3,
    CONVERSATION_OPEN = 4,
    SERVICE_AVAILABLE = 5,
    SESSION_AVAILABLE = 6,
    SESSION_HOSTED = 7,
    SESSION_JOINED = 8,
    PLAYER_CREATED = 9,
    COMM_SETTINGS_EXCHANGED = 10,
    GAME_PLAYER_SET = 11,
    GAME_OPTIONS_EXCHANGED = 12,
    GAME_IS_LOADING = 13,
    GAME_IS_RUNNING = 14,
    GAME_IS_PAUSED = 15,
};

enum CharType : unsigned int {
    SingleByteChar = 0,
    SingleByteKanaChar = 1,
    DoubleByteChar = 2,
};

enum DrawStyle : unsigned int {
    DrawStyleNormal = 0,
    DrawStyleLeftButton = 1,
};

enum DrawType : unsigned int {
    DrawClear = 1,
    DrawPicture = 2,
    DrawTextA = 3,
    DrawPictureAndText = 4,
    DrawFillAndText = 5,
    DrawBevelPicture = 6,
};

enum DropdownMode : unsigned int {
    ModeNone = 0,
    ModeValue = 1,
    ModeList = 2,
};

enum FormatType : unsigned int {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

enum FormatType : unsigned int {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

enum ItemType : unsigned int {
    ItemNone = 0,
    ItemUp = 1,
    ItemDown = 2,
    ItemTab = 3,
    ItemTop = 4,
    ItemBottom = 5,
};

enum JustType : unsigned int {
    TopJust = 0,
    BottomJust = 1,
    LeftJust = 2,
    RightJust = 3,
    CenterJust = 4,
};

enum MapSize : unsigned int {
    Tiny = 0,
    Small = 1,
    Medium = 2,
    Large = 3,
    Huge = 4,
    Humongous = 5,
};

enum MapType : unsigned int {
    AllWater = 0,
    MostlyWater = 1,
    WaterAndLand = 2,
    MostlyLand = 3,
    AllLand = 4,
    Continental = 5,
    Lake = 6,
    Hilly = 7,
    Isthmas = 8,
};

enum MapType : unsigned int {
    MapTypeNone = 0,
    MapTypeBlank = 1,
    MapTypeRandom = 2,
    MapTypeSeed = 3,
};

enum MessageType : unsigned int {
    InfoMessage = 0,
    BadMessage = 1,
    DebugMessage = 2,
    ChatMessage = 3,
    ColoredChatMessage = 4,
    RightInfoMessage = 5,
};

enum MessageType : unsigned int {
    MessageTypeNone = 0,
    MessageTypeDescription = 1,
    MessageTypeInstructions = 2,
    MessageTypeVictory = 3,
    MessageTypeFailure = 4,
};

enum Mode : unsigned int {
    ModeNone = 0,
    ModeDown = 1,
    ModeHold = 2,
};

enum Mode : unsigned int {
    InGame = 0,
    InPregame = 1,
};

enum Mode : unsigned int {
    SaveGame = 0,
    SaveScenario = 1,
    SaveScenarioEdit = 2,
};

enum Mode : unsigned int {
    AsChat = 0,
    AsComment = 1,
};

enum MouseAction : unsigned int {
    MouseActionNone = 0,
    MouseActionDown = 1,
    MouseActionHold = 2,
    MouseActionMove = 3,
};

enum MouseButton : unsigned int {
    MouseButtonNone = 0,
    LeftMouseButton = 1,
    RightMouseButton = 2,
};

enum NotifyType : unsigned int {
    NotifyAction = 1,
    NotifyCommand = 2,
};

enum Orientation : unsigned int {
    Vertical = 0,
    Horizontal = 1,
};

enum PLAYERHUMANITY : unsigned int {
    ME_ABSENT = 0,
    ME_CLOSED = 1,
    ME_HUMAN = 2,
    ME_ELIMINATED = 3,
    ME_COMPUTER = 4,
    ME_CYBORG = 5,
    ME_VIEWONLY = 6,
};

enum PROXY_PHASE : unsigned int {
    PROXY_CALCSIZE = 0,
    PROXY_GETBUFFER = 1,
    PROXY_MARSHAL = 2,
    PROXY_SENDRECEIVE = 3,
    PROXY_UNMARSHAL = 4,
};

enum PaintType : unsigned int {
    PaintTypeNone = 0,
    PaintTypeTerrain = 1,
    PaintTypeElevation = 2,
    PaintTypeCliffs = 3,
};

enum PathResult : unsigned int {
    PathFound = 0,
    NoPathFound = 1,
    WaitingOnPathingCap = 2,
};

enum PictureType : unsigned int {
    Picture = 0,
    Shape = 1,
};

enum PlacementResult : unsigned int {
    PlacementOk = 0,
    PlacementOnImpassableTile = 1,
    PlacementObstructed = 2,
    PlacementUnknownObject = 3,
    PlacementFailed = 4,
    PlacementFailedNoLot = 5,
};

enum PositionMode : unsigned int {
    PositionFixed = 0,
    PositionVariable = 1,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionRight = 5,
    PositionBottom = 6,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10,
};

enum RedrawMode : unsigned int {
    RedrawNone = 0,
    RedrawNormal = 1,
    RedrawFull = 2,
};

enum ResourceLevel : unsigned int {
    DefaultResources = 0,
    LowResource = 1,
    MediumResources = 2,
    HighResources = 3,
    VeryHighResources = 4,
};

enum SELECT_REGION_e : unsigned int {
    SELECT_OFF = 0,
    SELECT_OBJECT = 1,
    SELECT_DEST_OBJECT = 2,
    SELECT_AREA = 3,
};

enum STUB_PHASE : unsigned int {
    STUB_UNMARSHAL = 0,
    STUB_CALL_SERVER = 1,
    STUB_MARSHAL = 2,
    STUB_CALL_SERVER_NO_HRESULT = 3,
};

enum ScenarioMode : unsigned int {
    ScenarioModeNone = 0,
    ScenarioModeMap = 1,
    ScenarioModeTerrain = 2,
    ScenarioModePlayers = 3,
    ScenarioModeUnits = 4,
    ScenarioModeDiplomacy = 5,
    ScenarioModeVictory = 6,
    ScenarioModeVictoryMulti = 7,
    ScenarioModeOptions = 8,
    ScenarioModeMessages = 9,
    ScenarioModeCinematics = 10,
    ScenarioModeSave = 11,
};

enum ScreenMode : unsigned int {
    ModeNone = 1,
    ModeFadeOut = 2,
    ModeFadeOutDone = 3,
    ModePause = 4,
    ModeFadeIn = 5,
};

enum ScrollAction : unsigned int {
    ScrollCount = 0,
    ScrollLine = 1,
    ScrollDown = 2,
    ScrollUp = 3,
    ScrollNext = 4,
    ScrollPrior = 5,
    ScrollHome = 6,
    ScrollEnd = 7,
};

enum SliderAction : unsigned int {
    ActionUp = 0,
    ActionDown = 1,
    ActionStartSlide = 2,
    ActionEndSlide = 3,
    ActionSelect = 4,
};

enum State : unsigned int {
    StateScenario = 0,
    StateRandom = 1,
};

enum Style : unsigned int {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};

enum Style : unsigned int {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};

enum Type : unsigned int {
    OKDialog = 0,
    OKCancelDialog = 1,
    YesNoDialog = 2,
    RetryAbortDialog = 3,
    YesNoCancelDialog = 4,
};

enum ValueType : unsigned int {
    ValueTypeNumber = 0,
    ValueTypeBonus = 1,
    ValueTypeCompare = 2,
    ValueTypePercent = 3,
    ValueTypeNone = 4,
};

enum VictoryType : unsigned int {
    VictoryDefault = 0,
    VictoryConquest = 1,
    VictoryExplore = 2,
    VictoryRuins = 3,
    VictoryArtifacts = 4,
    VictoryDiscoveries = 5,
    VictoryGold = 6,
    VictoryTime = 7,
    VictoryScore = 8,
    VictoryStandard = 9,
};

enum VictoryType : unsigned int {
    VictoryTypeNone = 0,
    VictoryTypeStandard = 1,
    VictoryTypeConquest = 2,
    VictoryTypeScore = 3,
    VictoryTypeTime = 4,
    VictoryTypeCustom = 5,
};

enum XLAT_SIDE : unsigned int {
    XLAT_SERVER = 1,
    XLAT_CLIENT = 2,
};

enum ZOrder : unsigned int {
    ZOrderPosition = 0,
    ZOrderTop = 1,
    ZOrderBottom = 2,
};

enum io_state : unsigned int {
    goodbit = 0,
    eofbit = 1,
    failbit = 2,
    badbit = 4,
};

enum open_mode : unsigned int {
    in = 1,
    out = 2,
    ate = 4,
    app = 8,
    trunc = 16,
    nocreate = 32,
    noreplace = 64,
    binary = 128,
};

enum seek_dir : unsigned int {
    beg = 0,
    cur = 1,
    end = 2,
};


// STRUCTURES
// ----------------------------------------------------------------
// AttackMemory
// Size: 0x18
struct AttackMemory {
    int id; // 0x0
    uchar type; // 0x4
    uchar minX; // 0x5
    uchar minY; // 0x6
    uchar maxX; // 0x7
    uchar maxY; // 0x8
    uchar attackingOwner; // 0x9
    uchar targetOwner; // 0xA
    short kills; // 0xC
    uchar success; // 0xE
    ulong timeStamp; // 0x10
    int play; // 0x14
};

// ----------------------------------------------------------------
// AttackState
// Size: 0x2C
struct AttackState {
    int bestTargetID; // 0x0
    float bestTargetValue; // 0x4
    int bestTargetMemoryIndex; // 0x8
    int iterationIndex; // 0xC
    int attackGroupID; // 0x10
    int playID; // 0x14
    uchar phase; // 0x18
    int bestNonWallTargetID; // 0x1C
    float bestNonWallTargetValue; // 0x20
    int bestNonWallTargetMemoryIndex; // 0x24
    int active; // 0x28
};

// ----------------------------------------------------------------
// Attribute_Cost
// Size: 0x6
struct Attribute_Cost {
    short type; // 0x0
    short amount; // 0x2
    uchar flag; // 0x4
};

// ----------------------------------------------------------------
// BITMAPINFO256
// Size: 0x428
struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader; // 0x0
    tagRGBQUAD bmiColors[256]; // 0x28
};

// ----------------------------------------------------------------
// BYTEPoint
// Size: 0x2
struct BYTEPoint {
    uchar x; // 0x0
    uchar y; // 0x1
};

// ----------------------------------------------------------------
// Blit_Queue_Entry
// Size: 0x20
struct Blit_Queue_Entry {
    tagRECT src; // 0x0
    tagRECT dest; // 0x10
};

// ----------------------------------------------------------------
// BuildRes_id_node
// Size: 0x118
struct BuildRes_id_node {
    ulong id; // 0x0
    int dataOffset; // 0x4
    uchar * resData; // 0x8
    int resSize; // 0xC
    BuildRes_id_node * next; // 0x10
    char fName[260]; // 0x14
};

// ----------------------------------------------------------------
// BuildRes_type_node
// Size: 0x14
struct BuildRes_type_node {
    ulong type; // 0x0
    int idOffset; // 0x4
    int nIds; // 0x8
    BuildRes_id_node * idList; // 0xC
    BuildRes_type_node * next; // 0x10
};

// ----------------------------------------------------------------
// BuildingLot
// Size: 0x8
struct BuildingLot {
    int typeID; // 0x0
    uchar status; // 0x4
    uchar x; // 0x5
    uchar y; // 0x6
};

// ----------------------------------------------------------------
// CHECKSUMARRAY
// Size: 0x24
struct CHECKSUMARRAY {
    uint PlayerNo; // 0x0
    ulong WTime; // 0x4
    ulong WTurn; // 0x8
    long cs1; // 0xC
    long cs2; // 0x10
    long cs3; // 0x14
    long cs4; // 0x18
    long cs5; // 0x1C
    uint Random; // 0x20
};

// ----------------------------------------------------------------
// COMMPLAYEROPTIONS
// Size: 0x1D0
struct COMMPLAYEROPTIONS {
    uchar NeedsToBeSent; // 0x0
    ulong LastSentTime; // 0x4
    COMMSTATES ProgramState; // 0x8
    ulong CurrentTurn; // 0xC
    uchar TurnSpeedMsec; // 0x10
    ulong dcoID[10]; // 0x14
    ulong AcknowledgeAfterMsec; // 0x3C
    uchar CommandTurnIncrement; // 0x40
    int PlayerReady[10]; // 0x44
    ulong User1[10]; // 0x6C
    ulong User2[10]; // 0x94
    ulong User3[10]; // 0xBC
    ulong User4[10]; // 0xE4
    ulong User5[10]; // 0x10C
    ulong User6[10]; // 0x134
    ulong User7[10]; // 0x15C
    PLAYERHUMANITY Humanity[10]; // 0x184
    uchar InvalidPlayer[10]; // 0x1AC
    ulong Initialized; // 0x1B8
    ulong RandomSeed; // 0x1BC
    ushort HighPlayerNumber; // 0x1C0
    ushort LowPlayerNumber; // 0x1C2
    uint HostPlayerNumber; // 0x1C4
    int GameHasStarted; // 0x1C8
    ulong DataSizeToFollow; // 0x1CC
};

// ----------------------------------------------------------------
// DClipInfo_Node
// Size: 0x40
struct DClipInfo_Node {
    DClipInfo_Node * Next; // 0x0
    DClipInfo_Node * NextOnLevel; // 0x4
    int Object_ID; // 0x8
    Shape_Info * Shape; // 0xC
    int Draw_Level; // 0x10
    int Draw_X; // 0x14
    int Draw_Y; // 0x18
    int Draw_Flag; // 0x1C
    uchar * Shape_Base; // 0x20
    uchar * Color_Table; // 0x24
    int Xform_Mask; // 0x28
    int Node_Type; // 0x2C
    short x1; // 0x30
    short y1; // 0x32
    short x2; // 0x34
    short y2; // 0x36
    short x3; // 0x38
    short y3; // 0x3A
    short x4; // 0x3C
    short y4; // 0x3E
};

// ----------------------------------------------------------------
// DIDEVCAPS
// Size: 0x2C
struct DIDEVCAPS {
    ulong dwSize; // 0x0
    ulong dwFlags; // 0x4
    ulong dwDevType; // 0x8
    ulong dwAxes; // 0xC
    ulong dwButtons; // 0x10
    ulong dwPOVs; // 0x14
    ulong dwFFSamplePeriod; // 0x18
    ulong dwFFMinTimeResolution; // 0x1C
    ulong dwFirmwareRevision; // 0x20
    ulong dwHardwareRevision; // 0x24
    ulong dwFFDriverVersion; // 0x28
};

// ----------------------------------------------------------------
// DIDEVICEINSTANCEA
// Size: 0x244
struct DIDEVICEINSTANCEA {
    ulong dwSize; // 0x0
    _GUID guidInstance; // 0x4
    _GUID guidProduct; // 0x14
    ulong dwDevType; // 0x24
    char tszInstanceName[260]; // 0x28
    char tszProductName[260]; // 0x12C
    _GUID guidFFDriver; // 0x230
    ushort wUsagePage; // 0x240
    ushort wUsage; // 0x242
};

// ----------------------------------------------------------------
// DIDEVICEOBJECTDATA
// Size: 0x10
struct DIDEVICEOBJECTDATA {
    ulong dwOfs; // 0x0
    ulong dwData; // 0x4
    ulong dwTimeStamp; // 0x8
    ulong dwSequence; // 0xC
};

// ----------------------------------------------------------------
// DIDEVICEOBJECTINSTANCEA
// Size: 0x13C
struct DIDEVICEOBJECTINSTANCEA {
    ulong dwSize; // 0x0
    _GUID guidType; // 0x4
    ulong dwOfs; // 0x14
    ulong dwType; // 0x18
    ulong dwFlags; // 0x1C
    char tszName[260]; // 0x20
    ulong dwFFMaxForce; // 0x124
    ulong dwFFForceResolution; // 0x128
    ushort wCollectionNumber; // 0x12C
    ushort wDesignatorIndex; // 0x12E
    ushort wUsagePage; // 0x130
    ushort wUsage; // 0x132
    ulong dwDimension; // 0x134
    ushort wExponent; // 0x138
    ushort wReserved; // 0x13A
};

// ----------------------------------------------------------------
// DIPROPHEADER
// Size: 0x10
struct DIPROPHEADER {
    ulong dwSize; // 0x0
    ulong dwHeaderSize; // 0x4
    ulong dwObj; // 0x8
    ulong dwHow; // 0xC
};

// ----------------------------------------------------------------
// DPCAPS
// Size: 0x28
struct DPCAPS {
    ulong dwSize; // 0x0
    ulong dwFlags; // 0x4
    ulong dwMaxBufferSize; // 0x8
    ulong dwMaxQueueSize; // 0xC
    ulong dwMaxPlayers; // 0x10
    ulong dwHundredBaud; // 0x14
    ulong dwLatency; // 0x18
    ulong dwMaxLocalPlayers; // 0x1C
    ulong dwHeaderLength; // 0x20
    ulong dwTimeout; // 0x24
};

// ----------------------------------------------------------------
// DisplaySelectedObjRec
// Size: 0x14
struct DisplaySelectedObjRec {
    int active; // 0x0
    int id; // 0x4
    ulong start_time; // 0x8
    ulong duration; // 0xC
    int select_type; // 0x10
};

// ----------------------------------------------------------------
// DrawAreaNode
// Size: 0xC
struct DrawAreaNode {
    TDrawArea * DrawArea; // 0x0
    DrawAreaNode * PrevNode; // 0x4
    DrawAreaNode * NextNode; // 0x8
};

// ----------------------------------------------------------------
// FlicHead
// Size: 0x84
struct FlicHead {
    long size; // 0x0
    ushort type; // 0x4
    short frames; // 0x6
    short width; // 0x8
    short height; // 0xA
    short depth; // 0xC
    short flags; // 0xE
    long speed; // 0x10
    short reserved1; // 0x14
    long created; // 0x18
    long creator; // 0x1C
    long updated; // 0x20
    long updater; // 0x24
    short aspect_dx; // 0x28
    short aspect_dy; // 0x2A
    char reserved2[38]; // 0x2C
    char * oframe1; // 0x54
    char * oframe2; // 0x58
    char reserved3[40]; // 0x5C
};

// ----------------------------------------------------------------
// FloatHeap
// Size: 0x8
struct FloatHeap {
    uchar x; // 0x0
    uchar y; // 0x1
    float total; // 0x4
};

// ----------------------------------------------------------------
// FrameHead
// Size: 0x10
struct FrameHead {
    long size; // 0x0
    short type; // 0x4
    short chunks; // 0x6
    char reserved[8]; // 0x8
};

// ----------------------------------------------------------------
// Friendliness
// Size: 0x40
struct Friendliness {
    int Attitude[16]; // 0x0
};

// ----------------------------------------------------------------
// GroupingStruct
// Size: 0x8
struct GroupingStruct {
    int id; // 0x0
    uchar groupID; // 0x4
    uchar type; // 0x5
};

// ----------------------------------------------------------------
// ICINFO
// Size: 0x238
struct ICINFO {
    ulong dwSize; // 0x0
    ulong fccType; // 0x4
    ulong fccHandler; // 0x8
    ulong dwFlags; // 0xC
    ulong dwVersion; // 0x10
    ulong dwVersionICM; // 0x14
    ushort szName[16]; // 0x18
    ushort szDescription[128]; // 0x38
    ushort szDriver[128]; // 0x138
};

// ----------------------------------------------------------------
// IDirectDraw
// Size: 0x4
struct IDirectDraw {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectDraw2
// Size: 0x4
struct IDirectDraw2 {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectDrawClipper
// Size: 0x4
struct IDirectDrawClipper {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectDrawPalette
// Size: 0x4
struct IDirectDrawPalette {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectDrawSurface
// Size: 0x4
struct IDirectDrawSurface {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectDrawSurface3
// Size: 0x4
struct IDirectDrawSurface3 {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectInputA
// Size: 0x4
struct IDirectInputA {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectInputDeviceA
// Size: 0x4
struct IDirectInputDeviceA {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectPlay
// Size: 0x4
struct IDirectPlay {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectPlay2
// Size: 0x4
struct IDirectPlay2 {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectPlay3
// Size: 0x4
struct IDirectPlay3 {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectPlayLobby
// Size: 0x4
struct IDirectPlayLobby {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectPlayLobby2
// Size: 0x4
struct IDirectPlayLobby2 {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectSound
// Size: 0x4
struct IDirectSound {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IDirectSoundBuffer
// Size: 0x4
struct IDirectSoundBuffer {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// IUnknown
// Size: 0x4
struct IUnknown {
    char _pad_0x0[0x4];
};

// ----------------------------------------------------------------
// Item_Avail
// Size: 0x28
struct Item_Avail {
    char * name; // 0x0
    short id; // 0x4
    short pict; // 0x6
    short inventory_item_1; // 0x8
    float inventory_cost_1; // 0xC
    short inventory_item_2; // 0x10
    float inventory_cost_2; // 0x14
    short inventory_item_3; // 0x18
    float inventory_cost_3; // 0x1C
    long help_string_id; // 0x20
    long help_page_id; // 0x24
};

// ----------------------------------------------------------------
// LINEINFO
// Size: 0x10
struct LINEINFO {
    int AllTrans; // 0x0
    int MidSolid; // 0x4
    long StartX; // 0x8
    long EndX; // 0xC
};

// ----------------------------------------------------------------
// LOSTBL
// Size: 0xC
struct LOSTBL {
    int y_delta; // 0x0
    int x_left; // 0x4
    int x_right; // 0x8
};

// ----------------------------------------------------------------
// List_Info
// Size: 0x66
struct List_Info {
    char text[100]; // 0x0
    short id; // 0x64
};

// ----------------------------------------------------------------
// MGP_FloatHeap
// Size: 0x8
struct MGP_FloatHeap {
    uchar x; // 0x0
    uchar y; // 0x1
    ushort next; // 0x2
    int total; // 0x4
};

// ----------------------------------------------------------------
// MSGFORMAT_ACKNOWLEDGE_GUARANTEED
// Size: 0x8
struct MSGFORMAT_ACKNOWLEDGE_GUARANTEED {
    uchar Command; // 0x0
    uint Serialno; // 0x4
};

// ----------------------------------------------------------------
// MSGFORMAT_ALL_DONE
// Size: 0xC
struct MSGFORMAT_ALL_DONE {
    uchar Command; // 0x0
    ulong ExecuteOnTurn; // 0x4
    uchar HighLatencyCenti; // 0x8
    uchar FrameRateMsec; // 0x9
};

// ----------------------------------------------------------------
// MSGFORMAT_CHAT
// Size: 0x114
struct MSGFORMAT_CHAT {
    uchar FromGamerID; // 0x0
    uchar DestPlayers[10]; // 0x1
    uint TextSize; // 0xC
    uchar Pregame; // 0x10
    char ChatMsg[256]; // 0x11
};

// ----------------------------------------------------------------
// MSGFORMAT_CHECKSUM
// Size: 0x24
struct MSGFORMAT_CHECKSUM {
    ulong WorldTime; // 0x0
    ulong WorldTurn; // 0x4
    uint Random; // 0x8
    long cs1; // 0xC
    long cs2; // 0x10
    long cs3; // 0x14
    long cs4; // 0x18
    long cs5; // 0x1C
    ulong PingInitiated; // 0x20
};

// ----------------------------------------------------------------
// MSGFORMAT_HEADER_GUARANTEED
// Size: 0xC
struct MSGFORMAT_HEADER_GUARANTEED {
    uchar Command; // 0x0
    uchar Sequence; // 0x1
    ulong ExecuteOnTurn; // 0x4
    uint Serialno; // 0x8
};

// ----------------------------------------------------------------
// MSGFORMAT_KILL_PLAYER
// Size: 0xC
struct MSGFORMAT_KILL_PLAYER {
    uint PlayerNo; // 0x0
    ulong dcoID; // 0x4
    ulong CurrentTurn; // 0x8
};

// ----------------------------------------------------------------
// MSGFORMAT_LATENCY
// Size: 0xC
struct MSGFORMAT_LATENCY {
    uchar Command; // 0x0
    ulong Initiated; // 0x4
    ulong CurrentTurn; // 0x8
};

// ----------------------------------------------------------------
// MSGFORMAT_MISSING_PLAYER
// Size: 0x8
struct MSGFORMAT_MISSING_PLAYER {
    uchar Command; // 0x0
    ulong PlayerID; // 0x4
};

// ----------------------------------------------------------------
// MSGFORMAT_ONTURN
// Size: 0x4
struct MSGFORMAT_ONTURN {
    ulong ExecuteOnTurn; // 0x0
};

// ----------------------------------------------------------------
// MSGFORMAT_RESEND
// Size: 0x8
struct MSGFORMAT_RESEND {
    uchar Command; // 0x0
    uint Serialno; // 0x4
};

// ----------------------------------------------------------------
// MSGFORMAT_SETREADYOPTIONS
// Size: 0x28
struct MSGFORMAT_SETREADYOPTIONS {
    uchar Command; // 0x0
    uchar Ready; // 0x1
    ulong User1; // 0x4
    ulong User2; // 0x8
    ulong User3; // 0xC
    ulong User4; // 0x10
    ulong User5; // 0x14
    ulong User6; // 0x18
    ulong User7; // 0x1C
    ulong CommunicationsVersionCode; // 0x20
    uchar RGEGuaranteed; // 0x24
};

// ----------------------------------------------------------------
// MSGFORMAT_SPEEDCHANGE
// Size: 0x4
struct MSGFORMAT_SPEEDCHANGE {
    ushort BufferFrames; // 0x0
    ushort FrameSizeMsec; // 0x2
};

// ----------------------------------------------------------------
// Map_Stack
// Size: 0x18
struct Map_Stack {
    long x; // 0x0
    long y; // 0x4
    float cost; // 0x8
    float tot_cost; // 0xC
    Map_Stack * next; // 0x10
    Map_Stack * prev; // 0x14
};

// ----------------------------------------------------------------
// MouseClickInfo
// Size: 0x2C
struct MouseClickInfo {
    int object_group; // 0x0
    int self_action; // 0x4
    int self_text_id; // 0x8
    int gaia_action; // 0xC
    int gaia_text_id; // 0x10
    int ally_action; // 0x14
    int ally_text_id; // 0x18
    int neutral_action; // 0x1C
    int neutral_text_id; // 0x20
    int enemy_action; // 0x24
    int enemy_text_id; // 0x28
};

// ----------------------------------------------------------------
// NotifyEvent
// Size: 0x18
struct NotifyEvent {
    int caller; // 0x0
    int recipient; // 0x4
    int mType; // 0x8
    long p1; // 0xC
    long p2; // 0x10
    long p3; // 0x14
};

// ----------------------------------------------------------------
// ObjectMemory
// Size: 0x24
struct ObjectMemory {
    int id; // 0x0
    short type; // 0x4
    short group; // 0x6
    uchar x; // 0x8
    uchar y; // 0x9
    uchar z; // 0xA
    uchar owner; // 0xB
    short hitPoints; // 0xC
    int attackAttempts; // 0x10
    uchar kills; // 0x14
    float damageCapability; // 0x18
    float rateOfFire; // 0x1C
    float range; // 0x20
};

// ----------------------------------------------------------------
// OldUnitData
// Size: 0x10
struct OldUnitData {
    int id; // 0x0
    int data1; // 0x4
    int data2; // 0x8
    int data3; // 0xC
};

// ----------------------------------------------------------------
// OldUnitData2
// Size: 0x14
struct OldUnitData2 {
    int id; // 0x0
    int data1; // 0x4
    int data2; // 0x8
    int data3; // 0xC
    int target; // 0x10
};

// ----------------------------------------------------------------
// OrderEvent
// Size: 0x24
struct OrderEvent {
    int issuer; // 0x0
    int orderType; // 0x4
    int priority; // 0x8
    int target; // 0xC
    int targetOwner; // 0x10
    float targetX; // 0x14
    float targetY; // 0x18
    float targetZ; // 0x1C
    float range; // 0x20
};

// ----------------------------------------------------------------
// Ov_Sprite_Draw_Rec
// Size: 0x30
struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec * next; // 0x0
    Ov_Sprite_Draw_Rec * prev; // 0x4
    TShape * theShape; // 0x8
    int thefacet; // 0xC
    int world_x; // 0x10
    int world_y; // 0x14
    int flags; // 0x18
    int drawLevel; // 0x1C
    int displayfunction; // 0x20
    ulong LastDrawTime; // 0x24
    ulong DrawTimeInterval; // 0x28
    uchar * colortable; // 0x2C
};

// ----------------------------------------------------------------
// PAL_TABLE
// Size: 0x8
struct PAL_TABLE {
    int index; // 0x0
    uchar red; // 0x4
    uchar green; // 0x5
    uchar blue; // 0x6
    uchar reserved; // 0x7
};

// ----------------------------------------------------------------
// PLAYER_SCORE
// Size: 0x14
struct PLAYER_SCORE {
    int comm_id; // 0x0
    int player_id; // 0x4
    int team_id; // 0x8
    long player_score; // 0xC
    long team_score; // 0x10
};

// ----------------------------------------------------------------
// PanelNode
// Size: 0xC
struct PanelNode {
    TPanel * panel; // 0x0
    PanelNode * prev_node; // 0x4
    PanelNode * next_node; // 0x8
};

// ----------------------------------------------------------------
// XYPoint
// Size: 0x8
struct XYPoint {
    int x; // 0x0
    int y; // 0x4
};

// ----------------------------------------------------------------
// PlacementState
// Size: 0x130
struct PlacementState {
    int buildingTypeID; // 0x0
    float buildingSize; // 0x4
    char buildingName[256]; // 0x8
    int builderID; // 0x108
    int minimumDistance; // 0x10C
    int maximumDistance; // 0x110
    int active; // 0x114
    XYPoint bestPoint; // 0x118
    int bestPointValue; // 0x120
    int iterationX; // 0x124
    int randomInfluence; // 0x128
    BuildItem * buildItem; // 0x12C
};

// ----------------------------------------------------------------
// PlayerName
// Size: 0x100
struct PlayerName {
    char Name[256]; // 0x0
};

// ----------------------------------------------------------------
// Player_Start_Info
// Size: 0x10
struct Player_Start_Info {
    int Gold; // 0x0
    int Wood; // 0x4
    int Food; // 0x8
    int Stone; // 0xC
};

// ----------------------------------------------------------------
// PrimaryPt
// Size: 0x8
struct PrimaryPt {
    int x; // 0x0
    int y; // 0x4
};

// ----------------------------------------------------------------
// Production_Queue_Record
// Size: 0x4
struct Production_Queue_Record {
    short master_id; // 0x0
    short unit_count; // 0x2
};

// ----------------------------------------------------------------
// PtToPt
// Size: 0x8
struct PtToPt {
    int x; // 0x0
    int y; // 0x4
};

// ----------------------------------------------------------------
// QuadrantLog
// Size: 0xC
struct QuadrantLog {
    int numberExploredTiles; // 0x0
    int numberAttacksOnUs; // 0x4
    int numberAttacksByUs; // 0x8
};

// ----------------------------------------------------------------
// RGE_Action_Node
// Size: 0x8
struct RGE_Action_Node {
    RGE_Action * action; // 0x0
    RGE_Action_Node * next; // 0x4
};

// ----------------------------------------------------------------
// RGE_Active_Sprite_Node
// Size: 0xC
struct RGE_Active_Sprite_Node {
    RGE_Active_Sprite * node; // 0x0
    uchar order; // 0x4
    uchar count; // 0x5
    RGE_Active_Sprite_Node * next; // 0x8
};

// ----------------------------------------------------------------
// RGE_Armor_Weapon_Info
// Size: 0x4
struct RGE_Armor_Weapon_Info {
    short type; // 0x0
    short value; // 0x2
};

// ----------------------------------------------------------------
// RGE_TOB_Picts
// Size: 0x6
struct RGE_TOB_Picts {
    short count; // 0x0
    short animations; // 0x2
    short shape_index; // 0x4
};

// ----------------------------------------------------------------
// RGE_Border_Set
// Size: 0x5A0
struct RGE_Border_Set {
    uchar loaded; // 0x0
    uchar random; // 0x1
    char name[13]; // 0x2
    char pict_name[13]; // 0xF
    long resource_id; // 0x1C
    TShape * shape; // 0x20
    RGE_Sound * sound; // 0x24
    uchar map_hi_color; // 0x28
    uchar map_med_color; // 0x29
    uchar map_low_color; // 0x2A
    uchar is_animated; // 0x2B
    short animation_frames; // 0x2C
    short pause_frames; // 0x2E
    float interval; // 0x30
    float pause_between_loops; // 0x34
    short frame; // 0x38
    short draw_frame; // 0x3A
    float animate_last; // 0x3C
    uchar frame_changed; // 0x40
    uchar drawn; // 0x41
    RGE_TOB_Picts borders[19][12]; // 0x42
    uchar draw_tile; // 0x59A
    short underlay_terrain; // 0x59C
    short border_style; // 0x59E
};

// ----------------------------------------------------------------
// RGE_Campaign_Header
// Size: 0x108
struct RGE_Campaign_Header {
    long version; // 0x0
    char name[255]; // 0x4
    long scenario_num; // 0x104
};

// ----------------------------------------------------------------
// RGE_Check_Node
// Size: 0x14
struct RGE_Check_Node {
    RGE_Static_Object * node; // 0x0
    float dx; // 0x4
    float dy; // 0x8
    uchar flag; // 0xC
    RGE_Check_Node * next; // 0x10
};

// ----------------------------------------------------------------
// RGE_Cliffs_Hot_Spots
// Size: 0xC
struct RGE_Cliffs_Hot_Spots {
    long x; // 0x0
    long y; // 0x4
    long radius; // 0x8
};

// ----------------------------------------------------------------
// RGE_Cliffs_Info
// Size: 0x4C0
struct RGE_Cliffs_Info {
    long number_of_cliffs; // 0x0
    long number_of_cliffs_variance; // 0x4
    long average_cliff_size; // 0x8
    long cliff_size_variance; // 0xC
    long cliff_terrain_spacing; // 0x10
    long cliff_to_cliff_spacing; // 0x14
    RGE_Cliffs_Hot_Spots hot_spots[99]; // 0x18
    long hot_spot_num; // 0x4BC
};

// ----------------------------------------------------------------
// RGE_Command_AI_Order
// Size: 0x28
struct RGE_Command_AI_Order {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar issuer; // 0x2
    int recipient; // 0x4
    short orderType; // 0x8
    uchar orderPriority; // 0xA
    int target; // 0xC
    uchar targetOwner; // 0x10
    float targetX; // 0x14
    float targetY; // 0x18
    float targetZ; // 0x1C
    float range; // 0x20
    uchar immediate; // 0x24
    uchar inFront; // 0x25
};

// ----------------------------------------------------------------
// RGE_Command_Add_Attribute
// Size: 0x8
struct RGE_Command_Add_Attribute {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar attr_id; // 0x2
    float attr_amount; // 0x4
};

// ----------------------------------------------------------------
// RGE_Command_Add_To_Group
// Size: 0x10
struct RGE_Command_Add_To_Group {
    uchar command; // 0x0
    uchar player_id; // 0x1
    int groupCommander; // 0x4
    float groupRange; // 0x8
    int newUnit; // 0xC
};

// ----------------------------------------------------------------
// XYZBYTEPoint
// Size: 0x3
struct XYZBYTEPoint {
    uchar x; // 0x0
    uchar y; // 0x1
    uchar z; // 0x2
};

// ----------------------------------------------------------------
// RGE_Command_Add_Waypoint
// Size: 0x18
struct RGE_Command_Add_Waypoint {
    uchar command; // 0x0
    uchar player_id; // 0x1
    int recipient; // 0x4
    uchar numberWaypoints; // 0x8
    XYZBYTEPoint waypoint[5]; // 0x9
};

// ----------------------------------------------------------------
// RGE_Command_Create
// Size: 0x14
struct RGE_Command_Create {
    uchar command; // 0x0
    short obj_catagory; // 0x2
    uchar player_id; // 0x4
    float location_x; // 0x8
    float location_y; // 0xC
    float location_z; // 0x10
};

// ----------------------------------------------------------------
// RGE_Command_Create_Group
// Size: 0x74
struct RGE_Command_Create_Group {
    uchar command; // 0x0
    uchar player_id; // 0x1
    int groupCommander; // 0x4
    float groupRange; // 0x8
    int unitsToGroup[25]; // 0xC
    uchar numberUnitsToGroup; // 0x70
};

// ----------------------------------------------------------------
// RGE_Command_Destroy_Group
// Size: 0x8
struct RGE_Command_Destroy_Group {
    uchar command; // 0x0
    uchar player_id; // 0x1
    int groupCommander; // 0x4
};

// ----------------------------------------------------------------
// RGE_Command_Formation
// Size: 0xC
struct RGE_Command_Formation {
    uchar command; // 0x0
    int unitNum; // 0x4
    int formationID; // 0x8
};

// ----------------------------------------------------------------
// RGE_Command_Give_Attribute
// Size: 0x8
struct RGE_Command_Give_Attribute {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar to_player_id; // 0x2
    uchar attr_id; // 0x3
    float attr_amount; // 0x4
};

// ----------------------------------------------------------------
// RGE_Command_Group_AI_Order
// Size: 0x24
struct RGE_Command_Group_AI_Order {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar issuer; // 0x2
    uchar recipient_count; // 0x3
    short orderType; // 0x4
    uchar orderPriority; // 0x6
    int target; // 0x8
    uchar targetOwner; // 0xC
    float targetX; // 0x10
    float targetY; // 0x14
    float targetZ; // 0x18
    float range; // 0x1C
    uchar immediate; // 0x20
    uchar inFront; // 0x21
};

// ----------------------------------------------------------------
// RGE_Command_Group_Waypoint
// Size: 0x4
struct RGE_Command_Group_Waypoint {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    uchar x; // 0x2
    uchar y; // 0x3
};

// ----------------------------------------------------------------
// RGE_Obj_Info
// Size: 0x4
struct RGE_Obj_Info {
    long id; // 0x0
};

// ----------------------------------------------------------------
// RGE_Command_Order
// Size: 0x14
struct RGE_Command_Order {
    uchar command; // 0x0
    RGE_Obj_Info target; // 0x4
    uchar unit_num; // 0x8
    float location_x; // 0xC
    float location_y; // 0x10
};

// ----------------------------------------------------------------
// RGE_Command_Pause
// Size: 0x2
struct RGE_Command_Pause {
    uchar command; // 0x0
    uchar unit_num; // 0x1
};

// ----------------------------------------------------------------
// RGE_Command_Remove_From_Group
// Size: 0xC
struct RGE_Command_Remove_From_Group {
    uchar command; // 0x0
    uchar player_id; // 0x1
    int groupCommander; // 0x4
    int unit; // 0x8
};

// ----------------------------------------------------------------
// RGE_Command_Resign
// Size: 0x4
struct RGE_Command_Resign {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar comm_player_id; // 0x2
    uchar dropped; // 0x3
};

// ----------------------------------------------------------------
// RGE_Command_Stop
// Size: 0x2
struct RGE_Command_Stop {
    uchar command; // 0x0
    uchar unit_num; // 0x1
};

// ----------------------------------------------------------------
// RGE_Damage_Sprite_Info
// Size: 0x8
struct RGE_Damage_Sprite_Info {
    RGE_Sprite * sprite; // 0x0
    uchar damage_percent; // 0x4
    uchar flag; // 0x5
};

// ----------------------------------------------------------------
// RGE_Effect
// Size: 0x2C
struct RGE_Effect {
    short id; // 0x0
    char name[31]; // 0x2
    short string_table_id; // 0x22
    short effect_list_num; // 0x24
    RGE_Effect_Command * effect_list; // 0x28
};

// ----------------------------------------------------------------
// RGE_Effect_Command
// Size: 0xC
struct RGE_Effect_Command {
    uchar command; // 0x0
    short change_num1; // 0x2
    short change_num2; // 0x4
    short change_num3; // 0x6
    float change_amount; // 0x8
};

// ----------------------------------------------------------------
// RGE_Elevation_Data
// Size: 0x8
struct RGE_Elevation_Data {
    long elevation_num; // 0x0
    RGE_Elevation_Data_Entry * elevation; // 0x4
};

// ----------------------------------------------------------------
// RGE_Elevation_Data_Entry
// Size: 0x18
struct RGE_Elevation_Data_Entry {
    long elevation_percent; // 0x0
    long elevation; // 0x4
    long clumps; // 0x8
    long spacing; // 0xC
    long base_terrain_type; // 0x10
    long base_elevation_type; // 0x14
};

// ----------------------------------------------------------------
// RGE_Elevation_Hot_Spots
// Size: 0x10
struct RGE_Elevation_Hot_Spots {
    long x; // 0x0
    long y; // 0x4
    long radius; // 0x8
    long fade; // 0xC
};

// ----------------------------------------------------------------
// RGE_Elevation_Info_Line
// Size: 0x18
struct RGE_Elevation_Info_Line {
    long elevation_size; // 0x0
    long elevation; // 0x4
    long clumps; // 0x8
    long spacing; // 0xC
    long base_elevation; // 0x10
    long base_terrain_type; // 0x14
};

// ----------------------------------------------------------------
// RGE_Elevation_Info
// Size: 0xF80
struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99]; // 0x0
    long elevation_num; // 0x948
    RGE_Elevation_Hot_Spots hot_spots[99]; // 0x94C
    long hot_spot_num; // 0xF7C
};

// ----------------------------------------------------------------
// RGE_Font
// Size: 0xC
struct RGE_Font {
    void * font; // 0x0
    long font_wid; // 0x4
    long font_hgt; // 0x8
};

// ----------------------------------------------------------------
// RGE_Game_Options
// Size: 0xA8
struct RGE_Game_Options {
    float versionValue; // 0x0
    uchar scenarioGameValue; // 0x4
    char scenarioNameValue[128]; // 0x5
    uchar singlePlayerGameValue; // 0x85
    uchar multiplayerGameValue; // 0x86
    uchar mapXSizeValue; // 0x87
    uchar mapYSizeValue; // 0x88
    uchar mapZSizeValue; // 0x89
    uchar allowCheatCodesValue; // 0x8A
    uchar mpPathFindingValue; // 0x8B
    uchar cheatNotificationValue; // 0x8C
    uchar fullVisibilityValue; // 0x8D
    uchar fogOfWarValue; // 0x8E
    uchar coloredChatValue; // 0x8F
    uchar numberPlayersValue; // 0x90
    uchar gameDeveloperModeValue; // 0x91
    uchar playerCDAndVersionValue[9]; // 0x92
    uchar difficultyValue; // 0x9B
    uchar playerTeamValue[9]; // 0x9C
};

// ----------------------------------------------------------------
// RGE_Info_Line
// Size: 0x14
struct RGE_Info_Line {
    float clump_num; // 0x0
    short percent_of_tiles_covered; // 0x4
    short percent_updown; // 0x6
    short min_elevation; // 0x8
    short max_elevation; // 0xA
    short terrain_type; // 0xC
    short terrain_base; // 0xE
    char obj_id; // 0x10
};

// ----------------------------------------------------------------
// RGE_Land_Data
// Size: 0x2C
struct RGE_Land_Data {
    long map_edge_buffer[4]; // 0x0
    long map_edge_fade; // 0x10
    long land_placement_edge; // 0x14
    long base_terrain; // 0x18
    long grown_land_percent; // 0x1C
    long id; // 0x20
    long land_num; // 0x24
    RGE_Land_Data_Entry * land; // 0x28
};

// ----------------------------------------------------------------
// RGE_Land_Data_Entry
// Size: 0x2C
struct RGE_Land_Data_Entry {
    long land_id; // 0x0
    uchar terrain_type; // 0x4
    long land_avoidance_tiles; // 0x8
    long base_square_radius; // 0xC
    uchar zone; // 0x10
    uchar placement_type; // 0x11
    long x; // 0x14
    long y; // 0x18
    uchar amount_of_land_used_percent; // 0x1C
    uchar by_player_flag; // 0x1D
    long radius; // 0x20
    long fade; // 0x24
    long clumpiness_factor; // 0x28
};

// ----------------------------------------------------------------
// RGE_Land_Info_Line
// Size: 0x34
struct RGE_Land_Info_Line {
    long land_size; // 0x0
    long terrain_type; // 0x4
    long x; // 0x8
    long y; // 0xC
    long base_size; // 0x10
    long area; // 0x14
    uchar zone; // 0x18
    long clumpiness_factor; // 0x1C
    long wall_1_avoidance_line; // 0x20
    long wall_2_avoidance_line; // 0x24
    long wall_3_avoidance_line; // 0x28
    long wall_4_avoidance_line; // 0x2C
    uchar wall_fade; // 0x30
};

// ----------------------------------------------------------------
// RGE_Land_Info
// Size: 0x1438
struct RGE_Land_Info {
    RGE_Land_Info_Line land[99]; // 0x0
    long land_num; // 0x141C
    uchar base_terrain; // 0x1420
    long wall_1_avoidance_line; // 0x1424
    long wall_2_avoidance_line; // 0x1428
    long wall_3_avoidance_line; // 0x142C
    long wall_4_avoidance_line; // 0x1430
    uchar wall_fade; // 0x1434
};

// ----------------------------------------------------------------
// RGE_Land_Point_Info_Line
// Size: 0x10
struct RGE_Land_Point_Info_Line {
    long x; // 0x0
    long y; // 0x4
    long id; // 0x8
    long player_id; // 0xC
};

// ----------------------------------------------------------------
// RGE_Map_Data
// Size: 0x8
struct RGE_Map_Data {
    long map_num; // 0x0
    RGE_Map_Data_Entry * maps; // 0x4
};

// ----------------------------------------------------------------
// RGE_Object_Data
// Size: 0x8
struct RGE_Object_Data {
    long object_num; // 0x0
    RGE_Object_Data_Entry * objects; // 0x4
};

// ----------------------------------------------------------------
// RGE_Terrain_Data
// Size: 0x8
struct RGE_Terrain_Data {
    long terrain_num; // 0x0
    RGE_Terrain_Data_Entry * terrain; // 0x4
};

// ----------------------------------------------------------------
// RGE_Map_Data_Entry
// Size: 0x48
struct RGE_Map_Data_Entry {
    long map_id; // 0x0
    RGE_Land_Data land_info; // 0x4
    RGE_Terrain_Data terrain_info; // 0x30
    RGE_Object_Data object_info; // 0x38
    RGE_Elevation_Data elevation_info; // 0x40
};

// ----------------------------------------------------------------
// RGE_Map_Gen_Info
// Size: 0x520
struct RGE_Map_Gen_Info {
    short base_terrain; // 0x0
    RGE_Info_Line land; // 0x4
    RGE_Info_Line elevation[20]; // 0x18
    short elevation_num; // 0x1A8
    RGE_Info_Line terrain[20]; // 0x1AC
    short terrain_num; // 0x33C
    RGE_Info_Line objects[20]; // 0x340
    short objects_num; // 0x4D0
    short player_num; // 0x4D2
    short player_x[9]; // 0x4D4
    short player_y[9]; // 0x4E6
    short player_connect[9]; // 0x4F8
    short player_base_land[9]; // 0x50A
    short space_between_islands_or_edge; // 0x51C
};

// ----------------------------------------------------------------
// RGE_Map_Image_Line
// Size: 0x6
struct RGE_Map_Image_Line {
    short tile_row; // 0x0
    short start_x; // 0x2
    short line_len; // 0x4
};

// ----------------------------------------------------------------
// RGE_Map_Tile_Row
// Size: 0x24
struct RGE_Map_Tile_Row {
    short image_line; // 0x0
    uchar draw; // 0x2
    short row_len; // 0x4
    float col_step; // 0x8
    float col_extra; // 0xC
    short map_col; // 0x10
    short map_row; // 0x12
    short draw_wid; // 0x14
    float draw_step; // 0x18
    short num_tiles; // 0x1C
    float ratio; // 0x20
};

// ----------------------------------------------------------------
// RGE_Object_Data_Entry
// Size: 0x2C
struct RGE_Object_Data_Entry {
    long obj_id; // 0x0
    long terrain; // 0x4
    uchar group_flag; // 0x8
    uchar scale_flag; // 0x9
    long object_number_per_group; // 0xC
    long object_number_varience; // 0x10
    long number_of_groups; // 0x14
    long group_area; // 0x18
    long player_id; // 0x1C
    long land_id; // 0x20
    long land_inner_radius; // 0x24
    long land_outer_radius; // 0x28
};

// ----------------------------------------------------------------
// RGE_Object_Info_Line
// Size: 0x30
struct RGE_Object_Info_Line {
    long obj_id; // 0x0
    long terrain; // 0x4
    uchar group_flag; // 0x8
    uchar scale_flag; // 0x9
    long object_number_per_group; // 0xC
    long object_number_varience; // 0x10
    long number_of_groups; // 0x14
    long group_area; // 0x18
    long player_id; // 0x1C
    long land_id; // 0x20
    long land_inner_radius; // 0x24
    long land_outer_radius; // 0x28
    long object_exclusion_zone; // 0x2C
};

// ----------------------------------------------------------------
// RGE_Object_Info
// Size: 0x18C8
struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99]; // 0x0
    long object_num; // 0x1290
    RGE_Land_Point_Info_Line lands[99]; // 0x1294
    long land_num; // 0x18C4
};

// ----------------------------------------------------------------
// RGE_Object_Node
// Size: 0x10
struct RGE_Object_Node {
    RGE_Static_Object * node; // 0x0
    RGE_Object_Node * next; // 0x4
    RGE_Object_Node * prev; // 0x8
    uchar centered; // 0xC
};

// ----------------------------------------------------------------
// RGE_Pick_Info
// Size: 0x14
struct RGE_Pick_Info {
    float x; // 0x0
    float y; // 0x4
    short scr_x; // 0x8
    short scr_y; // 0xA
    RGE_Static_Object * object; // 0xC
    RGE_Tile * tile; // 0x10
};

// ----------------------------------------------------------------
// RGE_Pick_Obj_Info
// Size: 0xC
struct RGE_Pick_Obj_Info {
    int object_id; // 0x0
    short confidence; // 0x4
    short draw_level; // 0x6
    short draw_x; // 0x8
    short draw_y; // 0xA
};

// ----------------------------------------------------------------
// RGE_Picture_List
// Size: 0x10
struct RGE_Picture_List {
    short picture_num; // 0x0
    RGE_Sprite * sprite; // 0x4
    short offset_x; // 0x8
    short offset_y; // 0xA
    short facet; // 0xC
};

// ----------------------------------------------------------------
// RGE_Player_Info
// Size: 0x2AC
struct RGE_Player_Info {
    char name[9][65]; // 0x0
    char type[9]; // 0x249
    char tribe[9]; // 0x252
    short color[9]; // 0x25C
    long player_id_hash[9]; // 0x270
    short player_num; // 0x294
    char * scenario; // 0x298
    RGE_Map_Gen_Info * map_info; // 0x29C
    short map_type; // 0x2A0
    short map_width; // 0x2A2
    short map_height; // 0x2A4
    short ai_info; // 0x2A6
    uchar campaign; // 0x2A8
};

// ----------------------------------------------------------------
// RGE_Prog_Info
// Size: 0x1238
struct RGE_Prog_Info {
    char prog_name[101]; // 0x0
    char prog_version[21]; // 0x65
    char prog_title[121]; // 0x7A
    char world_db_file[261]; // 0xF3
    char game_data_file[261]; // 0x1F8
    char vol_name[261]; // 0x2FD
    ulong vol_ser_num; // 0x404
    int verify_cd; // 0x408
    int max_players_per_cd; // 0x40C
    void * instance; // 0x410
    void * prev_instance; // 0x414
    char registry_key[256]; // 0x418
    char cmd_line[256]; // 0x518
    int show_wnd_flag; // 0x618
    char icon_name[41]; // 0x61C
    char menu_name[41]; // 0x645
    char pal_file[261]; // 0x66E
    char cursor_file[261]; // 0x773
    int max_players; // 0x878
    int check_expiration; // 0x87C
    short expire_month; // 0x880
    short expire_day; // 0x882
    short expire_year; // 0x884
    ulong update_interval; // 0x888
    int check_multi_copies; // 0x88C
    int skip_startup; // 0x890
    int full_screen; // 0x894
    int fixed_window_size; // 0x898
    int use_dir_draw; // 0x89C
    int use_sys_mem; // 0x8A0
    int use_music; // 0x8A4
    int use_sound; // 0x8A8
    int use_cd_audio; // 0x8AC
    int use_ima; // 0x8B0
    int use_midi; // 0x8B4
    int use_wave_music; // 0x8B8
    int fast_view; // 0x8BC
    int auto_scroll; // 0x8C0
    long mouse_scroll_edge; // 0x8C4
    ulong mouse_scroll_interval; // 0x8C8
    float mouse_scroll_max_dist; // 0x8CC
    ulong key_scroll_interval; // 0x8D0
    float key_scroll_max_dist; // 0x8D4
    float key_scroll_object_move; // 0x8D8
    short interface_style; // 0x8DC
    long main_wid; // 0x8E0
    long main_hgt; // 0x8E4
    _GUID game_guid; // 0x8E8
    _GUID zone_guid; // 0x8F8
    char data_dir[261]; // 0x908
    char graphics_dir[261]; // 0xA0D
    char save_dir[261]; // 0xB12
    char scenario_dir[261]; // 0xC17
    char campaign_dir[261]; // 0xD1C
    char sounds_dir[261]; // 0xE21
    char resource_dir[261]; // 0xF26
    char ai_dir[261]; // 0x102B
    char avi_dir[261]; // 0x1130
};

// ----------------------------------------------------------------
// RGE_Random_Map_Module_List
// Size: 0x8
struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module * module; // 0x0
    RGE_Random_Map_Module_List * next; // 0x4
};

// ----------------------------------------------------------------
// RGE_SPick_Info
// Size: 0x14
struct RGE_SPick_Info {
    int object_id; // 0x0
    short confidence; // 0x4
    short draw_level; // 0x6
    short draw_x; // 0x8
    short draw_y; // 0xA
    RGE_SPick_Info * next; // 0xC
    RGE_SPick_Info * prev; // 0x10
};

// ----------------------------------------------------------------
// RGE_Scenario_File_Entry
// Size: 0x10C
struct RGE_Scenario_File_Entry {
    long time; // 0x0
    RGE_Scenario_Header * scenario_header; // 0x4
    char name[260]; // 0x8
};

// ----------------------------------------------------------------
// RGE_Scenario_Info
// Size: 0x1
struct RGE_Scenario_Info {
    uchar scenario_status; // 0x0
};

// ----------------------------------------------------------------
// RGE_Scenario_Offset
// Size: 0x208
struct RGE_Scenario_Offset {
    long size; // 0x0
    long offset; // 0x4
    char name[255]; // 0x8
    char file_name[255]; // 0x107
};

// ----------------------------------------------------------------
// RGE_Shallows_Info_Line
// Size: 0x8
struct RGE_Shallows_Info_Line {
    long x; // 0x0
    long y; // 0x4
};

// ----------------------------------------------------------------
// RGE_Shallows_Info
// Size: 0x31C
struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line shallows[99]; // 0x0
    long shallows_num; // 0x318
};

// ----------------------------------------------------------------
// RGE_Sound_Info
// Size: 0x24
struct RGE_Sound_Info {
    char name[13]; // 0x0
    long resource_id; // 0x10
    short percent; // 0x14
    TDigital * digital_sound; // 0x18
    uchar loaded; // 0x1C
    ulong time; // 0x20
};

// ----------------------------------------------------------------
// RGE_Sound_List
// Size: 0x14
struct RGE_Sound_List {
    RGE_Sound * sound[3]; // 0x0
    short frame[3]; // 0xC
};

// ----------------------------------------------------------------
// RGE_Terrain_Data_Entry
// Size: 0x18
struct RGE_Terrain_Data_Entry {
    long terrain_percent; // 0x0
    long terrain_type; // 0x4
    long clumps; // 0x8
    long spacing; // 0xC
    long base_terrain_type; // 0x10
    long clumpiness_factor; // 0x14
};

// ----------------------------------------------------------------
// RGE_Terrain_Hot_Spots
// Size: 0x10
struct RGE_Terrain_Hot_Spots {
    long x; // 0x0
    long y; // 0x4
    long radius; // 0x8
    long fade; // 0xC
};

// ----------------------------------------------------------------
// RGE_Terrain_Info_Line
// Size: 0x20
struct RGE_Terrain_Info_Line {
    long terrain_size; // 0x0
    long terrain_generated; // 0x4
    long terrain_type; // 0x8
    long clumps; // 0xC
    long spacing; // 0x10
    long base_terrain_type; // 0x14
    long clumpiness_factor; // 0x18
    long avoid_hot_spots; // 0x1C
};

// ----------------------------------------------------------------
// RGE_Terrain_Info
// Size: 0x1298
struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99]; // 0x0
    long terrain_num; // 0xC60
    RGE_Terrain_Hot_Spots hot_spots[99]; // 0xC64
    long hot_spot_num; // 0x1294
};

struct RGE_Tile {
    short screen_xpos;              // 0x0
    short screen_ypos;              // 0x2
    uchar tile_type;                // 0x4
    
    // Offset 0x5 (Bitfields for 1 byte)
    uchar terrain_type : 5; 
    uchar height : 3;
    
    // Offset 0x6 (Bitfields for 1 byte)
    uchar border_type : 4;
    uchar border_shape : 4;
    
    uchar last_drawn_as;            // 0x7
    uchar last_drawn_shape;         // 0x8
    uchar draw_as;                  // 0x9
    uchar draw_attribute;           // 0xA
    uchar last_drawn_shape2;        // 0xB
    
    RGE_Object_List objects;        // 0xC (Size 0xC)
    
    // Total Size: 0xC + 0xC = 0x18
};

static_assert(sizeof(RGE_Tile) == 0x18, "Wrong size for RGE_Tile");
static_assert(offsetof(RGE_Tile, objects) == 0xC, "Wrong offset for RGE_Tile::objects");

// ----------------------------------------------------------------
// RGE_Tile_List_Node
// Size: 0x8
struct RGE_Tile_List_Node {
    int col; // 0x0
    int row; // 0x4
};

// ----------------------------------------------------------------
// RGE_Tile_Set
// Size: 0x198
struct RGE_Tile_Set {
    uchar loaded; // 0x0
    uchar random; // 0x1
    char name[13]; // 0x2
    char pict_name[13]; // 0xF
    long resource_id; // 0x1C
    TShape * shape; // 0x20
    RGE_Sound * sound; // 0x24
    uchar map_hi_color; // 0x28
    uchar map_med_color; // 0x29
    uchar map_low_color; // 0x2A
    uchar map_lt_cliff_color; // 0x2B
    uchar map_rt_cliff_color; // 0x2C
    uchar passable_terrain; // 0x2D
    uchar impassable_terrain; // 0x2E
    uchar is_animated; // 0x2F
    short animation_frames; // 0x30
    short pause_frames; // 0x32
    float interval; // 0x34
    float pause_between_loops; // 0x38
    short frame; // 0x3C
    short draw_frame; // 0x3E
    float animate_last; // 0x40
    uchar frame_changed; // 0x44
    uchar drawn; // 0x45
    RGE_TOB_Picts tiles[19]; // 0x46
    short terrain_to_draw; // 0xB8
    short rows; // 0xBA
    short cols; // 0xBC
    short borders[32]; // 0xBE
    short obj_types[30]; // 0xFE
    short obj_density[30]; // 0x13A
    uchar obj_placement_flag[30]; // 0x176
    short num_obj_type; // 0x194
};

// ----------------------------------------------------------------
// RGE_Tile_Size
// Size: 0x6
struct RGE_Tile_Size {
    short width; // 0x0
    short height; // 0x2
    short y_delta; // 0x4
};

// ----------------------------------------------------------------
// RGE_Time_Entry
// Size: 0x30
struct RGE_Time_Entry {
    float time; // 0x0
    uchar command; // 0x4
    short obj_type; // 0x6
    uchar player; // 0x8
    float x; // 0xC
    float y; // 0x10
    float z; // 0x14
    short task; // 0x18
    RGE_Static_Object * this_obj; // 0x1C
    short this_obj_id; // 0x20
    RGE_Static_Object * target_obj; // 0x24
    short target_obj_id; // 0x28
    RGE_Time_Entry * next; // 0x2C
};

// ----------------------------------------------------------------
// RGE_Timing_Info
// Size: 0x20
struct RGE_Timing_Info {
    ulong accum_time; // 0x0
    ulong last_time; // 0x4
    ulong start_time; // 0x8
    int include_in_total; // 0xC
    int is_summary; // 0x10
    ulong last_single_time; // 0x14
    ulong max_time; // 0x18
    ulong last_max_time; // 0x1C
};

// ----------------------------------------------------------------
// RGE_Victory_Entry
// Size: 0x34
struct RGE_Victory_Entry {
    uchar command; // 0x0
    long obj_type; // 0x4
    RGE_Player * target_player; // 0x8
    float x0; // 0xC
    float y0; // 0x10
    float x1; // 0x14
    float y1; // 0x18
    long number; // 0x1C
    long count; // 0x20
    RGE_Static_Object * this_obj; // 0x24
    RGE_Static_Object * target_obj; // 0x28
    uchar victory_group; // 0x2C
    uchar ally_flag; // 0x2D
    uchar state; // 0x2E
    uchar checked_flag; // 0x2F
    RGE_Victory_Entry * next; // 0x30
};

// ----------------------------------------------------------------
// RGE_Victory_Point_Entry
// Size: 0x1C
struct RGE_Victory_Point_Entry {
    uchar command; // 0x0
    uchar state; // 0x1
    uchar id; // 0x2
    uchar group; // 0x3
    long attribute; // 0x4
    long amount; // 0x8
    long points; // 0xC
    long curr_points; // 0x10
    float curr_attribute_amount; // 0x14
    RGE_Victory_Point_Entry * next; // 0x18
};

// ----------------------------------------------------------------
// ResFileHdr
// Size: 0x114
struct ResFileHdr {
    uchar * mapped_file; // 0x0
    int handle; // 0x4
    resfile_header * header; // 0x8
    ResFileHdr * next; // 0xC
    char res_name[260]; // 0x10
};

// ----------------------------------------------------------------
// ResourceMemory
// Size: 0x14
struct ResourceMemory {
    int id; // 0x0
    uchar x; // 0x4
    uchar y; // 0x5
    uchar gatherAttempts; // 0x6
    int gatherValue; // 0x8
    uchar valid; // 0xC
    uchar gone; // 0xD
    uchar dropDistance; // 0xE
    uchar resourceType; // 0xF
    int dropsiteID; // 0x10
};

// ----------------------------------------------------------------
// SEs
// Size: 0x238
struct SEs {
    char Name[255]; // 0x0
    char Password[255]; // 0xFF
    _GUID AppGUID; // 0x200
    _GUID SessGUID; // 0x210
    ulong CurrentPlayers; // 0x220
    ulong MaxPlayers; // 0x224
    ulong User1; // 0x228
    ulong User2; // 0x22C
    ulong User3; // 0x230
    ulong User4; // 0x234
};

// ----------------------------------------------------------------
// SLhape_File_Header
// Size: 0x20
struct SLhape_File_Header {
    char Version[4]; // 0x0
    long Num_Shapes; // 0x4
    char Comment[24]; // 0x8
};

// ----------------------------------------------------------------
// SNDOBJ
// Size: 0x14
struct SNDOBJ {
    uchar * pbWaveData; // 0x0
    ulong cbWaveSize; // 0x4
    int iAlloc; // 0x8
    int iCurrent; // 0xC
    IDirectSoundBuffer * Buffers[1]; // 0x10
};

// ----------------------------------------------------------------
// SP_Victory_Info
// Size: 0x3C
struct SP_Victory_Info {
    int ObjType; // 0x0
    int AllFlag; // 0x4
    int PlayerID; // 0x8
    int DestObjID; // 0xC
    float x1; // 0x10
    float y1; // 0x14
    float x2; // 0x18
    float y2; // 0x1C
    int VictoryType; // 0x20
    int Amount; // 0x24
    int AttribType; // 0x28
    int obj_ID; // 0x2C
    int dest_obj_ID; // 0x30
    RGE_Static_Object * obj; // 0x34
    RGE_Static_Object * dest_obj; // 0x38
};

// ----------------------------------------------------------------
// SPs
// Size: 0x60
struct SPs {
    char Name[80]; // 0x0
    _GUID * GUID; // 0x50
    ulong MajVersion; // 0x54
    ulong MinVersion; // 0x58
    int Active; // 0x5C
};

// ----------------------------------------------------------------
// Shape_File_Header
// Size: 0x8
struct Shape_File_Header {
    long version; // 0x0
    long shape_num; // 0x4
};

// ----------------------------------------------------------------
// Shape_Header
// Size: 0x18
struct Shape_Header {
    long bounds; // 0x0
    long origin; // 0x4
    long xmin; // 0x8
    long ymin; // 0xC
    long xmax; // 0x10
    long ymax; // 0x14
};

// ----------------------------------------------------------------
// Shape_Info
// Size: 0x20
struct Shape_Info {
    ulong Shape_Data_Offsets; // 0x0
    ulong Shape_Outline_Offset; // 0x4
    long Reserved1; // 0x8
    long Reserved2; // 0xC
    long Width; // 0x10
    long Height; // 0x14
    long Hotspot_X; // 0x18
    long Hotspot_Y; // 0x1C
};

// ----------------------------------------------------------------
// Shape_Offsets
// Size: 0x8
struct Shape_Offsets {
    long shape; // 0x0
    long palette; // 0x4
};

// ----------------------------------------------------------------
// Special_Events
// Size: 0xB0
struct Special_Events {
    long time_slice; // 0x0
    long X_line_pos; // 0x4
    long Y_line_pos; // 0x8
    long intermediate_y_line_segment; // 0xC
    uchar player_id; // 0x10
    uchar player_color; // 0x11
    uchar event; // 0x12
    long pop_total; // 0x14
    long interger_value_1; // 0x18
    long interger_value_2; // 0x1C
    long start_x; // 0x20
    long start_y; // 0x24
    long start_txt_x1; // 0x28
    long start_txt_y1; // 0x2C
    long start_txt_x2; // 0x30
    long start_txt_y2; // 0x34
    int text_length1; // 0x38
    char text1[50]; // 0x3C
    int text_length2; // 0x70
    char text2[50]; // 0x74
    int icon_flag; // 0xA8
    Special_Events * next; // 0xAC
};

// ----------------------------------------------------------------
// TRANSINFO
// Size: 0x18
struct TRANSINFO {
    int AnyTrans; // 0x0
    long x; // 0x4
    long y; // 0x8
    long w; // 0xC
    long h; // 0x10
    LINEINFO * LineInfo; // 0x14
};

// ----------------------------------------------------------------
// TRIBE_Cliff_Info
// Size: 0x10
struct TRIBE_Cliff_Info {
    long info[4]; // 0x0
};

// ----------------------------------------------------------------
// TRIBE_Command_Attack_Ground
// Size: 0xC
struct TRIBE_Command_Attack_Ground {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    float location_x; // 0x4
    float location_y; // 0x8
};

// ----------------------------------------------------------------
// TRIBE_Command_Build
// Size: 0x14
struct TRIBE_Command_Build {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    uchar unit_player_id; // 0x2
    float location_x; // 0x4
    float location_y; // 0x8
    short obj_id; // 0xC
    int unique_id; // 0x10
};

// ----------------------------------------------------------------
// TRIBE_Command_Build_Wall
// Size: 0x10
struct TRIBE_Command_Build_Wall {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    uchar unit_player_id; // 0x2
    uchar x1; // 0x3
    uchar y1; // 0x4
    uchar x2; // 0x5
    uchar y2; // 0x6
    short obj_id; // 0x8
    int unique_id; // 0xC
};

// ----------------------------------------------------------------
// TRIBE_Command_Cancel_Build
// Size: 0x8
struct TRIBE_Command_Cancel_Build {
    uchar command; // 0x0
    int unit_id; // 0x4
};

// ----------------------------------------------------------------
// TRIBE_Command_Explore
// Size: 0xC
struct TRIBE_Command_Explore {
    uchar command; // 0x0
    uchar numUnits; // 0x1
    uchar unit_player_id; // 0x2
    float targetXPosition; // 0x4
    float targetYPosition; // 0x8
};

// ----------------------------------------------------------------
// TRIBE_Command_Game
// Size: 0x10
struct TRIBE_Command_Game {
    uchar command; // 0x0
    uchar game_command; // 0x1
    short var1; // 0x2
    short var2; // 0x4
    float var3; // 0x8
    short var4; // 0xC
};

// ----------------------------------------------------------------
// TRIBE_Command_Give_Attribute
// Size: 0xC
struct TRIBE_Command_Give_Attribute {
    uchar command; // 0x0
    uchar player_id; // 0x1
    uchar to_player_id; // 0x2
    uchar attr_id; // 0x3
    float attr_amount; // 0x4
    float attr_cost; // 0x8
};

// ----------------------------------------------------------------
// TRIBE_Command_Make
// Size: 0x10
struct TRIBE_Command_Make {
    uchar command; // 0x0
    int unit_id; // 0x4
    uchar unit_player_id; // 0x8
    short obj_id; // 0xA
    int unique_id; // 0xC
};

// ----------------------------------------------------------------
// TRIBE_Command_Queue
// Size: 0xC
struct TRIBE_Command_Queue {
    uchar command; // 0x0
    long bldg_id; // 0x4
    short train_id; // 0x8
    short train_count; // 0xA
};

// ----------------------------------------------------------------
// TRIBE_Command_Repair
// Size: 0x8
struct TRIBE_Command_Repair {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    RGE_Obj_Info target; // 0x4
};

// ----------------------------------------------------------------
// TRIBE_Command_Research
// Size: 0x10
struct TRIBE_Command_Research {
    uchar command; // 0x0
    int unit_id; // 0x4
    uchar unit_player_id; // 0x8
    short tech_id; // 0xA
    int unique_id; // 0xC
};

// ----------------------------------------------------------------
// TRIBE_Command_Trade_Attribute
// Size: 0x8
struct TRIBE_Command_Trade_Attribute {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    long attribute; // 0x4
};

// ----------------------------------------------------------------
// TRIBE_Command_Unload
// Size: 0xC
struct TRIBE_Command_Unload {
    uchar command; // 0x0
    uchar unit_num; // 0x1
    float location_x; // 0x4
    float location_y; // 0x8
};

// ----------------------------------------------------------------
// TRIBE_Game_Options
// Size: 0x6C
struct TRIBE_Game_Options {
    MapSize mapSizeValue; // 0x0
    MapType mapTypeValue; // 0x4
    int animalsValue; // 0x8
    int predatorsValue; // 0xC
    VictoryType victoryTypeValue; // 0x10
    int victoryAmountValue; // 0x14
    uchar civilizationValue[9]; // 0x18
    int scenarioPlayerValue[9]; // 0x24
    uchar playerColorValue[9]; // 0x48
    uchar computerNameValue[9]; // 0x51
    uchar allowTradingValue; // 0x5A
    uchar longCombatValue; // 0x5B
    uchar randomizePositionsValue; // 0x5C
    uchar fullTechTreeValue; // 0x5D
    ResourceLevel resourceLevelValue; // 0x60
    Age startingAgeValue; // 0x64
    uchar startingUnitsValue; // 0x68
    uchar deathMatchValue; // 0x69
    uchar popLimitValue; // 0x6A
};

// ----------------------------------------------------------------
// TRIBE_History_Entry
// Size: 0x1
struct TRIBE_History_Entry {
    uchar population; // 0x0
};

// ----------------------------------------------------------------
// TRIBE_History_Events
// Size: 0x10
struct TRIBE_History_Events {
    uchar event; // 0x0
    long time; // 0x4
    long world_time; // 0x8
    TRIBE_History_Events * next; // 0xC
};

// ----------------------------------------------------------------
// TRIBE_Master_Cliff_Info
// Size: 0x28
struct TRIBE_Master_Cliff_Info {
    long id; // 0x0
    long facet; // 0x4
    long id2; // 0x8
    long facet2; // 0xC
    TRIBE_Cliff_Info info; // 0x10
    float offset_x; // 0x20
    float offset_y; // 0x24
};

// ----------------------------------------------------------------
// TRIBE_Zone_High_Score_Info
// Size: 0x18
struct TRIBE_Zone_High_Score_Info {
    long score; // 0x0
    uchar civ; // 0x4
    char player_name[16]; // 0x5
    uchar num_allies; // 0x15
};

// ----------------------------------------------------------------
// TRIBE_Zone_Player_Info
// Size: 0x28
struct TRIBE_Zone_Player_Info {
    char name[16]; // 0x0
    long score; // 0x10
    uchar winner; // 0x14
    uchar civ_played; // 0x15
    uchar civ_random; // 0x16
    uchar player_no; // 0x17
    uchar team_no; // 0x18
    uchar game_outcome; // 0x19
    long tool_time; // 0x1C
    long bronze_time; // 0x20
    long iron_time; // 0x24
};

// ----------------------------------------------------------------
// TRIBE_Zone_Map_Info
// Size: 0xC
struct TRIBE_Zone_Map_Info {
    uchar Map_Size; // 0x0
    uchar Map_Type; // 0x1
    short Pop_Limit; // 0x2
    uchar Victory_Condition; // 0x4
    uchar Start_Age; // 0x5
    uchar Resources; // 0x6
    uchar Full_Tech; // 0x7
    uchar Fixed_Pos; // 0x8
    uchar Reveal_Map; // 0x9
    uchar Death_Match; // 0xA
};

// ----------------------------------------------------------------
// TRIBE_Zone_Info
// Size: 0x1FC
struct TRIBE_Zone_Info {
    uchar number_of_players; // 0x0
    uchar number_of_computer_players; // 0x1
    char scenario_name[32]; // 0x2
    ulong game_time; // 0x24
    TRIBE_Zone_High_Score_Info total_score; // 0x28
    TRIBE_Zone_High_Score_Info religion_score; // 0x40
    TRIBE_Zone_High_Score_Info economy_score; // 0x58
    TRIBE_Zone_High_Score_Info combat_score; // 0x70
    TRIBE_Zone_High_Score_Info research_score; // 0x88
    TRIBE_Zone_Player_Info player_info[8]; // 0xA0
    TRIBE_Zone_Map_Info map_info; // 0x1E0
    uchar cheats_enabled; // 0x1EC
    uchar game_end_condition_code; // 0x1ED
    ulong database_checksum; // 0x1F0
    ulong code_checksum; // 0x1F4
    ulong program_version; // 0x1F8
};

// ----------------------------------------------------------------
// Tech_Player_Tree
// Size: 0x8
struct Tech_Player_Tree {
    float research_done; // 0x0
    short state; // 0x4
};

// ----------------------------------------------------------------
// Tech_Tree
// Size: 0x3C
struct Tech_Tree {
    char * name; // 0x0
    short pre_reqs[4]; // 0x4
    short pre_reqs_required; // 0xC
    short attribute[3]; // 0xE
    short attribute_cost[3]; // 0x14
    uchar attribute_used[3]; // 0x1A
    short research; // 0x1E
    short effect; // 0x20
    short track; // 0x22
    short icon; // 0x24
    uchar button_location; // 0x26
    short build_obj_id; // 0x28
    short string_id; // 0x2A
    short string_id2; // 0x2C
    long help_string_id; // 0x30
    long help_page_id; // 0x34
    long hotkey_id; // 0x38
};

// ----------------------------------------------------------------
// TextNode
// Size: 0x10
struct TextNode {
    char * text; // 0x0
    char * text2; // 0x4
    long id; // 0x8
    TextNode * next_node; // 0xC
};

// ----------------------------------------------------------------
// Tile_BlackEdge_Table
// Size: 0x4
struct Tile_BlackEdge_Table {
    VSpanMiniList * black_UNdraw; // 0x0
};

// ----------------------------------------------------------------
// Tile_FogEdge_Table
// Size: 0x8
struct Tile_FogEdge_Table {
    VSpanMiniList * normal_draw; // 0x0
    VSpanMiniList * fog_draw; // 0x4
};

// ----------------------------------------------------------------
// Trade_Avail
// Size: 0xC
struct Trade_Avail {
    RGE_Player * player; // 0x0
    RGE_Static_Object * dock; // 0x4
    float inventory; // 0x8
};

// ----------------------------------------------------------------
// UnitData
// Size: 0x18
struct UnitData {
    int id; // 0x0
    int data1; // 0x4
    int data2; // 0x8
    int data3; // 0xC
    int target; // 0x10
    ulong lastTaskTime; // 0x14
};

// ----------------------------------------------------------------
// VC_LOG
// Size: 0x24
struct VC_LOG {
    int world_time; // 0x0
    int player_id; // 0x4
    int action; // 0x8
    int object_id; // 0xC
    int x1; // 0x10
    int y1; // 0x14
    int x2; // 0x18
    int y2; // 0x1C
    int supress; // 0x20
};

// ----------------------------------------------------------------
// VISIBLE_RESOURCE_REC
// Size: 0x8
struct VISIBLE_RESOURCE_REC {
    int object_id; // 0x0
    uchar distance; // 0x4
    uchar zone; // 0x5
    uchar pos_x; // 0x6
    uchar pos_y; // 0x7
};

// ----------------------------------------------------------------
// VISIBLE_UNIT_PTR
// Size: 0x8
struct VISIBLE_UNIT_PTR {
    VISIBLE_UNIT_REC * unit_list; // 0x0
    short list_size; // 0x4
    short used; // 0x6
};

// ----------------------------------------------------------------
// VISIBLE_UNIT_REC
// Size: 0x8
struct VISIBLE_UNIT_REC {
    int object_id; // 0x0
    uchar distance; // 0x4
    uchar player; // 0x5
    uchar pos_x; // 0x6
    uchar pos_y; // 0x7
};

// ----------------------------------------------------------------
// VSpanMiniList
// Size: 0x3
struct VSpanMiniList {
    uchar Y_delta; // 0x0
    uchar X_start; // 0x1
    uchar X_end; // 0x2
};

// ----------------------------------------------------------------
// VSpan_Node
// Size: 0x10
struct VSpan_Node {
    VSpan_Node * Next; // 0x0
    VSpan_Node * Prev; // 0x4
    int StartPx; // 0x8
    int EndPx; // 0xC
};

// ----------------------------------------------------------------
// Victory_StartInfo
// Size: 0x18
struct Victory_StartInfo {
    int MP_Conquest; // 0x0
    int MP_Ruins; // 0x4
    int MP_Artifacts; // 0x8
    int MP_Discoveries; // 0xC
    int MP_Exploration; // 0x10
    int MP_Gold; // 0x14
};

// ----------------------------------------------------------------
// WSAData
// Size: 0x190
struct WSAData {
    ushort wVersion; // 0x0
    ushort wHighVersion; // 0x2
    char szDescription[257]; // 0x4
    char szSystemStatus[129]; // 0x105
    ushort iMaxSockets; // 0x186
    ushort iMaxUdpDg; // 0x188
    char * lpVendorInfo; // 0x18C
};

// ----------------------------------------------------------------
// Waypoint
// Size: 0x10
struct Waypoint {
    float x; // 0x0
    float y; // 0x4
    float z; // 0x8
    uchar facetToNextWaypoint; // 0xC
};

// ----------------------------------------------------------------
// XYZPoint
// Size: 0xC
struct XYZPoint {
    int x; // 0x0
    int y; // 0x4
    int z; // 0x8
};

// ----------------------------------------------------------------
// Zone_Queue
// Size: 0xC
struct Zone_Queue {
    long x; // 0x0
    long y; // 0x4
    Zone_Queue * next; // 0x8
};

// ----------------------------------------------------------------
// combined_options
// Size: 0x114
struct combined_options {
    RGE_Game_Options rge_options; // 0x0
    TRIBE_Game_Options tribe_options; // 0xA8
};

// ----------------------------------------------------------------
// waveformat_tag
// Size: 0xE
struct waveformat_tag {
    ushort wFormatTag; // 0x0
    ushort nChannels; // 0x2
    ulong nSamplesPerSec; // 0x4
    ulong nAvgBytesPerSec; // 0x8
    ushort nBlockAlign; // 0xC
};

// ----------------------------------------------------------------
// pcmwaveformat_tag
// Size: 0x10
struct pcmwaveformat_tag {
    waveformat_tag wf; // 0x0
    ushort wBitsPerSample; // 0xE
};

// ----------------------------------------------------------------
// rdlg_list_info
// Size: 0x66
struct rdlg_list_info {
    char text[100]; // 0x0
    short id; // 0x64
};

// ----------------------------------------------------------------
// res_file_type_info
// Size: 0x8
struct res_file_type_info {
    char extension[4]; // 0x0
    ulong rType; // 0x4
};

// ----------------------------------------------------------------
// resfile_header
// Size: 0x40
struct resfile_header {
    char banner_msg[40]; // 0x0
    char version[4]; // 0x28
    char password[12]; // 0x2C
    int num_res_types; // 0x38
    int directory_size; // 0x3C
};

// ----------------------------------------------------------------
// resfile_id_dir_node
// Size: 0xC
struct resfile_id_dir_node {
    ulong id; // 0x0
    long itemOffset; // 0x4
    long itemSize; // 0x8
};

// ----------------------------------------------------------------
// resfile_type_dir_node
// Size: 0xC
struct resfile_type_dir_node {
    ulong type; // 0x0
    long dirOffset; // 0x4
    long numID; // 0x8
};

// ----------------------------------------------------------------
// tm
// Size: 0x24
struct tm {
    int tm_sec; // 0x0
    int tm_min; // 0x4
    int tm_hour; // 0x8
    int tm_mday; // 0xC
    int tm_mon; // 0x10
    int tm_year; // 0x14
    int tm_wday; // 0x18
    int tm_yday; // 0x1C
    int tm_isdst; // 0x20
};
