# Insert at Tail

You are given the pointer to the head node of a linked list and an integer
to add to the list. Create a new node with the given integer. Insert this
node at the tail of the linked list and return the head node of the linked
list formed after inserting this new node. The given head pointer may be
null, meaning that the initial list is empty.

## Input Format

You have to complete the _insertAtTail_ method. It takes two arguments:
the head of the linked list and the integer to insert at the tail. You
should <b>not</b> read any input from the console.

The input is handled by code in the editor as follows:
The first line contains an integer _n_, denoting the elements of the linked
list. The next _n_ lines contain an integer each, denoting the element that
needs to be inserted at the tail.

## Constraints
- 1 <= n <= 1000
- 1 <= _list[i]_ <= 1000

## Output Format

Insert the new node at the tail and just return the head of the updated
linked list. Do <b>not</b> print anything to the console.

The ouput is handled by the code in the editor and is as follows:
Print the elements of the linked list from head to tail, each in a new line.

## Sample Input

```
5
141
302
164
530
474
```

## Sample Output

```
141
302
164
530
474
```

## Explanation

First the linked list is _NULL_. After inserting 141, the list is 141 -> _NULL_.

After inserting 302, the list is 141 -> 302 -> _NULL_.

After inserting 164, the list is 141 -> 302 -> 164 -> _NULL_.

After inserting 530, the list is 141 -> 302 -> 164 -> 530 > _NULL_. After inserting
474, the list is 141 -> 302 -> 164 -> 530 -> 474 -> _NULL_, which is the final list.
