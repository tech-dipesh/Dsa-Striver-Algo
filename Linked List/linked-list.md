1. One the linked list we must check every case first before writing a code.

WE store the linked list by first put that into the memory with the random location. and just set the tail next of the linked list that new variable.



We just dont' wantt to pass nullptr every time, so we can set only onee values, on the constructorby default set to the nullptr.


On the linked list, we also can delete any variable next value, just don't need to delete any value.


At the majority time i don't need to update the temp variable to the head variable.




When on any point if you alter the value next it could cause:
(1) (2) (4)
When insert: 3 and create node=3, 
now if we do: temp->next=node.
It could break the pointer rather we do.
node->next=temp->next;
temp->next=node->next;
That's it.



Make sure on the doubly linked list to take a another variable to track the previous and make value next to current value while current previous to new vlaue 
and prvious next to current value and current value back to previous:

//Join new inserted value to the next value:
value->next=temp->next;
temp->next->prev=value;

Front to connect with new value:
temp->next=value;
value->prev=temp;




For the add two number i've the one approach that's let's check, 
first reverse the both given linked list, and now we can add the number from the back order and for thee returing a result again reverse that given output tha'ts it we got the result.




For the odd even LInked list problem:
Memorize the even value or odd value on teh separate memory about head->next to store on teh even value.



Odd Even Linked List: 11/13 (Brute Force with store on array with first odd and then even, Optimal is first take the odd value with jump to two pointer and take even with jump to two point)


For the odd even that make sure cheeck the base case with the better way and also the while loop condition with even not reach null and not even next.



For the sort given 0s, 1s and 2s we can do the link arrangemeent o it can be on teh correct order, 




For the sort a given 0s, 1s onad 0s make a link of the eeach of one, with zeroNode, oneNode, and towNode with teh dummyhead, so it doesn't need if else condition every time, with after linking entire zero to zero one to one with three node, now just connect the zeroNode to the oneDummy next, and oneNode to twodummy next.




For the Remove kth node fromt eh end of the LL:
we've to use the tortoise and harare algorithm as the first fast will move k times, and both move simeltounsly now we can just remove the slow pointer:



For the reverse a linke list problem:
i can solved easily with three appraoch, on recursive we've make base case:
the base case is until one element or no element, we'l be calling a recursion with new node creation until it don't become single problem, 
then now the front will be the head next, as front store the head next variable:
on single call front store the nullpointer, now we'll be making front next to the head, and with 
with head next to the  nullptr:


base case
on new variable call head next,
set front node to the head next node, 
 set the front next variable to head, to go backward,
   set the head next to nullpointer of front call.
   now return teh new variable which called the head next.


   


IN every major case that the slow and fast pointer are quite useful on the linked list.


For checking a palindrome we can implment first reverse and check reverse and front is that same,
another approach is using the stack and anotehr is,
first from all half of the elemetn reverse a link and then check is that a same from first and second half.



For the add 1 linked list approach, reverse and keep adding the carray value, and if at last 1 value have then again crate new node with 1 then connect head.
or use the recursive appraoch, with go backtracking till last and add carray 1 and if the value is <9 then just return 0 or return 1.





For finding a intersection of the given linked list, there are the 4 approach i can use to solve the problem:
1. Use the brute force of subgenerate all teh nodes, make sure whenever nested node finished looping, move back to teh next node of the head. o(n^2)
2. With the hashmap, first insert all the element from the first to teh hashmap with 1 point if that exist of the node, and then just check on second node if that node exist just return it. o(2n) && o(n)
3. Find the both size, whichever is the smaler point that to teh same size, and traverse, but first have to find the length, and move bigger to teh same size and traverse: o(n)+o(k)+o(n)
4. Use the linking, if the first ll is finished point to the second, and if second finished point to the first they'll meet on any point.



The find middle of the linked list, i've solved with only once times, with teh count and divide 2, brute and slow and fast pointer, with tortoise and harare algorithm approach.



Detect Cycle:
For the brute force, 
The Optimal appraoch is obviously use the tortoise and harare algorithm, 


Find the length of the Cycle Linked list:
The brute force is using teh hashmap approach, 
each time we store the index of that value and, now after that increase the index, now if that node appear anywhere on the linekd list that mean it's a loop detect. so we can get that index, and subtract with that node value.
return currentIndex-mp[temp]. that value index.

The Optimal with:
Tortoise and harare algorithm with any point if the slow and fast pointer meet, count the total value with where that slow is nto matched with fast, 
just mvoe the fast and count and return it.






For the Find the startring point of the Loop Linked List:
We've to answer the two question: 
How are you we sure that they will collide.
How are we sure that the collision point will be started.





For the remove duplciates, make sure to keep going the next node until we don't find the not equal node, and then just connect it.



Reverse nodes in k group size:
if we dont' have the k element at the last on the linked list, we don't reverse the node.
The steps are:
//i: Find teh kth node head with the iteration (k)
ii: if the kthnode is appear to be the last then just move the prviousNode to the temp and break don't need further opeation.
(make sure to preserver the prevNode next to temp to store that left elment)
iii: First store the kthndoe next elemetn as we're breaking a kthnode to the indivisually as we need kthnode next later.

iv: Rverse given LL:
v: if that point where a given linked list is the first then set the head node to the kthnode.
vi: if that not the first call: point prevNode->next=kthNode.
vii now just move the prviousNode to teh temp and temp to the nextNode preserved nextNode.



Almos i've written a code of the Rotate LL code that is almost correct, with brute force correct.



For the merge two sorted linked list, first appraoch is using the array createion and sorted and again move to linke list
another is linked changes, with teh dummynode of teh head point, and then just creatre a temp point to dummy and just set that a smaller valu to temp and move temp=t1; and t1=t1->next
and last should be return dummyNode, to store the head of teh node.


Merge Sort: 
There is the sligh change that happen compare to the array:
First is, we find the middle by thte tortoise and hare algoritm, with make sure to run fast from head->next not from the head.
We don't call with low middle high instead we only call with low and high, but with retun the call function.
The approach for the merge two sorted linekd list is same as that we do above.
Also time complexity is: o(nlogn+n/2)





The flatten a linked list will also have the child pointer alongside with teh next pointer. 
every child notes are the sorted child noets. 
# Check Later have'nt come up with the undersrtand a problem.




Merge K Sorted List:
On the given list of the node, we've to sort them and return the new list.
Brute force:
With put them all into the single array and again put them into the new head and retrun that head.



For the Clone a Linked List with the random Pointer:
    1. The approach is using the hashmap approach:
      i. First insert the each value with first create a node and insert that temp value and store on teh hashmap, 
      ii: Now we just haave to connect or retrieved from the hashmap to copy:
          i: First store the copyNode with from the map,
          ii:: now set the next, ->random from the hashmap value.

      iii: now retrurn the hashmap node value.



    2. The second approach is only improve a space complexity not recommnd to study:



Design broswer history question is the super simmple question,, with doubly linekd list, it's too easy.
