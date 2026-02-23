#include "../include/MainDecisionAIModule.h"
#include "../include/RGE_Static_Object.h"

#include <new>

MainDecisionAIModule::MainDecisionAIModule() {
    this->player = nullptr;
    this->objects.value = nullptr;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}

MainDecisionAIModule::~MainDecisionAIModule() {
    if (this->objects.value != nullptr) {
        ::operator delete(this->objects.value);
        this->objects.value = nullptr;
    }
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
int MainDecisionAIModule::loggingHistory() { return 0; }
void MainDecisionAIModule::setLogHistory(int param_1) { (void)param_1; }
void MainDecisionAIModule::toggleLogHistory() {}
void MainDecisionAIModule::setHistoryFilename(char* param_1) { (void)param_1; }
int MainDecisionAIModule::loggingCommonHistory() { return 0; }
void MainDecisionAIModule::setLogCommonHistory(int param_1) { (void)param_1; }
void MainDecisionAIModule::toggleLogCommonHistory() {}
int MainDecisionAIModule::loadState(char* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::saveState(char* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::gleanState(int param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::processMessage(AIModuleMessage* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::update(int param_1) { (void)param_1; return 1; }
void MainDecisionAIModule::setCallbackMessage(AIModuleMessage* param_1) { (void)param_1; }
int MainDecisionAIModule::filterOutMessage(AIModuleMessage* param_1) { (void)param_1; return 0; }
int MainDecisionAIModule::save(int param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::addObject(RGE_Static_Object* param_1) {
    // Source of truth: aimdmod.cpp.decomp @ 0x0040D180
    if (param_1 == nullptr) {
        return 0;
    }

    int current_count = this->objects.numberValue;
    int object_id = param_1->id;
    for (int index = 0; index < current_count; ++index) {
        if (this->objects.maximumSizeValue <= index) {
            break;
        }
        if (this->objects.value[index] == object_id) {
            return 1;
        }
    }

    if (this->objects.maximumSizeValue - 1 < current_count) {
        int new_capacity = current_count + 1;
        int* new_values = (int*)::operator new((size_t)new_capacity * sizeof(int), std::nothrow);
        if (new_values != nullptr) {
            for (int index = 0; index < this->objects.maximumSizeValue; ++index) {
                if (new_capacity <= index) {
                    break;
                }
                new_values[index] = this->objects.value[index];
            }
            ::operator delete(this->objects.value);
            this->objects.value = new_values;
            this->objects.maximumSizeValue = new_capacity;
        }
    }

    if (this->objects.value != nullptr && this->objects.numberValue < this->objects.maximumSizeValue) {
        this->objects.value[this->objects.numberValue] = object_id;
        this->objects.numberValue = this->objects.numberValue + 1;
    }

    return 1;
}

int MainDecisionAIModule::removeObject(int param_1) {
    // Source of truth: aimdmod.cpp.decomp @ 0x0040D250
    int capacity = this->objects.maximumSizeValue;
    int index = 0;
    if (capacity > 0 && this->objects.value != nullptr) {
        int* values = this->objects.value;
        while (index < capacity) {
            if (*values == param_1) {
                break;
            }
            index = index + 1;
            values = values + 1;
        }
    }

    if (capacity <= index) {
        return 0;
    }

    if (index < capacity - 1 && this->objects.value != nullptr) {
        while (index < this->objects.maximumSizeValue - 1) {
            int next_index = index + 1;
            this->objects.value[index] = this->objects.value[next_index];
            index = next_index;
        }
    }

    int new_count = this->objects.numberValue - 1;
    this->objects.numberValue = new_count;
    if (new_count < 0) {
        this->objects.numberValue = 0;
    }

    return 1;
}
int MainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) { (void)param_1; return -1; }
int MainDecisionAIModule::canPerformAction(int param_1, int param_2) { (void)param_1; (void)param_2; return 0; }
