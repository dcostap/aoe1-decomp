// 0040FD80 AIPlayStatus::group

unsigned char AIPlayStatus::group(int id) {
    if (id < 0)
        return 0xFF;
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == id)
            return this->groupings[i].groupID;
    }
    return 0xFF;
}
