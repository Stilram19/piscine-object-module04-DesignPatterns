# include "Professor.hpp"
# include "Headmaster.hpp"
# include "CourseFinishedForm.hpp"
# include "NeedCourseCreationForm.hpp"
# include "NeedMoreClassRoomForm.hpp"
# include "Enums.hpp"
# include "Classroom.hpp"
# include "singletons.hpp"

// checks if the given room is a classroom and it is free
// this function is used to iterate over the list of rooms
bool Professor::is_classroom_and_empty(Room *room) {
    if (room == NULL) {
        return (false);
    }

    // checking if the room is a classroom
    if (dynamic_cast<Classroom *>(room) == NULL) {
        return (false);
    }

    return (room->is_free());
}

Room *Professor::findFreeRoom() {
    RoomList &instance_ref = RoomList::get_instance();
    Room *room = instance_ref.findItemIf(&is_classroom_and_empty);

    return (room);
}

void Professor::assignCourse(Course *p_course) {
    this->_currentCourse = p_course;
}

void Professor::requestNewClassroomCreation() {
        // requesting of the form
    NeedMoreClassRoomForm *needMoreClassRoomForm = dynamic_cast<NeedMoreClassRoomForm *>(this->headmaster->getNewForm(NeedMoreClassRoom));

    if (needMoreClassRoomForm == NULL) {
        return ;
    }

    // requesting the signature and execution of the form
    this->headmaster->sign(needMoreClassRoomForm);
}

void Professor::requestCourseCreation(int _minimumGradeToGraduate, int _maximumNumberOfStudents, const std::string &courseName) {
    // requesting the form
    NeedCourseCreationForm *needCourseCreationForm = dynamic_cast<NeedCourseCreationForm *>(this->headmaster->getNewForm(NeedCourseCreation));

    if (needCourseCreationForm == NULL) {
        return ;
    }

    needCourseCreationForm->fill_in(_minimumGradeToGraduate, _maximumNumberOfStudents, courseName, this);

    // requesting the signature and execution of the form
    this->headmaster->sign(needCourseCreationForm);
}

void Professor::doClass() {
    if (this->numberOfDoneClasses == this->numberOfClasses) {
        return ;
    }

    if (this->_currentCourse == NULL) {
        return ;
    }

    Classroom *classroom = dynamic_cast<Classroom *>(this->findFreeRoom());

    // requesting a new class to the headmaster if no free room found
    if (classroom == NULL) {
        this->requestNewClassroomCreation();
        classroom = dynamic_cast<Classroom *>(this->findFreeRoom()); // it will be found after the creation
    }

    this->enter(classroom);
    this->lastAttendedClassroom = classroom;
    classroom->assignCourse(this->_currentCourse);

    this->numberOfDoneClasses++;
    std::cout << "Prof is having a class!" << std::endl;
}

void Professor::closeCourse() {
    if (this->numberOfDoneClasses < this->numberOfClasses) {
        this->numberOfClasses = this->numberOfDoneClasses;// setting the mandatory number
        // of course classes, with the finished classes so far.
        // this will ensure that we fairly decide the graduation of students
    }

    if (this->headmaster == NULL || this->_currentCourse == NULL) {
        return ;
    }

    // requesting the form
    CourseFinishedForm *courseFinishedForm = dynamic_cast<CourseFinishedForm *>(this->headmaster->getNewForm(CourseFinished));

    if (courseFinishedForm == NULL) {
        return ;
    }

    courseFinishedForm->fill_in(this->_currentCourse);

    // requesting the signature and execution of the form
    this->headmaster->sign(courseFinishedForm);

    this->numberOfDoneClasses = 0;
    this->_currentCourse = NULL;
}

void Professor::setNumberOfClasses(int numberOfClasses) {
    this->numberOfClasses = numberOfClasses;

    // making sure that the numberOfClasses is reasonable
    if (this->numberOfClasses > MAX_NUMBER_OF_CLASSES) {
        this->numberOfClasses = MAX_NUMBER_OF_CLASSES;
    }

    if (this->numberOfClasses < MANDATORY_NUMBER_OF_CLASSES) {
        this->numberOfClasses = MANDATORY_NUMBER_OF_CLASSES;
    }
}

int Professor::getNumberOfClasses() const {
    return (this->numberOfClasses);
}

// the repeated implementation in each of Professor and Student will differ
// in a serious implementation.

void Professor::pauseStarts() {
    this->exit();
}

void Professor::pauseOver() {
    this->enter(this->lastAttendedClassroom);
}
