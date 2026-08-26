// 004DA190 TribeInformationAIModule::mapXSize
// BINARY NOTE: The executable loads the player at md+1256Ch. This is the
// aiPlayer member, not the primary player at md+0F0h.
// Grouped result: MATCH after using the canonical aiPlayer ownership.

int TribeInformationAIModule::mapXSize() {
    if (this->mapXSizeValue == -1) {
        this->mapXSizeValue = this->md->aiPlayer->world->map->mapWidth;
    }
    return this->mapXSizeValue;
}
