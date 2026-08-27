package Experiment_1_DSA;

import java.util.LinkedList;

public class LinkedList_GFG {
	public static void main(String[] args) {
		LinkedList<String> linkedList = new LinkedList<>();

		linkedList.add("A");
		linkedList.add("B");
		linkedList.addLast("C");
		linkedList.addFirst("D");
		linkedList.add(2, "E");

		System.out.println(linkedList);

		linkedList.remove("B");
		linkedList.remove(3);
		linkedList.removeFirst();
		linkedList.removeLast();

		System.out.println(linkedList);
	}
}
