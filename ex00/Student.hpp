#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;
class Classroom;

# include "Person.hpp"

class Student : public Person {
    private:
        std::vector<Course*> _subscribedCourse;

    public:
        void attendClass(Classroom* p_classroom);
        void exitClass();
        void graduate(Course* p_course);
};

#endif