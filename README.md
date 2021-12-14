# Wikipedia Game
### (1) The location of all major code, data, and results. 
- Logistics Folder:
    * Team Contract
    * Team Proposal
    * Development Log

- Data Folder:
    * Fake data files for test cases (vertices and edges)
    * Shortened data files (vertices and edges)

### (2) Full instructions on how to build and run your executable, including how to define the input data and output location for each method. 
- Compiling and Running the code
    * compile using make
    * run using ./graph
    * main will run, this currently reads in the data, constructs a graph, constructs a visualization of the graph and a forcedirected visualization of the graph
    * there are commented out commands for the user to input for running shortest path and pagerank

- Constructing the Graph
    * create a graph pointer using the ***constructGraph*** function
        * Input: 3 parameters
            * string filename of the file with vertices (format should have 1 vertex on each line with an index followed by a name: "0 Kool-Aid")
            * string filename of the file with edges (format should have the indices of the two vertices which will make that edge: "0 176"
            * int the number of data points / verticies you want to read in from that file
        * Output: pointer to a Graph objext

- Traversing the Graph
    * Construct a graph 
    * Create a BFS traversal object
        * Input: pointer to the Graph object
        * Output: a traversed graph

- Finding the Shortest Path
    * Construct a graph
    * Create a BFS traversal object
    * Run ***shortestPath*** on the BFS object
        * Input: 3 parameters
            * pointer to the the graph
            * string name of the first vertex between which the path should be found
            * string name of the second vertex between which the path should be found
        * Output:
            * string path from the first vertex to the second vertex that is the shortest path possible

- Visualizing the Graph
    * Construct a graph
    * Create a GraphVisualization object
    * run ***initialLayout*** on the GraphVisualization object
        * Input: pointer to the graph
        * Output: map from strings to a pair of integers or the "layout" of the graph
    * run ***drawGraph*** on the GraphVisualization object
        * Input: map from strings to a pair of integers or the "layout" of the graph
        * Output: png of the drawn graph
    * Write the PNG into a file and visualize

- Visualizing the Force Directed Graph
    * Construct a graph
    * Create a GraphVisualization object
    * run ***initialLayout*** on the GraphVisualization object
        * Input: pointer to the graph
        * Output: map from strings to a pair of integers or the "layout" of the graph
    * run constructForceDirectedGraph on the GraphVisualization object
        * Input: 
            * map from strings to a pair of integers or the "layout" of the graph
            * pointer to the graph
            * int max iterations (we reccomend 30)
            * int length (we reccomend 101)
            * int cooling factor (we reccomend 1)
        * Output: map from strings to a pair of integers or the "layout" of the force directed graph   
    * run ***drawGraph*** on the GraphVisualization object
        * Input: map from strings to a pair of integers or the "layout" of the force directed graph   
        * Output: png of the drawn force directed graph
    * Write the PNG into a file and visualize

- Running Page Rank
    * 

### (3) Full instructions how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.
- Making and running tests
    * run make test
    * run ./test
- Content of tests
    * graph_tests: makes sure that files are properly read and organized into a graph with correct vertices and edges
        * 
        *
    * bfs_tests: makes sure that graph traversal and shortest path returns the correct path for a anumber of edge cases
        *
        *
    * forcedirected_tests: makes sure that the visualization matches the computation and that all vertices are run
        *
        *
    * pagerank_tests: the test suite for the pagerank algorithm tests every method in the cpp file. Each test begins by creating a graph, setting the correct solution, and then comparing the correct solution to the solution outputted by the method in pagerank. 
        * 