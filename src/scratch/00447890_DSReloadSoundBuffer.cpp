int __cdecl _DSGetWaveResource(int a, int b, int c, void* d, void* e);
int __cdecl _DSFillSoundBuffer(void* a, int b, void* c);

typedef struct {
    int* vftable;
} DSBuffer;

int __cdecl _DSReloadSoundBuffer(DSBuffer* buffer, int param2, void* param3) {
    int result = 0;
    char local_4[4];

    if (_DSGetWaveResource(0, param2, 0, local_4, &param2) != 0) {
        if (((int (__cdecl *)(DSBuffer*))buffer->vftable[0x50/4])(buffer) >= 0) {
            if (_DSFillSoundBuffer(buffer, param2, param3) != 0) {
                result = 1;
            }
        }
    }
    return result;
}
