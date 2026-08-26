// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master(void) {
    return new TRIBE_Master_Combat_Object(this, 1);
}
