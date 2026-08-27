# 00462010 play_track

The original source is `music.cpp`, lines 452 through 467.

The function sets a one-track request. It starts a fade when active playback uses fade-out. Otherwise it calls the protected play helper.

Earlier work tested raw field offsets. The module keeps named fields only.
