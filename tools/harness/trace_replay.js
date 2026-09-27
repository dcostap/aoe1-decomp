// Fast native replay of a deterministic-trace human recording.
// Runs inside the 32-bit game. Hot paths live in trace_replay.c (cfg.traceNative).
// Game-visible behavior matches the V8 replay core with human_message_replay.js,
// human_clock_replay.js, and human_alloc_fill.js: recorded clocks and pump
// results, no-op TranslateMessage, recorded input state for GetKeyState,
// GetAsyncKeyState, and GetCursorPos, zero-filled operator new, and the same
// registry, mutex, and network isolation. Replay never waits for wall time and
// captures only the terminal frame.
'use strict';
const cfg = __CONFIG__;
if (Process.arch !== 'ia32') throw new Error('Expected an IA-32 game');
const base = Process.mainModule.base;
const human = cfg.human;
const meta = human.message_recording;
if (!meta || meta.format !== 'aoe-message-pump-v7-le' || meta.record_size !== 80 ||
        !human.replay_clock_trace || !human.alloc_fill)
    throw new Error('Fast replay needs a v7 message trace, a clock trace, and zero-filled allocations');
const gameRegistryKey = 'software\\microsoft\\games\\age of empires\\1.00';
let registryRedirects = 0, mutexRedirects = 0;
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('CreateMutexA'), {
    onEnter(args) {
        if (args[2].isNull() || args[2].readCString() !== 'Age of Empires, Roman Expansion') return;
        this.name = Memory.allocUtf8String('AoE1Harness-' + cfg.registryBase.split('\\').pop());
        args[2] = this.name;
        mutexRedirects++;
    }
});
Interceptor.attach(Process.getModuleByName('advapi32.dll').getExportByName('RegCreateKeyExA'), {
    onEnter(args) {
        if (args[1].isNull() || args[1].readCString().toLowerCase() !== gameRegistryKey) return;
        const hive = args[0].toUInt32();
        if (hive !== 0x80000001 && hive !== 0x80000002) throw new Error('Unexpected game registry hive');
        this.path = Memory.allocUtf8String(cfg.registryBase + (hive === 0x80000001 ? '\\user' : '\\machine'));
        args[0] = ptr('0x80000001');
        args[1] = this.path;
        registryRedirects++;
    }
});
const verifiedTargets = new Map();
function target(name) {
    if (verifiedTargets.has(name)) return verifiedTargets.get(name);
    const hook = cfg[name];
    const address = base.add(hook.rva);
    const actual = Array.from(new Uint8Array(address.readByteArray(hook.bytes.length)));
    if (JSON.stringify(actual) !== JSON.stringify(hook.bytes))
        throw new Error(name + ' entry bytes differ from the selected image');
    verifiedTargets.set(name, address);
    return address;
}
const raised = new Map();
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('RaiseException'), {
    onEnter(args) {
        raised.set(this.threadId, {code: args[0].toUInt32(), caller: this.returnAddress.toString()});
    }
});
Process.setExceptionHandler(details => {
    const thread = Process.getCurrentThreadId();
    const software = raised.get(thread);
    raised.delete(thread);
    const origin = software ? Process.findModuleByAddress(ptr(software.caller)) : null;
    send({kind: 'exception', type: details.type, address: details.address,
        code: software ? software.code : null, caller: software ? software.caller : null,
        callerModule: origin ? origin.name : null, memory: details.memory, context: details.context});
    return false;
});
function currentPanelName() {
    const value = base.add(cfg.panelSystem.rva).add(12).readPointer();
    if (value.isNull()) return null;
    const name = value.add(28).readPointer();
    return name.isNull() ? null : name.readCString();
}
const hu = Process.getModuleByName('user32.dll');
const k32 = Process.getModuleByName('kernel32.dll');
function api(module, name, result, args) {
    return new NativeFunction(module.getExportByName(name), result, args, 'stdcall');
}
const hs = api(k32, 'Sleep', 'void', ['uint']);
const cts = api(hu, 'ClientToScreen', 'int', ['pointer','pointer']);
const stc = api(hu, 'ScreenToClient', 'int', ['pointer','pointer']);
const parentOf = api(hu, 'GetParent', 'pointer', ['pointer']);
const windowAt = api(hu, 'GetWindow', 'pointer', ['pointer','uint']);
const controlId = api(hu, 'GetDlgCtrlID', 'int', ['pointer']);
const classOf = api(hu, 'GetClassNameA', 'int', ['pointer','pointer','int']);
const setKeys = api(hu, 'SetKeyboardState', 'int', ['pointer']);
const ddraw = Process.getModuleByName('ddraw.dll');
const getAddress = ddraw.base.add(0x22a40), peekAddress = ddraw.base.add(0x22aa0);

const events = human.events;
const waiting = [], delivered = [];
const hkeys = new Set();
const hp = Memory.alloc(8), hkb = Memory.alloc(256);
let gameWindow = null, count = 0, posted = 0, dropped = 0, stopped = false, stopReason = null;
let rngSent = 0, observedEvents = 0, inputRows = [];
const siteIds = new Map();
const callbacks = [];
function callback(fn, result, args) {
    const value = new NativeCallback(fn, result, args, 'mscdecl');
    callbacks.push(value);
    return value;
}
const FAILURES = {1:'API differs', 2:'update count differs', 3:'input count differs', 4:'poll entry parameters differ',
    5:'message entry differs', 6:'dispatch MSG differs', 7:'Replay used more global clock calls than recorded',
    8:'poll filter differs', 10:'trace is exhausted'};
// Index order matches the S[] macros in trace_replay.c.
const STATE = Object.fromEntries('ready trace_thread game_thread stopped stop_requested stop_trace_complete game_window trace trace_records trace_index clock_runs clock_run_count clock_run clock_run_used clock_calls ticks updates input turn bound duration_ms fail_code fail_index cursor_x cursor_y observe rng_buf rng_cap rng_used rng_total upd_buf upd_cap upd_used world_time world_objects camera_player camera_seen camera_changes camera_x camera_y alloc_blocks alloc_bytes_lo alloc_bytes_hi native_peek native_get active_count dump_at clock_log clock_log_cap clock_log_used clock_log_first clock_log_last'.split(' ').map((name, index) => [name, index]));
const stateMemory = Memory.alloc(64 * 4), keysMemory = Memory.alloc(256);
const sitesMemory = Memory.alloc(4096 * 16), activeMemory = Memory.alloc(64 * 8);
for (const [block, size] of [[stateMemory, 256], [keysMemory, 256], [sitesMemory, 4096 * 16], [activeMemory, 64 * 8]])
    block.writeByteArray(new Uint8Array(size));
function slot(name) { return stateMemory.add(STATE[name] * 4); }
function u32(name) { return slot(name).readU32(); }
function allocBytes() { return u32('alloc_bytes_lo') + u32('alloc_bytes_hi') * 4294967296; }
slot('ticks').writeU32(1000);
slot('cursor_x').writeS32(320);
slot('cursor_y').writeS32(240);
const cm = new CModule(cfg.traceNative, {
    S: stateMemory, KEYS: keysMemory, SITES: sitesMemory, ACTIVE: activeMemory,
    user_invalidate: hu.getExportByName('InvalidateRect'),
    current_thread: k32.getExportByName('GetCurrentThreadId'),
    js_fail: callback(code => {
        const index = u32('fail_index');
        humanStop(code === 7 ? FAILURES[7] : 'Message replay mismatch at record ' + index + ': ' +
            (FAILURES[code] || 'code ' + code));
    }, 'void', ['uint']),
    js_window: callback(id => windowFor(id), 'pointer', ['uint']),
    js_owned: callback(hwnd => { try { route(hwnd); return 1; } catch (_) { return 0; } }, 'int', ['pointer']),
    js_site: callback((kind, file, line) => site(kind, file, line), 'uint', ['uint','pointer','int']),
    js_flush: callback(() => flush(), 'void', []),
    js_bind: callback(() => guard(bindHumanInput), 'void', []),
    js_removed: callback((message, value, parameter, hwnd) => {
        const event = events[posted];
        if (!event || event.message !== message || event.value !== value || event.parameter !== parameter)
            fail('recorded input differs from message stream');
        else { waiting.push({hwnd, event}); posted++; }
    }, 'void', ['uint','uint','uint','pointer']),
    js_dispatch_input: callback(msg => {
        try { return dispatchInput(msg); } catch (error) { humanStop(String(error)); return 0; }
    }, 'int', ['pointer']),
    js_dump_state: callback(world => guard(() => dumpState(world)), 'void', ['pointer']),
    js_dispatched: callback(() => guard(() => {
        const expected = delivered.pop();
        if (waiting[0] !== expected) throw new Error('Recorded input dispatch identity changed');
        waiting.shift();
    }), 'void', []),
});
function guard(fn) { try { fn(); } catch (error) { humanStop(String(error)); } }
function fail(text) { humanStop('Message replay mismatch at record ' + u32('trace_index') + ': ' + text); }
function windowClass(hwnd) {
    const text = Memory.alloc(256);
    if (!classOf(hwnd, text, 256)) throw new Error('Cannot identify input window');
    return text.readCString();
}
function route(hwnd) {
    const result = [];
    while (!hwnd.equals(gameWindow)) {
        if (hwnd.isNull() || result.length >= 8) throw new Error('Input window is not an owned game child');
        const parent = parentOf(hwnd), id = controlId(hwnd), cls = windowClass(hwnd);
        let matches = 0, found = false;
        for (let child = windowAt(parent, 5), n = 0; !child.isNull() && n < 512; child = windowAt(child, 2), n++) {
            if (child.equals(hwnd)) found = true;
            if (controlId(child) === id && windowClass(child) === cls) matches++;
        }
        if (!found || matches !== 1) throw new Error('Child input route is missing or ambiguous');
        result.unshift({id, cls, index:0}); hwnd = parent;
    }
    return result;
}
function resolveRoute(path) {
    let hwnd = gameWindow;
    for (const part of path) {
        let match = NULL, matches = 0;
        for (let child = windowAt(hwnd, 5), n = 0; !child.isNull() && n < 512; child = windowAt(child, 2), n++) {
            if (controlId(child) === part.id && windowClass(child) === part.cls) { match = child; matches++; }
        }
        if (match.isNull() || matches !== 1) throw new Error('Recorded input window is missing or ambiguous');
        hwnd = match;
    }
    return hwnd;
}
function windowFor(id) {
    const role = meta.windows[String(id)];
    if (!role) { fail('unknown window role ' + id); return gameWindow; }
    if (role.role === 'thread') return NULL;
    if (role.role === 'main') return gameWindow;
    if (role.role === 'owned') {
        try { return resolveRoute(role.route); } catch (error) { fail(String(error)); return gameWindow; }
    }
    fail('record contains an external-window message');
    return gameWindow;
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
        // As in the v10 editor profile: mouse-wheel coordinates are already screen coordinates.
        if ((message !== 0x20a && !cts(hwnd, hp)) || !stc(gameWindow, hp))
            throw new Error('Cannot map received cursor coordinates');
        slot('cursor_x').writeS32(hp.readS32()); slot('cursor_y').writeS32(hp.add(4).readS32());
    }
    hkb.writeByteArray(new Uint8Array(256));
    keysMemory.writeByteArray(new Uint8Array(256));
    for (const key of hkeys) if (key >= 0 && key < 256) { hkb.add(key).writeU8(128); keysMemory.add(key).writeU8(1); }
    if (!setKeys(hkb)) throw new Error('Cannot set owned input queue state');
}
const SUPPORTED = new Set([0x100,0x101,0x102,0x103,0x104,0x105,0x106,0x107,
    0x200,0x201,0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a]);
function dispatchInput(msg) {
    const hwnd = msg.readPointer(), message = msg.add(4).readU32();
    const value = msg.add(8).readU32(), parameter = msg.add(12).readU32();
    if (!SUPPORTED.has(message)) throw new Error('Unsupported input message: ' + message);
    const expected = waiting[0];
    if (!expected || expected.dispatching || !hwnd.equals(expected.hwnd) || message !== expected.event.message ||
            value !== expected.event.value || parameter !== expected.event.parameter) {
        msg.add(4).writeU32(0); dropped++; return 0;
    }
    expected.dispatching = true;
    const input = u32('input');
    inputRows.push({kind:'human-input', index:input, time_ms:u32('ticks')-1000, turn:u32('turn'),
        updates:u32('updates'), panel:currentPanelName(), route:route(hwnd), message, value, parameter,
        expected_time_ms:expected.event.time_ms});
    if (inputRows.length >= 512) sendInputs();
    syncInput(hwnd, message, value, parameter);
    slot('input').writeU32(input + 1);
    delivered.push(expected);
    return 1;
}
function sendInputs() {
    if (inputRows.length) send({kind:'human-input-batch', rows:inputRows});
    inputRows = [];
}
function site(kind, file, line) {
    flush();
    const raw = file.readCString();
    const normalized = {kind: kind ? 'rand' : 'srand', file: raw.replace(/\//g,'\\').toLowerCase(), line};
    const key = JSON.stringify(normalized);
    if (!siteIds.has(key)) {
        const id = siteIds.size;
        siteIds.set(key, id);
        send({kind:'replay-rng-site', id, site:normalized, raw_file:raw});
    }
    return siteIds.get(key);
}
function flush() {
    const used = u32('rng_used');
    if (used) {
        send({kind:'replay-rng-batch', records:used}, slot('rng_buf').readPointer().readByteArray(used * 8));
        rngSent += used;
        slot('rng_used').writeU32(0);
    }
    const updates = u32('upd_used');
    if (updates) {
        const rows = new Uint32Array(slot('upd_buf').readPointer().readByteArray(updates * 20));
        let batch = [];
        for (let i = 0; i < updates; i++) {
            batch.push({kind:'observer-update', sequence:++observedEvents, rng_count:rows[i*5],
                updates:rows[i*5+1], input:rows[i*5+2], world_time:rows[i*5+3], state_hash:rows[i*5+4]});
            if (batch.length === 128) { send({kind:'observer-events', events:batch}); batch = []; }
        }
        if (batch.length) send({kind:'observer-events', events:batch});
        slot('upd_used').writeU32(0);
    }
}
// Diagnostic object-state dump at one completed update; read-only.
function dumpState(world) {
    const table = world.add(136).readPointer(), count = world.add(144).readS32();
    let rows = [];
    for (let i = 0; i < count; i++) {
        const object = table.add(i * 4).readPointer();
        if (object.isNull()) continue;
        const master = object.add(8).readPointer(), owner = object.add(12).readPointer();
        rows.push([object.add(4).readS32(), master.isNull() ? null : master.add(16).readS16(),
            owner.isNull() ? null : owner.add(74).readS16(), object.add(48).readFloat(), object.add(56).readFloat(),
            object.add(60).readFloat(), object.add(64).readFloat(), object.add(72).readU8()]);
        if (rows.length === 1024) { send({kind:'state-dump', updates:u32('updates'), rows}); rows = []; }
    }
    send({kind:'state-dump', updates:u32('updates'), rows, last:true});
}
function bindHumanInput() {
    for (const name of ['GetKeyState','GetAsyncKeyState','GetCursorPos']) {
        const slot = base.add(cfg.inputIAT[name]), protection = Process.findRangeByAddress(slot).protection;
        if (!Memory.protect(slot, 4, 'rw-')) throw new Error('Cannot bind input import');
        slot.writePointer(name === 'GetCursorPos' ? native('cursor_pos') : native('key_state'));
        if (!Memory.protect(slot, 4, protection)) throw new Error('Cannot protect input import');
    }
}
const processTimes = new NativeFunction(k32.getExportByName('GetProcessTimes'), 'int',
    ['pointer','pointer','pointer','pointer','pointer'], 'stdcall');
const currentProcess = new NativeFunction(k32.getExportByName('GetCurrentProcess'), 'pointer', [], 'stdcall');
function cpuMilliseconds() {
    const times = Memory.alloc(32);
    if (!processTimes(currentProcess(), times, times.add(8), times.add(16), times.add(24))) return null;
    return {kernel: times.add(16).readU64().toNumber() / 10000, user: times.add(24).readU64().toNumber() / 10000};
}
const openThread = new NativeFunction(k32.getExportByName('OpenThread'), 'pointer', ['uint','int','uint'], 'stdcall');
const threadTimes = new NativeFunction(k32.getExportByName('GetThreadTimes'), 'int',
    ['pointer','pointer','pointer','pointer','pointer'], 'stdcall');
const closeHandle = new NativeFunction(k32.getExportByName('CloseHandle'), 'int', ['pointer'], 'stdcall');
function threadCpu() {
    const rows = [], times = Memory.alloc(32);
    for (const thread of Process.enumerateThreads()) {
        const handle = openThread(0x0800, 0, thread.id); // THREAD_QUERY_LIMITED_INFORMATION
        if (handle.isNull()) continue;
        try {
            if (threadTimes(handle, times, times.add(8), times.add(16), times.add(24)))
                rows.push({id:thread.id, game:thread.id === u32('game_thread'),
                    kernel:times.add(16).readU64().toNumber() / 10000, user:times.add(24).readU64().toNumber() / 10000});
        } finally { closeHandle(handle); }
    }
    return rows.filter(row => row.kernel + row.user >= 50);
}
function status() {
    const camera = slot('camera_seen').readS32() ? {player:slot('camera_player').readS32(),
        x:slot('camera_x').readFloat(), y:slot('camera_y').readFloat()} : null;
    const updates = u32('updates');
    return {count, failures:0, posted, ticks:u32('ticks'), rngCount:u32('rng_total'), rngTrace:[],
        panel:currentPanelName(), registryRedirects, mutexRedirects,
        modules: Process.enumerateModules().map(m => ({name:m.name, path:m.path, base:m.base, size:m.size})),
        human:{turn:u32('turn'), updates, input:u32('input'), posted, stopped, stopRequested:!!u32('stop_requested'),
            stop_reason:stopReason, dropped, time_ms:u32('ticks')-1000,
            world:updates ? {time:u32('world_time'), objects:slot('world_objects').readS32()} : null,
            camera, camera_changes:slot('camera_changes').readS32()},
        message_replay:{records:u32('trace_index'), total:meta.records, loaded:traceLoaded, ready:!!u32('ready')},
        clock_replay:{calls:u32('clock_calls'), runs:u32('clock_run'), run_calls:u32('clock_run_used'),
            complete:u32('clock_run') === clockRuns.length && u32('clock_run_used') === 0},
        alloc_fill:{blocks:u32('alloc_blocks'), bytes:allocBytes()}, process_cpu_ms:cpuMilliseconds(), thread_cpu_ms:threadCpu()};
}
function humanStop(error) {
    if (stopped) return;
    stopped = true;
    slot('stopped').writeU32(1);
    if (!stopReason && u32('stop_trace_complete')) stopReason = 'message-trace-complete';
    sendInputs();
    sendProbeRows();
    sendClockLog();
    if (human.observe) {
        flush();
        send({kind:'observer-summary', records:rngSent, events:observedEvents, error:error || null});
    }
    send({kind:'alloc-fill-status', blocks:u32('alloc_blocks'), bytes:allocBytes()});
    send({kind:'human-done', error:error || null, status:status()});
    hs(0xffffffff);
}

// Load the recorded streams into native memory.
const clockRuns = human.replay_clock_trace;
const clockBuffer = Memory.alloc(clockRuns.length * 8);
{
    const values = new Uint32Array(clockRuns.length * 2);
    clockRuns.forEach((run, i) => { values[i*2] = run[0] >>> 0; values[i*2+1] = run[1] >>> 0; });
    clockBuffer.writeByteArray(values.buffer);
}
slot('clock_runs').writePointer(clockBuffer);
slot('clock_run_count').writeU32(clockRuns.length);
slot('duration_ms').writeS32(human.duration_ms);
const traceBytes = meta.records * 80;
const traceBuffer = Memory.alloc(traceBytes);
slot('trace').writePointer(traceBuffer);
slot('trace_records').writeU32(meta.records);
let traceLoaded = 0;
function receiveTrace() {
    recv('message-trace', function(packet, data) {
        traceBuffer.add(packet.offset >>> 0).writeByteArray(data);
        traceLoaded += data.byteLength;
        if (packet.done) {
            if (traceLoaded !== traceBytes) { send({kind:'capture-error', error:'Message trace byte count differs'}); return; }
            slot('ready').writeU32(1);
            send({kind:'trace-ready', records:meta.records});
        } else receiveTrace();
    });
}
receiveTrace();
// Native buffers must stay referenced at module scope; Frida frees collected allocations.
const rngCap = 1 << 18, updCap = 1 << 14;
const rngBuffer = human.observe ? Memory.alloc(rngCap * 8) : null;
const updBuffer = human.observe ? Memory.alloc(updCap * 20) : null;
if (human.state_dump) slot('dump_at').writeU32(human.state_dump);
const clockLogCap = 1 << 18;
const clockLogBuffer = human.clock_log ? Memory.alloc(clockLogCap * 12) : null;
if (human.clock_log) {
    slot('clock_log').writePointer(clockLogBuffer); slot('clock_log_first').writeU32(human.clock_log.first);
    slot('clock_log_last').writeU32(human.clock_log.last); slot('clock_log_cap').writeU32(clockLogCap);
}
function sendClockLog() {
    const used = human.clock_log ? u32('clock_log_used') : 0;
    if (!used) return;
    const words = new Uint32Array(clockLogBuffer.readByteArray(used * 12));
    const rows = [];
    for (let i = 0; i < used; i++) rows.push([words[i*3], words[i*3+1], words[i*3+2]]);
    for (let i = 0; i < rows.length; i += 8192) send({kind:'clock-log-batch', rows:rows.slice(i, i + 8192)});
}
if (human.observe) {
    slot('rng_buf').writePointer(rngBuffer); slot('rng_cap').writeU32(rngCap);
    slot('upd_buf').writePointer(updBuffer); slot('upd_cap').writeU32(updCap);
    slot('observe').writeU32(1);
}

// TinyCC decorates stdcall exports (name@bytes); accept either spelling.
function native(name) {
    if (cm[name]) return cm[name];
    const key = Object.keys(cm).find(k => k.replace(/^_/, '').split('@')[0] === name);
    if (!key) throw new Error('Native replay export is missing: ' + name + ' in ' + Object.keys(cm).join(','));
    return cm[key];
}
// Install hooks. Native code owns every per-call path.
Interceptor.replaceFast(target('clock'), native('replay_clock'));
Interceptor.attach(target('srand'), {onEnter: native('srand_enter')});
Interceptor.attach(target('rand'), {onEnter: native('rand_enter'), onLeave: native('rand_leave')});
Interceptor.attach(target('alloc_new'), {onEnter: native('new_enter'), onLeave: native('new_leave')});
Interceptor.attach(target('probe_human_world'), {onEnter: native('world_enter'), onLeave: native('world_leave')});
Interceptor.attach(target('probe_human_camera'), {onEnter: native('camera_enter'), onLeave: native('camera_leave')});
Interceptor.attach(target('wndproc'), {onEnter: native('wndproc_enter')});
Interceptor.attach(target('idle'), {onLeave: native('idle_leave')});
Interceptor.replaceFast(hu.getExportByName('TranslateMessage'), native('replay_translate'));
Interceptor.attach(hu.getExportByName('DispatchMessageA'), {onEnter: native('dispatch_enter'), onLeave: native('dispatch_leave')});
slot('native_get').writePointer(Interceptor.replaceFast(getAddress, native('replay_get')));
slot('native_peek').writePointer(Interceptor.replaceFast(peekAddress, native('replay_peek')));
// Optional read-only call probe for divergence diagnosis. It reads registers and
// the stack and changes no game state.
let probeRows = [];
function sendProbeRows() {
    if (probeRows.length) send({kind:'call-probe-batch', rows:probeRows});
    probeRows = [];
}
if (human.call_probe) {
    const probe = human.call_probe;
    probe.functions.forEach((fn, index) => Interceptor.attach(target('probe_call' + index), {onEnter(args) {
        const updates = u32('updates');
        this.probeRow = null;
        if (updates < probe.first || updates > probe.last) return;
        // FUZZY scans the stack: frame-pointer-free callers stay visible, stale addresses can appear.
        const stack = [this.returnAddress].concat(Thread.backtrace(this.context, Backtracer.FUZZY).slice(0, 14));
        // Words behind each argument that reads as a pointer; null when unreadable.
        const words = [0,1,2,3,4,5,6].map(i => {
            try { return Array.from(new Int32Array(args[i].readByteArray(32))); } catch (_) { return null; }
        });
        const first = words[0];
        let thisWords = null;
        try { thisWords = Array.from(new Int32Array(this.context.ecx.readByteArray(4096))); } catch (_) {}
        this.probeRow = {kind:'call-probe', function:fn.module + ':' + fn.va, updates, input:u32('input'), rng:u32('rng_total'),
            clock:u32('clock_calls'), this_words:thisWords,
            ecx:this.context.ecx.toString(), args:[0,1,2,3,4,5,6].map(i => args[i].toInt32()), arg0_words:first, arg_words:words,
            base:base.toString(), stack:stack.map(address => address.toString())};
        probeRows.push(this.probeRow);
    }, onLeave(result) {
        if (!this.probeRow) return;
        this.probeRow.result = result.toInt32();
        this.probeRow.rng_after = u32('rng_total');
        if (probeRows.length >= 256) sendProbeRows();
    }}));
}
// Scenarios and the editor are allowed: the recorded trace decides what the game does,
// and any divergence from it fails at the first differing clock read or poll.

// Paint owns the window identity and the terminal frame, as in menu.js.
const desc = Memory.alloc(108), palette = Memory.alloc(1024);
const methods = new Map();
function method(object, slot, types) {
    const address = object.readPointer().add(slot * 4).readPointer();
    const key = address.toString();
    if (!methods.has(key)) methods.set(key, new NativeFunction(address, 'int', types, 'stdcall'));
    return methods.get(key);
}
Interceptor.attach(target('paint'), {onEnter() {
    try {
        const system = this.context.ecx;
        gameWindow = system.add(4).readPointer();
        slot('game_window').writePointer(gameWindow);
        slot('game_thread').writeU32(this.threadId);
        count++;
        if (stopped || !(u32('stop_requested') || u32('ticks') - 1000 >= human.duration_ms)) return;
        const area = system.add(12).readPointer();
        if (area.isNull()) return;
        const surface = area.add(60).readPointer(), pal = system.add(36).readPointer();
        if (surface.isNull() || pal.isNull()) return;
        desc.writeU32(108);
        if (method(surface, 22, ['pointer','pointer'])(surface, desc) !== 0) throw new Error('GetSurfaceDesc failed');
        const height = desc.add(8).readU32(), width = desc.add(12).readU32(), pitch = desc.add(16).readS32();
        const pixels = desc.add(36).readPointer(), bits = desc.add(84).readU32();
        if (bits !== 8 || pixels.isNull() || width < 1 || height < 1 || width > 4096 || height > 4096 ||
                pitch < width || pitch > 8192) throw new Error('Unsupported surface description');
        if (method(pal, 4, ['pointer','uint','uint','uint','pointer'])(pal, 0, 0, 256, palette) !== 0)
            throw new Error('GetEntries failed');
        const data = new Uint8Array(pitch * height + 1024);
        data.set(new Uint8Array(pixels.readByteArray(pitch * height)));
        data.set(new Uint8Array(palette.readByteArray(1024)), pitch * height);
        send({kind:'frame', count, width, height, pitch, bits, panel:currentPanelName(), time_ms:u32('ticks') - 1000},
            data.buffer);
        humanStop(waiting.length || u32('input') !== events.length ? 'Recording ended before all inputs arrived' : null);
    } catch (error) {
        send({kind:'capture-error', error:String(error)});
    }
}});
rpc.exports = {status};
send({kind:'ready', paint:target('paint').toString(), arch:Process.arch, engine:'trace-native'});
