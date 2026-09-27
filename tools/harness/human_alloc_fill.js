// Harness-only determinism shim. Zero-fill every game C++ allocation.
// The shipped operator new returns untouched memory. Empty ManagedArray
// slots then read heap leftovers as game ids (taitacmd.cpp:2758, 2861,
// 2881, 6973, 7642). Source recovery keeps that behavior. Deterministic
// trace runs normalize fresh allocations to zero here instead.
// Scope: operator new is emitted inside empiresx.exe. DLL allocators stay
// native. C++ constructors run after this fill and overwrite fields.
{
    const allocNew = target('alloc_new'); // operator new(unsigned); original 0x0054B6F0
    const zeroChunk = new Uint8Array(65536);
    let allocBlocks = 0, allocBytes = 0;
    Interceptor.attach(allocNew, {
        onEnter(args) { this.size = args[0].toUInt32(); },
        onLeave(retval) {
            if (retval.isNull() || this.size === 0 || this.size > 0x4000000) return;
            let offset = 0;
            while (offset < this.size) {
                const count = Math.min(zeroChunk.length, this.size - offset);
                retval.add(offset).writeByteArray(count === zeroChunk.length
                    ? zeroChunk : zeroChunk.subarray(0, count));
                offset += count;
            }
            allocBlocks++;
            allocBytes += this.size;
        }
    });
    const allocFillStop = humanStop;
    humanStop = function(error) {
        send({kind:'alloc-fill-status', blocks:allocBlocks, bytes:allocBytes});
        allocFillStop(error);
    };
}
