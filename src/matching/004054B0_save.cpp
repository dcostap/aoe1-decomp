// RGE_Action_Missile::save (004054B0, 94 bytes, ACT_misl.cpp)
// Attempt 1

void __cdecl rge_write(int handle, const void* buffer, int size);

class RGE_Action {
public:
    void save(int handle);
};

class RGE_Action_Missile : public RGE_Action {
public:
    char gap_00[0x40];
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;

    void save(int handle);
};

void RGE_Action_Missile::save(int handle) {
    RGE_Action::save(handle);
    rge_write(handle, &this->velocity_x, 4);
    rge_write(handle, &this->velocity_y, 4);
    rge_write(handle, &this->velocity_z, 4);
    rge_write(handle, &this->ballistic_velocity, 4);
    rge_write(handle, &this->ballistic_acceleration, 4);
}
