#include "../include/tmplayer.h"

TRIBE_Master_Player::TRIBE_Master_Player(FILE* file)
    : RGE_Master_Player(file)
{
    this->type = 1;
}

TRIBE_Master_Player::TRIBE_Master_Player(int player)
    : RGE_Master_Player(player)
{
    this->type = 1;
}

TRIBE_Master_Player::~TRIBE_Master_Player()
{
}

void TRIBE_Master_Player::load_master_object(
    int id, unsigned char object_type, RGE_Sprite** sprites,
    RGE_Sound** sounds, short index)
{
    RGE_Master_Static_Object* object;

    switch (object_type) {
    case 'F':
        object = new TRIBE_Master_Combat_Object(id, sprites, sounds, 1);
        break;
    case 'P':
        object = new TRIBE_Master_Building_Object(id, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 'Z':
        object = new TRIBE_Master_Tree_Object(id, sprites, sounds, 1);
        break;
    default:
        RGE_Master_Player::load_master_object(id, object_type, sprites, sounds,
                                              index);
        return;
    }

    this->master_objects[index] = object;
}

void TRIBE_Master_Player::load_object(
    FILE* file, unsigned char object_type, RGE_Sprite** sprites,
    RGE_Sound** sounds, short index)
{
    RGE_Master_Static_Object* object;

    switch (object_type) {
    case 'F':
        object = new TRIBE_Master_Combat_Object(file, sprites, sounds, index, 1);
        break;
    case 'P':
        object = new TRIBE_Master_Building_Object(file, sprites, sounds, index,
                                                   1);
        this->master_objects[index] = object;
        return;
    case 'Z':
        object = new TRIBE_Master_Tree_Object(file, sprites, sounds, index, 1);
        break;
    default:
        RGE_Master_Player::load_object(file, object_type, sprites, sounds,
                                       index);
        return;
    }

    this->master_objects[index] = object;
}
