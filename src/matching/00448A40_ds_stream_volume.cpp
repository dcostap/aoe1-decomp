typedef struct DsStreamVolumeBuffer DsStreamVolumeBuffer;
typedef struct DsStreamVolumeBufferVtbl DsStreamVolumeBufferVtbl;

struct DsStreamVolumeBufferVtbl {
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void* vf20;
    void* vf24;
    void* vf28;
    void* vf2C;
    void* vf30;
    void* vf34;
    void* vf38;
    int (__stdcall *SetVolume)(DsStreamVolumeBuffer* self, int volume);
};

struct DsStreamVolumeBuffer {
    DsStreamVolumeBufferVtbl* lpVtbl;
};

extern void* _lpDSBStreamBuffer;

int __cdecl ds_stream_volume(int volume) {
    DsStreamVolumeBuffer* stream;
    int result;

    stream = (DsStreamVolumeBuffer*)_lpDSBStreamBuffer;
    if (stream == 0) {
        return 0;
    }
    result = stream->lpVtbl->SetVolume(stream, volume);
    return result == 0;
}
