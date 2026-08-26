#ifndef TPNL_TML_WRAPPER
struct TRIBE_History_Events { unsigned char event; char gap_01[3]; long time; char gap_08[4]; TRIBE_History_Events* next; };
class TRIBE_History_Info { public: char gap_00[4]; TRIBE_History_Events* events; unsigned char get_history_event(long time, unsigned char& event); };
struct Special_Events { long time_slice; long X_line_pos; long Y_line_pos; long intermediate_y_line_segment; unsigned char player_id; unsigned char player_color; unsigned char event; char gap_13; long pop_total; long integer_value_1; long integer_value_2; long start_x; long start_y; long start_txt_x1; long start_txt_y1; long start_txt_x2; long start_txt_y2; int text_length1; char text1[50]; char gap_6E[2]; int text_length2; char text2[50]; char gap_A6[2]; int icon_flag; Special_Events* next; };
class Time_Line_Panel { public: char gap[0x518]; Special_Events* time_slice_events; void record_special_event(unsigned char,TRIBE_History_Info*,unsigned char,long,long,long,long); };
#endif
void* __cdecl calloc(int,int);
void Time_Line_Panel::record_special_event(unsigned char param_1,TRIBE_History_Info* param_2,unsigned char param_3,long param_4,long param_5,long param_6,long param_7){
    long t=param_4;
    if (!param_2->get_history_event(t, *(unsigned char*)&param_4)) return;
    Special_Events* p=(Special_Events*)calloc(1,0xB0);
    p->X_line_pos=param_5; p->Y_line_pos=param_6; p->intermediate_y_line_segment=param_7; p->time_slice=t;
    p->player_id=param_1; p->player_color=param_3; p->event=(unsigned char)param_4;
    p->pop_total=0;
    p->integer_value_1=0; p->integer_value_2=0; p->start_x=0; p->start_y=0; p->start_txt_x1=0; p->start_txt_y1=0; p->start_txt_x2=0; p->start_txt_y2=0; p->text_length1=0; p->text1[0]=0; p->text_length2=0; p->text2[0]=0; p->icon_flag=0;
    p->next=time_slice_events; time_slice_events=p;
}
