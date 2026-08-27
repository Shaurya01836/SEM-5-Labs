package Beyond_Syllabus;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class Average_age {
	public static class Map extends Mapper<LongWritable, Text, Text, IntWritable> {
		private final Text gender = new Text();
		private final IntWritable age = new IntWritable();

		@Override
		public void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException {
			String[] columns = value.toString().split(",");
			if (columns.length > 6 && columns[1].equals("0") && columns[5].matches("\\d+")) {
				gender.set(columns[4]);
				age.set(Integer.parseInt(columns[5]));
				context.write(gender, age);
			}
		}
	}

	public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable> {
		@Override
		public void reduce(Text key, Iterable<IntWritable> values, Context context)
				throws IOException, InterruptedException {
			int total = 0;
			int count = 0;
			for (IntWritable value : values) {
				total += value.get();
				count++;
			}
			if (count > 0) {
				context.write(key, new IntWritable(total / count));
			}
		}
	}

	public static void main(String[] args) throws Exception {
		if (args.length != 2) {
			System.err.println("Usage: Average_age <input> <output>");
			System.exit(2);
		}
		Configuration configuration = new Configuration();
		Job job = Job.getInstance(configuration, "Average age survived");
		job.setJarByClass(Average_age.class);
		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(IntWritable.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		Path output = new Path(args[1]);
		FileOutputFormat.setOutputPath(job, output);
		output.getFileSystem(configuration).delete(output, true);
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}
