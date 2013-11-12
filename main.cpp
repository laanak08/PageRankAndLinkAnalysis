#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include "webgraph.h"

using namespace std;

int main( int argc, char ** argv)
{
	
	char inputfile[100];
	char options[100];
	int iflag=0;
	int oflag=0;
	int index;
	int c;
	
	//cout<<max_string();
	opterr = 0;
	while ((c = getopt (argc, argv, "i:o:")) != -1)
	{
		switch (c)
		{
			case 'i':
				strcpy(inputfile, optarg);
				iflag=1;
				break;
			case 'o':
				strcpy(options, optarg);
				oflag=1;
				break;
			default:
				fprintf (stderr, "error: parsing command line parameters\n");
				abort ();
		}
	}
	
	if (iflag==0){
		fprintf (stderr, "program needs input file name\n");
		abort ();
	}
	
	if (oflag==0){
		fprintf (stderr, "program needs options\n");
		abort ();
	}
	
	string ifile(inputfile);
	WebGraph graph(ifile);
	string cmd(options);
	if(cmd.compare("exp1")==0)
		graph.print_adj_list();
	// 	else if(cmd.compare("exp2")==0)
	// 		graph.page_rand(d,niter);
	
	
	return 0;
}
