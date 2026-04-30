// TSound_Driver::open_mixer
// Standalone approach - use THUNK that calls the real implementation.
// This eliminates class-size issues by keeping the struct simple.
extern "C" unsigned int __stdcall mixerGetNumDevs(void);
extern "C" int __stdcall mixerOpen(void** handle, unsigned int dev_id, void* a, void* b, unsigned int c);
extern "C" int __stdcall mixerClose(void* handle);
extern "C" int __stdcall mixerGetLineInfoA(void* handle, void* info, unsigned int flags);
extern "C" int __stdcall mixerGetLineControlsA(void* handle, void* controls, unsigned int flags);
extern "C" int __stdcall mixerGetControlDetailsA(void* handle, void* details, unsigned int flags);

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    char gap_02[2];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    int dsrval;
    int start_volume;
    int volume;
    char path[260];
    int mixer_open;         // +0x120
    void* mixer_handle;     // +0x124
};

// Helper: open mixer inline with this+offset
extern "C" int __fastcall do_open_mixer(TSound_Driver* this_);

int TSound_Driver::open_mixer(void) {
    return do_open_mixer(this);
}

int __fastcall do_open_mixer(TSound_Driver* this_) {
    unsigned int num_devs;
    unsigned int dev_id;

    num_devs = mixerGetNumDevs();
    if (num_devs == 0) {
        return 0;
    }

    for (dev_id = 0; dev_id < num_devs; dev_id++) {
        int result;
        result = mixerOpen(&this_->mixer_handle, dev_id, 0, 0, 0);
        if (result == 0) {
            unsigned long* p;
            int i;

            // Zero 42 DWORDs at this+0x128
            p = (unsigned long*)((char*)this_ + 0x128);
            i = 0x2A;
            do {
                *p = 0;
                p++;
                i--;
            } while (i != 0);

            ((unsigned long*)((char*)this_ + 0x128))[0] = 0xA8;
            ((unsigned long*)((char*)this_ + 0x128))[6] = 0x1008;

            result = mixerGetLineInfoA(this_->mixer_handle, (char*)this_ + 0x128, 3);
            if (result == 0) {
                unsigned long line_id = *((unsigned long*)((char*)this_ + 0x134));

                // Zero 6 DWORDs at this+0x1D0
                p = (unsigned long*)((char*)this_ + 0x1D0);
                i = 6;
                do {
                    *p = 0;
                    p++;
                    i--;
                } while (i != 0);

                // Zero 37 DWORDs at this+0x1E8
                p = (unsigned long*)((char*)this_ + 0x1E8);
                i = 0x25;
                do {
                    *p = 0;
                    p++;
                    i--;
                } while (i != 0);

                ((unsigned long*)((char*)this_ + 0x1D0))[0] = 0x18;
                ((unsigned long*)((char*)this_ + 0x1D0))[1] = line_id;
                ((unsigned long*)((char*)this_ + 0x1D0))[2] = 0x50030001;
                ((unsigned long*)((char*)this_ + 0x1D0))[3] = 1;
                ((unsigned long*)((char*)this_ + 0x1D0))[4] = 0x94;
                ((void**)((char*)this_ + 0x1D0))[5] = (char*)this_ + 0x1E8;

                result = mixerGetLineControlsA(this_->mixer_handle, (char*)this_ + 0x1D0, 2);
                if (result == 0) {
                    // Zero 6 DWORDs at this+0x27C
                    p = (unsigned long*)((char*)this_ + 0x27C);
                    i = 6;
                    do {
                        *p = 0;
                        p++;
                        i--;
                    } while (i != 0);

                    *(unsigned long*)((char*)this_ + 0x294) = 0;

                    unsigned long control_id = *((unsigned long*)((char*)this_ + 0x1EC));

                    ((unsigned long*)((char*)this_ + 0x27C))[0] = 0x18;
                    ((unsigned long*)((char*)this_ + 0x27C))[1] = control_id;
                    ((unsigned long*)((char*)this_ + 0x27C))[2] = 1;
                    ((unsigned long*)((char*)this_ + 0x27C))[4] = 4;
                    ((void**)((char*)this_ + 0x27C))[5] = (char*)this_ + 0x294;

                    result = mixerGetControlDetailsA(this_->mixer_handle, (char*)this_ + 0x27C, 0);
                    if (result == 0) {
                        unsigned long value = *(unsigned long*)((char*)this_ + 0x294);
                        long max_val = *(long*)((char*)this_ + 0x250);
                        long min_val = *(long*)((char*)this_ + 0x24C);

                        this_->mixer_open = 1;
                        this_->start_volume = (int)((value * 10000) / (unsigned long)(max_val - min_val)) - 10000;
                        this_->volume = this_->start_volume;
                        return 1;
                    }
                }
            }

            mixerClose(this_->mixer_handle);
            this_->mixer_handle = 0;
        }
    }

    return 0;
}
