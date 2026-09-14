"""Locate RNG, clock, world-state, and combat differences in diagnostic captures."""
import argparse
import json
from pathlib import Path

from human_compare import compare_captures, load_capture


def first_observation_difference(left,right,kind,fields):
    rows=[[row for row in events if row.get('kind')==kind] for events in (left,right)]
    for index in range(max(map(len,rows))):
        pair=[group[index] if index<len(group) else None for group in rows]
        values=[None if row is None else {key:row.get(key) for key in fields} for row in pair]
        if values[0]!=values[1]:
            return {'index':index,'compared_fields':fields,'left':pair[0],'right':pair[1]}
    return None


def investigate(left,right):
    reports=[capture['report'] for capture in (left,right)]
    if any(not r.get('rng_recording') for r in reports):
        raise ValueError('Both captures need complete RNG files.')
    if not reports[0].get('observer_sha256') or reports[0]['observer_sha256']!=reports[1].get('observer_sha256'):
        raise ValueError('Observer scripts differ.')
    modes=[tuple(r['fixture']['human'].get(key,False) for key in ('observe','rng_only','combat')) for r in reports]
    if modes[0]!=modes[1]:
        raise ValueError('Observer modes differ.')
    comparison=compare_captures(left,right)
    events=[r['events'] for r in reports]
    fields=['phase','updates','time','delta','registrations','speed']
    clock_fields=['phase','updates','time_ms','old_time','clock_counts']
    attack_fields=['phase','updates','actor','target','action_state','timer','attack_timer',
                   'need_to_attack','fire_frame','sprite','animation']
    villager_fields=['phase','updates','actor','speed','master_speed','sprite','velocity','action']
    rng_difference=comparison['full_rng']['first_difference']
    context=[]
    if rng_difference:
        for rows in events:
            combat=[row for row in rows if row.get('kind')=='observer-combat']
            before=[row for row in combat if row['rng_count']<=rng_difference['index']]
            after=[row for row in combat if row['rng_count']>rng_difference['index']]
            context.append({'at_or_before':before[-1:] ,'after':after[:1]})
    return {'schema':1,'complete':True,'left':left['path'],'right':right['path'],
            'scope':'Read-only diagnostic observations. This report does not establish observer neutrality or prove a source defect.',
            'inputs':comparison['inputs'],'first_rng_difference':rng_difference,
            'first_simulation_difference':first_observation_difference(*events,'observer-world',fields),
            'first_clock_difference':first_observation_difference(*events,'observer-world',clock_fields),
            'first_attack_difference':first_observation_difference(*events,'observer-attack-update',attack_fields),
            'first_villager_difference':first_observation_difference(*events,'observer-villager',villager_fields),
            'first_sprite_difference':first_observation_difference(*events,'observer-sprite',['updates','actor','sprite','order']),
            'observation_counts':[{kind:sum(row.get('kind')==kind for row in rows) for kind in
                ('observer-world','observer-combat','observer-attack-update','observer-sprite','observer-villager')} for rows in events],
            'combat_near_rng_difference':context,'terminal_boundaries':comparison['terminal_boundaries'],
            'rng_counts':comparison['rng_total_counts']}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--left',type=Path,required=True)
    parser.add_argument('--right',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    args.output.mkdir(parents=True,exist_ok=False)
    try:
        result=investigate(load_capture(args.left),load_capture(args.right))
    except (OSError,ValueError,KeyError) as error:
        result={'schema':1,'complete':False,'error':str(error)}
    (args.output/'report.json').write_text(json.dumps(result,indent=2)+'\n')
    print('Report:',args.output/'report.json')
    print('First RNG difference:',result.get('first_rng_difference',result.get('error')))
    return 0 if result['complete'] else 1


if __name__=='__main__':
    raise SystemExit(main())
