#include "../include/mst_play.h"
#include "../include/m_mi_obj.h"
#include "../include/m_dg_obj.h"

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buffer, int size);
    void rge_write(int fd, void* buffer, int size);
}

RGE_Master_Player::RGE_Master_Player(FILE* file)
{
    short temp_index;
    short temp_culture;
    short temp_amount;
    float amount;

    type = 0;
    fscanf(file, "%s %hd %hd", name, &tribe_effect, &attribute_num);

    if (attribute_num > 0) {
        attributes = (float*)calloc((int)attribute_num, 4);
    } else {
        attributes = 0;
    }

    fscanf(file, "%hd", &temp_index);
    for (short i = 0; i < temp_index; i++) {
        fscanf(file, "%hd %f", &temp_amount, &amount);
        attributes[temp_amount] = amount;
    }

    fscanf(file, "%hd", &temp_culture);
    culture = (unsigned char)temp_culture;
    master_object_num = 0;
    master_objects = 0;
}

RGE_Master_Player::RGE_Master_Player(int fd)
{
    rge_read(fd, name, 20);
    rge_read(fd, &attribute_num, 2);
    rge_read(fd, &tribe_effect, 2);
    if (attribute_num > 0) {
        attributes = (float*)calloc(attribute_num, 4);
        rge_read(fd, attributes, attribute_num * 4);
    } else {
        attributes = 0;
    }
    rge_read(fd, &culture, 1);
}

RGE_Master_Player::~RGE_Master_Player()
{
    if (this->attribute_num > 0 && this->attributes != 0) {
        free(this->attributes);
        this->attributes = 0;
        this->attribute_num = 0;
    }

    short num = this->master_object_num;
    if (num > 0 && this->master_objects != 0) {
        for (short i = 0; i < this->master_object_num; i++) {
            RGE_Master_Static_Object* obj = this->master_objects[i];
            if (obj != 0) {
                delete obj;
                this->master_objects[i] = 0;
            }
        }

        free(this->master_objects);
        this->master_objects = 0;
        this->master_object_num = 0;
    }
}

void RGE_Master_Player::finish_init(int fd, RGE_Sprite** sprites,
                                    RGE_Sound** sounds)
{
    rge_read(fd, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects =
            (RGE_Master_Static_Object**)calloc(
                (int)this->master_object_num, 4);
        rge_read(fd, this->master_objects,
                 (int)this->master_object_num * 4);

        for (int i = 0; (short)i < this->master_object_num; i++) {
            if (this->master_objects[(short)i] != 0) {
                int temp;
                rge_read(fd, &temp, 1);
                this->load_master_object(fd, temp, sprites, sounds, i);
            }
        }
    } else {
        this->master_objects = 0;
    }
}

void RGE_Master_Player::load_master_object(
    int id, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds,
    short index)
{
    RGE_Master_Static_Object* obj;
    switch (type) {
    case 10:
        obj = new RGE_Master_Static_Object(id, sprites, sounds, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(id, sprites, sounds, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(id, sprites, sounds, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(id, sprites, sounds, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}

void RGE_Master_Player::create_master_object_space(short count)
{
    this->master_object_num = count;
    if (count > 0) {
        this->master_objects =
            (RGE_Master_Static_Object**)calloc((int)count, 4);
    }
}

void RGE_Master_Player::load_object(
    FILE* file, unsigned char type, RGE_Sprite** sprites,
    RGE_Sound** sounds, short index)
{
    RGE_Master_Static_Object* obj;
    switch (type) {
    case 10:
        obj = new RGE_Master_Static_Object(file, sprites, sounds, index, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(file, sprites, sounds, index, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(file, sprites, sounds, index, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(
            file, sprites, sounds, index, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}

void RGE_Master_Player::save(int fd)
{
    short i;

    rge_write(fd, &type, 1);
    rge_write(fd, name, 20);
    rge_write(fd, &attribute_num, 2);
    rge_write(fd, &tribe_effect, 2);

    if (attribute_num > 0) {
        rge_write(fd, attributes, attribute_num * 4);
    }

    rge_write(fd, &culture, 1);
    rge_write(fd, &master_object_num, 2);

    if (master_object_num > 0) {
        rge_write(fd, master_objects, master_object_num * 4);
        for (i = 0; i < master_object_num; i++) {
            if (master_objects[i] != 0) {
                master_objects[i]->save(fd);
            }
        }
    }
}
