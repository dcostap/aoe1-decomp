// VA: 0045AA70 RGE_Missile_Object::missile_move
// PDB source: misl_obj.cpp
// Attempt log:
// - Original stub only.
// Probe 1: natural virtual surface with x/y/z + deltas and map bounds; body matched except byte-width return.
// Probe 2: widen visible return to int to force mov eax/xor eax tails.

unsigned char RGE_Missile_Object::missile_move()
{
    float new_x;
    float new_y;
    float new_z;
    // BINARY NOTE: the PDB ABI is unsigned char, but the shipped tails return dwords.
    int result;

    new_x = this->world_x;
    new_x = new_x + this->dx;
    new_y = this->world_y + this->dy;
    new_z = this->world_z + this->dz;

    if (new_x < 0.0f || (float)this->owner->world->map_info->width <= new_x ||
        new_y < 0.0f || (float)this->owner->world->map_info->height <= new_y) {
        this->die_die_die();
    }

    if (this->teleport(new_x, new_y, new_z) == this->world_z) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
