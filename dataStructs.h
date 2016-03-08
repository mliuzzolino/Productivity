#include <iostream>
#include "nodes.h"

using namespace std;


// DATA STRUCTURE CLASS
template<class T>
class DataStructure
{
public:
	int listSize;
	Node<T>* headNode;
	char dataStructType;

	DataStructure(char DSType);
	DataStructure(char DSType, T initialData);

	void push(T theData);
	T pop();
	void traverse();
	int size(){ return listSize; }
	
};


template<class T>
DataStructure<T>::DataStructure(char DSType)
{
	dataStructType = DSType;
	listSize = 0;
	headNode = NULL;
}

template<class T>
DataStructure<T>::DataStructure(char DSType, T initialData)
{
	dataStructType = DSType;
	listSize = 1;
	headNode = new Node<T>(initialData, NULL);
}

template<class T>
void DataStructure<T>::push(T theData)
{
	if (dataStructType == 's' && listSize > 0)
	{
		headNode = new Node<T>(theData, headNode);
	}
	else if (dataStructType == 's' && listSize == 0)
	{
		headNode = new Node<T>(theData, NULL);
	}
	else if (dataStructType == 'q' && listSize > 0)
	{
		
		Node<T>* currentNode;
		currentNode = headNode;
		while(1)
		{
			if (currentNode->getLink() == NULL)
			{
				currentNode->setLink(new Node<T>(theData, NULL));
				break;
			}
			currentNode = currentNode->getLink();
		}
	}
	else if (dataStructType == 'q' && listSize == 0)
	{
		headNode = new Node<T>(theData, NULL);
	}

	listSize++;

	return;
}

template<class T>
T DataStructure<T>::pop()
{
	T data;

	data = headNode->getData();
	
	if (listSize == 1)
	{
		headNode = NULL;
	}
	else
	{
		headNode = headNode->getLink();
	}

	listSize--;

	return data;
}

template<class T>
void DataStructure<T>::traverse()
{

	if (listSize == 0)
	{
		cout << "*** Warning: List contains no nodes. ***" << endl;
		return;
	}
	Node<T>* currentNode;
	currentNode = headNode;

	int i = 1;
	while(1)
	{	
		cout << "Node " << i << ": " << currentNode->getData() << endl;

		if (currentNode->getLink() == NULL)
		{
			break;
		}

		currentNode = currentNode->getLink();
		i++;
	}
	return;
}