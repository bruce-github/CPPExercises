#include "Team.h"

Team::Team(unsigned int id) : pLast(NULL), pNext(NULL), m_id(id), m_time(0), m_error(0)
{
}

Team::~Team()
{
}

bool Team::update(unsigned int problemID, unsigned int submitTime, bool passed)
{
	if (m_problem.find(problemID) != m_problem.end())
	{
		return false;
	}
	else
	{
		if (passed)
		{
			m_problem.insert(problemID);
			m_time = submitTime;
			return true;
		}
		else
		{
			++m_error;
			return false;
		}
	}
}

unsigned int Team::solvedProblem()
{
	return m_problem.size();
}

unsigned int Team::costTime()
{
	return m_error*20 + m_time;
}

void Team::print(ostream &out)
{
	out << "ID: " << m_id << " solved: " << solvedProblem() << " costed:" <<  costTime() << endl; 
}

unsigned int Team::id()
{
	return m_id;
}
