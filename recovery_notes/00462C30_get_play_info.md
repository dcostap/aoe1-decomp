# 00462C30 get_play_info

The original source is `music.cpp`, lines 1127 through 1171.

The function initializes every output. It then reports current playback state. For MIDI playback it queries MCI position with a status record.

Earlier work tested shared and duplicated MCI tails. The prior exact result used two case-local MCI calls. The command passes the status record at `dwReturn`, sets `dwTrack` to 2, and reads `dwItem` as the result.

The prior grouped `music_tu.cpp` build matched this owner. The new normal `music.cpp` source can change this result.

## Current module result

The authentic `music.cpp` module check reports `MISMATCH`. The rebuilt body is
309 bytes, equal to the original body. It has 5 positional diff bytes across
5 spans (1.6181%), with the first mismatch at offset `+0xD7`. The frame, saved
registers, instruction count, calls, CFG, owner symbol, and boundary match.
Both relocated call sites also match.

The natural source remains the source body. This owner is scratch and is not
registered as an exact translation-unit owner.
