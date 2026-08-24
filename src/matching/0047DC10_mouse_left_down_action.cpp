#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel;

class TTextPanelHandler {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void mouse_left_down_action(TTextPanel* panel, int a2, int a3, int a4);
};
#endif

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    virtual long mouse_left_down_action(long x, long y, int buttons, int keys);

    unsigned char gap_04[0x3C];
    TTextPanelHandler* handler;
};
#endif

long TTextPanel::mouse_left_down_action(long x, long y, int buttons, int keys) {
    if (handler != 0) {
        handler->mouse_left_down_action(this, 1, 0, 0);
    }
    return 0;
}
