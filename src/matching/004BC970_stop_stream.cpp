class TSound_Driver {
public:
    unsigned char isValid;
    int actual_stop_stream();
    int stop_stream();
};

int TSound_Driver::stop_stream() {
    if (!this->isValid)
        return 0;
    return this->actual_stop_stream();
}
