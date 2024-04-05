# include "observers.hpp"
# include "Classroom.hpp"

void BreakBellObserver::startBreak() {
    std::cout << this->observerType << " is taking a Break!" << std::endl;
    this->exit();
}

void BreakBellObserver::stopBreak() {
    std::cout << this->observerType << "'s Break is over!" << std::endl;
    this->enter(this->lastAttendedClassroom);
}

void LunchBellObserver::LunchTime() {
    std::cout << this->observerType << " is taking launch" << std::endl;
    this->exit();
}
