#ifndef AOE1_SPRITE_RECORDS_H
#define AOE1_SPRITE_RECORDS_H

class RGE_Sprite;
class RGE_Sound;

class RGE_Picture_List {
public:
    short picture_num;
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
};

typedef char sprite_records_picture_list_size_check[
    (sizeof(RGE_Picture_List) == 0x10) ? 1 : -1];
typedef char sprite_records_sound_list_size_check[
    (sizeof(RGE_Sound_List) == 0x14) ? 1 : -1];

#endif
