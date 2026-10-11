#include "../include/game_globals.h"
#include "../include/aiemomod.h"

char* __cdecl strcpy(char* dest, const char* src);
void __cdecl rge_read(int handle, void* buf, int size);
void __cdecl rge_write(int file, void* data, int size);

EmotionalAIModule::EmotionalAIModule(void* pW, int playerID) : AIModule("Emotional AI", 0x3EC, playerID, pW), md(0) {
    for (int i = 0; i < 6; i++)
        stateValue[i] = 49;
    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}

EmotionalAIModule::EmotionalAIModule(int playerID, int infile) : AIModule("Emotional AI", 0x3EC, playerID, 0), md(0) {
    for (int i = 0; i < 6; i++) {
        rge_read(infile, &this->stateValue[i], 4);
    }

    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}

EmotionalAIModule::~EmotionalAIModule() {
}

void EmotionalAIModule::setMainDecisionAI(MainDecisionAIModule* m) {
    this->md = m;
}

int EmotionalAIModule::save(int outfile) {
    for (int i = 0; i < 6; i++) {
        rge_write(outfile, &this->stateValue[i], 4);
    }
    return 1;
}

char* EmotionalAIModule::stateName(int s) {
    if ((s >= 0) && (s < 6)) {
        return this->stateNameValue[s];
    }
    return 0;
}

int EmotionalAIModule::state(int s) const {
    if (s < 0 || s >= 6)
        return -1;
    return this->stateValue[s];
}

void EmotionalAIModule::setState(int s, int value) {
    if (s < 0 || s >= 6)
        return;
    this->stateValue[s] = value;
}

void EmotionalAIModule::incrementState(int s, int delta) {
    if ((s >= 0) && (s < 6)) {
        this->stateValue[s] = this->stateValue[s] + delta;
    }
}

void EmotionalAIModule::decrementState(int s, int delta) {
    if ((s >= 0) && (s < 6)) {
        this->stateValue[s] = this->stateValue[s] - delta;
    }
}

int EmotionalAIModule::overallState(void) const {
    int max_value = this->stateValue[0];
    int result = 0;
    int i = 1;
    const int* values = &this->stateValue[1];

    while (i < 6) {
        if (max_value < *values) {
            result = i;
            max_value = *values;
        }
        i++;
        values++;
    }
    return result;
}

void EmotionalAIModule::setOverallState(int s) {
    switch (s) {
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
