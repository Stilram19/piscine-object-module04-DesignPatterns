#ifndef CLASS_ROOM_HPP
# define CLASS_ROOM_HPP

class Course;

# include "Room.hpp"

class ClassRoom : public Room {
    private:
        Course* _currentRoom;

    public:
        ClassRoom();
        void assignCourse(Course* p_course);
};

#endif