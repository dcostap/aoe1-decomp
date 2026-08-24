#ifndef RGE_VIEW_SHARED_CONTEXT
class DClipInfo_List {
public:
    char gap_00[0x3C];
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;

    void SetDrawRegion(int xmin, int ymin, int xmax, int ymax);
};
#endif

void DClipInfo_List::SetDrawRegion(int xmin, int ymin, int xmax, int ymax) {
    if (xmin <= xmax) {
        if (ymin <= ymax) {
            SD_XMin = xmin;
            SD_XMax = xmax;
            SD_YMin = ymin;
            SD_YMax = ymax;
        }
    }
}
