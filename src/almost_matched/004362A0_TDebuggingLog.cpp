// STATUS: almost_matched
// CLASS: codegen_calling_convention_stub
// RISK: low
// WHY: Original is a pure `jmp` stub. Rebuild emits `mov ecx,[esp+4]; jmp` because VC5
// cannot emit a bare-call stub without the thiscall parameter-load prologue first.
// NEXT: None under VC5 — codegen-level constraint.
extern "C" void probe_TDebuggingLog(void* p);
#pragma alloc_text(".text", probe_TDebuggingLog)
extern "C" void probe_TDebuggingLog(void* p) {
    (void)p;
}
