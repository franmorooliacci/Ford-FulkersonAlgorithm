# Ford-Fulkerson algorithm (FFA)

The FFA computes the maximum flow in a flow network. The idea behind the algorithm is as follows: as long as there is a path from the source (start node) to the sink (end node), with available capacity on all edges in the path, we send flow along one of the paths. Then we find another path, and so on. A path with available capacity is called an augmenting path.

## How to use it

1. Download the fordFulkerson.c and fordFulkerson.h files.
2. Open both files with a text editor.
3. In the first line of the fordFulkerson.h file, change the default value(6) to the given number of nodes of your graph. Save the file.

   ![Screenshot from 2023-10-11 11-07-15](https://github.com/franmorooliacci/Ford-FulkersonAlgorithm/assets/144138185/2b2a9a74-0251-4b99-a7ee-1e89cb5e089e)

4. In the fordFulkerson.c file, the graph is represented as a 2D matrix. Change the default values accordingly and save the changes.

   ![Screenshot from 2023-10-11 11-32-10](https://github.com/franmorooliacci/Ford-FulkersonAlgorithm/assets/144138185/35b47f4f-f953-439c-9d49-fd89586d8f54)

5. Open the terminal in the directory you have the two program's files and run the following command:\
`gcc -Wall fordFulkerson.c -o ffa`.
6. Use `./ffa` in the terminal to execute the program. The result of applicating the FFA will be displayed on the screen.
