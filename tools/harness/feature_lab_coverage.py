"""Summarize observed feature activity. Placement alone is not execution coverage."""
from __future__ import annotations

import math
import struct


def number(bits):
    value = struct.unpack('<f', struct.pack('<I', bits))[0]
    if not math.isfinite(value):
        raise ValueError('A sampled game value is not finite.')
    return value


def action_types(actions):
    result = set()
    for action in actions:
        result.add(action['type'])
        result.update(action_types(action['children']))
    return result


class Coverage:
    def __init__(self, setup):
        self.setup = setup
        self.labels = {row['id']: row['label'] for row in setup['placed']}
        self.planned = {row['label']: row for row in setup['placed']}
        self.seen = set()
        self.actions = {}
        self.carried = set()
        self.healed = set()
        self.hurt = set()
        self.converted = set()
        self.boarded = set()
        self.unloaded = set()
        self.built = set()
        self.trained = set()
        self.traded = set()
        self.moved = set()
        self.previous = {}
        self.researched = set()
        self.initial_tech = None
        self.samples = 0
        self.initial_objects = None

    def observe(self, state):
        self.samples += 1
        if self.initial_objects is None:
            self.initial_objects = {obj['id'] for obj in state['objects']}
        for obj in state['objects']:
            oid = obj['id']
            self.seen.add((oid, obj['owner'], obj['master']))
            self.actions.setdefault(oid, set()).update(action_types(obj['actions']))
            prior = self.previous.get(oid)
            if prior:
                if number(obj['held']) > number(prior['held']):
                    self.carried.add(oid)
                if prior.get('position') != obj.get('position'):
                    self.moved.add(oid)
                if number(prior['held']) > 0 and number(obj['held']) == 0 and \
                        obj['state'] == 2 and obj['owner'] == prior['owner'] and \
                        any(a['type'] == 111 and a['state'] == 8 for a in prior['actions']):
                    self.traded.add(oid)
                before, after = number(prior['hp']), number(obj['hp'])
                if after > before:
                    self.healed.add(oid)
                if after < before:
                    self.hurt.add(oid)
                if obj['owner'] != prior['owner']:
                    self.converted.add(oid)
                if prior['inside'] is not None and obj['inside'] is None:
                    self.unloaded.add(oid)
            if obj['inside'] is not None:
                self.boarded.add(oid)
            if oid not in self.labels and obj['owner'] == 1 and obj['state'] == 2 and \
                    (oid not in self.initial_objects or (prior and prior['state'] != 2)):
                if obj['master'] == 70:
                    self.built.add(oid)
                if obj['master'] == 83:
                    self.trained.add(oid)
            self.previous[oid] = obj
        tech = {p['id']: p.get('tech') for p in state['players']}
        if self.initial_tech is None:
            self.initial_tech = tech
        for player, rows in tech.items():
            before = self.initial_tech.get(player)
            if rows is not None and before is not None:
                for index, row in enumerate(rows):
                    if row[1] == 3 and before[index][1] != 3:
                        self.researched.add((player, index))

    def chaos_result(self):
        """A home economy plus one battle. The chaos map has no catalog lane."""
        def ids(prefix):
            return {oid for oid, label in self.labels.items() if label.startswith(prefix)}
        rows = {}
        for prefix in ('berries', 'wood', 'gold', 'stone', 'hunt'):
            actors = sorted(ids(prefix + '-worker-') & self.carried)
            rows['gather-' + prefix] = dict(observed=bool(actors), actors=actors, evidence='carried resource')
        actors = sorted((ids('combat-') | ids('guard-') | ids('raider-')) & self.hurt)
        rows['combat'] = dict(observed=bool(actors), actors=actors, evidence='health decreased')
        guards = sorted(ids('guard-') & self.moved)
        rows['guard-movement'] = dict(observed=bool(guards), actors=guards, evidence='position changed')
        villagers = {row['actor'] for row in self.setup.get('orders', []) if '-worker-' in row['actor']}
        activity = {label: dict(id=self.planned[label]['id'],
                    actions=sorted(self.actions.get(self.planned[label]['id'], set())),
                    moved=self.planned[label]['id'] in self.moved,
                    carried_resource=self.planned[label]['id'] in self.carried)
                    for label in sorted(villagers)}
        return dict(samples=self.samples, features=rows, catalog=dict(planned=0, missing=[]),
                    ordered_actors=activity,
                    observed=sum(row['observed'] for row in rows.values()), requested=len(rows),
                    passed=self.samples > 0 and all(row['observed'] for row in rows.values()),
                    limits=['A stress map is not an exhaustive feature map.',
                            'The battle is chaotic by design; it does not mirror civilizations.'])

    def result(self):
        if self.setup.get('layout') == 'chaos':
            return self.chaos_result()
        def ids(prefix):
            return {oid for oid, label in self.labels.items() if label.startswith(prefix)}

        rows = {}
        for prefix in ('berries', 'wood', 'gold', 'stone', 'hunt'):
            workers = ids(prefix + '-worker-')
            actors = sorted(workers & self.carried)
            rows['gather-' + prefix] = dict(observed=bool(actors), actors=actors, evidence='carried resource')
        for feature, actor in [('farming', 'farmer'), ('fishing', 'fishing-boat')]:
            actors = sorted(ids(actor) & self.carried)
            rows[feature] = dict(observed=bool(actors), actors=actors, evidence='carried resource')
        for feature, actors, evidence in [
            ('combat', (ids('attacker-') | ids('defender-') | ids('warship-') | ids('enemy-ship-')) & self.hurt, 'health decreased'),
            ('conversion', ids('convert-target-') & self.converted, 'owner changed'),
            ('healing', ids('patient') & self.healed, 'health increased'),
            ('repair', ids('repair-house') & self.healed, 'health increased'),
            ('construction', self.built, 'new completed house'),
            ('training', self.trained, 'new villager'),
            ('boarding', ids('passenger') & self.boarded, 'inside another object'),
            ('unloading', ids('passenger') & self.unloaded, 'left another object'),
            ('trade', ids('trade-boat') & self.traded, 'trade cargo loaded and delivered'),
        ]:
            rows[feature] = dict(observed=bool(actors), actors=sorted(actors), evidence=evidence)
        rows['research'] = dict(observed=bool(self.researched), technologies=sorted(self.researched), evidence='technology completed')
        catalog = [row for row in self.setup['placed'] if row['label'].startswith('catalog-')]
        missing = [row['label'] for row in catalog if (row['id'], row['owner'], row['master']) not in self.seen]
        actors = {row['actor'] for row in self.setup.get('orders', [])}
        activity = {label: dict(id=self.planned[label]['id'],
                    actions=sorted(self.actions.get(self.planned[label]['id'], set())),
                    moved=self.planned[label]['id'] in self.moved,
                    carried_resource=self.planned[label]['id'] in self.carried)
                    for label in sorted(actors)}
        return dict(samples=self.samples, features=rows, catalog=dict(planned=len(catalog), missing=missing),
                    ordered_actors=activity,
                    observed=sum(row['observed'] for row in rows.values()), requested=len(rows),
                    passed=self.samples > 0 and not missing and all(row['observed'] for row in rows.values()),
                    limits=['A unit catalog does not cover every action, upgrade, terrain, or civilization combination.',
                            'Multiplayer, campaigns, cinematics, audio, and victory conditions need separate cases.'])
