from pathlib import Path
import sys

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools/harness'))
from rng_investigate import first_observation_difference


def test_clock_metadata_remains_separate_from_simulation_values():
    left=[{'kind':'observer-world','time':100,'time_ms':1200}]
    right=[{'kind':'observer-world','time':100,'time_ms':1220}]
    assert first_observation_difference(left,right,'observer-world',['time']) is None
    result=first_observation_difference(left,right,'observer-world',['time_ms'])
    assert result['index']==0 and result['left']==left[0] and result['right']==right[0]


def test_missing_tail_is_a_difference():
    row={'kind':'observer-world','time':100}
    result=first_observation_difference([row],[],'observer-world',['time'])
    assert result['index']==0 and result['right'] is None


def test_event_order_is_not_sorted_to_hide_a_difference():
    a={'kind':'observer-world','time':100}
    b={'kind':'observer-world','time':200}
    assert first_observation_difference([a,b],[b,a],'observer-world',['time'])['index']==0
