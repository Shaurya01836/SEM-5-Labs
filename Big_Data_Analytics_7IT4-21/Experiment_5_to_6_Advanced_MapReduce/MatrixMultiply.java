package Experiment_5_to_6_Advanced_MapReduce;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class MatrixMultiply {
	public static void main(String[] args) throws Exception {
		if (args.length != 2) {
			System.err.println("Usage: MatrixMultiply <in_dir> <out_dir>");
			System.exit(2);
		}

		Configuration configuration = new Configuration();
		configuration.set("m", "1000");
		configuration.set("n", "100");
		configuration.set("p", "1000");

		Job job = Job.getInstance(configuration, "MatrixMultiply");
		job.setJarByClass(MatrixMultiply.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		job.setMapperClass(Map_Matrix.class);
		job.setReducerClass(Reduce_Matrix.class);
		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}
