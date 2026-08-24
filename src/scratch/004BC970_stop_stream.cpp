#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char isValid;
    int actual_stop_stream();
    int stop_stream();
};

int TSound_Driver::stop_stream() {
    if (!this->isValid)
        return 0;
    return this->actual_stop_stream();
}
#else
extern "C" int __cdecl ds_stream_stop(void);

int TSound_Driver::stop_stream() {
    if (this->ready == 0)
        return 0;
    return ds_stream_stop();
}
#endif
