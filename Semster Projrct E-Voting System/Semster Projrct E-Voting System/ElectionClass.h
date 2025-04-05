#ifndef ELECTION_H
#define ELECTION_H

#include "CandidateClass.h"
#include <iostream>
#include <string>

using namespace std;

class Election {
    int election_id;
    Candidate* candidate_info;
    int candidate_count;
    bool election_status;

public:
    Election();
    Election(int e, int c);
    int getCandidatecount();
    int getElectionId();
    Candidate * getCandidateinfo(); 
    void setCandidateinfo(Candidate* c,int ccount);
    void setElectionid(int e);
    void ElectionMenu();
    void endElection();
    void startElection();
    ~Election();
};

class LocalElection : public Election {
    static string level;

public:
    LocalElection();
    LocalElection(int e, int c);
};

class NationalElection : public Election {
    static string level;

public:
    NationalElection();
    NationalElection(int e, int c);
};

#endif // ELECTION_H
