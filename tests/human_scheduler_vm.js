'use strict';

const assert = require('assert');
const crypto = require('crypto');
const fs = require('fs');
const path = require('path');
const vm = require('vm');

const root = path.resolve(__dirname, '..');
const source = fs.readFileSync(path.join(root, 'tools', 'harness', 'human.js'), 'utf8');
const candidatePath = path.join(root, 'config', 'harness', 'human-candidate-20260915.json');
const candidateBytes = fs.readFileSync(candidatePath);
assert.strictEqual(crypto.createHash('sha256').update(candidateBytes).digest('hex'),
                   '60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e');
const candidate = JSON.parse(candidateBytes);
const enterEvents = candidate.events.slice(1110, 1114);
assert.deepStrictEqual(enterEvents.map(event => [event.turn, event.route, event.message]), [
  [2770, [], 0x100],
  [2770, [], 0x102],
  [2770, [{id: 1, cls: 'Edit', index: 0}], 0x101],
  [2770, [], 0x200],
]);

class Value {
  constructor(value) { this.value = value >>> 0; }
  toUInt32() { return this.value; }
  toInt32() { return this.value | 0; }
}

class Pointer {
  constructor(name) { this.name = name; }
  add() { return this; }
  compare(other) { return this.name === other.name ? 0 : -1; }
  equals(other) { return this === other; }
  isNull() { return false; }
  readPointer() { return this; }
  readU32() { return 0; }
  readS32() { return 0; }
  readS16() { return 0; }
  readFloat() { return 0; }
  toString() { return this.name; }
  writePointer() {}
}

const NULL = {
  add() { return this; }, compare() { return -1; }, equals(other) { return other === this; },
  isNull() { return true; }, readPointer() { return this; }, toString() { return '0x0'; },
};

class MemoryBlock {
  constructor() { this.values = new Map(); this.cstring = ''; }
  add(offset) {
    const parent = this;
    return {
      writeS32(value) { parent.values.set(offset, value | 0); },
      readS32() { return parent.values.get(offset) || 0; },
      writeU8(value) { parent.values.set(offset, value); },
      writeU16(value) { parent.values.set(offset, value); },
      writeU32(value) { parent.values.set(offset, value >>> 0); },
      readU32() { return parent.values.get(offset) || 0; },
      readPointer() { return parent.values.get(offset) || NULL; },
    };
  }
  writeS32(value) { this.values.set(0, value | 0); }
  readS32() { return this.values.get(0) || 0; }
  writeU32(value) { this.values.set(0, value >>> 0); }
  writeByteArray() {}
  readCString() { return this.cstring; }
}

class MessagePointer {
  constructor(hwnd, event, name) { this.hwnd = hwnd; this.event = event; this.name = name; }
  add(offset) {
    const message = this;
    return {
      readU32() {
        if (offset === 4) return message.event.message >>> 0;
        if (offset === 8) return message.event.value >>> 0;
        if (offset === 12) return message.event.parameter >>> 0;
        return 0;
      },
      writeU32(value) { if (offset === 4) message.event.message = value >>> 0; },
    };
  }
  readPointer() { return this.hwnd; }
  toString() { return this.name; }
}

function makeHarness(events) {
  const rootWindow = new Pointer('root');
  const windows = new Map([[rootWindow, {parent: null, id: 0, cls: 'Root'}]]);
  const children = new Map([[rootWindow, []]]);
  const queue = [];
  const sent = [];
  const hooks = new Map();
  let nextWindow = 1;
  let nextMessage = 1;
  let failPost = false;

  function addWindow(parent, id, cls, visible = true) {
    const hwnd = new Pointer(`${cls}-${id}-generation-${nextWindow++}`);
    windows.set(hwnd, {parent, id, cls, visible});
    children.set(hwnd, []);
    children.get(parent).push(hwnd);
    return hwnd;
  }
  function removeWindow(hwnd) {
    const row = windows.get(hwnd);
    if (!row) return;
    const siblings = children.get(row.parent);
    siblings.splice(siblings.indexOf(hwnd), 1);
    children.delete(hwnd);
    windows.delete(hwnd);
  }
  function native(name) {
    if (name === 'GetParent') return hwnd => windows.get(hwnd)?.parent || NULL;
    if (name === 'GetWindow') return (hwnd, command) => {
      if (command === 5) return (children.get(hwnd) || [])[0] || NULL;
      if (command === 2) {
        const row = windows.get(hwnd);
        if (!row?.parent) return NULL;
        const siblings = children.get(row.parent) || [];
        return siblings[siblings.indexOf(hwnd) + 1] || NULL;
      }
      return NULL;
    };
    if (name === 'GetDlgCtrlID') return hwnd => windows.get(hwnd)?.id ?? -1;
    if (name === 'IsWindowVisible') return hwnd => (windows.get(hwnd)?.visible ? 1 : 0);
    if (name === 'GetClassNameA') return (hwnd, buffer) => {
      const row = windows.get(hwnd);
      if (!row) return 0;
      buffer.cstring = row.cls;
      return row.cls.length;
    };
    if (name === 'GetTickCount') return () => 1000;
    if (name === 'Sleep') return () => {};
    if (name === 'SetKeyboardState' || name === 'ClientToScreen' || name === 'ScreenToClient' ||
        name === 'InvalidateRect') return () => 1;
    return () => 1;
  }
  const modules = new Map();
  function module(name) {
    if (!modules.has(name)) modules.set(name, {name, getExportByName(symbol) { return `${name}:${symbol}`; }});
    return modules.get(name);
  }
  const context = {
    cfg: {human: {mode: 'replay', duration_ms: 190000, events}, inputIAT: {}},
    Process: {getModuleByName: module, findRangeByAddress() { return {protection: 'r--'}; }},
    NativeFunction: function(address) { return native(address.split(':').at(-1)); },
    NativeCallback: function(callback) { return callback; },
    Interceptor: {
      attach(address, callbacks) { hooks.set(address, callbacks); },
      replace() {},
    },
    Memory: {alloc() { return new MemoryBlock(); }, protect() { return true; }},
    ptr(value) { return value === 0 ? NULL : new Pointer(String(value)); },
    NULL,
    target(name) { return `target:${name}`; },
    base: new Pointer('base'),
    run: new Pointer('run'),
    gameWindow: rootWindow,
    gameThread: 7,
    ticks: 1000,
    post(hwnd, message, value, parameter) {
      if (failPost) return 0;
      queue.push(new MessagePointer(hwnd, {message, value, parameter}, `msg-${nextMessage++}`));
      return 1;
    },
    currentPanelName() { return 'Game Screen'; },
    send(row) { sent.push(row); },
    rpc: {exports: {status() { return {}; }}},
    Uint8Array,
    console,
  };
  vm.createContext(context);
  vm.runInContext(source, context);

  function evaluate(expression) { return vm.runInContext(expression, context); }
  function state() { return evaluate('({human:{...human},pending:waiting.length})'); }
  function pump() { return evaluate('pumpReplay()'); }
  function dispatch(message, effect = () => {}, api = 'DispatchMessageA') {
    const hook = hooks.get(`user32.dll:${api}`);
    const invocation = {threadId: 7};
    hook.onEnter.call(invocation, [message]);
    effect(invocation);
    hook.onLeave.call(invocation);
  }
  return {rootWindow, windows, children, queue, sent, hooks, addWindow, removeWindow,
          evaluate, state, pump, dispatch, setPostFailure(value) { failPost = value; }};
}

function drain(harness, effect) {
  while (harness.queue.length) {
    const message = harness.queue.shift();
    harness.dispatch(message, () => effect(message));
  }
}

// The candidate recording keeps its older route shape. This core records and
// resolves the visible window, so the replay events carry the current shape.
function currentRoutes(events) {
  return events.map(event => ({...event,
                              route: event.route.map(part => ({id: part.id, cls: part.cls, vis: 1}))}));
}

// The real candidate sequence creates Edit during Return key-down dispatch.
// Return key-up can destroy it before the next root event is resolved.
{
  const harness = makeHarness(currentRoutes(enterEvents));
  harness.evaluate('human.turn=2770');
  harness.pump();
  assert.deepStrictEqual([harness.state().human.posted, harness.state().pending, harness.queue.length], [1, 1, 1]);
  const destinations = [];
  let edit;
  drain(harness, message => {
    destinations.push(message.hwnd.name);
    if (message.event.message === 0x100) edit = harness.addWindow(harness.rootWindow, 1, 'Edit');
    if (message.event.message === 0x101) harness.removeWindow(edit);
  });
  assert.deepStrictEqual(destinations, ['root', 'root', edit.name, 'root']);
  assert.deepStrictEqual([harness.state().human.posted, harness.state().human.input,
                          harness.state().pending], [4, 4, 0]);
}

// Resolve each route after its predecessor returns. Do not retain a destroyed HWND.
{
  const route = [{id: 1, cls: 'Edit', vis: 1}];
  const events = [
    {turn: 1, route: [], message: 0x100, value: 1, parameter: 0, time_ms: 1},
    {turn: 1, route, message: 0x101, value: 1, parameter: 0, time_ms: 1},
    {turn: 1, route, message: 0x100, value: 2, parameter: 0, time_ms: 1},
  ];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.pump();
  const destinations = [];
  let first;
  drain(harness, message => {
    destinations.push(message.hwnd.name);
    if (message.event.message === 0x100 && message.event.value === 1)
      first = harness.addWindow(harness.rootWindow, 1, 'Edit');
    if (message.event.message === 0x101 && message.event.value === 1) {
      harness.removeWindow(first);
      harness.addWindow(harness.rootWindow, 1, 'Edit');
    }
  });
  assert.match(destinations[1], /generation-1$/);
  assert.match(destinations[2], /generation-2$/);
}

// A/W forwarding, unrelated nested dispatch, and nested pump calls cannot release pending input.
{
  const events = [
    {turn: 1, route: [], message: 0x100, value: 3, parameter: 0, time_ms: 1},
    {turn: 1, route: [], message: 0x101, value: 3, parameter: 0, time_ms: 1},
  ];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.pump();
  const message = harness.queue.shift();
  const outer = {threadId: 7};
  const alias = {threadId: 7};
  const a = harness.hooks.get('user32.dll:DispatchMessageA');
  const w = harness.hooks.get('user32.dll:DispatchMessageW');
  a.onEnter.call(outer, [message]);
  w.onEnter.call(alias, [message]);
  harness.pump();
  w.onLeave.call(alias);
  const duplicate = new MessagePointer(harness.rootWindow,
    {message: 0x100, value: 3, parameter: 0}, 'nested-identical-input');
  harness.dispatch(duplicate);
  assert.deepStrictEqual([harness.state().human.input, harness.state().human.dropped,
                          harness.state().pending], [1, 1, 1]);
  const nested = new MessagePointer(harness.rootWindow,
    {message: 0x000f, value: 0, parameter: 0}, 'nested-paint');
  harness.dispatch(nested);
  harness.pump();
  assert.deepStrictEqual([harness.state().human.posted, harness.queue.length], [1, 0]);
  a.onLeave.call(outer);
  assert.deepStrictEqual([harness.state().human.posted, harness.queue.length], [2, 1]);
}

// A genuine nested modal dispatch can consume input. Release its successor when
// that exact nested call returns, not when the unrelated outer call returns.
{
  const events = [
    {turn: 1, route: [], message: 0x100, value: 7, parameter: 0, time_ms: 1},
    {turn: 1, route: [], message: 0x101, value: 7, parameter: 0, time_ms: 1},
  ];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.pump();
  const expected = harness.queue.shift();
  const paint = new MessagePointer(harness.rootWindow,
    {message: 0x000f, value: 0, parameter: 0}, 'outer-modal-paint');
  const hook = harness.hooks.get('user32.dll:DispatchMessageA');
  const outer = {threadId: 7};
  hook.onEnter.call(outer, [paint]);
  harness.dispatch(expected);
  assert.deepStrictEqual([harness.state().human.posted, harness.queue.length], [2, 1]);
  hook.onLeave.call(outer);
  assert.deepStrictEqual([harness.state().human.posted, harness.queue.length], [2, 1]);
}

// An unrequested input message stays blocked and cannot release expected input.
{
  const events = [{turn: 1, route: [], message: 0x100, value: 8, parameter: 0, time_ms: 1}];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.pump();
  const expected = harness.queue.shift();
  const extra = new MessagePointer(harness.rootWindow,
    {message: 0x101, value: 8, parameter: 0}, 'extra-input');
  harness.dispatch(extra);
  assert.deepStrictEqual([harness.state().human.posted, harness.state().human.input,
                          harness.state().human.dropped, harness.state().pending], [1, 0, 1, 1]);
  harness.dispatch(expected);
  assert.deepStrictEqual([harness.state().human.input, harness.state().pending], [1, 0]);
}

// The dispatch that entered with the expected object must release that same object.
{
  const events = [{turn: 1, route: [], message: 0x100, value: 4, parameter: 0, time_ms: 1}];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.pump();
  const message = harness.queue.shift();
  const hook = harness.hooks.get('user32.dll:DispatchMessageA');
  const invocation = {threadId: 7};
  hook.onEnter.call(invocation, [message]);
  harness.evaluate('waiting[0]={hwnd:waiting[0].hwnd,event:waiting[0].event}');
  hook.onLeave.call(invocation);
  assert.strictEqual(harness.state().human.stopped, true);
  assert.match(harness.sent.at(-1).error, /dispatch identity changed/);
}

// Missing and ambiguous routes fail. They do not retry or advance the posted count.
for (const ambiguous of [false, true]) {
  const events = [{turn: 1, route: [{id: 1, cls: 'Edit', vis: 1}],
                   message: 0x100, value: 5, parameter: 0, time_ms: 1}];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  if (ambiguous) {
    harness.addWindow(harness.rootWindow, 1, 'Edit');
    harness.addWindow(harness.rootWindow, 1, 'Edit');
  }
  assert.throws(() => harness.pump(), /Recorded input window is missing or ambiguous/);
  assert.deepStrictEqual([harness.state().human.posted, harness.state().pending], [0, 0]);
}

// A hidden sibling of the same class and control id does not make the route
// ambiguous. The editor keeps hidden edit panels beside the visible one.
{
  const events = [{turn: 1, route: [{id: 1, cls: 'Edit', vis: 1}],
                   message: 0x100, value: 9, parameter: 0, time_ms: 1}];
  const harness = makeHarness(events);
  const hidden = harness.addWindow(harness.rootWindow, 1, 'Edit', false);
  const visible = harness.addWindow(harness.rootWindow, 1, 'Edit');
  harness.evaluate('human.turn=1');
  harness.pump();
  assert.deepStrictEqual(harness.queue.map(message => message.hwnd.name), [visible.name]);
  assert.notStrictEqual(harness.queue[0].hwnd.name, hidden.name);
}

// A failed PostMessage removes pending state and does not count the event as posted.
{
  const events = [{turn: 1, route: [], message: 0x100, value: 6, parameter: 0, time_ms: 1}];
  const harness = makeHarness(events);
  harness.evaluate('human.turn=1');
  harness.setPostFailure(true);
  assert.throws(() => harness.pump(), /Cannot post recorded input/);
  assert.deepStrictEqual([harness.state().human.posted, harness.state().pending], [0, 0]);
}

console.log('PASS: human serialized scheduler VM tests');
