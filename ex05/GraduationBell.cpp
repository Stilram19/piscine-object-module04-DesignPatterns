# include "GraduationBell.hpp"
# include "observers.hpp"

void GraduationBell::lunchNotification(GraduationBellObserver *observer) {
    observer->prepareForGraduation();
}

void GraduationBell::ring() {
    this->forEach(&lunchNotification);
}

void GraduationBell::addObserver(BellObserver *observer) {
    GraduationBellObserver *spec_observer = dynamic_cast<GraduationBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->addItem(spec_observer);
    }
}

void GraduationBell::removeObserver(BellObserver *observer) {
    GraduationBellObserver *spec_observer = dynamic_cast<GraduationBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->removeItem(spec_observer);
    }
}
