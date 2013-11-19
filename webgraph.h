#pragma once

#include <string>
#include "adjacencylist.h"

using namespace std;

class WebGraph{
private:
	double * pr; // page ranks for the pages
	AdjacencyList<int> * graph;
public:
	WebGraph(std::string file);
	~WebGraph();

	void page_rank(double d = 0.85, int niter);
	void print_adj_list();
private:
	void process_line(string);
};
