// Dedicated setup profile. It is not an accepted human-input replay profile.
const labSleep = new NativeFunction(Process.getModuleByName('kernel32.dll').getExportByName('Sleep'),
    'void', ['uint'], 'stdcall');
function api(name, result, args) {
    if (!cfg['probe_'+name]) return null; // Setup-only methods can be removed by the rebuilt linker.
    return new NativeFunction(target('probe_' + name), result, ['pointer', ...args], {abi:'thiscall', traps:'all'});
}
const labAPI = {
    editor: api('editor', 'int', ['pointer', 'int']),
    editorQuit: api('editor_quit', 'void', []),
    newMap: api('new_map', 'int', ['pointer', 'int', 'int', 'int', 'int', 'int']),
    player: api('get_player', 'pointer', []),
    create: api('create', 'pointer', ['int', 'float', 'float', 'float', 'int']),
    save: api('save', 'uint8', ['pointer']),
    load: api('load', 'int', ['pointer']),
    camera: api('camera', 'void', ['float', 'float']),
    relation: api('relation', 'void', ['int', 'uint8']),
    visible: api('visible', 'void', []),
    terrain: api('terrain', 'void', ['pointer', 'int16', 'int16', 'uint8', 'int', 'int']),
    work: api('work', 'void', ['pointer', 'int16', 'pointer', 'float', 'float']),
    mapVisible: api('map_visible', 'void', ['uint8']),
    mapFog: api('map_fog', 'void', ['uint8']),
    modify: api('modify_percent', 'void', ['float', 'uint8']),
    attribute: api('attribute', 'void', ['int16', 'float', 'uint8']),
    train: api('train', 'void', ['pointer', 'int16']),
    research: api('research', 'void', ['pointer', 'int16']),
    build: api('build', 'void', ['pointer', 'int16', 'int16', 'float', 'float']),
    unload: api('unload', 'void', ['pointer', 'int16', 'float', 'float']),
    saveScenario: api('save_scenario', 'uint8', ['pointer']),
    technology: api('technology', 'uint8', ['int16']),
    repair: api('repair', 'void', ['pointer', 'int16', 'pointer']),
    elevation: api('elevation', 'void', ['int16','int16','int16','int16','uint8','int16','uint8']),
    redraw: api('redraw', 'void', ['int']),
    civilizationEffect: api('civilization_effect', 'void', ['int16','pointer']),
    placement: api('placement', 'uint8', ['pointer','float','float','pointer','uint8','uint8','uint8','uint8','uint8','uint8']),
};
let labPhase = 0, labBusy = false, labGame = null, labWorld = null, labUpdates = 0;
if (cfg.lab.mode==='generate') Interceptor.attach(target('probe_cancel_build'),{onEnter(args){
    send({kind:'lab-build-cancelled',reason:args[0].toInt32(),blocker:args[1].toInt32(),
        master:args[2].toInt32(),builder:args[6].toInt32()});
}});
Interceptor.attach(target('probe_world_update'), {onLeave() { labUpdates++; }});
if (cfg.lab.mode==='generate') Interceptor.attach(target('probe_new_map'), {onEnter(args) {
    // Use the normal editor constructor. Its views must bind to the final world.
    args[2] = ptr(cfg.generator.seed);
    args[3] = ptr(cfg.generator.size);
    args[4] = ptr(cfg.generator.size);
}});
if (cfg.lab.mode==='generate') Interceptor.attach(target('probe_new_scenario'), {onEnter(args) {
    const info=args[0], offset=cfg.generator.civilization_offset;
    if (info.add(0x294).readS16()!==8 || this.context.ecx.add(68).readS16()<=8+offset)
        throw new Error('Scenario player or civilization count differs');
    // RGE_Player_Info in world_info.h: name[9][65], type[9], tribe[9].
    for (let p=0;p<8;p++) {
        info.add(0x252+p).writeU8(p+1+offset);
        info.add(p*65).writeUtf8String('Lab '+(p+1));
    }
}});
function progress(phase, fields = {}) { send({kind:'lab-progress', phase, ...fields}); }
function labStop(error) {
    if (labControl.stopped) return;
    labControl.stopped=true;
    flushFeatureRng();
    send({kind:'lab-draw-summary',calls:labDrawCalls,objects:[...labDrawn].sort((a,b)=>a-b)});
    send({kind:error ? 'lab-error' : 'lab-done', error:error || null, status:rpc.exports.status()});
    labSleep(0xffffffff);
}
function labPlayer(id) { return labWorld.add(64).readPointer().add(id*4).readPointer(); }
function labCatalog(player) {
    const n = player.add(34).readS16(), array = player.add(36).readPointer(), rows = [];
    if (n < 1 || n > 4096 || array.isNull()) throw new Error('Invalid master object array');
    for (let i = 0; i < n; i++) {
        const master = array.add(i*4).readPointer();
        if (master.isNull()) continue;
        const name = master.add(8).readPointer();
        rows.push({index:i, id:master.add(16).readS16(), name:name.isNull() ? null : name.readCString(),
            type:master.add(4).readU8(), group:master.add(20).readS16(),
            hidden:master.add(78).readU8(), available:master.add(82).readU8(),
            radius:[master.add(48).readFloat(),master.add(52).readFloat()],
            hp:master.add(38).readS16(), terrain:master.add(102).readS16()});
        rows[rows.length-1].tileRequirements=[84,86,88,90].map(offset=>master.add(offset).readS16());
    }
    return rows;
}
const labOriginalIdle = new NativeFunction(target('idle'),'int',['pointer'],'thiscall');
const labIdleCallback = new NativeCallback(function(game) {
        if (labBusy) return labOriginalIdle(game);
        labBusy = true;
        let result=0;
        try {
            if (gameWindow && Process.getCurrentThreadId()===gameThread) {
                bindFeatureInputs();
                labControl.turn++;
                ticks+=20;
            }
            result=labOriginalIdle(game);
            if (!gameWindow || Process.getCurrentThreadId()!==gameThread) return result;
            labGame = game;
            if (cfg.lab.mode==='replay') {
                replayFeatureStep(game);
            } else if (labPhase === 0 && currentPanelName() === 'Main Menu' && labControl.turn>=5) {
                labPhase++;
                progress('open-editor');
                if (!labAPI.editor(labGame, NULL, 0)) throw new Error('Editor initialization failed');
            } else if (labPhase === 1 && currentPanelName() === 'Scenario Editor Screen') {
                labPhase++;
                const player = labAPI.player(labGame);
                labWorld = player.add(60).readPointer();
                progress('world', {players:labWorld.add(60).readS16()});
                buildFeatureMap();
                labAPI.camera(labPlayer(1),24,192);
                if (!labAPI.save(labWorld,Memory.allocUtf8String('feature_lab.gmx')))
                    throw new Error('Save failed');
                progress('saved');
            } else if (labPhase === 2) {
                labPhase++;
                labAPI.editorQuit(base.add(cfg.panelSystem.rva).add(12).readPointer());
                progress('closed-editor', {panel:currentPanelName()});
            } else if (labPhase === 3 && currentPanelName() === 'Main Menu') {
                labPhase++;
                if (!labAPI.load(labGame,Memory.allocUtf8String('feature_lab.gmx')))
                    throw new Error('Load failed');
                progress('loaded', {panel:currentPanelName()});
            } else if (labPhase === 4 && currentPanelName() === 'Game Screen') {
                labPhase++;
                labWorld = labAPI.player(labGame).add(60).readPointer();
                issueFeatureOrders();
                progress('orders-issued', {updates:labUpdates});
            } else if (labPhase === 5 && labUpdates >= 12) {
                labPhase++;
                if (!labAPI.save(labWorld,Memory.allocUtf8String('feature_lab.gmx')))
                    throw new Error('Active save failed');
                send({kind:'lab-setup', layout:cfg.lab.layout, placed:labPlaced, orders:labOrders});
                progress('active-save', {updates:labUpdates});
                sampleFeatureState('saved');
                labFinished=true;
                labForceFrame=true;
            }
            labPaint(gameWindow,0xf,NULL,NULL);
            // Editor mode uses GetMessage, not the gameplay idle loop. Wake it
            // with one owned timer message; discard all native timer messages.
            if (cfg.lab.mode==='generate' && [1,2].includes(labPhase) &&
                !post(gameWindow,0x113,0x464c4142,0)) throw new Error('Cannot wake the editor');
        } catch (error) { labStop(String(error.stack || error)); }
        finally { labBusy = false; }
        return result;
},'int',['pointer'],'thiscall');
Interceptor.replace(target('idle'),labIdleCallback);
