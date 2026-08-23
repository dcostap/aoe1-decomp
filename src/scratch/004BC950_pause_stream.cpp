class TSound_Driver {
public:
    unsigned char isValid;
    int actual_pause_stream();
    int pause_stream();
};

int TSound_Driver::pause_stream() {
    if (!this->isValid)
        return 0;
    return this->actual_pause_stream();
}
