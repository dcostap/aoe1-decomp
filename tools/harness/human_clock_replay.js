// Replay every recorded game-clock return value in call order.
{
    const clockTrace = cfg.human.replay_clock_trace;
    const boundaryRealStart = (realTick() - Math.max(0,ticks - 1000)) >>> 0;
    globalThis.replayBoundaryTime = function() { return ((realTick() - boundaryRealStart) >>> 0); };
    let clockRun = 0, clockRunUsed = 0, clockCalls = 0;
    humanClock = function() {
        if (clockRun >= clockTrace.length) {
            humanStop('Replay used more global clock calls than recorded');
            return ticks >>> 0;
        }
        const run = clockTrace[clockRun], value = run[0] >>> 0;
        if (++clockRunUsed === run[1]) { clockRun++; clockRunUsed = 0; }
        clockCalls++;
        ticks = value;
        return value;
    };
    // The responsive shell maps humanAdvance to wall time. The recorded stream
    // owns ticks during replay, so idle calls must not overwrite it.
    humanAdvance = function() { return ticks >>> 0; };
    const globalClockStatus = rpc.exports.status;
    rpc.exports.status = () => Object.assign(globalClockStatus(), {clock_replay:{calls:clockCalls,
        runs:clockRun,run_calls:clockRunUsed,complete:clockRun === clockTrace.length && clockRunUsed === 0}});
    if (!cfg.human.message_recording) setInterval(function() {
        if (!isReplay || human.stopped || waiting.length) return;
        pumpReplay();
        if (!waiting.length && human.posted < events.length && human.updates < events[human.posted].updates)
            post(gameWindow,0,0,0);
    }, 1);
}
