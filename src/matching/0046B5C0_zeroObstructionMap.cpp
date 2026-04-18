extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);
class PathingSystem {
public:
    void zeroObstructionMap();
    char pad[0xCE624];
    int obstructionMap[0xFE01];
};
void PathingSystem::zeroObstructionMap() {
    memset(this->obstructionMap, 0, sizeof(this->obstructionMap));
}
