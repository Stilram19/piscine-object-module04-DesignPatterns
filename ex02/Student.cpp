# include "Student.hpp"
# include "Classroom.hpp"

bool Student::is_subscribed(Course *p_course) {
    for (std::vector<Course *>::const_iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
        if (p_course == *course) {
            return (true);
        }
    }
    return (false);
}

void Student::erase_course(Course *p_course) {
    for (std::vector<Course *>::iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
        if (p_course == *course) {
            this->_subscribedCourse.erase(course);
            return ;
        }
    }
}

void Student::attendClass(Classroom *p_classroom) {
    if (p_classroom == NULL) {
        return ;
    }

    if (this->is_subscribed(p_classroom->current_course())) {
        this->enter(p_classroom);
    }
}

void Student::exitClass() {
    this->exit();
}

void Student::graduate(Course* p_course) {
    if (p_course == NULL) {
        return ;
    }

    this->erase_course(p_course);
}

void Student::subscribe(Course *p_course) {
    if (p_course == NULL) {
        return ;
    }

    if (is_subscribed(p_course)) {
        return ;
    }

    this->_subscribedCourse.push_back(p_course);
}
