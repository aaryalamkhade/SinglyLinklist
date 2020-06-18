#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class node
{
	public:
int value;
node*next;	
};

class link
{
	public:
node*head,*curr;
link()
{
	head=NULL;

}
void insert_be();
void insert_pos();
void insert_ls();
void delete_l();
void update();
void sort_l();
void reverse();
void display();
};


void link::insert_be()
{
	int value;
	node *temp,*p;
	cout<<"enter the value:";
	cin>>value;
	temp=new node;
	temp->value=value;
	
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		p=head;
	   head=temp;
	   head->next=p;
	   	
	}
	
}


void link::insert_pos()
{
	int pos,value;
	cout<<"enter the pos where you want to insert the ele:"<<endl;
	cin>>pos;
	cout<<"enter the value:"<<endl;
	cin>>value;
	node*p,*temp;
	temp=new node;
	temp->value=value;
	p=head;
	for(int i=1;i<pos-1;i++)
	{   
		p=p->next;
		
	}
	
	temp->next=p->next;
	p->next=temp;
	
	
}


void link::insert_ls()
{
	node*temp,*p;
	temp=new node;
	int value;
	cout<<"enter the value:"<<endl;
	cin>>value;
	temp->value=value;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
     p->next=temp;
    temp->next=NULL;
    }
}

void link::delete_l()
{
int no;
int count=0;;
cout<<"enter the number you want to delete:"<<endl;
cin>>no;
node*p,*q;
p=head;

while(p->value!=no)
{   q=p;
	p=p->next;
	count++;
}

if(count==0)
{
head=p->next;	
}

else
{
	
q->next=p->next;
	      
}


}

void link::update()
{
	int value,pos;
	cout<<"enter the pos of update:";
	cin>>pos;
	cout<<"enter the value:";
	cin>>value;
	node*temp;
	temp=new node;
	temp->value=value;
	node*p,*q;
	p=head;
	if(pos==1)
	{
		head=temp;
		head->next=p->next;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{   q=p;
			p=p->next;
		}
		temp->next=p->next;
		p=temp;
		q->next=temp;
	}
}

void link::sort_l()
{
	
    node*p,*s;
    p=head;
    for(p=head;p!=NULL;p=p->next)
    {
    	for(s=p->next;s!=NULL;s=s->next)
    	{
    		if(p->value>s->value)
    		{
    			int temp=p->value;
    			p->value=s->value;
    			s->value=temp;
			}
		}
		
	}
	
}

void link::reverse()
{
node*p,*q;
p=head;
q=head;
curr=q;
p=p->next;
curr->next=NULL;
while(p!=NULL)
{  
q=p;
p=p->next;
q->next=curr;
curr=q;
}
head=curr;
}

void link::display()
{
node*p;
p=head;
    while(p->next!=NULL)
   {
   	  cout<<p->value<<"->";	
      p=p->next;
   }
   if(p!=NULL)
   {
   	   cout<<p->value<<endl;
	}	
}

int main()
{
	link l;
	int choice;
	int ch;
	do
	{
		cout<<"enter the choice: 1.insert at begin  2.insert at pos 3.insert at last 4.delete 5.update  6.sort 7.Reverse 8.display"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: 
			       l.insert_be();
			       break;
		    case 2:
			        l.insert_pos();
					break;
			case 3:
			        l.insert_ls();
					break;
			case 4:
				    l.delete_l();
				    break;
			case 5:
				    l.update();
				    break;
		    case 6:
		    	    l.sort_l();
		    	    break;
			case 7:  
			        l.reverse();
					break;
			case 8:  
			        l.display();
					break;		
								       
		}
		cout<<"press 1 for loop:"<<endl;
		cin>>ch;
		
	}while(ch==1);

}
