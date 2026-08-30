# Function notes: 00461F60 `set_volume`

## Earlier notes from `decomp_notes/functions/0046/00461F60_set_volume.md`

This section is historical. Use the status query for current state.

## 00461F60 set_volume

The original source is `music.cpp`, lines 393 through 448.

The function clamps the volume to -10000 through 0. It saves the requested value when requested. Type 3 sends the value to the sound driver. Types 1 and 2 set the mixer control value.

The mixer formula uses `(range * (volume + 10000)) / 10000`. This gave the prior exact VC5 lowering. The normal module calls `mixerSetControlDetails` directly. It removes the old imported function-pointer fallback.
