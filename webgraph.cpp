#include <fstream>
#include <string>
#include <iostream>
#include "WebGraph.h"

using namespace std;

WebGraph::WebGraph(std::string file)
{
	this->graph = new vector<Vertex<int>* >();

	string line;
	ifstream myFile;
	myFile.open(file.c_str(), ios::in);
	if( myFile.is_open() ) {
		while( getline(myFile, line) ) {
			process_line(line);
		}
	}
	myFile.close();

// 	FIXME: remove the following later
	graph->add_edge(1,2);
	graph->add_edge(1,4);
	graph->add_edge(2,5);
	graph->add_edge(3,6);
	graph->add_edge(4,3);
	graph->add_edge(1,3);
	graph->add_edge(6,3);
	graph->add_edge(5,6);
	graph->add_edge(5,1);
}

WebGraph::~WebGraph()
{
}

void WebGraph::process_line(string line) {

}

void WebGraph::page_rank(double d, int niter )
{
	double numPages = this->graph->size();
	double partOnePR = (1 - d) / numPages;
	int indegreeCurrentPage = this->graph->at(0)->get_indegree();
	for( int i = 1; i < indegreeCurrentPage; ++i ) {
		double outDegree = this->graph->at(i)->get_outdegree();

	}

}

void WebGraph::print_adj_list()
{
}



bool WebGraph::add_vertex(int vertex)
{
	Vertex<int> * v = new Vertex<int>(vertex);

	this->graph->push_back(v);
	++lastFilledIndex;

	if(graph->size() > 1 )
		sort( this->graph->begin(), this->graph->end() );
	return true;
}


bool WebGraph::add_edge(int fromVertex, int toVertex)
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
	this->graph->at(fromVertexIndex)->add_edge(toVertexIndex);
	return true;
}


int WebGraph::index_of(int vertex)
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
		int midArrayItem = this->graph->at(i)->get_label();

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
