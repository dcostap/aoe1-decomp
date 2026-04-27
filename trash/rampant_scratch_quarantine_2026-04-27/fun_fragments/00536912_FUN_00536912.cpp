// tail-block fragment in view.cpp: starts mid-function at 00536912 and jumps into 00536992
// quick-win triage: no ordinary source model found yet; this looks like a continuation block inside a larger scroll/map update routine
// trying to spell it as a normal function would add a prolog and miss the exact bytes immediately at offset 0
// remaining mismatch to solve later: region/block-level structure, not the arithmetic at the block tail
