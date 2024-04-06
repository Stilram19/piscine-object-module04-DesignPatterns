# include "NeedCourseCreationForm.hpp"
# include "Course.hpp"
# include "singletons.hpp"
# include "Professor.hpp"

void NeedCourseCreationForm::execute() {
    if (this->responsable == NULL) {
        return ;
    }

    Course *newCourse = new Course(this->course_name);
    newCourse->setMinimumGradeToGraduate(DEFAULT_MINIMUM_GRADE_TO_GRADUATE);
    newCourse->setMaximumNumberOfStudents(DEFAULT_MAX_NUMBER_OF_STUDENTS);

    this->responsable->assignCourse(newCourse);
    newCourse->assign(this->responsable);

    // adding the new course to the CourseList
    CourseList &instance_ref = CourseList::get_instance();

    instance_ref.addItem(newCourse);
}

void NeedCourseCreationForm::fill_in(const std::string &course_name, Professor *responsable) {
    this->responsable = responsable;
    this->course_name = course_name;
}
