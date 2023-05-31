#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

class tnode{
	int data;
	tnode *left,*right;
	public:
		tnode()
		{
			data=0;
			left=right=NULL;
		}
		tnode(int val)
		{
			data=val;
			left=right=NULL;
		}
		friend class bintree;
};

class bintree
{
	tnode *root;
	public:
		bintree()
		{
			root=NULL;
		}
	
	
		
		
	bool isEmpty()
	{
		if(root==NULL)
		{
			return true;
		}
		else{
			return false;
		}
	}
	
	
		
	void create()
	{
		tnode *temp,*travel;
		int val;
		
		cout<<"Enter the data to be added "<<endl;
		cin>>val;
		
		temp=new tnode(val);
		
		if(root==NULL){
			root=temp;
			cout<<" BST Tree is empty ,Now creating new tree "<<endl;
			return;
		}
		
		else{
			travel=root;
			while(travel!=NULL)
			{
				if(temp->data==travel->data)
				{
					cout<<"Duplicate data "<<endl;
					return;
				}
				else if((temp->data<travel->data) && travel->left==NULL)
				{
					travel->left=temp;
					cout<<"value inserted"<<endl;
					break;
				}
				else if(temp->data<travel->data)									//above condition will become false if
				{															//travel->left is not null,then this condition
                    travel=travel->left;                                              //will execute and traverse to left
				}
				else if((temp->data>travel->data) && (travel->right==NULL))
				{
					travel->right=temp;
					cout<<"Value inserted "<<endl;
					break;
				}
				else{
					travel=travel->right;
				}
			}
		}
	}
	
	
	
	int search()
	{
		int val;
		tnode *travel;
		
		cout<<"ENter the node to search"<<endl;
		cin>>val;
		
		
		if(root==NULL)
		{
			cout<<"Node not in tree"<<endl;
			return 0;
		}
		else{
			travel=root;
			while(travel!=NULL)
			{
				if(val==travel->data)
				{
					cout<<"Node found "<<endl;
					return 0;
				}
				else if(val<travel->data)
				{
					travel=travel->left;
				}
				else{
					travel=travel->right;
				}
			}
			if(travel==NULL){
				cout<<"Node not found"<<endl;
			}
			
		}
	}
	
	
		
	void preorder(tnode *rt){
		stack<tnode*>s;
	
		while(rt!=NULL)
		{
			cout<<rt->data<<" ";
			s.push(rt);
			rt=rt->left;
		}
		while(!s.empty())
		{
			rt=s.top();
			s.pop();
			rt=rt->right;
			while(rt!=NULL)
			{
			cout<<rt->data<<" ";
			s.push(rt);
			rt=rt->left;
			}
			
		}
	}
	
	void display()
	{
		if(root==NULL){
			cout<<" Tree is Empty "<<endl;
		}
		
		else{
			preorder(root);
		}
	}
	
	
	void mirror(tnode *rt){
		if(rt!=NULL){
			
			tnode *temp=rt->left;
			rt->left=rt->right;
			rt->right=temp;
			
			mirror(rt->left);
			mirror(rt->right);
		}
	}
	
	void mirror(){
		mirror(root);
		display();
	}
	
	
	void minimum(){
		tnode *travel;
		
		if(root==NULL){
			cout<<"tree is empty."<<endl;
			return;
		}
		else{
			travel=root;
			while(travel->left!=NULL){
				travel=travel->left;
			}
			cout<<"Minimum is "<<travel->data;
		}
	}
	
	void maximum()
	{
		tnode *travel;
		if(root==NULL){
			cout<<"tree is empty ";
			return;
		}
		else{
			travel=root;
			while(travel->right!=NULL){
				travel=travel->right;
			}
			cout<<"Max is  "<<travel->data;
		}
	}
	
	int height(tnode *root){
		if(root==NULL){
			return -1;
		}
	    else if(root->left==NULL && root->right==NULL){
	    	return 1;
		}
		else{
			return max(height(root->left),height(root->right))+1;
		}
	}
	void Height(){
		if(root==NULL){
			cout<<" Tree os empty";
		}
		else
			height(root);
	}
	
	int max(int hl,int hr){
		if(hl>hr){
			return hl;
		}
		else{
			return hr;
		}
	}
	
};


int main()
{
	bintree obj;
	int choice;
	while(1){
		
		cout<<" BST tree operations \n 1.insert \n 2.display \n 3.exit \n 4.search\n 5.mirror\n 6.mimimum\n 7. maximum\n8.height\nEnter the choice "<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:obj.create();
			break;
			case 2:obj.display();
			break;
			case 3:exit(0);
			break;
			case 4:obj.search();
			break;
			case 5:obj.mirror();
			break;
			case 6:obj.minimum();
			break;
			case 7:obj.maximum();
			break;
			case 8:obj.Height();
			break;
			
		}
	}
	return 0;
	
}


