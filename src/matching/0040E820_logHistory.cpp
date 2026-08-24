// logHistory (0040E820) - AIModule::logHistory
// Empty member function - just ret

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    void logHistory(void);
};
#endif

#ifdef AOE1_AIMODULE_TU_CONTEXT
void AIModule::logHistory(char*, ...)
#else
void AIModule::logHistory(void)
#endif
{
}
