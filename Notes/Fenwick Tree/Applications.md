This structure is useful to implement dynamic cumulative frequency tables. 

This video clearly illustrates what happens to compute the fenwick tree: 
https://www.youtube.com/watch?v=uSFzHCZ4E-8&ab_channel=StableSort

If a range sum is desired, sum(L, R) then we can use sum(R) - sum(L-1) to determine the sum between those values.

