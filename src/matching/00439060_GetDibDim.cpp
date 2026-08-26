#include "../../include/dib_context.h"

void GetDibDim(BITMAPINFO256* param_1, long& param_2, long& param_3, long& param_4) {
    param_2 = (param_1->bmiHeader.biWidth + 3) & 0xFFFFFFFC;
    param_3 = param_1->bmiHeader.biHeight;
    if (param_3 < 0) {
        param_3 = -param_3;
        param_4 = 1;
        return;
    }
    param_4 = -1;
}
