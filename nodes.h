#include <iostream>

using namespace std;

// NODE CLASS
template<class T>
class Node
{
public:
	Node(T theData, Node<T>* theLink): data(theData), link(theLink) {}

	T getData() { return data; }
	Node<T>* getLink() { return link; }

	void setData(T theData) { data = theData;} 
	void setLink(Node<T>* theLink) { link = theLink; }

private:
	T data;
	Node<T>* link;
};


