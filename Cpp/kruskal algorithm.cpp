
/*

Represent any real world graph using adjacency list /adjacency matrix.Find minimum spanning tree using Kruskal’s algorithm.

*/


#include<iostream>
#include<stdlib.h>

using namespace std;

class node                                       //class node
{
   int ver,wt;
   node *next;

   friend class graph;

};


class graph                                      //class graph
{
    int min_cost[20][3],list_of_edges[20][3],visited[20],i,c=0,n;
    node *a[20];

    public:

    graph()
    {
         for(i=0;i<20;i++)
              a[i]=NULL;

         for(i=0;i<20;i++)
             visited[i]=0;

    }

    void create();
    void kruskal();
    void add(int u,int v,int w);

};


void graph::add(int u,int v,int w)                //function to crate link between nodes
{
     node *temp,*p;

     temp=new node;

     temp->ver=v;
     temp->wt=w;

     if(a[u-1]==NULL)
        {
              a[u-1]=temp;
              a[u-1]->next=NULL;
        }

     else
      {
         p=a[u-1];

         while(p->next!=NULL)
                 p=p->next;

         p->next=temp;
         temp->next=NULL;
      }

}


void graph::create()                                   //function to create graph
{

  int starting_vertex,ending_vertex,w,f;
  node *p;

  cout<<"\nEnter number of vertices:";
  cin>>n;

  while(n<=0)
  {
      cout<<"\nINVALID!!!  ENTER AGAIN ";
      cout<<"\nEnter number of vertices:";
      cin>>n;
  }

  do
  {
     cout<<"\nEnter the starting vertex (1 to "<<n<<" ) :";
     cin>>starting_vertex;

     while(starting_vertex < 1 || starting_vertex >=n+1)
     {
        cout<<"\nINVALID!!!  ENTER AGAIN ";
        cout<<"\nEnter the starting vertex (1 to "<<n<<" ) :";
        cin>>starting_vertex;
     }

     cout<<"\nEnter the ending vertex (1 to "<<n<<" ) :";
     cin>>ending_vertex;

     while(ending_vertex==starting_vertex || ending_vertex < 1 || ending_vertex >=n+1)
     {
        cout<<"\nINVALID!!!  ENTER AGAIN ";
        cout<<"\nEnter the ending vertex (1 to "<<n<<" ) :";
        cin>>ending_vertex;
     }

     cout<<"\nEnter weight of the edge : ";
     cin>>w;

     while(w<=0)
     {
         cout<<"\nINVALID!!!  ENTER AGAIN ";
         cout<<"\nEnter weight of the edge : ";
         cin>>w;
     }

     add(starting_vertex,ending_vertex,w);
     add(ending_vertex,starting_vertex,w);

     list_of_edges[c][0]=starting_vertex;              //storing values of vertices and weight in matrix
     list_of_edges[c][1]=ending_vertex;
     list_of_edges[c][2]=w;

     c++;

    cout<<"\nDo u want to add another edge ?  (0/1) :";
    cin>>f;

  }

  while(f==1);

}


void graph::kruskal()                              //function for implementation of kruskal algorithm
{
   int k,j,v1,v2,e,q=0,weight=0,temp,sv,s1,s2;

   for(k=0;k<c;k++)                                       //loop for sorting edges according to their weight in ascending order
    {
      for(j=0;j<c;j++)
       {

	    if(list_of_edges[k][2] < list_of_edges[j][2])
            {
		     temp=list_of_edges[k][2];                         //swap edges
		     list_of_edges[k][2]=list_of_edges[j][2];
		     list_of_edges[j][2]=temp;

		     temp=list_of_edges[k][1];                        //swap vertex2
		     list_of_edges[k][1]=list_of_edges[j][1];
		     list_of_edges[j][1]=temp;

		     temp=list_of_edges[k][0];                        //swap vertex1
		     list_of_edges[k][0]=list_of_edges[j][0];
		     list_of_edges[j][0]=temp;
            }
       }
    }


   for(k=0;k<c;k++)
    {
        v1=list_of_edges[k][0];
        v2=list_of_edges[k][1];
        e=list_of_edges[k][2];

        if(visited[v1-1]==0 && visited[v2-1]==0)                  //if both vertices are not visited
        {
	      sv++;

	      visited[v1-1]=sv;
          visited[v2-1]=sv;

          min_cost[q][0]=v1;                                     //storing values of vertices and weight in matrix
          min_cost[q][1]=v2;
          min_cost[q][2]=e;

          q++;
        }

         if(visited[v1-1] != visited[v2-1])                     //if one vertex is visited and other vertex is not visited
        {
           s1=visited[v1-1];
           s2=visited[v2-1];
           temp=v2;

           if(s1==0)                                          //if vertex1 is not visited
            {
                 temp=s1;
                 s1=s2;
                 s2=temp;
                 temp=v1;
            }

           if(s2==0 && s1!=0)                               //if vertex1 is visited and vertex2 is not visited
            {
               visited[temp-1]=s1;
            }

            else
            {
              for(j=0;j<n;j++)
                 {
                   if(visited[j]==s2)
                      {
                         visited[j]=s1;
                      }
                 }
            }

	      min_cost[q][0]=v1;
          min_cost[q][1]=v2;
          min_cost[q][2]=e;

          q++;
        }

        if(q==n-1)                                      //if number of edges = no of vertices - 1
          break;
    }

    cout<<"\n\nVertices"<<"\t"<<"Edge";

    for(k=0;k<q;k++)
       cout<<"\n("<<min_cost[k][0]<<","<<min_cost[k][1]<<")"<<"\t\t"<<min_cost[k][2];

    for(k=0;k<q;k++)
       weight=weight+min_cost[k][2];

    cout<<"\nThe total weight of the minimum spanning tree is :"<<weight;

}


int main()
{
   graph g;
   g.create();
   g.kruskal();

  return 0;
}
