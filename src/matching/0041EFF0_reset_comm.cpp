


extern TCommunications_Handler* comm;

int RGE_Base_Game::reset_comm() {
    TCommunications_Handler* handler = comm_handler;
    if (handler != 0) {
        handler->~TCommunications_Handler();
        operator delete(handler);
        comm_handler = 0;
        comm = 0;
    }
    return setup_comm();
}
