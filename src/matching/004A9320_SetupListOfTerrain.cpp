// VA: 004A9320 TRIBE_Screen_Sed::SetupListOfTerrain | scr_sed.cpp:836-848

#ifndef SCR_SED_TU_CONTEXT
class TTextPanel {
public:
    char gap_00[4];
    void empty_list(void);
    int append_line(long string_id, int param);
};
class TListPanel : public TTextPanel {
};

class TRIBE_Screen_Sed {
public:
    int SetupListOfTerrain(TListPanel* list);
};
#endif

int TRIBE_Screen_Sed::SetupListOfTerrain(TListPanel* list) {
    list->empty_list();
    list->append_line(0x297D, 0);
    list->append_line(0x297E, 0);
    list->append_line(0x297F, 0);
    list->append_line(0x2980, 0);
    list->append_line(0x2981, 0);
    list->append_line(0x2982, 0);
    list->append_line(0x2983, 0);
    list->append_line(0x2984, 0);
    list->append_line(0x2985, 0);
    return 8;
}
