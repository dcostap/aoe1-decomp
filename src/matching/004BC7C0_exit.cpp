#ifndef SOUNDDRV_CANONICAL_TU
class IDirectSoundBuffer {
public:
    void** vftable;
};

class IDirectSound {
public:
    void** vftable;
};
#endif

typedef void (__stdcall *BufferMethod)(IDirectSoundBuffer*);
typedef void (__stdcall *SoundMethod)(IDirectSound*);

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    char ready;
    char gap_01[7];
    IDirectSound* direct_sound;
    IDirectSoundBuffer* primary_buffer;

    void close_mixer(void);
    void exit(void);
};
#endif

extern void ds_stream_exit(void);

void TSound_Driver::exit(void) {
    this->close_mixer();
    if (this->ready != 0) {
        ds_stream_exit();
        if (this->primary_buffer != 0) {
#ifdef SOUNDDRV_CANONICAL_TU
            this->primary_buffer->Stop();
            this->primary_buffer->Release();
#else
            ((BufferMethod)((void**)this->primary_buffer->vftable)[0x12])(this->primary_buffer);
            ((BufferMethod)((void**)this->primary_buffer->vftable)[2])(this->primary_buffer);
#endif
            this->primary_buffer = 0;
        }
        if (this->direct_sound != 0) {
#ifdef SOUNDDRV_CANONICAL_TU
            this->direct_sound->Release();
#else
            ((SoundMethod)((void**)this->direct_sound->vftable)[2])(this->direct_sound);
#endif
            this->direct_sound = 0;
        }
        this->ready = 0;
    }
}
