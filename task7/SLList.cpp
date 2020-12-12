#include "SLList.h"

SLList::SLList(int data)
{
	m_nextElem = NULL;
	m_data = data;
}

int SLList::getData()
{
	return m_data;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList* SLList::next()
{
	return m_nextElem;
}

bool SLList::hasNext()
{
	return m_nextElem != NULL;
}


SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

SLList* SLList::addElement(int data)
{
	if (hasNext()) return nullptr;
	m_nextElem = new SLList(data);
	return m_nextElem;
}

SLList* SLList::addElement(SLList* next)
{
	if (hasNext()) return nullptr;
	m_nextElem = next;
	return m_nextElem;
}

void SLList::removeNext()
{
	free(m_nextElem);
	m_nextElem = NULL;
}

SLList::~SLList()
{
	if (hasNext())
		delete next();
}