// VA: 00539510 RGE_View::sprite_check
// view.cpp lines 5238-5347
// Attempt log:
// 1: natural switch source produced inline early returns and wrong info register (ESI not EDI), 86.9% pos diff.
// 2: shared labels/goto to force original shared epilogues and branch polarity: 400 B, close CFG but info/base registers swapped and code handling too compact.
// 3: explicit base/si locals and int code made code shorter (384 B), still info/base registers swapped.
// tried flags /O2(no /Oy), /O1, /Ox, /Ob0: /O1 shorter, others same.
// left in scratch: control-flow/source behavior is understood, but standalone VC5 allocates info in ESI and sprite stream in ESI instead of original info=EDI, shape base=ESI, stream=EAX; this collapses/shortens the switch body and cascades. Not accepted_drift-safe.

typedef unsigned char uchar;

struct Shape_Info {
    int Shape_Data_Offsets;
    int Shape_Outline_Offset;
    char gap_08[0x08];
    int Width;
    int Height;
};

class RGE_View {
public:
    int sprite_check(uchar* shape, Shape_Info* info, int x, int y);
};

int RGE_View::sprite_check(uchar* shape, Shape_Info* info, int x, int y)
{
    uchar* base = shape;
    Shape_Info* si = info;
    int width;
    int start;
    int right_pad;
    uchar* p;
    int code;
    unsigned int n;

    if (si != 0) {
        if (x >= 0) {
            width = si->Width;
            if (x < width) {
                if (y >= 0) {
                    if (y < si->Height) {
                        start = *(short*)(base + si->Shape_Outline_Offset + y * 4);
                        right_pad = *(short*)(base + si->Shape_Outline_Offset + y * 4 + 2);
                        if (start >= 0) {
                            if (x >= start) {
                                if (x <= width - right_pad) {
                                    p = base + *(int*)(base + si->Shape_Data_Offsets + y * 4);
                                    if (start < width) {
                                        do {
                                            if (x < start) {
                                                goto ret1;
                                            }
                                            code = *p++;
                                            switch (code & 0x0F) {
                                            case 0:
                                            case 4:
                                            case 8:
                                            case 12:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 1:
                                            case 5:
                                            case 9:
                                            case 13:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                break;
                                            case 2:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 3:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                break;
                                            case 6:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 7:
                                            case 10:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p++;
                                                break;
                                            case 11:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                break;
                                            case 14:
                                            case 15:
                                                goto ret0;
                                            }
                                        } while (start < width);
                                    }
ret1:
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
ret0:
    return 0;
ret2:
    return 2;
}
