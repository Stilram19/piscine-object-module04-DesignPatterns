#ifndef COURSE_HPP
# define COURSE_HPP

# include "List.hpp"

class Student;
class Professor;

# define NUMBER_OF_CLASS_TO_GRADUATE 60
# define MAX_NUMBER_OF_STUDENTS 20

class Course : List<Student> {
    private:
        std::string _name;
        Professor* _responsable;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;

    public:
        Course(std::string p_name) : _name(p_name), _responsable(NULL), \
            _numberOfClassToGraduate(NUMBER_OF_CLASS_TO_GRADUATE),  _maximumNumberOfStudent(MAX_NUMBER_OF_STUDENTS) {}

        const std::string &get_name() { return (this->_name); }

        void assign(Professor* p_professor) {
           this->_responsable = p_professor;
        }

        void subscribe(Student* p_student);
};

#endif