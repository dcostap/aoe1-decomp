



struct GetWorldChecksums_Locals {
    long c1;
    long c2;
    long c3;
    RGE_Base_Game* self;
};

unsigned char RGE_Base_Game::GetWorldChecksums(long& checksum1, long& checksum2, long& checksum3)
{
    GetWorldChecksums_Locals locals;
    int i;
    RGE_Game_World* w;

    i = 0;
    locals.self = this;
    locals.c1 = 0;
    checksum1 = 0;
    checksum2 = 0;
    checksum3 = 0;
    w = world;
    locals.c2 = 0;
    locals.c3 = 0;
    if (w != 0) {
        if (w->player_num > 0) {
            do {
                w->players[i]->get_checksums(locals.c1, locals.c2, locals.c3);
                checksum1 += locals.c1;
                checksum2 += locals.c2;
                checksum3 += locals.c3;
                ++i;
                w = locals.self->world;
            } while (i < w->player_num);
        }
        return 1;
    }
    return 0;
}
