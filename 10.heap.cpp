#include<iostream>
using namespace std;           //heap is level wise insertion
int const MAX=20;

class MaxHeap                       //position of left child =2*i
{                                   //position of right child =2*i+1
  public:                            //position of parent =i/2
  	    int lastindex;               
  	    
  	     MaxHeap()
          {
            lastindex=-1;
          } 
          
         void reheapup(int);
         void reheapdown();   
         void insert(int val);
         int findMax();
         int remove();
         void display();
         void swap(int a,int b);

   private:
          int data[MAX];
        
};

int MaxHeap::findMax(){
	return data[0];
}
void MaxHeap::swap(int a,int b)            //swap for maximum heap
{
   int temp;
   temp=data[a];
   data[a]=data[b]; 
   data[b]=temp;
}

void MaxHeap::reheapup(int child)
{
   int parent;
   if(child>0)
   {
     parent=(child-1)/2;
       if(data[parent]<data[child])
        {
           swap(parent,child);
           reheapup(parent); 
        }
   }     
}

void MaxHeap:: insert(int val)                //insert for maximum heap
{
   if(lastindex<MAX-1)
    {
       lastindex=lastindex+1;
       data[lastindex]=val;
       reheapup(lastindex);
    }
   else
    {
       cout<<"\nHEAP OVERFLOW\n";
    } 
 }

void MaxHeap::reheapdown()                
{
   int parent=0;
   int child;
   child=2*parent+1;
   while(child<=lastindex)
   {
      if(child<lastindex && data[child]<data[child+1])   //means bigger value is at child+1
       {
          child++;
       }
      if(data[parent]<data[child])
       {
          swap(parent,child);
          parent=child;
          child=2*parent+1;
       }
      else
       {
          break;
       }  
   }
}

int MaxHeap::remove()                    //remove or deletion for maximum heap
{
   data[0]=data[lastindex];
   lastindex=lastindex-1;
   reheapdown();
}

void MaxHeap::display()                   //display for maximum heap
{
   int i;
   cout<<"\nmax heap online marks are=  ";
   for(i=0;i<=lastindex;i++)
   {
      cout<<data[i]<<",";
   }
}

/////////////////////////////////////////////////////////////////////////////////////
class MinHeap
{
  public:
  	    int lastindex;
  	    
  	     MinHeap()
          {
            lastindex=-1;
          } 
         int findMin();          
         void reheapup(int);
         void reheapdown();   
         void insert(int val);
         int remove();
         void display();
         
         void swap(int a,int b);

   private:
          int data[MAX];
        
};

int MinHeap::findMin(){
	return data[0];
}
void MinHeap::swap(int a,int b)            //swap for maximum heap
{
   int temp;
   temp=data[a];
   data[a]=data[b]; 
   data[b]=temp;
}

void MinHeap::reheapup(int child)
{
   int parent;
   if(child>0)
   {
     parent=(child-1)/2;
       if(data[parent] > data[child])
        {
           swap(parent,child);
           reheapup(parent); 
        }
   }     
}

void MinHeap:: insert(int val)                //insert for maximum heap
{
   if(lastindex<MAX-1)
    {
       lastindex=lastindex+1;
       data[lastindex]=val;
       reheapup(lastindex);
    }
   else
    {
       cout<<"\nHEAP OVERFLOW\n";
    } 
}

void MinHeap::reheapdown()                
{
   int parent=0;
   int child;
   child=2*parent+1;
   while(child<=lastindex)
   {
      if(child<lastindex && data[child] > data[child+1])
       {
          child++;
       }
      if(data[parent] > data[child])
       {
          swap(parent,child);
          parent=child;
          child=parent*2+1;
       }
      else
       {
          break;
       }  
   }
}

int MinHeap::remove()                    //remove or deletion for maximum heap
{
   data[0]=data[lastindex];
   lastindex=lastindex-1;
   reheapdown();
}

void MinHeap::display()                   //display for maximum heap
{
   int i;
   cout<<"\nminheap online marks are=  " ;
   for(i=0;i<=lastindex;i++)
   {
      cout<<data[i]<<",";
   }
}


int main()
{
   MinHeap hMin;
   MaxHeap hMax;
   int ch,num;
                 do
                 {
                    cout<<"\n1.insert marks of online exam \n2.delete marks\n3.display the online marks\n4.Find Max and Min\n5.exit\n";
                    cout<<"\nenter your choice:";
                    cin>>ch;
                    switch(ch)
                    {
                       case 1:
                             cout<<"\nenter the marks which u want to insert in heap: ";
                             cin>>num;
                             hMax.insert(num);
                             hMin.insert(num);
                             break;
                       case 2:
                             hMax.remove();
                             hMin.remove();
                             break;
                       case 3:
                             hMax.display();
                             hMin.display();
                             break;
                       case 4:
                             cout<<"\nMaximum = "<<hMax.findMax();
                             cout<<"\nMinimum = "<<hMin.findMin();                             
                             return 0;                   
                             
                       case 5:
                             return 0;                   
                    }
                 }while(ch!=5);
           return 0;
}
