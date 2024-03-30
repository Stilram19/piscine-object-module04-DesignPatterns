#ifndef CLASS_ROOM_HPP
# define CLASS_ROOM_HPP

class Course;

# include "Room.hpp"

class ClassRoom : public Room {
    private:
        Course* _currentCourse;

    public:
        ClassRoom() : _currentCourse(NULL) {}

        void assignCourse(Course* p_course) {
            this->_currentCourse = p_course;
        }
};

#endif