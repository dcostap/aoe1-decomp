extern "C" int __cdecl ds_stream_volume(long value);

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;

    int set_stream_volume(long value);
};
#endif

int TSound_Driver::set_stream_volume(long value) {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_volume(value);
}
