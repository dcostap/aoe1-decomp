// Menu-only interaction profile. Input enters through Windows messages, never control actions.
const ui = {index: 0, done: false, checkpoints: [], receipts: 0};
const user = Process.getModuleByName('user32.dll');
const sleep = new NativeFunction(Process.getModuleByName('kernel32.dll').getExportByName('Sleep'),
    'void', ['uint'], 'stdcall');
for (const name of ['forbidStart', 'forbidLoad', 'forbidScenario', 'forbidEditor']) {
    if (cfg.replay && name === 'forbidStart') continue;
    Interceptor.attach(target(name), {onEnter() {
        send({kind: 'forbidden-gameplay', boundary: name});
        // Stop before the original body. The controller kills this owned process.
        sleep(0xffffffff);
    }});
}
let mx = 0, my = 0, leftDown = false;
const coordinateWidth = 640, coordinateHeight = 480;
const uiResolution = cfg.uiResolution || {width: coordinateWidth, height: coordinateHeight};
const keys = new Set();
const keyboardState = Memory.alloc(256);
const setKeyboardState = new NativeFunction(user.getExportByName('SetKeyboardState'), 'int', ['pointer'], 'stdcall');
function updateKeyboardState() {
    keyboardState.writeByteArray(new Uint8Array(256));
    for (const key of keys) keyboardState.add(key).writeU8(0x80);
    if (leftDown) keyboardState.add(1).writeU8(0x80);
    if (!setKeyboardState(keyboardState)) throw new Error('Cannot set private input-queue key state');
}
const keyCallbacks = [];
const inputImports = new Map();
for (const name of ['GetKeyState', 'GetAsyncKeyState']) {
    const callback = new NativeCallback(key => (key === 1 ? leftDown : keys.has(key)) ? -32768 : 0,
        'int16', ['int'], 'stdcall');
    keyCallbacks.push(callback);
    inputImports.set(name, callback);
    Interceptor.replace(user.getExportByName(name), callback);
}
inputImports.set('GetCursorPos', new NativeCallback(point => {
    point.writeS32(mx); point.add(4).writeS32(my); return 1;
}, 'int', ['pointer'], 'stdcall'));
let inputSlots = null;
function bindInputImports() {
    if (!inputSlots) {
        inputSlots = [];
        for (const [name, callback] of inputImports) {
            const slot = base.add(cfg.inputIAT[name]), protection = Process.findRangeByAddress(slot).protection;
            if (!Memory.protect(slot, Process.pointerSize, 'rw-')) throw new Error('Cannot write input import');
            slot.writePointer(callback);
            send({kind:'ui-input-import', name, slot:slot.toString(),
                requested:callback.toString(), actual:slot.readPointer().toString()});
            if (!Memory.protect(slot, Process.pointerSize, protection)) throw new Error('Cannot restore input import protection');
            inputSlots.push({name, slot, callback});
        }
        send({kind:'ui-input-bindings', names:inputSlots.map(i => i.name)});
    }
    for (const i of inputSlots) if (!i.slot.readPointer().equals(i.callback))
        throw new Error('Game input import changed: ' + i.name + ': ' + i.slot.readPointer() + ' != ' + i.callback);
}
const focus = new NativeFunction(user.getExportByName('GetFocus'), 'pointer', [], 'stdcall');
let pending = [];
let keyRelease = null;
Interceptor.attach(user.getExportByName('DispatchMessageA'), {
    onEnter(args) {
        const m = args[0];
        const receipt = [m.readPointer().toString(), m.add(4).readU32(), m.add(8).readU32(), m.add(12).readU32()];
        if (pending.length && JSON.stringify(receipt) === JSON.stringify(pending[0])) {
            this.releaseKey = receipt[1] === 0x100 && keyRelease !== null;
            pending.shift();
            ui.receipts++;
            if (receipt[1] === 0x201) leftDown = true;
            if (receipt[1] === 0x202) leftDown = false;
            if (receipt[1] === 0x100) keys.add(receipt[2]);
            if (receipt[1] === 0x101) keys.delete(receipt[2]);
            updateKeyboardState();
            send({kind: 'ui-input-consumed', step: ui.index, message: receipt[1], value: receipt[2],
                window: receipt[0], parameter: receipt[3], updates:cfg.replay ? replayState.updates : undefined});
        }
    },
    onLeave() {
        if (this.releaseKey) {
            const hwnd = focus(), key = keyRelease;
            keyRelease = null;
            queue(hwnd.isNull() ? gameWindow : hwnd, 0x101, key, 0xc0000001);
        }
    }
});
function queue(hwnd, message, value, param) {
    pending.push([hwnd.toString(), message, value >>> 0, param >>> 0]);
    if (!post(hwnd, message, value, param)) throw new Error('PostMessage failed');
}
function rootPanel() {
    const system = base.add(cfg.panelSystem.rva);
    const modal = system.add(8).readPointer();
    return modal.isNull() ? system.add(12).readPointer() : modal;
}
function ansi(value) {
    if (value.isNull()) return null;
    let result = '';
    for (let i = 0; i < 512; i++) {
        const c = value.add(i).readU8();
        if (!c) break;
        result += String.fromCharCode(c);
    }
    return result;
}
const drawKinds = new Map(['drop', 'button', 'list', 'text', 'edit', 'scroll'].map(k =>
    [target(k + 'Draw').toString(), k]));
function controls() {
    const result = [];
    function visit(p, path, depth) {
        if (p.isNull()) return;
        if (depth > 16 || result.length >= 512) throw new Error('Control tree limit reached');
        const kind = drawKinds.get(p.readPointer().add(48).readPointer().toString()) || 'panel';
        const row = {path, kind, name: ansi(p.add(28).readPointer()),
            rect: [12,16,20,24].map(o => p.add(o).readS32()),
            active: p.add(108).readS32(), visible: p.add(112).readS32(), focus: p.add(120).readS32()};
        if (kind === 'drop') {
            row.mode = p.add(260).readS32(); row.value = p.add(264).readS16();
        }
        if (kind === 'button') {
            row.value = p.add(0x1f6).readS16(); row.down = p.add(0x1f8).readS32();
            row.disabled = p.add(0x2b0).readS32();
            row.text = row.value >= 0 && row.value < 9 ? ansi(p.add(0x198 + row.value * 4).readPointer()) : null;
        }
        if (kind === 'edit') nativeEdit(p, row);
        if (kind === 'scroll' && row.active && row.visible) {
            row.value = p.add(260).readS32();
            row.thumb = [0,4,8,12].map(o => p.add(388 + o).readS32());
        }
        if (kind === 'list' || kind === 'text') {
            row.value = p.add(256).readS16(); row.top = p.add(252).readS16();
            row.lines = p.add(248).readS16();
            let node = p.add(244).readPointer();
            for (let i = 0; i < row.value && i < 4096 && !node.isNull(); i++) node = node.add(12).readPointer();
            row.text = node.isNull() ? null : ansi(node.readPointer());
        }
        result.push(row);
        let node = p.add(88).readPointer(), index = 0;
        while (!node.isNull()) {
            if (++index > 512) throw new Error('Child list limit reached');
            visit(node.readPointer(), path + '/' + index, depth + 1);
            node = node.add(8).readPointer();
        }
    }
    visit(rootPanel(), 'root', 0);
    return result;
}
function applyInput(step) {
    if (!windowEnabled(gameWindow)) throw new Error('Native modal window blocks scripted game UI');
    for (const key of [16,17,18]) keys.delete(key);
    for (const key of step.modifiers || []) keys.add(key);
    updateKeyboardState();
    const type = step.type || 'snapshot';
    if (type === 'snapshot') return;
    if (type === 'key') {
        const hwnd = focus();
        keyRelease = step.key;
        queue(hwnd.isNull() ? gameWindow : hwnd, 0x100, step.key, 1);
        return;
    }
    if (type === 'text') {
        const hwnd = focus();
        for (const c of step.text) queue(hwnd.isNull() ? gameWindow : hwnd, 0x102, c.charCodeAt(0), 1);
        return;
    }
    mx = Math.round(step.x * uiResolution.width / coordinateWidth);
    my = Math.round(step.y * uiResolution.height / coordinateHeight);
    let hwnd = getCapture();
    if (hwnd.isNull()) hwnd = childAt(gameWindow, [mx,my], 3);
    if (hwnd.isNull()) hwnd = gameWindow;
    const point = Memory.alloc(8); point.writeS32(mx); point.add(4).writeS32(my);
    if (!hwnd.equals(gameWindow) && (!clientToScreen(gameWindow, point) || !screenToClient(hwnd, point)))
        throw new Error('Cannot map mouse input into owned child');
    const xy = ((point.add(4).readS32() << 16) | (point.readS32() & 0xffff)) >>> 0;
    queue(hwnd, 0x200, leftDown ? 1 : 0, xy);
    if (type === 'click' || type === 'down') queue(hwnd, 0x201, 1, xy);
    if (type === 'click' || type === 'up') queue(hwnd, 0x202, 0, xy);
    if (!['click','down','up','move'].includes(type)) throw new Error('Unknown UI action: ' + type);
}
let phase = 'input', stable = 0, previousCount = -1;
Interceptor.attach(target('idle'), {
    onLeave() {
        if (cfg.replay || ui.done || phase === 'failed' || !gameWindow || this.threadId !== gameThread || count < 8) return;
        if (this.returnAddress.compare(run) < 0 || this.returnAddress.compare(run.add(0xd0)) >= 0) return;
        if (pending.length) return;
        if (count !== previousCount) { previousCount = count; stable = 0; return; }
        if (++stable < 3) return;
        try {
            bindInputImports();
            const step = cfg.uiSteps[ui.index];
            if (!step) { ui.done = true; send({kind: 'ui-done'}); return; }
            if (phase === 'input') {
                const name = ansi(rootPanel().add(28).readPointer());
                if (step.before && name !== step.before) throw new Error('Wrong source panel: ' + name);
                applyInput(step); phase = 'check'; stable = 0;
            } else {
                const tree = controls();
                const checkpoint = {name: step.name, frame: count, panel: tree[0].name, controls: tree,
                    rngCount, rngTrace: rngTrace.slice()};
                ui.checkpoints.push(checkpoint);
                send({kind: 'ui-checkpoint', checkpoint});
                if (step.panel && checkpoint.panel !== step.panel) throw new Error('Wrong destination panel: ' + checkpoint.panel);
                for (const check of step.check || []) {
                    const matches = tree.filter(c => c.kind === check.kind && (!check.text || c.text === check.text) &&
                        (!check.active_only || (c.active && c.visible)) &&
                        (!check.at || (c.rect[0] <= check.at[0] && c.rect[1] <= check.at[1] &&
                            c.rect[0]+c.rect[2] > check.at[0] && c.rect[1]+c.rect[3] > check.at[1])));
                    if (matches.length !== 1) throw new Error('Control assertion is not unique: ' + JSON.stringify(check));
                    for (const [key, value] of Object.entries(check.equals || {}))
                        if (JSON.stringify(matches[0][key]) !== JSON.stringify(value)) throw new Error('Control assertion failed: ' + JSON.stringify({check, actual: matches[0]}));
                }
                ui.index++; phase = 'input'; stable = 0;
            }
        } catch (error) {
            ui.done = false;
            send({kind: 'ui-error', step: ui.index, error: String(error)});
            // Do not execute another action after a failed assertion.
            phase = 'failed';
            cfg.uiSteps = [];
        }
    }
});
const oldStatus = rpc.exports.status;
rpc.exports.status = () => Object.assign(oldStatus(), {ui});

// Focused TEditPanel text lives in an owned Windows EDIT child, not the draw surface.
// Ask only that child to paint into our memory bitmap. Never read any desktop DC.
const gdi = Process.getModuleByName('gdi32.dll');
function api(module, name, result, args) {
    return new NativeFunction(module.getExportByName(name), result, args, 'stdcall');
}
const getText = api(user, 'GetWindowTextA', 'int', ['pointer','pointer','int']);
const visible = api(user, 'IsWindowVisible', 'int', ['pointer']);
const windowEnabled = api(user, 'IsWindowEnabled', 'int', ['pointer']);
const clientRect = api(user, 'GetClientRect', 'int', ['pointer','pointer']);
const clientToScreen = api(user, 'ClientToScreen', 'int', ['pointer','pointer']);
const screenToClient = api(user, 'ScreenToClient', 'int', ['pointer','pointer']);
const getCapture = api(user, 'GetCapture', 'pointer', []);
const childAt = api(user, 'ChildWindowFromPointEx', 'pointer', ['pointer',['int','int'],'uint']);
const sendWindow = api(user, 'SendMessageA', 'int', ['pointer','uint','pointer','pointer']);
const createDC = api(gdi, 'CreateCompatibleDC', 'pointer', ['pointer']);
const deleteDC = api(gdi, 'DeleteDC', 'int', ['pointer']);
const createDIB = api(gdi, 'CreateDIBSection', 'pointer', ['pointer','pointer','uint','pointer','pointer','uint']);
const selectObject = api(gdi, 'SelectObject', 'pointer', ['pointer','pointer']);
const deleteObject = api(gdi, 'DeleteObject', 'int', ['pointer']);
const flushGdi = api(gdi, 'GdiFlush', 'int', []);
function nativeEdit(panel, row) {
    const hwnd = panel.add(244).readPointer();
    if (hwnd.isNull()) return;
    const text = Memory.alloc(1024);
    getText(hwnd, text, 1024);
    row.text = ansi(text);
    const start = Memory.alloc(4), end = Memory.alloc(4);
    sendWindow(hwnd, 0xb0, start, end);
    row.selection = [start.readU32(), end.readU32()];
    row.native_visible = !!visible(hwnd);
    if (!row.native_visible) return;
    const rect = Memory.alloc(16), point = Memory.alloc(8);
    if (!clientRect(hwnd, rect) || !clientToScreen(hwnd, point) || !screenToClient(gameWindow, point))
        throw new Error('Cannot measure owned edit window');
    const width = rect.add(8).readS32(), height = rect.add(12).readS32();
    if (width < 1 || height < 1 || width > 640 || height > 480) throw new Error('Invalid edit window size');
    const info = Memory.alloc(40), bits = Memory.alloc(Process.pointerSize);
    info.writeU32(40); info.add(4).writeS32(width); info.add(8).writeS32(-height);
    info.add(12).writeU16(1); info.add(14).writeU16(32);
    const dc = createDC(NULL);
    if (dc.isNull()) throw new Error('Cannot create edit capture DC');
    let bitmap = NULL, old = NULL;
    try {
        bitmap = createDIB(dc, info, 0, bits, NULL, 0);
        if (bitmap.isNull()) throw new Error('Cannot create edit capture bitmap');
        old = selectObject(dc, bitmap);
        if (old.isNull()) throw new Error('Cannot select edit capture bitmap');
        sendWindow(hwnd, 0x318, dc, ptr(12)); // WM_PRINTCLIENT: client and background, without blinking caret.
        flushGdi();
        send({kind:'ui-native-frame', step:cfg.replay ? ui.checkpoints.length : ui.index, path:row.path,
            rect:[point.readS32(),point.add(4).readS32(),width,height]}, bits.readPointer().readByteArray(width*height*4));
    } finally {
        if (!old.isNull()) selectObject(dc, old);
        if (!bitmap.isNull()) deleteObject(bitmap);
        deleteDC(dc);
    }
}
