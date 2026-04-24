import struct
import sys


def read_c_string(buf, off):
    end = buf.find(b"\0", off)
    if end < 0:
        end = len(buf)
    return buf[off:end].decode("ascii", "replace")


def resolve_section_name(raw_name, data, ptr_symtab, num_symbols):
    raw_name = raw_name.rstrip(b"\0")
    if not raw_name.startswith(b"/"):
        return raw_name.decode("ascii", "replace")

    try:
        str_off = int(raw_name[1:].decode("ascii"))
    except ValueError:
        return raw_name.decode("ascii", "replace")

    string_table_base = ptr_symtab + num_symbols * 18
    if string_table_base + 4 > len(data):
        return raw_name.decode("ascii", "replace")

    target = string_table_base + str_off
    if target >= len(data):
        return raw_name.decode("ascii", "replace")

    return read_c_string(data, target)


def load_text(path):
    data = open(path, "rb").read()
    if len(data) < 20:
        raise SystemExit("file too small for COFF header")

    (
        machine,
        num_sections,
        _timestamp,
        ptr_symtab,
        num_symbols,
        opt_size,
        _chars,
    ) = struct.unpack_from("<HHLLLHH", data, 0)

    sec_base = 20 + opt_size
    text_chunks = []
    for i in range(num_sections):
        off = sec_base + i * 40
        raw_name = data[off:off + 8]
        name = resolve_section_name(raw_name, data, ptr_symtab, num_symbols)
        (
            _vsize,
            _va,
            size_raw,
            ptr_raw,
            _ptr_reloc,
            _ptr_lnum,
            _n_reloc,
            _n_lnum,
            _sec_chars,
        ) = struct.unpack_from("<LLLLLLHHL", data, off + 8)
        if name == ".text" or name.startswith(".text$"):
            text_chunks.append((name, data[ptr_raw:ptr_raw + size_raw]))

    if not text_chunks:
        raise SystemExit("no .text section in object")

    text = b"".join(chunk for _, chunk in text_chunks)
    return text_chunks, text


def main():
    if len(sys.argv) != 3:
        raise SystemExit("usage: python tools/tmp_extract_coff_text.py <input.obj> <output.text>")

    inp, outp = sys.argv[1], sys.argv[2]
    chunks, text = load_text(inp)
    with open(outp, "wb") as f:
        f.write(text)
    for name, chunk in chunks:
        print(f"{name}: {len(chunk)}")
    print(f"wrote {len(text)} bytes to {outp}")


if __name__ == "__main__":
    main()
