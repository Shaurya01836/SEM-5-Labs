package Experiment_5_to_6_Advanced_MapReduce;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.MultipleOutputs;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class CalculateMaxAndMinTemeratureWithTime {
	public static final String CALIFORNIA = "California";
	public static final String NEWYORK = "Newyork";
	public static final String NEWJERSY = "Newjersy";
	public static final String AUSTIN = "Austin";
	public static final String BOSTON = "Boston";
	public static final String BALTIMORE = "Baltimore";

	public static class WhetherForcastMapper extends Mapper<Object, Text, Text, Text> {
		@Override
		public void map(Object key, Text dayReport, Context context)
				throws IOException, InterruptedException {
			StringTokenizer tokens = new StringTokenizer(dayReport.toString(), "\t");
			if (!tokens.hasMoreTokens()) {
				return;
			}
			String cityAndDate = tokens.nextToken();
			Text outputKey = new Text(cityAndDate);
			while (tokens.hasMoreTokens()) {
				String time = tokens.nextToken();
				if (!tokens.hasMoreTokens()) {
					break;
				}
				context.write(outputKey, new Text(time + "," + tokens.nextToken()));
			}
		}
	}

	public static class WhetherForcastReducer extends Reducer<Text, Text, Text, Text> {
		private MultipleOutputs<Text, Text> outputs;

		@Override
		public void setup(Context context) {
			outputs = new MultipleOutputs<>(context);
		}

		@Override
		public void reduce(Text key, Iterable<Text> values, Context context)
				throws IOException, InterruptedException {
			String city = key.toString().split("_")[0];
			String date = key.toString().split("_", 2)[1];
			String minimum = null;
			String maximum = null;
			float minimumValue = Float.MAX_VALUE;
			float maximumValue = -Float.MAX_VALUE;

			for (Text value : values) {
				String[] parts = value.toString().split(",", 2);
				float temperature = Float.parseFloat(parts[1]);
				if (temperature < minimumValue) {
					minimumValue = temperature;
					minimum = "Time:" + parts[0] + " MinTemp:" + parts[1];
				}
				if (temperature > maximumValue) {
					maximumValue = temperature;
					maximum = "Time:" + parts[0] + " MaxTemp:" + parts[1];
				}
			}

			Text result = new Text(minimum + " " + maximum);
			outputs.write(city, new Text(date), result);
		}

		@Override
		public void cleanup(Context context) throws IOException, InterruptedException {
			outputs.close();
		}
	}

	public static void main(String[] args) throws Exception {
		Configuration configuration = new Configuration();
		Job job = Job.getInstance(configuration, "WheatherStatisticsOfUSA");
		job.setJarByClass(CalculateMaxAndMinTemeratureWithTime.class);
		job.setMapperClass(WhetherForcastMapper.class);
		job.setReducerClass(WhetherForcastReducer.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		for (String city : new String[] { CALIFORNIA, NEWYORK, NEWJERSY, AUSTIN, BOSTON, BALTIMORE }) {
			MultipleOutputs.addNamedOutput(job, city, TextOutputFormat.class, Text.class, Text.class);
		}
		Path input = new Path("hdfs://192.168.213.133:54310/weatherInputData/input_temp.txt");
		Path output = new Path("hdfs://192.168.213.133:54310/user/hduser1/testfs/output_mapred3");
		FileInputFormat.addInputPath(job, input);
		FileOutputFormat.setOutputPath(job, output);
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}
