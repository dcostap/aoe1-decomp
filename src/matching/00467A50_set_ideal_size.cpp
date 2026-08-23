// VA: 00467A50, TEasy_Panel::set_ideal_size, Panel_ez.cpp lines 559-562.
// Exact finish: the PDB-proven protected virtual long/long owner replaces a
// synthetic same-layout class. The shared class header belongs before the
// ordered Panel_ez.cpp method bodies; a repeated local include was incidental.
void TEasy_Panel::set_ideal_size(long width, long height) {
    this->ideal_width = width;
    this->ideal_height = height;
}
