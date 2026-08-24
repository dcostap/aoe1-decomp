// 00448B30 ds_stream_messages
// Dsutil.c:1684-1718, 105 bytes, __cdecl

extern unsigned long ds_stream_position;
extern unsigned long ds_buffer_bytes;
extern long ds_last_percent;
int ds_stream_stop(void);

int ds_stream_messages(int a1, int a2)
{
    switch (a2) {
    case 0x500:
        ds_stream_stop();
        break;
    case 0x502: {
        unsigned long a = ds_stream_position;
        unsigned long b = ds_buffer_bytes;
        if (a > b) {
            ds_stream_position = a - b;
            a = a - b;
        }
        {
            unsigned long temp = a * 100 / b;
            double d = (double)temp;
            long percent = (long)d;
            if (percent != ds_last_percent) {
                ds_last_percent = percent;
            }
        }
        break;
    }
    }
    return 0;
}
