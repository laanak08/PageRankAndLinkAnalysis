#ifndef __WEB_GRAPH__
#define __WEB_GRAPH__
#include <string>
#include <list>
#include <map>

using namespace std;

template <typename T>
class Vertex {
	private:
		T data;
		list * edges;
	public:
		vertex() : edges(new list<T>()) {};
		vertex(T label,int index) : this-data(label), this->edges(new list<T>()) { add_edge(index); };
		~vertex( delete edges; );

		T get_data() { return this->data; };
		bool set_label(T label) : data(label) { return true; };
		bool add_edge(int index) { edges.push_back(index); return true; };
};

template <typename T>
class AdjacencyList {
	public:
		AdjacencyList(){};
		AdjacencyList(int numVertices) : this->numVertices(numVertices), this->lastFilledIndex(0), this->adjList(new Vertex[numVertices]) {};
		~AdjacencyList( delete [] adjList; );

		bool add_vertex(T);
		bool add_edge(int,T);
	private:
		Vertex * adjList;
		int lastFilledIndex;
		int numVertices;
};

class WebGraph{
	private:
		double * pr; // page ranks for the pages
		AdjacencyList<int> * graph;
	public:
		WebGraph(std::string file);
		~WebGraph();

		// calculate PageRank
		void page_rank(double d, int niter);
		// print the adjacency list
		void print_adj_list();
	private:
		void process_line(string);
};
#endif


template <typename T>
bool AdjacencyList<T>::add_vertex(T label)
{
	if( lastFilledIndex < numVertices )
		vertices[lastFilledIndex].set_label(label);
	++lastFilledIndex;
	return true;
}

template <typename T>
bool AdjacencyList<T>::add_edge(int edgeIndex, T vertex)
{
	int notIndexed = -1;
	// find vertex index
	int vertexIndex = index_of(vertex);

	if(  vertexIndex != notIndexed )
		this->vertices[vertexIndex].add_edge(edgeIndex);
// 	else if( vertexIndex == notIndexed )

	return true;
}
// FIXME: either sort while inserting into adjList or insert all then sort after and use a search that doesnt care about sorting
template <typename T>
int InvIndex::index_of(T vertex)
{
	// binary search
	int listSize = lastFilledIndex;
	int notIndexed = -1;

	if( 0 == listSize )
		return notIndexed;

	// set left and right boundary beyond array bounds
	int l = 0;
	int r = listSize-1;

	// stop when l and r converge on the same index
	while(l <= r) {
		// check middle of subarray
		int i = l+((r-l)/2);
		T midArrayWord = vertices[i].get_data();

		if( midArrayWord > vertex ){
			r = i-1;
		}else if( midArrayWord < vertex ){
			l = i+1;
		}else{
			return i;
		}
	}
	return notIndexed;
}
