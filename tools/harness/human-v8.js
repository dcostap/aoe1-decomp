// V8 keeps interactive recording responsive. Controlled V9 replay uses the frozen paced clock.
if (['human-real-clock-v8-responsive-recording',
     'human-real-clock-v10-responsive-editor-recording'].includes(cfg.humanControl.executed_policy)) {
    const responsiveStart = realTick();
    humanAdvance = function() {
        ticks = 1000 + ((realTick() - responsiveStart) >>> 0);
        return ticks >>> 0;
    };
    humanClock = function() { return humanAdvance(); };
    Interceptor.attach(target('idle'), {onLeave() {
        if (!isReplay && gameWindow && !human.stopped && this.threadId === gameThread) {
            humanAdvance();
            // Give controlled replay a stable 20-ms schedule without limiting recording input.
            human.turn = Math.floor((ticks - 1000) / 20);
        }
    }});
}
