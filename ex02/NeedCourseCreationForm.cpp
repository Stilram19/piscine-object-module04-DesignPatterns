# include "NeedCourseCreationForm.hpp"
# include "Course.hpp"

void NeedCourseCreationForm::execute() {
    if (this->course != NULL) {
        return ;// the form has already been executed
    }

    this->course = new Course(this->course_name);
    this->course->setMinimumGradeToGraduate(this->_minimumGradeToGraduate);
    this->course->setMaximumNumberOfStudents(this->_maximumNumberOfStudents);
}

void NeedCourseCreationForm::fill_in(int minimumGradeToGraduate, int maximumNumberOfStudents, std::string &course_name) {
    this->_minimumGradeToGraduate = minimumGradeToGraduate;
    this->_minimumGradeToGraduate = maximumNumberOfStudents;
    this->course_name             = course_name;
}

Course *NeedCourseCreationForm::get_course() const {
    return (this->course);
}
