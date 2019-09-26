# Push-Swap
Algorithm project : We have at our disposal a set of int values, 2 stacks and a set of instructions to manipulate bot stacks.

set of instruction : 

+ sa : swap a - swap the first 2 elements at the top of stack a. 
+ sb : swap b - swap the first 2 elements at the top of stack b. 
+ ss : sa and sb at the same time
+ pa : push a - take the first element at the top of b an put it at the top of a. 
+ pb : push b - take the first element at the top of a an put it at the top of b. 
+ ra : rotate a - shift up all elements of stack a by 1. the first element becomes the last one.
+ rb : rotate b - shift up all elements of stack a by 1. the first element becomes the last one.
+ rr : ra and rb at the same time
+ rra : reverse rotate a - shift down all elements of stack a by 1. the last element becomes the first one.
+ rrb : reverse rotate b - shift down all elements of stack a by 1. the last element becomes the first one.
+ rrr : rra and rrb at the same time


# My algorithm : 

I made a greedy version of insertion sort algortithm :

Insertion sort : Each time an integer is push to stack b , it will be in the right position.

Greedy : before pushing an element to stack b , the algorithm will find the item from stack a that will need the minimum operation to be push perfectly in b.



# Compiling and running 
run `make`. 
Execute pushswap with the list of number you want : `./push_swap 4 8 5 1 2 3` 

