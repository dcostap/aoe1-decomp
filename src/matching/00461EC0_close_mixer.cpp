typedef void* HMIXER;
extern "C" __declspec(dllimport) int __stdcall mixerClose(HMIXER hmx);

class TMusic_System {
public:
    char gap_00[0x278];
    int mixer_open;
    HMIXER mixer_handle;

    void close_mixer(void);
};

void TMusic_System::close_mixer(void) {
    if (this->mixer_open != 0) {
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}
