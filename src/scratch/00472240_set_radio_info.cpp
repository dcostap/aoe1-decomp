// STATUS: active lead
// allocation/free/copy behavior matches; the remaining drift is the count/copy register choice around the final copy loop
// the explicit destination pointer underbuilt badly; next lead is an explicit short-count plus int-total split, targeting the original di-for-count and ebx-for-total register family

extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class TButtonPanel {
public:
    char gap_00[0x13C];
    long buttonTypeValue;
    char gap_140[0xBC];
    TButtonPanel** radio_buttons;
    short num_radio_buttons;

    void set_radio_info(TButtonPanel** buttons, short count);
};

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    short button_count;

    buttonTypeValue = 2;
    if (radio_buttons != 0) {
        free(radio_buttons);
        radio_buttons = 0;
    }

    button_count = count;
    if (button_count != 0) {
        int total;

        total = (int)button_count;
        num_radio_buttons = button_count;
        radio_buttons = (TButtonPanel**)calloc(total, 4);
        if (button_count > 0) {
            int offset;

            offset = 0;
            do {
                *(TButtonPanel**)((char*)radio_buttons + offset) = *(TButtonPanel**)((char*)buttons + offset);
                offset += 4;
                total = total - 1;
            } while (total != 0);
        }
    }
}
