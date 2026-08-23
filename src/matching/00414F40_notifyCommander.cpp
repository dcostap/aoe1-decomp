#include "../../include/aiuaimod_context.h"

int UnitAIModule::notifyCommander(NotifyEvent* event) {
    return this->notifyCommander(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}
