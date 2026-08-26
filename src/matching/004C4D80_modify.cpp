// VA: 004C4D80 RGE_Static_Object::modify

void RGE_Static_Object::modify(volatile float value, unsigned char type) {
    switch (type) {
    case 0:
        {
            int maxHp = *(short*)((char*)this->master_obj + 0x26);
            this->hp = (float)(short)(long)(value * this->hp / maxHp);
        }
        break;
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            this->setDamage(this->owner, 0, -1);
            this->setHealth(this->owner, 0, (long)value);
            return;
        }
        break;
    }
}
