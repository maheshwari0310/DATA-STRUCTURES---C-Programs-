/* LINKED LIST PROGARM */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int item);
struct node *addb(struct node *start,int data);
struct node *addafter(struct node *start,int data ,int item);
struct node *addbefore(struct node *start,int data ,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *adde(struct node *start,int data);
struct node *Delete(struct node *start,int data);
struct node *Reverse(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,data,item,pos;
	while(1)
	{
		printf("\n");
		printf("1.CREATE LIST\n");
		printf("2.DISPLAY LIST\n");
		printf("3.COUNT THE NO. OF NODES\n");
		printf("4.SEARCH AN ELEMENT AND DISPLAY ITS POSITION\n");
		printf("5.ADD AT THE BEGINNING\n");
		printf("6.ADD AT THE END\n");
		printf("7.ADD AFTER A NODE\n");
		printf("8.ADD BEFORE A NODE\n");
		printf("9.ADD AT A PARTICULAR POSITION\n");
		printf("10.DELETE A NODE\n");
		printf("11. REVERSE THE LINKED LIST \n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		printf("\n");

    	switch(choice)
	    {
	      	case 1:
		             start=create_list(start);
		             break;
	       	case 2: 
	        	     display(start);
		             break;
    		case 3:
       	    	     count(start);
	    	         break;
	     	case 4:
	     		     printf("Enter the element to be searched\n");
	     		     scanf("%d",&data);
		             search(start,data);
		             break;
	    	case 5:
	    		     printf("Enter the element\n");
	    		     scanf("%d",&data);
	    	         start=addb(start,data);
	    	         break;
	    	case 6 :
	    	     	 printf("Enter the element\n");
	    		     scanf("%d",&data);
	    	         start=adde(start,data);
	    	         break;
	    	       
	        case 7 :
			         printf("Enter the element to be inserted\n");
	     		     scanf("%d",&data);
	     		     printf("Enter the element after which you want to insert:");
	     		     scanf("%d",&item);
	    	         start=addafter(start,data,item);
	    	         break;
	    	       
	    	case 8 :
			         printf("Enter the element to be inserted\n");
	     		     scanf("%d",&data);
	     		     printf("Enter the element before which you want to insert:\n");
	     		     scanf("%d",&item);
	    	         start=addbefore(start,data,item);
	    	         break;
	    	       
            case 9 :
			         printf("Enter the element to be inserted\n");
                     scanf("%d",&data);
                     printf("Enter the position at which you want to insert\n");
                     scanf("%d",&pos);
                     start=addatpos(start,data,pos);
                     break;
                    
            case 10 :
			         printf("Enter the element to be deleted\n");
                     scanf("%d",&data);
			         start=Delete(start,data);
			         break;
			        
			case 11:
			        start=Reverse(start);
			        break;
			case 12:
			        exit(0);
			        break;
			        
	     	default: 
	    	       printf("Invalid case\n");
		     	   break; 
			printf("\n");  	          
	}
    }
    
	return 0;
}
struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes you want to add\n");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	{
		return start;
	}
		printf("Enter the elements to be inserted\n");
		scanf("%d",&data);
		start = addb(start,data);
		for(i=2;i<=n;i++)
		{
			printf("Enter the elements\n");
	    	scanf("%d",&data);
	    	start=adde(start,data);
	   	}
	    return start;
}
struct node *addb(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *adde(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=tmp;
	tmp->link=NULL;
	return start;
}
void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("Item %d is found at positon %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("Item %d is not found\n",item);
}
void count(struct node *start)
{
	struct node *p;
	int count=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		count++;
	}
	printf("The number of elements are : %d\n",count);
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("The list is empty\n");
		return;
	} 
	p=start;
	printf("LIST IS :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}
struct node *addafter(struct node *start,int data ,int item)
{
	struct node *p,*tmp;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("Item %d not found in the list\n",item);
	return start;
}
struct node *addbefore(struct node *start,int data ,int item)
{
	struct node *p,*tmp;
	if(start==NULL)
	{
		printf("Empty List\n");
		return start;
	}
	if(start->info==item)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
	    	tmp->info=data;
	    	tmp->link=p->link;
	    	p->link=tmp;
	    	return start;
		}
		p=p->link;
	}
	printf("Item %d not found in the list\n");
	return start;
}
struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *p,*tmp;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start;
	    start=tmp;
	    return start;
    }
    p=start;
    for(i=1;i<pos-1&&p!=NULL;i++)
    {
    	p=p->link;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements\n",pos);
	}
	else
	{
		tmp->link=p->link;
	    p->link=tmp;
	}
	return start;
}
struct node *Delete(struct node*start,int data)
{
	struct node *p,*tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==data)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	
	printf("Element not found\n");
	return start;
}
struct node *Reverse(struct node*start)
{
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}	
	start=prev;
	return start;
}

