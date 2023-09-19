#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

#define num_vertices 4

/*******************
 * Global variables
 *******************/

int adjacency_matrix_a[50][50];
int visited_vertices[500];
Graph *graph_a;

/*******************
 * Function Signatures
 *******************/

void read_file_create_graph(Graph **graph, FILE *file);
void flood_with_DFS(int v);
void flood_with_BFS(int v);
int number_of_connected_components(int choice);

/*******************
 * Function Implementations
*******************/

void read_file_create_graph(Graph **graph, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' ') insert_main_list(graph, Line[a]);   
        }
    }

    while (!feof(file)) {
        if (fgets(Line, 100, file)) {
            for (a = 0; a <= (strlen(Line)); a++) {
                if (Line[a] == '1') {
                    node_to_insert = find_vertex(*graph, a + 1);
                    base_node = find_vertex(*graph, (i + 1));
                    insert_at_end_adj_list(&node_to_insert->main_list, &base_node);
                }

                if (Line[a] == '1' || Line[a] == '0') {
                    adjacency_matrix_a[i][a] = Line[a];               
                }
            }
        }
        i++;
    }
}

void flood_with_DFS(int v) {
    struct Stack remaining_nodes;
    int capacity = 50;

    create_stack(&remaining_nodes, capacity);
    push(&remaining_nodes, v);

    while (!is_empty(&remaining_nodes)) {
        int current_node = pop(&remaining_nodes);

        if(!visited_vertices[current_node]){
            visited_vertices[current_node] = 1;

            Graph *aux = find_vertex(graph_a, current_node - 64);
            if(aux->main_list->adjacency_list != NULL){
                Node *neighbors = aux->main_list->adjacency_list;

                while(neighbors != NULL){
                    push(&remaining_nodes, neighbors->pointed_letter->letter);
                    neighbors = neighbors->adjacency_list;
                }
            }
                
        }
            
    }
}

void flood_with_BFS(int v) {
    Queue remaining_nodes;
    int capacity = 50;

    create_queue(&remaining_nodes, capacity);
    insert(&remaining_nodes, v);

    while (!is_empty(&remaining_nodes)) {
        int current_node = remove_item(&remaining_nodes);

        if(!visited_vertices[current_node]){
            visited_vertices[current_node] = 1;

            Graph *aux = find_vertex(graph_a, current_node - 64);
            if(aux->main_list->adjacency_list != NULL){
                Node *neighbors = aux->main_list->adjacency_list;

                while(neighbors != NULL){
                    insert(&remaining_nodes, neighbors->pointed_letter->letter);
                    neighbors = neighbors->adjacency_list;
                }
            }
                
        }
            
    }
}

int number_of_connected_components(int choice){
    
    memset(visited_vertices, 0, sizeof(visited_vertices));

    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Flooding algorithm using DFS (choice == 0) =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    if(choice == 0){
        memset(visited_vertices, 0, sizeof(visited_vertices));
        int num_isles_dfs = 0;
        for(int i='A'; i<'A'+4; i++){
            if(visited_vertices[i] != 1){
                flood_with_DFS(i);
                num_isles_dfs++;           
            }
        }
        return num_isles_dfs;
    
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Flooding algorithm using BFS (choice == 1) =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    }else{
        memset(visited_vertices, 0, sizeof(visited_vertices));
        int num_isles_bfs = 0;
        for(int i='A'; i<'A'+4; i++){
            if(visited_vertices[i] != 1){
                flood_with_BFS(i);
                num_isles_bfs++;
            }
        }
        return num_isles_bfs;
    }
}