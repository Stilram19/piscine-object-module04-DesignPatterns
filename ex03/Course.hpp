#ifndef COURSE_HPP
# define COURSE_HPP

# include <iostream>
# include <vector>

class Student;
class Professor;

# define GLOBAL_MINIMUM_GRADE_TO_GRADUATE 60
# define GLOBAL_MAX_NUMBER_OF_STUDENTS 20

class Course {
    private:
        std::string _name;
        Professor *_responsable;
        std::vector<Student *> _students;
        int _minimumGradeToGraduate;
        int _maximumNumberOfStudents;

    public:
        Course(std::string p_name) : _name(p_name), _responsable(NULL), \
            _minimumGradeToGraduate(GLOBAL_MINIMUM_GRADE_TO_GRADUATE),  _maximumNumberOfStudents(GLOBAL_MAX_NUMBER_OF_STUDENTS) {}

    public:
        const std::string &get_name();

    public:
        void assign(Professor *p_professor);
        void subscribe(Student *p_student);
        void close();

    public:
        void setMinimumGradeToGraduate(int new_value) {
            this->_minimumGradeToGraduate = new_value;
            if (new_value < GLOBAL_MINIMUM_GRADE_TO_GRADUATE) {
                this->_minimumGradeToGraduate = GLOBAL_MINIMUM_GRADE_TO_GRADUATE;
            }
        }

        void setMaximumNumberOfStudents(int new_value) {
            this->_maximumNumberOfStudents = new_value;
            if (new_value > GLOBAL_MAX_NUMBER_OF_STUDENTS) {
                this->_maximumNumberOfStudents = GLOBAL_MAX_NUMBER_OF_STUDENTS;
            }
        }

        void setName(const std::string &name) {
            this->_name = name;
        }
};

#endif