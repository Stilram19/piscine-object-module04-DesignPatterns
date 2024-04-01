# include "Professor.hpp"
# include "Course.hpp"
# include "Headmaster.hpp"

void Professor::assignCourse(Course *p_course) {
    if (this->_currentCourse == p_course) {
        return ;
    }

    this->_currentCourse = p_course;

    if (this->_currentCourse != NULL) {
        this->_currentCourse->assign(this);
    }
}

void Professor::doClass() {
    std::cout << "Prof doing \"" << this->_currentCourse->get_name() << "\"..." << std::endl;
}

void Professor::closeCourse() {
    std::cout << "Course \"" << this->_currentCourse->get_name() << "\" is closed!" << std::endl;
    this->_currentCourse = NULL;
}
