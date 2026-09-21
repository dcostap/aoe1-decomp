// Diagnostic: log every zone-map cache creation with its rules and caller stack.
// Read-only. Attach points come from config/functions/src/zone_map.cpp.json.
{
    const zoneCreate = base.add(0x1468c0); // RGE_Zone_Map::RGE_Zone_Map(RGE_Map*, float*, long)
    const zoneGet = base.add(0x1473b0);    // RGE_Zone_Map_List::get_zone_map(float*, long, int&)
    const zoneCreateList = base.add(0x1472b0); // RGE_Zone_Map_List::create_zone_map(float*, long)
    const zoneModuleEnd = base.add(Process.mainModule.size);
    let zoneCreates = 0, zoneQueries = 0, zoneCreateQueries = 0;
    function zoneStack(context) {
        return Thread.backtrace(context, Backtracer.ACCURATE).slice(0, 12).map(address =>
            address.compare(base) >= 0 && address.compare(zoneModuleEnd) < 0
                ? 'exe+' + address.sub(base).toString(16) : address.toString());
    }
    Interceptor.attach(zoneCreate, {onEnter(args) {
        try {
            const num = args[2].toInt32();
            const rules = [];
            const limit = num > 0 && num < 64 ? num : 0;
            for (let i = 0; i < limit; i++) rules.push(args[1].add(i * 4).readFloat());
            send({kind:'zone-create', index:zoneCreates++, rules_num:num, rules,
                  get_queries:zoneQueries, create_queries:zoneCreateQueries,
                  updates:human.updates, input:human.input, turn:human.turn, time_ms:ticks - 1000,
                  stack:zoneStack(this.context)});
        } catch (error) { send({kind:'zone-probe-error', error:String(error)}); }
    }});
    Interceptor.attach(zoneGet, {onEnter() { zoneQueries++; }});
    Interceptor.attach(zoneCreateList, {onEnter() { zoneCreateQueries++; }});

    // Confirmation of the unguarded soldiers[0] read in setupSoldierGroups.
    // Offsets come from the shipped call site at 0x004fbe54..0x004fbeac.
    const zoneSetupGroups = base.add(0xfbc30); // TribeTacticalAIModule::setupSoldierGroups
    const zoneExplored = base.add(0xd9110);    // TribeInformationAIModule::fullyExploredZone(int)
    const zoneResolve = base.add(0xd760);      // MainDecisionAIModule::object(int)
    let zoneSetupLogs = 0, zoneExploreDepth = 0, zoneResolveId = 0;
    Interceptor.attach(zoneSetupGroups, {onEnter() {
        try {
            const list = this.context.ecx.add(0x114);
            const value = list.readPointer();
            const numberValue = list.add(4).readS32();
            const desired = list.add(8).readS32();
            const maximumSize = list.add(12).readS32();
            const slots = [];
            if (!value.isNull()) {
                for (let i = 0; i < Math.min(maximumSize, 4); i++) slots.push(value.add(i * 4).readS32());
            }
            send({kind:'zone-soldiers', index:zoneSetupLogs, numberValue, desired,
                  maximumSize, value:value.toString(), slots,
                  updates:human.updates, input:human.input, time_ms:ticks - 1000});
            zoneSetupLogs++;
        } catch (error) { send({kind:'zone-probe-error', error:String(error)}); }
    }});
    Interceptor.attach(zoneExplored, {onEnter(args) {
        zoneExploreDepth++;
        zoneResolveId = args[0].toInt32();
        send({kind:'zone-explore', id:zoneResolveId, depth:zoneExploreDepth,
              updates:human.updates, input:human.input, time_ms:ticks - 1000});
    }, onLeave() { zoneExploreDepth--; }});
    Interceptor.attach(zoneResolve, {onEnter(args) {
        this.during = zoneExploreDepth > 0;
        if (this.during) this.id = args[0].toInt32();
    }, onLeave(retval) {
        if (!this.during) return;
        send({kind:'zone-resolve', id:this.id, object:retval.toString(),
              live:!retval.isNull(), updates:human.updates, input:human.input});
    }});
}
