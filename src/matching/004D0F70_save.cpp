extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Action {
public:
    virtual void save(int handle);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    char gap_04[0x3C];
    short obj_id;
    char gap_42[2];
    int work_done;
    int unique_id;
    unsigned char pre_paid;
    char gap_4D[3];

    void save(int handle);
};

void TRIBE_Action_Make_Obj::save(int handle) {
    RGE_Action::save(handle);
    rge_write(handle, &this->obj_id, 2);
    rge_write(handle, &this->work_done, 4);
    rge_write(handle, &this->unique_id, 4);
    rge_write(handle, &this->pre_paid, 1);
}
