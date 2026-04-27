// 00509530 TTaunt::PlayTauntNo
// Source: taunt.cpp lines 59-116
// Size: 209 bytes, no EH
//
// Attempt log:
// Probe 1-2: wrong class layout (missing pack)
// Probe 3: #pragma pack(1) fixed struct offsets → 74% diff, early returns vs shared epilogue
// Probe 4: single-return with result variable → 224 bytes (too big)
// Left in scratch: codegen basin (shared epilogue, loop structure, pack alignment)
