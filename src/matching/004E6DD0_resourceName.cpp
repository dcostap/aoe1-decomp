#include "../../include/tairesmd_context.h"

char* TribeResourceAIModule::resourceName(int param_1) {
    if (param_1 == 0) {
        return (char*)"Food";
    }
    if (param_1 == 1) {
        return (char*)"Wood";
    }
    if (param_1 == 2) {
        return (char*)"Stone";
    }
    if (param_1 == 3) {
        return (char*)"Gold";
    }
    return (char*)"Unknown";
}
