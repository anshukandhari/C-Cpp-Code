#include<iostream.h>
#include<conio.h>

#define MAX 100

class kruskal
{
	private : struct edge_info
		  {
			int u, v, weight;
		  } edge[MAX];
		  int tree[MAX][2], set[MAX];
		  int n;
	public  : int readedges();
		  void makeset();
		  int find(int);
		  void join(int, int);
		  void arrange_edges(int);
		  int spanningtree(int);
		  void display(int);
};

int kruskal :: readedges()
{
	int x, y, k, cost;
	k = 1;
	cout << "\nEnter the number of Vertices in the Graph : ";
	cin  >> n;
	cout << endl;
	for (x = 1; x<=n; x++)
		{
        for (y = 1; y <=x; y++)
		{
			cout << "weight[" << x << "][" << y << "] : ";
			cin  >> cost;
			if (cost != 999)
			{
				edge[k].u = x;
				edge[k].v = y;
				edge[k++].weight = cost;
			}
		}
        }
	return (k - 1);
}

void kruskal :: makeset()
{
	int i;
	for (i = 1; i <= n; i++)
		set[i] = i;
}

int kruskal :: find(int vertex)
{
	return (set[vertex]);
}

void kruskal :: join(int v1, int v2)
{
	int i, j;
	if (v1 < v2)
		set[v2] = v1;
	else
		set[v1] = v2;
}

void kruskal :: arrange_edges(int k)
{
	int i, j;
	struct edge_info temp;
	for (i = 1; i < k; i++)
		for (j = 1; j <= k - i; j++)
			if (edge[j].weight > edge[j + 1].weight)
			{
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
}

int kruskal :: spanningtree(int k)
{
	int i, t, sum;
	arrange_edges(k);
	t = 1;
	sum = 0;
	for (i=1;i<=k;i++)
	cout<<edge[i].u<<edge[i].v<<" "<<edge[i].weight<<endl;getch();
	for (i = 1; i <= k; i++)
		if (find (edge[i].u) != find (edge[i].v))
		{
			tree[t][1] = edge[i].u;
			tree[t][2] = edge[i].v;
			sum += edge[i].weight;
			join (edge[t].u, edge[t].v);
			t++;
		}
	return sum;
}

void kruskal :: display(int cost)
{
	int  i;
	cout << "\nThe Edges of the Minimum Spanning Tree are\n\n";
	for (i = 1; i < n; i++)
		cout << tree[i][1] << " - " << tree[i][2] << endl;
	cout << "\nThe Cost of the Minimum Spanning Tree is : " << cost;
}

int main()
{
	int ecount, totalcost;
	kruskal k;
	ecount = k.readedges();
	k.makeset();
	totalcost = k.spanningtree(ecount);
	k.display(totalcost);
	return 0;
}
