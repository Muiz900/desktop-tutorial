#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>
#include<string>
using namespace std;
class Candidate 
{
    string name;
    string party;
    int votecount;
public:
    Candidate();
    ~Candidate();
    Candidate(string n, string p, int v);
    void setCandidate(string n, string p, int v);
    int getvotecount();
    string getName();
	string getParty();
};
#endif
