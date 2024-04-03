# include "Person.hpp"
# include "Room.hpp"

Person::Person(std::string p_name) : _name(p_name), _currentRoom(NULL) {}

const std::string &Person::get_name() { return (this->_name); }

Room* Person::room() { return (this->_currentRoom); }

void Person::exit() {
    if (this->_currentRoom == NULL) {
        return ;
    }

    Room *roomTemp = this->_currentRoom;

    this->_currentRoom = NULL;
    roomTemp->exit(this);
}

void Person::enter(Room *room) {
    if (room == NULL) {
        return ;
    }
    if (this->_currentRoom == room) {
        return ;
    }

    // checking if the person is currently in another Room
    if (this->_currentRoom != NULL) {
        return ;
    }

    this->_currentRoom = room;
    room->enter(this);
}
