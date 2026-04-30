// 00448B30 ds_stream_messages
// Dsutil.c:1684-1718, 105 bytes, __cdecl

extern unsigned long stream_position;
extern unsigned long stream_buffer_size;
extern long old_position;
void ds_stream_stop(void);

void ds_stream_messages(int msg) {
    msg -= 0x500;
    if (msg == 0) {
        ds_stream_stop();
        msg = 0;
        return;
    }
    if (msg != 2) return;
    
    {
        unsigned long a = stream_position;
        unsigned long b = stream_buffer_size;
        if (a > b) {
            stream_position = a - b;
            a = a - b;
        }
        
        a = a * 5;
        a = a * 5;
        a = a * 4;
        a = a / b;
        
        if ((long)((double)a) != old_position) {
            old_position = (long)((double)a);
        }
    }
}
