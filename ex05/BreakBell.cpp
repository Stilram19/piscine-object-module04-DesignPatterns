# include "BreakBell.hpp"
# include "observers.hpp"

void BreakBell::pauseOverNotification(BreakBellObserver *observer) {
    observer->stopBreak();
}

void BreakBell::pauseStartsNotification(BreakBellObserver *observer) {
    observer->startBreak();
}

void BreakBell::ring() {
    this->isPauseOver = !(this->isPauseOver); // switch the state of the bell

    if (this->isPauseOver == true) {
        this->forEach(&pauseOverNotification);
        return ;
    }
    this->forEach(&pauseStartsNotification);
}

void BreakBell::addObserver(BellObserver *observer) {
    BreakBellObserver *spec_observer = dynamic_cast<BreakBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->addItem(spec_observer);
    }
}

void BreakBell::removeObserver(BellObserver *observer) {
    BreakBellObserver *spec_observer = dynamic_cast<BreakBellObserver *>(observer);

    if (spec_observer != NULL) {
        this->removeItem(spec_observer);
    }
}
