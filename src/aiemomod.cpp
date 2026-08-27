#include "../include/game_globals.h"
#include "../include/aiemomod.h"

char* __cdecl strcpy(char* dest, const char* src);
void __cdecl rge_read(int handle, void* buf, int size);
void __cdecl rge_write(int file, void* data, int size);

EmotionalAIModule::EmotionalAIModule(void* param1, int param2)
    : AIModule("Emotional AI", 0x3EC, param2, param1)
    , md(0)
{
    for (int i = 0; i < 6; i++) stateValue[i] = 49;
    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}

EmotionalAIModule::EmotionalAIModule(int param1, int param2)
    : AIModule("Emotional AI", 0x3EC, param1, 0)
    , md(0)
{
    int* ptr = stateValue;
    int count = 6;
    do {
        rge_read(param2, ptr, 4);
        ptr++;
        count--;
    } while (count != 0);

    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}

EmotionalAIModule::~EmotionalAIModule() {
}

void EmotionalAIModule::setMainDecisionAI(MainDecisionAIModule* v) {
    this->md = v;
}

int EmotionalAIModule::save(int file) {
    int* value = this->stateValue;
    int count = 6;

    do {
        rge_write(file, value, 4);
        value = value + 1;
        count = count - 1;
    } while (count != 0);
    return 1;
}

char* EmotionalAIModule::stateName(int index) {
    if ((index >= 0) && (index < 6)) {
        return this->stateNameValue[index];
    }
    return 0;
}

int EmotionalAIModule::state(int index) const {
    if (index < 0 || index >= 6) return -1;
    return this->stateValue[index];
}

void EmotionalAIModule::setState(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->stateValue[index] = val;
}

void EmotionalAIModule::incrementState(int index, int value) {
    if ((index >= 0) && (index < 6)) {
        this->stateValue[index] = this->stateValue[index] + value;
    }
}

void EmotionalAIModule::decrementState(int index, int value) {
    if ((index >= 0) && (index < 6)) {
        this->stateValue[index] = this->stateValue[index] - value;
    }
}

int EmotionalAIModule::overallState(void) const {
    int maxValue = this->stateValue[0];
    int result = 0;
    int i = 1;
    const int* values = &this->stateValue[1];

    while (i < 6) {
        if (maxValue < *values) {
            result = i;
            maxValue = *values;
        }
        i++;
        values++;
    }
    return result;
}

void EmotionalAIModule::setOverallState(int state)
{
    switch (state) {
    case 0:
        stateValue[0] = 100;
        stateValue[4] = 10;
        stateValue[1] = 10;
        stateValue[3] = 10;
        stateValue[2] = 0;
        stateValue[5] = 70;
        break;
    case 4:
        stateValue[0] = 20;
        stateValue[4] = 100;
        stateValue[1] = 70;
        stateValue[3] = 50;
        stateValue[2] = 60;
        stateValue[5] = 0;
        break;
    case 1:
        stateValue[0] = 10;
        stateValue[4] = 50;
        stateValue[1] = 100;
        stateValue[3] = 80;
        stateValue[2] = 50;
        stateValue[5] = 0;
        break;
    case 3:
        stateValue[0] = 10;
        stateValue[4] = 50;
        stateValue[1] = 70;
        stateValue[3] = 100;
        stateValue[2] = 50;
        stateValue[5] = 20;
        break;
    case 2:
        stateValue[0] = 20;
        stateValue[4] = 60;
        stateValue[1] = 50;
        stateValue[3] = 50;
        stateValue[2] = 100;
        stateValue[5] = 10;
        break;
    case 5:
        stateValue[0] = 90;
        stateValue[4] = 10;
        stateValue[1] = 0;
        stateValue[3] = 30;
        stateValue[2] = 50;
        stateValue[5] = 100;
        break;
    }
}

int EmotionalAIModule::defaultState() const {
    return 4;
}
