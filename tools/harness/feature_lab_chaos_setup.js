// Chaos layout: eight home bases with villager economies, and one large central battle.
// The harness calls buildFeatureMap() and issueFeatureOrders(), so this file keeps those
// names. The placed list and the order list are part of the fixture it writes.
const labPlaced = cfg.lab.mode==='replay'?cfg.lab.setup.placed.map(row=>({...row})):[];
const labOrders = [], labDefinitions = new Map();
// Homes sit in a ring. The square between them belongs to the battle.
const CHAOS_HOMES = [[30,30],[120,26],[210,30],[26,120],[214,120],[30,210],[120,214],[210,210]];
const CHAOS_CENTER = [72,72,168,168];
const CHAOS_VILLAGERS = 10, CHAOS_RAIDERS = 4, CHAOS_FIGHTERS = 150, CHAOS_TRIES = 60;
const CHAOS_NODES = [['berries', /^Forage-Fruit$/i], ['wood', /^Tree[0-9][0-9]$/i],
                     ['gold', /^Mine-Gold$/i], ['stone', /^Mine-Stone$/i], ['hunt', /^Gazelle$/i]];
// A local generator keeps a regenerated map reproducible. The fixture pins the result.
let labChaosSeed = (cfg.generator.seed ^ 0x5f3759df) >>> 0;
function chaosRandom() { labChaosSeed = (labChaosSeed*1664525 + 1013904223) >>> 0; return labChaosSeed/4294967296; }
function chaosPick(rows) {
    if (!rows.length) throw new Error('Empty choice list');
    return rows[Math.floor(chaosRandom()*rows.length)];
}
function chaosNumber(low, high) { return low + chaosRandom()*(high-low); }
function definition(owner, id) {
    const row = labDefinitions.get(owner).find(row => row.index === id);
    if (!row) throw new Error('Missing master ' + owner + ':' + id);
    return row;
}
function catalogMatch(owner, pattern, type) {
    const rows = labDefinitions.get(owner).filter(row => !row.hidden && row.type === type &&
        pattern.test(row.name || ''));
    if (!rows.length) throw new Error('Missing catalog entry for player ' + owner + ': ' + pattern);
    return rows[0].index;
}
function tryPlace(label, owner, master, x, y) {
    const def = definition(owner, master);
    if (labPlaced.some(row => row.label === label)) throw new Error('Duplicate object label: ' + label);
    if (x-def.radius[0] < 1 || y-def.radius[1] < 1 ||
        x+def.radius[0] >= cfg.generator.size-1 || y+def.radius[1] >= cfg.generator.size-1) return false;
    const player=labPlayer(owner),prototype=player.add(36).readPointer().add(master*4).readPointer();
    const blocker=Memory.alloc(4);blocker.writeS32(-1);
    if (labAPI.placement(prototype,player,x,y,blocker,0,1,1,0,0,1)) return false;
    const object = labAPI.create(labPlayer(owner), master, x, y, 0, 1);
    if (object.isNull()) return false;
    if (object.add(8).readPointer().add(16).readS16() !== def.id ||
        object.add(12).readPointer().add(74).readS16() !== owner)
        throw new Error('Created object identity differs: ' + label);
    labPlaced.push({label,owner,master:def.id,definition:master,id:object.add(4).readS32(),x,y});
    return true;
}
function placeAt(label, owner, master, x, y) {
    if (!tryPlace(label, owner, master, x, y))
        throw new Error('Placement rejected: '+label+' owner='+owner+' master='+master+' at '+x+','+y);
}
// Units are mobile, so a random tile can be taken. Try again instead of failing the map.
function scatter(label, owner, master, x0, y0, x1, y1, tries = CHAOS_TRIES) {
    for (let attempt=0; attempt<tries; attempt++) {
        const x = chaosNumber(x0, x1), y = chaosNumber(y0, y1);
        if (tryPlace(label, owner, master, x, y)) return labPlaced[labPlaced.length-1];
    }
    throw new Error('No free tile for ' + label);
}
function live(label) {
    const row = labPlaced.find(row => row.label === label);
    if (!row || row.id < 0 || row.id >= labWorld.add(144).readS32()) throw new Error('Invalid setup object: ' + label);
    const object = labWorld.add(136).readPointer().add(row.id*4).readPointer();
    if (object.isNull() || object.add(4).readS32() !== row.id) throw new Error('Setup object no longer exists: ' + label);
    return object;
}
function order(kind, actor, target, extra = {}) { labOrders.push({kind,actor,target,...extra}); }
function gaiaID(pattern) {
    const choices = labDefinitions.get(0).filter(row => !row.hidden && pattern.test(row.name || ''));
    if (!choices.length) throw new Error('Missing Gaia definition: ' + pattern);
    return choices[0].index;
}
function labChaosTour() {
    const plan = [];
    for (const [x,y] of CHAOS_HOMES) plan.push(['home', x, y]);
    for (let row=0;row<3;row++) for (let column=0;column<3;column++)
        plan.push(['battle', 88+column*32, 88+row*32]);
    return plan;
}
function buildFeatureMap() {
    const size = labWorld.add(40).readPointer().add(8).readS32();
    if (size !== cfg.generator.size || labWorld.add(60).readS16() !== 9)
        throw new Error('Map initialization differs from the setup request');
    for (let p=1;p<=8;p++) {
        const player=labPlayer(p),civilization=player.add(0x105).readU8(),effect=player.add(0x10c).readS32();
        if (civilization!==p+cfg.generator.civilization_offset || effect<0)
            throw new Error('Civilization initialization differs');
        // Editor initialization omits this normal scenario-load step.
        labAPI.civilizationEffect(labWorld.add(0x4c).readPointer(),effect,player);
        send({kind:'lab-civilization',player:p,civilization,effect});
    }
    for (let p=0;p<9;p++) {
        const rows = labCatalog(labPlayer(p));
        labDefinitions.set(p,rows);
        send({kind:'lab-catalog',player:p,objects:rows});
    }
    const map = labWorld.add(40).readPointer();
    labAPI.mapVisible(map,1);
    labAPI.mapFog(map,0);
    for (let p=1;p<=8;p++) {
        // Every player is hostile. The centre fights on its own.
        for (let q=1;q<=8;q++) labAPI.relation(labPlayer(p),q,p === q ? 0 : 3);
        for (let a=0;a<4;a++) labAPI.attribute(labPlayer(p),a,10000,0);
        labAPI.visible(labPlayer(p));
    }
    const villagers = new Map(), homes = new Map(), fighters = new Map();
    const combatCatalog = new Map();
    for (let p=1;p<=8;p++) {
        const combat = labDefinitions.get(p).filter(row => !row.hidden && row.type === 70 &&
            ![1,2,4,18,20,21,22].includes(row.group)).map(row => row.index);
        if (!combat.length) throw new Error('No combat catalog for player ' + p);
        combatCatalog.set(p, combat);
    }
    for (let p=1;p<=8;p++) {
        const [cx,cy] = CHAOS_HOMES[p-1];
        const x0 = cx-16, y0 = cy-16, x1 = cx+16, y1 = cy+16;
        placeAt('home-tc-'+p, p, catalogMatch(p, /^Town_Center/i, 80), cx, cy);
        // Each home gets its own nodes, so villagers walk a short distance.
        const nodes = [];
        for (const [name,pattern] of CHAOS_NODES) {
            const master = gaiaID(pattern);
            for (let i=0;i<3;i++) {
                const node = scatter(name+'-'+p+'-'+i, 0, master, x0, y0, x1, y1);
                nodes.push({name, label:node.label});
            }
        }
        const villagerMaster = catalogMatch(p, /^Man$/i, 70);
        const homeVillagers = [];
        for (let i=0;i<CHAOS_VILLAGERS;i++) {
            // The label names the resource the worker collects. Coverage reads it.
            const node = chaosPick(nodes);
            const row = scatter(node.name+'-worker-'+p+'-'+i, p, villagerMaster, x0, y0, x1, y1);
            order('work', row.label, node.label);
            homeVillagers.push(row.label);
        }
        villagers.set(p, homeVillagers);
        const combat = combatCatalog.get(p);
        // One unit of this home civilization defends it.
        const defender = scatter('guard-'+p+'-own', p, chaosPick(combat), x0, y0, x1, y1).label;
        // A random few intruders of other civilizations stand inside the same home.
        const raiders = [];
        for (let i=0;i<CHAOS_RAIDERS;i++) {
            const enemy = 1 + Math.floor(chaosRandom()*8);
            if (enemy === p) continue;
            raiders.push(scatter('raider-'+p+'-'+enemy+'-'+i, enemy, chaosPick(combatCatalog.get(enemy)),
                x0, y0, x1, y1).label);
        }
        homes.set(p, {defender, raiders, villagers:homeVillagers});
        const list = [];
        const [bx0,by0,bx1,by1] = CHAOS_CENTER;
        for (let i=0;i<CHAOS_FIGHTERS;i++) {
            const master = chaosPick(combat);
            const unit = scatter('combat-'+p+'-'+master+'-'+i, p, master, bx0, by0, bx1, by1);
            list.push(unit.label);
        }
        fighters.set(p, list);
        progress('home-built', {player:p, villagers:CHAOS_VILLAGERS, fighters:list.length,
            nodes:nodes.length, placed:labPlaced.length});
    }
    // Send every fighter at a random enemy. That keeps the centre moving.
    for (const [p, list] of fighters) {
        const enemies = [...fighters.keys()].filter(other => other !== p)
            .flatMap(other => fighters.get(other));
        for (const label of list) order('work', label, chaosPick(enemies));
    }
    // Guards walk out and raid the other homes. That is the villager skirmish.
    for (const [, home] of homes) {
        if (!home.raiders.length) continue;
        order('work', home.defender, chaosPick(home.raiders));
        // Half the intruders fight the defender. The rest raid the villagers.
        home.raiders.forEach((label, i) => {
            order('work', label, i % 2 ? chaosPick(home.villagers) : home.defender);
        });
    }
    progress('populated', {objects:labPlaced.length,orders:labOrders.length});
}
function issueFeatureOrders() {
    const commands = labWorld.add(88).readPointer();
    for (const order of labOrders) {
        const actor = live(order.actor), list = Memory.alloc(4);
        list.writePointer(actor);
        if (order.kind === 'work') {
            const target = live(order.target);
            labAPI.work(commands,list,1,target,target.add(56).readFloat(),target.add(60).readFloat());
        } else throw new Error('Unsupported setup order: ' + order.kind);
    }
}
