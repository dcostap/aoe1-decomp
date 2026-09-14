// Experimental replay: real window messages, read-only state probes, explicit stop boundaries.
const replayState = {input:0, updates:0, stopped:false, observations:0};
const probeCounts = new Map();
const rngSites = new Map();
const rngBuffer = new ArrayBuffer(4096 * 8);
const rngView = new DataView(rngBuffer);
let rngUsed = 0;
function flushReplayRng() {
    if (!rngUsed) return;
    send({kind:'replay-rng-batch', records:rngUsed}, rngBuffer.slice(0, rngUsed * 8));
    rngUsed = 0;
}
function replayRng(row) {
    if (rngCount > 10000000) { replayStop('RNG recording limit reached'); return; }
    const site = {kind:row.kind, file:row.file.replace(/\//g, '\\').toLowerCase(), line:row.line};
    const key = JSON.stringify(site);
    if (!rngSites.has(key)) {
        flushReplayRng();
        const id = rngSites.size;
        rngSites.set(key, id);
        send({kind:'replay-rng-site', id, site, raw_file:row.file});
    }
    rngView.setUint32(rngUsed * 8, rngSites.get(key), true);
    rngView.setUint32(rngUsed * 8 + 4, row.kind === 'srand' ? row.seed : row.value, true);
    if (++rngUsed === 4096) flushReplayRng();
}
function replayStop(error) {
    if (replayState.stopped) return;
    replayState.stopped = true;
    flushReplayRng();
    send({kind:error ? 'replay-error' : 'replay-done', error:error || null,
        replay:replayState, status:rpc.exports.status()});
    sleep(0xffffffff);
}
function readProbeFields(receiver, description) {
    const fields = {};
    for (const [name, [offset, type]] of Object.entries(description || {})) {
        const p = receiver.add(offset);
        const readers = {u8:'readU8', i16:'readS16', u16:'readU16', i32:'readS32', u32:'readU32', f32:'readFloat'};
        const size = {u8:1, i16:2, u16:2, i32:4, u32:4, f32:4}[type];
        fields[name] = {value:p[readers[type]](), bytes:Array.from(new Uint8Array(p.readByteArray(size)))};
    }
    return fields;
}
function probeState(probe, phase, invocation) {
    if (replayState.observations >= 10000) throw new Error('Observation limit reached');
    flushReplayRng();
    const fields = readProbeFields(invocation.receiver, probe.fields);
    send({kind:'behavior-state', probe:probe.name, phase, ordinal:invocation.ordinal,
        input:replayState.input, updates:replayState.updates, fields, arguments:invocation.arguments,
        receiver:invocation.receiver.toString(),
        stack:Thread.backtrace(invocation.context, Backtracer.ACCURATE).map(address => {
            const module = Process.findModuleByAddress(address);
            return {address:address.toString(), module:module ? module.name : null,
                rva:module ? address.sub(module.base).toUInt32() : null};
        })});
    replayState.observations++;
}
for (const probe of cfg.replay.probes) {
    Interceptor.attach(target('probe_' + probe.name), {
        onEnter() {
            this.receiver = this.context.ecx;
            this.ordinal = (probeCounts.get(probe.name) || 0) + 1;
            probeCounts.set(probe.name, this.ordinal);
            try {
                this.arguments = readProbeFields(this.context.esp.add(4), probe.arguments);
                if (probe.phase !== 'leave') probeState(probe, 'enter', this);
            }
            catch (error) { replayStop(String(error)); }
        },
        onLeave() {
            try {
                if (probe.name === cfg.replay.update_probe) replayState.updates++;
                if (probe.phase !== 'enter') probeState(probe, 'leave', this);
                if (replayState.updates >= cfg.replay.updates) {
                    replayStop(replayState.input !== cfg.uiSteps.length || pending.length ? 'Replay ended before all inputs' : null);
                }
            } catch (error) { replayStop(String(error)); }
        }
    });
}
let replayStable = 0, replayPaint = -1;
Interceptor.attach(target('idle'), {onLeave() {
    if (replayState.stopped || !gameWindow || this.threadId !== gameThread || count < 8 || pending.length) return;
    // Mouse handling also calls idle. Do not miss update boundaries reached through that path.
    if (replayState.updates === 0 &&
        (this.returnAddress.compare(run) < 0 || this.returnAddress.compare(run.add(0xd0)) >= 0)) return;
    const step = cfg.uiSteps[replayState.input];
    if (!step || replayState.updates < (step.after_updates || 0)) return;
    if (currentPanelName() !== step.before) return;
    if (replayState.updates === 0) {
        if (count !== replayPaint) { replayPaint = count; replayStable = 0; return; }
        if (++replayStable < 3) return;
    }
    try {
        bindInputImports();
        ui.index = replayState.input;
        send({kind:'replay-input', index:replayState.input, updates:replayState.updates, step});
        applyInput(step);
        replayState.input++;
        replayStable = 0;
    } catch (error) { replayStop(String(error)); }
}});
