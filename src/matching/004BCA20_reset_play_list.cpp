#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    virtual ~TSound_Driver();
    char gap_0[0x694];
    int field_698;
    void reset_play_list();
};

void TSound_Driver::reset_play_list() { this->field_698 = 0; }
#else
void TSound_Driver::reset_play_list() { this->play_list_count = 0; }
#endif
