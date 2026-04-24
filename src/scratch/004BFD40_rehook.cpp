// attempt 1: base draft, size 80 (1 byte short of 81)
// attempt 2: direct member access, still 80
// attempt 3: for loop, still 80
// attempt 4: pointer iteration, 64 bytes (too small)
// attempt 5: dual if (no else), size 81 but layout/shl wrong
// attempt 6: fix RGE_Picture_List to 16 bytes, still 80
// attempt 7: cast draw_list_num to int, still 80
// left in scratch: 1 byte size drift, behavior correct, source basin not found

class RGE_Picture_List {
public:
    short picture_num;
    void* sprite;
    char gap_08[0x8];
};

class RGE_Sprite {
public:
    char gap_00[0x36];
    short draw_list_num;
    RGE_Picture_List* draw_list;

    void rehook(RGE_Sprite** sprites);
    void load_facets(RGE_Sprite** sprites);
};

void RGE_Sprite::rehook(RGE_Sprite** sprites) {
    short i;
    if (draw_list_num > 0 && draw_list != 0) {
        i = 0;
        if (draw_list_num > 0) {
            do {
                if (draw_list[i].picture_num == -1) {
                    draw_list[i].sprite = this;
                }
                else {
                    draw_list[i].sprite = sprites[draw_list[i].picture_num];
                }
                i++;
            } while (i < draw_list_num);
        }
    }
    load_facets(sprites);
}
