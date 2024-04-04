#ifndef COURSE_HPP
# define COURSE_HPP

# include "List.hpp"

class Student;
class Professor;
class CourseFinishedForm;

# define DEFAULT_MINIMUM_GRADE_TO_GRADUATE 60
# define DEFAULT_MAX_NUMBER_OF_STUDENTS 20

class Course : public List<Student> {
    private:
        std::string _name;
        Professor *_responsable;
        int _minimumGradeToGraduate;
        int _maximumNumberOfStudents;

    public:
        Course(std::string p_name) : List<Student>(false), _name(p_name), _responsable(NULL), \
            _minimumGradeToGraduate(DEFAULT_MINIMUM_GRADE_TO_GRADUATE),  _maximumNumberOfStudents(DEFAULT_MAX_NUMBER_OF_STUDENTS) {}
        ~Course() {}

    public:
        const std::string &get_name();

    public:
        void assign(Professor *p_professor);
        void subscribe(Student *p_student);
        void close();

    public:
        void setMinimumGradeToGraduate(int new_value) {
            this->_minimumGradeToGraduate = new_value;
            if (new_value < DEFAULT_MINIMUM_GRADE_TO_GRADUATE) {
                this->_minimumGradeToGraduate = DEFAULT_MINIMUM_GRADE_TO_GRADUATE;
            }
        }

        void setMaximumNumberOfStudents(int new_value) {
            this->_maximumNumberOfStudents = new_value;
            if (new_value > DEFAULT_MAX_NUMBER_OF_STUDENTS) {
                this->_maximumNumberOfStudents = DEFAULT_MAX_NUMBER_OF_STUDENTS;
            }
        }

        void setName(const std::string &name) {
            this->_name = name;
        }
};

#endif