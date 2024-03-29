#ifndef SECRETARIAL_OFFICE_HPP
# define SECRETARIAL_OFFICE_HPP

class Form;

# include "Room.hpp"

class SecretarialOffice: public Room {
    private:
        std::vector<Form*> _archivedForms;

    public:

};

#endif