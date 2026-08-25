void RGE_Moving_Object::transform(RGE_Master_Static_Object* master) {
    this->RGE_Animated_Object::transform(master);
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->turnTimer = 0.0f;
    this->turn_towards_time = 0.0f;
    this->set_angle();
}
