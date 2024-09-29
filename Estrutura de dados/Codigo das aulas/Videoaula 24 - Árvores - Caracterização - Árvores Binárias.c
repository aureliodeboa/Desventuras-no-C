#include<stdio.h>
#include<stdlib.h>
#define NUMNODES 100
typedef struct {
	int info;
	int left;
  	int right;
  	int father;
  	
}NODE;
typedef struct
{
	int root;
	int nodeFree;
	NODE nodes[NUMNODES];
}ARV_BIN_SEQ;
void maketree(ARV_BIN_SEQ *t,int x )
{
	int i,ind;
	for(i=0;i<NUMNODES-1;i++)
	{
		t->nodes[i].left=i+1;
	}
	t->nodes[i].left=-1; 
	t->nodeFree=0;
	ind=getNode(t);
	
	if(ind!=-1)
	{
		t->nodes[ind].info=x;
		t->nodes[ind].father=-1;
		t->nodes[ind].left=-1;
		t->nodes[ind].right=-1;
		t->root=ind;
		
	}
	else
	{
		printf("NAO FOI POSSIVEL CRIAR A ARVORE NEGAO\n");exit(1);
	}
}
int getNode(ARV_BIN_SEQ *t)
{
	if(t->nodeFree!=-1)
	{
		int i=t->nodeFree;
		t->nodeFree=t->nodes[t->nodeFree].left;
		return i;
	}
	else
	{
		return -1;
	}
}
void freeNode(ARV_BIN_SEQ *t, int node)
{
	t->nodes[node].left=t->nodeFree; //atualizando o antigo primeiro livre pra ser o proximo
	t->nodeFree=node;
}
void setleft(ARV_BIN_SEQ *t,int p,int x	)
{
	int ind=getNode(t);
	
	if(ind!=-1)
	{
		t->nodes[p].left=ind;
		t->nodes[ind].info=x;
		t->nodes[ind].father=p;
		t->nodes[ind].right=-1;
		t->nodes[ind].left=-1;
		
	}
	else
	{
		printf("NAO FOI POSSIVEL SETAR A ESQUERDA DA ARVORE");exit(2);
	}
}
void setright(ARV_BIN_SEQ *t,int p,int x)
{
	int ind=getNode(t);
	
	if(ind!=-1)
	{
		t->nodes[p].right=ind;
		t->nodes[ind].father=p;
		t->nodes[ind].left=-1;
		t->nodes[ind].right=-1;
		t->nodes[ind].info=x;
	}
	else
	{
		printf("NAO FOI POSSIBLE INSERIR FILHO A DIREITA!");exit(3);
	}
	
}
int info(ARV_BIN_SEQ *t,int p)
{
	return (t->nodes[p].info);
}
int left(ARV_BIN_SEQ *t,int p)
{
	return(t->nodes[p].left);
}
int right(ARV_BIN_SEQ *t, int p)
{
	return(t->nodes[p].right);
}
int father(ARV_BIN_SEQ *t, int p)
{
	return(t->nodes[p].father);
}
int brother(ARV_BIN_SEQ *t,int p)
{
	if(father(t,p)!=-1)
	{
		if(isleft(t,p))
		{
			return(right(t,father(t,p)));
		}
		else
		{
			return(t->nodes[t->nodes[p].father].left);
		}
	}
	else
	{
		return -1;
	}
	
}
int isleft(ARV_BIN_SEQ *t, int p)
{
	int q=father(t,p);
	if(q==-1)//se nao for raiz
		return 0;
	if(left(t,q)==p)
		return(1);
	return(0);	
	
}
int isright(ARV_BIN_SEQ *t,int p)
{
	if(father(t,p)!=-1)
		return(!isleft(t,p));
	return(0);		
}
void imprimir(ARV_BIN_SEQ *t)
{
	int i;
	for(i=t->root;i<NUMNODES-1;i++)
	{
		printf(" NODO %d=%d\n",i,t->nodes[i].info);
	}
}
 int main()
 {
 	ARV_BIN_SEQ t;
 	int i;
 	maketree(&t,0);
 	setright(&t,0,1);
 	printf("NODO LIVRE %d \n",t.nodeFree);
 	printf("NODO RAIZ %d \n",t.root);
 	printf("NODO Father %d \n",t.nodes[1].father);
 	printf("INFO %d \n",t.nodes[1].info);
 	printf("NODO LEFT %d \n",t.nodes[0].left);
 	printf("NODO Right %d \n",t.nodes[0].right);
 	
 }







