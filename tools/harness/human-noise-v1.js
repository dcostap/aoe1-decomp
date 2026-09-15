// Explicit robustness stimulus. These queued messages are not recorded user input.
let noiseBatches = 0;
const noiseTimer = setInterval(() => {
    if (!gameWindow || human.stopped) return;
    if (!post(gameWindow,0x113,0,0) || !post(gameWindow,0xf,0,0)) {
        humanStop('Cannot post diagnostic queue noise');
        return;
    }
    noiseBatches++;
}, 37);
const noisePreviousStop = humanStop;
humanStop = function(error) {
    clearInterval(noiseTimer);
    send({kind:'control-noise-summary',period_ms:37,batches:noiseBatches});
    noisePreviousStop(error);
};
send({kind:'control-noise-ready',period_ms:37,messages:[0x113,0xf],
    scope:'Queued timer/paint robustness stimulus; not a read-only observer or recorded input'});
