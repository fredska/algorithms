#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <Graph.h>
#include <GraphTest.h>
#include <BreadthFirstSearchTest.h>
using namespace std;

void thisisatest()
{
	ASSERT(false);
}

void runSuite()
{
	GraphTest gt;

	cute::suite s;
	s.push_back(CUTE(thisisatest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Graph Tests");
}

int main(){
	GraphTest gt;
	gt.runGraphTestSuite();

	BreadthFirstSearchTest bfsTest;
	bfsTest.runBFSSuite();
    return 0;
}



