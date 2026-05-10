// TRIBE_Screen_Sed::command_menu — real pass (EH-framed)
// VA: 004AD270
// Attempt log:
// - Previous raw __fastcall helpers missed EH/new-expression shape and produced an 80-byte too-short body.
// - 2026-05-10 StarryZephyr pass: rewrote as natural typed /GX new-expression with virtual activation check.

class TRIBE_Screen_Sed;

class TRIBE_Dialog_Sed_Menu {
public:
    virtual void activate(int flag);
    char gap_004[0x0D8 - 0x004];
    void* field_D8;
    char gap_0DC[0x4B4 - 0x0DC];

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* screen);
};

class TRIBE_Screen_Sed {
public:
    int command_menu();
};

int TRIBE_Screen_Sed::command_menu()
{
    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this);
    if (dlg != 0 && dlg->field_D8 != 0) {
        dlg->activate(1);
        return 0;
    }
    return 1;
}
