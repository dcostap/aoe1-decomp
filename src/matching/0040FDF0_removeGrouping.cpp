// 0040FDF0 AIPlayStatus::removeGrouping

int AIPlayStatus::removeGrouping(int id) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == id) {
            this->groupings[i].id = -1;
            this->groupings[i].groupID = 0xFF;
            this->groupings[i].type = 0xFF;
            return 1;
        }
    }
    return 0;
}
