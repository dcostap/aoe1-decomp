// Optional read-only diagnostics. The accepted control script remains unchanged.
const observationSites = new Map();
const observationRawSites = new Map();
let observationEventBuffer = [];
const observationBuffer = new ArrayBuffer(4096*8);
const observationView = new DataView(observationBuffer);
let observationUsed = 0, observationEvents = 0, observationRecords = 0;
function flushObservations() {
    if (!observationUsed) return;
    send({kind:'replay-rng-batch',records:observationUsed},observationBuffer.slice(0,observationUsed*8));
    observationUsed = 0;
}
const controlRng = rng;
rng = function(row) {
    controlRng(row);
    if (++observationRecords > 10000000) { humanStop('Full RNG trace limit reached'); return; }
    const rawKey = row.kind + ':' + row.file + ':' + row.line;
    if (!observationRawSites.has(rawKey)) {
        const site = {kind:row.kind,file:row.file.replace(/\//g,'\\').toLowerCase(),line:row.line};
        const key = JSON.stringify(site);
        if (!observationSites.has(key)) {
            flushObservations();
            const id = observationSites.size;
            observationSites.set(key,id);
            send({kind:'replay-rng-site',id,site,raw_file:row.file});
        }
        observationRawSites.set(rawKey,observationSites.get(key));
    }
    observationView.setUint32(observationUsed*8,observationRawSites.get(rawKey),true);
    observationView.setUint32(observationUsed*8+4,row.kind === 'srand' ? row.seed : row.value,true);
    if (++observationUsed === 4096) flushObservations();
};
const controlStop = humanStop;
function flushObservationEvents() {
    if (!observationEventBuffer.length) return;
    send({kind:'observer-events',events:observationEventBuffer});
    observationEventBuffer = [];
}
humanStop = function(error) {
    flushObservations();
    flushObservationEvents();
    send({kind:'observer-summary',records:observationRecords,events:observationEvents,error:error || null});
    controlStop(error);
};
function observed(kind,data) {
    if (++observationEvents > 200000) { humanStop('Diagnostic observation limit reached'); return; }
    observationEventBuffer.push(Object.assign({kind,sequence:observationEvents,rng_count:observationRecords,
        turn:human.turn,updates:human.updates,time_ms:ticks-1000,input:human.input},data));
    if (observationEventBuffer.length >= 128) flushObservationEvents();
}
function guardObservation(fn) {
    try { fn(); } catch (error) { humanStop('Diagnostic read failed: ' + error); }
}
function floatValue(pointer) {
    return {value:pointer.readFloat(),bytes:Array.from(new Uint8Array(pointer.readByteArray(4)))};
}
function objectValue(object) {
    if (object.isNull()) return null;
    const master = object.add(8).readPointer(), owner = object.add(12).readPointer();
    return {id:object.add(4).readS32(),master:master.isNull() ? null : master.add(16).readS16(),
        owner:owner.isNull() ? null : owner.add(74).readS16(),
        x:floatValue(object.add(56)),y:floatValue(object.add(60)),hp:floatValue(object.add(48)),
        state:object.add(72).readU8()};
}
if (!cfg.human.rng_only) {
Interceptor.attach(target('probe_human_world'), {
    onEnter() {
        this.world = this.context.ecx;
        guardObservation(() => observed('observer-world',{phase:'enter',time:this.world.add(4).readU32(),
            delta:this.world.add(12).readU32(),registrations:this.world.add(140).readS32()}));
    },
    onLeave() {
        guardObservation(() => observed('observer-world',{phase:'leave',time:this.world.add(4).readU32(),
            delta:this.world.add(12).readU32(),registrations:this.world.add(140).readS32()}));
    }
});
Interceptor.attach(target('probe_observer_add'), {
    onEnter(args) { this.object = args[0]; this.world = this.context.ecx; },
    onLeave(value) { guardObservation(() => observed('observer-object',{operation:'register',result:value.toInt32(),
        object:objectValue(this.object),registrations:this.world.add(140).readS32()})); }
});
Interceptor.attach(target('probe_observer_remove'), {
    onEnter(args) {
        guardObservation(() => {
            const id = args[0].toInt32(), w = this.context.ecx;
            const index = id < 0 ? -id : id, table = w.add(id < 0 ? 148 : 136).readPointer();
            const size = w.add(id < 0 ? 156 : 144).readS32();
            const object = index < size && !table.isNull() ? table.add(index*4).readPointer() : NULL;
            observed('observer-object',{operation:'remove',id,object:objectValue(object),registrations:w.add(140).readS32()});
        });
    }
});
Interceptor.attach(target('probe_observer_pick'), {
    onEnter(args) { this.xy = [args[0].toInt32(),args[1].toInt32()]; this.x = args[2]; this.y = args[3]; },
    onLeave(value) { guardObservation(() => observed('observer-pick',{screen:this.xy,result:value.toInt32(),
        tile:value.toInt32() ? [this.x.isNull() ? null : this.x.readS16(),this.y.isNull() ? null : this.y.readS16()] : null})); }
});
Interceptor.attach(target('probe_human_camera'), {
    onEnter() {
        guardObservation(() => observed('observer-camera',{player:this.context.ecx.add(74).readS16(),
            arguments:[floatValue(this.context.esp.add(4)),floatValue(this.context.esp.add(8))]}));
    }
});
}
send({kind:'observer-ready',schema:1,scope:cfg.human.rng_only ? 'Full debug RNG only' :
    'Full debug RNG, registration/removal, world counters, minimap picks, and camera arguments'});
