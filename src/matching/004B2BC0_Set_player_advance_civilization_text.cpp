// VA: 004B2BC0 TRIBE_Screen_Sed::Set_player_advance_civilization_text
// try 1: natural C++ member declarations instead of raw __fastcall address calls.
class TDropDownPanel {
public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void set_active(int);
    void empty_list();
    int append_line(long, long);
    void setCurrentLineNumber(long);
};
class TRIBE_Screen_Sed {
public:
    char gap[0x5BC];
    TDropDownPanel* player_advance_civilization_drop;
    int Set_player_advance_civilization_text(int);
};
int TRIBE_Screen_Sed::Set_player_advance_civilization_text(int)
{
    this->player_advance_civilization_drop->empty_list();
    this->player_advance_civilization_drop->append_line(0x1069, 0);
    this->player_advance_civilization_drop->append_line(0x106A, 1);
    this->player_advance_civilization_drop->append_line(0x106B, 2);
    this->player_advance_civilization_drop->append_line(0x106C, 3);
    this->player_advance_civilization_drop->append_line(0x106D, 4);
    this->player_advance_civilization_drop->setCurrentLineNumber(0);
    this->player_advance_civilization_drop->set_active(0);
    return 1;
}
