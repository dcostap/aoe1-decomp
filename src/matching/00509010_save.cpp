class RGE_Task;

class RGE_Task_List {
public:
    void* vtable_ptr;
    RGE_Task** list;
    short list_num;
    void save(int f);
};

extern void rge_write(int f, void* data, int size);
class RGE_Task {
public:
    void save(int f);
};

void RGE_Task_List::save(int f) {
    rge_write(f, &this->list_num, 2);
    for (short i = 0; i < this->list_num; ++i) {
        this->list[i]->save(f);
    }
}
