#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include"candidateClass.h"
#include"ElectionClass.h"
using namespace std;
class User
{
	string uname;
	string pass;
public:
	User();//Default Constructor
	User(string u, string p);//Parameterized Constructor
	User(User& u);//Copy Constructor
	bool userlogin();
	void usersignup();
};
class Voter :public User
{
	const string status="Voter";
public:
	Voter();
	Voter(string u, string p);
	void VoteMenu();
	void castVote();
};
class Admin :public User
{
	int NEcount;
	int LEcount;
	NationalElection* no_of_NElection;
	LocalElection* no_of_LElection;
	const string status="Admin";
public:
	Admin();
	Admin(int ne,int le,string u, string p) ;
	void AdminMenu();
	void addCandidates();
	void createElections();
	void startElection();

};
#endif 