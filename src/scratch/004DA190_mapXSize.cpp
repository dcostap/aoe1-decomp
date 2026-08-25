// 004DA190 TribeInformationAIModule::mapXSize

int TribeInformationAIModule::mapXSize() {
    if (this->mapXSizeValue == -1) {
        this->mapXSizeValue = this->md->player->world->map->mapWidth;
    }
    return this->mapXSizeValue;
}
