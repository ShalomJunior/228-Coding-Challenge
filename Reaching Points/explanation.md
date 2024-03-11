# Explanation of the solution

    Starting from position (x1, y1) we are asked to check if you can reach position (x2, y2) knowing that the only move we can do is when at position (x, y) :

    - move to position (x, y + x) or
    - move to position (x + y, y)

The basic solution works here like trying every possible moves. Note that according to the constraints `0 < x , y < 1000`. This means that if we want to check all possible reaching points starting from `(x1, y1)` we will check at most **1000 \* 1000** points. Since currents computer can process around 1e8 instructions under 1 seconds our solution is garenteed to pass. The only thing to have in mind is to avoid revisiting the same position twice since it is useless.

If you are some seasonned coder you might have noticed that this is a classic recursion or a graph traversal (if you want to see it like that)

**Check the source codes to see the implementation**
