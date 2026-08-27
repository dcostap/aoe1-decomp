# 00461A30 open_device

The original source is `music.cpp`, lines 71 through 216.

The function opens sequencer, MIDI-file, and wave-file music devices. It scans numbered files for types 2 and 3. It opens a mixer for types 1 and 2.

Tests found that a bottom-tested scan loop kept the required file-open calls. A typed MCI status record, MCI set record, MCI open record, and 261-byte file name were required. The status command uses the record tail at `dwReturn`. This follows the executable call layout.

The old source used aggregate locals and an artificial file-name prefix for byte tuning. The normal module now uses direct SDK records and a normal file-name buffer. This can change bytes.

## Current module result

The authentic `music.cpp` module check reports `MISMATCH`. The rebuilt body is
551 bytes, equal to the original body. It has 8 positional diff bytes across
8 spans (1.4519%), with the first mismatch at offset `+0x14F`. The frame,
saved registers, instruction count, calls, CFG, owner symbol, and boundary
match. All 13 relocated call sites also match.

The natural source remains the source body. This owner is scratch and is not
registered as an exact translation-unit owner.
