#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    char gap_00[0x13C];
    int buttonTypeValue;
    char gap_140[0xB4];
    short num_states;

    void set_state_info(short param);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_state_info(short param) {
    buttonTypeValue = 3;
    num_states = param;
}
