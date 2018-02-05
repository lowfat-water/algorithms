#ifndef NODE_H
#define NODE_H

using namespace std;


// linked list node
template <typename T>
class node
{
   public:
      T cardInfo;      // data held by the node
      node<T> *next;    // next node in the list

      // default constructor with no initial value
      node() : next(NULL)
      {}

      // constructor. initialize nodeValue and next
      node(const T& item, node<T> *nextNode = NULL) : 
			  cardInfo(item), next(nextNode)
      {}
      
};

#endif   // NODE_CLASS