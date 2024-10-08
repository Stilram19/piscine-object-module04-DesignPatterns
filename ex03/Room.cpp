# include "Room.hpp"
# include "Person.hpp"

bool Room::is_free() const {
    return (this->_occupants.size() == 0);
}

bool Room::canEnter(Person *person) const {
    if (person == NULL) {
        return (false);
    }
    // to ensure that we don't have useless repititions in the list
    for (std::vector<Person*>::const_iterator occupant = this->_occupants.begin(); occupant != this->_occupants.end(); occupant++) {
        if (*occupant == person) {
            return (false); // already there
        }
    }
    return (person->room() == NULL || person->room() == this);
}

void Room::enter(Person *person) {
    if (person == NULL) {
        return ;
    }

    if (this->canEnter(person) == false) {
        return ;
    }
    this->_occupants.push_back(person);
    person->enter(this);
}

void Room::exit(Person *person) {
    if (person == NULL) {
        return ;
    }

    for (std::vector<Person *>::iterator occupant = this->_occupants.begin(); occupant != this->_occupants.end(); occupant++) {
        if (person == *occupant) {
            this->_occupants.erase(occupant);
            person->exit();
            break ;
        }
    }
}

void Room::printOccupant() const {
    for (std::vector<Person *>::const_iterator occupant = this->_occupants.begin(); occupant != this->_occupants.end(); occupant++) {
        std::cout << (*occupant)->get_name() << std::endl;
    }
}