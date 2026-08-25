// 004DA1C0 TribeInformationAIModule::mapYSize

int TribeInformationAIModule::mapYSize() {
    if (this->mapYSizeValue == -1) {
        this->mapYSizeValue = this->md->player->world->map->mapHeight;
    }
    return this->mapYSizeValue;
}
