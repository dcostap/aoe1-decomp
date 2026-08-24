#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char isValid;
    int actual_resume_stream();
    int resume_stream();
};

int TSound_Driver::resume_stream() {
    if (!this->isValid)
        return 0;
    return this->actual_resume_stream();
}
#else
extern "C" int __cdecl ds_stream_resume(void);

int TSound_Driver::resume_stream() {
    if (this->ready == 0)
        return 0;
    return ds_stream_resume();
}
#endif
