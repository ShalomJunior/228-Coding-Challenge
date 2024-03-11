# Explanation of the solution

    In this problem we are asked to find the minimum cost over all possible paths that start at a certain node (in this case 1) traverse some node x and y in that order and ends at a last node (in this case n). Each edges have a certain weight

This is a classic problem of graph like a direct application of `djikstra algorithm`. If you are not aware of djikstra check on **wikipédia**

Now our problem can be split into 3 :

- Find the shortest path (saying the minimum cost of the path) from 1 to x
- Find the shortest path from x to y
- Find the shortest path from y to n

Since Djikstra algorithm helps us to find the shortest path (minimum cost in our case) between two nodes a and b we can run it **three times** and just sum the values that we want
