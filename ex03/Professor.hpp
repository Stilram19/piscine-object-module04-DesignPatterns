#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

class Course;
class Headmaster;

# include "Staff.hpp"

class Professor : public Staff {
    private:
        Course *_currentCourse;
        Headmaster *headmaster;// mediator

    public:
        Professor(std::string &p_name, Headmaster *headmaster) : Staff(p_name), _currentCourse(NULL) {}

    public:
        void assignCourse(Course *p_course);
        void doClass();
        void closeCourse();
};

#endif