@echo off
set PIG_HOME=C:\pig-0.17.0
set PATH=%PATH%;%PIG_HOME%\bin
set HADOOP_BIN_PATH=%HADOOP_HOME%\libexec

pig -x local
pig -x mapreduce
