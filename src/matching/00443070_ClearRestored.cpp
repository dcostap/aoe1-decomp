class TDrawArea {
public:
    char gap_00[0xF4];
    int restored;
};

class DrawAreaNode {
public:
    TDrawArea* draw_area;
    char gap_04[0x04];
    DrawAreaNode* next;
};

class TDrawSystem {
public:
    char gap_00[0x14];
    DrawAreaNode* draw_area_list;
    char gap_18[0x30];
    int restored;

    void ClearRestored();
};

void TDrawSystem::ClearRestored() {
    DrawAreaNode* node;

    node = this->draw_area_list;
    this->restored = 0;
    while (node != 0) {
        node->draw_area->restored = 0;
        node = node->next;
    }
}
