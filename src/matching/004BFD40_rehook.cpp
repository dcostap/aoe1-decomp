// attempt 1: base draft, size 80 (1 byte short of 81)
// attempt 2: direct member access, still 80
// attempt 3: for loop, still 80
// attempt 4: pointer iteration, 64 bytes (too small)
// attempt 5: dual if (no else), size 81 but layout/shl wrong
// attempt 6: fix RGE_Picture_List to 16 bytes, still 80
// attempt 7: cast draw_list_num to int, still 80
// exact basin: keep the duplicated `draw_list_num > 0` guard and use a `goto loop_test / loop_body` form; that preserves the original early `mov ax`, repeated draw_list reload, and 16-byte scaling

#include "..\..\include\sprite_context.h"

void RGE_Sprite::rehook(RGE_Sprite** sprites) {
    short i;
    if (draw_list_num > 0 && draw_list != 0) {
        i = 0;
        if (draw_list_num > 0) {
            goto loop_test;
            loop_body:
            if (draw_list[i].picture_num == -1) {
                draw_list[i].sprite = this;
            }
            else {
                draw_list[i].sprite = sprites[draw_list[i].picture_num];
            }
            i++;
            loop_test:
            if (i < draw_list_num) goto loop_body;
        }
    }
    load_facets(sprites);
}
