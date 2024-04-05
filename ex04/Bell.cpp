# include "Bell.hpp"
# include "observer.hpp"

void Bell::pauseOverNotification(BellObserver *observer) {
    observer->pauseOver();
}

void Bell::pauseStartsNotification(BellObserver *observer) {
    observer->pauseStarts();
}

void Bell::ring() {
    this->isPauseOver = !(this->isPauseOver); // switch the state of the bell

    if (this->isPauseOver == true) {
        this->forEach(&pauseOverNotification);
        return ;
    }
    this->forEach(&pauseStartsNotification);
}
