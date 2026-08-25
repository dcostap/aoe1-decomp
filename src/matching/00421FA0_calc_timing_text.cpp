extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

void RGE_Base_Game::calc_timing_text()
{
    unsigned long divisor = this->frame_count;
    if (divisor == 0)
        divisor = 1;

    sprintf(this->timing_text,
        "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu",
        this->fps,
        this->world_update_count / divisor,
        this->view_update_count / divisor,
        this->timings[0].last_time / divisor,
        this->timings[0].accum_time / divisor,
        this->timings[0].start_time / divisor,
        this->timings[1].last_time / divisor,
        this->timings[1].accum_time / divisor,
        this->timings[1].start_time / divisor,
        this->timings[0].last_single_time / divisor);
}
