# include "School.hpp"
# include "singletons.hpp"
# include "Professor.hpp"
# include "Student.hpp"

// methods

void  School::launchClasses() {
    // ask all professors to launch their classes
    for (std::vector<Professor *>::iterator item = List<Professor>::items.begin(); item != List<Professor>::items.end(); item++) {
        this->headmaster.askProfToAttendClass(*item);
        Course *course = (*item)->getCurrentCourse();
        Classroom *classroom = (*item)->getCurrentClassroom();

        // command all students subscribed to the prof's current course to attend the class
        for (std::vector<Student *>::iterator item = List<Student>::items.begin(); item != List<Student>::items.end(); item++) {
            if ((*item)->is_subscribed(course) == true) {
                this->headmaster.commandStudentToAttendClass(*item, classroom);
            }
        }
    }
}

void  School::runDayRoutine() {
    this->launchClasses();
    this->requestRingBell();
    this->launchClasses();
    this->requestRingBell();
    this->launchClasses();
    this->requestRingBell();
    this->launchClasses();
}

void  School::requestRingBell() {
    this->headmaster.doEvent(RingBell); // break
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
    return (this->secretary);
}

Headmaster School::getHeadmaster() const {
    return (this->headmaster);
}
