#include <fstream>
#include <string>
#include <iostream>
#include "webgraph.h"

using namespace std;

WebGraph::WebGraph(std::string file)
{
	string line;
	ifstream myFile;
	myFile.open(file.c_str(), ios::in);
	if( myFile.is_open() ) {
		while( getline(myFile, line) ) {
			process_line(line);
		}
	}
	myFile.close();
}

WebGraph::~WebGraph()
{
}

void WebGraph::process_line(string line) {
	
}

void WebGraph::page_rank(double d, int niter )
{
}

void WebGraph::print_adj_list()
{
}

