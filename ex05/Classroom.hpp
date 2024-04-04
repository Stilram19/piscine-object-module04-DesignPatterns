#ifndef CLASSROOM_HPP
# define CLASSROOM_HPP

class Course;

# include "Room.hpp"

class Classroom : public Room {
    private:
        Course *_currentCourse;

    public:
        Classroom() : _currentCourse(NULL) {}
        ~Classroom() {}

    public:
        Course *current_course() { return (this->_currentCourse); }

        void assignCourse(Course* p_course) {
            this->_currentCourse = p_course;
        }
};

#endif