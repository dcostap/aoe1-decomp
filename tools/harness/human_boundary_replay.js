// Diagnostic replay restores exact recorded time, idle, and update boundaries.
globalThis.replayBoundaryTime = null;
const boundaryRealClock = humanClock;
let boundaryClock = null;
let boundaryFreeze = false;
humanClock = function() {
    if (waiting.length && boundaryFreeze) {
        if (boundaryClock === null) boundaryClock = ticks;
        return boundaryClock >>> 0;
    }
    boundaryClock = null;
    return boundaryRealClock();
};
pumpReplay = function() {
    if (!isReplay || pumping || human.stopped || waiting.length) return;
    if (human.posted >= events.length) return;
    const first = events[human.posted];
    const boundaryTime = typeof globalThis.replayBoundaryTime === 'function' ? globalThis.replayBoundaryTime() : ticks - 1000;
    if (human.turn < first.turn || human.updates < first.updates || boundaryTime < first.time_ms) return;
    pumping = true;
    try {
        const turn = first.turn, updates = first.updates, time = first.time_ms;
        let batchCount = 0;
        while (human.posted + batchCount < events.length) {
            const event = events[human.posted + batchCount];
            if (event.turn !== turn || event.updates !== updates || event.time_ms !== time) break;
            batchCount++;
        }
        boundaryFreeze = ['Game Screen','Save Game Screen'].includes(first.panel) && batchCount > 1;
        while (human.posted < events.length) {
            const event = events[human.posted];
            if (event.turn !== turn || event.updates !== updates || event.time_ms !== time) break;
            const pending = {hwnd:resolveRoute(event.route), event};
            waiting.push(pending);
            if (!post(pending.hwnd,event.message,event.value,event.parameter)) {
                waiting.pop();
                throw new Error('Cannot post recorded input batch');
            }
            human.posted++;
        }
    } finally { pumping = false; }
};
humanAfterFrame = function() {
    human.lastFrame = ticks - 1000;
    if (human.input === events.length && waiting.length === 0)
        humanStop(null);
};
Interceptor.attach(target('probe_human_world'), {onLeave() {
    if (isReplay && !human.stopped) pumpReplay();
}});
