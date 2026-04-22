unsigned int __cdecl ds_stream_messages(void* a, unsigned int b, unsigned int c, long d);

class TSound_Driver_hm {
public:
    unsigned int handle_messages(void* a, unsigned int b, unsigned int c, long d);
    unsigned char ready;
};

unsigned int TSound_Driver_hm::handle_messages(void* a, unsigned int b, unsigned int c, long d) {
    if (this->ready == 0)
        return 0;
    return ds_stream_messages(a, b, c, d);
}
