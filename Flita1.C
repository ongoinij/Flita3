#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE *file1;
    FILE *file2;
    int first, second;
    file1 = fopen("C:\\GraphProject\\1\\forgraph1.txt", "r");
    file2 = fopen("C:\\GraphProject\\1\\forgraph1.dot", "w");
    fprintf(file2, "graph{\n");
    while (fscanf(file1, "%d %d", &first, &second) != EOF) 
    {
        fprintf(file2, "%d -- %d\n", first, second);
    }
    fprintf(file2, "}\n");
    fclose(file1);
    fclose(file2);
    
    FILE* matrixfile1 = fopen("forgraph1.txt", "r");
    int edges[100][100];
    int vertex1, vertex2;
    int num_vertices = 0;
    while (fscanf(matrixfile1, "%d %d", &vertex1, &vertex2) == 2) {
        edges[vertex1][vertex2] = 1;
        edges[vertex2][vertex1] = 1;
        if (vertex1 > num_vertices) {
            num_vertices = vertex1;
        }
        if (vertex2 > num_vertices) {
            num_vertices = vertex2;
        }
    }

            for (int i = 0; i < num_vertices+1; ++i)
            {
                for (int j = 0; j < num_vertices+1; ++j)
                {
                    printf("%d\t", edges[i][j]);

                    if (j == num_vertices)
                    {
                        printf("\n");
                    }
                }
            }
    
    bool flag = true;

    for (int i = 0; i < num_vertices+1; i++)
    {
        int count = 0;
        for (int j = 0; j < num_vertices+1; j++)
        {
            if(edges[i][j]!=0 && i!=j)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            flag = false;
            break;
        }
    }
    
    if(flag == true)
        printf("%s", "Graph is bonded");
    if(flag == false)
        printf("%s", "Graph is not bonded");
    system("dot -Tpng -O C:\\GraphProject\\1\\forgraph1.dot");
    system("C:\\GraphProject\\1\\forgraph1.dot.png");
    return 0;
}