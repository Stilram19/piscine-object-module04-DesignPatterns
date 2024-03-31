# include "SubscriptionToCourseForm.hpp"
# include "Course.hpp"

void SubscriptionToCourseForm::execute() {
    if (this->student == NULL || this->course == NULL) {
        return ;// can't execute the form
    }

    this->course->subscribe(this->student);
}

void SubscriptionToCourseForm::fill_in(Student *student, Course *course) {
    this->student = student;
    this->course = course;
}
