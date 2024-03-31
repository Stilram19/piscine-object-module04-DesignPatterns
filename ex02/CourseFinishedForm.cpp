# include "CourseFinishedForm.hpp"
# include "Course.hpp"

void CourseFinishedForm::execute() {
    if (this->_course == NULL) {
        return ;
    }

    // closing the course
    this->_course->close();
}

void CourseFinishedForm::fill_in(Course *course) {
    this->_course = course;
}