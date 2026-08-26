// Authentic candidate wrapper for C:\\msdev\\work\\age1_x1\\asp_list.cpp.
//
// PDB owner includes follow source-line order.  The wrapper uses the reviewed
// class surfaces for RGE_Active_Sprite_List (0x0C bytes) and
// RGE_Active_Sprite (0x14 bytes).  Focused owner files keep their narrow
// declarations when compiled alone.
//
// Evidence-backed flags: /nologo /c /O2 /Oy /GX from config/flags/default_gx.rsp.
// No manual vptr writes, fake slots, assembly, volatility, register steering,
// synthetic padding, or generated-destructor source is used.
// BINARY NOTE: FPO names 0041A660 as vector-deleting. Natural VC5 emits the
// ??_E identity as a weak external to the byte-identical ??_G body. Strict
// validation proves that compiler-generated fallback without array-new use.

#define ASP_LIST_SHARED_CONTEXT 1

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Active_Sprite;
struct RGE_Active_Sprite_Node;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    virtual void set_offset(long param_1, long param_2);
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4,
                       long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual short frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short param_1);
    virtual unsigned char frame_passed(short param_1);
    virtual unsigned char looped();
    virtual short get_facetindex(short param_1);
    virtual unsigned char get_frame(short* param_1, short* param_2, short* param_3,
                                    short* param_4, long param_5);
    virtual void setToFirstFrame();
    void destroy(int flags);

    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    int check_for_shadows();
    unsigned char get_lowest_draw_level();

    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;
    char gap_16[0x2];
    long animate_interval;
    long animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;
    char gap_25[0x3];

    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Sprite {
public:
    int check_for_shadows();
    RGE_Active_Sprite* make_active_sprite();
};

class RGE_Static_Object {
public:
    void remove_shadows();
};

struct RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4,
                       short param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);

// BINARY NOTE: FPO names load_node as the protected virtual owner (MAE), not
// the public virtual form (UAE) used by its focused standalone declaration.
protected:
    virtual unsigned char load_node(int param_1, unsigned char param_2,
                                    RGE_Sprite** param_3);

public:
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner);
    void load(int param_1, RGE_Sprite** param_2);
    void save(int file);
    void delete_list();
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* list);
    void add_sprite(RGE_Sprite* sprite, unsigned char order, long offset_x, long offset_y);
    void remove_sprite(RGE_Sprite* sprite);
    int check_for_shadows();
    unsigned char get_lowest_draw_level();
    unsigned char get_frame(short& param_1, short& param_2, short& param_3,
                            short& param_4, RGE_Sprite* param_5, long param_6);
};

#include "matching/0041A640_RGE_Active_Sprite_List.cpp"
#include "matching/0041A680_RGE_Active_Sprite_List.cpp"
#include "matching/0041A690_load.cpp"
#include "matching/0041A6F0_load_node.cpp"
#include "matching/0041A820_save.cpp"
#include "matching/0041A860_delete_list.cpp"
#include "matching/0041A8B0_copy_sprite_list.cpp"
#include "matching/0041A8F0_use_sprite_list.cpp"
#include "verified_logic/0041A910_add_sprite.cpp"
#include "matching/0041A9B0_remove_sprite.cpp"
#include "matching/0041AA20_update.cpp"
#include "matching/0041AA50_draw.cpp"
#include "matching/0041AAA0_normal_draw.cpp"
#include "matching/0041AAE0_shadow_draw.cpp"
#include "matching/0041AB20_frame.cpp"
#include "matching/0041AB60_is_animating.cpp"
#include "matching/0041AB90_set_frame.cpp"
#include "matching/0041ABC0_frame_passed.cpp"
#include "matching/0041AC00_looped.cpp"
#include "matching/0041AC30_get_facetindex.cpp"
#include "matching/0041AC70_get_frame.cpp"
#include "matching/0041ACC0_get_lowest_draw_level.cpp"
#include "matching/0041ACF0_check_for_shadows.cpp"

#undef ASP_LIST_SHARED_CONTEXT
