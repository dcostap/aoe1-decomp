class TDrawArea {
public:
    void Clear(void* rect, int unk);
};

class TDrawSystem {
public:
    void Paint(void* rect);
};

class RGE_Base_Game {
public:
    char gap_00[0x44];
    TDrawSystem* draw_system;
    TDrawArea* draw_area;

    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int action_close();

    int handle_close(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

int RGE_Base_Game::handle_close(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != 0 && this->draw_system != 0) {
        this->draw_area->Clear(0, 0);
        this->draw_system->Paint(0);
    }
    return 1;
}
