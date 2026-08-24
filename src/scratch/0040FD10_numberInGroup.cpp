// 0040FD10 AIPlayStatus::numberInGroup

unsigned char AIPlayStatus::numberInGroup(int groupIndex) {
    unsigned char count = 0;
    AIPlayStatus::GroupingStruct* entry = this->groupings;
    int remaining = 50;
    do {
        if (entry->id != -1) {
            if (entry->groupID == groupIndex)
                count++;
        }
        entry++;
        remaining--;
    } while (remaining);
    return count;
}
