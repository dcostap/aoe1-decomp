
#include "../include/tairesmd.h"
#include "../include/taimdmd.h"
#include "../include/player.h"
#include "../include/rge_fio.h"


TribeResourceAIModule::TribeResourceAIModule(void* pW, int playerID,
                                             int n, int iV,
                                             int minV, int maxV)
    : AIModule((char*)"Resource AI", 0x3EF, playerID, pW),
      md(0),
      numberResourcesValue(n) {
}

TribeResourceAIModule::TribeResourceAIModule(int playerID, int infile)
    : AIModule("ResAI", 0x3EF, playerID, 0),
      md(0) {
    rge_read(infile, &this->numberResourcesValue, 4);
}

TribeResourceAIModule::~TribeResourceAIModule() {
}

void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

int TribeResourceAIModule::save(int outfile) {
    rge_write(outfile, &this->numberResourcesValue, 4);
    return 1;
}

int TribeResourceAIModule::numberResources() const {
    return this->numberResourcesValue;
}

int TribeResourceAIModule::resource(int n) const {
    if ((n >= 0) && (n < this->numberResourcesValue)) {
        return (int)this->md->player->attributes[n];
    }
    return -1;
}

int TribeResourceAIModule::resourcesAvailable(ResourceItem* ri) {
    if (ri == 0)
        return 0;
    if (numberResourcesValue != ri->number())
        return 0;

    int i = 0;
    int n = ri->number();
    while (i < n) {
        if (this->md->player->attributes[i] < (float)ri->value(i))
            return 0;
        ++i;
        n = ri->number();
    }

    return 1;
}

int TribeResourceAIModule::unavailableResource(ResourceItem* ri) {
    if (ri == 0)
        return 0;

    if (this->numberResourcesValue == ri->number()) {
        int i = 0;
        while (i < ri->number()) {
            float* amounts = this->md->player->attributes;
            if (amounts[i] < (float)ri->value(i)) {
                return i;
            }
            ++i;
        }
        return -1;
    }
    return -1;
}

char* TribeResourceAIModule::resourceName(int i) {
    if (i == 0) {
        return (char*)"Food";
    }
    if (i == 1) {
        return (char*)"Wood";
    }
    if (i == 2) {
        return (char*)"Stone";
    }
    if (i == 3) {
        return (char*)"Gold";
    }
    return (char*)"Unknown";
}
