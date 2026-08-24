// ResourceItem::ResourceItem(int)
// VA: 00411F10 | airesitm.cpp:40-51

ResourceItem::ResourceItem(int count) {
    int i;
    int* p;

    i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = count;

    if (count > 0) {
        p = this->sortedValue;
        while (1) {
            if (i >= 8) {
                return;
            }
            p[-8] = 0;
            p[0] = -1;
            p[8] = -1;
            i = i + 1;
            p = p + 1;
            if (i < this->numberValue) continue;
            break;
        }
    }

    if (i < 8) {
        p = this->sortedValue + i;
        count = 8 - i;
        do {
            p[-8] = -1;
            p[0] = -1;
            p[8] = -1;
            p = p + 1;
            count = count - 1;
        } while (count != 0);
    }
}
