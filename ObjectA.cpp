#include "ObjectA.hpp"

void ObjectA::init(void) {
    unsigned int _listenerID = 
    EventEmitter::getInstance()->on<void(int, const char*), int, const char*>(Object::EVENT_INIT, [&](int value, const char* value_str) {
        this->obj_value_int = value;
        this->obj_value_str = value_str;
    });

    // EventEmitter::getInstance()->erase_Listener(Object::EVENT_INIT, _listenerID);

    return;
}

void ObjectA::test_erase_eventID(void) {
    EventEmitter::getInstance()->erase_Event(Object::EVENT_INIT);
}