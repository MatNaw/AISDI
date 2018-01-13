#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
class Graph
{
   private:
    int loadSize()
    {
        int siz;

        if(cin.good() == true)
            cin >> siz;
        return siz;
    }
    struct BoolExcept
    {
        bool value;
    };
    public:
    int u=0,v=0,result=0,count_apex=0;
    int flag = 0;
    int visited = 1;
    int apex = count_apex - 2;
    int **matrix;
    int result_matrix[][2];
Graph()
{
    count_apex = loadSize();
    matrix = new int*[count_apex];
    for(int i=0; i< count_apex; ++i)
    {
        matrix[i] = new int[count_apex];
    }
    for(int i=0; i<count_apex; i++)
        {
            for(int j=0; j<count_apex; j++)
            {
                matrix[i][j]=0;
            }
        }
}

~Graph()
{
    for (int i=0; i<count_apex; i++)
        delete []matrix[i];
    delete [] matrix;
}


int *loadMatrix()
    {
        string line;
        //if(file.good() == true)
            //file >> line;
        if(cin.good() == true)
        {
            while(!cin.eof())
            {
                cin >> u >> v;
                matrix[u][v] = 1;
                matrix[v][u] = 1;
                //cout << u << " " << v << "\n";
            }
        }

        for(int i=0; i<count_apex; i++)
        {
            for(int j=0; j<count_apex; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout <<"\n";
        }
        cout <<"\n";

}

void findingBridges()
    {
        for(int i=0; i<count_apex; i++)
        {
            for(int j=i+1; j<count_apex; j++)
            {
                if(matrix[i][j]>0)
                {
                    convert(i, j);
                    bridge(i, j, 0);
                    if(flag == 0)
                        addBridge(i, j);
                    convert(i, j);
                    flag = 0;
                }
            }
        }
    }
void convert(int i, int j)
    {
        for(int a=0; a<count_apex; a++)
        {
            matrix[i][a]*=(-1);
            if(a!=i)
                matrix[a][i]*=(-1);
        }
        for (int b=0; b<count_apex; b++)
        {
            if(b!=i)
            matrix[j][b]*=(-1);
            if(b!=j && b!=i)
                matrix[b][j]*=(-1);
        }
    /*for(int f=0; f<count_apex; f++)
        {
            for(int g=0; g<count_apex; g++)
            {
                cout << matrix[f][g] << " ";
            }
            cout <<"\n";
        }
       cout <<"\n";*/
    }
void bridge(int a, int b, int x)
    {
        for(int i=x; i<count_apex; i++)
        {
            if(flag == 1)
                return;
            if(i!=a && i!=b)
            {
                for(int j=i+1; j<count_apex; j++)
                {
                    if(j!=a && j!=b)
                    {
                        if(flag == 1)
                            return;
                        if (matrix[i][j]>0)
                        {
                            ++visited;
                            if(visited == count_apex-2)
                            {
                                visited = 1;
                                flag = 1;
                                return;
                            }
                            bridge(a, b, j);
                        }
                    }
                }
            }
        }
        visited = 1;

    }
void addBridge(int a, int b)
    {
        result_matrix[result][0]=a;
        result_matrix[result][1]=b;
        result++;
    }


};

#endif // GRAPH_H
