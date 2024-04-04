# include "School.hpp"
# include "singletons.hpp"

// methods

void  School::launchClasses() {

}

void  School::recreationTime() {
    this->headmaster.doEvent(RingBell);
}

void  School::runDayRoutine() {

}

void  School::requestRingBell() {

}

void  School::recruteProfessor() {

}

void  School::recruteStudent() {

}

// getters

Course* School::getCourse(std::string p_name) const {
    CourseList &instance_ref = CourseList::get_instance();

    return (instance_ref.getCourse(p_name));
}

std::vector<Student*> School::getStudents() const {
    return (List<Student>::getItems());
}

std::vector<Professor*> School::getProfessors() const {
    return (List<Professor>::getItems());
}

Secretary School::getSecretary() const {
    return (this->secretary)
}

Headmaster School::getHeadmaster() const {
    return (this->headmaster);
}
