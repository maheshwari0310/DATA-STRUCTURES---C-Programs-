#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int dkey);
struct node *Min(struct node *ptr);
struct node *Max(struct node *ptr);
void display(struct node *ptr,int level);
int height(struct node *ptr);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void levelorder(struct node *ptr);
void levelnodes(struct node *root,int level);
void getLevelWidth(struct node* root, int cLevel, int level, int *width);
int getMaxWidth(struct node* root);
void CurrentLevel(struct node * root, int level) ;
int heightlev(struct node * node);
int main()
{
	struct node *root=NULL,*ptr;
	int choice,k;
	while(1)
	{
		printf("\n");
		printf("1.Search\n");
		printf("2.Insert\n");
		printf("3.Delete\n");
		printf("4.Preorder Traversal\n");
		printf("5.Inorder Traversal\n");
		printf("6.Postorder Traversal\n");
		printf("7.Levelorder Traversal\n");
		printf("8.Nodes on a level\n");
		printf("9.Height of tree\n");
		printf("10.Find minimum and maximum\n");
		printf("11.Display\n");
		printf("12.Width\n");
		printf("13.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1: 
			printf("Enter the key to be searched : ");
			scanf("%d",&k);
			ptr = search(root, k);
			if(ptr!=NULL)
				printf("Key found\n");
			break;
		case 2:
			printf("Enter the key to be inserted : ");
			scanf("%d",&k);
			root = insert(root, k);
			break;
		case 3:
			printf("Enter the key to be deleted : ");
			scanf("%d",&k);
			root = del(root,k);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			inorder(root);
			break;
		 case 6:
		 	postorder(root);
		 	break;
		  case 7:
		  	levelorder(root);
		  	break;
		  case 8:
		    printf("Enter the level\n");
			scanf("%d",&k);
			levelnodes(root,k);
			break;
		 case 9:
			 printf("Height of tree is %d\n", height(root));
			 break;
		 case 10:
			ptr = Min(root);
			if(ptr!=NULL)
				printf("Minimum key is %d\n", ptr->info );
			ptr = Max(root); 	
			if(ptr!=NULL)
				printf("Maximum key is %d\n", ptr->info );
			break;
		 case 11:
		 	display(root,k);
		 	break;
		 case 12:
		 	printf("Width is %d\n",getMaxWidth(root));
		 	break;
		 case 13:
			exit(1);
			break;
		 default:
			printf("Wrong choice\n");
		}
	}
}
struct node *search(struct node *ptr, int skey)
{
	if(ptr==NULL)   
	{	
		printf("key not found\n");
		return NULL;
	}
	else if(skey < ptr->info)
		return search(ptr->lchild, skey);	
	else if(skey > ptr->info)
		return search(ptr->rchild, skey);
	else
		return ptr;
}
struct node *insert(struct node *ptr, int ikey )
{
	if(ptr==NULL)	
	{
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)	
		ptr->lchild = insert(ptr->lchild, ikey);
	else if(ikey > ptr->info)	
		ptr->rchild = insert(ptr->rchild, ikey);  
	else
		printf("Duplicate key\n");
	return ptr;
}
struct node *del(struct node *ptr, int dkey)
{
	struct node *tmp, *succ;

	if( ptr == NULL)
	{
		printf("dkey not found\n");
		return(ptr);
	}
	if( dkey < ptr->info )
		ptr->lchild = del(ptr->lchild, dkey);
	else if( dkey > ptr->info )
		ptr->rchild = del(ptr->rchild, dkey);
	else
	{
		if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL )  
		{
			succ=ptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}
		else	
		{
			tmp = ptr;
			if( ptr->lchild != NULL ) 
				ptr = ptr->lchild;
			else if( ptr->rchild != NULL) 
				ptr = ptr->rchild;
			else	
				ptr = NULL;
			free(tmp);
		}						
	}
	return ptr; 
}
struct node *Min(struct node *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->lchild==NULL)
        return ptr;
	else 
		return Min(ptr->lchild);
}
struct node *Max(struct node *ptr)
{
	if(ptr==NULL) 
		return NULL;
	else if(ptr->rchild==NULL)
        return ptr;
	else 
		return Max(ptr->rchild);
}
void preorder(struct node *ptr)
{
	if(ptr == NULL )
		return;
	printf("%d  ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}
void inorder(struct node *ptr)
{
	if(ptr == NULL )
		return;
	inorder(ptr->lchild);
	printf("%d  ",ptr->info);
	inorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
	if(ptr == NULL )
		return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d  ",ptr->info);
	
}
void levelorder(struct node * root) 
{
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);
}
void levelnodes(struct node * root,int level) 
{
  if (root == NULL)
    return;
  if (level == 1)
    {
		printf("%d ", root -> info);
		return;
	}
	levelnodes(root -> lchild, level - 1);
	levelnodes(root -> rchild, level - 1);
}
void CurrentLevel(struct node * root, int level) 
{
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root -> info);
  else if (level > 1) 
  {
    CurrentLevel(root -> lchild, level - 1);
    CurrentLevel(root -> rchild, level - 1);
  }
}
int heightlev(struct node * node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node -> lchild);
    int rheight = height(node -> rchild);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}
int getMax(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}
int getHeight(struct node *root){
    int leftHeight, rightHeight;
    if(root == NULL)
        return 0;
    leftHeight = getHeight(root->lchild);
    rightHeight = getHeight(root->rchild);
      
    return getMax(leftHeight, rightHeight) + 1;
}
void getLevelWidth(struct node* root, int cLevel, int level, int *width) 
{
   
  if(root == NULL) {
      return;   
  }  
  if(cLevel == level) {
	  printf("%d",root->info);
      *width = *width + 1;
      return;
  }           
  getLevelWidth(root->lchild, cLevel+1, level, width);
  getLevelWidth(root->rchild, cLevel+1, level, width);
}
int getMaxWidth(struct node* root) {
    int i, width, height, maxWidth = -1;
 height = getHeight(root);
 for(i = 0; i < height ; i++)
 {
     width = 0;
     getLevelWidth(root, 0, i, &width);
     maxWidth = getMax(width, maxWidth);
 }
  
 return maxWidth;
}
int height(struct node *ptr)
{
	int h_lchild, h_rchild; 

	if (ptr == NULL) 
		return 0; 

	h_lchild =  height(ptr->lchild); 
	h_rchild = height(ptr->rchild); 

	if (h_lchild > h_rchild) 
		return 1 + h_lchild; 
	else 
		return 1 + h_rchild; 
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

