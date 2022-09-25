// Doubly Linear linked list using template.
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCLL 
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int CountNode;

     public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int Count();
        void Display();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
 Head = NULL;
 Tail = NULL;
 CountNode = 0;   
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
 struct node<T> *newn = NULL;

  newn = new node<T>;

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if(Head == NULL)
  {
    Head = newn;
    Tail = newn; 
  }
  else
  {
    newn->next = Head;
    Head->prev = newn;
    Head = newn; 
  }
  CountNode++;   
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
 struct node<T> *newn = NULL;

  newn = new node<T>;

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if(Head == NULL)
  {
    Head = newn; 
    Tail = newn;
  }
  else
  {
    newn->prev = Tail;
    Tail->next = newn;
    Tail = newn;
  }
  CountNode++;   
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no, int iPos)
{
  int iSize = Count();

  if(iPos == 1)
  {
    InsertFirst(no);
  }
  else if (iPos == (iSize+1))
  {
    InsertLast(no);
  }
  else
  {
    struct node<T> *newn = NULL;
    struct node<T> *temp = Head;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; 

    for(int i=1;i<(iPos-1);i++)
    {
      temp = temp->next;  
    }
    
    newn->next = temp->next;
    temp->next = newn;
    newn->prev = temp; 
  }
  CountNode++;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
  if(Head == NULL)
  {
    return;
  }  
  else
  {
    struct node<T> * tempDel = Head;

    Head = Head->next;
    delete tempDel;
    Head->prev = NULL;
  }
  CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
  if(Head == NULL)
  {
    return;
  }  
  else
  {
    struct node<T> * tempDel = Tail;
    
    Tail = Tail->prev;
    Tail->next = NULL;
    delete tempDel;
  }
  CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
  int iSize = Count();

  if(iPos == 1)
  {
    DeleteFirst();
  }
  else if (iPos == iSize)
  {
    DeleteLast();
  }
  else
  {
    struct node<T> *temp = Head;
    struct node<T> *tempDel = NULL;

    for(int i=1;i<(iPos-1);i++)
    {
      temp = temp->next;  
    }

    tempDel = temp->next;
    
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete tempDel;

    CountNode--;
  }
}

template<class T>
void DoublyCLL<T>::Display()
{
  struct node<T> *temp = Head;

  while(temp != NULL)
  {
    cout<<"| "<<temp->data<<" |->";
    temp = temp->next;
  }  
  cout<<"NULL"<<endl;
}

template<class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}

int main()
{
    DoublyCLL <int>obj1;
    DoublyCLL <float>obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertAtPos(99,4);
    obj1.Display();

    obj1.DeleteAtPos(4);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Count of nodes is :"<<obj1.Count()<<endl;

    /*
    obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.26);
    obj2.InsertLast(51.51);
    obj2.InsertLast(101.26);
    obj2.InsertAtPos(99.99,4);

    obj2.DeleteAtPos(4);
    obj2.Display();
    cout<<"Count of nodes is :"<<obj2.Count()<<endl;
     */
    return 0;
}
