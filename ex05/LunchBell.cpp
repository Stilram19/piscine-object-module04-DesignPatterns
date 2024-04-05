# include "LunchBell.hpp"
# include "observers.hpp"

void LunchBell::lunchNotification(LunchBellObserver *observer) {
    observer->LunchTime();
}

void LunchBell::ring() {
    this->forEach(&lunchNotification);
}

void LunchBell::addObserver(BellObserver *observer) {
    LunchBellObserver *spec_observer = dynamic_cast<LunchBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->addItem(spec_observer);
    }
}

void LunchBell::removeObserver(BellObserver *observer) {
    LunchBellObserver *spec_observer = dynamic_cast<LunchBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->removeItem(spec_observer);
    }
}
