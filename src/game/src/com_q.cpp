#include "../include/RGE_Communications_Queue.h"

#include <new>
#include <string.h>

namespace {
static void queue_entry_clear(MsgQueue* entry) {
    if (entry == nullptr) {
        return;
    }

    char* msg = entry->msgptr;
    entry->Code = 0;
    entry->ExecTurn = 0;
    entry->SeqNo = 0;
    entry->From = 0;
    entry->Size = 0;
    entry->ControlCommand = 0;

    if (msg != nullptr) {
        ::operator delete(msg);
    }
    entry->msgptr = nullptr;
}

static void queue_entry_reset_no_free(MsgQueue* entry) {
    if (entry == nullptr) {
        return;
    }
    entry->Code = 0;
    entry->ExecTurn = 0;
    entry->SeqNo = 0;
    entry->msgptr = nullptr;
    entry->From = 0;
    entry->Size = 0;
    entry->ControlCommand = 0;
}
}

RGE_Communications_Queue::RGE_Communications_Queue(int max_queue_size) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431720
    if (max_queue_size < 0x14) {
        max_queue_size = 0x14;
    }

    this->QueueDepth = 0;
    this->HighQueueDepth = 0;
    this->LastCurrentTurn = 0;
    this->Queue = nullptr;
    this->MaxQSize = (uint)max_queue_size;
    this->Sequence = 1;
    this->AllocateQueue((uint)max_queue_size);
}

RGE_Communications_Queue::~RGE_Communications_Queue() {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431760
    if (this->Queue != nullptr) {
        for (uint i = 0; i <= this->MaxQSize; ++i) {
            if (this->Queue[i].msgptr != nullptr) {
                ::operator delete(this->Queue[i].msgptr);
                this->Queue[i].msgptr = nullptr;
            }
        }
        ::operator delete(this->Queue);
        this->Queue = nullptr;
    }
}

int RGE_Communications_Queue::AllocateQueue(uint queue_size) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431810
    if (queue_size < this->MaxQSize) {
        return 0;
    }

    const uint new_capacity = queue_size + 1;
    MsgQueue* new_queue = (MsgQueue*)::operator new(sizeof(MsgQueue) * new_capacity, std::nothrow);
    if (new_queue == nullptr) {
        return 0;
    }

    for (uint i = 0; i < new_capacity; ++i) {
        queue_entry_reset_no_free(&new_queue[i]);
    }

    if (this->Queue != nullptr) {
        for (uint i = 0; i <= this->MaxQSize; ++i) {
            if (this->Queue[i].Size == 0) {
                continue;
            }

            new_queue[i].Code = this->Queue[i].Code;
            new_queue[i].ExecTurn = this->Queue[i].ExecTurn;
            new_queue[i].SeqNo = this->Queue[i].SeqNo;
            new_queue[i].From = this->Queue[i].From;
            new_queue[i].Size = this->Queue[i].Size;
            new_queue[i].ControlCommand = this->Queue[i].ControlCommand;

            if (this->Queue[i].msgptr != nullptr && this->Queue[i].Size > 0) {
                new_queue[i].msgptr = (char*)::operator new(this->Queue[i].Size + 1, std::nothrow);
                if (new_queue[i].msgptr != nullptr) {
                    memcpy(new_queue[i].msgptr, this->Queue[i].msgptr, this->Queue[i].Size);
                }
            }
        }

        for (uint i = 0; i <= this->MaxQSize; ++i) {
            if (this->Queue[i].msgptr != nullptr) {
                ::operator delete(this->Queue[i].msgptr);
                this->Queue[i].msgptr = nullptr;
            }
        }
        ::operator delete(this->Queue);
    }

    this->MaxQSize = queue_size;
    this->Queue = new_queue;
    return 1;
}

uchar RGE_Communications_Queue::ExpectedNextSequence(ulong exec_turn, uint from_player) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x004319E0
    uchar seq = 1;

    for (uint i = 0; i <= this->HighQueueDepth; ++i) {
        MsgQueue* entry = &this->Queue[i];
        if (entry->ExecTurn == exec_turn && entry->From == from_player && entry->Size != 0) {
            seq = (uchar)(seq + 1);
        }
    }

    return seq;
}

uint RGE_Communications_Queue::QueuedForTurn(ulong exec_turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431A40
    uint queued = 0;

    for (uint i = 0; i <= this->HighQueueDepth; ++i) {
        if (this->Queue[i].ExecTurn == exec_turn) {
            ++queued;
        }
    }

    return queued;
}

void RGE_Communications_Queue::FlushAll() {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431A70
    this->FlushTurnRange(0, 0);
}

uint RGE_Communications_Queue::FlushTurnRange(ulong start_turn, ulong end_turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431A80
    uint flushed = 0;

    for (uint i = 0; i <= this->HighQueueDepth; ++i) {
        MsgQueue* entry = &this->Queue[i];
        const ulong turn = entry->ExecTurn;

        if ((((start_turn <= turn) && (turn <= end_turn)) || ((start_turn == 0) && (end_turn == 0)))) {
            ++flushed;
            if (entry->Size != 0) {
                queue_entry_clear(entry);
            }
        }
    }

    return flushed;
}

void RGE_Communications_Queue::FlushForPlayer(uint from_player) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431B10
    for (uint i = 0; i <= this->HighQueueDepth; ++i) {
        MsgQueue* entry = &this->Queue[i];
        if ((entry->From == from_player) && (entry->Size != 0)) {
            queue_entry_clear(entry);
        }
    }
}

uint RGE_Communications_Queue::FlushForTurn(ulong turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431BD0
    return this->FlushTurnRange(turn, turn);
}

uint RGE_Communications_Queue::FlushThruTurn(ulong turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431BE0
    return this->FlushTurnRange(0, turn);
}

int RGE_Communications_Queue::AddItem(ulong exec_turn, void* payload, ulong payload_size, uint from_player,
                                      uchar sequence, int control_command) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431BF0
    uint index = 0;
    if (this->Queue != nullptr && this->Queue[0].Size != 0) {
        while (true) {
            if (this->MaxQSize <= index) {
                break;
            }
            ++index;
            if (this->Queue[index].Size == 0) {
                break;
            }
        }
    }

    if (this->MaxQSize <= index) {
        if (this->AllocateQueue(this->MaxQSize + 0x14) == 0) {
            return 0;
        }
        ++index;
    }

    if (this->HighQueueDepth < index) {
        this->HighQueueDepth = index;
    }

    MsgQueue* entry = &this->Queue[index];
    entry->msgptr = (char*)::operator new(payload_size + 1, std::nothrow);
    if (entry->msgptr != nullptr && payload_size > 0) {
        memcpy(entry->msgptr, payload, payload_size);
    }

    entry->Size = (uint)payload_size;
    entry->SeqNo = sequence;
    entry->ExecTurn = exec_turn;
    entry->From = from_player;
    entry->Code = (ulong)((uint)sequence + from_player * 1000);
    entry->ControlCommand = control_command;

    this->QueueDepth = index;
    return 1;
}

void* RGE_Communications_Queue::GetNextItemSingle() {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431DD0
    for (uint index = 0; index <= this->HighQueueDepth; ++index) {
        MsgQueue* entry = &this->Queue[index];
        if (entry->Size != 0) {
            void* send_msg = entry->msgptr;
            entry->Code = 0;
            entry->ExecTurn = 0;
            entry->SeqNo = 0;
            entry->From = 0;
            entry->Size = 0;
            entry->ControlCommand = 0;
            entry->msgptr = nullptr;
            return send_msg;
        }
    }

    return nullptr;
}

void* RGE_Communications_Queue::GetNextItemOrdered(ulong current_turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431E40
    uint lowest_code = 0xFFFFFFFF;
    uint selected_index = 0xFFFFFFFF;

    for (uint index = 0; index <= this->HighQueueDepth; ++index) {
        MsgQueue* entry = &this->Queue[index];
        if ((entry->Code != 0) && (entry->Size != 0)) {
            if ((uint)entry->ExecTurn < (uint)current_turn) {
                this->TestShowQueue();
            }

            const uint code = (uint)entry->Code;
            if ((code < lowest_code) && (entry->ExecTurn == current_turn)) {
                lowest_code = code;
                selected_index = index;
            }
        }
    }

    if (selected_index == 0xFFFFFFFF) {
        return nullptr;
    }

    MsgQueue* selected = &this->Queue[selected_index];
    void* send_msg = selected->msgptr;
    selected->msgptr = nullptr;
    selected->Code = 0;
    selected->ExecTurn = 0;
    selected->SeqNo = 0;
    selected->From = 0;
    selected->Size = 0;
    selected->ControlCommand = 0;
    return send_msg;
}

uchar RGE_Communications_Queue::GetNextSequence(ulong current_turn) {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431F10
    if (current_turn != this->LastCurrentTurn) {
        this->LastCurrentTurn = current_turn;
        this->Sequence = 1;
        return 1;
    }

    uchar next = (uchar)(this->Sequence + 1);
    this->Sequence = next;
    if (next == 0xff) {
        return 0;
    }
    return next;
}

void RGE_Communications_Queue::TestShowQueue() {
    // Fully verified. Source of truth: com_q.cpp.decomp @ 0x00431F50
}
