#include "EventEmitter.hpp"

EventEmitter::EventEmitter(void) {

}

EventEmitter::~EventEmitter(void) {

}

EventEmitter *EventEmitter::_instance = nullptr;

EventEmitter *EventEmitter::getInstance(void) {
    if(EventEmitter::_instance == nullptr) {
        EventEmitter::_instance = new EventEmitter();
    }

    return EventEmitter::_instance;
}

void EventEmitter::erase_Listener(unsigned int eventID, unsigned int listenerID) {
    auto it = _listeners.find(eventID);
    if(it != _listeners.end()) {
        if(it->second.size() > 0) {
            it->second.erase(it->second.begin()+listenerID);
        } else {
            cerr << "No Listener is listening to event" << endl;
            return;
        }
    } else {
        cerr << "Event does not exist" << endl;
    }
}

void EventEmitter::erase_Event(unsigned int eventID) {
    auto it = _listeners.find(eventID);

    if(it != _listeners.end()) {
        _listeners.erase(eventID);
    } else {
        cerr << "Event does not exist" << endl;
    }
}
