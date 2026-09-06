#include <stdio.h>
#include <string.h>
#include "../../../include/drawarea.h"
#include "../../../include/asm_draw.h"

// Each row has a literal run, a transparent run, a color fill, and a terminator.
int main()
{
    unsigned char actual[16*96], expected[16*96], frame[2048];
    void* rows[16];
    VSpan_Node spans[16];
    VSpan_Node* heads[16];
    VSpan_Node* tails[16];
    unsigned char pixels[4][20];
    int cases=0;
    int x, y;
    for (int flip=0; flip<2; ++flip) {
        for (int align=0; align<4; ++align) {
            for (int px=-12; px<=60; px+=3) {
                for (int py=-3; py<=14; ++py) {
                    memset(frame, 0, sizeof(frame));
                    int cursor=32;
                    for (y=0; y<4; ++y) {
                        ((unsigned long*)frame)[y]=cursor;
                        frame[cursor++]=8<<2;
                        for (x=0; x<8; ++x) frame[cursor++]=pixels[y][x]=(unsigned char)(x+y*31+1);
                        frame[cursor++]=(4<<2)|1;
                        for (x=8; x<12; ++x) pixels[y][x]=0xCD;
                        frame[cursor++]=(8<<4)|7;
                        frame[cursor++]=(unsigned char)(y+201);
                        for (x=12; x<20; ++x) pixels[y][x]=(unsigned char)(y+201);
                        frame[cursor++]=0x0F;
                    }
                    memset(actual, 0xCD, sizeof(actual));
                    memcpy(expected, actual, sizeof(actual));
                    for (y=0; y<16; ++y) {
                        rows[y]=actual+y*96+8+align;
                        memset(&spans[y], 0, sizeof(spans[y]));
                        spans[y].StartPx=5;
                        spans[y].EndPx=58;
                        heads[y]=tails[y]=&spans[y];
                    }
                    for (int sy=0; sy<4; ++sy) {
                        int dy=py+sy;
                        if (dy<0 || dy>=16) continue;
                        for (int sx=0; sx<20; ++sx) {
                            int dx=px+(flip ? 19-sx : sx);
                            if (dx>=5 && dx<=58) expected[dy*96+8+align+dx]=pixels[sy][sx];
                        }
                    }
                    ASMSet_Surface_Info(rows, heads, tails, 0, 0, 63, 15);
                    ASMSet_Color_Xform(0);
                    ASMDraw_Sprite(frame, px, py, 20, 4, 0, 16, flip ? 2 : 0);
                    if (memcmp(actual, expected, sizeof(actual))) {
                        printf("Sprite failed: flip=%d align=%d x=%d y=%d\n",flip,align,px,py);
                        for (int i=0; i<sizeof(actual); ++i) if (actual[i]!=expected[i]) {
                            printf("First difference: %d actual=%u expected=%u\n",i,actual[i],expected[i]); break;
                        }
                        return 1;
                    }
                    ++cases;
                }
            }
        }
    }
    printf("Sprite: PASS, %d cases\n", cases);
    return cases==3600 ? 0 : 2;
}
