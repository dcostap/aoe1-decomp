#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    void* flic_buffer;

    ~RGE_Flic_Player();
};

extern "C" void __cdecl free(void* ptr);
#endif

RGE_Flic_Player::~RGE_Flic_Player() {
    if (this->flic_buffer) {
        free(this->flic_buffer);
    }
}
