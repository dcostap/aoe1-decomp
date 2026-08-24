// VA: 004195F0 UnitAIModule::processIdle
// aiuaimod.cpp lines 5255-5282; protected virtual owner (PDB symbol MAEHH).
// Body boundary: 004195F0-00419642; processGroupNotify ends at 004195E0.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
class UnitAIModule {
public:
    virtual int pad0();
    virtual int pad1();
    virtual int pad2();
    virtual int pad3();
    virtual int pad4();
    virtual int pad5();
    virtual int pad6();
    virtual int pad7();
    virtual int pad8();
    virtual int pad9();
    virtual int pad10();
    virtual int pad11();
    virtual int find_unit(int, int, int);
    virtual int padb13();
    virtual int padb14();
    virtual int padb15();
    virtual int padb16();
    virtual int padb17();
    virtual int padb18();
    virtual int padb19();
    virtual int padb20();
    virtual int padb21();
    virtual int padb22();
    virtual int do_stuff(int, int);
    virtual int padc24();
    virtual int padc25();
    virtual int padc26();
    virtual int padc27();
    virtual int padc28();
    virtual int padc29();
    virtual int padc30();
    virtual int padc31();
    virtual int padc32();
    virtual int padc33();
    virtual int padc34();
    virtual int padc35();
    virtual int padc36();
    virtual int padc37();
    virtual int padc38();
    virtual int padc39();
    virtual int padc40();
    virtual int padc41();
    virtual int padc42();
    virtual int padc43();
    virtual int padc44();
    virtual int padc45();
    virtual int padc46();
    virtual int padc47();
    virtual int padc48();
    virtual int padc49();
    virtual int padc50();
    virtual int padc51();
    virtual int padc52();
    virtual int padc53();
    virtual int padc54();
    virtual int get_type();

protected:
    virtual int processIdle(int param);
};
#endif

int UnitAIModule::processIdle(int param) {
    if (param == 1 && get_type() == 8)
        return 6;

    int idx = find_unit(1, 0, 0);
    if (idx != -1) {
        if (do_stuff(idx, 1) == 1)
            return 6;
    }

    return 5;
}
