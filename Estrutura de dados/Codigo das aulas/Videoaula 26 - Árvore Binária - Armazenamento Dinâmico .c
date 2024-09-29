#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *father;
	struct node *left;
	struct node *right;

}NODE;
typedef NODE *ARV_BIN_ENC;
void maketree(ARV_BIN_ENC *t, int x)
{
	*t=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t))
	{
		printf("NAO POSSIVEL ALOCAR  A ARVORE NA MEMORIA");exit(1);
		
	}
	else
	{
		(*t)->info=x;
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->father=NULL;
	}
}
void setleft(ARV_BIN_ENC t,int x)
{
	t->left=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t->left))
	{
		printf("NAO FOI POSSIBLE ALOCAR UM NOVO NODO (A ESQUERDA) NA MEMORIA!!");exit(2);
	}
	else
	{
		t->left->info=x;
		t->left->father=t;
		t->left->left=NULL;
		t->left->right=NULL;
		
	}
	
}
void setright(ARV_BIN_ENC t, int x)
{
	t->right=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t->right))
	{
		printf("NAO FOI POSSIBLE ALICAR UM NOVO NODO (A DIREITA) NA MEMORIA");exit(3);
	}
	else
	{
		t->right->info=x;
		t->right->father=t;
		t->right->left=NULL;
		t->right->right=NULL;
	}
	
}
int info(ARV_BIN_ENC t)
{
	return(t->info);
}
ARV_BIN_ENC left(ARV_BIN_ENC t)
{
	return(t->left);
}
ARV_BIN_ENC right(ARV_BIN_ENC t)
{
	return(t->right);
}
ARV_BIN_ENC father(ARV_BIN_ENC t)
{
	return(t->father);
}
ARV_BIN_ENC brother(ARV_BIN_ENC t)
{
	if(t->father)
	 	if(isleft(t))
			return(t->father)->right;
		else
		return(t->father)->left;
	return NULL;			
}
 int isleft(ARV_BIN_ENC *t)
 {
 	  ARV_BIN_ENC q=(*t)->father;
 	 
	  if(!q)
		  return(0);
	  if(q->left==(*t))
	  	return(1);
	return(0);	     	 
 }
int isright(ARV_BIN_ENC *t)
{
	if((*t)->father)
	 return(!isleft(t));
	return (0); 
}
int main()
{
	ARV_BIN_ENC t;
	int i=1;
	maketree(&t,0);
 	setleft(t,1);
 	setright(t,2);
 	printf("ROOT %d \n",t->info);
 	printf("LEFT %d \n",t->left->info);
 	printf("RIGHT %d \n",t->right->info);
 	printf("ISRIGHT %d \n",isright(&(t->left))?1:0);
 	//printf(" %d \n",t.info);
 	
}









