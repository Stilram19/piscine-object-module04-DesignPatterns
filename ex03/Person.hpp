#ifndef PERSON_HPP
# define PERSON_HPP

# include <iostream>
# include <vector>

class Room;

class Person {
    private:
        std::string _name;
        Room* _currentRoom;

    public:
        Person(std::string p_name);

    public:
        const std::string &get_name();
        Room* room();
        void exit();
        void enter(Room *room);
};

#endif