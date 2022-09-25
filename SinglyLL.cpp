//Singly linear LL using template 

#include<iostream>
using namespace std;

template<class T>
struct node 
{
  T data;
  struct node * next;  
};

template<class T>
class SinglyLL
{
  public:
    struct node<T> *Head;
    int Count;

    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void Display();
    int CountNode();

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T,int);
    void DeleteAtPos(int);
    
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
  Head = NULL;
  Count = 0;  
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
  struct node<T> *newn = NULL;

  newn = new node<T>;

  newn->data = no;
  newn->next = NULL;

  if(Head == NULL)
  {
    Head = newn; 
  }
  else
  {
    newn->next = Head;
    Head = newn; 
  }
  Count++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
  struct node<T> *newn = NULL;

  newn = new node<T>;

  newn->data = no;
  newn->next = NULL;

  if(Head == NULL)
  {
    Head = newn; 
  }
  else
  {
    struct node<T> *temp = Head;

    while(temp->next != NULL)
    {
      temp = temp->next;  
    }

    temp->next = newn;
  }
  Count++;
}

template<class T>
void SinglyLL<T> :: Display()
{
  cout<<"Elements in LL are:"<<endl;

  struct node<T> *temp = Head;

  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

template<class T>
int SinglyLL<T> :: CountNode()
{
  return Count;
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
  if(Head == NULL)
  {
    return;
  }
  else
  {
    struct node<T> *temp = Head;

    Head = Head->next;

    delete temp; 
  }
  Count--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
  if(Head == NULL)
  {
    return;
  }
  else
  {
    struct node<T> *temp = Head;

    while(temp->next->next != NULL)
    {
      temp = temp->next;
    } 

    struct node<T> *tempDel = temp->next;

    delete tempDel;

    temp->next = NULL;
    
  }
  Count--;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no,int Pos)
{
  if(Pos == 1)
  {
    InsertFirst(no);
  }
  else if(Pos == (Count+1))
  {
    InsertLast(no);
  }
  else
  {
   struct node<T> *newn = NULL;

   newn = new node<T>;

   newn->data = no;
   newn->next = NULL;

   struct node<T> *temp = Head;

   for(int i=1;i < (Pos-1);i++)
   {
     temp = temp->next;
   }

   newn->next = temp->next;
   temp->next = newn;

  }
  Count++;
}


template <class T>
void SinglyLL<T> :: DeleteAtPos(int Pos)
{
  if(Pos == 1)
  {
    DeleteFirst();
  }
  else if(Pos == Count)
  {
    DeleteLast();
  }
  else
  {
    struct node<T> *temp = Head;

    for(int i=1;i< (Pos-1);i++)
    {
      temp = temp->next;
    }

    struct node<T> *tempDel = temp->next;

    temp->next = temp->next->next;

     delete tempDel;
  }
}

int main()
{
  SinglyLL <int>obj1;

  SinglyLL <float>obj2;

  obj1.InsertFirst(21);
  obj1.InsertFirst(11); 
  obj1.InsertLast(51);
  obj1.InsertLast(101);

  obj1.InsertAtPos(99,2);
  obj1.DeleteAtPos(2);
  obj1.Display();

  obj1.DeleteFirst();
  obj1.DeleteLast();
  obj1.Display();


  obj2.InsertFirst(21.11);
  obj2.InsertFirst(11.11); 
  obj2.InsertLast(51.11);
  obj2.InsertLast(101.11);
  obj2.Display();

  obj2.InsertAtPos(99.99,2);
  obj2.DeleteAtPos(2);
  obj2.Display();

  obj2.DeleteFirst();
  obj2.DeleteLast();
  obj2.Display();
  
  return 0;   
}