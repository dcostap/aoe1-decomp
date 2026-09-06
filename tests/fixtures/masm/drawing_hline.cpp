#include "../../../include/drawarea.h"
#include "../../../include/asm_draw.h"
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char actual[8*768], expected[8*768];
    void* rows[8];
    VSpan_Node nodes[8][3];
    VSpan_Node* heads[8];
    VSpan_Node* tails[8];
    for (int i=0; i<8192; ++i) {
        int align = i&3;
        long x1, x2, y;
        memset(actual, 0xCD, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        for (int row=0; row<8; ++row) {
            rows[row] = actual+row*768+8+align;
            memset(nodes[row], 0, sizeof(nodes[row]));
            nodes[row][0].StartPx = i<4096 ? 0 : 10;
            nodes[row][0].EndPx = i<4096 ? 699 : 120;
            nodes[row][1].StartPx = 140;
            nodes[row][1].EndPx = 300;
            nodes[row][2].StartPx = 350;
            nodes[row][2].EndPx = 680;
            heads[row] = &nodes[row][0];
            tails[row] = heads[row];
            if (i>=4096) {
                nodes[row][0].Next = &nodes[row][1];
                nodes[row][1].Prev = &nodes[row][0];
                nodes[row][1].Next = &nodes[row][2];
                nodes[row][2].Prev = &nodes[row][1];
                tails[row] = &nodes[row][2];
                if (i%7 == 0) heads[row] = tails[row] = 0;
            }
        }
        if (i<4096) {
            x1 = 16+((i>>10)&3)*3;
            x2 = x1+((i>>2)&255);
            y = 2;
        } else {
            x1 = i%900-100;
            x2 = x1+((i>>4)%400)-6;
            y = i%10-1;
            if (i&16) { long swap=x1; x1=x2; x2=swap; }
        }
        unsigned long color = (i*37)^0xACBD8700;
        long left = x1<x2 ? x1 : x2;
        long right = x1>x2 ? x1 : x2;
        if (left<5) left=5;
        if (right>694) right=694;
        if (y>=1 && y<=6) {
            for (VSpan_Node* node=heads[y]; node; node=node->Next) {
                long first=left>node->StartPx ? left : node->StartPx;
                long last=right<node->EndPx ? right : node->EndPx;
                if (first<=last)
                    memset(expected+y*768+8+align+first, (unsigned char)color, last-first+1);
            }
        }
        ASMSet_Surface_Info(rows, heads, tails, 5, 1, 694, 6);
        ASMSet_Color_Xform(0x76543210);
        ASMDraw_HLine(x1, x2, y, color);
        if (memcmp(actual, expected, sizeof(actual))) {
            printf("HLine failed: case %d, endpoints %ld %ld, row %ld\n", i, x1, x2, y);
            return 1;
        }
        if (ASMGet_Color_Xform()!=0x10) return 2;
    }
    puts("HLine: PASS, 8192 input sets");
    return 0;
}
