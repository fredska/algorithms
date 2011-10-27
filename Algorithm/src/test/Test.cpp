#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <Graph.h>
using namespace std;
void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    /*
    Graph graph(10);
    graph.addEdge(Edge(0,1));
    graph.addEdge(Edge(0,2));
    graph.addEdge(Edge(0,3));
    graph.addEdge(Edge(2,3));
    graph.addEdge(Edge(4,3));
    graph.addEdge(Edge(6,3));

    set<int> getVerts;
    int vertexPos;
    vertexPos = 4;
    getVerts = graph.fetchAdjacencyList(vertexPos);

    vector<set<int> >::iterator vertexIter;
    set<int>::iterator setIter;
    for(setIter=getVerts.begin();setIter!=getVerts.end();setIter++)
    	{
    		cout << vertexPos << "," << *setIter << endl;
    	}
    */
    return 0;
}



