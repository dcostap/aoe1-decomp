// VA: 00413090 ~UnitAIModule dtor (183B)
// aiuaimod.cpp
// EH frame (/GX)

#include "../../include/aiuaimod_context.h"

UnitAIModule::~UnitAIModule() {
    // BINARY NOTE: the constructor uses delayed novtable publication. The
    // executable restores the base vptr before it reads the first owned queue.
    OrderEvent* queue;
    if ((*(void* volatile*)this = (void*)0x56EAD8,
         queue = *(OrderEvent* volatile*)&orderQueueValue)) {
        delete queue;
        orderQueueValue = 0;
    }
    if (notifyQueueValue) {
        delete notifyQueueValue;
        notifyQueueValue = 0;
    }
    if (importantObjects) {
        delete importantObjects;
        importantObjects = 0;
    }
    if (playStatus) {
        delete playStatus;
        playStatus = 0;
    }
}
