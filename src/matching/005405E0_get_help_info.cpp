// RGE_Main_View::get_help_info
// VA: 005405E0
// PDB-qualified owner/name: RGE_Main_View::get_help_info
// PDB source: vw_main.cpp:1926-1940
// Original body boundary: 005405E0-00540677; next symbol: 00540680.
// 152 bytes
//
// Exact-finish: typed object ownership, the proven TPanel virtual surface, and
// a qualified base call reproduce the original 152 bytes.
// The raw offset walkback was exact but was discarded by policy.
// BINARY NOTE: The original rereads object->master_obj before both helper calls.
// Keep both expressions direct to preserve that fault order and reload pattern.

#include <string.h>

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Tile;

class RGE_Pick_Info {
public:
    float x;       // +0x00
    float y;       // +0x04
    short scr_x;   // +0x08
    short scr_y;   // +0x0A
    RGE_Static_Object* object; // +0x0C
    RGE_Tile* tile; // +0x10
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int get_help_message(void);
    int get_help_page(void);
};

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual int vfBC(long x, long y);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual unsigned char get_help_info(char*& str_out, long& page_out,
                                        long param_3, long param_4);
    char* get_string(int id);
};

class RGE_Main_View : public TPanel {
public:
    unsigned char pick1(int key, int key_mod, long x, long y, RGE_Pick_Info* info, void* exclude, int flag);
protected:
    virtual unsigned char get_help_info(char*& str_out, long& page_out,
                                        long param_3, long param_4);
};

unsigned char RGE_Main_View::get_help_info(char*& str_out, long& page_out, long param_3, long param_4) {
    RGE_Pick_Info pickInfo;
    unsigned char result = this->pick1(0x29, 2, param_3, param_4, &pickInfo, 0, 1);

    if (result == 0x34) {
        // Use object field (+0x0C) not tile (+0x10) to match original stack offset
        int msgId = pickInfo.object->master_obj->get_help_message();
        char* msg = this->get_string(msgId);

        strcpy(str_out, msg);

        int pageId = pickInfo.object->master_obj->get_help_page();
        page_out = pageId;

        return 1;
    }

    return TPanel::get_help_info(str_out, page_out, param_3, param_4);
}
