#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

# include "Course.hpp"
# include "Staff.hpp"

class Professor : public Staff {
    private:
        Course *_currentCourse;

    public:
        Professor(std::string &p_name) : Staff(p_name), _currentCourse(NULL) {}

    public:
        void assignCourse(Course *p_course);
        void doClass();
        void closeCourse();
};

#endif