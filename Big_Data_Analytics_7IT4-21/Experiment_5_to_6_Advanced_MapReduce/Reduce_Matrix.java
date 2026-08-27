package Experiment_5_to_6_Advanced_MapReduce;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class Reduce_Matrix extends Reducer<Text, Text, Text, Text> {
	@Override
	public void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		Map<Integer, Float> firstMatrix = new HashMap<>();
		Map<Integer, Float> secondMatrix = new HashMap<>();

		for (Text value : values) {
			String[] parts = value.toString().split(",");
			if (parts[0].equals("M")) {
				firstMatrix.put(Integer.parseInt(parts[1]), Float.parseFloat(parts[2]));
			} else {
				secondMatrix.put(Integer.parseInt(parts[1]), Float.parseFloat(parts[2]));
			}
		}

		float result = 0;
		for (Integer index : firstMatrix.keySet()) {
			if (secondMatrix.containsKey(index)) {
				result += firstMatrix.get(index) * secondMatrix.get(index);
			}
		}
		context.write(key, new Text(Float.toString(result)));
	}
}
package Experiment_5_to_6_Advanced_MapReduce;

public class Reduce_Matrix {
    
}
