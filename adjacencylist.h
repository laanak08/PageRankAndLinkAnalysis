#include "vertex.h"
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class AdjacencyList {
public:
	AdjacencyList() : lastFilledIndex(0), adjList( new vector<Vertex<T>* >() ) {};
	~AdjacencyList() { delete adjList; };

	bool add_edge(T,T);
	int size() { return adjList->size(); };
private:
	int index_of(T);
	bool add_vertex(T);

	vector<Vertex<T>* > * adjList;
	int lastFilledIndex;
};

template <typename T>
bool AdjacencyList<T>::add_vertex(T vertex)
{
	Vertex<T> * v = new Vertex<T>(vertex);

	this->adjList->push_back(v);
	++lastFilledIndex;

	if(adjList->size() > 1 )
		sort( this->adjList->begin(), this->adjList->end() );
	return true;
}

template <typename T>
bool AdjacencyList<T>::add_edge(T fromVertex, T toVertex)
{

	// find vertex index
	int notIndexed = -1;
	int fromVertexIndex = index_of( fromVertex );
	int toVertexIndex = index_of( toVertex );

	if( fromVertexIndex == notIndexed ){
		add_vertex( fromVertex );
		fromVertexIndex = index_of( fromVertex );
	}

	if( toVertexIndex == notIndexed ){
		add_vertex( toVertex);
		toVertexIndex = index_of( toVertex );
	}
	this->adjList->at(fromVertexIndex)->add_edge(toVertexIndex);
	return true;
}

template <typename T>
int AdjacencyList<T>::index_of(T vertex)
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
		T midArrayItem = this->adjList->at(i)->get_label();

		if( midArrayItem > vertex ){
			r = i-1;
		}else if( midArrayItem < vertex ){
			l = i+1;
		}else{
			return i;
		}
	}
	return notIndexed;
}
