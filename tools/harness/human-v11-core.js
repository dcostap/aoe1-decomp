// Original-only human input recording. Polling uses message-driven state in both modes.
const hu = Process.getModuleByName('user32.dll');
function ha(module, name, result, args) {
    return new NativeFunction(module.getExportByName(name), result, args, 'stdcall');
}
const hs = ha(Process.getModuleByName('kernel32.dll'), 'Sleep', 'void', ['uint']);
const realTick = ha(Process.getModuleByName('kernel32.dll'), 'GetTickCount', 'uint', []);
let realStart = null;
function humanAdvance(amount) {
    ticks += amount;
    if (realStart === null) realStart = realTick();
    const ahead = ticks - 1000 - ((realTick() - realStart) >>> 0);
    if (ahead > 0 && ahead < 1000) hs(ahead);
    return ticks >>> 0;
}
function humanClock() { return humanAdvance(1); }
const human = {turn:0, updates:0, input:0, posted:0, stopped:false, stopRequested:false, lastFrame:-50, dropped:0};
let world = null;
const isReplay = cfg.human.mode === 'replay';
const events = cfg.human.events || [];
const hkeys = new Set();
let hx = 320, hy = 240;
const waiting = [];
let humanInputDrained = null;
const hp = Memory.alloc(8), hkb = Memory.alloc(256);
const cts = ha(hu, 'ClientToScreen', 'int', ['pointer','pointer']);
const stc = ha(hu, 'ScreenToClient', 'int', ['pointer','pointer']);
const parentOf = ha(hu, 'GetParent', 'pointer', ['pointer']);
const windowAt = ha(hu, 'GetWindow', 'pointer', ['pointer','uint']);
const controlId = ha(hu, 'GetDlgCtrlID', 'int', ['pointer']);
const classOf = ha(hu, 'GetClassNameA', 'int', ['pointer','pointer','int']);
const setKeys = ha(hu, 'SetKeyboardState', 'int', ['pointer']);
const invalidate = ha(hu, 'InvalidateRect', 'int', ['pointer','pointer','int']);
const isVisible = ha(hu, 'IsWindowVisible', 'int', ['pointer']);
let pumping = false;
function pumpReplay() {
    if (!isReplay || pumping || human.stopped || waiting.length) return;
    if (human.posted >= events.length || human.turn < events[human.posted].turn) return;
    pumping = true;
    try {
        const event = events[human.posted], pending = {hwnd:resolveRoute(event.route), event};
        waiting.push(pending);
        if (!post(pending.hwnd,event.message,event.value,event.parameter)) {
            waiting.pop();
            throw new Error('Cannot post recorded input');
        }
        human.posted++;
    } finally { pumping = false; }
}
function windowClass(hwnd) {
    const text = Memory.alloc(256);
    if (!classOf(hwnd, text, 256)) throw new Error('Cannot identify input window');
    return text.readCString();
}
function childIdentity(hwnd) {
    return {id:controlId(hwnd), cls:windowClass(hwnd), vis:isVisible(hwnd) ? 1 : 0};
}
function route(hwnd) {
    const result = [];
    while (!hwnd.equals(gameWindow)) {
        if (hwnd.isNull() || result.length >= 8) throw new Error('Input window is not an owned game child');
        const parent = parentOf(hwnd), want = childIdentity(hwnd);
        let found = false, matches = 0, siblings = 0;
        for (let child = windowAt(parent, 5), n = 0; !child.isNull() && n < 512; child = windowAt(child, 2), n++) {
            const other = childIdentity(child);
            if (child.equals(hwnd)) found = true;
            if (other.id === want.id && other.cls === want.cls) {
                siblings++;
                if (other.vis === want.vis) matches++;
            }
        }
        // The editor keeps hidden edit panels beside the visible one, so one class and
        // one control id repeat. Visibility separates them. Input reaches only the visible one.
        if (!found || matches !== 1)
            throw new Error('Child input route is ' + (found ? 'ambiguous' : 'missing') +
                ': id ' + want.id + ', class ' + want.cls + ', visible ' + want.vis +
                ', ' + matches + ' of ' + siblings + ' matching siblings');
        result.unshift(want); hwnd = parent;
    }
    return result;
}
function resolveRoute(path) {
    let hwnd = gameWindow;
    for (const part of path) {
        let match = NULL, matches = 0;
        for (let child = windowAt(hwnd, 5), n = 0; !child.isNull() && n < 512; child = windowAt(child, 2), n++) {
            const other = childIdentity(child);
            if (other.id === part.id && other.cls === part.cls && other.vis === part.vis) { match = child; matches++; }
        }
        if (match.isNull() || matches !== 1) throw new Error('Recorded input window is missing or ambiguous');
        hwnd = match;
    }
    return hwnd;
}
function syncInput(hwnd, message, value, parameter) {
    if ([0x100,0x104].includes(message)) hkeys.add(value);
    if ([0x101,0x105].includes(message)) hkeys.delete(value);
    const buttons = {513:[1,true],514:[1,false],515:[1,true],516:[2,true],517:[2,false],518:[2,true],519:[4,true],520:[4,false],521:[4,true]};
    if (buttons[message]) {
        const [key, down] = buttons[message]; if (down) hkeys.add(key); else hkeys.delete(key);
    }
    if (message >= 0x200 && message <= 0x20a) {
        hp.writeS32((parameter << 16) >> 16); hp.add(4).writeS32(parameter >> 16);
        if ((message !== 0x20a && !cts(hwnd, hp)) || !stc(gameWindow, hp))
            throw new Error('Cannot map received cursor coordinates');
        hx = hp.readS32(); hy = hp.add(4).readS32();
    }
    hkb.writeByteArray(new Uint8Array(256));
    for (const key of hkeys) if (key >= 0 && key < 256) hkb.add(key).writeU8(128);
    if (!setKeys(hkb)) throw new Error('Cannot set owned input queue state');
}
const callbacks = [];
function bindHumanInput() {
    for (const name of ['GetKeyState','GetAsyncKeyState','GetCursorPos']) {
        const callback = name === 'GetCursorPos' ? new NativeCallback(point => {
            point.writeS32(hx); point.add(4).writeS32(hy);
            // cnc-ddraw 7.1.0.0 virtualizes game-window coordinates. Do not add its desktop offset.
            return 1;
        }, 'int', ['pointer'], 'stdcall') : new NativeCallback(key => hkeys.has(key) ? -32768 : 0, 'int16', ['int'], 'stdcall');
        const slot = base.add(cfg.inputIAT[name]), protection = Process.findRangeByAddress(slot).protection;
        if (!Memory.protect(slot, 4, 'rw-')) throw new Error('Cannot bind input import');
        slot.writePointer(callback);
        if (!Memory.protect(slot, 4, protection)) throw new Error('Cannot protect input import');
        callbacks.push(callback);
    }
}
// The recording already includes WM_CHAR. Do not generate a second copy on replay.
if (isReplay) {
    const translate = new NativeCallback(() => 0, 'int', ['pointer'], 'stdcall');
    callbacks.push(translate);
    Interceptor.replace(hu.getExportByName('TranslateMessage'), translate);
}
let bound = false;
function humanStop(error) {
    if (human.stopped) return;
    human.stopped = true;
    send({kind:'human-done', error:error || null, status:rpc.exports.status()});
    hs(0xffffffff);
}
// Saves come from the hash-checked repository fixture set in this profile.
// The profile selects its startup blocks. Editor recordings pass an empty list.
for (const name of (cfg.blockedStartups || ['forbidScenario','forbidEditor'])) {
    Interceptor.attach(target(name), {onEnter() { humanStop('Unsupported startup: ' + name); }});
}
Interceptor.attach(target('wndproc'), {onEnter(args) {
    if (!isReplay && gameWindow && args[0].equals(gameWindow) && args[1].toUInt32() === 0x10) {
        human.stopRequested = true;
        human.stop_reason = 'window-close';
        args[1] = ptr(0); // Finish at Paint before normal window destruction can end the recording.
        if (!invalidate(gameWindow,NULL,0)) humanStop('Cannot request the closing game frame');
        return;
    }
    // Activation changes can be sent directly, without DispatchMessage.
    if (!isReplay && args[1].toUInt32() === 0x1c && args[2].toUInt32() === 0 && human.input > 0)
        humanStop('Focus left the recorded game; use F10 before switching windows');
}});
Interceptor.attach(target('probe_human_world'), {
    onEnter() { this.world = this.context.ecx; },
    onLeave() { human.updates++; world = {time:this.world.add(4).readU32(), objects:this.world.add(140).readS32()}; }
});
let lastCamera = null;
Interceptor.attach(target('probe_human_camera'), {
    onEnter() { this.player = this.context.ecx; },
    onLeave() {
        const camera = {player:this.player.add(74).readS16(), x:this.player.add(276).readFloat(), y:this.player.add(280).readFloat()};
        if (JSON.stringify(camera) !== JSON.stringify(lastCamera)) {
            lastCamera = camera;
            send({kind:'human-camera', time_ms:ticks-1000, updates:human.updates, cursor:[hx,hy], camera});
        }
    }
});
const activeDispatch = new Set();
for (const name of ['DispatchMessageA','DispatchMessageW']) {
    Interceptor.attach(hu.getExportByName(name), {
        onEnter(args) {
            this.delivered = null;
            this.dispatchKey = this.threadId + ':' + args[0].toString();
            this.outer = !activeDispatch.has(this.dispatchKey);
            if (!this.outer) return;
            activeDispatch.add(this.dispatchKey);
            if (!gameWindow || human.stopped) return;
            try {
                const msg = args[0], hwnd = msg.readPointer(), message = msg.add(4).readU32();
                const value = msg.add(8).readU32(), parameter = msg.add(12).readU32();
                if (!isReplay && message === 0x1c && value === 0 && human.input > 0)
                    throw new Error('Focus left the recorded game; use F10 before switching windows');
                if (!isReplay && [0x100,0x104].includes(message) && value === 0x79) {
                    human.stopRequested = true; human.stop_reason = 'F10'; msg.add(4).writeU32(0); return; // F10 belongs to the recorder.
                }
                if (!((message >= 0x100 && message <= 0x107) || (message >= 0x200 && message <= 0x20e))) return;
                if (![0x100,0x101,0x102,0x103,0x104,0x105,0x106,0x107,0x200,0x201,0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a].includes(message))
                    throw new Error('Unsupported input message: ' + message);
                const expected = waiting[0];
                if (isReplay && (!expected || expected.dispatching || !hwnd.equals(expected.hwnd) || message !== expected.event.message || value !== expected.event.value || parameter !== expected.event.parameter)) {
                    msg.add(4).writeU32(0); human.dropped++; return;
                }
                if (isReplay) expected.dispatching = true;
                const row = {kind:'human-input', index:human.input, time_ms:ticks-1000,
                    turn:human.turn, updates:human.updates, panel:currentPanelName(), route:route(hwnd), message, value, parameter};
                if (isReplay) row.expected_time_ms = expected.event.time_ms;
                syncInput(hwnd, message, value, parameter);
                send(row); human.input++; if (isReplay) this.delivered = expected;
                if (human.input > 100000) throw new Error('Input recording limit reached');
            } catch (error) { humanStop(String(error)); }
        },
        onLeave() {
            if (!this.outer) return;
            activeDispatch.delete(this.dispatchKey);
            if (!isReplay || !this.delivered || human.stopped) return;
            try {
                if (waiting[0] !== this.delivered) throw new Error('Recorded input dispatch identity changed');
                waiting.shift();
                pumpReplay();
                if (humanInputDrained) humanInputDrained();
            } catch (error) { humanStop(String(error)); }
        }
    });
}
function humanFrameDue() {
    return !human.stopped && (human.stopRequested || ticks-1000 >= cfg.human.duration_ms || ticks-1000-human.lastFrame >= 50);
}
function humanAfterFrame() {
    human.lastFrame = ticks-1000;
    if (human.stopRequested || ticks-1000 >= cfg.human.duration_ms)
        humanStop(isReplay && (waiting.length || human.input !== events.length) ? 'Recording ended before all inputs arrived' : null);
}
let smokeIndex = 0, smokeAt = 500;
const smoke = cfg.human.cursor_check ? [['Main Menu',320,198,'click'],['Single Player Menu',320,138,'click'],
    ['MP Setup Screen',170,455,'click'],['Game Screen',320,200,'move']] :
    [['Main Menu',320,198,'click'],['Single Player Menu',320,138,'click'],
    ['MP Setup Screen',170,455,'click'],['Game Screen',638,240,'move'],['Game Screen',320,240,'move'],
    ['Game Screen',0,0,'key'],['Game Screen',150,180,'down'],['Game Screen',220,230,'drag'],
    ['Game Screen',280,280,'up'],['Game Screen',350,200,'right'],['Game Screen',0,0,'stop']];
Interceptor.attach(target('idle'), {onLeave() {
    if (!gameWindow || human.stopped || this.threadId !== gameThread) return;
    try {
        human.turn++;
        if (this.returnAddress.compare(run) >= 0 && this.returnAddress.compare(run.add(0xd0)) < 0) {
            humanAdvance(20);
        }
        if (!bound) { bindHumanInput(); bound = true; }
        if (human.stopRequested || ticks-1000 >= cfg.human.duration_ms) {
            if (!invalidate(gameWindow,NULL,0)) throw new Error('Cannot request terminal game frame');
        }
        if (cfg.human.cursor_check && !human.stopRequested && ticks-1000 >= cfg.human.duration_ms-500)
            if (!post(gameWindow,0x10,0,0)) throw new Error('Cannot test the normal close button');
        pumpReplay();
        if (cfg.human.smoke && smokeIndex < smoke.length && ticks-1000 >= smokeAt && currentPanelName() === smoke[smokeIndex][0]) {
            const [panel,x,y,action] = smoke[smokeIndex], xy = (y << 16) | x;
            const queue = (message,value,param) => { if (!post(gameWindow,message,value,param)) throw new Error('Smoke input failed'); };
            if (action === 'key') { queue(0x100,72,1); queue(0x101,72,0xc0000001); }
            else if (action === 'stop') queue(0x100,0x79,1);
            else {
                queue(0x200,action === 'drag' || action === 'up' ? 1 : 0,xy);
                if (action === 'click' || action === 'down') queue(0x201,1,xy);
                if (action === 'click' || action === 'up') queue(0x202,0,xy);
                if (action === 'right') { queue(0x204,2,xy); queue(0x205,0,xy); }
            }
            smokeIndex++; smokeAt = ticks-1000 + 700;
        }
    } catch (error) { humanStop(String(error)); }
}});
const previousHumanStatus = rpc.exports.status;
rpc.exports.status = () => Object.assign(previousHumanStatus(), {human:{...human, time_ms:ticks-1000,
    world, camera:lastCamera, cursor:[hx,hy]}});
// Composite visible owned native controls through WM_PRINTCLIENT into memory DCs only.
const hg = Process.getModuleByName('gdi32.dll');
const hrect = ha(hu,'GetClientRect','int',['pointer','pointer']);
const hsend = ha(hu,'SendMessageA','int',['pointer','uint','pointer','pointer']);
const hdc = ha(hg,'CreateCompatibleDC','pointer',['pointer']);
const hdelDC = ha(hg,'DeleteDC','int',['pointer']);
const hdib = ha(hg,'CreateDIBSection','pointer',['pointer','pointer','uint','pointer','pointer','uint']);
const hselect = ha(hg,'SelectObject','pointer',['pointer','pointer']);
const hdelete = ha(hg,'DeleteObject','int',['pointer']);
const hflush = ha(hg,'GdiFlush','int',[]);
function humanNativeFrames() {
    function children(parent, depth) {
        if (depth > 8) throw new Error('Native control depth limit');
        for (let hwnd = windowAt(parent,5), n = 0; !hwnd.isNull(); hwnd = windowAt(hwnd,2)) {
            if (++n > 512) throw new Error('Native control count limit');
            if (!isVisible(hwnd)) continue;
            const rect = Memory.alloc(16), point = Memory.alloc(8);
            if (!hrect(hwnd,rect) || !cts(hwnd,point) || !stc(gameWindow,point)) throw new Error('Cannot measure native child');
            const w = rect.add(8).readS32(), h = rect.add(12).readS32();
            if (w < 1 || h < 1 || w > 4096 || h > 4096) throw new Error('Invalid native child dimensions');
            const info = Memory.alloc(40), bits = Memory.alloc(4);
            info.writeU32(40); info.add(4).writeS32(w); info.add(8).writeS32(-h);
            info.add(12).writeU16(1); info.add(14).writeU16(32);
            const dc = hdc(NULL); let bitmap = NULL, old = NULL;
            if (dc.isNull()) throw new Error('Cannot create native capture DC');
            try {
                bitmap = hdib(dc,info,0,bits,NULL,0);
                if (bitmap.isNull()) throw new Error('Cannot create native capture bitmap');
                old = hselect(dc,bitmap);
                if (old.isNull() || old.equals(ptr('0xffffffff'))) throw new Error('Cannot select native capture bitmap');
                hsend(hwnd,0x318,dc,ptr(12)); hflush();
                send({kind:'human-native-frame', rect:[point.readS32(),point.add(4).readS32(),w,h]}, bits.readPointer().readByteArray(w*h*4));
            } finally {
                if (!old.isNull() && !old.equals(ptr('0xffffffff'))) hselect(dc,old);
                if (!bitmap.isNull()) hdelete(bitmap);
                hdelDC(dc);
            }
            children(hwnd,depth+1);
        }
    }
    children(gameWindow,0);
}
