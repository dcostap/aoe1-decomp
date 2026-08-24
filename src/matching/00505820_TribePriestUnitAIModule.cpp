// VA: 00505820 TribePriestUnitAIModule::TribePriestUnitAIModule
// PDB source: taiuaimd.cpp
// Attempt log:

#ifndef TAIUAIMD_COMPLETE_TU
class UnitAIModule {
public:
    UnitAIModule(void* param_1, int param_2);
    virtual ~UnitAIModule();

    char gap_04[0x11C];
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    char field_130;
};

class __declspec(novtable) TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(void* param_1, int param_2);
    virtual ~TribePriestUnitAIModule();
};

extern void* __cdecl operator_new(unsigned int size);
#endif

TribePriestUnitAIModule::TribePriestUnitAIModule(void* param_1, int param_2)
#ifdef TAIUAIMD_COMPLETE_TU
    : UnitAIModule((RGE_Static_Object*)param_1, param_2)
#else
    : UnitAIModule(param_1, param_2)
#endif
{
#ifdef TAIUAIMD_COMPLETE_TU
    this->field_128 = 0x11;
    this->field_124 = (int)operator_new(0x44);
#else
    *(void**)this = (void*)0x575E28;
    this->field_128 = 0x11;

    this->field_124 = (int)operator_new(0x44);

    if (this->field_124 != 0) {
        *(int*)this->field_124 = 3;
        *((int*)this->field_124 + 1) = 0;
        *((int*)this->field_124 + 2) = 4;
        *((int*)this->field_124 + 3) = 0x1A;
        *((int*)this->field_124 + 4) = 0x18;
        *((int*)this->field_124 + 5) = 6;
        *((int*)this->field_124 + 6) = 0x19;
        *((int*)this->field_124 + 7) = 0x11;
        *((int*)this->field_124 + 8) = 0xA;
        *((int*)this->field_124 + 9) = 0xC;
        *((int*)this->field_124 + 10) = 0x23;
        *((int*)this->field_124 + 11) = 0x17;
        *((int*)this->field_124 + 12) = 0x24;
        *((int*)this->field_124 + 13) = 0x1C;
        *((int*)this->field_124 + 14) = 0x12;
        *((int*)this->field_124 + 15) = 0xD;
        *((int*)this->field_124 + 16) = 0x27;
    }
#endif
}
