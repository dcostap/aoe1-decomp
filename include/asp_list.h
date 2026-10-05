#ifndef AOE1_ASP_LIST_H
#define AOE1_ASP_LIST_H

// Compiler-facing declarations for the original asp_list.cpp module.

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;
class RGE_Static_Object;
struct RGE_Active_Sprite_Node;

class RGE_Active_Sprite {
  public:
    virtual ~RGE_Active_Sprite();
    virtual void set_offset(long x, long y);
    virtual void save(int outfile);
    virtual void update(float time, float speed);
    virtual void draw(
        short facet, long x, long y, long sx, long sy, RGE_Color_Table* player_color, TDrawArea* draw_area
    );
    virtual void normal_draw(short facet, long x, long y, RGE_Color_Table* player_color, TDrawArea* draw_area);
    virtual void shadow_draw(
        short facet, long x, long y, RGE_Color_Table* player_color, TDrawArea* draw_area, unsigned char flag
    );
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short new_frame);
    virtual unsigned char frame_passed(short passed_frame);
    virtual unsigned char looped();
    virtual short get_facetindex(short facet);
    virtual unsigned char get_frame(short& min_x, short& min_y, short& max_x, short& max_y, long facet);
    virtual void setToFirstFrame();

    RGE_Sprite* sprite;
    unsigned char type;
    long offset_x;
    long offset_y;

    int check_for_shadows();
    unsigned char get_lowest_draw_level();

    RGE_Active_Sprite(RGE_Sprite* new_sprite);
    RGE_Active_Sprite(int infile, RGE_Sprite** sprites);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
  public:
    RGE_Active_Animated_Sprite(RGE_Sprite* new_sprite);
    short frame;
    float animate_interval;
    float animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;

    RGE_Active_Animated_Sprite(int infile, RGE_Sprite** sprites);
    virtual ~RGE_Active_Animated_Sprite();

    virtual void save(int outfile);
    virtual void update(float time, float speed);
    virtual void draw(
        short facet, long x, long y, long sx, long sy, RGE_Color_Table* player_color, TDrawArea* draw_area
    );
    virtual void normal_draw(short facet, long x, long y, RGE_Color_Table* player_color, TDrawArea* draw_area);
    virtual void shadow_draw(
        short facet, long x, long y, RGE_Color_Table* player_color, TDrawArea* draw_area, unsigned char flag
    );
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short new_frame);
    virtual unsigned char frame_passed(short passed_frame);
    virtual unsigned char looped();
    virtual short get_facetindex(short facet);
    virtual unsigned char get_frame(short& min_x, short& min_y, short& max_x, short& max_y, long facet);
    virtual void setToFirstFrame();
};

struct RGE_Active_Sprite_Node {
  public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
  public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float time, float speed);
    virtual void draw(
        short facet, short x, short y, short sx, short sy, RGE_Color_Table* player_color, TDrawArea* draw_area
    );
    virtual void normal_draw(short facet, short x, short y, RGE_Color_Table* player_color, TDrawArea* draw_area);
    virtual void shadow_draw(
        short facet, short x, short y, RGE_Color_Table* player_color, TDrawArea* draw_area, unsigned char flag
    );
    virtual unsigned char is_animating(RGE_Sprite* sprite);
    virtual void set_frame(RGE_Sprite* sprite, short new_frame);
    virtual unsigned char frame_passed(RGE_Sprite* sprite, short pass_frame);
    virtual unsigned char looped(RGE_Sprite* sprite);
    virtual short get_facetindex(RGE_Sprite* sprite, short facet);

  protected:
    virtual unsigned char load_node(int infile, unsigned char type, RGE_Sprite** sprites);

  public:
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner_in);
    void load(int infile, RGE_Sprite** sprites);
    void save(int outfile);
    void delete_list();
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* temp_list);
    void add_sprite(RGE_Sprite* sprite, unsigned char order, long x, long y);
    void remove_sprite(RGE_Sprite* sprite);
    int check_for_shadows();
    unsigned char get_lowest_draw_level();
    unsigned char get_frame(short& min_x, short& min_y, short& max_x, short& max_y, RGE_Sprite* sprite, long facet);
};

typedef char asp_list_active_sprite_size_check[(sizeof(RGE_Active_Sprite) == 0x14) ? 1 : -1];
typedef char asp_list_active_animated_sprite_size_check[(sizeof(RGE_Active_Animated_Sprite) == 0x28) ? 1 : -1];
typedef char asp_list_active_sprite_node_size_check[(sizeof(RGE_Active_Sprite_Node) == 0x0C) ? 1 : -1];
typedef char asp_list_active_sprite_list_size_check[(sizeof(RGE_Active_Sprite_List) == 0x0C) ? 1 : -1];

#endif
