# POORNIMA COLLEGE OF ENGINEERING, JAIPUR
### Department of Information Technology

---

# BIG DATA ANALYTICS LAB MANUAL
**Lab Code:** 7IT4-21  
**Semester:** 8th Semester, 4th Year  
**Academic Year:** 2026-27  


---

# Zero Lecture: Overview of Hadoop

### Topic to be covered: Hadoop Ecosystem & Big Data Overview

#### Overview
Apache Hadoop is an open-source framework designed to make interaction with big data easier. What is big data? It refers to datasets that are too large, fast, or complex to be processed using traditional database systems like RDBMS. Hadoop enables the distributed processing of large data sets across clusters of computers using simple programming models. It is designed to scale up from single servers to thousands of machines, each offering local computation and storage.

#### Hadoop Components
Hadoop Ecosystem provides various services to solve big data problems. The four major elements of Hadoop are:
1. **HDFS (Hadoop Distributed File System):** A distributed file system that provides high-throughput access to application data.
2. **YARN (Yet Another Resource Negotiator):** A framework for job scheduling and cluster resource management.
3. **MapReduce:** A YARN-based system for parallel processing of large data sets.
4. **Hadoop Common:** The common utilities that support the other Hadoop modules.

#### Ecosystem Overview
* **Spark:** In-memory data processing framework.
* **Pig & Hive:** Query and scripting languages for processing data (Pig Latin & HiveQL).
* **HBase:** A scalable, distributed NoSQL database.
* **Mahout & Spark MLlib:** Machine learning libraries.
* **ZooKeeper:** A centralized service for maintaining configuration information and coordinating distributed systems.
* **Oozie:** A workflow scheduler system to manage Apache Hadoop jobs.

---

# Experiment–1

### AIM
Implement the following Data structures in Java:
1. Linked Lists
2. Stacks
3. Queues
4. Set
5. Map

---

## 1. Linked List Implementation

### Program
```java
import java.util.*;

public class GFG {
    public static void main(String args[]) {
        // Creating object of the LinkedList class
        LinkedList<String> ll = new LinkedList<String>();

        // Adding elements to the linked list
        ll.add("A");
        ll.add("B");
        ll.addLast("C");
        ll.addFirst("D");
        ll.add(2, "E");

        System.out.println("Original LinkedList: " + ll);

        // Removing elements
        ll.remove("B"); 
        ll.remove(3); 
        ll.removeFirst(); 
        ll.removeLast();

        System.out.println("After removals: " + ll);
    }
}
```

### Output
```text
Original LinkedList: [D, A, E, B, C]
After removals: [A]
```

---

## 2. Stacks Implementation

### Program
```java
import java.io.*;
import java.util.*;

class Test {
    // Pushing elements on the top of the stack
    static void stack_push(Stack<Integer> stack) {
        System.out.println("Push Operation:");
        for(int i = 0; i < 5; i++) {
            stack.push(i);
            System.out.println(i);
        }
    }

    // Popping elements from the top of the stack
    static void stack_pop(Stack<Integer> stack) {
        System.out.println("Pop Operation:");
        for(int i = 0; i < 5; i++) {
            Integer y = stack.pop();
            System.out.println(y);
        }
    }

    // Displaying element on the top of the stack
    static void stack_peek(Stack<Integer> stack) {
        Integer element = stack.peek();
        System.out.println("Element on stack top: " + element);
    }

    // Searching element in the stack
    static void stack_search(Stack<Integer> stack, int element) {
        Integer pos = stack.search(element);
        if(pos == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element is found at position: " + pos);
        }
    }

    public static void main (String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        stack_push(stack);
        stack_pop(stack);
        stack_push(stack);
        stack_peek(stack);
        stack_search(stack, 2);
        stack_search(stack, 6);
    }
}
```

### Output
```text
Push Operation:
0
1
2
3
4
Pop Operation:
4
3
2
1
0
Element on stack top: 4
Element is found at position: 3
Element not found
```

---

## 3. Queue Implementation

### Program
```java
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();

        // Adds elements {0, 1, 2, 3, 4} to the queue
        for (int i = 0; i < 5; i++) {
            q.add(i);
        }

        // Display contents of the queue
        System.out.println("Elements of queue: " + q);

        // To remove the head of queue
        int removedele = q.remove();
        System.out.println("Removed element: " + removedele);
        System.out.println("Queue after removal: " + q);

        // To view the head of queue
        int head = q.peek();
        System.out.println("Head of queue: " + head);

        // Rest of the methods like size
        int size = q.size();
        System.out.println("Size of queue: " + size);
    }
}
```

### Output
```text
Elements of queue: [0, 1, 2, 3, 4]
Removed element: 0
Queue after removal: [1, 2, 3, 4]
Head of queue: 1
Size of queue: 4
```

---

## 4. Set Implementation

### Program
```java
import java.util.*;

public class GFG {
    public static void main(String[] args) {
        // Demonstrating Set using HashSet
        Set<String> hash_Set = new HashSet<String>();

        // Adding elements to the Set
        hash_Set.add("Geeks");
        hash_Set.add("For");
        hash_Set.add("Geeks");
        hash_Set.add("Example");
        hash_Set.add("Set");

        // Printing elements of HashSet object
        System.out.println(hash_Set);
    }
}
```

### Output
```text
[Set, Example, Geeks, For]
```

---

## 5. Map Implementation

### Program
```java
import java.util.*;

class GFG {
    public static void main(String args[]) {
        // Creating an empty HashMap
        Map<String, Integer> hm = new HashMap<String, Integer>();

        // Inserting pairs in Map
        hm.put("a", 100);
        hm.put("b", 200);
        hm.put("c", 300);
        hm.put("d", 400);

        // Traversing through Map using for-each loop
        for (Map.Entry<String, Integer> me : hm.entrySet()) {
            // Printing keys and values
            System.out.print(me.getKey() + ":");
            System.out.println(me.getValue());
        }
    }
}
```

### Output
```text
a:100
b:200
c:300
d:400
```

---

# Experiment–2

### AIM
Write down the Hadoop installation steps in three modes: Standalone, Pseudo-distributed, and Fully distributed.

---

## 1. Hadoop Installation: Standalone Mode (Ubuntu)

### Steps for Installation
1. **Update system packages:**
   ```bash
   sudo apt-get update
   ```
2. **Install Java JDK (JDK 1.8):**
   ```bash
   sudo apt-get install python-software-properties
   sudo add-apt-repository ppa:webupd8team/java
   sudo apt-get update
   sudo apt-get install oracle-java8-installer
   ```
3. **Setup dedicated Hadoop user (Recommended):**
   ```bash
   sudo adduser hadoop_dev
   # Switch to the new user:
   su - hadoop_dev
   ```
4. **Download Apache Hadoop distribution:**
   ```bash
   wget http://apache.mirrors.lucidnetworks.net/hadoop/common/hadoop-2.7.0/hadoop-2.7.0.tar.gz
   ```
5. **Extract and rename folder:**
   ```bash
   tar -xvzf hadoop-2.7.0.tar.gz
   mv hadoop-2.7.0 hadoop2
   ```
6. **Configure environment (`hadoop-env.sh`):**
   ```bash
   vim /home/hadoop_dev/hadoop2/etc/hadoop/hadoop-env.sh
   ```
   Uncomment and update the `JAVA_HOME` configuration line:
   ```bash
   export JAVA_HOME=/usr/lib/jvm/java-8-oracle
   ```
7. **Verify installation:**
   ```bash
   cd /home/hadoop_dev/hadoop2/
   bin/hadoop
   ```
   *Running this command should prompt you with the available options for the hadoop utility.*

8. **Run a Sample standalone MapReduce grep example:**
   ```bash
   mkdir input
   cp etc/hadoop/*.xml input
   bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
   cat output/*
   ```

---

## 2. Hadoop Installation: Pseudo-Distributed Mode (Local HDFS)

### Configuration Changes
1. **Edit `core-site.xml` (`/home/hadoop_dev/hadoop2/etc/hadoop/core-site.xml`):**
   ```xml
   <configuration>
       <property>
           <name>fs.defaultFS</name>
           <value>hdfs://localhost:9000</value>
       </property>
   </configuration>
   ```
2. **Edit `hdfs-site.xml` (`/home/hadoop_dev/hadoop2/etc/hadoop/hdfs-site.xml`):**
   ```xml
   <configuration>
       <property>
           <name>dfs.replication</name>
           <value>1</value>
       </property>
   </configuration>
   ```

3. **Configure Password-less SSH Login:**
   ```bash
   ssh localhost
   # If ssh-server is not installed, install it:
   sudo apt-get install ssh
   
   # Generate SSH keys and authorize them:
   ssh-keygen -t dsa -P '' -f ~/.ssh/id_dsa
   cat ~/.ssh/id_dsa.pub >> ~/.ssh/authorized_keys
   ```

4. **Format HDFS NameNode:**
   ```bash
   bin/hdfs namenode -format
   ```

5. **Start HDFS Daemons:**
   ```bash
   sbin/start-dfs.sh
   ```
   Verify NameNode status on web browser: [http://localhost:50070](http://localhost:50070)

6. **Run MapReduce grep Job on HDFS:**
   ```bash
   # Create user directory in HDFS
   bin/hdfs dfs -mkdir -p /user/hadoop_dev
   
   # Copy input configuration files to HDFS
   bin/hdfs dfs -put etc/hadoop input
   
   # Run grep job
   bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
   
   # Read output from HDFS
   bin/hdfs dfs -cat output/*
   
   # Stop HDFS daemons
   sbin/stop-dfs.sh
   ```

---

## 3. Hadoop Installation: Pseudo-Distributed Mode with YARN

### Configuration Changes
1. **Edit `mapred-site.xml`:**
   ```xml
   <configuration>
       <property>
           <name>mapreduce.framework.name</name>
           <value>yarn</value>
       </property>
   </configuration>
   ```
2. **Edit `yarn-site.xml`:**
   ```xml
   <configuration>
       <property>
           <name>yarn.nodemanager.aux-services</name>
           <value>mapreduce_shuffle</value>
       </property>
   </configuration>
   ```

### Execution Steps
1. **Start YARN Daemons:**
   ```bash
   sbin/start-yarn.sh
   ```
   Verify ResourceManager status on browser: [http://localhost:8088](http://localhost:8088)

2. **Verify active daemons with `jps`:**
   ```bash
   jps
   ```
   Expected output:
   ```text
   15567 ResourceManager
   15785 NodeManager
   15933 Jps
   ```

3. **Run WordCount/Grep MapReduce Job on YARN:**
   ```bash
   bin/yarn jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
   bin/hdfs dfs -cat output/*
   ```

4. **Stop YARN Daemons:**
   ```bash
   sbin/stop-yarn.sh
   ```

---

# Experiment–3

### AIM
Write the steps to run a basic word-count Map-reduce Program on Hadoop.

---

## MapReduce WordCount Source Code

```java
import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.fs.Path;

public class WordCount {

    // Mapper Class
    public static class Map extends Mapper<LongWritable, Text, Text, IntWritable> {
        private final static IntWritable one = new IntWritable(1);
        private Text word = new Text();

        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            String line = value.toString();
            StringTokenizer tokenizer = new StringTokenizer(line);
            while (tokenizer.hasMoreTokens()) {
                word.set(tokenizer.nextToken());
                context.write(word, one);
            }
        }
    }

    // Reducer Class
    public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable> {
        public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
            int sum = 0;
            for(IntWritable x : values) {
                sum += x.get();
            }
            context.write(key, new IntWritable(sum));
        }
    }

    // Driver Entry Point
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "My Word Count Program");
        
        job.setJarByClass(WordCount.class);
        job.setMapperClass(Map.class);
        job.setReducerClass(Reduce.class);
        
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);
        
        job.setInputFormatClass(TextInputFormat.class);
        job.setOutputFormatClass(TextOutputFormat.class);
        
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        
        Path outputPath = new Path(args[1]);
        // Automatically delete the output directory if it already exists
        outputPath.getFileSystem(conf).delete(outputPath, true);
        
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
```

---

## Program Components Explained

### 1. Mapper Phase Code
The `Map` class extends Hadoop's `Mapper` class:
* **Inputs:** `LongWritable` (byte offset of the line) and `Text` (line content).
* **Outputs:** `Text` (the extracted word/token) and `IntWritable` (constant value of `1`).
* **Logic:** The `map()` method parses each line into words using `StringTokenizer` and writes `(word, 1)` key-value pairs to the Context.

### 2. Reducer Phase Code
The `Reduce` class extends Hadoop's `Reducer` class:
* **Inputs:** `Text` (the unique word) and `Iterable<IntWritable>` (list of values, i.e., `[1, 1, 1...]` representing occurrences).
* **Outputs:** `Text` (the word) and `IntWritable` (total sum).
* **Logic:** The `reduce()` method sums all values in the iterator for each key and writes `(word, sum)` to output.

### 3. Driver Code
The `main()` method configures the overall execution job:
* Allocates a new `Job` instance.
* Sets classes for Mapper, Reducer, outputs, input format, and output format.
* Extracts command-line arguments for HDFS input and output paths.
* Executes the job synchronously using `job.waitForCompletion(true)`.

---

## Running the WordCount Program
```bash
# Package code as jar and execute it on Hadoop
hadoop jar WordCount.jar WordCount /hdfs/input/path /hdfs/output/path
```

---

# Experiment–4

### AIM
Write the steps for file management in Hadoop (HDFS commands).

---

## HDFS CLI File Management Tools

### 1. Create a Directory
Creates directories on HDFS at given path(s).
* **Usage:** `hadoop fs -mkdir <paths>`
* **Example:**
  ```bash
  hadoop fs -mkdir /user/saurzcode/dir1 /user/saurzcode/dir2
  ```

### 2. List Directory Contents
Lists the files and subdirectories.
* **Usage:** `hadoop fs -ls <args>`
* **Example:**
  ```bash
  hadoop fs -ls /user/saurzcode
  ```

### 3. Upload File to HDFS
Copies files from the local file system to HDFS.
* **Usage:** `hadoop fs -put <localsrc> ... <HDFS_dest_Path>`
* **Example:**
  ```bash
  hadoop fs -put /home/saurzcode/Samplefile.txt /user/saurzcode/dir3/
  ```

### 4. Download File from HDFS
Copies/Downloads files from HDFS to the local file system.
* **Usage:** `hadoop fs -get <hdfs_src> <localdst>`
* **Example:**
  ```bash
  hadoop fs -get /user/saurzcode/dir3/Samplefile.txt /home/downloads/
  ```

### 5. View File Contents
Prints file contents to console.
* **Usage:** `hadoop fs -cat <path>`
* **Example:**
  ```bash
  hadoop fs -cat /user/saurzcode/dir1/abc.txt
  ```

### 6. Copy HDFS Files
Copies a file within HDFS from source to destination.
* **Usage:** `hadoop fs -cp <source> <dest>`
* **Example:**
  ```bash
  hadoop fs -cp /user/saurzcode/dir1/abc.txt /user/saurzcode/dir2
  ```

### 7. Copy From Local Direct Command
Restricted to local files as source.
* **Usage:** `hadoop fs -copyFromLocal <localsrc> <hdfs_dest_uri>`
* **Example:**
  ```bash
  hadoop fs -copyFromLocal /home/saurzcode/abc.txt /user/saurzcode/abc.txt
  ```

### 8. Copy To Local Direct Command
Restricted to local folders as destination.
* **Usage:** `hadoop fs -copyToLocal <hdfs_src_uri> <localdst>`
* **Example:**
  ```bash
  hadoop fs -copyToLocal /user/saurzcode/abc.txt /home/saurzcode/abc.txt
  ```

### 9. Move File within HDFS
Moves files within HDFS.
* **Usage:** `hadoop fs -mv <src> <dest>`
* **Example:**
  ```bash
  hadoop fs -mv /user/saurzcode/dir1/abc.txt /user/saurzcode/dir2
  ```

### 10. Remove File or Directory
Deletes files, or deletes directory only if it is empty.
* **Usage:** `hadoop fs -rm <arg>`
* **Example:**
  ```bash
  hadoop fs -rm /user/saurzcode/dir1/abc.txt
  ```

### 11. Recursive Remove
Deletes folders and all child elements recursively.
* **Usage:** `hadoop fs -rmr <arg>`
* **Example:**
  ```bash
  hadoop fs -rmr /user/saurzcode/
  ```

### 12. Display Last Lines (Tail)
* **Usage:** `hadoop fs -tail <path>`
* **Example:**
  ```bash
  hadoop fs -tail /user/saurzcode/dir1/abc.txt
  ```

### 13. Check Space Usage (Du)
* **Usage:** `hadoop fs -du <path>`
* **Example:**
  ```bash
  hadoop fs -du /user/saurzcode/dir1/abc.txt
  ```

---

# Experiment–5

### AIM
Write a Map Reduce program that mines weather data. Weather sensors collecting data every hour at many locations across the globe gather a large volume of log data, which is a good candidate for analysis with Map Reduce, since it is semi-structured and record-oriented.

---

## Problem Description
The system receives temperature updates from various US cities (Austin, Boston, New York, Baltimore, California, etc.) captured at regular intervals. The program processes this semi-structured data to find the daily maximum and minimum temperatures for each city and writes separate reports dynamically using `MultipleOutputs`.

### Input Record Schema
```text
CA_25-Jan-2014   00:12:345   15.7   01:19:345   23.1   02:34:542   12.3 ...
```
Here, `CA` stands for California, followed by a date, and then a sequence of tab-separated `time` and `temperature` values.

---

## Weather Data MapReduce Implementation

```java
import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.output.MultipleOutputs;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class CalculateMaxAndMinTemperatureWithTime {
    public static String calOutputName = "California";
    public static String nyOutputName = "Newyork";
    public static String njOutputName = "Newjersy";
    public static String ausOutputName = "Austin";
    public static String bosOutputName = "Boston";
    public static String balOutputName = "Baltimore";

    // Mapper Class
    public static class WeatherForecastMapper extends Mapper<Object, Text, Text, Text> {
        public void map(Object keyOffset, Text dayReport, Context con) throws IOException, InterruptedException {
            StringTokenizer strTokens = new StringTokenizer(dayReport.toString(), "	");
            int counter = 0;
            Float currentTemp = null;
            Float minTemp = Float.MAX_VALUE;
            Float maxTemp = Float.MIN_VALUE;
            String date = null;
            String currentTime = null;
            String minTempANDTime = null;
            String maxTempANDTime = null;

            while (strTokens.hasMoreElements()) {
                if (counter == 0) {
                    date = strTokens.nextToken();
                } else {
                    if (counter % 2 == 1) {
                        currentTime = strTokens.nextToken();
                    } else {
                        currentTemp = Float.parseFloat(strTokens.nextToken());
                        if (minTemp > currentTemp) {
                            minTemp = currentTemp;
                            minTempANDTime = minTemp + "AND" + currentTime;
                        }
                        if (maxTemp < currentTemp) {
                            maxTemp = currentTemp;
                            maxTempANDTime = maxTemp + "AND" + currentTime;
                        }
                    }
                }
                counter++;
            }

            // Emit Max Temp
            Text temp = new Text();
            temp.set(maxTempANDTime);
            Text dateText = new Text();
            dateText.set(date);
            con.write(dateText, temp);

            // Emit Min Temp
            temp.set(minTempANDTime);
            con.write(dateText, temp);
        }
    }

    // Reducer Class
    public static class WeatherForecastReducer extends Reducer<Text, Text, Text, Text> {
        private MultipleOutputs<Text, Text> mos;

        @Override
        public void setup(Context context) {
            mos = new MultipleOutputs<Text, Text>(context);
        }

        public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            int counter = 0;
            String reducerInputStr[] = null;
            String f1Time = "";
            String f2Time = "";
            String f1 = "", f2 = "";
            Text result = new Text();

            for (Text value : values) {
                if (counter == 0) {
                    reducerInputStr = value.toString().split("AND");
                    f1 = reducerInputStr[0];
                    f1Time = reducerInputStr[1];
                } else {
                    reducerInputStr = value.toString().split("AND");
                    f2 = reducerInputStr[0];
                    f2Time = reducerInputStr[1];
                }
                counter++;
            }

            if (Float.parseFloat(f1) > Float.parseFloat(f2)) {
                result = new Text("Time: " + f2Time + " MinTemp: " + f2 + "	Time: " + f1Time + " MaxTemp: " + f1);
            } else {
                result = new Text("Time: " + f1Time + " MinTemp: " + f1 + "	Time: " + f2Time + " MaxTemp: " + f2);
            }

            String fileName = "";
            String keyStr = key.toString();
            if (keyStr.startsWith("CA")) {
                fileName = calOutputName;
            } else if (keyStr.startsWith("NY")) {
                fileName = nyOutputName;
            } else if (keyStr.startsWith("NJ")) {
                fileName = njOutputName;
            } else if (keyStr.startsWith("AUS")) {
                fileName = ausOutputName;
            } else if (keyStr.startsWith("BOS")) {
                fileName = bosOutputName;
            } else if (keyStr.startsWith("BAL")) {
                fileName = balOutputName;
            }

            String strArr[] = keyStr.split("_");
            key.set(strArr[1]); // Set actual date value as key
            mos.write(fileName, key, result);
        }

        @Override
        public void cleanup(Context context) throws IOException, InterruptedException {
            mos.close();
        }
    }

    // Driver Method
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "Weather Statistics of USA");
        
        job.setJarByClass(CalculateMaxAndMinTemperatureWithTime.class);
        job.setMapperClass(WeatherForecastMapper.class);
        job.setReducerClass(WeatherForecastReducer.class);
        
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(Text.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        // Register multiple outputs
        MultipleOutputs.addNamedOutput(job, calOutputName, TextOutputFormat.class, Text.class, Text.class);
        MultipleOutputs.addNamedOutput(job, nyOutputName, TextOutputFormat.class, Text.class, Text.class);
        MultipleOutputs.addNamedOutput(job, njOutputName, TextOutputFormat.class, Text.class, Text.class);
        MultipleOutputs.addNamedOutput(job, bosOutputName, TextOutputFormat.class, Text.class, Text.class);
        MultipleOutputs.addNamedOutput(job, ausOutputName, TextOutputFormat.class, Text.class, Text.class);
        MultipleOutputs.addNamedOutput(job, balOutputName, TextOutputFormat.class, Text.class, Text.class);

        Path pathInput = new Path("hdfs://192.168.213.133:54310/weatherInputData/input_temp.txt");
        Path pathOutputDir = new Path("hdfs://192.168.213.133:54310/user/hduser1/testfs/output_mapred3");
        
        FileInputFormat.addInputPath(job, pathInput);
        FileOutputFormat.setOutputPath(job, pathOutputDir);

        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
```

---

# Experiment-6

### AIM
Implement Matrix Multiplication with Hadoop Map Reduce.

---

## 1. Mapper Class (Map.java)
```java
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import java.io.IOException;

public class Map extends Mapper<LongWritable, Text, Text, Text> {
    @Override
    public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        Configuration conf = context.getConfiguration();
        int m = Integer.parseInt(conf.get("m"));
        int p = Integer.parseInt(conf.get("p"));
        String line = value.toString();
        String[] indicesAndValue = line.split(",");
        Text outputKey = new Text();
        Text outputValue = new Text();

        if (indicesAndValue[0].equals("M")) {
            for (int k = 0; k < p; k++) {
                outputKey.set(indicesAndValue[1] + "," + k); // key = (i, k)
                outputValue.set("M," + indicesAndValue[2] + "," + indicesAndValue[3]); // value = (M, j, Mij)
                context.write(outputKey, outputValue);
            }
        } else { // Matrix N
            for (int i = 0; i < m; i++) {
                outputKey.set(i + "," + indicesAndValue[2]); // key = (i, k)
                outputValue.set("N," + indicesAndValue[1] + "," + indicesAndValue[3]); // value = (N, j, Njk)
                context.write(outputKey, outputValue);
            }
        }
    }
}
```

---

## 2. Reducer Class (Reduce.java)
```java
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;
import java.io.IOException;
import java.util.HashMap;

public class Reduce extends Reducer<Text, Text, Text, Text> {
    @Override
    public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
        String[] value;
        HashMap<Integer, Float> hashA = new HashMap<Integer, Float>();
        HashMap<Integer, Float> hashB = new HashMap<Integer, Float>();
        
        for (Text val : values) {
            value = val.toString().split(",");
            if (value[0].equals("M")) {
                hashA.put(Integer.parseInt(value[1]), Float.parseFloat(value[2]));
            } else {
                hashB.put(Integer.parseInt(value[1]), Float.parseFloat(value[2]));
            }
        }
        
        int n = Integer.parseInt(context.getConfiguration().get("n"));
        float result = 0.0f;
        float m_ij;
        float n_jk;
        
        for (int j = 0; j < n; j++) {
            m_ij = hashA.containsKey(j) ? hashA.get(j) : 0.0f;
            n_jk = hashB.containsKey(j) ? hashB.get(j) : 0.0f;
            result += m_ij * n_jk;
        }
        
        if (result != 0.0f) {
            context.write(null, new Text(key.toString() + "," + Float.toString(result)));
        }
    }
}
```

---

## 3. Driver Program (MatrixMultiply.java)
```java
import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
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
        
        Configuration conf = new Configuration();
        // M is an m-by-n matrix; N is an n-by-p matrix.
        conf.set("m", "1000");
        conf.set("n", "100");
        conf.set("p", "1000");
        
        Job job = Job.getInstance(conf, "MatrixMultiply");
        job.setJarByClass(MatrixMultiply.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);
        
        job.setMapperClass(Map.class);
        job.setReducerClass(Reduce.class);
        
        job.setInputFormatClass(TextInputFormat.class);
        job.setOutputFormatClass(TextOutputFormat.class);
        
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
```

---

## 4. Packing and Execution Commands
```bash
# 1. Create a JAR file containing the compiled classes
jar -cvf MatrixMultiply.jar Map.class Reduce.class MatrixMultiply.class

# 2. Setup directories and upload input matrices M and N to HDFS
hadoop fs -mkdir Matrix/
hadoop fs -copyFromLocal M Matrix/
hadoop fs -copyFromLocal N Matrix/

# 3. Execute the MapReduce JAR
hadoop jar MatrixMultiply.jar MatrixMultiply Matrix/* result/
```

---

# Experiment-7

### AIM
Install and Run Pig then write Pig Latin scripts to sort, group, join, project, and filter your data.

---

## 1. Apache Pig Overview
Apache Pig is a high-level data manipulation platform built on top of Hadoop's MapReduce framework. It uses a textual scripting language called **Pig Latin** to express data analysis programs. Pig programs are automatically compiled into sequences of MapReduce jobs by the compiler.

### Modes of Execution
* **Interactive Mode (Grunt Shell):** Executes commands interactively line-by-line.
* **Batch Mode (Pig Scripts):** Executes compiled pig scripts saved with `.pig` extension.
* **Embedded Mode (User-Defined Functions):** Leverages custom modules written in Java, Python, etc.

---

## 2. Pig Installation Steps on Windows

### Step 1: Download & Extract
1. Download Pig distribution (e.g., version `0.17.0`) from the official website: [https://downloads.apache.org/pig/](https://downloads.apache.org/pig/)
2. Extract the `.tar.gz` archive to a folder using 7-Zip (e.g., `C:\pig-0.17.0`).

### Step 2: Configure Environment Variables
1. Open the System Environment Variables window.
2. Add new user variable:
   * **Variable Name:** `PIG_HOME`
   * **Variable Value:** `C:\pig-0.17.0`
3. Edit the system `Path` variable and append:
   * `%PIG_HOME%\bin`

### Step 3: Modify configuration script
Open `C:\pig-0.17.0\bin\pig.cmd` in a text editor:
* Find the line:
  ```cmd
  set HADOOP_BIN_PATH=%HADOOP_HOME%\bin
  ```
* Replace it with:
  ```cmd
  set HADOOP_BIN_PATH=%HADOOP_HOME%\libexec
  ```

---

## 3. Invoking the Grunt Shell
* **Local Mode:** Processes files on local storage without HDFS.
  ```bash
  pig -x local
  ```
* **MapReduce/HDFS Mode:** Processes files stored in HDFS.
  ```bash
  pig -x mapreduce
  ```

---

# Experiment-8

### AIM
Install and Run Hive then use Hive to create, alter, and drop databases, tables, views, functions, and indexes.

---

## 1. Hive Overview
Apache Hive is a data warehouse software project built on top of Apache Hadoop for providing data query and analysis. Hive gives an SQL-like interface to query data stored in HDFS, called **HiveQL**.

---

## 2. Installation & Setup Steps (Windows)

### Prerequisites
* Download Hive: [Hive Archive](https://archive.apache.org/dist/hive/hive-2.1.0/) (Download version `2.1.0`).
* Download Apache Derby (for Metastore DB): [Derby Archive](https://archive.apache.org/dist/db/derby/db-derby-10.12.1.1/) (Download version `10.12.1.1`).
* Download a sample configuration file `hive-site.xml`.

### Setup Steps
1. **Extract Archives:**
   * Extract Hive to `D:\Hive\apache-hive-2.1.0-bin`
   * Extract Derby to `D:\Derby\db-derby-10.12.1.1-bin`
2. **Move Configurations:** Place the downloaded `hive-site.xml` file into the Hive conf folder: `D:\Hive\apache-hive-2.1.0-bin\conf`
3. **Link Derby Libraries:** Copy all jar files inside `D:\Derby\db-derby-10.12.1.1-bin\lib` and paste them into `D:\Hive\apache-hive-2.1.0-bin\lib`.

4. **Configure Environment Variables:** Add the following User Variables:
   * `HIVE_HOME` = `D:\Hive\apache-hive-2.1.0-bin`
   * `DERBY_HOME` = `D:\Derby\db-derby-10.12.1.1-bin`
   * `HADOOP_USER_CLASSPATH_FIRST` = `true`
5. **Update Path Variable:** Append the following paths to the System `Path` variable:
   * `%HIVE_HOME%\bin`
   * `%DERBY_HOME%\bin`

---

## 3. Hive Configuration (`hive-site.xml`)
Edit the database connection properties in `hive-site.xml` to point to the Derby metastore database instance.
```xml
<configuration>
    <property>
        <name>javax.jdo.option.ConnectionURL</name>
        <value>jdbc:derby:;databaseName=metastore_db;create=true</value>
        <description>JDBC connect string for a JDBC metastore</description>
    </property>
    <property>
        <name>javax.jdo.option.ConnectionDriverName</name>
        <value>org.apache.derby.jdbc.EmbeddedDriver</value>
        <description>Driver class name for a JDBC metastore</description>
    </property>
</configuration>
```

---

# Experiment-9

### AIM
Solve some real-life big data problems using HDFS shell utilities (e.g. merge tools).

---

## Hadoop `-getmerge` Utility
The Hadoop `-getmerge` command reads files from HDFS directory, concatenates/merges them, and downloads the unified file directly into the local file system.

### Steps to Use `-getmerge`

1. **Verify files in HDFS:**
   ```bash
   hdfs dfs -mkdir /Hadoop_File
   
   # Copy sample files to HDFS
   hdfs dfs -copyFromLocal /home/dikshant/Documents/hadoop_file/file1.txt /Hadoop_File
   hdfs dfs -copyFromLocal /home/dikshant/Documents/hadoop_file/file2.txt /Hadoop_File
   
   # View files in directory
   hdfs dfs -ls /Hadoop_File
   ```

2. **Execute GetMerge command:**
   ```bash
   # Syntax:
   hdfs dfs -getmerge -nl <hdfs_src_folder_or_files> <local_dest_file>
   
   # Execution:
   hdfs dfs -getmerge -nl /Hadoop_File/file1.txt /Hadoop_File/file2.txt /home/dikshant/Documents/hadoop_file/output.txt
   ```
   *The `-nl` flag adds a newline character at the end of each merged file boundary.*

---

# Beyond Syllabus Experiment-1

### AIM
Write a MapReduce Program to find the average age of male and female victims who died in the Titanic disaster.

---

## Titanic Analyzer Code (`Average_age.java`)

```java
import java.io.IOException;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class Average_age {

    // Mapper Class
    public static class Map extends Mapper<LongWritable, Text, Text, IntWritable> {
        private Text gender = new Text();
        private IntWritable age = new IntWritable();

        @Override
        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            String line = value.toString();
            // Titanic CSV line splitting
            String[] str = line.split(", ");
            
            if (str.length > 6) {
                gender.set(str[4]); // 5th Column contains gender
                
                // Column 2 indicates survival: "0" = Died, "1" = Survived
                if (str[1].equals("0")) {
                    if (str[5].matches("\\d+")) { // Age is numeric check
                        int parsedAge = Integer.parseInt(str[5]);
                        age.set(parsedAge);
                        context.write(gender, age);
                    }
                }
            }
        }
    }

    // Reducer Class
    public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable> {
        @Override
        public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
            int sum = 0;
            int count = 0;
            
            for (IntWritable val : values) {
                count++;
                sum += val.get();
            }
            
            if (count > 0) {
                int average = sum / count;
                context.write(key, new IntWritable(average));
            }
        }
    }

    // Driver Main
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "Titanic Average Age of Deceased");
        
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
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        
        Path out = new Path(args[1]);
        out.getFileSystem(conf).delete(out, true);
        
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
```

---

# Beyond Syllabus Experiment-2

### AIM
Write a MapReduce Program to find the top 10 movies by view count (Note: titled as "XGBoost for regression" in course files, but contains top 10 viewed movies MapReduce Mapper code).

---

## Movie Views Top 10 Mapper (`top_10_Movies_Mapper.java`)

```java
import java.io.*;
import java.util.*;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class top_10_Movies_Mapper extends Mapper<Object, Text, Text, LongWritable> {
    private TreeMap<Long, String> tmap;

    @Override
    public void setup(Context context) throws IOException, InterruptedException {
        tmap = new TreeMap<Long, String>();
    }

    @Override
    public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
        // Input format: movie_name 	 no_of_views
        String[] tokens = value.toString().split("\	");
        if (tokens.length >= 2) {
            String movie_name = tokens[0];
            long no_of_views = Long.parseLong(tokens[1]);
            
            tmap.put(no_of_views, movie_name);
            
            // Keep only top 10 elements in tree map
            if (tmap.size() > 10) {
                tmap.remove(tmap.firstKey());
            }
        }
    }

    @Override
    public void cleanup(Context context) throws IOException, InterruptedException {
        for (Map.Entry<Long, String> entry : tmap.entrySet()) {
            long count = entry.getKey();
            String name = entry.getValue();
            context.write(new Text(name), new LongWritable(count));
        }
    }
}
```
