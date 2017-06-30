// Grafos - DFS (busca em profundidade)
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS
 
using namespace std;
 
class Grafo{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências
 
public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
 
	// faz uma DFS a partir de um vértice
	void dfs(int v);
};
 
Grafo::Grafo(int V){
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}
 
void Grafo::adicionarAresta(int v1, int v2){
	// adiciona vértice v2 à  lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}
 
void Grafo::dfs(int v){
	stack<int> pilha;
	bool visitados[V]; // vetor de visitados
 
	// marca todos como nÃ£o visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;
 
	while(true){
		if(!visitados[v]){
			cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere "v" na pilha
		}
 
		bool achou = false;
		list<int>::iterator it;
 
		// busca por um vizinho não visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				achou = true;
				break;
			}
		}
 
		if(achou)
			v = *it; // atualiza o "v"
		else{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilha.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilha.top();
		}
	}
}
 
int main(){
	std::ifstream file("matriz.txt");
	cout << "Informe o numero de arestas: ";
	int V;
	scanf("%i", &V);

	Grafo grafo(V);
	while (true) {
	    std::string value;
	    int pai;
	    int filho;
	    
	    int v1, v2;
	    
	    if (!(file >> value))
	      break;
	      
	    pai   = atoi(value.substr(0, value.find("#")).c_str());
	    filho = atoi(value.substr(2, value.find("#")).c_str());
		
		grafo.adicionarAresta(pai, filho);
	}
	
	grafo.dfs(0);
}
