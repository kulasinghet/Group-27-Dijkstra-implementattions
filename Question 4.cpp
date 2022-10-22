/*
	SCS2201 DSA III
	Assignment
	Question 04
	N.D Kumarage
	20001002
*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;
  
typedef pair<int, int> intPair;

// Structure to represent the sets
struct DisjointSets
{
    int *parent, *rank;
    int n;
   
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
  
		// Initialize all cities rank to 0 and it's parent to it self
        for (int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
  
    // Function to find the parent of a node 
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    // Function to Join 2 sets
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        if (rank[x] > rank[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;
  
        if (rank[x] == rank[y])
            rank[y]++;
    }
};
  
// Structure to represent a graph
struct Graph
{
    int citiy, link;
    vector< pair<float, intPair> > edges;
  
    Graph(int city, int link)
    {
        this->citiy = city;
        this->link = link;
    }
  
    // Function to add an edge to the graph
    void addEdge(int u, int v, float cost)
    {
        edges.push_back({cost, {u, v}});
    }
  
    // Function to find MST using Kruskal   
	void MST()
	{
    	// Sort edges in increasing order of cost
    	sort(edges.begin(), edges.end());
  
		// Create disjoint sets for all cities
		DisjointSets dSet(citiy);
	
		// Iterate through all sorted edges
		vector< pair<float, intPair> >::iterator it;

		for (it=edges.begin(); it!=edges.end(); it++)
		{
			int u = it->second.first;
			int v = it->second.second;
	
			int set_u = dSet.find(u);
			int set_v = dSet.find(v);
	
			// Check whether two cities are in same set or not
			if (set_u != set_v)
			{
				if(u<v)
				{
					cout << u+1 << " - " << v+1 << endl;
				}
				else
				{
					cout << v+1 << " - " << u+1 << endl;
				}
				// Merge two sets
				dSet.merge(set_u, set_v);
			}
		}
	}
};
  
int main()
{
	int cities;
	cout<<"Enter the number of citiy : ";
	cin>>cities;
	cout<<endl;
	assert(cities>0);

	int links = (cities-1)*cities/2;
	float lo[cities] , li[cities] , cost;

	// Initialize the complete graph
    Graph  myGraph (cities, links);

	for (int i = 0; i < cities; i++)
	{
		cout<<"Enter longitudinal of the city "<< i+1 <<" : ";
		cin>>lo[i];
		cout<<"Enter Latitudinal of the city "<< i+1 <<" : ";
		cin>>li[i];
		cout<<endl;
	}

	// Adding edges to the complete graph
	for (int i = 0; i < cities-1; i++)
	{
		for (int j = i+1; j < cities; j++)
		{
			cost = sqrt((li[i]-li[j])*(li[i]-li[j]) + (lo[i]-lo[j])*(lo[i]-lo[j]) );
			myGraph.addEdge(i,j,cost);
		}
		
	}
	
	cout<<"Number of terminal links built : "<<cities-1<<"\n"<<endl;
    myGraph.MST();

    return 0;
}