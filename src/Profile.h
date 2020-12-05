#include "string"

#ifndef PINGPONG_PROFILE_H
#define PINGPONG_PROFILE_H

class Profile {

public:
    Profile();
    std::string name;
    int points;
    int record;

    void initRecord();
    void updateRecord(int);
};


#endif //PINGPONG_PROFILE_H
