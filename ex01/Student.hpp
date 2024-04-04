#ifndef STUDENT_HPP
# define STUDENT_HPP


# include "Person.hpp"
# include "List.hpp"

class Course;
class Classroom;

class Student : public Person, public List<Course> {
    public:
        Student(std::string &p_name) : Person(p_name), List<Course>(true) {}

    public:
        void attendClass(Classroom *p_classroom);
        void exitClass();
        void graduate(Course* p_course);
        void subscribe(Course *p_course);
};

#endif