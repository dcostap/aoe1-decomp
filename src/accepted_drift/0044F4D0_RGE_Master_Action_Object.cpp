// m_ac_obj.cpp:169-175, 112 bytes
// attempt 7: no-inheritance explicit base call kept store sunk and introduced extra cleanup call.
// attempt 8: restore real inheritance/auto base dtor, manual volatile vftable store before task cleanup.
// SpruceGlow tries 1-10: plain member load, extra local, if/not-null/else/goto forms, delete expression,
//   non-volatile vftable store, volatile local pointer, reference slot, and manual base dtor. Most keep same
//   near-match; plain/non-volatile/manual-base variants are worse.
// SpruceGlow tries 11-20: dummy locals before/after load, dummy condition, helper delete, conditional local,
//   raw slot null store, empty/nested conditionals, and try/catch. Same near-match or much worse.
// ACCEPTED_DRIFT: reviewed by Boss. Remaining mismatch is localized scheduling of
// EH state store vs null test: original does `mov state=0; test edi,edi`; rebuilt
// does `test edi,edi; mov state=0`. The EH state is set to 0 before any possible
// throwing call and before the branch target, and all else (EH frame, vtable store,
// task destructor/delete/null store, base destructor, epilogue) matches.

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    RGE_Task_List* task_list = *(RGE_Task_List* volatile*)((char*)this + 0xD8);
    if (task_list == 0) {
    } else {
        task_list->~RGE_Task_List();
        operator_delete(task_list);
        this->tasks = 0;
    }
}
