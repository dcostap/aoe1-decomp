// Replay the clock values observed inside each recorded world update.
{
    const updateTrace = cfg.human.replay_update_trace;
    const outsideUpdateClock = humanClock;
    let updateIndex = 0, activeUpdate = null, clockRun = 0, clockRunUsed = 0;
    humanClock = function() {
        if (activeUpdate === null) {
            if (updateIndex >= updateTrace.length) return outsideUpdateClock();
            const next = updateTrace[updateIndex];
            const outside = outsideUpdateClock() >>> 0;
            if (!waiting.length && human.posted < events.length) pumpReplay();
            if (ticks < next.entry_clock || human.input < next.entry_input)
                return (updateIndex ? updateTrace[updateIndex - 1].exit_clock :
                    Math.min(outside, next.entry_clock - 1)) >>> 0;
            return next.entry_clock >>> 0;
        }
        if (clockRun >= activeUpdate.clocks.length) {
            humanStop('World update used more clock reads than recorded at update ' + (updateIndex + 1));
            return activeUpdate.exit_clock >>> 0;
        }
        const run = activeUpdate.clocks[clockRun], value = run[0] >>> 0;
        if (++clockRunUsed === run[1]) { clockRun++; clockRunUsed = 0; }
        return value;
    };
    Interceptor.attach(target('probe_human_world'), {
        onEnter() {
            this.world = this.context.ecx;
            if (updateIndex >= updateTrace.length) {
                humanStop('Replay used more world updates than recorded');
                return;
            }
            activeUpdate = updateTrace[updateIndex];
            clockRun = 0; clockRunUsed = 0;
        },
        onLeave() {
            if (activeUpdate === null) return;
            const ordinal = updateIndex + 1;
            if (clockRun !== activeUpdate.clocks.length || clockRunUsed !== 0)
                humanStop('World update used fewer clock reads than recorded at update ' + ordinal);
            else if (this.world.add(4).readU32() !== activeUpdate.exit_time ||
                     this.world.add(12).readU32() !== activeUpdate.exit_delta)
                humanStop('World state diverged at update ' + ordinal);
            activeUpdate = null;
            updateIndex++;
        }
    });
    setInterval(function() {
        if (isReplay && !human.stopped && !waiting.length) pumpReplay();
    }, 1);
}
