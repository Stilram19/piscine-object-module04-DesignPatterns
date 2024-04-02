# include "SubscriptionToCourseForm.hpp"
# include "Course.hpp"

void SubscriptionToCourseForm::execute() {
    if (this->student == NULL || this->course == NULL) {
        return ;// form doesn't have important informations
    }

    // letting the receiver complete the job
    this->course->subscribe(this->student);
}

void SubscriptionToCourseForm::fill_in(Student *student, Course *course) {
    this->student = student;
    this->course = course;
}
