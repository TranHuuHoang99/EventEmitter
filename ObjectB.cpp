#include "ObjectB.hpp"

void ObjectB::init(void) {
    unsigned int _eventId = 
    EventEmitter::getInstance()->on<void(int, const char*), int, const char*>(Object::EVENT_INIT, [&](int value, const char *value_str) {
        this->objb_value_int = value;
        this->objb_value_str = value_str;
    });
}

void ObjectB::go(void) {
    EventEmitter::getInstance()->emit<int, const char*>(Object::EVENT_INIT, 333, "hoangprodnhahah");
}

