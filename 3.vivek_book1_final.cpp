#include<iostream>
#include<string.h>
using namespace std;

class tnode{
	string name;
	int flag;
	tnode *next;
	tnode *down;
	public:
		tnode(string val){
			name=val;
			flag=0;
			next=down=NULL;
		}
		friend class tree;
};

class tree{
	tnode*root;
	tnode*chapter;
	tnode*section;
	tnode*subsection;
	public:
		tree(){
			root=chapter=section=subsection=NULL;
		}
	
	
	void insert()
	{
		string val;
		if(root==NULL){
			cout<<"Enter the name of the book :";
			cin>>val;
			
			root=new tnode(val);
			cout<<"Now creating the book...";
		}
		else{
			int n,m,s;
			cout<<"Enter number of chapters to insert: ";
			cin>>n;
			
			for(int i=1;i<=n;i++){
				cout<<"Enter name of chapter."<<i<<" ";
				cin>>val;
				chapter=new tnode(val);
				chapter->next=root->down;
				chapter->down=NULL;
				root->down=chapter;
				root->flag=1;
				chapter->flag=0;
				
				cout<<"Enter number of sections:";
				cin>>m;
				for(int j=1;j<=m;j++){
					cout<<"Enter name of section"<<j<<" ";
					cin>>val;
					section=new tnode(val);
					section->next=chapter->down;
					section->down=NULL;
					chapter->down=section;
					chapter->flag=1;
					section->flag=0;
					
					cout<<"Enter number of subsections:";
					cin>>s;
					for(int k=1;k<=s;k++){
						cout<<"enter name of subsection: ";
						cin>>val;
						subsection=new tnode(val);
						subsection->next=section->down;
						subsection->down=NULL;
						section->down=subsection;
						section->flag=1;
						subsection->flag=0;
					}
					
				} 
			}
		}
	}
	
	void display(tnode *root){
		tnode*temp=root;
		tnode*t1;
		tnode*t2;
		if(temp!=NULL){
			cout<<"NAme of the book is:"<<temp->name<<endl;
			if(temp->flag=1 && temp->down!=NULL){
				temp=temp->down;
				while(temp!=NULL){
					cout<<"name of the chapter is "<<temp->name<<endl;
					t1=temp;
					if(t1->flag=1 && t1->down!=NULL){
						t1=t1->down;
						while(t1!=NULL){
							cout<<"name of section "<<t1->name<<endl;
							t2=t1;
							if(t2->flag=1 && t2->down!=NULL){
								t2=t2->down;
								while(t2!=NULL){
									cout<<"name of subsection is:"<<t2->name<<endl;
									t2=t2->next;
								}
							}
							t1=t1->next;
						}
					}
					temp=temp->next;
				}
			}
		}
	}
	
	void display(){
		display(root);
	}
	
	
};

int main(){
    tree g;
    int ch;
    do{
        cout<<"Enter your choice\n1.Create\n2.Display\n3.Exit";
        cin>>ch;
        switch (ch)
        {
        case 1:
            g.insert();
            break;
        case 2:
        g.display();
        }
    }while(ch!=3);
}
