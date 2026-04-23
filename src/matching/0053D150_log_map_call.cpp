// tried the direct ring-buffer spelling first; first mismatch was the outer wrap branch direction
// trying the wrap-first spelling next so VC5 may choose the same jl/jge layout as the asm
// if it stays non-exact, the remaining gap is likely branch-form/codegen rather than behavior

class VC_LOG {
public:
    int world_time;
    int player_id;
    int action;
    int object_id;
    int x1;
    int y1;
    int x2;
    int y2;
    int supress;
};

extern int VCALL_LOG_HEAD;
extern int VCALL_LOG_TAIL;
extern VC_LOG VCALL_LOG[1024];

void __cdecl log_map_call(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    int idx = VCALL_LOG_HEAD + 1;
    if (idx >= 0x400) {
        idx = 0;
        VCALL_LOG_TAIL = 1;
    } else if (VCALL_LOG_TAIL >= 0) {
        VCALL_LOG_TAIL = idx + 1;
        if (VCALL_LOG_TAIL >= 0x400) {
            VCALL_LOG_TAIL = 0;
        }
    }
    VCALL_LOG_HEAD = idx;
    VCALL_LOG[idx].world_time = param_1;
    VCALL_LOG[idx].player_id = param_2;
    VCALL_LOG[idx].action = param_3;
    VCALL_LOG[idx].object_id = param_4;
    VCALL_LOG[idx].x1 = param_5;
    VCALL_LOG[idx].y1 = param_6;
    VCALL_LOG[idx].x2 = param_7;
    VCALL_LOG[idx].y2 = param_8;
    VCALL_LOG[idx].supress = param_9;
}
