// Runs inside the 32-bit game. Capture only at a game-thread Paint boundary.
'use strict';
const cfg = __CONFIG__;
if (Process.arch !== 'ia32') throw new Error('Expected an IA-32 game');
const base = Process.mainModule.base;
const gameRegistryKey = 'software\\microsoft\\games\\age of empires\\1.00';
let registryRedirects = 0;
let mutexRedirects = 0;
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
const paint = target('paint');
const run = target('run');
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
        callerModule: origin ? origin.name : null,
        memory: details.memory, context: details.context});
    return false;
});
function currentPanelName() {
    const value = base.add(cfg.panelSystem.rva).add(12).readPointer();
    if (value.isNull()) return null;
    const name = value.add(28).readPointer();
    return name.isNull() ? null : name.readCString();
}
Interceptor.attach(target('wndproc'), {
    onEnter(args) {
        const message = args[1].toUInt32();
        if (message === 0x100 || message === 0x101)
            send({kind: 'input-consumed', message, key: args[2].toUInt32(), panel: currentPanelName()});
    }
});
let ticks = 1000;
let rngCount = 0;
let rngTrace = [];
let clockCallback = null;
if (cfg.clockMode === 'calls') {
    clockCallback = new NativeCallback(() => (++ticks) >>> 0, 'uint', ['pointer', 'int'], 'mscdecl');
    Interceptor.replace(target('clock'), clockCallback);
}
function rng(row) {
    rngCount++;
    if (rngTrace.length < 10000) rngTrace.push(row);
}
Interceptor.attach(target('srand'), {
    onEnter(args) { rng({kind: 'srand', file: args[0].readCString(), line: args[1].toInt32(), seed: args[2].toUInt32()}); }
});
Interceptor.attach(target('rand'), {
    onEnter(args) { this.site = {kind: 'rand', file: args[0].readCString(), line: args[1].toInt32()}; },
    onLeave(value) { rng(Object.assign(this.site, {value: value.toInt32()})); }
});
let count = 0;
let failures = 0;
const posted = new Set();
let gameWindow = null;
let gameThread = null;
const post = new NativeFunction(Process.getModuleByName('user32.dll').getExportByName('PostMessageA'),
    'int', ['pointer', 'uint', 'uint', 'uint'], 'stdcall');
// Queue input only after the drawing call and its parent handler have returned.
// Posting during Paint can put the event into a constructor's input-flush path.
{
    Interceptor.attach(target('idle'), {
        onEnter() {
            if (!gameWindow || this.threadId !== gameThread) return;
            if (this.returnAddress.compare(run) < 0 || this.returnAddress.compare(run.add(0xd0)) >= 0) return;
            for (const [index, action] of cfg.actions.entries()) {
                if (count >= action.after_paint && !posted.has(index)) {
                    posted.add(index);
                    const down = post(gameWindow, 0x100, action.key, 1);
                    const up = post(gameWindow, 0x101, action.key, 0xc0000001);
                    send({kind: 'input-posted', index, after_paint: count, boundary: 'run:handle_idle',
                        key: action.key, down, up});
                    break;
                }
            }
        }
    });
}
const desc = Memory.alloc(108);
const palette = Memory.alloc(1024);
const functions = new Map();
function method(object, slot, types) {
    const address = object.readPointer().add(slot * 4).readPointer();
    const key = address.toString();
    if (!functions.has(key)) functions.set(key, new NativeFunction(address, 'int', types, 'stdcall'));
    return functions.get(key);
}
Interceptor.attach(paint, {
    onEnter() {
        try {
            const system = this.context.ecx;
            gameWindow = system.add(4).readPointer();
            gameThread = this.threadId;
            const area = system.add(12).readPointer();
            if (area.isNull()) return;
            const surface = area.add(60).readPointer();
            const pal = system.add(36).readPointer();
            if (surface.isNull() || pal.isNull()) return;
            desc.writeU32(108);
            if (method(surface, 22, ['pointer', 'pointer'])(surface, desc) !== 0)
                throw new Error('GetSurfaceDesc failed');
            const height = desc.add(8).readU32();
            const width = desc.add(12).readU32();
            const pitch = desc.add(16).readS32();
            const pixels = desc.add(36).readPointer();
            const bits = desc.add(84).readU32();
            if (bits !== 8 || pixels.isNull() || width < 1 || height < 1 ||
                width > 4096 || height > 4096 || pitch < width || pitch > 8192)
                throw new Error('Unsupported surface description');
            if (method(pal, 4, ['pointer', 'uint', 'uint', 'uint', 'pointer'])(pal, 0, 0, 256, palette) !== 0)
                throw new Error('GetEntries failed');
            count++;
            if (count > cfg.maxFrames) return;
            const data = new Uint8Array(pitch * height + 1024);
            data.set(new Uint8Array(pixels.readByteArray(pitch * height)));
            data.set(new Uint8Array(palette.readByteArray(1024)), pitch * height);
            send({kind: 'frame', count, width, height, pitch, bits, panel: currentPanelName()}, data.buffer);
        } catch (error) {
            if (++failures <= 5) send({kind: 'capture-error', error: String(error)});
        }
    }
});
rpc.exports = {
    status() {
        return {count, failures, posted: posted.size, ticks, rngCount, rngTrace, panel: currentPanelName(),
            registryRedirects, mutexRedirects,
            modules: Process.enumerateModules().map(m => ({name: m.name, path: m.path, base: m.base, size: m.size}))};
    }
};
send({kind: 'ready', paint: paint.toString(), arch: Process.arch});
