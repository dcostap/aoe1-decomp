// 00424B80 RGE_Communications_Addresses::SetIPAliases
// Source: com_addr.cpp lines 100-135
// Size: 152 bytes, no EH
//
// Attempt log:
// Probe 1: char* hostname, 3 callee-saves → lea vs mov for hostname, 10-byte diff
// Probe 2-3: char[] hostname, restructured → completely different register alloc
// Probe 4-5: char[] + proper hostent2/strcpy → 144 vs 152 bytes (lazy register saves)
// Left in scratch: register allocation basin (3 vs 4 callee-saves at function entry)
