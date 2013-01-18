#include "RankList.h"
#include <cassert>

using namespace std;

//if A is better than B, compare() return true.
bool RankList:: compare(Team *pA, Team *pB)
{
	if (pA->solvedProblem() > pB->solvedProblem())
	{
		return true;
	}
	else if (pA->solvedProblem() < pB->solvedProblem())
	{
		return false;
	}
	else
	{
		if (pA->costTime() < pB->costTime())
			return true;
		else if (pA->costTime() > pB->costTime())
			return false;
		else
		{
			if (pA->id() < pB->id())
				return true;
			else
				return false;
		}
	}
}

RankList::RankList(unsigned int time) : pHead(NULL), pTail(NULL), startTime(time)
{
}

void RankList::submit(unsigned int teamID, unsigned int problemID, unsigned int time, bool passed)
{
	assert(time > startTime);
	if (time <= startTime)
	{
		return;
	}
	
	map<unsigned int, Team *>::iterator index = teams.find(teamID);
	if ( index == teams.end())
	{
		Team *p = new Team(teamID);
		index = (teams.insert(pair<unsigned int, Team *>(teamID, p))).first;
		addTail(p);
	}

	Team *pObj = index->second;

	if (pObj->update(problemID, time, passed))
	{
		Team *pPos = findPos(pObj);
		if (pPos != pObj)
		{
			pObj = remove(pObj);
			insert(pPos, pObj);
		}
	}
}
void RankList::print(ostream &out)
{
	Team *p = pHead;
	while (p)
	{
		p->print(out);
		p = p->pNext;
	}
}

RankList::~RankList()
{
	while (pTail)
	{
		Team *p = pTail->pLast;
		delete pTail;
		pTail = p;
	}
}

Team *RankList::findPos(Team *pObj)
{
	assert(pObj != NULL);
	if (pObj == NULL)
		return NULL;

	Team *p = pObj->pLast;
	while (p)
	{
		if (compare(p, pObj))
			break;
		else
			p = p->pLast;
	}

	if (p == NULL)
		return pHead;

	return p->pNext;
}

Team *RankList::remove(Team *pObj)
{
	assert(pObj != NULL);
	if (pObj == NULL)
		return NULL;

	if (pObj->pLast == NULL)
	{
		pHead = pObj->pNext;
	}
	else
	{
		pObj->pLast->pNext = pObj->pNext;
	}

	if (pObj->pNext == NULL)
	{
		pTail = pObj->pLast;
	}
	else
	{
		pObj->pNext->pLast = pObj->pLast;
	}

	pObj->pNext = NULL;
	pObj->pLast = NULL;

	return pObj;
}

void RankList::insert(Team *pPos, Team *pObj)
{
	assert(pPos != NULL && pObj != NULL);
	if (pPos == NULL || pObj == NULL || pPos == pObj)
		return;

	pObj->pLast = pPos->pLast;
	pObj->pNext = pPos;
	if (pPos->pLast != NULL)
	{
		pPos->pLast->pNext = pObj;
	}
	else
	{
		pHead = pObj;
	}
	pPos->pLast = pObj;
}

void RankList::addTail(Team *p)
{
	assert(p != NULL);
	if (p == NULL)
		return;

	
	if (pTail == NULL)
	{
		pHead = p;
	}
	else
	{
		pTail->pNext = p;
		p->pLast = pTail;
	}

	pTail = p;
}


















