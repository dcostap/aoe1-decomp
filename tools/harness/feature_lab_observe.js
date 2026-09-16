// Read defined fields only. Do not hash heap addresses, padding, or allocator state.
const labRngSites=new Map(), labRngRaw=new Map();
const labRngBuffer=new ArrayBuffer(4096*8), labRngView=new DataView(labRngBuffer);
let labRngUsed=0, labRngRecords=0;
const labClockSites=new Map(),labClockRawSites=new Map(),labClockCounts=[];
Interceptor.attach(target('clock'),{onEnter(args){
    const file=args[0],line=args[1].toInt32();
    const raw=file.toString()+':'+line;
    if (!labClockRawSites.has(raw)) {
        const site={file:file.readCString().replace(/\//g,'\\').toLowerCase(),line};
        const key=JSON.stringify(site);
        if (!labClockSites.has(key)) {
            const id=labClockSites.size;
            labClockSites.set(key,id); labClockCounts.push(0);
            send({kind:'lab-clock-site',id,site});
        }
        labClockRawSites.set(raw,labClockSites.get(key));
    }
    labClockCounts[labClockRawSites.get(raw)]++;
}});
const labDrawn=new Set();
let labDrawCalls=0;
Interceptor.attach(target('probe_draw_object'),{onEnter(){
    if (cfg.lab.mode!=='replay' || labPhase!==1) return;
    labDrawCalls++;
    labDrawn.add(this.context.ecx.add(4).readS32());
}});
function flushFeatureRng() {
    if (!labRngUsed) return;
    send({kind:'replay-rng-batch',records:labRngUsed},labRngBuffer.slice(0,labRngUsed*8));
    labRngUsed=0;
}
const labOriginalRng=rng;
rng=function(row) {
    labOriginalRng(row);
    const raw=row.kind+':'+row.file+':'+row.line;
    if (!labRngRaw.has(raw)) {
        const site={kind:row.kind,file:row.file.replace(/\//g,'\\').toLowerCase(),line:row.line};
        const key=JSON.stringify(site);
        if (!labRngSites.has(key)) {
            flushFeatureRng();
            const id=labRngSites.size;
            labRngSites.set(key,id);
            send({kind:'replay-rng-site',id,site});
        }
        labRngRaw.set(raw,labRngSites.get(key));
    }
    if (++labRngRecords>10000000) throw new Error('RNG observation limit exceeded');
    labRngView.setUint32(labRngUsed*8,labRngRaw.get(raw),true);
    labRngView.setUint32(labRngUsed*8+4,row.kind==='srand'?row.seed:row.value,true);
    if (++labRngUsed===4096) flushFeatureRng();
};
function objectID(object) { return object.isNull()?null:object.add(4).readS32(); }
function featureActions(list,depth=0) {
    if (list.isNull()) return [];
    if (depth>12) throw new Error('Action nesting exceeds the observation bound');
    const actions=[];
    for (let node=list.add(8).readPointer();!node.isNull();node=node.add(4).readPointer()) {
        if (actions.length>=128) throw new Error('Action list exceeds the observation bound');
        const action=node.readPointer();
        if (action.isNull()) throw new Error('Null action in a live action list');
        const type=action.add(4).readS16();
        actions.push({type,state:action.add(12).readU8(),
            target:objectID(action.add(16).readPointer()),target2:objectID(action.add(20).readPointer()),
            targetID:action.add(24).readS32(),target2ID:action.add(28).readS32(),
            position:[32,36,40].map(offset=>action.add(offset).readU32()),timer:action.add(44).readU32(),
            children:featureActions(action.add(52).readPointer(),depth+1),
            production:[102,103].includes(type)?[action.add(64).readS16(),action.add(68).readU32()]:null});
    }
    return actions;
}
function featureObject(object) {
    const master=object.add(8).readPointer(),type=master.add(4).readU8();
    return {id:object.add(4).readS32(),master:master.add(16).readS16(),type,
        owner:object.add(12).readPointer().add(74).readS16(),
        hp:object.add(48).readU32(),position:[56,60,64].map(offset=>object.add(offset).readU32()),
        held:object.add(68).readU32(),resource:object.add(76).readS16(),state:object.add(72).readU8(),
        facet:object.add(53).readU8(),inside:objectID(object.add(32).readPointer()),
        actions:[40,50,60,70,80].includes(type)?featureActions(object.add(388).readPointer()):[]};
}
function featureWorld() {
    return {time:labWorld.add(4).readU32(),delta:labWorld.add(12).readU32(),oldTime:labWorld.add(20).readU32(),
        speed:labWorld.add(24).readU32(),state:labWorld.add(29).readU8(),objects:labWorld.add(140).readS32(),
        negativeObjects:labWorld.add(152).readS32(),nextID:labWorld.add(104).readS32(),nextReusable:labWorld.add(108).readS32()};
}
function sampleFeatureState(phase) {
    const players=[],objects=[];
    for (let p=0;p<labWorld.add(60).readS16();p++) {
        const player=labPlayer(p), n=player.add(76).readS16(), attributes=player.add(80).readPointer();
        if (n<0 || n>1024) throw new Error('Invalid player attribute count');
        const tech=player.add(0x220).readPointer(), techCount=tech.add(4).readS16(), techRows=tech.readPointer();
        if (techCount<0 || techCount>4096) throw new Error('Invalid player technology count');
        players.push({id:p,computer:player.add(4).readS32(),attributes:Array.from({length:n},(_,i)=>attributes.add(i*4).readU32()),
            tech:Array.from({length:techCount},(_,i)=>[techRows.add(i*8).readU32(),techRows.add(i*8+4).readS16()])});
    }
    for (const offset of [136,148]) {
        const array=labWorld.add(offset).readPointer(),capacity=labWorld.add(offset+8).readS32();
        if (capacity<0 || capacity>100000) throw new Error('Invalid object array capacity');
        for (let i=0;i<capacity;i++) {
            const object=array.add(i*4).readPointer();
            if (!object.isNull()) objects.push(featureObject(object));
        }
    }
    objects.sort((a,b)=>a.id-b.id);
    send({kind:'lab-state',phase,turn:labControl.turn,updates:labControl.updates,ticks,calls:labControl.calls,
        rng:labRngRecords,clockSites:[...labClockCounts],world:featureWorld(),players,objects});
}
Interceptor.attach(target('probe_world_update'),{
    onEnter() {
        this.sample=labWorld && this.context.ecx.equals(labWorld) &&
            (cfg.lab.mode==='replay'?labPhase===1:labPhase===5);
        if (this.sample) send({kind:'lab-world',phase:'enter',turn:labControl.turn,updates:labControl.updates,
            ticks,calls:labControl.calls,rng:labRngRecords,clockSites:[...labClockCounts],world:featureWorld()});
    },
    onLeave() {
        if (!this.sample) return;
        try { labControl.updates++; sampleFeatureState('leave'); }
        catch(error) { labStop(String(error.stack||error)); }
    }
});
