#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;
class Classroom;
class Headmaster;

# include "Person.hpp"

class Student : public Person {
    private:
        Headmaster *headmaster;
        std::vector<Course*> _subscribedCourse;

    public:
        Student(Headmaster *headmaster, std::string &p_name) : headmaster(headmaster), Person(p_name) {}

    private:
        bool is_subscribed(Course *p_course);
        void erase_course(Course *p_course);

    public:
        void attendClass(Classroom *p_classroom);
        void exitClass();
        void graduate(Course *p_course);
        void subscribe(Course *p_course);
};

#endif