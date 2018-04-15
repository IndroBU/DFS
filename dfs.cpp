/*  Depth-first search
    God is Almighty
    Indrojit Mondal
    Department of Computer Science and Engineering,
    University of Barisal
    */
#include<bits/stdc++.h>
using namespace std;
int Vertex,Edge;
int G[100][100];
int Time=0;
int Color[100];
int Path[100];
 /* 0(NULL)==>White
   1==>Gray
   2==>Black
   */
int U,V,I,J;
int D[100]; // D->Destination Time
int F[100]; // F->Finishing Time
int DFS_VISIT(int U);
void PathPrint(int U)
{
    if(U==0) return;
     cout<<U<<" ";
    PathPrint(Path[U]);
}
void DFS()
{

    for(I=1; I<=Vertex; I++)
    {
        Color[I]=0;
    }
    Time =0;
    for(U=1; U<=Vertex; U++)
    {
        if(Color[U]==0)
        {
            DFS_VISIT(U);
        }

    }
}

int DFS_VISIT(int U)
{
    Time=Time+1;
    D[U]=Time;
    Color[U]=1;

    for( V=1; V<=Vertex; V++)
    {
        if(G[U][V]==1 && Color[V]==0)
        {

          Path[U]=V;
          DFS_VISIT(V);
        }
        else{
            Path[U]=0;
        }
    }
    //cout<<U<<endl;
    Color[U]=2;
    Time = Time +1;
    F[U]=Time;


}

int main()
{
    int i,j;
    freopen("in.txt","r",stdin);
    cin>>Vertex>>Edge;
    int Node1,Node2;
    for(i=1; i<=Edge; i++)
    {
        cin>>Node1>>Node2;
        G[Node1][Node2]=1;
    }
    /*for(int x=1; x<=Vertex; x++)
    {
        for(int y=1; y<=Vertex; y++)
        {
            if(G[x][y]==1)
            {
                cout<<x<<"-->"<<y<<endl;
            }
        }
    }*/

    DFS();

    for(U=1; U<=Vertex; U++)
    {
        cout<<U<<" 's Destination Time = "<<D[U]<<" & Finishing Time = "<<F[U]<<endl;

    }
    ///Check kore dekhlam 1 theke kothai kothai jaoa jai
    PathPrint(1);


    return 0;
}


