#include "../include/tmplayer.h"

TRIBE_Master_Player::TRIBE_Master_Player(FILE* infile) : RGE_Master_Player(infile) {
    this->type = 1;
}

TRIBE_Master_Player::TRIBE_Master_Player(int infile) : RGE_Master_Player(infile) {
    this->type = 1;
}

TRIBE_Master_Player::~TRIBE_Master_Player() {
}

void TRIBE_Master_Player::load_master_object(
    int infile, unsigned char obj_type, RGE_Sprite** sprites, RGE_Sound** sounds, short index
) {
    RGE_Master_Static_Object* object;

    switch (obj_type) {
        case 'F':
            object = new TRIBE_Master_Combat_Object(infile, sprites, sounds, 1);
            break;
        case 'P':
            object = new TRIBE_Master_Building_Object(infile, sprites, sounds, 1);
            this->master_objects[index] = object;
            return;
        case 'Z':
            object = new TRIBE_Master_Tree_Object(infile, sprites, sounds, 1);
            break;
        default:
            RGE_Master_Player::load_master_object(infile, obj_type, sprites, sounds, index);
            return;
    }

    this->master_objects[index] = object;
}

void TRIBE_Master_Player::load_object(
    FILE* infile, unsigned char obj_type, RGE_Sprite** sprites, RGE_Sound** sounds, short index
) {
    RGE_Master_Static_Object* object;

    switch (obj_type) {
        case 'F':
            object = new TRIBE_Master_Combat_Object(infile, sprites, sounds, index, 1);
            break;
        case 'P':
            object = new TRIBE_Master_Building_Object(infile, sprites, sounds, index, 1);
            this->master_objects[index] = object;
            return;
        case 'Z':
            object = new TRIBE_Master_Tree_Object(infile, sprites, sounds, index, 1);
            break;
        default:
            RGE_Master_Player::load_object(infile, obj_type, sprites, sounds, index);
            return;
    }

    this->master_objects[index] = object;
}
