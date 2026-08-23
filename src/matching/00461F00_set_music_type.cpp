#include "../../include/music_context.h"

int TMusic_System::set_music_type(unsigned char type) {
    if (type == this->music_type) {
        return this->device_open;
    }
    this->close_device();
    this->music_type = type;
    return this->open_device();
}
