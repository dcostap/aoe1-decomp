# 00461D20 open_mixer

The original source is `music.cpp`, lines 294 through 353.

The function opens each mixer. It selects the MIDI or wave component. It gets the volume control and its current value. It closes a mixer when a required query fails.

A direct `num_dev <= 0` guard kept the prior comparison shape. Fixed-size record clears and the normal WinMM records gave the prior exact result.
