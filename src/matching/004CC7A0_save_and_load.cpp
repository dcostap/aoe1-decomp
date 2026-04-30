// VA: 004CC7A0 TRIBE_History_Info::save (t_histry.cpp lines 59-75)
// VA: 004CC840 TRIBE_History_Info::load (t_histry.cpp lines 82-103)

// attempt 1: natural save/load with rge_write/rge_read

extern "C" void rge_write(int file, void* data, int size);
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

    void save(int file);
    void load(int file);
};

void TRIBE_History_Info::save(int file) {
    TRIBE_History_Step* step;

    rge_write(file, &this->field_0C, 4);
    rge_write(file, &this->field_08, 4);
    rge_write(file, &this->buffer_size, 4);
    rge_write(file, this->buffer, this->buffer_size);

    // Count steps in linked list
    int step_count = 0;
    step = this->first_step;
    while (step) {
        step_count++;
        step = step->next;
    }

    rge_write(file, &step_count, 4);

    // Write each step
    step = this->first_step;
    while (step) {
        rge_write(file, step, 0x10);
        step = step->next;
    }
}

void TRIBE_History_Info::load(int file) {
    rge_read(file, &this->field_0C, 4);
    rge_read(file, &this->field_08, 4);
    rge_read(file, &this->buffer_size, 4);

    this->buffer = (char*)calloc(this->buffer_size, 1);
    rge_read(file, this->buffer, this->buffer_size);

    int step_count;
    rge_read(file, &step_count, 4);

    TRIBE_History_Step** prev_ptr = &this->first_step;
    while (step_count > 0) {
        TRIBE_History_Step* step = (TRIBE_History_Step*)calloc(0x10, 1);
        rge_read(file, step, 0x10);
        *prev_ptr = step;
        step_count--;
        prev_ptr = &step->next;
    }
}
