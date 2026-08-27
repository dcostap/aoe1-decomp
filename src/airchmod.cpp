#include "../include/airchmod.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

extern "C" int __cdecl rge_read(int file, void* dst, int size);
extern "C" void __cdecl rge_write(int file, void* data, int size);

ResearchAIModule::ResearchAIModule(void* ptr, int arg)
    : AIModule((char*)"Research AI", 0x3ee, arg, ptr),
      md(0),
      techTree(),
      techTreeLengthValue(0)
{
    TechnologyItem* head = &this->techTree;
    this->techTree.next = head;
    this->techTree.prev = head;
    strcpy(this->techTreeNameValue, "");
}

ResearchAIModule::ResearchAIModule(int file, int arg2)
    : AIModule((char*)"Research AI", 0x3ee, file, 0),
      md(0),
      techTree(),
      techTreeLengthValue(0)
{
    TechnologyItem* head = &this->techTree;
    int i;
    int tempInt;
    int typeID;
    int rc[4];
    char name[0x104];

    this->techTree.next = head;
    this->techTree.prev = head;
    rge_read(arg2, &this->techTreeLengthValue, 4);

    rge_read(arg2, &i, 4);
    rge_read(arg2, &this->techTreeNameValue[0], i);
    this->techTreeNameValue[i] = 0;

    for (typeID = 0; typeID < this->techTreeLengthValue; ++typeID) {
        rge_read(arg2, &i, 4);
        rge_read(arg2, name, i);
        name[i] = 0;
        rge_read(arg2, &tempInt, 4);

        int j;
        int* p = rc;
        for (j = 4; j != 0; --j) {
            rge_read(arg2, &i, 4);
            *p++ = i;
        }

        ResourceItem newRCost(4, rc);
        TechnologyItem* item = new TechnologyItem(tempInt, name, newRCost);

        item->next = head;
        TechnologyItem* oldTail = this->techTree.prev;
        item->prev = oldTail;
        oldTail->next = item;
        this->techTree.prev = item;
    }
}

ResearchAIModule::~ResearchAIModule()
{
    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }
}

void ResearchAIModule::setMainDecisionAI(MainDecisionAIModule* value)
{
    this->md = value;
}

int ResearchAIModule::save(int file)
{
    int tempInt;
    char tempString[257];

    rge_write(file, &this->techTreeLengthValue, 4);

    strcpy(tempString, this->techTreeNameValue);
    tempInt = strlen(tempString);
    rge_write(file, &tempInt, 4);
    rge_write(file, tempString, strlen(tempString));

    TechnologyItem* item = this->techTree.next;
    TechnologyItem* end = &this->techTree;
    while (item != end) {
        if (item == 0) {
            return 1;
        }
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(file, &tempInt, 4);
        rge_write(file, tempString, tempInt);
        tempInt = item->id();
        rge_write(file, &tempInt, 4);
        ResourceItem* cost = item->resourceCost();
        int i = 0;
        do {
            tempInt = cost->value(i);
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < 4);
        item = item->next;
    }

    return 1;
}

ResourceItem* ResearchAIModule::resourceCost(int id)
{
    TechnologyItem* tech = this->item(id);
    if (tech == 0) {
        return 0;
    }
    return tech->resourceCost();
}

int ResearchAIModule::buildable(BuildItem* item)
{
    return 1;
}

void ResearchAIModule::research(BuildItem* item)
{
}

int ResearchAIModule::loadTechnologyTree(char* filename)
{
    int rc[5];
    char name[64];
    char temp[256];
    FILE* fp;
    TechnologyItem* item;
    TechnologyItem* tail;
    char* id;

    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }

    strcpy(this->techTreeNameValue, filename);
    id = this->techTreeNameValue;
    if (strcmp(id, "NONE") != 0) {
        if (id == 0) goto no_tree;
        this->logCommonHistory("Loading tech tree in file '%s'.", filename);
        sprintf(temp, "%s", id);
        fp = fopen(temp, "r");
        if (fp == 0) return 0;
        if (fgets(temp, 0x100, fp) != 0) {
            tail = &this->techTree;
            do {
                sscanf(temp, "%*c%d %s %*d %*d %d %d %d %d %*d %*d %*d %*d", rc, name, rc + 1, rc + 2, rc + 3, rc + 4);
                ResourceItem newRCost2(4, rc + 1);
                TechnologyItem* alloc = new TechnologyItem(rc[0], name, newRCost2);
                item = alloc;
                item->next = tail;
                TechnologyItem* oldTail = this->techTree.prev;
                item->prev = oldTail;
                oldTail->next = item;
                this->techTree.prev = item;
                this->techTreeLengthValue++;
            } while (fgets(temp, 0x100, fp) != 0);
        }
        fclose(fp);
        if (strstr(id, ".tmp") != 0) {
            unlink(id);
        }
    } else {
        if (id == 0) {
no_tree:
            strcpy(0, "NULL");
        }
        this->logCommonHistory("There is no tech tree to load.");
    }
    return 1;
}

int ResearchAIModule::numberTechnologyItems() const
{
    return this->techTreeLengthValue;
}

char* ResearchAIModule::technologyTreeName()
{
    return this->techTreeNameValue;
}

void ResearchAIModule::removeOldTechTree(void)
{
    TechnologyItem* head = &this->techTree;
    TechnologyItem* node = this->techTree.next;

    while (node != head && node != 0) {
        TechnologyItem* next = node->next;
        delete node;
        node = next;
    }

    this->techTree.next = head;
    this->techTree.prev = head;
    this->techTreeLengthValue = 0;
}

TechnologyItem* ResearchAIModule::item(int tech_id)
{
    TechnologyItem* item = this->techTree.next;
    TechnologyItem* end = &this->techTree;

    while (item != end) {
        if (item == 0)
            return 0;
        if (item->id() == tech_id)
            return item;
        item = item->next;
    }

    return 0;
}
