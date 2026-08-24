class TCommunications_Handler {
public:
    ~TCommunications_Handler();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual int reset_comm_tail();

    char gap_004[0x188];
    TCommunications_Handler* comm_handler;

    int reset_comm();
};

extern TCommunications_Handler* comm;

int RGE_Base_Game::reset_comm() {
    TCommunications_Handler* handler = comm_handler;
    if (handler != 0) {
        handler->~TCommunications_Handler();
        operator delete(handler);
        comm_handler = 0;
        comm = 0;
    }
    return reset_comm_tail();
}
