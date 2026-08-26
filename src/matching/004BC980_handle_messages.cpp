#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    unsigned int handle_messages(void* a, unsigned int b, unsigned int c, long d);
};
#endif

extern "C" unsigned int __cdecl ds_stream_messages(
    void* a, unsigned int b, unsigned int c, long d);

unsigned int TSound_Driver::handle_messages(
    void* a, unsigned int b, unsigned int c, long d) {
    if (this->ready == 0)
        return 0;
    return ds_stream_messages(a, b, c, d);
}
