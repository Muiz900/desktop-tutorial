#include "UserClass.h"
User::User()//Default Constructor
	{
		cout << "User Default Constructor" << endl;
		uname = "";
		pass = "";
	}
User::	User(string u, string p)//Parameterized Constructor
	{
		cout << "User Parameterized Constructor" << endl;
		uname = u;
		pass = p;
	}
User::User(User& u)//Copy Constructor
	{
		cout << "User Copy Constructor" << endl;
		uname = u.uname;
		pass = u.pass;
	}
bool User:: userlogin()
	{
		string u, p;
		cout << uname << endl;
		cout << "Enter Username";
		cin.ignore();
		getline(cin, u);
		cout << pass << endl;
		cout << "Enter Password";
		getline(cin, p);
		if (uname == u && pass == p)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
void User:: usersignup()
	{
		cout << "Enter Username: ";
		cin >> uname;
		cout << "Enter Password: ";
		cin >> pass;
		User u(uname, pass);
	}

Voter::	Voter() {};
Voter::	Voter(string u, string p) :User(u, p)
	{
		cout << "Voter Parameterized Constructor" << endl;
	}
void Voter:: VoteMenu()
	{
		cout << "1. Cast Vote" << endl;
		cout << "2. View Results" << endl;
		cout << "3. Exit" << endl;
	}
void Voter::castVote()
	{

	}
Admin::Admin(): User(), no_of_LElection(NULL), no_of_NElection(NULL),NEcount(0),LEcount(0) {};
Admin::Admin(int ne,int le,string u, string p):User(u, p),NEcount(ne),LEcount(le), no_of_LElection(NULL), no_of_NElection(NULL)
	{
		cout << "Admin Parameterized Constructor" << endl;
	}
void Admin:: AdminMenu()
	{
		cout << "1.Create Election" << endl;
		cout << "2.Add Candidates" << endl;
		cout << "3.Start Election" << endl;
		cout << "4.View Election" << endl;
	}
void Admin::createElections() {
		int count = 0;
		cout << "Enter Number of Elections" << endl;
		cin >> count;
		cout << "Select Type of Election" << endl;
		cout << "1.National" << endl;
		cout << "2.Local" << endl;
		cout << "Enter Choice" << endl;
		int choice = 0;
		cin.ignore();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			// Create an array of NationalElection objects
			int election_id = 0;
			int candidate_count = 0;
			NationalElection* no_of_NElection = new NationalElection[count];
			NEcount = count;
			/*for (int i = 0;i < count;i++)
			{
				cout << "Enter Election ID For "<<i+1<<" election" << endl;
				cin >> election_id;
				no_of_NElection[i].setElectionid(election_id);
				cout << no_of_LElection[i].getElectionId() << endl;
			}
			*/break;
		}
		case 2:

		{
			int election_id = 0;
			int candidate_count = 0;
			LocalElection* no_of_NElection = new LocalElection[count];
			LEcount = count;
			for (int i = 0;i < count;i++)
			{
				cout << "Enter Election ID For " << i + 1 << " election" << endl;
				cin >> election_id;
				no_of_NElection[i].setElectionid(election_id);
			}

			break; 
		}
		default:
			cout << "Invalid Choice" << endl;
		}
}
void Admin::startElection() 
{
	int choice = 0;
	cout << "Enter Election Type" << endl;
	cout << "1.National" << endl;
	cout << "2.Local" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			int e_id = 0;cout << NEcount<<endl;
			cout << "Enter election id to start election" << endl;
			cin >> e_id;
			for (int i = 0;i < NEcount;i++)
			{
				if (no_of_NElection->getElectionId() == e_id) {
					no_of_NElection[i].startElection();
					return;
				}
			}cout << "Election ID not found" << endl;

			break;
		}
		case 2: 
		{
			int e_id = 0;
			cout << "Enter election id to start election" << endl;
			cin >> e_id;
			for (int i = 0;i < LEcount;i++)
			{
				if (no_of_LElection[i].getElectionId() == e_id) {
					no_of_LElection[i].startElection();
					return;
				}
				
			}cout << "Election ID not found" << endl;
			break;
		}
			default:
			cout << "Invalid Choice" << endl;
	}
    
}
void Admin::addCandidates() {
		cout << "NeCOUnt" << NEcount << endl;
	cout << "Enter Election Type" << endl;
	cout << "1.National" << endl;
	cout << "2.Local" << endl;
	int choice = 0;
	cin >> choice;
		int election_id = 0;

		int index = -1;
	switch (choice)
	{
	case 1:
	{
		int t_eid = 0;
		cout << "Enter election id to add candidates" << endl;
		cin >> election_id;
		for (int i = 0;i < NEcount;i++)
		{
			cout << "Loop number" << i << endl;
			if (election_id == (no_of_NElection+i)->getElectionId()) {
				index = i;
				cout << "ID Found" << endl;
				break;
			}
			
		}
		if (index == -1) {
			cout << "Election ID not found" << endl;
			return;
		}
		cout << "Index" << index << endl;
			int count = 0;
			cout << "Enter Number of Candidates" << endl;
			cin >> count;
			if (no_of_NElection[index].getCandidateinfo() != NULL)
			{
				delete[] no_of_NElection[index].getCandidateinfo();
			}
			Candidate* candidate_info = new Candidate[count];
			for (int i = 0;i < count;i++)
			{
				string name, party;
				
				cout << "Enter Candidate Name" << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter Candidate Party" << endl;
				getline(cin, party);
				candidate_info[i].setCandidate(name, party, 0);
			}
			no_of_NElection[index].setCandidateinfo(candidate_info, count);
			break;

		}
	case 2:
	{
		cout << "Enter election id to add candidates" << endl;
		cin >> election_id;
		for (int i = 0;i < LEcount;i++) {
			if (election_id == no_of_LElection[i].getElectionId()) {
				index = i;
				break;
			}
			else {
				cout << "Election ID not found" << endl;
				return;
			}
		}
			int count = 0;
			cout << "Enter Number of Candidates" << endl;
			cin >> count;
			if (no_of_LElection[index].getCandidateinfo() != NULL)
			{
				delete[] no_of_LElection[index].getCandidateinfo();
			}
			Candidate* candidate_info = new Candidate[count];
			for (int i = 0;i < count;i++)
			{
				string name, party;
				int votecount = 0;
				cout << "Enter Candidate Name" << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter Candidate Party" << endl;
				getline(cin, party);
				candidate_info[i].setCandidate(name, party, votecount);
			}
			no_of_LElection[index].setCandidateinfo(candidate_info, count);
			break;
		
	}
	default:
		cout << "Invalid Choice" << endl;

	}

	
}
	



