// VA: 0044F1E0 RGE_Master_Action_Object::setup (copy-from-master variant)
// PDB source: m_ac_obj.cpp
// The copied state uses the canonical master-object and task-list declarations.

int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* src) {
    RGE_Master_Moving_Object::setup(
        static_cast<RGE_Master_Moving_Object*>(src));
    this->master_type = 0x28;
    this->default_task = src->default_task;
    this->search_radius = src->search_radius;
    this->work_rate = src->work_rate;
    this->drop_site = src->drop_site;
    this->backup_drop_site = src->backup_drop_site;
    this->task_by_group = src->task_by_group;
    this->command_sound = src->command_sound;
    this->move_sound = src->move_sound;
    this->run_pattern = src->run_pattern;
    this->tasks = this->create_task_list();
    this->tasks->copy(src->tasks);
    return 1;
}
