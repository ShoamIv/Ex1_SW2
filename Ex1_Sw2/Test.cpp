/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) ==true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "There is no path between 0 and 4");

     vector<vector<int>> graph3 = {
        {0, 0, 1},
        {1, 0, 3},
        {0, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0},
        {1, 0, 5, 0},
        {0, 2, 0, 3},
        {0, 0, 1, 0},};
        g.loadGraph(graph4);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");

    vector<vector<int>> graph5 = {
            {0,1,2},
            {-2,0,0},
            {0,3,0}
     };
     g.loadGraph(graph5);
     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");


     vector<vector<int>> graph6 = {
    {0, -1, 2, 0, 0},
    {-2, 0, 0, 1, 0},
    {0, 3, 0, 0, 0},
    {0, 0, 0, 0, -5},
    {0, 0, 0, 0, 0}
    };
        g.loadGraph(graph6);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "no cycle detected.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph3 = {
            {0,1,2},
            {-2,0,0},
            {0,3,0}
     };
     g.loadGraph(graph3);
     CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");

     vector<vector<int>> graph4 = {
    {0, -1, 2, 0, 0},
    {-2, 0, 0, 1, 0},
    {0, 3, 0, 0, 0},
    {0, 0, -1, 0, -5},
    {0, 0, 0, 0, 0}
    };
     g.loadGraph(graph4);
     CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");
    }
    
    TEST_CASE("Test isBipartite")
    {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>>graph4={
        {0, 0, 0, 1, 1,1},
        {0, 0, 0, 1, 1,1},
        {0, 0, 0, 1, 1,1},
        {1, 1, 1, 0, 0,0},
        {1, 1, 1, 0, 0,0},
        {1, 1, 1, 0, 0,0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4, 5}");

    vector<vector<int>> graph5 = {
    {0, -1, 2, 0, 0},
    {-2, 0, 0, 1, 0},
    {0, 3, 0, 0, 0},
    {0, 0, -1, 0, -5},
    {0, 0, 0, 0, 0}
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

}   
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
    {},{}};
    CHECK_THROWS(g.loadGraph(graph));
}

  TEST_CASE("General Test")
{
        ariel::Graph g;
        vector<vector<int>>graph = {
            {0, 0, 0, 0, 0},
            {-2, 0,0, -6,0},
            {0, 1, 0, 0, 3},
            {0, 0, 4, 0, 0},
            {0, 0, 0, 9, 0}

    };
     g.loadGraph(graph);
     CHECK(ariel::Algorithms::isConnected(g)==0);
     CHECK(ariel::Algorithms::shortestPath(g,0,4)=="-1");
     CHECK(ariel::Algorithms::isContainsCycle(g) == "3->2->1->3");
     CHECK(ariel::Algorithms::isBipartite(g)=="0");
}
