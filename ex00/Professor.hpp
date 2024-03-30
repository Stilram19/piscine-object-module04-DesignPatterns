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
        void assignCourse(Course *p_course) {
            this->_currentCourse = p_course;
        }

        void doClass() {
            std::cout << "Prof doing \"" << this->_currentCourse->get_name() << "\"..." << std::endl;
        }

        void closeCourse() {
            std::cout << "Course \"" << this->_currentCourse->get_name() << "\" is closed!" << std::endl;
            this->_currentCourse = NULL;
            // maybe sign a form
        }
};

#endif