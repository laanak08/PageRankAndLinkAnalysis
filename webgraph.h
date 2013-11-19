#pragma once

#include <string>
#include "Vertex.h"

using namespace std;

class WebGraph{
private:
	double * pr; // page ranks for the pages
	vector<Vertex<int>* > * graph;
public:
	WebGraph(std::string file);
	~WebGraph();

	void page_rank(double d = 0.85, int niter);
	void print_adj_list();
private:
	bool add_edge(int,int);
	int size() { return graph->size(); };
	void process_line(string);
	int index_of(int);
	bool add_vertex(int);

	int lastFilledIndex;
};
