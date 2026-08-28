#ifndef AOE1_PICTURE_TYPES_H
#define AOE1_PICTURE_TYPES_H

struct LINEINFO {
    int AllTrans;
    int MidSolid;
    long StartX;
    long EndX;
};

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

typedef char picture_line_info_size_check[
    (sizeof(LINEINFO) == 0x10) ? 1 : -1];
typedef char picture_trans_info_size_check[
    (sizeof(TRANSINFO) == 0x18) ? 1 : -1];

#endif
