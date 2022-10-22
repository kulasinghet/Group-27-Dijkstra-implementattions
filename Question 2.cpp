/*
	SCS2201 DSA III
	Assignment
	Question 02
	R D T D Kulasinghe
	20000995
*/

#include <bits/stdc++.h>
using namespace std;

int turns;

// Function to print the path from source to destination
void print_path(vector<int>& parent, int vertex, int target)
{
	// if vertex is 0 then we have reached the source
	if (vertex == 0) {
		return;
	}

	// print the path recursively
	print_path(parent, parent[vertex], target);

	// print the current vertex
	cout << vertex << (vertex == target ? "\n" : " --> ");
}

// Function to perform Dijkstra algorithm on graph
void dijkstra(vector<vector<pair<int, int> > >& Graph, int src, int target)
{
	
	// stores the number of vertices in the graph
	vector<int> widest(Graph.size(), INT_MIN);

	// set to store vertices that are being preprocessed
	vector<int> parent(Graph.size(), 0);

	// set to maintain vertices that are being preprocessed
	priority_queue<pair<int, int>, vector<pair<int, int> >,	greater<pair<int, int>>> container;

	// insert source vertex in the set and initialize its distance as 0
	container.push(make_pair(0, src));

	// loop till set becomes empty
	widest[src] = INT_MAX;

	// run till all vertices are processed
	while (container.empty() == false) {
		pair<int, int> temp = container.top();

		int current_src = temp.second;

		// remove the minimum distance vertex from the set
		container.pop();

		// loop through all adjacent vertices of current vertex
		for (auto vertex : Graph[current_src]) {
			
			// get vertex label and weight of current adjacent of u
			int distance = max(widest[vertex.second], min(widest[current_src], vertex.first));

			// if there is shorted path to v through u
			if (distance > widest[vertex.second]) {
				widest[vertex.second] = distance;
				parent[vertex.second] = current_src;
				container.push(make_pair(distance, vertex.second));
			}
		}
	}

	// print the path from source to destination
	print_path(parent, target, target);

	turns = widest[target];
}

void main()
{
    // Get number of students
    int totalStudent;
    cout << "Enter the number of foreign students:";
    cin >> totalStudent;
    
	// Get number of AIESEC members
    int totalAIESEC;
    cout << "Enter the number of AIESEC students:";
    cin >> totalAIESEC;

	// Initialize the graph
	vector<vector<pair<int, int> > > graph;
    
    // Get the number of cities and the number of roads
	int noOfCities;
	int noOfRoads;
	cin >> noOfCities >> noOfRoads;

	// Initialize the graph with the number of cities (0 to n with both inlcuded)
	graph.assign(noOfCities + 1, vector<pair<int, int> >());
	
	// Add the roads and maximum student limits to the graph
	int i = noOfRoads;
	while(i > 0){
	    int sourceCity, destinationCity, maxStudents;
	    cin >> sourceCity >> destinationCity >> maxStudents;
	    graph[sourceCity].push_back(make_pair(maxStudents, destinationCity));
	    i--;
	}

	// Need to go from city 1 to city 6
	int parent = 1;
	int destination = 6;

	// Call the dijkstra function
    dijkstra(graph, parent, destination);

	// Print the number of turns
	cout << (totalStudent / (turns - totalAIESEC));
}