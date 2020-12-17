#include "MTreeNode.h"

const int size = 2;

MTreeNode::MTreeNode(MTreeNode* parent)
{
	if (parent == nullptr)
		return;
	m_parent = parent;
	m_distance = parent->distance() + 1;
}

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

const MTreeNode* MTreeNode::child(int i) const
{
	return i > childCount() ? nullptr : m_children[i];
}

int MTreeNode::distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	return sizeof(m_children) / sizeof(*m_children);
}
bool MTreeNode::addChild(int i, int j)
{
	for (int n = 0; n < size; n++)
	{
		if (m_children[n] == nullptr)
		{
			m_children[n] = new MTreeNode(this);
			m_children[n]->m_i = i;
			m_children[n]->m_j = j;
			return true;
		}
	}
	return false;
}
MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (int n = 0; n < size; n++)
	{
		if (m_children[n] != nullptr && m_children[n]->i() == i && m_children[n]->j() == j)
			return m_children[n];
	}
	return nullptr;
}
MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* headNode = new MTreeNode(nullptr);
	headNode->m_i = i;
	headNode->m_j = j;
	headNode->m_distance = 0;
	return headNode;
}