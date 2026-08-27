# 00462670 resume_play

The original source is `music.cpp`, lines 779 through 820.

The function resumes only an active paused device. It ends a fade first. Types 1 and 2 issue separate MCI play calls. Type 3 resumes the sound-driver stream.

Several guard and switch forms had the same wrong VC5 register allocation. Case-local MCI results preserved both required MCI calls. That source gave the prior exact result.
