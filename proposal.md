# Final Project Proposal
## Leading Question
The Wiki Game, or the Wikipedia Race, is a popular game in which two players start on a randomly selected wikipedia page and must navigate through the hyperlinks within the page to a preselected target article. The fastest player wins. *Our project aims to automate the game and return the shortest hyperlink path between any two articles within Wikipedia.*

Our project will use a BFS traversal to traverse the graph and find the nodes of interest (article names which the user inputs). The shortest path algorithm will be used to find the shortest path between these two nodes and will return this path to the user. The force-directed graph drawing will create a visualization of the entire dataset which the user can explore.
## Data Acquisition
- We are using the publicly available data from Stanford Large Network Dataset Collection of wikipedia hyperlinks
    - Link: http://snap.stanford.edu/data/wiki-topcats.html
- We will acquire the data directly from the Stanford Network Analysis Project website, under the wiki-topcats dataset.
- We will process the data using the Stanford Network Analysis Platform, a network analysis and graph mining library. Since the graph is preprocessed from Wikipedia, we do not anticipate many issues. However, if needed, we will use SNAP to classify and connect nodes.
- In the event of an invalid input, or one which does not exist in the dataset (since the dataset only includes wikipedia articles which are linked > 100 times) the program will return that the input is not valid or does not have enough connections to compute a path.
- Since the dataset is limited to only Wikipedia pages with 100+ hyperlinks referencing them, the diameter of the graph is 9. We expect that this limitation will allow us to overcome any runtime or storage issues that may have otherwise interfered with the project.
## Graph Algorithms
- The graph traversal algorithm we will use:
    - BFS
        - Input: a single Wikipedia Article
        - Output: location of the node
        - Expected Big O: O(n)
    - Shortest Path (Dijkstra's Algorithm)
        - Input: two Wikipedia article names
        - Output: the path between the nodes
        - Expected Big O: O(|E| + |V|* log(V))
    - Force-directed graph drawing
        - Input: All vertices and edges in the graph dataset
        - Output: an interactive, colored force-directed graph containing all of the nodes and edges in our dataset.
        - Expected Big O: O(n^3)
## Timeline
- Week of Nov 7
    - Familiarize ourselves with [SNAP](http://snap.stanford.edu/proj/snap-icwsm/) and making graphs in C++ using basic datasets
    - Learn/research algorithms as necessary
- Week of Nov 14
    - Download, store, and organize our data of Wikipedia hyperlinks
    - Process data in graph notations (nodes and edges) in C++
    - Get started on BFS (and other algorithms)
- Week of Nov 21 (Thanksgiving)
    - BFS (everyone)
- Week of Nov 28
    - ½ Shortest Path (Sumin & Meghan)
    - ½ Force-Directed graph drawing (Emily & Sarah)
    - Implementation of necessary test cases
- Week of Dec 5
    - ½ Shortest Path (Sumin & Meghan)
    - ½ Force-Directed graph drawing (Emily & Sarah)
    - Implementation of necessary test cases
    - Start writing written report and organize deliverables
- Week of Dec 12
    - Write written report and organize deliverables
    - Wrap up and get ready to submit