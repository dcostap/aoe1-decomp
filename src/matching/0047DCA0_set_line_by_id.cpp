// TTextPanel::set_line_by_id - walk linked list, find node with matching id

class TTextPanel {
public:
    char gap_00[0xF4];
    void* list;          // 0xF4 - linked list head
    char gap_F8[0x108];  // padding to set_line at correct vtable offset

    void set_line(long line);

    void set_line_by_id(long id);
};

void TTextPanel::set_line_by_id(long id) {
    int index = 0;
    void** node = (void**)this->list;

    if (node == 0)
        return;

    while (node) {
        if ((long)node[2] == id) {
            this->set_line(index);
            return;
        }
        node = (void**)node[3];
        index++;
    }
}
