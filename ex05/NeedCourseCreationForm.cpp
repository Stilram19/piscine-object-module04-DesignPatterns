# include "NeedCourseCreationForm.hpp"
# include "Course.hpp"
# include "singletons.hpp"
# include "Professor.hpp"

void NeedCourseCreationForm::execute() {
    if (this->responsable == NULL) {
        return ;
    }

    Course *newCourse = new Course(this->course_name);
    newCourse->setMinimumGradeToGraduate(this->_minimumGradeToGraduate);
    newCourse->setMaximumNumberOfStudents(this->_maximumNumberOfStudents);

    this->responsable->assignCourse(newCourse);
    newCourse->assign(this->responsable);

    // adding the new course to the CourseList
    CourseList &instance_ref = CourseList::get_instance();

    instance_ref.addItem(newCourse);
}

void NeedCourseCreationForm::fill_in(int minimumGradeToGraduate, int maximumNumberOfStudents, const std::string &course_name, Professor *responsable) {
    this->_minimumGradeToGraduate = minimumGradeToGraduate;
    this->_minimumGradeToGraduate = maximumNumberOfStudents;
    this->responsable = responsable;
    this->course_name = course_name;
}
