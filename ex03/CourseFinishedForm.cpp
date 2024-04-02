# include "CourseFinishedForm.hpp"
# include "Course.hpp"

void CourseFinishedForm::execute() {
    if (this->_course == NULL) {
        return ;
    }

    // letting the receiver complete the job
    this->_course->close();
    std::cout << "Course \"" << this->_course->get_name() << "\" is closed!" << std::endl;
}

void CourseFinishedForm::fill_in(Course *course) {
    this->_course = course;
}
