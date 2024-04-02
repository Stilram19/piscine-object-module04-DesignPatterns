#ifndef CLASSROOM_HPP
# define CLASSROOM_HPP

class Course;

# include "Room.hpp"

class Classroom : public Room {
    private:
        Course* _currentCourse;

    public:
        Classroom();

    public:
        Course *current_course();
        void assignCourse(Course* p_course);
};

#endif