// Auto-generated scaffold header
#pragma once

#include <windows.h>
#include <ddraw.h>
#include <dsound.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

// Common MSVC-ish aliases (kept simple for scaffolding)
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

// NOTE: `FormatType` is used throughout many dumped UI panel vtable signatures (e.g. TEasy_Panel::create_input/create_edit).
// Immutable references (`Pnl_inp.cpp.asm`, `pnl_edit.cpp.asm`) show numeric comparisons against values 7 (multi-line) and 8 (percent).
// TODO: Confirm the exact original name for value 0 (no filtering / general text).
enum FormatType : int {
    FormatAny = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

// External struct/class forward declarations
struct TDrawArea;
struct TDrawSystem;
class TShape;
class TTaunt;
struct TSound_Driver;
class TMusic_System;
struct TDigital;
class TRegistry;
class TDebuggingLog;
class TCommunications_Handler;
class TMousePointer;
class TChat;
class TPanel;
class TButtonPanel;
struct TPanelSystem;
class TPicture;

// RGE and TRIBE game classes
class RGE_Base_Game;
class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_Player;
class RGE_Master_Player;
class RGE_Static_Object;
class RGE_Moving_Object;
class RGE_Animated_Object;
class RGE_Action_Object;
class RGE_Sound;
class RGE_Sound_Info;
class RGE_Sprite;
class RGE_Effects;
class RGE_Command;
class RGE_Scenario;
class RGE_Timeline;
class RGE_Font;
class RGE_Scenario_Header;
struct RGE_Player_Info;
class RGE_Color_Table;
class RGE_Map;
class RGE_Action_List;
class RGE_Action;
struct RGE_Task;
class RGE_Action_Node;
class RGE_Effect;
class RGE_Damage_Sprite_Info;
class RGE_Picture_List;
class RGE_Sound_List;
class RGE_Active_Sprite_List;
class RGE_Active_Sprite_Node;
class RGE_Object_List;
class RGE_Task_List;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Combat_Object;
class RGE_Master_Action_Object;
class TRIBE_Game;
class TRIBE_World;
class TRIBE_Player;
struct TRIBE_Tech;
class TRIBE_Player_Tech;
class TRIBE_History_Info;
class TRIBE_Screen_Game;

// AI related
class AIPlayBook;
class UnitAIModule;
class TribeMainDecisionAIModule;

// Map and Terrain
struct RGE_Tile;
struct RGE_Tile_List_Node;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class Visible_Resource_Manager;

// Lists and nodes
struct RGE_Object_Node;
struct DrawAreaNode;
struct PanelNode;

// Utility types
struct XYZBYTEPoint;
struct XYZPoint;
struct XYPoint;
struct Waypoint;
struct Path;
struct LOSTBL;
struct RGE_Armor_Weapon_Info;
class RGE_Victory_Conditions;
class TSpan_List_Manager;

struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader;
    tagRGBQUAD bmiColors[256];
};

// Forward declare these structs — real definitions are in dedicated headers
struct RGE_Tile_Size;
struct RGE_Tile_Set;
struct RGE_Border_Set;

class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;

struct Tile_FogEdge_Table;
struct Tile_BlackEdge_Table;
struct Blit_Queue_Entry;
struct RGE_SPick_Info;
struct DClipInfo_List;
struct Ov_Sprite_Draw_Rec;
struct DisplaySelectedObjRec;

// Stubs for templates found in PDB
template <typename T> struct ManagedArray {
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};
