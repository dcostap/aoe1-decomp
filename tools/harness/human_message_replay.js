// Replays the recorded message-pump stream from messages.bin.
// Design: synthesize every recorded poll result at the recorded boundary.
// TranslateMessage and DispatchMessageA stay native USER32 calls. Poll
// entries and exits are consumed in recorded order for paired traces.
// Callers outside the recorded boundary keep stock USER32 behavior.
{
    const meta = cfg.human.message_recording;
    const traceBytes = meta.records * meta.record_size;
    const traceBuffer = new ArrayBuffer(traceBytes);
    const traceView = new DataView(traceBuffer);
    let traceLoaded = 0, traceIndex = 0, traceThread = 0, traceReady = false;
    const pairedTrace = ['aoe-message-pump-v5-le','aoe-message-pump-v6-le','aoe-message-pump-v7-le'].includes(meta.format);
    const timedTrace = meta.format === 'aoe-message-pump-v6-le' || meta.format === 'aoe-message-pump-v7-le';
    const wrapperTrace = meta.format === 'aoe-message-pump-v7-le';
    const callDurations = new Uint32Array(meta.records);
    const replayMainEnd = base.add(Process.mainModule.size);
    function gameReplayCaller(address) { return address.compare(base) >= 0 && address.compare(replayMainEnd) < 0; }
    function replayCallerAllowed(address) { return meta.format !== 'aoe-message-pump-v4-le' || gameReplayCaller(address); }
    function receiveTrace() {
        recv('message-trace', function(packet,data) {
            const offset = packet.offset >>> 0;
            new Uint8Array(traceBuffer,offset,data.byteLength).set(new Uint8Array(data));
            traceLoaded += data.byteLength;
            if (packet.done) {
                if (traceLoaded !== traceBytes) humanStop('Message replay byte count differs from its metadata');
                else {
                    if (timedTrace) {
                        const stack = [];
                        for (let i = 0; i < meta.records; i++) {
                            const api = traceView.getUint32(i * 80, true);
                            if (api & 0x80000000) stack.push(i);
                            else if (stack.length) callDurations[stack.pop()] = traceView.getUint32(i * 80 + 4, true);
                        }
                    }
                    traceReady = true;
                }
            } else receiveTrace();
        });
    }
    receiveTrace();
    function field(index) { return traceView.getUint32(traceIndex*80+index*4,true); }
    function fail(text) { humanStop('Message replay mismatch at record '+traceIndex+': '+text); }
    function finishTrace() {
        if (!human.stopRequested) {
            human.stopRequested = true; human.stop_reason = 'message-trace-complete';
            invalidate(gameWindow,NULL,0);
        }
    }
    function windowFor(id) {
        const role = meta.windows[String(id)];
        if (!role) { fail('unknown window role '+id); return gameWindow; }
        if (role.role === 'thread') return NULL;
        if (role.role === 'main') return gameWindow;
        if (role.role === 'owned') return resolveRoute(role.route);
        fail('record contains an external-window message'); return gameWindow;
    }
    function checkState() {
        // human.turn is not checked. Frida defers hook delivery, so it drifts at
        // record boundaries without any game-state difference.
        if (field(16) !== human.updates) fail('update count differs');
        if (field(17) !== human.input) fail('input count differs');
    }
    function consume(api,msg) {
        if (!traceReady) { fail('trace data is not ready'); return 0; }
        if (traceIndex >= meta.records) { fail('trace is exhausted'); return 0; }
        if (field(0) !== api) { fail('expected API '+field(0)+', got '+api); return 0; }
        checkState();
        const result = field(3);
        if (msg && result !== 0xffffffff && (api >= 5 || result !== 0)) {
            const message = field(9), value = field(10), parameter = field(11);
            let resolvedHwnd = msg.readPointer();
            if (api < 5) {
                resolvedHwnd = windowFor(field(8));
                msg.writePointer(resolvedHwnd); msg.add(4).writeU32(message); msg.add(8).writeU32(value);
                msg.add(12).writeU32(parameter); msg.add(16).writeU32(field(12));
                msg.add(20).writeU32(field(13)); msg.add(24).writeU32(field(14));
            } else if (msg.add(4).readU32() !== message || msg.add(8).readU32() !== value ||
                       msg.add(12).readU32() !== parameter) fail('dispatch MSG differs');
            const removed = api === 1 || (api === 3 && (field(7) & 1));
            const input = (message >= 0x100 && message <= 0x107) || (message >= 0x200 && message <= 0x20e);
            if (removed && input) {
                const event = events[human.posted];
                if (!event || event.message !== message || event.value !== value || event.parameter !== parameter)
                    fail('recorded input differs from message stream');
                else { waiting.push({hwnd:resolvedHwnd,event}); human.posted++; }
            }
        }
        traceIndex++;
        return result;
    }
    function consumeEnter(api,msg,hwnd,min,max,flags) {
        if (!pairedTrace) return 0;
        const entryIndex = traceIndex;
        if (field(0) !== ((api|0x80000000)>>>0)) { fail('expected API entry '+field(0)+', got '+api); return 0; }
        checkState();
        if (api < 5) {
            if (field(5) !== (min>>>0) || field(6) !== (max>>>0) || field(7) !== (flags>>>0))
                fail('poll entry parameters differ');
        } else if (msg && (msg.add(4).readU32() !== field(9) || msg.add(8).readU32() !== field(10) ||
                           msg.add(12).readU32() !== field(11))) fail('message entry differs');
        traceIndex++;
        return callDurations[entryIndex];
    }
    Interceptor.attach(target('wndproc'), {onEnter(args) {
        if (gameWindow && args[0].equals(gameWindow)) traceThread = this.threadId;
    }});
    const replayDdraw = Process.getModuleByName('ddraw.dll');
    const getAddress = wrapperTrace ? replayDdraw.base.add(0x22a40) : hu.getExportByName('GetMessageA');
    const peekAddress = wrapperTrace ? replayDdraw.base.add(0x22aa0) : hu.getExportByName('PeekMessageA');
    const nativeGet = new NativeFunction(getAddress,'int',['pointer','pointer','uint','uint'],'stdcall');
    const nativePeek = new NativeFunction(peekAddress,'int',['pointer','pointer','uint','uint','uint'],'stdcall');
    const replayGet = new NativeCallback(function(msg,hwnd,min,max) {
        if (!traceReady || !traceThread || Process.getCurrentThreadId() !== traceThread ||
            !replayCallerAllowed(this.returnAddress))
            return nativeGet(msg,hwnd,min,max);
        if (traceIndex >= meta.records) { finishTrace(); return nativeGet(msg,hwnd,min,max); }
        const duration = consumeEnter(1,msg,hwnd,min,max,0); if (duration) hs(duration);
        if (field(5) !== (min>>>0) || field(6) !== (max>>>0)) fail('GetMessage filter differs');
        return consume(1,msg)|0;
    },'int',['pointer','pointer','uint','uint'],'stdcall');
    const replayPeek = new NativeCallback(function(msg,hwnd,min,max,flags) {
        if (!traceReady || !traceThread || Process.getCurrentThreadId() !== traceThread ||
            !replayCallerAllowed(this.returnAddress))
            return nativePeek(msg,hwnd,min,max,flags);
        if (traceIndex >= meta.records) { finishTrace(); return nativePeek(msg,hwnd,min,max,flags); }
        const duration = consumeEnter(3,msg,hwnd,min,max,flags); if (duration) hs(duration);
        if (field(5) !== (min>>>0) || field(6) !== (max>>>0) || field(7) !== (flags>>>0))
            fail('PeekMessage filter differs');
        return consume(3,msg)|0;
    },'int',['pointer','pointer','uint','uint','uint'],'stdcall');
    callbacks.push(replayGet,replayPeek);
    Interceptor.replace(getAddress,replayGet);
    Interceptor.replace(peekAddress,replayPeek);
    for (const pair of [['TranslateMessage',5],['DispatchMessageA',6]]) {
        Interceptor.attach(hu.getExportByName(pair[0]), {onEnter(args) {
            this.replayMessage = false;
            if (!traceReady || !traceThread || this.threadId !== traceThread ||
                !replayCallerAllowed(this.returnAddress) || traceIndex >= meta.records) return;
            const hwnd = args[0].readPointer();
            if (!hwnd.isNull() && !hwnd.equals(gameWindow)) {
                try { route(hwnd); } catch (_) { return; }
            }
            this.replayMessage = true; this.msg = args[0];
            const duration = consumeEnter(pair[1],this.msg,NULL,0,0,0); if (duration) hs(duration);
        }, onLeave() {
            if (this.replayMessage) consume(pair[1],this.msg);
        }});
    }
    // The message stream supplies input. The old input poster must remain inactive.
    pumpReplay = function() {};
    const messageReplayStatus = rpc.exports.status;
    rpc.exports.status = () => Object.assign(messageReplayStatus(), {message_replay:{
        records:traceIndex,total:meta.records,loaded:traceLoaded,ready:traceReady}});
}
