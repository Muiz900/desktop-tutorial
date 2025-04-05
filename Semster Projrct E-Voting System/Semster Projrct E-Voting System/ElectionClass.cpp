#include "ElectionClass.h"
Election::Election() :candidate_info(nullptr), candidate_count(0),election_status(false) {
    cout << "Election Default Constructor" << endl;
    cout << "Enter Election ID For election" << endl;
    cin >> election_id;

}
int Election::getElectionId() {
	
    return election_id;
}
int Election::getCandidatecount() { return candidate_count; }
void Election::setCandidateinfo(Candidate* c,int count) {
	if (candidate_info != nullptr) {
		delete[] candidate_info;
	}
	candidate_info = new Candidate[count];
    for (int i = 0;i < count;i++)
	{
		candidate_info[i].setCandidate(c[i].getName(), c[i].getParty(), c[i].getvotecount());
	}
    
}
Candidate* Election::getCandidateinfo() {
	return candidate_info;
}

Election::Election(int e, int c) : election_id(e), candidate_count(c) ,election_status(false){
    cout << "Election Parameterized Constructor" << endl;
    candidate_info = NULL;
}

void Election::setElectionid(int e) {
    
    election_id = e;
    election_status = false;
}

void Election::ElectionMenu() {
    cout << "1. Start Election" << endl;
    cout << "2. End Election" << endl;
    cout << "3. Exit" << endl;
}

void Election::startElection() {
    if (election_status == false) {
        election_status = true;
        cout << "Election Started" << endl;
    }else
		cout << "Election Already Started" << endl;
}
void Election::endElection() { 
    if(election_status==true){
        election_status = false; 
        cout << "Election Ended" << endl;
 }
else
cout << "Election Already Ended" << endl;
}
Election::~Election() {
    delete[] candidate_info;
}
LocalElection::LocalElection():Election(){
    cout << "Local Election Default Constructor" << endl;
}

LocalElection::LocalElection(int e, int c) : Election(e, c) {
    cout << "Local Election Parameterized Constructor" << endl;
}

NationalElection::NationalElection() :Election() { cout << "National Election Default Constrctor" << endl; }

NationalElection::NationalElection(int e, int c) : Election(e, c) {
    cout << "National Election Parameterized Constructor" << endl;
}
