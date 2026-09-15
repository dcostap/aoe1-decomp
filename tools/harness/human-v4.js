// V4 extends the frozen v3 experiment with deterministic queued-paint delivery.
// Synchronous game-requested paints remain intact.
const v4Validate = ha(hu, 'ValidateRect', 'int', ['pointer','pointer']);
const v4Send = ha(hu, 'SendMessageA', 'int', ['pointer','uint','pointer','pointer']);
let v4Painting = false;
human.control_profile = 'v4-controlled-paint';
human.native_paints_suppressed = 0;
for (const name of ['DispatchMessageA','DispatchMessageW']) {
    Interceptor.attach(hu.getExportByName(name), {onEnter(args) {
        if (this.threadId !== gameThread || !gameWindow || human.stopped) return;
        const msg = args[0];
        if (msg.add(4).readU32() === 0xf && msg.readPointer().equals(gameWindow)) {
            // Acknowledge the dirty region, or PeekMessage can return WM_PAINT forever.
            if (!v4Validate(gameWindow,NULL)) { humanStop('Cannot acknowledge queued paint'); return; }
            msg.add(4).writeU32(0);
            human.native_paints_suppressed++;
        }
    }});
}
Interceptor.attach(target('idle'), {onLeave() {
    if (this.threadId !== gameThread || !gameWindow || human.stopped || v4Painting) return;
    v4Painting = true;
    try { v4Send(gameWindow,0xf,NULL,NULL); }
    finally { v4Painting = false; }
}});
