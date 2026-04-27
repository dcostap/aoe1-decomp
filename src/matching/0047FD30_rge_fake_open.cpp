// rge_fake_open (0047FD30, 90 bytes, rge_fio.cpp)
// Attempt 2 - match exact global store order from asm

void* calloc(unsigned int count, unsigned int size);

unsigned char g_b_86B264;        // 0x86B264
int g_d_86B260;                  // 0x86B260
int g_d_86B268;                  // 0x86B268
int g_d_86B26C;                  // 0x86B26C
void* g_p_86B270;                // 0x86B270
void* g_p_86B278;                // 0x86B278
int g_d_86B27C;                  // 0x86B27C
int g_d_86B280;                  // 0x86B280

int __cdecl rge_fake_open(int param_1, int param_2) {
    if (param_1 >= 0) {
        g_b_86B264 = 2;
        g_d_86B268 = 0;
        g_p_86B270 = calloc(0x10000, 1);
        g_p_86B278 = g_p_86B270;
        g_d_86B280 = 0;
        g_d_86B26C = 0;
        g_d_86B260 = param_1;
        g_d_86B27C = param_2;
    }
    return param_1;
}
