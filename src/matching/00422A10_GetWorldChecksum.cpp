// VA: 00422A10 GetWorldChecksum (64B)
// basegame.cpp - RGE_Base_Game member function




long RGE_Base_Game::GetWorldChecksum(void) {
    long sum;
    RGE_Game_World* world;

    sum = 0;
    world = this->world;
    if (world != 0) {
        int i = 0;
        if (world->player_num > 0) {
            do {
                sum += world->players[i]->get_checksum();
                world = this->world;
                i++;
            } while (i < world->player_num);
        }
        return sum;
    }
    return 0;
}
