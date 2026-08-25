// VA: 0044F880 RGE_Master_Action_Object::save
// PDB source: m_ac_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

void RGE_Master_Action_Object::save(int fd)
{
    short temp0 = -1;
    short temp1 = -1;

    RGE_Master_Moving_Object::save(fd);

    if (this->command_sound) {
        temp0 = this->command_sound->id;
    }
    if (this->move_sound) {
        temp1 = this->move_sound->id;
    }

    rge_write(fd, (char*)this + 0xDC, 2);
    rge_write(fd, (char*)this + 0xE0, 4);
    rge_write(fd, (char*)this + 0xE4, 4);
    rge_write(fd, (char*)this + 0xE8, 2);
    rge_write(fd, (char*)this + 0xEA, 2);
    rge_write(fd, (char*)this + 0xEC, 1);
    rge_write(fd, &temp0, 2);
    rge_write(fd, &temp1, 2);
    rge_write(fd, (char*)this + 0xF8, 1);
    this->tasks->save(fd);
}
