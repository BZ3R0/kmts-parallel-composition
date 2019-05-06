#include <bits/stdc++.h>
#include <list>
using namespace std;

//std::list<int> *estados;
std::list<int> *estados = new list<int>[4]; //4 é a quantidade de vezes em que a função de adicionar variavel é chamada.

void adicionarVariavel(int state, int value){
	//adiciona vértice v2 a lista de vértices adjacentes de v1
	estados[state].push_back(value);
}

void imprimirVariavel(int v){
	list<int>::iterator var;
	int posicaoVar = 0;
	for(var = estados[v].begin(); var!=estados[v].end(); var++){

		cout << "\tVariavel [" <<posicaoVar++ <<"] ";
		if(*var == 0){
			cout << "Falso";
		}else if(*var == 1){
			cout << "Verdadeiro";
		}else
			cout << "Indefinido";
		cout << "\n";
	}
	cout << "\n";
}

// utility function for printing
// the found path in graph
void printpath(vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++){
		cout << path[i] << " ";
		imprimirVariavel(path[i]);
	}
	cout << endl << endl << endl;
}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0; //foi visitado
	return 1; //não foi visitado
}

// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int> >&g, int src,
								int dst, int v)
{
	// create a queue which stores
	// the paths
	queue<vector<int> > q;

	int visitado = 0, aux = 0;
	// path vector to store the current path
	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		// if last vertex is the desired destination
		// then print the path
		if (last == dst)
			printpath(path);

		// traverse to all the nodes connected to
		// current vertex and push new path to queue
		for (int i = 0; i < g[last].size(); i++) {
			//cout << "glast: " << g[last].size() << endl;
			visitado = isNotVisited(g[last][i], path);
			if (visitado == 0)
				aux++;
			if ((visitado == 1) || (aux <= 2)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

// driver program
int main()
{
	vector<vector<int> > g;
	// number of vertices
	int v = 4;
	g.resize(4);

	// construct a graph
	g[0].push_back(3);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);

	// adicionando aos estados as variáveis.
	adicionarVariavel(0, 1);
	adicionarVariavel(1, 0);
	adicionarVariavel(1, 1);
	adicionarVariavel(1, 1);
	adicionarVariavel(1, -1);
	adicionarVariavel(2, -1);
	adicionarVariavel(3, 1);

	int src = 2, dst = 3;
	cout << "path from src " << src
		<< " to dst " << dst << " are \n";

	// function for finding the paths
	findpaths(g, src, dst, v);

	return 0;
}
