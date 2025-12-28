#include "TPanelSystem.h"

void TPanelSystem::release_palette(TPanelSystem *ps, void *pal) {}
void *TPanelSystem::get_palette(TPanelSystem *ps, const char *pal_file, int id) { return nullptr; }
void TPanelSystem::setCurrentPanel(TPanelSystem *ps, const char *name, int id) {}
void TPanelSystem::destroyPanel(TPanelSystem *ps, const char *name) {}
void *TPanelSystem::panel(TPanelSystem *ps, const char *name) { return nullptr; }
