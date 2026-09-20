// V11 waits for dense responsive input to finish before it starts the terminal turn window.
let v11TerminalTurn = null;
human.terminal_turn = null;
function v11UpdateTerminal() {
    if (v11TerminalTurn === null && human.input === events.length && waiting.length === 0) {
        v11TerminalTurn = human.turn;
        human.terminal_turn = v11TerminalTurn;
    }
}
humanFrameDue = function() {
    v11UpdateTerminal();
    return !human.stopped && ((v11TerminalTurn !== null && human.turn >= v11TerminalTurn) ||
        ticks-1000-human.lastFrame >= 50);
};
humanAfterFrame = function() {
    human.lastFrame = ticks-1000;
    if (v11TerminalTurn !== null && human.turn >= v11TerminalTurn)
        humanStop(waiting.length || human.input !== events.length ? 'V11 terminal turn reached before all inputs arrived' : null);
};
Interceptor.attach(target('idle'), {onLeave() {
    if (this.threadId !== gameThread || !gameWindow || human.stopped) return;
    v11UpdateTerminal();
    if (v11TerminalTurn !== null && human.turn >= v11TerminalTurn && !invalidate(gameWindow,NULL,0))
        humanStop('Cannot request the v11 terminal frame');
}});
humanInputDrained = function() {
    if (!gameWindow || human.stopped) return;
    v11UpdateTerminal();
    if (v11TerminalTurn !== null) humanStop(null);
};
for (const name of ['DispatchMessageA','DispatchMessageW']) {
    Interceptor.attach(hu.getExportByName(name), {onLeave() {
        if (this.threadId !== gameThread || !gameWindow || human.stopped) return;
        v11UpdateTerminal();
        if (v11TerminalTurn !== null && !invalidate(gameWindow,NULL,0))
            humanStop('Cannot request the v11 terminal frame');
    }});
}
