// VA: 0041B290 update
// PDB source: asprite.cpp
// Attempt log:
// - baseline: decompiler-shaped flat object and guessed time fields; 360 diff bytes,
//   with a 6-byte overrun and an extra stack local.
// - layout/behavior: restored the RGE_Active_Sprite base, canonical RGE_Sprite
//   animation fields, double zero/minimum constants, and the natural short frame
//   count conversion.  The update owns elapsed time, frame state, and loop mode.
// - variant: the reverse-loop arm must assign frame from sprite->frame_num - 1
//   before setting animate_flag and clearing frame_looped; this reproduces the
//   oracle's CX load/decrement and exact 409-byte function without fake aliases.

#ifndef ASPRITE_FULL_TU
class RGE_Color_Table;
class TDrawArea;

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame_num;                 // +0x5E
    char gap_60[0x04];
    float base_speed;                // +0x64
    float duration;                  // +0x68
    float pause_between_loops;       // +0x6C
    unsigned char flag;              // +0x70
};

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4,
                      long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
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
    RGE_Sprite* sprite;              // +0x04
    unsigned char type;              // +0x08
    char gap_09[0x03];
    long offset_x;                   // +0x0C
    long offset_y;                   // +0x10
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;                     // +0x14
    char gap_16[0x02];
    float animate_interval;          // +0x18
    float animate_last;              // +0x1C
    short last_frame;                // +0x20
    unsigned char frame_changed;     // +0x22
    unsigned char frame_looped;      // +0x23
    unsigned char animate_flag;      // +0x24

    virtual void update(float param_1, float param_2);
};

extern double DAT_0056ee78;
#endif
void RGE_Active_Animated_Sprite::update(float param_1, float param_2)
{
    frame_changed = 0;
    frame_looped = 0;

    if (sprite != 0 && animate_flag != 0) {
        if (frame >= sprite->frame_num)
            frame = sprite->frame_num - 1;

        if ((sprite->flag & 1) != 0) {
            animate_last = param_1 + animate_last;

            if (animate_last >= animate_interval) {
                frame_changed = 1;
                last_frame = frame;

                short count = (short)(animate_last / animate_interval);
                animate_last = animate_last - (float)count * animate_interval;

                if (param_2 > 0.0 || sprite->base_speed == 0.0) {
                    frame += (unsigned char)count;
                    if (frame >= sprite->frame_num)
                        frame_looped = 1;
                }

                if (sprite->base_speed == 0.0 || param_2 == 0.0)
                    animate_interval = sprite->duration;
                else
                    animate_interval = sprite->duration * sprite->base_speed / param_2;

                if (animate_interval < DAT_0056ee78)
                    animate_interval = 0.001f;

                if (frame_looped != 0) {
                    if (sprite->pause_between_loops <= 0.0 || animate_flag == 2) {
                        animate_flag = 1;
                        while (frame >= sprite->frame_num)
                            frame -= sprite->frame_num;
                    } else {
                        animate_interval = sprite->pause_between_loops
                            - (float)(frame - sprite->frame_num) * sprite->duration;
                        frame = sprite->frame_num - 1;
                        animate_flag = 2;
                        frame_looped = 0;
                    }
                }
            }
        }
    }

    if (frame_looped != 0 && (sprite->flag & 8) != 0) {
        animate_flag = 0;
        frame = sprite->frame_num - 1;
    }
}
