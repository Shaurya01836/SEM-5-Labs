package Experiment_1_DSA;

import java.util.HashMap;
import java.util.Map;

public class Map_GFG {
	public static void main(String[] args) {
		Map<String, Integer> hashMap = new HashMap<>();
		hashMap.put("a", 100);
		hashMap.put("b", 200);
		hashMap.put("c", 300);
		hashMap.put("d", 400);

		for (Map.Entry<String, Integer> entry : hashMap.entrySet()) {
			System.out.print(entry.getKey() + ":");
			System.out.println(entry.getValue());
		}
	}
}
