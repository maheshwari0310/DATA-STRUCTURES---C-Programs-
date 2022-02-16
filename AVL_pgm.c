#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
struct node
{
	struct  node *lchild;
	int info;
	struct  node *rchild;
	int balance;
};
void inorder(struct node *ptr);
struct node *RotateLeft(struct node *pptr);
struct node *RotateRight(struct node *pptr);
struct node *insert(struct node *pptr, int ikey);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_LeftBalance(struct node *pptr);
struct node *insert_RightBalance(struct node *pptr);
struct node *del(struct node *pptr, int dkey);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);
struct node *del_LeftBalance(struct node *pptr,int *pshorter);
struct node *del_RightBalance(struct node *pptr,int *pshorter);
void display(struct node *ptr,int level);

int main()
{
	int choice,key;
	struct node *root = NULL;

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the key to be inserted : ");
			scanf("%d",&key);
			root = insert(root,key);
			break;
		 case 2:
			printf("Enter the key to be deleted : ");
			scanf("%d",&key);
			root = del(root,key);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
		    display(root,key);
		    break;
		 case 5:
			exit(1);
			break;
		 default:
			printf("Wrong choice\n");
			break;
		}
	}
}

struct node *insert(struct node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	
	{
		pptr = (struct node *) malloc(sizeof(struct node));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
	}
	else if(ikey < pptr->info)
	{
		pptr->lchild = insert(pptr->lchild, ikey);
		if(taller==TRUE)
			pptr = insert_left_check( pptr, &taller );
	}
	else if(ikey > pptr->info)
	{
		pptr->rchild = insert(pptr->rchild, ikey);  
		if(taller==TRUE)
			pptr = insert_right_check(pptr, &taller);
	}
	else 
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}
struct node *insert_left_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: 
		pptr->balance = 1;	
		break;
	 case -1:
		pptr->balance = 0;
		*ptaller = FALSE;
			break;
	 case 1:
		pptr = insert_LeftBalance(pptr);
		*ptaller = FALSE;
	}
	return pptr;
}
struct node *insert_right_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: 
		pptr->balance = -1;	 
		break;
	 case 1:  
		pptr->balance = 0; 
		*ptaller = FALSE;
		break;
	 case -1:  
		pptr = insert_RightBalance(pptr); 
		*ptaller = FALSE;
	}
	return pptr;
} 
struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)  
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else	 
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:			    
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					 
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:				 
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}
struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if(aptr->balance == -1) 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else	
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:
			pptr->balance = 1;  
			aptr->balance = 0;
			break;
		case 1:	
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:	
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}
struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->rchild;
	pptr->rchild = aptr->lchild; 
	aptr->lchild = pptr; 
	return aptr; 
}
struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->lchild;	
	pptr->lchild = aptr->rchild; 
	aptr->rchild = pptr;		
	return aptr; 
}
struct node *del(struct node *pptr, int dkey)
{
	struct node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) 
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		pptr->lchild = del(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info )
	{
		pptr->rchild = del(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else 
	{
	    if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )  
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			pptr->info = succ->info;
			pptr->rchild = del(pptr->rchild, succ->info);
			if( shorter == TRUE )
				pptr = del_right_check(pptr, &shorter);
		}
		else	
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) 
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) 
				pptr = pptr->rchild;
			else	
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
		}						
	}
	return pptr; 
}
struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: 
			pptr->balance = -1;	
			*pshorter = FALSE;
			break;
		case 1: 
			pptr->balance = 0;	
			break;            
		case -1: 
			pptr = del_RightBalance(pptr, pshorter); 
	}
	return pptr;
}
struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:			
			pptr->balance = 1;
			*pshorter = FALSE;
			break;
		case -1:
			pptr->balance = 0;
			break;
		case 1:
			pptr = del_LeftBalance(pptr, pshorter ); 
	}
	return pptr;
}
struct node *del_LeftBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 ) 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:					
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					
				pptr->balance = -1;		
				aptr->balance = 0;
				break;
			case -1:		
				pptr->balance = 0;	
				aptr->balance = 1;
		}
		bptr->balance = 0;			
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

struct node *del_RightBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)	
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);			
	}
	else if(aptr->balance == -1 )	
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);			
	}
	else							
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:					
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:				
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:			
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}
void display(struct node *ptr,int level)
{
	int i;
	if(ptr == NULL )
		return;
	else
    {
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}
