// VA: 004CC840 TRIBE_History_Info::load (t_histry.cpp lines 82-103)

// attempt 1: natural load with rge_read/calloc

extern "C" void rge_read(int file, void* data, int size);
extern "C" void* calloc(int count, int size);

class TRIBE_History_Step {
public:
    char gap_000[0x0C];
    TRIBE_History_Step* next;
};

class TRIBE_History_Info {
public:
    char* buffer;                // +0x00
    TRIBE_History_Step* first_step; // +0x04
    int field_08;                // +0x08
    int field_0C;                // +0x0C
    int buffer_size;             // +0x10

    void load(int file);
};

void TRIBE_History_Info::load(int file) {
    rge_read(file, &this->field_0C, 4);
    rge_read(file, &this->field_08, 4);
    rge_read(file, &this->buffer_size, 4);

    this->buffer = (char*)calloc(this->buffer_size, 1);
    rge_read(file, this->buffer, this->buffer_size);

    int step_count;
    TRIBE_History_Step** prev_ptr = &this->first_step;
    rge_read(file, &step_count, 4);

    while (step_count > 0) {
        TRIBE_History_Step* step = (TRIBE_History_Step*)calloc(1, 0x10);
        rge_read(file, step, 0x10);
        *prev_ptr = step;
        prev_ptr = &step->next;
        step_count--;
    }
}
