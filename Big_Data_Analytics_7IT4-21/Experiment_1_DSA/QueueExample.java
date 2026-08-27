package Experiment_1_DSA;

import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList<>();

		for (int index = 0; index < 5; index++) {
			queue.add(index);
		}

		System.out.println("Elements of queue " + queue);
		int removedElement = queue.remove();
		System.out.println("removed element - " + removedElement);
		System.out.println(queue);
		int head = queue.peek();
		System.out.println("head of queue - " + head);
		int size = queue.size();
		System.out.println("Size of queue - " + size);
	}
}
