class TSound_Driver {
public:
    unsigned char isValid;
    int actual_resume_stream();
    int resume_stream();
};

int TSound_Driver::resume_stream() {
    if (!this->isValid)
        return 0;
    return this->actual_resume_stream();
}
