// 00431DD0 RGE_Communications_Queue::GetNextItemSingle
//
// BLOCKER: behavior and clear order are understood, but VC5 stays in a different
// scan register/prologue basin. Original delays `push edi` until after loading
// Queue into ESI and zeroing EBX, then scans with `cmp [edx], ebx; ja found`,
// using EDI only for HighQueueDepth. Best source instead saves EDI early, keeps
// Queue in EDI, hoists the first Size into ESI, and uses ESI for HighQueueDepth.
// Tail clear/reload shape is close but inherits the EDI-vs-ESI queue choice.
//
// Attempt log:
// 1. Prior pointer-walk source compiled too small (96B) and did not keep original queue reload/clear shape.
// 2. Array-indexed source matched clear tail broadly but pushed EDI early and used EDI for queue.
// 3. Size-pointer do/while and explicit goto variants: stable early-EDI/queue-in-EDI basin.
// 4. volatile size_ptr and register queue: no change.
// 5. Simple mq++ loop like neighboring queue functions: worse, hoisted Queue before saves and only used EBX/ESI.
// 6. variant_lab over init order, ptr_do/ptr_while/arr_while scans, offset expression forms, clear forms, and vc5-small flags: no exact; best default family is same early-EDI/queue-in-EDI basin (edit diff 27-29), /Ow variants produce smaller 96B bodies but wrong prologue/tail.

class MsgQueue {
public:
    unsigned long Code;
    unsigned long ExecTurn;
    unsigned char SeqNo;
    char pad_09[3];
    void* msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[0xFF];
    unsigned char _pad_0[1];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    unsigned char _pad_1[3];
    MsgQueue* Queue;

    void* GetNextItemSingle();
};

extern void* DAT_0062cf34;

void* RGE_Communications_Queue::GetNextItemSingle() {
    MsgQueue* queue = this->Queue;
    unsigned int index = 0;
    unsigned int* size_ptr = &queue->Size;

loop:
    if (*size_ptr != 0) {
        unsigned int offset = index;
        offset = offset << 3;
        offset = offset - index;
        offset = offset << 2;
        DAT_0062cf34 = *(void**)((char*)queue + offset + 0x0C);
        MsgQueue* entry = (MsgQueue*)((char*)this->Queue + offset);
        entry->Code = 0;
        entry->ExecTurn = 0;
        entry->SeqNo = 0;
        entry->From = 0;
        entry->Size = 0;
        entry->ControlCommand = 0;
        *(void**)((char*)this->Queue + offset + 0x0C) = 0;
        return DAT_0062cf34;
    }
    {
        unsigned int high = this->HighQueueDepth;
        ++index;
        size_ptr = (unsigned int*)((char*)size_ptr + 0x1C);
        if (index <= high) {
            goto loop;
        }
    }
    return 0;
}
