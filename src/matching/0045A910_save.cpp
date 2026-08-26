// VA: 0045A910 RGE_Missile_Object::save
// PDB source: misl_obj.cpp

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

void RGE_Missile_Object::save(int fd)
{
    RGE_Combat_Object::save(fd);
    rge_write(fd, (char*)this + 0x1C4, 4);
}
