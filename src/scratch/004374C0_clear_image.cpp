// 004374C0 RGE_Diamond_Map::clear_image (diam_map.cpp:519-569)

#include <string.h>

struct TDA {
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    unsigned char* Bits;
    int _gap[4];
    int Height;
    int Pitch;
    int Orien;
};

class DMap {
public:
    void clear_image();
    char _0[0x0C];
    long pnl_x;
    long pnl_y;
    char _1[0x10];
    long clip_l;
    long clip_t;
    long clip_r;
    long clip_b;
    char _2[0xBB];
    unsigned char bg;
    char _3[0x34];
    short* lines;
    char _4[8];
    short w, h, sy, iw, ih;
    char _5[0x2C];
    TDA* sa;
};

void DMap::clear_image()
{
    unsigned char* lock_ret = this->sa->Lock("diam_map::clear_image", 1);
    if (lock_ret == 0)
        return;

    {
        short start_y = this->sy;
        unsigned char* p;
        short pi;

        if (this->sa->Orien == 1) {
            pi = (short)this->sa->Pitch;
            p = this->sa->Bits + (int)start_y * this->sa->Pitch;
        } else {
            p = this->sa->Bits + ((this->sa->Height - (int)start_y) - 1) * this->sa->Pitch;
            pi = -(short)this->sa->Pitch;
        }

        short cur_y = (short)this->pnl_y + start_y;
        short end_y = this->ih + cur_y;

        if (cur_y < end_y) {
            short* lp = this->lines + 2;
            int yv = (int)cur_y;
            int rm = (int)end_y - yv;

            do {
                if (yv >= this->clip_t && yv <= this->clip_b) {
                    short sx = lp[-1];
                    int s2 = (int)this->pnl_x + (int)sx;
                    int ex = s2 + (int)*lp - 1;

                    if (s2 < this->clip_l) {
                        int adj = this->clip_l - s2;
                        sx = (short)((int)sx + adj);
                        s2 = this->clip_l;
                    }
                    if (ex > this->clip_r) ex = this->clip_r;

                    if (s2 >= this->clip_l && ex <= this->clip_r)
                        memset(p + (int)sx, this->bg, ex - s2 + 1);
                }
                lp += 3;
                p += (int)pi;
                yv++;
                rm--;
            } while (rm);
        }
    }

    this->sa->Unlock("diam_map::clear_image");
}
