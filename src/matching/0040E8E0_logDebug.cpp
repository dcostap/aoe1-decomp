// logDebug (0040E8E0) - AIModule::logDebug
// Empty member function - just ret

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    void logDebug(char*, ...);
};
#endif

#ifdef AOE1_AIMODULE_TU_CONTEXT
void AIModule::logDebug(char*, ...)
#else
void AIModule::logDebug(char*, ...)
#endif
{
}
