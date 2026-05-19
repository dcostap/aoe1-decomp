struct TRIBE_History_Events { unsigned char event; char gap_01[3]; long time; char gap_08[4]; TRIBE_History_Events* next; };
class TRIBE_History_Info { public: char gap_00[4]; TRIBE_History_Events* events; unsigned char get_history_event(long time, unsigned char& event); };
struct Special_Events { long time_slice; long X_line_pos; long Y_line_pos; long intermediate_y_line_segment; unsigned char player_id; unsigned char player_color; unsigned char event; char gap_13; long pop_total; long field_18; long field_1C; long field_20; long field_24; long field_28; long field_2C; long field_30; long field_34; long field_38; unsigned char field_3C; char gap_3D[0x33]; long field_70; unsigned char field_74; char gap_75[0x33]; long field_A8; Special_Events* next; };
class Time_Line_Panel { public: char gap[0x518]; Special_Events* time_slice_events; void record_special_event(unsigned char,TRIBE_History_Info*,unsigned char,long,long,long,long); };
void* __cdecl calloc(int,int);
void Time_Line_Panel::record_special_event(unsigned char param_1,TRIBE_History_Info* param_2,unsigned char param_3,long param_4,long param_5,long param_6,long param_7){
    long t=param_4;
    if (!param_2->get_history_event(t, *(unsigned char*)&param_4)) return;
    Special_Events* p=(Special_Events*)calloc(1,0xB0);
    p->X_line_pos=param_5; p->Y_line_pos=param_6; p->intermediate_y_line_segment=param_7; p->time_slice=t;
    p->player_id=param_1; p->player_color=param_3; p->event=(unsigned char)param_4;
    p->pop_total=0; p->field_18=0; p->field_1C=0; p->field_20=0; p->field_24=0; p->field_28=0; p->field_2C=0; p->field_30=0; p->field_34=0; p->field_38=0; p->field_3C=0; p->field_70=0; p->field_74=0; p->field_A8=0;
    p->next=time_slice_events; time_slice_events=p;
}
