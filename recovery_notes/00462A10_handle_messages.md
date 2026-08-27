# 00462A10 handle_messages

The original source is `music.cpp`, lines 969 through 1065.

The function handles activation, timer, MCI notify, and streamed-wave completion messages. It pauses or resumes for activation. It advances tracks after completion.

A nested message dispatch with the timer and notify arms in this order gave the prior exact result.
