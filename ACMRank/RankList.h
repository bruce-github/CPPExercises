#ifndef _RANKLIST_H__
#define _RANKLIST_H__

#include "Team.h"
#include <map>
#include <iostream>

using namespace std;

class RankList
{
public:
	RankList(unsigned int time);
	~RankList();
	void submit(unsigned int teamID, unsigned int problemID, unsigned int time, bool passed);
	void print(ostream &out);

private:
	Team *remove(Team *pObj);
	void insert(Team *pPos, Team *pObj);
	Team *findPos(Team *pObj);
	bool compare(Team *pA, Team *pB);
	void addTail(Team *p);
	
private:
	Team *pHead;
	Team *pTail;
	map<unsigned int, Team *> teams;
	unsigned int startTime;
};

#endif
