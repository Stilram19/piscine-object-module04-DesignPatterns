# include "Student.hpp"
# include "Classroom.hpp"
# include "Headmaster.hpp"
# include "SubscriptionToCourseForm.hpp"

bool Student::is_subscribed(Course *p_course) const {
    for (std::map<Course *, int>::const_iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
        if (p_course == course->first) {
            return (true);
        }
    }
    return (false);
}

void Student::erase_course(Course *p_course) {
    for (std::map<Course *, int>::iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
        if (p_course == course->first) {
            this->_subscribedCourse.erase(course);
            return ;
        }
    }
}

void Student::attendClass(Classroom *p_classroom) {
    if (p_classroom == NULL) {
        return ;
    }

    Course *course = p_classroom->current_course();

    if (this->is_subscribed(course)) {
        this->enter(p_classroom);
        this->_subscribedCourse[course]++; // marking the presence of the student
    }
}

void Student::exitClass() {
    this->exit();
}

void Student::graduate(Course* p_course) {
    this->passedCoursesCount++;
    this->erase_course(p_course);
}

void Student::fail(Course *p_course) {
    this->erase_course(p_course);
}

void Student::subscribe(Course *p_course) {
    if (p_course == NULL) {
        return ;
    }

    // requesting of the form
    SubscriptionToCourseForm *subscriptionToCourseForm = dynamic_cast<SubscriptionToCourseForm *>(this->headmaster->getNewForm(SubscriptionToCourse));

    if (subscriptionToCourseForm == NULL) {
        return ;
    }

    subscriptionToCourseForm->fill_in(this, p_course);

    // requesting the signature and execution of the form
    this->headmaster->sign(subscriptionToCourseForm);

    this->_subscribedCourse[p_course]; // inserting the new course
}

int Student::getPassedCoursesCount() const {
    return (this->passedCoursesCount);
}

int Student::getNumberOfAttendedClasses(Course *p_course) {
    if (this->is_subscribed(p_course) == false) {
        throw std::out_of_range("Student isn't subscribed to the given Course!");
    }

    return (this->_subscribedCourse[p_course]);
}

int Student::getCoursesCount() const {
    return (this->_subscribedCourse.size());
}
