#pragma once

typedef struct Node
{
	int		idata;
	Node*	pNextNode;
};


typedef struct LinkedList
{
	Node*	pHeadNode;
	int		iCount;
};

