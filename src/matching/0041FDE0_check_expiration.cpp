// attempt 1: zeroed tm-like local, build the expiration date, then compare current time against it
// exact match landed once the tm-like layout started at tm_min and memset zeroed the 9-dword local block before the date fields were filled

struct tm_like {
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    int tm_gmtoff;
};



extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" long mktime(tm_like* tm);
extern "C" long time(long* cur_date);

int RGE_Base_Game::check_expiration() {
    tm_like kill_def;
    long cur_date;
    long expiration;

    memset(&kill_def, 0, sizeof(kill_def));
    kill_def.tm_year = (int)this->prog_info->expire_year - 1;
    kill_def.tm_mon = (int)this->prog_info->expire_month;
    kill_def.tm_wday = (int)this->prog_info->expire_day;

    expiration = mktime(&kill_def);
    time(&cur_date);
    return cur_date <= expiration;
}
