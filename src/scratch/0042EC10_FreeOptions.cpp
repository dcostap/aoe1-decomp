extern "C" void __cdecl operator_delete_fo(void*);

class TCommunications_Handler_fo {
public:
    void FreeOptions(void);
    char gap_00[0x04];
    void* options_data;
    char gap_08[0x1714];
    int data_size;
};

void TCommunications_Handler_fo::FreeOptions(void) {
    if (this->options_data) {
        this->data_size = 0;
        operator_delete_fo(this->options_data);
        this->options_data = 0;
    }
}
