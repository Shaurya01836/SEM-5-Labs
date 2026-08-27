# Experiment–1

## BDA Lab Manual

### AIM: Implement the following Data structures in Java

i) Linked Lists
ii) Stacks
iii) Queues
iv) Set
v) Map

---

# Program

## 1. LinkedList

```java
// Java Program to Demonstrate
// Implementation of LinkedList
// class

// Importing required classes
import java.util.*;

// Main class
public class GFG {

    // Driver code
    public static void main(String args[])
    {
        // Creating object of the
        // class linked list
        LinkedList<String> ll = new LinkedList<String>();

        // Adding elements to the linked list
        ll.add("A");
        ll.add("B");
        ll.addLast("C");
        ll.addFirst("D");
        ll.add(2, "E");

        System.out.println(ll);

        ll.remove("B");
        ll.remove(3);
        ll.removeFirst();
        ll.removeLast();

        System.out.println(ll);
    }
}
```

### Output:

```text
[D, A, E, B, C]
[A]
```

---

# 2. Stacks

```java
// Java code for stack implementation

import java.io.*;
import java.util.*;

class Test
{
    // Pushing element on the top of the stack
    static void stack_push(Stack<Integer> stack)
    {
        for(int i = 0; i < 5; i++)
        {
            stack.push(i);
        }
    }

    // Popping element from the top of the stack
    static void stack_pop(Stack<Integer> stack)
    {
        System.out.println("Pop Operation:");

        for(int i = 0; i < 5; i++)
        {
            Integer y = (Integer) stack.pop();
            System.out.println(y);
        }
    }

    // Displaying element on the top of the stack
    static void stack_peek(Stack<Integer> stack)
    {
        Integer element = (Integer) stack.peek();
        System.out.println("Element on stack top: " + element);
    }

    // Searching element in the stack
    static void stack_search(Stack<Integer> stack, int element)
    {
        Integer pos = (Integer) stack.search(element);

        if(pos == -1)
            System.out.println("Element not found");
        else
            System.out.println("Element is found at position: " + pos);
    }

    public static void main (String[] args)
    {
        Stack<Integer> stack = new Stack<Integer>();

        stack_push(stack);
        stack_pop(stack);
        stack_push(stack);
        stack_peek(stack);
        stack_search(stack, 2);
        stack_search(stack, 6);
    }
}
```

### Output:

```text
Pop Operation:
4
3
2
1
0
Element on stack top: 4
Element is found at position: 3
Element not found
```

---

# 3. Queue

```java
// Java program to demonstrate a Queue

import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {

    public static void main(String[] args)
    {
        Queue<Integer> q
        = new LinkedList<>();

        // Adds elements {0, 1, 2, 3, 4} to
        // the queue
        for (int i = 0; i < 5; i++)
            q.add(i);

        // Display contents of the queue.
        System.out.println("Elements of queue "
        + q);

        // To remove the head of queue.
        int removedele = q.remove();

        System.out.println("removed element-"
        + removedele);

        System.out.println(q);

        // To view the head of queue
        int head = q.peek();

        System.out.println("head of queue-"
        + head);

        // Rest all methods of collection
        // interface like size and contains
        // can be used with this
        // implementation.
        int size = q.size();

        System.out.println("Size of queue-"
        + size);
    }
}
```

### Output:

```text
Elements of queue [0, 1, 2, 3, 4]
removed element-0
[1, 2, 3, 4]
head of queue-1
Size of queue-4
```

---

# 4. Set

```java
// Java program Illustrating Set Interface

// Importing utility classes
import java.util.*;

// Main class
public class GFG {

    // Main driver method
    public static void main(String[] args)
    {
        // Demonstrating Set using HashSet
        // Declaring object of type String
        Set<String> hash_Set = new HashSet<String>();

        // Adding elements to the Set
        // using add() method
        hash_Set.add("Geeks");
        hash_Set.add("For");
        hash_Set.add("Geeks");
        hash_Set.add("Example");
        hash_Set.add("Set");

        // Printing elements of HashSet object
        System.out.println(hash_Set);
    }
}
```

### Output:

```text
[Set, Example, Geeks, For]
```

---

# 5. Map

```java
// Java Program to Demonstrate
// Working of Map interface

// Importing required classes
import java.util.*;

// Main class
class GFG {

    // Main driver method
    public static void main(String args[])
    {
        // Creating an empty HashMap
        Map<String, Integer> hm
        = new HashMap<String, Integer>();

        // Inserting pairs in above Map
        // using put() method
        hm.put("a", new Integer(100));
        hm.put("b", new Integer(200));
        hm.put("c", new Integer(300));
        hm.put("d", new Integer(400));

        // Traversing through Map using for-each loop
        for (Map.Entry<String, Integer> me :
        hm.entrySet()) {

            // Printing keys
            System.out.print(me.getKey() + ":");
            System.out.println(me.getValue());
        }
    }
}
```

### Output:

```text
a:100
b:200
c:300
d:400
```

