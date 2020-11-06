#ifndef IDLEOBJECT_H
#define IDLEOBJECT_H

#include "entity.h"

class idleObject : public entity{

    public:
        idleObject(char const *path, int x, int y);
        ~idleObject();


    private:
        Uint32 lastUpdate; 

};

#endif