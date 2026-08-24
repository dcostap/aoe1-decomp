#ifndef COM_Q_CONTEXT
void __cdecl operator delete(void* ptr);

class MsgQueue {
public:
    ~MsgQueue();
};

extern "C" void __stdcall eh_vector_destructor_iterator(void* ptr, unsigned int size, int count, void (*destructor)(void*));

class RGE_Communications_Queue {
public:
    char gap_00[0x114];
    MsgQueue* Queue;

    ~RGE_Communications_Queue();
};
#endif

static void destroy_msg_queue(void* ptr) {
    ((MsgQueue*)ptr)->~MsgQueue();
}

RGE_Communications_Queue::~RGE_Communications_Queue() {
    MsgQueue* queue = this->Queue;

    if (queue != 0) {
        eh_vector_destructor_iterator(queue, 0x1C, *((int*)queue - 1), destroy_msg_queue);
        operator delete((int*)queue - 1);
    }
}
