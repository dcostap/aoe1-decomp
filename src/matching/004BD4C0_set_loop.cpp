#ifndef SOUNDDRV_CANONICAL_TU
class TDigital {
public:
    char gap_00[0x28];
    int loop;

    void set_loop(short value);
};
#endif

void TDigital::set_loop(short value) {
    if (value == 0) {
        this->loop = 0;
        return;
    }
    this->loop = 1;
}
