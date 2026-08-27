// VA: 0044F760 RGE_Master_Action_Object::copy_obj
// PDB source: m_ac_obj.cpp

void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* src)
{
    RGE_Master_Moving_Object::copy_obj(src);
    RGE_Master_Action_Object* source =
        static_cast<RGE_Master_Action_Object*>(src);
    this->default_task = source->default_task;
    this->search_radius = source->search_radius;
    this->work_rate = source->work_rate;
    this->drop_site = source->drop_site;
    this->backup_drop_site = source->backup_drop_site;
    this->task_by_group = source->task_by_group;
    this->command_sound = source->command_sound;
    this->move_sound = source->move_sound;
    this->tasks->copy(source->tasks);
}
