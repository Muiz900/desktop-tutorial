#include "CandidateClass.h"
Candidate::Candidate() : name(""), party(""), votecount(0) { cout << "Candidate Default Constructor called" << endl; }
Candidate::Candidate(string n, string p, int v = 0) : name(n), party(p), votecount(v) { cout << "Candidate Parametrized Constuctor is called" << endl; }
void Candidate:: setCandidate(string n, string p, int v) {
    name = n;
    party = p;
    votecount = v;
}
string Candidate::getName() {
	return name;
}
string Candidate::getParty() {
	return party;
}
int Candidate:: getvotecount() {
    return votecount;
}
Candidate::~Candidate(){}
