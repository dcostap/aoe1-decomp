#ifndef RGE_VIEW_SHARED_CONTEXT
class DClipInfo_List {
public:
    char gap_00[0x4C];
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;

    void SetCaptureLevel(int min_level, int max_level);
};
#endif

void DClipInfo_List::SetCaptureLevel(int min_level, int max_level) {
    int temp;

    if (min_level > max_level) {
        temp = min_level;
        min_level = max_level;
        max_level = temp;
    }
    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > Max_Draw_Levels) {
        max_level = Max_Draw_Levels;
    }
    Accept_Min_Level = min_level;
    Accept_Max_Level = max_level;
}
