// TButtonPanel::set_radio_info - free old, allocate new, copy pointer array

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* ptr);

class TButtonPanel {
public:
    char gap_00[0x13C];
    int buttonTypeValue;              // 0x13C
    char gap_140[0xBC];
    TButtonPanel** radio_buttons;    // 0x1FC
    short num_radio_buttons;         // 0x200

    void set_radio_info(TButtonPanel** buttons, short count);
};

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    this->buttonTypeValue = 2;

    if (this->radio_buttons != 0) {
        free(this->radio_buttons);
        this->radio_buttons = 0;
    }

    if (count != 0) {
        int cnt = (int)(short)count;
        this->num_radio_buttons = count;
        this->radio_buttons = (TButtonPanel**)calloc(cnt, 4);

        if (count > 0) {
            TButtonPanel** dst = this->radio_buttons;
            int remaining = cnt;
            int i = 0;
            do {
                dst[i] = buttons[i];
                i++;
                remaining--;
            } while (remaining != 0);
        }
    }
}
