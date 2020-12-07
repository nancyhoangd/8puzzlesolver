/*
Nancy Hoang (ndh9tsj)
11/20/20
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <map> 
using namespace std;

/**
 * @brief Determines the possible tiles that can be swapped  with 0 and moves them 
 * @return A vector of vectors containing strings and each individual vector is a possible configuration of the puzzle after swapping a tile with 0. 
 * @param config is a vector of strings that represents the puzzle for which we are determining the possible moves for
 */
vector<vector<string>> determine_adjacent_nodes(vector<string> config){
  int locationOf0;
  vector<vector<string>> adjacencies;
  vector<string> copyOfConfig = config; 
  for (int i = 0; i < config.size(); i++){
    if (config[i] == "0"){
      locationOf0 = i;
      break;
    }
  }
  switch(locationOf0){
  case 0:
    copyOfConfig[0] = config[1]; // swap with index 1
    copyOfConfig[1] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[0] = config[3]; // swap with index 3
    copyOfConfig[3] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 1:
    copyOfConfig[1] = config[0]; // swap with index 0
    copyOfConfig[0] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[1] = config[2]; // swap with index 2
    copyOfConfig[2] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[1] = config[4]; // swap with index 4
    copyOfConfig[4] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 2:
    copyOfConfig[2] = config[1]; // swap with index 1
    copyOfConfig[1] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[2] = config[5]; // swap with index 5
    copyOfConfig[5] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 3:
    copyOfConfig[3] = config[0]; // swap with index 0
    copyOfConfig[0] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[3] = config[4]; // swap with index 4
    copyOfConfig[4] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[3] = config[6]; // swap with index 6
    copyOfConfig[6] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 4:
    copyOfConfig[4] = config[1]; // swap with index 1
    copyOfConfig[1] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[4] = config[3]; // swap with index 3
    copyOfConfig[3] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[4] = config[5]; // swap with index 5
    copyOfConfig[5] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[4] = config[7]; // swap with index 7
    copyOfConfig[7] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 5:
    copyOfConfig[5] = config[2]; // swap with index 2
    copyOfConfig[2] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[5] = config[4]; // swap with index 4
    copyOfConfig[4] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[5] = config[8]; // swap with index 8 
    copyOfConfig[8] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 6:
    copyOfConfig = config;
    copyOfConfig[6] = config[3]; // swap with index 3
    copyOfConfig[3] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[6] = config[7]; // swap with index 7 
    copyOfConfig[7] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 7:
    copyOfConfig[7] = config[8]; // swap with index 8 
    copyOfConfig[8] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[7] = config[4]; // swap with index 4
    copyOfConfig[4] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[7] = config[6]; // swap with index 6 
    copyOfConfig[6] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;
  case 8:
    copyOfConfig = config;
    copyOfConfig[8] = config[5]; // swap with index 5
    copyOfConfig[5] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config;
    copyOfConfig[8] = config[7]; // swap with index 7 
    copyOfConfig[7] = "0";
    adjacencies.push_back(copyOfConfig);
    copyOfConfig = config; 
    break;    
  }
  return adjacencies; 
}

/**
 * @brief This file is a puzzle 8 solver and uses breadth-first search to find the minimum # of steps to solve the puzzle. 
 * @details The goal state is 1, 2, 3, 4, 5, 6, 7, 8, 0.
 * @details prints IMPOSSIBLE if the puzzle is not solvable else prints the minimum # of steps needed to solve the puzzle. 
 */ 
int main(){
  vector<string> puzzle(9); // initial graph state
  vector<string> goal{"1", "2", "3", "4", "5", "6", "7", "8", "0"};

  // taking in the puzzle and storing into vector; 
  cout << "Enter puzzle" << endl; 
  for (int i = 0; i < 9; i++){
    cin >> puzzle[i];
  }
  cout << "Solving puzzle" << endl; 

  // checking for solvability
  int solvabilityCheck = 0; 
  for (int i = 0; i<puzzle.size()-1; i++){
    for (int j = i+1; j < puzzle.size(); j++){
      if ((puzzle[i] > puzzle[j]) && (puzzle[i] != "0") && (puzzle[j] != "0")){
	      solvabilityCheck++;
      }
    }
  }
  if (solvabilityCheck % 2 != 0){
    cout << "IMPOSSIBLE" << endl;
    return 0; 
  }
 
  // vector<string> = representation of graph, int = distance
  map<vector<string>, int> graph; // keeps track of if node has been visited
  graph[puzzle] = 0;
 
  //BFS
  queue<vector<string>> q;
  vector<string> v;
  vector<vector<string>> adjacentNodes;
  vector<string> curNode;
  q.push(puzzle);

  while (!q.empty()){
    v = q.front();
    q.pop();
    adjacentNodes = determine_adjacent_nodes(v);
    for (int i = 0; i < adjacentNodes.size(); i++){
      curNode = adjacentNodes[i];
      if (graph.find(curNode) == graph.end()){
	      graph[curNode] = graph[v]+1;
	      q.push(curNode);
	      bool found = true;
	      for (int j = 0; j<curNode.size(); j++){
	        if (goal[j] != curNode[j]){
	          found = false;
	        }
	      }
	      if (found){
	        cout << graph[curNode] << endl;
	        return 0; 
	      }
      }
    }
  }
  return 0; 
}
