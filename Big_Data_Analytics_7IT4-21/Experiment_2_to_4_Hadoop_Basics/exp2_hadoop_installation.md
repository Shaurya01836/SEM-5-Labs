# Experiment–2

# Hadoop Installation on Ubuntu

### Object: Write down the Hadoop installation steps in three modes.

## A. Standalone Mode

### 1. Update Ubuntu

```bash
sudo apt-get update
```

### 2. Install Java

```bash
sudo apt-get install openjdk-8-jdk
```

Check Java:

```bash
java -version
```

### 3. Create Hadoop User

```bash
sudo adduser hadoop_dev
su - hadoop_dev
```

### 4. Download and Extract Hadoop

```bash
wget http://apache.mirrors.lucidnetworks.net/hadoop/common/hadoop-2.7.0/hadoop-2.7.0.tar.gz
tar xvzf hadoop-2.7.0.tar.gz
mv hadoop-2.7.0 hadoop2
```

### 5. Set JAVA_HOME

```bash
vim ~/hadoop2/etc/hadoop/hadoop-env.sh
```

Set:

```bash
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
```

### 6. Verify Hadoop

```bash
cd ~/hadoop2
bin/hadoop
```

This completes Hadoop installation in standalone mode.

### 7. Run Sample Program

```bash
mkdir input
cp etc/hadoop/*.xml input
bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
cat output/*
```

---

# B. Pseudo Distributed Mode

### 1. Configure `core-site.xml`

```bash
vim ~/hadoop2/etc/hadoop/core-site.xml
```

```xml
<configuration>
    <property>
        <name>fs.defaultFS</name>
        <value>hdfs://localhost:9000</value>
    </property>
</configuration>
```

### 2. Configure `hdfs-site.xml`

```bash
vim ~/hadoop2/etc/hadoop/hdfs-site.xml
```

```xml
<configuration>
    <property>
        <name>dfs.replication</name>
        <value>1</value>
    </property>
</configuration>
```

### 3. Setup Passwordless SSH

```bash
sudo apt-get install ssh
ssh-keygen -t dsa -P '' -f ~/.ssh/id_dsa
cat ~/.ssh/id_dsa.pub >> ~/.ssh/authorized_keys
```

### 4. Format NameNode

```bash
bin/hdfs namenode -format
```

### 5. Start HDFS

```bash
sbin/start-dfs.sh
```

Check services:

```bash
jps
```

### 6. Run Hadoop Program

```bash
bin/hdfs dfs -mkdir -p /user/hadoop_dev
bin/hdfs dfs -put etc/hadoop input
bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
bin/hdfs dfs -cat output/*
```

### 7. Stop HDFS

```bash
sbin/stop-dfs.sh
```

---

# C. Pseudo Distributed Mode using YARN

### 1. Configure `mapred-site.xml`

```xml
<configuration>
    <property>
        <name>mapreduce.framework.name</name>
        <value>yarn</value>
    </property>
</configuration>
```

### 2. Configure `yarn-site.xml`

```xml
<configuration>
    <property>
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
</configuration>
```

### 3. Format NameNode

```bash
bin/hdfs namenode -format
```

### 4. Start YARN

```bash
sbin/start-yarn.sh
```

Check services:

```bash
jps
```

Expected services include:

```text
ResourceManager
NodeManager
```

### 5. Run Hadoop Program

```bash
bin/hdfs dfs -mkdir -p /user/hadoop_dev
bin/hdfs dfs -put etc/hadoop input
bin/yarn jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar grep input output 'dfs[a-z.]+'
bin/hdfs dfs -cat output/*
```

### 6. Stop YARN

```bash
sbin/stop-yarn.sh
```


One important point: your original manual has **Hadoop 2.7.0 but later uses a 2.6.0 example JAR**. That should be kept consistent; I used **2.7.0** throughout.
