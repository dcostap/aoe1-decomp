class TSound_Driver {
public:
    char gap_00[0x1C];
    char path[0x80];

    void set_path(char* param_1);
};

void TSound_Driver::set_path(char* param_1) {
    if (param_1 == 0) {
        this->path[0] = 0;
        return;
    }

    char* src = param_1;
    while (*src != 0) {
        ++src;
    }

    char* dst = this->path;
    while (param_1 != src) {
        *dst = *param_1;
        ++dst;
        ++param_1;
    }
}
