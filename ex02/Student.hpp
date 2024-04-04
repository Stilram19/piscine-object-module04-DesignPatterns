#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;
class Classroom;

# include "Person.hpp"
# include "List.hpp"

class Student : public Person, List<Course> {
    private:
        std::vector<Course*> _subscribedCourse;

    public:
        Student(std::string &p_name) : Person(p_name), List<Course>(false) {}

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