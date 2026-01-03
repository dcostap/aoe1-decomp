#pragma once
#include "../common.h"
#include "Picture.h"

typedef enum PictureType : unsigned int {
    Picture = 0,
    Shape = 1,
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];                       // 0xF4
    long res_id;                             // 0x100
    int size_from_pic;                       // 0x104
    int keep_loaded;                         // 0x108
    int own_pic;                             // 0x10C
    PictureType pic_type;                    // 0x110
    TPicture* pic;                           // 0x114
    TShape* shape;                           // 0x118

    TPicturePanel();
    virtual ~TPicturePanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, long param_8, int param_9, int param_10);
    virtual void set_picture(TShape* param_1, long param_2);
    virtual int load_pic();
    virtual void free_pic();
    virtual void draw();
};

static_assert(sizeof(TPicturePanel) == 0x11C, "TPicturePanel Size Mismatch");
static_assert(offsetof(TPicturePanel, shape) == 0x118, "TPicturePanel Offset Mismatch");

