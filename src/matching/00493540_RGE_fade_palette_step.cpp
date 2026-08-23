// VA: 00493540
// PDB: scr_cred.cpp lines 705-753
// RGE_fade_palette_step
// FLAGS: default

#include "../../include/scr_cred_context.h"

#if 0
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

extern unsigned int DAT_0086b294;
extern float DAT_0086b290;
extern int DAT_0086b2a0;
extern unsigned char DAT_0086b2a4;
extern unsigned int DAT_0086b2a8;
extern unsigned int DAT_0086b298;
extern unsigned int DAT_0086b29c;
extern float DAT_0086b2ac;
extern unsigned char DAT_0086b2b0;
extern unsigned char DAT_0086b6b0;
extern unsigned int DAT_0086bab0;

extern float DAT_00572968;
extern double DAT_00572970;
extern float DAT_00572978;
extern float DAT_0057297c;

void RGE_translate_palette(unsigned char* src, unsigned char* dst, unsigned int a, int b, unsigned int c, unsigned int d);
class TDrawSystem {
public:
    char gap_00[0x478];
    void SetPalette(void* hPal);
};
#endif

int RGE_fade_palette_step()
{
    float delta;
    int amount;
    unsigned char done = 0;
    
    if (DAT_0086b2a4 == 1) {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2C8);
        int ticks = cur - DAT_0086b294;
        delta = (float)ticks * 0.001f;
        
        if (DAT_0086b290 <= 0.0 || delta > DAT_0086b290 || delta < 0.0f) {
            amount = 100;
        } else {
            float v = delta * delta / DAT_0086b2ac * DAT_0057297c;
            amount = (long)v;
        }
        DAT_0086b2a0 = amount;
        if (amount >= 100) {
            DAT_0086b2a0 = 100;
            done = 1;
        }
    } else {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2DC);
        int ticks = cur - DAT_0086b294;
        delta = DAT_0086b290 - (float)ticks * 0.001f;
        
        if (DAT_0086b290 <= 0.0 || delta > DAT_0086b290 || delta < 0.0f) {
            amount = 0;
        } else {
            float v = delta * delta / DAT_0086b2ac * DAT_0057297c;
            amount = (long)v;
        }
        DAT_0086b2a0 = amount;
        if (amount <= 0) {
            DAT_0086b2a0 = 0;
            done = 1;
        }
    }
    
    RGE_translate_palette(DAT_0086b2b0, DAT_0086b6b0, DAT_0086b2a8,
                          DAT_0086b2a0, DAT_0086b298, DAT_0086b29c);
    DAT_0086bab0->SetPalette(DAT_0086b6b0);
    
    return done;
}
