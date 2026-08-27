hadoop fs -mkdir /Hadoop_File
hadoop fs -copyFromLocal file1.txt /Hadoop_File/
hadoop fs -copyFromLocal file2.txt /Hadoop_File/
hdfs dfs -getmerge -nl /Hadoop_File/file1.txt /Hadoop_File/file2.txt /home/dikshant/Documents/hadoop_file/output.txt
