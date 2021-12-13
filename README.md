# Wikipedia 
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
    * 

- Traversing the Graph
    * 

- Finding the Shortest Path
    * 

- Visualizing the Graph
    * 

- Visualizing the Force Directed Graph
    * 

- Running Page Rank
    * 

### (3) Full instructions how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.
- Making and running tests
    * run make test
    * run ./test
- Content of tests
    * graph_tests: makes sure that files are properly read and organized into a graph with correct vertices and edges
    * bfs_tests: makes sure that graph traversal and shortest path returns the correct path for a anumber of edge cases
    * forcedirected_tests: makes sure that the visualization matches the computation and that all vertices are run
    * pagerank_tests