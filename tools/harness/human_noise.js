// Noise v2: marked queue traffic with observed suppression receipts.
let noiseBatches = 0;
const noiseReceipts = {timer:0,paint:0};
const noiseActive = new Set();
for (const name of ['DispatchMessageA','DispatchMessageW']) {
    Interceptor.attach(hu.getExportByName(name), {onEnter(args) {
        this.noiseKey = null;
        if (this.threadId !== gameThread || !gameWindow) return;
        const msg = args[0], key = msg.toString();
        if (!msg.readPointer().equals(gameWindow) || msg.add(12).readU32() !== 0 || noiseActive.has(key)) return;
        const marker = msg.add(8).readU32();
        if (marker !== 0x4e540001 && marker !== 0x4e500001) return;
        noiseActive.add(key);
        this.noiseKey = key;
        // Earlier control hooks must already have changed this message to WM_NULL.
        if (msg.add(4).readU32() === 0) noiseReceipts[marker === 0x4e540001 ? 'timer' : 'paint']++;
    },onLeave() {
        if (this.noiseKey !== null) noiseActive.delete(this.noiseKey);
    }});
}
const noiseTimer = setInterval(() => {
    if (!gameWindow || human.stopped) return;
    if (!post(gameWindow,0x113,0x4e540001,0) || !post(gameWindow,0xf,0x4e500001,0)) {
        humanStop('Cannot post diagnostic queue noise');
        return;
    }
    noiseBatches++;
}, 37);
const noisePreviousStop = humanStop;
humanStop = function(error) {
    clearInterval(noiseTimer);
    send({kind:'control-noise-summary',version:2,period_ms:37,batches:noiseBatches,
        suppressed_dispatches:noiseReceipts});
    noisePreviousStop(error);
};
send({kind:'control-noise-ready',version:2,period_ms:37,messages:[0x113,0xf],
    scope:'Queued timer/paint robustness stimulus; not a read-only observer or recorded input'});
