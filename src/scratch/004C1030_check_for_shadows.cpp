// tried the direct list-walk with exact draw_level/draw_list_num offsets; mismatch moved into the early branch layout
// tried the exact field offsets from the asm; VC5 still preferred a different prolog/branch family on the initial low-count checks
// leaving in scratch because the remaining gap is branch-shape drift, not a behavior mismatch
class RGE_Sprite;

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[0x2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};

class RGE_Sprite {
public:
    char gap_00[0x29];
    unsigned char draw_level;
    char gap_2A[0xC];
    short draw_list_num;
    RGE_Picture_List* draw_list;

    int check_for_shadows();
};

int RGE_Sprite::check_for_shadows() {
    int i;
    RGE_Picture_List* list;
    RGE_Sprite* sprite;

    if (this->draw_list_num <= 0) {
        if (this->draw_level != 0) {
            return 0;
        }
        return 1;
    }
    if (this->draw_list == 0) {
        if (this->draw_level != 0) {
            return 0;
        }
        return 1;
    }
    i = 0;
    list = this->draw_list;
    while (1) {
        sprite = list->sprite;
        if (sprite->draw_level == 0) {
            return 1;
        }
        i++;
        list = (RGE_Picture_List*)((char*)list + 0x10);
        if (this->draw_list_num <= i) {
            return 0;
        }
    }
}
