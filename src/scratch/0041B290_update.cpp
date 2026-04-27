// VA: 0041B290 update
// PDB source: asprite.cpp
// RGE_Active_Animated_Sprite::update(float, float)

struct RGE_Sprite {
    char gap_00[0x5E];
    short frame_count;      // +0x5E
    char gap_60[0x04];
    float field_64;         // +0x64
    float animate_speed;    // +0x68
    float field_6C;         // +0x6C
    char flags;             // +0x70
};

struct RGE_Active_Animated_Sprite {
    void* vtable;           // +0x00
    RGE_Sprite* sprite;     // +0x04
    char byte_08;            // +0x08
    char gap_09_13[0x0B];    // +0x09 to +0x13
    short frame;            // +0x14
    char gap_16_17[2];
    float animate_interval; // +0x18
    float animate_last;     // +0x1C
    short last_frame;       // +0x20
    char frame_changed;     // +0x22
    char frame_looped;     // +0x23
    char animate_flag;      // +0x24

    void update(float param_1, float param_2);
};

extern "C" long __cdecl __ftol();

void RGE_Active_Animated_Sprite::update(float param_1, float param_2)
{
    frame_changed = 0;
    frame_looped = 0;

    if (!sprite || !animate_flag)
        goto end;

    if (frame >= sprite->frame_count)
        frame = sprite->frame_count - 1;

    if (!(sprite->flags & 1))
        goto end;

    animate_last = param_1 + animate_last;

    if (animate_last < animate_interval)
        goto end;

    frame_changed = 1;
    last_frame = frame;

    {
        float tmp = animate_last;
        float ratio = animate_last / animate_interval;
        int ft = __ftol();
        int count = (short)ft;
        animate_last = tmp - (float)count * animate_interval;

        if (param_2 > 0.0f || sprite->field_64 < 0.0f) {
            unsigned char ft_low = (unsigned char)ft;
            frame = (short)((int)(unsigned short)frame + (int)ft_low);
            if (frame >= sprite->frame_count)
                frame_looped = 1;
        }
    }

    {
        if (sprite->field_64 < 0.0f || sprite->field_6C < 0.0f)
            animate_interval = sprite->animate_speed;
        else
            animate_interval = sprite->animate_speed * sprite->field_64 / param_2;

        if (animate_interval < 0.001f)
            animate_interval = 0.001f;
    }

    if (!frame_looped)
        goto end;

    {
        if (sprite->field_6C <= 0.0f || animate_flag == 2) {
            animate_flag = 1;
            while (frame >= sprite->frame_count)
                frame -= sprite->frame_count;
        } else {
            animate_interval = sprite->field_6C
                - (float)((int)frame - (int)sprite->frame_count) * sprite->animate_speed;
            frame = sprite->frame_count - 1;
            animate_flag = 2;
            frame_looped = 0;
        }
    }

end:
    if (frame_looped && (sprite->flags & 8)) {
        animate_flag = 0;
        frame = sprite->frame_count - 1;
    }
}
