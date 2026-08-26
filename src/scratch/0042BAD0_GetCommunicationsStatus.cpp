#if !defined(COM_HAND_TU_CONTEXT)
enum COMMSTATUS {
    UNINITIALIZED = 0,
    INITIALIZED = 1,
    SINGLE_PLAYER = 2,
    MULTIPLAYER_RESET = 3,
    CONVERSATION_OPEN = 4,
    SERVICE_AVAILABLE = 5,
    SESSION_AVAILABLE = 6,
    SESSION_HOSTED = 7,
    COMMSTATUS_UNKNOWN = 8,
    PLAYER_CREATED = 9,
    COMM_SETTINGS_EXCHANGED = 10,
    GAME_PLAYER_SET = 11,
    GAME_OPTIONS_EXCHANGED = 12,
    GAME_IS_LOADING = 13,
    GAME_IS_RUNNING = 14,
    GAME_IS_PAUSED = 15
};

class TCommunications_Handler {
public:
    char gap_0[0x12D4];
    COMMSTATUS field_12D4;
    COMMSTATUS AnalyzeCommunicationsStatus();
    COMMSTATUS GetCommunicationsStatus();
};
#endif // COM_HAND_TU_CONTEXT


COMMSTATUS TCommunications_Handler::GetCommunicationsStatus() {
    this->field_12D4 = this->AnalyzeCommunicationsStatus();
    return this->field_12D4;
}
