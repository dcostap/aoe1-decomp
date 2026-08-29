#ifndef AOE1_BITMAP_INFO_H
#define AOE1_BITMAP_INFO_H

struct BITMAPINFO256 {
public:
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

typedef char bitmap_info_256_size_check[
    (sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];

#endif
