// Feature-lab control v1. Calls advance one millisecond; idle boundaries add twenty.
// Native timers and queued paints cannot select simulation boundaries.
const labControl = {turn:0, calls:0, updates:0, lastFrame:-50, stopped:false, loadedTurn:null};
let labForceFrame = false, labFinished = false;
function humanClock() { labControl.calls++; return (++ticks) >>> 0; }
function humanFrameDue() { return !labControl.stopped && (labForceFrame || ticks-1000-labControl.lastFrame >= 50); }
function humanNativeFrames() {} // This profile does not open native edit controls.
function humanAfterFrame() {
    labControl.lastFrame = ticks-1000;
    labForceFrame = false;
    if (labFinished) labStop(null);
}
const labUser = Process.getModuleByName('user32.dll');
const labValidate = new NativeFunction(labUser.getExportByName('ValidateRect'),'int',['pointer','pointer'],'stdcall');
const labPaint = new NativeFunction(labUser.getExportByName('SendMessageA'),'int',['pointer','uint','pointer','pointer'],'stdcall');
const labInputs = new Map();
for (const name of ['GetKeyState','GetAsyncKeyState','GetCursorPos']) {
    const callback = name === 'GetCursorPos' ? new NativeCallback(point => {
        point.writeS32(320); point.add(4).writeS32(240); return 1;
    },'int',['pointer'],'stdcall') : new NativeCallback(() => 0,'int16',['int'],'stdcall');
    labInputs.set(name,callback);
}
let labInputsBound=false;
function bindFeatureInputs() {
    if (labInputsBound) return;
    // Bind after graphics initialization. The wrapper can replace these imports.
    for (const [name,callback] of labInputs) {
        const slot=base.add(cfg.inputIAT[name]),protection=Process.findRangeByAddress(slot).protection;
        if (!Memory.protect(slot,4,'rw-')) throw new Error('Cannot bind laboratory input');
        slot.writePointer(callback);
        if (!Memory.protect(slot,4,protection)) throw new Error('Cannot restore input protection');
    }
    labInputsBound=true;
}
for (const name of ['DispatchMessageA','DispatchMessageW']) Interceptor.attach(labUser.getExportByName(name), {
    onEnter(args) {
        if (!gameWindow || this.threadId !== gameThread) return;
        const msg=args[0], code=msg.add(4).readU32();
        const ownedWake=cfg.lab.mode==='generate' && [1,2].includes(labPhase) &&
            msg.readPointer().equals(gameWindow) && msg.add(8).readU32()===0x464c4142;
        if (code===0x113 && !ownedWake) msg.add(4).writeU32(0);
        if (code===0xf && msg.readPointer().equals(gameWindow)) {
            if (!labValidate(gameWindow,NULL)) throw new Error('Cannot acknowledge queued paint');
            msg.add(4).writeU32(0);
        }
    }
});
const labOldStatus = rpc.exports.status;
rpc.exports.status = function() {
    const status=labOldStatus();
    delete status.rngTrace; // The worker stores the complete binary RNG stream.
    return {...status,lab:{...labControl,phase:labPhase,clockSites:[...labClockCounts]}};
};
const labChaos = typeof labChaosTour === 'function';
const labTour = labChaos ? labChaosTour() : [
    ['food',18,198], ['mining-and-wood',46,198], ['construction-and-repair',45,222],
    ['melee-and-archery',80,187], ['cavalry-and-siege',110,187], ['siege-and-elephants',92,210],
    ['conversion',153,189], ['healing',170,186], ['conversion-south',153,214],
    ['fishing',201,186], ['naval-combat',215,207], ['trade-and-transport',190,219],
];
if (!labChaos) for (let p=1;p<=8;p++) {
    const x=((p-1)%4)*60,y=Math.floor((p-1)/4)*82;
    for (const dy of [10,21,32,43,54,69]) for (const dx of [10,21,32,43,54])
        labTour.push(['catalog-'+p+'-'+dx+'-'+dy,x+dx,y+dy]);
}
if (!labChaos) for (let x=12;x<240;x+=12) labTour.push(['nature-'+x,x,167]);
if (!labChaos) for (let x=140;x<=176;x+=12) labTour.push(['terrain-'+x,x,230]);
let labTourIndex=-1;
let labUnloaded=false,labReboarded=false,labBlockedUnload=false;
function replayFeatureStep(game) {
    if (labPhase===0 && currentPanelName()==='Main Menu' && labControl.turn>=5) {
        labPhase=1;
        if (!labAPI.load(game,Memory.allocUtf8String('feature_lab.gmx'))) throw new Error('Reference load failed');
        labWorld=labAPI.player(game).add(60).readPointer();
        labControl.loadedTurn=labControl.turn;
        send({kind:'lab-loaded',turn:labControl.turn,ticks,calls:labControl.calls});
        sampleFeatureState('loaded');
    }
    if (labPhase!==1) return;
    const playTurn=labControl.turn-labControl.loadedTurn;
    const activityTurns=Math.min(360,Math.floor(cfg.lab.turns/2));
    // The transport view gets nine intervals: unloading, boarding, then a blocked shore.
    const index=labChaos?Math.min(labTour.length-1,Math.floor(playTurn*labTour.length/cfg.lab.turns)):
        playTurn<activityTurns?Math.min(11,Math.floor(playTurn*20/activityTurns)):
        Math.min(labTour.length-1,12+Math.floor((playTurn-activityTurns)*(labTour.length-12)/(cfg.lab.turns-activityTurns)));
    if (index!==labTourIndex) {
        labTourIndex=index;
        const [name,x,y]=labTour[index];
        labAPI.camera(labAPI.player(game),x,y);
        labAPI.redraw(base.add(cfg.panelSystem.rva).add(12).readPointer(),1);
        labForceFrame=true;
        send({kind:'lab-tour',name,x,y,turn:labControl.turn,ticks});
    }
    const unloadTurn=Math.floor(activityTurns*11/20)+5;
    if (!labChaos && !labUnloaded && playTurn>=unloadTurn) {
        const transport=live('transport'),list=Memory.alloc(4);
        list.writePointer(transport);
        labAPI.unload(labWorld.add(88).readPointer(),list,1,187,211);
        labUnloaded=true;
        send({kind:'lab-command',command:'unload',object:transport.add(4).readS32(),x:187,y:211,turn:labControl.turn,ticks});
    }
    if (!labChaos && !labReboarded && playTurn>=unloadTurn+55) {
        const passenger=live('passenger'),transport=live('transport'),list=Memory.alloc(4);
        list.writePointer(passenger);
        labAPI.work(labWorld.add(88).readPointer(),list,1,transport,
            transport.add(56).readFloat(),transport.add(60).readFloat());
        labReboarded=true;
        send({kind:'lab-command',command:'board-again',object:passenger.add(4).readS32(),
            target:transport.add(4).readS32(),turn:labControl.turn,ticks});
    }
    if (!labChaos && !labBlockedUnload && playTurn>=unloadTurn+80) {
        const transport=live('transport'),list=Memory.alloc(4);
        list.writePointer(transport);
        labAPI.unload(labWorld.add(88).readPointer(),list,1,187,218);
        labBlockedUnload=true;
        send({kind:'lab-command',command:'unload-blocked-shore',object:transport.add(4).readS32(),
            x:187,y:218,turn:labControl.turn,ticks});
    }
    if (playTurn>=cfg.lab.turns) {
        sampleFeatureState('terminal');
        labFinished=true;
        labForceFrame=true;
    }
}
