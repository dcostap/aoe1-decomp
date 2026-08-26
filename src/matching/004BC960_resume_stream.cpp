#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    int resume_stream();
};
#endif

extern "C" int __cdecl ds_stream_resume(void);

int TSound_Driver::resume_stream() {
    if (this->ready == 0)
        return 0;
    return ds_stream_resume();
}
