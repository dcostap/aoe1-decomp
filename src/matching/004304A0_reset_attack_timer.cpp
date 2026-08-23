// PDB owner: RGE_Combat_Object, com_obj.cpp lines 483-492.
// The named float preserves the binary-observed x87 load and store.
void RGE_Combat_Object::reset_attack_timer() {
    float timer = this->master_obj->speed_of_attack;
    this->attack_timer = timer;
}
