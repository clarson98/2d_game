#include "idleObject.h"

idleObject::idleObject(const char* path, int x, int y) : entity{path, x, y} {

}

idleObject::idleObject(char const *path, int x, int y, char const *partPath, int part_x, int part_y, int w, int h, int type) : entity{path, x, y} {
    e = new emitter(partPath, part_x, part_y, w, h, type);
}

idleObject::~idleObject(){

}
