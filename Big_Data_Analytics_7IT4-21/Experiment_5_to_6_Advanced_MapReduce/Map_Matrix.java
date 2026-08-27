package Experiment_5_to_6_Advanced_MapReduce;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class Map_Matrix extends Mapper<LongWritable, Text, Text, Text> {
	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		Configuration configuration = context.getConfiguration();
		int rowsInFirstMatrix = Integer.parseInt(configuration.get("m"));
		int columnsInSecondMatrix = Integer.parseInt(configuration.get("p"));
		String[] indicesAndValue = value.toString().split(",");
		Text outputKey = new Text();
		Text outputValue = new Text();

		if (indicesAndValue[0].equals("M")) {
			for (int column = 0; column < columnsInSecondMatrix; column++) {
				outputKey.set(indicesAndValue[1] + "," + column);
				outputValue.set("M," + indicesAndValue[2] + "," + indicesAndValue[3]);
				context.write(outputKey, outputValue);
			}
		} else {
			for (int row = 0; row < rowsInFirstMatrix; row++) {
				outputKey.set(row + "," + indicesAndValue[2]);
				outputValue.set("N," + indicesAndValue[1] + "," + indicesAndValue[3]);
				context.write(outputKey, outputValue);
			}
		}
	}
}
