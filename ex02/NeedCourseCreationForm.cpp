# include "NeedCourseCreationForm.hpp"
# include "Course.hpp"
# include "singletons.hpp"

void NeedCourseCreationForm::execute() {
    if (this->course != NULL) {
        return ;// the form has already been executed
    }

    Course *newCourse;

    Course *newCourse = new Course(this->course_name);
    newCourse->setMinimumGradeToGraduate(this->_minimumGradeToGraduate);
    newCourse->setMaximumNumberOfStudents(this->_maximumNumberOfStudents);

    // adding the new course to the CourseList
    CourseList &instance_ref = CourseList::get_instance();

    instance_ref.addItem(newCourse);
}

void NeedCourseCreationForm::fill_in(int minimumGradeToGraduate, int maximumNumberOfStudents, std::string &course_name) {
    this->_minimumGradeToGraduate = minimumGradeToGraduate;
    this->_minimumGradeToGraduate = maximumNumberOfStudents;
    this->course_name             = course_name;
}
