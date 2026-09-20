// V11 waits for dense responsive input to finish before it starts the terminal turn window.
let v11TerminalTurn = null;
let v11DrawSystem = null;
human.terminal_turn = null;
Interceptor.attach(paint, {onEnter() { v11DrawSystem = this.context.ecx; }});
function v11CaptureInputFrame() {
    if (v11DrawSystem === null) return;
    const area = v11DrawSystem.add(12).readPointer();
    if (area.isNull()) return;
    const surface = area.add(60).readPointer(), pal = v11DrawSystem.add(36).readPointer();
    if (surface.isNull() || pal.isNull()) return;
    desc.writeU32(108);
    if (method(surface,22,['pointer','pointer'])(surface,desc) !== 0) throw new Error('V11 GetSurfaceDesc failed');
    const height=desc.add(8).readU32(), width=desc.add(12).readU32(), pitch=desc.add(16).readS32();
    const pixels=desc.add(36).readPointer(), bits=desc.add(84).readU32();
    if (bits !== 8 || pixels.isNull() || width < 1 || height < 1 || width > 4096 || height > 4096 || pitch < width || pitch > 8192)
        throw new Error('V11 surface description is invalid');
    if (method(pal,4,['pointer','uint','uint','uint','pointer'])(pal,0,0,256,palette) !== 0)
        throw new Error('V11 GetEntries failed');
    const data = new Uint8Array(pitch*height+1024);
    data.set(new Uint8Array(pixels.readByteArray(pitch*height)));
    data.set(new Uint8Array(palette.readByteArray(1024)),pitch*height);
    humanNativeFrames();
    send({kind:'frame',count,width,height,pitch,bits,panel:currentPanelName(),time_ms:ticks-1000},data.buffer);
    humanAfterFrame();
}
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
    if (ticks-1000-human.lastFrame >= 50) v11CaptureInputFrame();
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
