/*
    Authors: Orlando Mota Pires https://github.com/orlandomotapires
*/

#include "./libraries/Flooding.h"

int main() {
    FILE *file_A;

    file_A = fopen("./matrixes/adj_a.txt", "rt");

    graph_a = initialize_graph();

    if (file_A == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    read_file_create_graph(&graph_a, file_A);

    printf("\n=-=-=-=-=-=-=-=-=-= Graph =-=-=-=-=-=-=-=-=-=\n");
    print_complete_graph(graph_a);

    printf("\n=-=-=-=-=-=-=-=-=-= Result =-=-=-=-=-=-=-=-=\n");
    printf("Number of connected components with DFS: %d\n", number_of_connected_components(0)); // 0 For DFS
    printf("Number of connected components with BFS: %d\n", number_of_connected_components(1)); // 1 For BFS

    fclose(file_A);

    return 0;
}
