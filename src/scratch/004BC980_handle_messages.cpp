void __cdecl process_sound_messages(int a, int b, int c, int d);

class TSound_Driver_hm {
public:
    int handle_messages(int a, int b, int c, int d);
    unsigned char ready;
};

int TSound_Driver_hm::handle_messages(int a, int b, int c, int d) {
    if (!this->ready) return 0;
    process_sound_messages(a, b, c, d);
    return 0;
}
