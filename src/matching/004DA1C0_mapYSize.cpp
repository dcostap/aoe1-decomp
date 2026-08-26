// 004DA1C0 TribeInformationAIModule::mapYSize
// BINARY NOTE: The executable loads the player at md+1256Ch. This is the
// aiPlayer member, not the primary player at md+0F0h.
// Grouped result: MATCH after using the canonical aiPlayer ownership.

int TribeInformationAIModule::mapYSize() {
    if (this->mapYSizeValue == -1) {
        this->mapYSizeValue = this->md->aiPlayer->world->map->mapHeight;
    }
    return this->mapYSizeValue;
}
