#ifndef _TEAM_H__
#define _TEAM_H__

#include <set>
#include <iostream>

using namespace std;

class Team
{
public:
	Team(unsigned int id);
	~Team();
	bool update(unsigned int problemID, unsigned int submitTime, bool passed);
	unsigned int solvedProblem();
	void print(ostream &out);
	unsigned int costTime();
	unsigned int id();

public:
	Team *pLast;
	Team *pNext;

private:
	unsigned int m_id;
	unsigned int m_time;
	unsigned int m_error;
	set<unsigned int> m_problem;
};

#endif
