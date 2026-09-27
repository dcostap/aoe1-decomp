// Read-only message-pump trace. Records fixed 80-byte little-endian rows.
// This module does not change API arguments, return values, or MSG storage.
{
    const MESSAGE_RECORD_SIZE = 80;
    const MESSAGE_BATCH_RECORDS = 2048;
    const messageBuffer = new ArrayBuffer(MESSAGE_RECORD_SIZE * MESSAGE_BATCH_RECORDS);
    const messageView = new DataView(messageBuffer);
    let messageUsed = 0, messageRecords = 0, messageClockCalls = 0;
    let messageThread = 0, recordingMessage = false;
    const messageWindows = new Map();
    function messageWindowId(hwnd) {
        if (!hwnd || hwnd.isNull()) return 0;
        if (hwnd.equals(gameWindow)) return 1;
        const key = hwnd.toString();
        if (messageWindows.has(key)) return messageWindows.get(key);
        const id = messageWindows.size + 2;
        messageWindows.set(key,id);
        try { send({kind:'message-window-site',id,role:'owned',route:route(hwnd)}); }
        catch (_) { send({kind:'message-window-site',id,role:'external',route:null}); }
        return id;
    }
    function ownedMessageWindow(hwnd) {
        if (!gameWindow) return false;
        if (!hwnd || hwnd.isNull() || hwnd.equals(gameWindow)) return true;
        try { route(hwnd); return true; } catch (_) { return false; }
    }
    const messageHooks = [];
    // Recording-only idle throttle. The stock loop busy-polls PeekMessage and
    // handle_idle; each spin becomes trace records that replay must consume.
    // A 1 ms sleep after an empty poll keeps input latency negligible. The game
    // reads only recorded clocks, so replay needs no matching sleep.
    const idleThrottleMs = !isReplay && cfg.human.idle_throttle_ms ? cfg.human.idle_throttle_ms : 0;
    if (idleThrottleMs) {
        const winmm = Module.load('winmm.dll');
        const period = new NativeFunction(winmm.getExportByName('timeBeginPeriod'),'uint',['uint'],'stdcall');
        if (period(1) !== 0) throw new Error('Cannot set a 1 ms timer period for the idle throttle');
    }
    const messageApis = {
        GetMessageA:1, GetMessageW:2, PeekMessageA:3, PeekMessageW:4,
        TranslateMessage:5, DispatchMessageA:6, DispatchMessageW:7
    };
    const messageDdraw = Process.getModuleByName('ddraw.dll');
    const messagePolls = [
        {name:'GetMessageA',api:1,address:messageDdraw.base.add(0x22a40)},
        {name:'PeekMessageA',api:3,address:messageDdraw.base.add(0x22aa0)}
    ];
    function flushMessageTrace() {
        if (!messageUsed) return;
        send({kind:'message-pump-batch',records:messageUsed,record_size:MESSAGE_RECORD_SIZE},
            messageBuffer.slice(0,messageUsed*MESSAGE_RECORD_SIZE));
        messageUsed = 0;
    }
    function put(offset, value) { messageView.setUint32(messageUsed*MESSAGE_RECORD_SIZE+offset,value>>>0,true); }
    function recordMessage(api, thread, result, msg, hwndFilter, min, max, flags, wallDuration) {
        if (!gameWindow || recordingMessage) return;
        if (!messageThread) return;
        if (thread !== messageThread) return;
        recordingMessage = true;
        try {
        let windowId = 0;
        if (msg && !msg.isNull() && result !== 0xffffffff && (api >= 5 || result !== 0)) {
            windowId = messageWindowId(msg.readPointer());
        }
        const base = messageUsed*MESSAGE_RECORD_SIZE;
        put(0,api); put(4,wallDuration||0); put(8,messageRecords); put(12,result);
        put(16,hwndFilter); put(20,min); put(24,max); put(28,flags);
        if (msg && !msg.isNull() && result !== 0xffffffff && (api >= 5 || result !== 0)) {
            put(32,windowId); put(36,msg.add(4).readU32());
            put(40,msg.add(8).readU32()); put(44,msg.add(12).readU32());
            put(48,msg.add(16).readU32()); put(52,msg.add(20).readU32()); put(56,msg.add(24).readU32());
        } else {
            for (let offset=32; offset<=56; offset+=4) put(offset,0);
        }
        put(60,human.turn); put(64,human.updates); put(68,human.input);
        put(72,messageClockCalls); put(76,typeof observationRecords === 'number' ? observationRecords : 0);
        messageRecords++; messageUsed++;
        if (messageUsed === MESSAGE_BATCH_RECORDS) flushMessageTrace();
        } finally { recordingMessage = false; }
    }
    function recordMessageEnter(api,thread,msg,hwndFilter,min,max,flags) {
        recordMessage((api|0x80000000)>>>0,thread,0,msg,hwndFilter,min,max,flags,0);
    }
    if (typeof humanClock !== 'undefined') {
        const messageObservedClock = humanClock;
        humanClock = function() { messageClockCalls++; return messageObservedClock(); };
    }
    messageHooks.push(Interceptor.attach(target('wndproc'), {onEnter(args) {
        if (gameWindow && args[0].equals(gameWindow)) messageThread = this.threadId;
    }}));
    for (const poll of messagePolls) {
        const name=poll.name, api=poll.api;
        const hook = Interceptor.attach(poll.address, {
            onEnter(args) {
                this.msg = args[0]; this.hwnd = args[1].toUInt32();
                this.wallStart = realTick();
                this.min = args[2].toUInt32(); this.max = args[3].toUInt32();
                this.flags = name.indexOf('Peek') === 0 ? args[4].toUInt32() : 0;
            },
            onLeave(retval) {
                const result = retval.toUInt32();
                if (result && result !== 0xffffffff && !ownedMessageWindow(this.msg.readPointer())) return;
                recordMessageEnter(api,this.threadId,null,this.hwnd,this.min,this.max,this.flags);
                try { recordMessage(api,this.threadId,result,this.msg,this.hwnd,this.min,this.max,this.flags,
                    (realTick()-this.wallStart)>>>0); }
                catch (error) { humanStop('Message trace failed: '+error); }
                if (idleThrottleMs && result === 0 && api === 3 && this.threadId === messageThread) hs(idleThrottleMs);
            }
        });
        messageHooks.push(hook);
    }
    for (const name of ['TranslateMessage','DispatchMessageA']) {
        const api = messageApis[name];
        const hook = Interceptor.attach(hu.getExportByName(name), {
            onEnter(args) {
                this.msg=args[0]; this.wallStart=realTick();
                this.ownedMessage = ownedMessageWindow(this.msg.readPointer());
                if (this.ownedMessage) recordMessageEnter(api,this.threadId,this.msg,0,0,0,0);
            },
            onLeave(retval) {
                if (!this.ownedMessage) return;
                try { recordMessage(api,this.threadId,retval.toUInt32(),this.msg,0,0,0,0,
                    (realTick()-this.wallStart)>>>0); }
                catch (error) { humanStop('Message trace failed: '+error); }
            }
        });
        messageHooks.push(hook);
    }
    const messageTraceStop = humanStop;
    let messageIdleStackSent=false;
    messageHooks.push(Interceptor.attach(target('idle'), {onEnter() {
        if (!messageIdleStackSent && messageThread && this.threadId===messageThread) {
            messageIdleStackSent=true;
            send({kind:'message-idle-backtrace',frames:Thread.backtrace(this.context,Backtracer.ACCURATE)
                .map(address=>address.toString())});
        }
    }}));
    humanStop = function(error) {
        flushMessageTrace();
        send({kind:'message-pump-summary',records:messageRecords,record_size:MESSAGE_RECORD_SIZE,
            clock_calls:messageClockCalls,thread:messageThread,windows:messageWindows.size+2});
        messageTraceStop(error);
    };
}
