#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    int pause_stream();
};
#endif

extern "C" int __cdecl ds_stream_pause(void);

int TSound_Driver::pause_stream() {
    if (this->ready == 0)
        return 0;
    return ds_stream_pause();
}
