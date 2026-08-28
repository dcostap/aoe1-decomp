#ifndef AOE1_COM_SPEED_H
#define AOE1_COM_SPEED_H

// PDB owner: Com_spd.cpp.

class RGE_TimeSinceLastCall;
class TCommunications_Handler;

class RGE_Communications_Speed {
public:
    char text_buffer[255];
    unsigned char text_buffer_pad;
    RGE_TimeSinceLastCall* turn_timer;
    RGE_TimeSinceLastCall* frame_timer;
    TCommunications_Handler* handler;
    unsigned char pad_10c[4];
    double accumulated_difference;
    int speed_control_enabled;
    unsigned int current_buffer_frames;
    unsigned int future_buffer_frames;
    unsigned int total_buffer_frames_remaining;
    unsigned int target_turn_length_msec;
    unsigned int current_buffer_granularity;
    unsigned int future_buffer_granularity;
    unsigned int overhead_factor;
    unsigned long time_since_last_buffer;
    unsigned long future_speed_change_turn;
    unsigned long next_latency_change_turn;
    unsigned int actual_latency[10];
    unsigned int average_tslc[10];
    unsigned char player_optimal_frames[10];
    unsigned char player_optimal_granularity[10];
    unsigned short request_faster_or_slower[10];
    unsigned long PlayerAvgFramesMsec[10];
    unsigned long player_high_latency_msec[10];
    unsigned long highest_latency_msec;
    unsigned int skip_frames;
    unsigned int optimal_buffer_frames;
    unsigned int optimal_buffer_granularity;
    unsigned int difference_offset;
    unsigned int acknowledged_buffers_remaining;
    unsigned int last_adjusted;
    unsigned long real_time_passed;
    unsigned long buffer_time_passed;
    unsigned int dropped_frames;
    unsigned int dropped_frames_turn;
    unsigned long adjustment_count;
    int last_frame_had_time;

    unsigned long GetPlayerLatency(unsigned int);
};

typedef char com_speed_size_check[
    (sizeof(RGE_Communications_Speed) == 0x240) ? 1 : -1];

#endif
