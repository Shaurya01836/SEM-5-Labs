package Experiment_1_DSA;

import java.util.Stack;

public class Stack_Test {
	private static void stackPush(Stack<Integer> stack) {
		for (int index = 0; index < 5; index++) {
			stack.push(index);
		}
	}

	private static void stackPop(Stack<Integer> stack) {
		System.out.println("Pop Operation:");
		for (int index = 0; index < 5; index++) {
			System.out.println(stack.pop());
		}
	}

	private static void stackPeek(Stack<Integer> stack) {
		System.out.println("Element on stack top: " + stack.peek());
	}

	private static void stackSearch(Stack<Integer> stack, int element) {
		int position = stack.search(element);
		if (position == -1) {
			System.out.println("Element not found");
		} else {
			System.out.println("Element is found at position: " + position);
		}
	}

	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<>();
		stackPush(stack);
		stackPop(stack);
		stackPush(stack);
		stackPeek(stack);
		stackSearch(stack, 2);
		stackSearch(stack, 6);
	}
}
