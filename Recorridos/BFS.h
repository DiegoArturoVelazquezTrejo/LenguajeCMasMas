#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

enum NODE_COLOR{
  WHITE,
  GRAY,
  BLACK
};

struct vertex{
  int node_id;
  std::string value;
  std::vector<std::pair<vertex*, int>> adj_list; 

  NODE_COLOR  color = WHITE; 
  int distance  = INT_MAX; 
  vertex * predecessor = NULL; 

  vertex(){}
}; 

class simple_graph{
  std::vector<vertex*> vertex_list; 
  int access_counter = 0; 
  friend void BFS(simple_graph&, int); 

  vertex* initialize_and_find_vertex(int vertex_id){}; 

  vertex* initialize_and_find_vertex(int vertex_id){
    vertex * v1 = NULL; 
    for each(auto vertex1 in vertex_list){
      vertex1->color = WHITE; 
      vertex1->distance = -1; 
      vertex1->predecessor = NULL; 

      if(vertex1 -> node_id == vertex_id){
        v1 = vertex1; 
      }
    }
    return v1; 
  }
  void depth_first_search(vertex* v){
    v -> color = GRAY; 
    std::cout <<" ( " << v-> node_id; 
    for each(auto adj_vertex in v->adj_list){
      if(adj_vertex.color == WHITE){
        depth_first_search((vertex*)(adj_vertex.first)); 
      }
    }
    std:.cout << v->node_id << " )"; 
    v-> color = BLACK; 
  }

  public: 
    simple_graph(){}
    ~simple_graph(){}
}; 

void BFS(simple_graph &graph, int source_vertex_id){
  std::queue<vertex*> q; 
  vertex * v1 = graph.initialize_and_find_vertex(source_vertex_id); 
  if(v1 == NULL){
    throw std::runtime_error("BFS failed: cannot find  source vertex with id "+std::to_string(source_vertex_id)); 
  }
  else{
    q.push(v1); 
    while(!q.empty()){
      vertex* u = q.front(); 
      q.pop(); 
      for each (auto v in u->adj_list){
        if(v.first->color == WHITE){
          v.first-> color = GRAY; 
          v.first->distance = u->distance + 1; 
          v.first ->predecessor = u; 
          q.push((vertex*) v.first); 
        }
      }
      u->color = BLACK; 
    }
  }
}

void DFS(simple_graph& graph, int source_vertex_id=-1){
  if(source_vertex_id != -1){
    vertex * v1 = graph.initialize_and_find_vertex(source_vertex_id); 
    if(v1 == NULL){
      throw std::runtime_error("DFS failed: cannot find  source vertex with id "+std::to_string(source_vertex_id)); 
    }else{
      graph.depth_first_search(v1); 
      std::cout << std:endl; 
    }
  }
  for each(auto v1 in graph.vertex_list){
    if(v1 -> color == WHITE){
      graph.depth_first_search(v1); 
      std::cout << endl; 
    }
  }
}
#endif 