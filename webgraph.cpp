#include <fstream>
#include <string>
#include <iostream>
#include "webgraph.h"

using namespace std;

WebGraph::WebGraph(std::string file)
{
	this->graph = new AdjacencyList<int>();

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

