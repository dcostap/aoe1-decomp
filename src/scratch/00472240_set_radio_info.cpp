// STATUS: blocked
// BLOCKER: loop stays close, but VC5 keeps the count/copy registers in bx/edi instead of the original di/ebx split and rewrites the copy loop body
// NOTE: allocation/free/copy behavior matches; remaining drift is register-loop shape only

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
    short radio_button_count;

    buttonTypeValue = 2;
    if (radio_buttons != 0) {
        free(radio_buttons);
        radio_buttons = 0;
    }
    radio_button_count = count;
    if (radio_button_count != 0) {
        int total;

        total = (int)radio_button_count;
        num_radio_buttons = radio_button_count;
        radio_buttons = (TButtonPanel**)calloc(total, 4);
        if (radio_button_count > 0) {
            int offset;

            offset = 0;
            do {
                TButtonPanel* value;

                value = *(TButtonPanel**)((char*)buttons + offset);
                *(TButtonPanel**)((char*)radio_buttons + offset) = value;
                offset += 4;
                total--;
            } while (total != 0);
        }
    }
}
