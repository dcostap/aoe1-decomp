class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[0x0F];
    int device_open;

    void close_device(void);
    int open_device(void);
    int set_music_type(unsigned char type);
};

int TMusic_System::set_music_type(unsigned char type) {
    if (type == this->music_type) {
        return this->device_open;
    }
    this->close_device();
    this->music_type = type;
    return this->open_device();
}
