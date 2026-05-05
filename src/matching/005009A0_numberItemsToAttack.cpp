// 005009A0 TribeTacticalAIModule::numberItemsToAttack()
// Source: taitacmd.cpp lines 11507-11509
// Attempt log:
// - Replaced stub with ManagedArray grow-to-one logic and informationAI query.
// - Exact match: the one-element copy loop needs `if (i < 1) { i++; copy
//   [i-1]; } else break;` inside the do-while. Spelling it as `if (i >= 1)
//   break; next = i + 1; copy [i];` makes VC5 choose a different index register
//   and move the limit check to the bottom.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class TribeInformationAIModule {
public:
    int numberGameIDsOwnedBy(int player, int gameID);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xCEC];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0xD28 - 0xF4];
    int* playersToAttackValue;
    char gap_D2C[0xD34 - 0xD2C];
    int playersToAttackMaximum;

    int numberItemsToAttack();
};

int TribeTacticalAIModule::numberItemsToAttack()
{
    int* newValue;
    int i;
    int max;

    if (this->playersToAttackMaximum - 1 < 0) {
        newValue = new int[1];
        if (newValue != 0) {
            max = this->playersToAttackMaximum;
            i = 0;
            if (0 < max) {
                do {
                    if (i < 1) {
                        i = i + 1;
                        newValue[i - 1] = this->playersToAttackValue[i - 1];
                    }
                    else {
                        break;
                    }
                } while (i < this->playersToAttackMaximum);
            }
            delete this->playersToAttackValue;
            this->playersToAttackValue = newValue;
            this->playersToAttackMaximum = 1;
        }
    }
    return this->md->informationAI.numberGameIDsOwnedBy(-1, *this->playersToAttackValue);
}
