// Edit this map-building code to add test areas. Native game methods own creation.
const labPlaced = cfg.lab.mode==='replay'?cfg.lab.setup.placed.map(row=>({...row})):[];
const labOrders = [], labDefinitions = new Map();
function definition(owner, id) {
    const row = labDefinitions.get(owner).find(row => row.index === id);
    if (!row) throw new Error('Missing master ' + owner + ':' + id);
    return row;
}
function place(label, owner, master, x, y, complete = 1) {
    if (labPlaced.some(row => row.label === label)) throw new Error('Duplicate object label: ' + label);
    const def = definition(owner,master);
    if (x-def.radius[0] < 1 || y-def.radius[1] < 1 ||
        x+def.radius[0] >= cfg.generator.size-1 || y+def.radius[1] >= cfg.generator.size-1)
        throw new Error('Placement exceeds map bounds: ' + label);
    const player=labPlayer(owner),prototype=player.add(36).readPointer().add(master*4).readPointer();
    const blocker=Memory.alloc(4);blocker.writeS32(-1);
    const placement=labAPI.placement(prototype,player,x,y,blocker,0,1,1,0,0,1);
    if (placement) throw new Error('Placement rejected: '+label+' code='+placement+' blocker='+blocker.readS32()+
        ' terrain='+def.terrain+' requirements='+JSON.stringify(def.tileRequirements));
    const object = labAPI.create(labPlayer(owner), master, x, y, 0, complete);
    if (object.isNull()) throw new Error('Creation failed: ' + label);
    const row = {label,owner,master:def.id,definition:master,id:object.add(4).readS32(),x,y};
    if (object.add(8).readPointer().add(16).readS16() !== def.id ||
        object.add(12).readPointer().add(74).readS16() !== owner)
        throw new Error('Created object identity differs: ' + label);
    labPlaced.push(row);
    return row;
}
function live(label) {
    const row = labPlaced.find(row => row.label === label);
    if (!row || row.id < 0 || row.id >= labWorld.add(144).readS32()) throw new Error('Invalid setup object: ' + label);
    const object = labWorld.add(136).readPointer().add(row.id*4).readPointer();
    if (object.isNull() || object.add(4).readS32() !== row.id) throw new Error('Setup object no longer exists: ' + label);
    return object;
}
function pond(x1,y1,x2,y2) {
    const map = labWorld.add(40).readPointer();
    for (let y=y1;y<=y2;y++) for (let x=x1;x<=x2;x++)
        labAPI.terrain(map,labWorld,x,y,1,0,0);
}
function order(kind, actor, target, extra = {}) { labOrders.push({kind,actor,target,...extra}); }
function gaiaID(pattern) {
    const choices = labDefinitions.get(0).filter(row => !row.hidden && pattern.test(row.name || ''));
    if (!choices.length) throw new Error('Missing Gaia definition: ' + pattern);
    return choices[0].index;
}
function buildFeatureMap() {
    const size = labWorld.add(40).readPointer().add(8).readS32();
    if (size !== cfg.generator.size || labWorld.add(60).readS16() !== 9)
        throw new Error('Map initialization differs from the setup request');
    // Keep all four ages represented. These are setup grants, not research coverage.
    for (let p=1;p<=8;p++) {
        const player=labPlayer(p),civilization=player.add(0x105).readU8(),effect=player.add(0x10c).readS32();
        if (civilization!==p+cfg.generator.civilization_offset || effect<0)
            throw new Error('Civilization initialization differs');
        // Editor initialization omits this normal scenario-load step.
        labAPI.civilizationEffect(labWorld.add(0x4c).readPointer(),effect,player);
        send({kind:'lab-civilization',player:p,civilization,effect});
        const age=[2,1,3,4][(p-1)%4], tech=player.add(0x220).readPointer();
        for (let a=1;a<age;a++) if (!labAPI.technology(tech,100+a)) throw new Error('Age setup failed');
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
        for (let q=1;q<=8;q++) labAPI.relation(labPlayer(p),q,p === q ? 0 : ((p===1&&q===5)||(p===5&&q===1) ? 3 : 0));
        for (let a=0;a<4;a++) labAPI.attribute(labPlayer(p),a,10000,0);
        labAPI.visible(labPlayer(p));
        const x0 = ((p-1)%4)*60, y0 = Math.floor((p-1)/4)*82;
        pond(x0+3,y0+63,x0+56,y0+76);
        for (let y=y0+67;y<=y0+72;y++) labAPI.terrain(map,labWorld,x0+57,y,2,0,0);
        let land=0, water=0;
        for (const def of labDefinitions.get(p)) {
            if (def.hidden || ![70,80].includes(def.type)) continue;
            const ship = [2,20,21,22].includes(def.group);
            let x,y;
            if (ship) { x=x0+6+(water%10)*5; y=y0+66+Math.floor(water/10)*5; water++; }
            else if (def.index === 45) { x=x0+56.5; y=y0+69.5; }
            else { x=x0+5+(land%10)*5.5; y=y0+6+Math.floor(land/10)*6; land++; }
            if (land > 90 || water > 20) throw new Error('Catalog exceeds its reserved area');
            place('catalog-'+p+'-'+def.index,p,def.index,x,y);
        }
    }
    const owned=new Set(labDefinitions.get(1).filter(row=>!row.hidden && [70,80].includes(row.type)).map(row=>row.index));
    let nature=0,shore=0;
    for (const def of labDefinitions.get(0)) {
        if (def.hidden || owned.has(def.index) || [5,11].includes(def.group)) continue;
        if (def.tileRequirements[0]===2 || def.terrain===3) {
            const x=4+shore++*4;
            pond(x,173,x+1,175);
            for (let y=173;y<=175;y++) labAPI.terrain(map,labWorld,x-1,y,2,0,0);
            place('nature-'+def.index,0,def.index,x+0.5,174.5);
            continue;
        }
        if (nature>=200) throw new Error('Nature catalog exceeds its reserved area');
        place('nature-'+def.index,0,def.index,4+(nature%100)*2.3,166+Math.floor(nature/100)*5);
        nature++;
    }
    // Keep economic work close to its drop sites. Each source gets separate workers.
    place('economy-tc',1,109,24,181);
    place('granary',1,68,10,191);
    place('storage',1,103,45,191);
    const resources = [
        ['berries', /^Forage-Fruit$/i, 12,198],
        ['wood', /^Tree[0-9][0-9]$/i, 34,198],
        ['gold', /^Mine-Gold$/i, 46,198],
        ['stone', /^Mine-Stone$/i, 56,198],
        ['hunt', /^Gazelle$/i, 22,212],
    ];
    for (const [name,pattern,x,y] of resources) {
        const id = gaiaID(pattern);
        for (let i=0;i<3;i++) {
            place(name+'-'+i,0,id,x+i*2,y);
            place(name+'-worker-'+i,1,83,x+i*2,y-3);
            order('work',name+'-worker-'+i,name+'-'+i);
        }
    }
    place('farm',1,50,10,219);
    place('farmer',1,83,10,215);
    order('work','farmer','farm');
    place('builder',1,83,40,222);
    order('build','builder',null,{master:70,x:42,y:225});
    place('repair-house',1,70,51,223);
    place('repairer',1,83,51,219);
    labAPI.modify(live('repair-house'),0.5,0);
    order('repair','repairer','repair-house');
    order('train','economy-tc',null,{master:83});
    // Separated lanes cover melee, missiles, siege, conversion, and healing.
    const fighters = labDefinitions.get(1).filter(row=>!row.hidden && row.type===70 &&
        ![1,2,4,18,20,21,22].includes(row.group)).map(row=>row.index);
    if (fighters.length>56) throw new Error('Combat catalog exceeds its reserved area');
    for (let i=0;i<fighters.length;i++) {
        const x=70+(i%8)*8,y=181+Math.floor(i/8)*8;
        place('attacker-'+i,1,fighters[i],x,y);
        place('defender-'+i,5,fighters[i],x+3,y+2);
        order('work','attacker-'+i,'defender-'+i);
        order('work','defender-'+i,'attacker-'+i);
    }
    for (let n=0;n<4;n++) {
        const y=184+n*11;
        place('converter-'+n,1,125,150,y);
        place('convert-target-'+n,5,73,157,y);
        order('work','converter-'+n,'convert-target-'+n);
    }
    place('healer',1,125,169,185);
    place('patient',1,37,173,185);
    labAPI.modify(live('patient'),0.4,0);
    order('work','healer','patient');
    // Naval work has its own sea, with docks on its western shore.
    pond(189,178,237,237);
    // A beach gives land units and ships a shared unloading boundary.
    for (let y=201;y<=215;y++) labAPI.terrain(map,labWorld,189,y,2,0,0);
    for (const start of [189,222]) for (let y=start;y<start+5;y++)
        labAPI.terrain(map,labWorld,189,y,2,0,0);
    place('naval-dock',1,45,190.5,191.5);
    place('trade-dock',2,45,190.5,224.5);
    place('fishing-boat',1,13,198,185);
    place('fish',0,gaiaID(/^Fish-/i),201,185);
    order('work','fishing-boat','fish');
    place('trade-boat',1,15,198,219);
    order('work','trade-boat','trade-dock');
    place('transport',1,17,191.5,207.5);
    place('passenger',1,73,186,207);
    order('work','passenger','transport');
    for (let i=0;i<3;i++) {
        place('warship-'+i,1,[19,250,360][i],210,192+i*12);
        place('enemy-ship-'+i,5,19,220,192+i*12);
        order('work','warship-'+i,'enemy-ship-'+i);
        order('work','enemy-ship-'+i,'warship-'+i);
    }
    // Editor creation bypasses the population gate. Supply real houses before
    // testing normal training, building, and repair commands in gameplay.
    for (let p=1;p<=8;p++) {
        const player=labPlayer(p), attributes=player.add(80).readPointer();
        labAPI.attribute(player,32,200-attributes.add(32*4).readFloat(),0);
        // Catalog placement consumes the building allowance (resource 30).
        labAPI.attribute(player,30,1000-attributes.add(30*4).readFloat(),0);
        labAPI.attribute(player,9,1000-attributes.add(9*4).readFloat(),0);
        const x0=((p-1)%4)*60,y0=Math.floor((p-1)/4)*82;
        for (let h=0;attributes.add(4*4).readFloat()<12;h++) {
            if (h>=36) throw new Error('Housing exceeds the reserved area');
            place('housing-'+p+'-'+h,p,70,x0+4+(h%18)*3,y0+54+Math.floor(h/18)*3);
        }
    }
    const tech=labPlayer(1).add(0x220).readPointer();
    const n=tech.add(4).readS16(), playerRows=tech.readPointer();
    const baseRows=tech.add(8).readPointer().readPointer(), technologies=[];
    for (let t=0;t<n;t++) {
        const row=baseRows.add(t*60), name=row.readPointer();
        technologies.push({id:t,name:name.isNull()?null:name.readCString(),
            state:playerRows.add(t*8+4).readS16(),building:row.add(40).readS16(),seconds:row.add(30).readS16()});
    }
    send({kind:'lab-technologies',player:1,technologies});
    const research=technologies.find(row=>row.state===1 && row.seconds>0 && row.seconds<=30 &&
        labPlaced.some(object=>object.label==='catalog-1-'+row.building));
    if (research) order('research','catalog-1-'+research.building,null,{technology:research.id});
    for (const [i,terrain] of [0,6,10,1,13,20,4,19,22].entries())
        for (let y=232;y<=236;y++) for (let x=135+i*5;x<140+i*5;x++)
            labAPI.terrain(map,labWorld,x,y,terrain,0,0);
    labAPI.elevation(map,136,225,143,230,3,0,1);
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
        } else if (order.kind === 'repair') labAPI.repair(commands,list,1,live(order.target));
        else if (order.kind === 'train') labAPI.train(commands,actor,order.master);
        else if (order.kind === 'research') labAPI.research(commands,actor,order.technology);
        else if (order.kind === 'build') labAPI.build(commands,list,1,order.master,order.x,order.y);
        else throw new Error('Unsupported setup order: ' + order.kind);
    }
}
