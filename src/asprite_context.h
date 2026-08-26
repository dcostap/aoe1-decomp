#ifndef ASPRITE_CONTEXT_H
#define ASPRITE_CONTEXT_H

class RGE_Color_Table;
class TDrawArea;
class TShape;
class RGE_Picture_List;
class RGE_Sound;
class RGE_Sound_List;
class RGE_Active_Sprite;
class RGE_Active_Animated_Sprite;

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    union {
        short frame_num;
        short frame_count;
    };
    short facet_num;
    char gap_62[2];
    union {
        float base_speed;
        float animate_speed;
    };
    union {
        float duration;
        float anim_elapsed;
    };
    float pause_between_loops;
    union {
        unsigned char flags;
        unsigned char flag;
    };
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    void load_facets(RGE_Sprite** facets);
    void play_sound(short param_1, short param_2, short param_3);
    unsigned char get_facetindex(long facet, long frame, long* frame_out);
    unsigned char draw(long facet, long param_2, long param_3, long param_4,
                       long param_5, long param_6,
                       RGE_Color_Table* color_table, TDrawArea* draw_area,
                       unsigned char color_index);
    unsigned char normal_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area);
    unsigned char shadow_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area, unsigned char color_index);
    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y,
                  long frame, long facet);
    unsigned char get_lowest_draw_level();
    int check_for_shadows();
};

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Active_Sprite(RGE_Sprite* sprite);
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);

    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[3];
    long offset_x;
    long offset_y;

    virtual void set_offset(long param_1, long param_2);
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4,
                      long param_5, RGE_Color_Table* param_6,
                      TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short param_1);
    virtual unsigned char frame_passed(short param_1);
    virtual unsigned char looped();
    virtual short get_facetindex(short param_1);
    virtual unsigned char get_frame(short& param_1, short& param_2,
                                    short& param_3, short& param_4, long param_5);
    virtual void setToFirstFrame();

    unsigned char get_lowest_draw_level();
    int check_for_shadows();
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    RGE_Active_Animated_Sprite(RGE_Sprite* sprite);
    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
    virtual ~RGE_Active_Animated_Sprite();

    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4,
                      long param_5, RGE_Color_Table* param_6,
                      TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short param_1);
    virtual unsigned char frame_passed(short param_1);
    virtual unsigned char looped();
    virtual short get_facetindex(short param_1);
    virtual unsigned char get_frame(short& param_1, short& param_2,
                                    short& param_3, short& param_4, long param_5);
    virtual void setToFirstFrame();

    union {
        short frame;
        short field_14;
    };
    char gap_16[2];
    float animate_interval;
    float animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;
};

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern double DAT_0056ee78;
extern float DAT_0056ee80;
extern int __cdecl debug_rand(char* file, int line);
extern RGE_Sprite* fog_next_shape;

#endif
