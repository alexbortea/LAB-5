/*Implementați și testați următoarele funcții
1. (2p) o functie care transforma un graf reprezentat prin matrice de adiacenta in reprezentarea cu
lista de adiacenta
2. (3p) funcții pentru testarea existenței unei muchii de la x la y (pentru fiecare reprezentare in
parte)
3. (3p) funcții pentru afișarea muchiilor incidente cu x (pentru fiecare reprezentare in parte)
4. (1p) functie pentru calculul matricei drumurilor - Algoritmul Roy – Warshall - pentru
reprezentare cu matrice de adiacență*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int vertex_no; // numarul varfului de stocat
    struct ListNode* next;
};
typedef struct ListNode Node;

typedef struct
{
    int V; // nr. varfuri
    int E; // nr. muchii
    int **a;
    Node** b;

} Graph;
Graph * create ()  // funcția alocă spațiu pentru un graf și îl inițializează cu valori
{
    int i,j;
    Graph *g = (Graph *) malloc (sizeof(Graph));
    if (g==NULL)
    {
        printf ( " no memory for this graph");
        return NULL;
    }

    printf("Cate varfuri are ?");
    scanf ("%d", &(g->V));
    g->a=(int**)malloc(g->V*sizeof(int*));
    for (i=0; i<g->V; i++)
        g->a[i]=(int*)malloc(sizeof(int));
    g->E = 0;
    {
        //este orientat
        for (i=0; i<g->V; i++)
            for (j=0; j<g->V; j++)
            {

                printf("Exista arc de la %d la %d?\n",i,j);
                scanf ("%d", &g->a[i][j]);
                if(g->a[i][j]!=0) g->E++;
            }
    }
    return g;
}
Graph* trecere(Graph *g)
{
    g->b=(Node**)malloc(sizeof(Node*));
    int i,j;
    for (i=0; i<g->V; i++)
        for (j=0; j<g->V; j++)
        {
            g->b[i]=(Node*)malloc(sizeof(Node));
            if(g->a[i][j]==1)
            {
                Node * newnode = (Node*)malloc(sizeof(Node));
                newnode->vertex_no=j;
                newnode->next=NULL;
                g->b[i]=newnode;
            }
        }
    return g;

}
void afisare(Graph* g)
{
    for (int i=0; i<g->V; i++)
    {
        for (int j=0; j<g->V; j++)
            printf("%d ",g->a[i][j]);
        printf("\n");
    }
}
void testare_existenta_muchie_matrice(int i,int j,Graph * g)
{
    if (g->a[i][j]==1)
        printf("exista muchie intre %d si %d",i,j);
    else
        printf("nu exista muchie intre %d si %d",i,j);
}
void testare_existenta_muchie_lista(int i,int j,Graph * g)
{
    int ok=0;
    while (g->b[i]->next!=NULL)
        if(g->b[i]->vertex_no==j)
            ok=1;
    if (ok==1)
        printf("exista muchie intre %d si %d",i,j);
    else
        printf("nu exista muchie intre %d si %d",i,j);
}
void testare_muchii_incidente_matrice(int x,Graph* g)
{
    printf("muchile incidente cu nodul %d sunt: ",x);
    for(int i=0; i<g->V; i++)
        if(g->a[x][i]==1)
            printf("%d ",i);
    printf("xxx");
}
void testare_muchii_incidente_lista(int x,Graph *g)
{
    printf("muchile incidente cu nodul %d sunt: ",x);
    while(g->b[x]->next!=NULL)
    {
        printf("%d ",g->b[x]->next->vertex_no);
        g->b[x]=g->b[x]->next;
    }
}
int drum(int i,int j,Graph * g)
{
    int ok=0,k;
    while (!NULL)
    {
       if(g->a[i][j]==1)
        return 1;
       else
       {
           for(k=0;k<g->V;k++)
            if(g->a[i][k]==1)
            drum(k,j,g);
       }
    }
    return 0;
}
int main()
{
    int i;
    Graph *g = create();
    afisare(g);
    trecere(g);
  /*  for(i=0; i<g->V; i++)
    {
        printf("%d ",i);
        while(g->b[i]!=NULL)
            printf("%d ",g->b[i]->vertex_no);
        printf("\n");
    }

    testare_existenta_muchie_matrice(0,1,g);
    printf("\n");
    testare_existenta_muchie_lista(4,5,g);
    printf("\n");
    testare_muchii_incidente_matrice(1,g);
    printf("\n");
    printf("yyy");
    testare_muchii_incidente_lista(4,g);

*/
if(drum(0,2,g))
    printf("exista");
else
    printf("nu exista");

    return 0;
}
