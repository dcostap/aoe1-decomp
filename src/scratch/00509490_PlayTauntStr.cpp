// 00509490 TTaunt::PlayTauntStr
// Source: taunt.cpp lines 30-56
// Size: 156 bytes, no EH
//
// Attempt log:
// Probe 1: hardcoded lengths, 3 register saves → 128 bytes, missing ebp push
// Probe 2-3: class layout issues + runtime strlen → different structure
// Left in scratch: codegen basin (register allocation for 4 callee-saves, strlen vs hardcoded, shared epilogue)
