// Chaos start: start a normal random-map game, add an engine-placed army near every
// town centre, then write an ordinary save with the game's own save function.
// Runs after menu.js and offline.js. Original executable only.
const chaos = cfg.chaos;
function chaosCall(name, result, args) {
    return new NativeFunction(target('probe_' + name), result, ['pointer', ...args], {abi:'thiscall', traps:'all'});
}
const chaosAPI = {
    numberPlayers: chaosCall('number_players', 'void', ['int']),
    difficulty: chaosCall('difficulty', 'void', ['int']),
    mapSize: chaosCall('map_size', 'void', ['int']),
    mapType: chaosCall('map_type', 'void', ['int']),
    resourceLevel: chaosCall('resource_level', 'void', ['int']),
    startingAge: chaosCall('starting_age', 'void', ['int']),
    civilization: chaosCall('civilization', 'void', ['int', 'int']),
    color: chaosCall('player_color', 'void', ['int', 'int']),
    team: chaosCall('player_team', 'void', ['int', 'int']),
    humanity: chaosCall('humanity', 'void', ['uint', 'int']),
    startGame: chaosCall('start_setup', 'int', []),
    player: chaosCall('get_player', 'pointer', []),
    attribute: chaosCall('set_attribute', 'void', ['int16', 'float']),
    placement: chaosCall('placement', 'uint8', ['pointer','float','float','pointer','uint8','uint8','uint8','uint8','uint8','uint8']),
    create: chaosCall('create', 'pointer', ['int', 'float', 'float', 'float', 'int']),
    save: chaosCall('save_game', 'int', ['pointer']),
    load: chaosCall('load_game', 'int', ['pointer']),
    camera: chaosCall('camera', 'void', ['float', 'float']),
    redraw: chaosCall('redraw', 'void', ['int']),
    setRelation: chaosCall('set_relation', 'void', ['int', 'uint8']),
    relation: chaosCall('relation', 'uint8', ['int']),
    setAlliedVictory: chaosCall('set_allied_victory', 'void', ['uint8']),
    alliedVictory: chaosCall('allied_victory', 'uint8', []),
    setChangeable: chaosCall('set_changeable', 'void', ['int', 'uint8']),
    changeable: chaosCall('changeable', 'int', ['int']),
};
const ME_HUMAN = 2, ME_COMPUTER = 4, RELATION_ENEMY = 3;
// Combat classes: archer, infantry, cavalry, siege, priest, chariot archer, elephant,
// elephant archer, phalanx, chariot, horse archer, slinger. Heroes and boats are left out.
const CHAOS_GROUPS = [0, 6, 12, 13, 18, 23, 24, 26, 28, 35, 36, 39];
let chaosSeed = chaos.seed >>> 0;
function chaosRandom() { chaosSeed = (chaosSeed*1664525 + 1013904223) >>> 0; return chaosSeed/4294967296; }
function chaosPick(rows) { return rows[Math.floor(chaosRandom()*rows.length)]; }
let chaosPhase = 0, chaosTurns = 0, chaosUpdates = 0, chaosInjectedAt = 0, chaosBusy = false;
let chaosGame = null, chaosWorld = null, chaosLoadedAt = 0, chaosFrames = 0;
const chaosSummary = {players: []};
function chaosProgress(phase, fields = {}) { send({kind:'chaos-progress', phase, ...fields}); }
function chaosPlayer(id) { return chaosWorld.add(64).readPointer().add(id*4).readPointer(); }
function chaosCatalog(player) {
    const n = player.add(34).readS16(), array = player.add(36).readPointer(), rows = [];
    for (let i = 0; i < n; i++) {
        const master = array.add(i*4).readPointer();
        if (master.isNull()) continue;
        const name = master.add(8).readPointer();
        rows.push({index:i, name:name.isNull() ? '' : name.readCString(), type:master.add(4).readU8(),
                   group:master.add(20).readS16(), hidden:master.add(78).readU8()});
    }
    return rows;
}
function chaosLiveCount() {
    const array = chaosWorld.add(136).readPointer(), count = chaosWorld.add(144).readS32();
    let live = 0;
    for (let i = 0; i < count; i++) if (!array.add(i*4).readPointer().isNull()) live++;
    return live;
}
function chaosObjects() {
    const array = chaosWorld.add(136).readPointer(), count = chaosWorld.add(144).readS32(), rows = [];
    for (let i = 0; i < count; i++) {
        const object = array.add(i*4).readPointer();
        if (object.isNull()) continue;
        const name = object.add(8).readPointer().add(8).readPointer();
        rows.push({owner:object.add(12).readPointer().add(74).readS16(), name:name.isNull() ? '' : name.readCString(),
                   x:object.add(56).readFloat(), y:object.add(60).readFloat()});
    }
    return rows;
}
function chaosTryPlace(owner, master, x, y) {
    const size = chaosWorld.add(40).readPointer().add(8).readS32();
    if (x < 2 || y < 2 || x > size-3 || y > size-3) return false;
    const player = chaosPlayer(owner), prototype = player.add(36).readPointer().add(master*4).readPointer();
    const blocker = Memory.alloc(4); blocker.writeS32(-1);
    // The engine's own placement check decides; a rejected cell stays empty.
    if (chaosAPI.placement(prototype, player, x, y, blocker, 0, 1, 1, 0, 0, 1)) return false;
    return !chaosAPI.create(player, master, x, y, 0, 1).isNull();
}
function chaosConfigure(screen) {
    const game = chaosGame;
    chaosAPI.numberPlayers(game, 8);
    chaosAPI.mapSize(game, chaos.map_size);
    chaosAPI.mapType(game, chaos.map_type);
    chaosAPI.resourceLevel(game, chaos.resource_level);
    chaosAPI.startingAge(game, chaos.starting_age);
    chaosAPI.difficulty(game, chaos.difficulty);
    const comm = base.add(chaos.comm_rva).readPointer();
    if (comm.isNull()) throw new Error('Communications handler is missing');
    const civilizations = [];
    for (let i = 0; i < 8; i++) {
        const civilization = 1 + Math.floor(chaosRandom()*chaos.civilizations);
        civilizations.push(civilization);
        chaosAPI.civilization(game, i, civilization);
        chaosAPI.color(game, i, i+1);
        chaosAPI.team(game, i, 1);
        chaosAPI.humanity(comm, i+1, i === 0 ? ME_HUMAN : ME_COMPUTER);
    }
    chaosSummary.civilizations = civilizations;
    chaosProgress('configured', {civilizations});
    if (!chaosAPI.startGame(screen)) throw new Error('The setup screen refused to start the game');
}
// Without teams, world.cpp starts every computer player all-neutral. About ten seconds in,
// TribeMainDecisionAIModule::update allies every still-neutral computer against the human.
// Mutual enmity from the start leaves no neutral computer to recruit. Each update the tactical
// AI (taitacmd.cpp) also drifts toward neutral or ally with anyone it does not hate most, but
// only where its diplomacy module marks the stance changeable. Locking every stance makes the
// free-for-all hold. Being attacked still sets enemy, which it already is.
function chaosDiplomacyModule(player) {
    const ai = player.add(0x238).readPointer();  // TRIBE_Player::playerAI
    return ai.isNull() ? null : ai.add(0x9dc);     // TribeMainDecisionAIModule::diplomacyAI
}
function chaosFreeForAll() {
    for (let p = 1; p <= 8; p++) {
        const player = chaosPlayer(p), diplomacy = chaosDiplomacyModule(player);
        chaosAPI.setAlliedVictory(player, 0);
        for (let q = 1; q <= 8; q++) {
            if (q === p) continue;
            chaosAPI.setRelation(player, q, RELATION_ENEMY);
            if (diplomacy) chaosAPI.setChangeable(diplomacy, q, 0);
        }
    }
}
function chaosDiplomacy() {
    const relations = [];
    for (let p = 1; p <= 8; p++) {
        const player = chaosPlayer(p), diplomacy = chaosDiplomacyModule(player), row = [], changeable = [];
        for (let q = 1; q <= 8; q++) {
            row.push(chaosAPI.relation(player, q));
            changeable.push(diplomacy ? chaosAPI.changeable(diplomacy, q) : null);
        }
        relations.push({player:p, relations:row, changeable, computer:!!diplomacy,
                        allied_victory:chaosAPI.alliedVictory(player)});
    }
    return relations;
}
function chaosPopulate() {
    if (chaos.diplomacy === 'ffa') chaosFreeForAll();
    chaosSummary.diplomacy_at_start = chaosDiplomacy();
    const objects = chaosObjects();
    for (let p = 1; p <= 8; p++) {
        const player = chaosPlayer(p), catalog = chaosCatalog(player);
        const combat = catalog.filter(row => row.type === 70 && !row.hidden && CHAOS_GROUPS.includes(row.group) &&
            (/^Soldier/.test(row.name) || row.name === 'Priest')).map(row => row.index);
        const villager = catalog.find(row => row.name === 'Man');
        const centre = objects.find(row => row.owner === p && /^Town_Center/i.test(row.name));
        if (!combat.length || !villager || !centre) throw new Error('Player ' + p + ' has no town centre or catalog');
        for (let a = 0; a < 4; a++) chaosAPI.attribute(player, a, chaos.resources);
        chaosAPI.attribute(player, 32, chaos.pop_limit);
        // Top villagers up to the requested count, in a ring around the town centre.
        let villagers = objects.filter(row => row.owner === p && row.name === 'Man').length, tries = 0;
        const startVillagers = villagers;
        while (villagers < chaos.villagers && tries++ < 400) {
            const angle = chaosRandom()*2*Math.PI, radius = 3 + chaosRandom()*4;
            if (chaosTryPlace(p, villager.index, centre.x + radius*Math.cos(angle), centre.y + radius*Math.sin(angle)))
                villagers++;
        }
        // One block formation at a random bearing; a new block starts when terrain fills the first.
        let placed = 0, blocks = 0;
        const kinds = {};
        while (placed < chaos.units && blocks < 8) {
            blocks++;
            const angle = chaosRandom()*2*Math.PI, distance = chaos.distance + chaosRandom()*4;
            const cx = centre.x + distance*Math.cos(angle), cy = centre.y + distance*Math.sin(angle);
            if (p === 1 && blocks === 1) chaosSummary.first_army = [cx, cy];
            const columns = Math.ceil(Math.sqrt(chaos.units - placed));
            for (let row = 0; placed < chaos.units && row < columns*3; row++) {
                for (let column = 0; placed < chaos.units && column < columns; column++) {
                    const master = chaosPick(combat);
                    const x = cx + (column - columns/2)*chaos.spacing, y = cy + (row - columns/2)*chaos.spacing;
                    if (chaosTryPlace(p, master, x, y)) {
                        placed++;
                        const name = catalog.find(r => r.index === master).name;
                        kinds[name] = (kinds[name] || 0) + 1;
                    }
                }
            }
        }
        const row = {player:p, civilization:player.add(0x105).readU8(), town_centre:[centre.x, centre.y],
                     villagers_before:startVillagers, villagers, army:placed, blocks, kinds};
        chaosSummary.players.push(row);
        chaosProgress('player-populated', row);
    }
}
Interceptor.attach(target('probe_world_update'), {onLeave() { chaosUpdates++; }});
Interceptor.attach(target('idle'), {
    onEnter() {
        if (gameWindow && this.threadId === gameThread) ticks += 20;
        this.game = this.context.ecx;
    },
    onLeave() {
        if (chaosBusy || !gameWindow || this.threadId !== gameThread) return;
        chaosBusy = true;
        try {
            chaosGame = this.game;
            chaosTurns++;
            const panel = currentPanelName();
            if (chaosPhase === 0 && panel === 'MP Setup Screen' && chaosTurns > 5) {
                chaosPhase = 1;
                chaosConfigure(base.add(cfg.panelSystem.rva).add(12).readPointer());
            } else if (chaosPhase === 1 && panel === 'Game Screen' && chaosUpdates >= 1) {
                chaosPhase = 2;
                chaosWorld = chaosAPI.player(chaosGame).add(60).readPointer();
                chaosSummary.map_size = chaosWorld.add(40).readPointer().add(8).readS32();
                chaosSummary.objects_before = chaosLiveCount();
                chaosPopulate();
                chaosSummary.objects_after = chaosLiveCount();
                chaosInjectedAt = chaosUpdates;
                chaosProgress('populated', {updates:chaosUpdates, objects:chaosSummary.objects_after});
            } else if (chaosPhase === 2 && chaosUpdates >= chaosInjectedAt + chaos.settle_updates) {
                chaosPhase = 3;
                if (!chaosAPI.save(chaosGame, Memory.allocUtf8String(chaos.save_name)))
                    throw new Error('Save failed');
                chaosSummary.saved_at_update = chaosUpdates;
                chaosProgress('saved', {updates:chaosUpdates});
                // Load the written save the normal way; this proves the file is playable.
                if (!chaosAPI.load(chaosGame, Memory.allocUtf8String(chaos.save_name)))
                    throw new Error('The written save did not load');
                chaosPhase = 4;
            } else if (chaosPhase === 4 && panel === 'Game Screen') {
                chaosPhase = 5;
                chaosWorld = chaosAPI.player(chaosGame).add(60).readPointer();
                chaosLoadedAt = chaosUpdates;
                chaosSummary.objects_loaded = chaosLiveCount();
                chaosProgress('loaded', {objects:chaosSummary.objects_loaded});
            } else if (chaosPhase === 5 && chaosUpdates >= chaosLoadedAt + chaos.view_updates &&
                       chaosWorld.add(4).readU32() > chaos.diplomacy_check_ms) {
                chaosPhase = 6;
                // Read diplomacy after the computer players' initial-diplomacy decision time.
                chaosSummary.diplomacy_checked_at_ms = chaosWorld.add(4).readU32();
                chaosSummary.diplomacy_after_load = chaosDiplomacy();
                // The army may already be moving; look at where it is now.
                const army = chaosObjects().filter(row => row.owner === 1 && (/^Soldier/.test(row.name) || row.name === 'Priest'));
                const x = army.reduce((sum, row) => sum + row.x, 0)/army.length;
                const y = army.reduce((sum, row) => sum + row.y, 0)/army.length;
                chaosSummary.first_army_loaded = {units:army.length, centre:[x, y],
                    spread:Math.max(...army.map(row => Math.hypot(row.x - x, row.y - y)))};
                chaosAPI.camera(chaosAPI.player(chaosGame), x, y);
                chaosAPI.redraw(base.add(cfg.panelSystem.rva).add(12).readPointer(), 1);
                cfg.maxFrames = count + 3; // menu.js sends frames up to this paint count.
            } else if (chaosPhase === 6 && count > cfg.maxFrames) {
                chaosPhase = 7;
                chaosSummary.loaded_updates = chaosUpdates - chaosLoadedAt;
                send({kind:'chaos-done', summary:chaosSummary});
            }
        } catch (error) {
            chaosPhase = 99;
            send({kind:'chaos-error', error:String(error.stack || error)});
        } finally { chaosBusy = false; }
    }
});
