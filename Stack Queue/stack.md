<!-- Stack NOtes -->
For the stack with linked list:
The push operation is just simple just create a new node and just insert that value to that node, and point the top to that node.
For the pop first take the temp variable and take that temp to top and move the top to the next.


Push Linked List: Insert the element to the new node, and move the top to that new element.
Pop Linked List: Store the current value to the new variable, move the current value to the next value and just remove the last stored element on the variable.



For the queue with the linked list:
Push: Insert on the end node of new value.
Pop: Print start node value and first delete that start value and move to the next.
Top: Print start node value.




Do queue with stack:
  now:
push: 9 3 1 
pop: 9
push: 2 3: 3 1 2 3
top: 3
push: 12
pop: 3
push: 8: 1 2 3 12
pop:1


push: insert all the element to the stack push library: 9 3 1:
pop: now if we need to push the element first move all element to the new array with top,  now move back: 1 3 9
Top: move back to the second array and again move back now just return top.




//Correct me is that the correect steps for the infix to postfix conversion let me knwo if that i'm missing anything fix me:
1. if any operand appear no the infix just store on teh res string.
2. if any operator appear just store on the stack:
  3. at any time the operator should have less priority compare to the stack top element., like: st top: ^ but value operator is: - so we keep popping the element from the stack and send to teh res string until we don't find similar priority operator or lower priority operator.
  4. any time closing bracket appear, keep poping the element from the stack until we don't find opening bracket and store that string to res string
5. at last just add rest of teh stack top element to the res string each time that's it.



For the arthmatic expressiona:
the priority of: 
value priority:
^      3
/*     2
+-     1
rest   -1



I have to take care of about learning what to use when of whether a character or the string what to use, in the which scenario.



For the Implement Min stack solution:
For the first of just iterate to find a min element for the getMin.
Another approach is use the key value pair on teh stack to track each time a minValue alongside top element.
Third appraoch with math appraoch: we track the smallestElement but there will be the some condition: 
  we use the formula of: 2*smallestValue-currentValue , during push if the smallestValeu on minvalue greate than current inserted element.
  for the pop use the same approach of: if(x<minvalue>) then return smallestVAlue or other condtion just return stack top element.
  For the top same appraoch of math appraoch.





For the next greter Element:
We can use the monotonic stack where we store the element basis on the either greater or smaller element. also applied for the previous smaller element.




For the trapping rain water problem:
There should be a water taller on the both side left and also on the right side to store the water.


The prefix mean the maximum till that index from start, while suffix mean maximim til that index from last.


of pse and nse i've to understand monotonic stack problem.

For the Largest Histogram problem, there should be the prerequisite for the pse, and nse which are: (previous smaller element.). with the stack store the indices and just track the indices of the pse and nse.


The maximum rectangle approach is the almost similar to the largest histogram problem.

With the remove k digits it's too easy question i feel.

For the stock span problem: The appraoch of the brute force just take the number that is greater than tha value with the count.
Optimal solution is the previousGreaterElement, with on the stack, we would be storing the value with the indices each time and whenever we require to do the output just use the formula of the:   index-st.size():st.


Celebrity Problem:
With brute force is just check personKnowMe and inowPerson with set to the increament the row and column, and if any point that the therPersonKnowMe become n-1 and iKnowPerson become 0 that means it'a that celebrity.
For the optimal solution we can the two poiner appraoch, with any point that variablle have the 0 on entire column side, that it ca'can't be a celebrity so we go the tne next, and at the last we reach:top<bottom.
Now we can check that entire row and col is that thre rwo all filed with the 0 and while col all fileed with teh 1 that mean it's a celbirty with teh o(n) time complexity.


For the Least Recently Used Problem:
We've to used the doubly linked list and alsoo the unordered map to get that whether element exist or notw ith o(1) space complexoity.







