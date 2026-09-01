from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from common import PeImage, Section
from pdb_scoped_symbols import (
    apply_type_names,
    parse_scoped_symbols,
    parse_type_summaries,
    resolve_type_name,
)


def _image() -> PeImage:
    return PeImage(
        image_base=0x00400000,
        sections=[
            Section(".text", 0x1000, 0x100000, 0x100000, 0, 0),
            Section("two", 0x110000, 0x1000, 0x1000, 0, 0),
            Section(".rdata", 0x16E000, 0x1000, 0x1000, 0, 0),
            Section(".data", 0x17F000, 0x200000, 0x200000, 0, 0),
        ],
        data=b"",
    )


def test_get_next_sequence_scoped_symbols() -> None:
    raw = """
** Module: ".\\Release\\Com_hand.obj"
(00426C) S_GPROC32: [0001:0002A200], Cb: 0000006C, Type: 0x2406, TCommunications_Handler::GetNextSequence
         Parent: 00000000, End: 0000431C, Next: 00000000
(0042BC)  S_REGISTER: ecx, Type: 0x23B6, this
(0042CC)  S_BPREL32: [00000004], Type: T_ULONG(0022), ThisTurn
(0042E4)  S_LDATA32: [0004:000ADF2C], Type: T_UCHAR(0020), Sequence
(0042FC)  S_LDATA32: [0004:000ADF30], Type: T_ULONG(0022), LastCurrentTurn
(00431C) S_END
"""
    payload = parse_scoped_symbols(raw, _image())
    function = payload["functions"]["0042B200"]
    assert function["module_object_path"] == ".\\Release\\Com_hand.obj"
    assert function["stack_symbols"][0]["name"] == "ThisTurn"
    assert function["stack_symbols"][0]["offset"] == 4
    assert function["register_symbols"][0]["register"] == "ecx"
    assert function["function_statics"] == [
        {
            "kind": "function_static",
            "name": "Sequence",
            "section": "0004",
            "offset": "000ADF2C",
            "address": "0062CF2C",
            "type_display": "T_UCHAR(0020)",
            "type_index": "0020",
            "type_name": "unsigned char",
        },
        {
            "kind": "function_static",
            "name": "LastCurrentTurn",
            "section": "0004",
            "offset": "000ADF30",
            "address": "0062CF30",
            "type_display": "T_ULONG(0022)",
            "type_index": "0022",
            "type_name": "unsigned long",
        },
    ]
    owners = payload["function_static_address_owners"]
    assert owners["0062CF2C"][0]["function_va"] == "0042B200"


def test_signed_stack_offset_and_procedure_scope() -> None:
    raw = """
** Module: "sample.obj"
(000100) S_GPROC32: [0001:00001000], Cb: 20, Type: 0x1000, sample
         Parent: 00000000, End: 00000180, Next: 00000000
(000120) S_BPREL32: [FFFFFFF8], Type: T_INT4(0074), local
(000140) S_BLOCK32: [0001:00001005], Cb: 4
(000150) S_END
(000160) S_REGISTER: esi, Type: T_UINT4(0075), value
(000180) S_END
(000190) S_LDATA32: [0004:00000010], Type: T_LONG(0012), not_scoped
"""
    payload = parse_scoped_symbols(raw, _image())
    function = payload["functions"]["00402000"]
    assert function["stack_symbols"][0]["offset"] == -8
    assert function["register_symbols"][0]["name"] == "value"
    assert function["function_statics"] == []


def test_complex_pointer_type_resolution() -> None:
    types = """
0x2000 : Length = 34, Leaf = 0x1504 LF_CLASS
    # members = 0
    Size = 0, class name = Demo, UDT(0x00002000)

0x2001 : Length = 10, Leaf = 0x1002 LF_POINTER
    Pointer (NEAR32), Size: 0
    Element type : 0x2000

0x2002 : Length = 10, Leaf = 0x1001 LF_MODIFIER
    const, modifies type 0x2000

0x2003 : Length = 10, Leaf = 0x1002 LF_POINTER
    const Pointer (NEAR32), Size: 0
    Element type : 0x2002
"""
    raw = """
** Module: "sample.obj"
(000100) S_GPROC32: [0001:00001000], Cb: 20, Type: 0x2001, sample
         Parent: 00000000, End: 00000140, Next: 00000000
(000120) S_REGISTER: ecx, Type: 0x2001, this
(000140) S_END
"""
    payload = parse_scoped_symbols(raw, _image())
    summaries = parse_type_summaries(types)
    apply_type_names(payload, summaries)
    function = payload["functions"]["00402000"]
    assert function["type_name"] == "Demo*"
    assert function["register_symbols"][0]["type_name"] == "Demo*"
    assert resolve_type_name("0x2003", summaries) == "const Demo*"
