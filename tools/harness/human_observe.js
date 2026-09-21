// Optional read-only diagnostics. The accepted control script remains unchanged.
const observationSites = new Map();
const observationRawSites = new Map();
let observationEventBuffer = [];
const observationBuffer = new ArrayBuffer(4096*8);
const observationView = new DataView(observationBuffer);
let observationUsed = 0, observationEvents = 0, observationRecords = 0;
let observationClockRuns = [], observationClockCalls = 0;
const observationClockCounts = {calls:0,idle:0};
if (cfg.human.combat) {
    const controlAdvance = humanAdvance;
    humanAdvance = function(amount) {
        if (amount === 1) observationClockCounts.calls++;
        if (amount === 20) observationClockCounts.idle++;
        return controlAdvance(amount);
    };
}
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
if (cfg.human.rng_only && typeof humanClock !== 'undefined') {
    const observedHumanClock = humanClock;
    humanClock = function() {
        const value = observedHumanClock() >>> 0;
        const last = observationClockRuns[observationClockRuns.length - 1];
        if (last && last[0] === value) last[1]++;
        else observationClockRuns.push([value,1]);
        observationClockCalls++;
        return value;
    };
}
const controlStop = humanStop;
function flushObservationEvents() {
    if (!observationEventBuffer.length) return;
    send({kind:'observer-events',events:observationEventBuffer});
    observationEventBuffer = [];
}
humanStop = function(error) {
    flushObservations();
    flushObservationEvents();
    for (let index = 0; index < observationClockRuns.length; index += 4096)
        send({kind:'observer-clock-batch',start:index,runs:observationClockRuns.slice(index,index+4096)});
    send({kind:'observer-clock-summary',calls:observationClockCalls,runs:observationClockRuns.length});
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
if (cfg.human.rng_only && typeof humanClock !== 'undefined') {
    let tracedUpdate = null;
    const tracedHumanClock = humanClock;
    humanClock = function() {
        const value = tracedHumanClock();
        if (tracedUpdate !== null) {
            const last = tracedUpdate.clocks[tracedUpdate.clocks.length - 1];
            if (last && last[0] === value) last[1]++;
            else tracedUpdate.clocks.push([value,1]);
        }
        return value;
    };
    Interceptor.attach(target('probe_human_world'), {
        onEnter() {
            this.world = this.context.ecx;
            tracedUpdate = {entry_clock:ticks, clocks:[], input:human.input,
                time:this.world.add(4).readU32(), delta:this.world.add(12).readU32()};
        },
        onLeave() {
            const trace = tracedUpdate;
            tracedUpdate = null;
            guardObservation(() => observed('observer-update',{
                entry_clock:trace.entry_clock, exit_clock:ticks, clocks:trace.clocks,
                entry_time:trace.time, entry_delta:trace.delta,
                exit_time:this.world.add(4).readU32(), exit_delta:this.world.add(12).readU32(),
                entry_input:trace.input, exit_input:human.input
            }));
        }
    });
}
function floatValue(pointer) {
    return {value:pointer.readFloat(),bytes:Array.from(new Uint8Array(pointer.readByteArray(4)))};
}
function objectValue(object) {
    if (object.isNull()) return null;
    const master = object.add(8).readPointer(), owner = object.add(12).readPointer();
    return {id:object.add(4).readS32(),master:master.isNull() ? null : master.add(16).readS16(),
        owner:owner.isNull() ? null : owner.add(74).readS16(),
        x:floatValue(object.add(56)),y:floatValue(object.add(60)),z:floatValue(object.add(64)),hp:floatValue(object.add(48)),
        state:object.add(72).readU8()};
}
if (!cfg.human.rng_only) {
Interceptor.attach(target('probe_human_world'), {
    onEnter() {
        this.world = this.context.ecx;
        if (cfg.human.combat) attachVillagerObserver();
        guardObservation(() => observed('observer-world',{phase:'enter',time:this.world.add(4).readU32(),
            delta:this.world.add(12).readU32(),registrations:this.world.add(140).readS32(),
            old_time:this.world.add(20).readU32(),speed:floatValue(this.world.add(24)),
            clock_counts:cfg.human.combat ? {...observationClockCounts} : null}));
    },
    onLeave() {
        guardObservation(() => observed('observer-world',{phase:'leave',time:this.world.add(4).readU32(),
            delta:this.world.add(12).readU32(),registrations:this.world.add(140).readS32(),
            old_time:this.world.add(20).readU32(),speed:floatValue(this.world.add(24)),
            clock_counts:cfg.human.combat ? {...observationClockCounts} : null}));
    }
});
}
if (!cfg.human.rng_only && !cfg.human.combat) {
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
if (cfg.human.combat) {
    Interceptor.attach(target('probe_observer_attack'), {
        onEnter(args) {
            guardObservation(() => observed('observer-combat',{
                actor:objectValue(this.context.ecx),target:objectValue(args[0]),
                attack_timer:floatValue(this.context.ecx.add(444))}));
        }
    });
    Interceptor.attach(target('probe_observer_attack_update'), {
        onEnter() {
            this.action = this.context.ecx;
            this.sample = human.updates >= 45 && human.updates <= 125;
            if (this.sample) guardObservation(() => observed('observer-attack-update',attackValue(this.action,'enter')));
        },
        onLeave() {
            if (this.sample) guardObservation(() => observed('observer-attack-update',attackValue(this.action,'leave')));
        }
    });
    Interceptor.attach(target('probe_observer_sprite_add'), {
        onEnter(args) {
            if (human.updates < 95 || human.updates > 130) return;
            guardObservation(() => observed('observer-sprite',{
                actor:objectValue(this.context.ecx.add(8).readPointer()),
                sprite:args[0].isNull() ? null : {id:args[0].add(114).readS16(),flags:args[0].add(112).readU8()},
                order:args[1].toUInt32() & 255}));
        }
    });
}
function attackValue(action,phase) {
    const actor = action.add(8).readPointer(), sprite = actor.add(16).readPointer();
    return {phase,actor:objectValue(actor),target:objectValue(action.add(16).readPointer()),
        action_state:action.add(12).readU8(),timer:floatValue(action.add(44)),
        attack_timer:floatValue(actor.add(444)),need_to_attack:action.add(88).readU8(),
        fire_frame:action.add(86).readS16(),animation:animationValue(actor,sprite),
        sprite:sprite.isNull() ? null : {id:sprite.add(114).readS16(),frames:sprite.add(94).readS16(),
            speed:floatValue(sprite.add(100))}};
}
function animationValue(actor,sprite) {
    const list = actor.add(24).readPointer();
    if (list.isNull()) return null;
    let node = list.add(4).readPointer(), count = 0;
    while (!node.isNull()) {
        if (++count > 64) throw new Error('Active sprite list exceeds diagnostic limit');
        const active = node.readPointer();
        if (active.add(4).readPointer().equals(sprite)) {
            const type = active.add(8).readU8();
            if (type !== 2) return {type};
            return {type,frame:active.add(20).readS16(),interval:floatValue(active.add(24)),
                elapsed:floatValue(active.add(28)),last_frame:active.add(32).readS16(),
                changed:active.add(34).readU8(),looped:active.add(35).readU8(),flag:active.add(36).readU8()};
        }
        node = node.add(8).readPointer();
    }
    return null;
}
let villagerObserverAttached = false;
function attachVillagerObserver() {
    if (villagerObserverAttached) return;
    villagerObserverAttached = true;
    Interceptor.attach(target('probe_observer_actor_update'), {
        onEnter() {
            this.actor = this.context.ecx;
            this.sample = human.updates <= 130 && this.actor.add(4).readS32() === 4969;
            if (this.sample) guardObservation(() => observed('observer-villager',villagerValue(this.actor,'enter')));
        },
        onLeave() {
            if (this.sample) guardObservation(() => observed('observer-villager',villagerValue(this.actor,'leave')));
        }
    });
}
function actionValue(list,depth) {
    if (list.isNull()) return null;
    const node = list.add(8).readPointer();
    if (node.isNull()) return null;
    if (depth >= 8) throw new Error('Action nesting exceeds diagnostic limit');
    const action = node.readPointer();
    return {type:action.add(4).readS16(),state:action.add(12).readU8(),target:action.add(24).readS32(),
        x:floatValue(action.add(32)),y:floatValue(action.add(36)),timer:floatValue(action.add(44)),
        sub:actionValue(action.add(52).readPointer(),depth+1)};
}
function villagerValue(actor,phase) {
    const master = actor.add(8).readPointer(), sprite = actor.add(16).readPointer();
    return {phase,actor:objectValue(actor),speed:floatValue(actor.add(136)),
        master_speed:floatValue(master.add(184)),
        sprite:sprite.isNull() ? null : {id:sprite.add(114).readS16(),speed:floatValue(sprite.add(100))},
        velocity:[floatValue(actor.add(144)),floatValue(actor.add(148))],
        action:actionValue(actor.add(388).readPointer(),0)};
}
send({kind:'observer-ready',schema:1,scope:cfg.human.rng_only ? 'Full debug RNG only' :
    cfg.human.combat ? 'Full RNG and clocks; attack updates 45-125; sprite additions 95-130; villager 4969 updates 0-130' :
    'Full debug RNG, registration/removal, world counters, minimap picks, and camera arguments'});
