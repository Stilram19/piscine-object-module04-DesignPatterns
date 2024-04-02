# include "Professor.hpp"

void Professor::assignCourse(Course *p_course) {
    this->_currentCourse = p_course;
}

void Professor::doClass() {
    std::cout << "Prof is having a class!" << std::endl;
}

void Professor::closeCourse() {
    this->_currentCourse = NULL;
}
