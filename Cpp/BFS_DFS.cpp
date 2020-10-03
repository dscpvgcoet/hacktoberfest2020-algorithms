#include<iostream>
#include<list>
#include<set>
#include<stack>
#include<queue>

void bfs(std::list<int>** heads, int v) {
	std::set<int> explored;
	std::queue<int> vertices;

	int current_vertex = 0, current_index = 0;

 	// start with a vertex that is not null
	for (int i = 0; i < v; i++) {
		int vertex = heads[i] -> front();
		if (vertex != 0) {
			vertices.push(i + 1);
			explored.insert(i + 1);
			break;
		}
	}

	std::cout << "BFS: ";
	while (vertices.size() != 0) {
		// pop and print the queue front element
		int current_vertex = vertices.front();
		vertices.pop();
		std::cout << current_vertex << " ";

		// find connections of the front element, and insert them in the queue at the end
		for (std::list<int>::iterator vertex = heads[current_vertex -1] -> begin(); vertex != heads[current_vertex -1] -> end(); ++vertex) {
			// check if the vertex is already explored
			auto search = explored.find(*vertex +1);
			if (search == explored.end()) {
				vertices.push(*vertex + 1);
				explored.insert(*vertex + 1);
			}
		}
	}
	std::cout << std::endl;
}

void dfs (std::list<int>** heads, int v) {
	std::set<int> explored;
	std::stack<int> vertices;

 	// start with a vertex that is not null
	for (int i = 0; i < v; i++) {
		int vertex = heads[i] -> front();
		if (vertex != 0) {
			vertices.push(i + 1);
			explored.insert(i + 1);
			break;
		}
	}

	std::cout << "DFS: ";
	for (vertices.size() != 0) {
		// pop and print the stack top
		int stack_top = vertices.top();
		vertices.pop();
		std::cout << stack_top << " ";

		// find connections of the stack top vertex, and insert them in the stack
		for (std::list<int>::iterator vertex = heads[stack_top - 1] -> begin(); vertex != heads[stack_top - 1] -> end(); ++vertex) {
			// check if the vertex is already explored
			auto search = explored.find(*vertex + 1);
			if (search == explored.end()) {
				vertices.push(*vertex + 1);
				explored.insert(*vertex + 1);
			}
		}
	}
	std::cout << std::endl;
}

// driver program to create a graph and perform BFS and DFS
int main () {
	int v;
	std::cout << "Number of vertices: ";
	std::cin >> v;

	std::list<int>* heads[v];
	for (int i = 0; i < v; i++)
		heads[i] = new std::list<int>;

	int matrix[v][v];
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			matrix[i][j] = 0;

	bool more_edges = true;
	do {
		int v1, v2;
		char input;

		std::cout << "Enter an edge:\n";

		std::cout << "\tVertex 1: ";
		std::cin >> v1;
		std::cout << "\tVertex 2: ";
		std::cin >> v2;

		heads[v1 - 1] -> push_back(v2 - 1);
		matrix[v1 - 1][v2 - 1] = 1;

		heads[v2 - 1] -> push_back(v1 - 1);
		matrix[v2 - 1][v1 - 1] = 1;

		std::cout << "Do you want to insert another edge? (Y/n): ";
		std::cin >> input;
		more_edges = input == 'Y' || input == 'y';

	} while(more_edges);

	int input;
	std::cout << "Menu:\n\t1. Perform BFS\n\t2. Perform DFS\n\tEnter your choice: ";

	bool invalid_input = false;
	do {
		invalid_input = false;
		std::cin >> input;
		switch(input) {
			case 1:
				bfs(heads, v);
				break;
			case 2:
				dfs(heads, v);
				break;
			case 3:
				exit(0);
				break;
			default:
				std::cout << "\nIncorrect option, try again\n\tEnter your choice: ";
				invalid_input = true;
		}
	} while (invalid_input);

}
