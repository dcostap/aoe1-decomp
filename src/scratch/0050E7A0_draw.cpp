// VA: 0050E7A0 TRIBE_Master_Building_Object::draw (420B)
// PDB source: tm_b_obj.cpp lines 228-260
// Draws building sprite and optional shadow/selection overlay
//
// STATUS: First implementation attempt - needs proper class hierarchy for exact match
#include "..\..\include\game_globals.h"

struct RGE_Sprite;
struct RGE_Color_Table;
struct RGE_Map;
struct DClipInfo_List;
struct TDrawArea;

// Offset layout for TRIBE_Master_Building_Object base fields
// Key offsets known from asm: sprite=0x18, flags=0x16C/0x16E, coords=0x30/0x34
struct TRIBE_Master_Building_Object {
    char field_00[0x18];
    RGE_Sprite* construction_sprite;    // +0x18
    char field_1C[0x14];
    float coord_x;                      // +0x30
    float coord_y;                      // +0x34
    char field_38[0x134];
    unsigned char building_connect_flag; // +0x16C
    short building_facet;               // +0x16E
    
    void draw(TDrawArea* area, short sx, short sy, RGE_Color_Table* ct,
              long p5, long p6, int p7, unsigned char p8);
};

extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

// C wrappers for member function calls
void RGE_Sprite__draw(RGE_Sprite* sprite, int a, int b, int c, int d, int e, int f,
                      RGE_Color_Table* ct, TDrawArea* area, int g);

void RGE_Map__get_point(RGE_Map* map, short* rx, short* ry, float a, float b, float zero, short sx, short sy);

void DClipInfo_List__AddGDINode(DClipInfo_List* list, int a, int b, int c, int d, int e, int f,
                                 int g, int h, int i, int j, int k, int l, int m);

void TRIBE_Master_Building_Object::draw(TDrawArea* area, short sx, short sy, RGE_Color_Table* ct,
                                          long p5, long p6, int p7, unsigned char p8) {
    if (!construction_sprite) return;
    
    int ivar4;
    if (building_connect_flag) {
        if (p5) {
            ivar4 = (int)(p5 - 1);
        } else {
            ivar4 = 2;
        }
    } else {
        ivar4 = (int)building_facet;
    }
    
    RGE_Sprite__draw(construction_sprite, ivar4, 0, (int)(short)sx, (int)(short)sy, 
                     (int)(short)sx, (int)(short)sy, ct, area, 0);
    
    if (!p7) return;
    
    RGE_Map* map = *(RGE_Map**)((char*)rge_base_game + 0x3F4);
    int map_get_y = *(int*)((char*)map + 0x28);
    RGE_Map* mp = (RGE_Map*)map_get_y;
    // Can't easily call RGE_Map::get_point without proper declaration
    // The rest needs proper RGE_Map/RGE_Sprite type declarations
}
