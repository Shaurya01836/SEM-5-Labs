package Beyond_Syllabus;

import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class top_10_Movies_Mapper extends Mapper<Object, Text, Text, LongWritable> {
	private TreeMap<Long, String> topMovies;

	@Override
	public void setup(Context context) {
		topMovies = new TreeMap<>();
	}

	@Override
	public void map(Object key, Text value, Context context)
			throws IOException, InterruptedException {
		String[] tokens = value.toString().split("\t", 2);
		if (tokens.length != 2) {
			return;
		}
		topMovies.put(Long.parseLong(tokens[1]), tokens[0]);
		if (topMovies.size() > 10) {
			topMovies.remove(topMovies.firstKey());
		}
	}

	@Override
	public void cleanup(Context context) throws IOException, InterruptedException {
		for (Map.Entry<Long, String> entry : topMovies.entrySet()) {
			context.write(new Text(entry.getValue()), new LongWritable(entry.getKey()));
		}
	}
}
