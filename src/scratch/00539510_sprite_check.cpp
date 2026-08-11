// VA: 00539510 RGE_View::sprite_check
// view.cpp lines 5238-5347
// Attempt log:
// prior worker: natural switch source produced inline early returns and wrong info
// register (ESI not EDI), 86.9% positional diff.
// prior worker: shared labels/goto and explicit base/si locals moved the CFG but
// still colored info/base incorrectly; /O1, /Ox, /Ob0 did not help.
// probe 1 hypothesis: remove compiler-steering aliases and use the ordinary
// parameter/member expressions with a top-tested while loop.
// probe 2: combined width/x loop gate plus byte opcode; size moved closer but
// VC5 added an extra opcode reload and kept the parameter registers swapped.
// probe 3: split opcode read/increment; emitted code was unchanged.
// probe 4: explicit width-exhaustion return and separate switch-default tail
// restored exact size, but VC5 inverted the two identical return-1 blocks.
// probe 5: explicit ret0/ret1/default labels improved CFG coverage only.
// probe 6: infinite-loop/top-guard form removed the duplicated x check but
// shortened the function; probe 7 returned to the natural nested while form.
// probe 8: donor-era <memory.h> context was codegen-neutral here.
// probe 9: register annotation on info was codegen-neutral.
// probe 10: opcode type/read/switch variant lab found no exact or register-color
// lead; best invariant group retained the same info=ESI/shape=EDI basin.
// left in scratch: canonical typed decoder and exact size/CFG family are
// reconstructed, but VC5 still colors info/shape opposite the oracle and emits
// a byte-opcode reload plus distinct return-tail drift. Not accepted_drift-safe.

#include <memory.h>

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
    int width;
    int start;
    int right_pad;
    uchar* p;
    uchar code;
    unsigned int n;

    if (info != 0) {
        if (x >= 0) {
            width = info->Width;
            if (x < width) {
                if (y >= 0) {
                    if (y < info->Height) {
                        start = *(short*)(shape + info->Shape_Outline_Offset + y * 4);
                        right_pad = *(short*)(shape + info->Shape_Outline_Offset + y * 4 + 2);
                        if (start >= 0) {
                            if (x >= start) {
                                if (x <= width - right_pad) {
                                    p = shape + *(int*)(shape + info->Shape_Data_Offsets + y * 4);
                                    if (start < width) {
                                        while (start <= x) {
                                        code = *p;
                                        ++p;
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
                                            default:
                                                return 1;
                                            }
                                            if (start >= width) {
                                                return 1;
                                            }
                                        }
                                    }
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
