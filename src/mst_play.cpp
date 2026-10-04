#include "../include/mst_play.h"
#include "../include/m_mi_obj.h"
#include "../include/m_dg_obj.h"

#include <stdlib.h>

#include "../include/rge_fio.h"

RGE_Master_Player::RGE_Master_Player(FILE* infile) {
    short temp_count;
    short temp_culture;
    short temp_index;
    float temp_amount;

    type = 0;
    fscanf(infile, "%s %hd %hd", name, &tribe_effect, &attribute_num);

    if (attribute_num > 0) {
        attributes = (float*)calloc((int)attribute_num, 4);
    } else {
        attributes = 0;
    }

    fscanf(infile, "%hd", &temp_count);
    for (short i = 0; i < temp_count; i++) {
        fscanf(infile, "%hd %f", &temp_index, &temp_amount);
        attributes[temp_index] = temp_amount;
    }

    fscanf(infile, "%hd", &temp_culture);
    culture = (unsigned char)temp_culture;
    master_object_num = 0;
    master_objects = 0;
}

RGE_Master_Player::RGE_Master_Player(int infile) {
    rge_read(infile, name, 20);
    rge_read(infile, &attribute_num, 2);
    rge_read(infile, &tribe_effect, 2);
    if (attribute_num > 0) {
        attributes = (float*)calloc(attribute_num, 4);
        rge_read(infile, attributes, attribute_num * 4);
    } else {
        attributes = 0;
    }
    rge_read(infile, &culture, 1);
}

RGE_Master_Player::~RGE_Master_Player() {
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

void RGE_Master_Player::finish_init(int infile, RGE_Sprite** sprites,
                                    RGE_Sound** sounds) {
    rge_read(infile, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc((int)this->master_object_num, 4);
        rge_read(infile, this->master_objects, (int)this->master_object_num * 4);

        for (int i = 0; (short)i < this->master_object_num; i++) {
            if (this->master_objects[(short)i] != 0) {
                int temp;
                rge_read(infile, &temp, 1);
                this->load_master_object(infile, temp, sprites, sounds, i);
            }
        }
    } else {
        this->master_objects = 0;
    }
}

void RGE_Master_Player::load_master_object(
    int infile, unsigned char obj_type, RGE_Sprite** sprites,
    RGE_Sound** sounds, short index) {
    RGE_Master_Static_Object* obj;
    switch (obj_type) {
    case 10:
        obj = new RGE_Master_Static_Object(infile, sprites, sounds, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(infile, sprites, sounds, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(infile, sprites, sounds, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(infile, sprites, sounds, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}

void RGE_Master_Player::create_master_object_space(short count) {
    this->master_object_num = count;
    if (count > 0) {
        this->master_objects =
            (RGE_Master_Static_Object**)calloc((int)count, 4);
    }
}

void RGE_Master_Player::load_object(
    FILE* infile, unsigned char obj_type, RGE_Sprite** sprites,
    RGE_Sound** sounds, short index) {
    RGE_Master_Static_Object* obj;
    switch (obj_type) {
    case 10:
        obj = new RGE_Master_Static_Object(infile, sprites, sounds, index, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(infile, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(infile, sprites, sounds, index, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(infile, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(infile, sprites, sounds, index, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(infile, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(infile, sprites, sounds, index, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}

void RGE_Master_Player::save(int outfile) {
    short i;

    rge_write(outfile, &type, 1);
    rge_write(outfile, name, 20);
    rge_write(outfile, &attribute_num, 2);
    rge_write(outfile, &tribe_effect, 2);

    if (attribute_num > 0) {
        rge_write(outfile, attributes, attribute_num * 4);
    }

    rge_write(outfile, &culture, 1);
    rge_write(outfile, &master_object_num, 2);

    if (master_object_num > 0) {
        rge_write(outfile, master_objects, master_object_num * 4);
        for (i = 0; i < master_object_num; i++) {
            if (master_objects[i] != 0) {
                master_objects[i]->save(outfile);
            }
        }
    }
}
