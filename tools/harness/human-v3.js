// Experimental v3 control: native timers must not select simulation idle boundaries.
// This is an explicit replay upgrade, not a reconstruction of missing v1 timer history.
if (!isReplay) throw new Error('The v3 experiment currently requires replay inputs');
const v3TerminalTurn = (events.length ? events[events.length-1].turn : 0) + 8;
const v3HistoricalDuration = cfg.human.duration_ms;
// The old duration describes another clock policy. Keep it in the capture fixture.
// Stop this experiment at a declared input-relative turn, with the worker deadline intact.
cfg.human.duration_ms = 290000;
human.control_profile = 'v3-no-native-timers';
human.historical_duration_ms = v3HistoricalDuration;
human.terminal_turn = v3TerminalTurn;
human.native_timers_suppressed = 0;
for (const name of ['DispatchMessageA','DispatchMessageW']) {
    Interceptor.attach(hu.getExportByName(name), {onEnter(args) {
        if (this.threadId !== gameThread || human.stopped) return;
        const msg = args[0];
        if (msg.add(4).readU32() === 0x113) {
            msg.add(4).writeU32(0);
            human.native_timers_suppressed++;
        }
    }});
}
humanFrameDue = function() {
    return !human.stopped && (human.turn >= v3TerminalTurn || ticks-1000-human.lastFrame >= 50);
};
humanAfterFrame = function() {
    human.lastFrame = ticks-1000;
    if (human.turn >= v3TerminalTurn) {
        humanStop(waiting.length || human.input !== events.length ? 'V3 terminal turn reached before all inputs arrived' : null);
    }
};
Interceptor.attach(target('idle'), {onLeave() {
    if (this.threadId !== gameThread || !gameWindow || human.stopped) return;
    if (human.turn >= v3TerminalTurn && !invalidate(gameWindow,NULL,0))
        humanStop('Cannot request the v3 terminal frame');
}});
