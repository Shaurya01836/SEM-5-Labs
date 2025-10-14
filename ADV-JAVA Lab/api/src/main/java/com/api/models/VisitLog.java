package com.api.models;

import java.sql.Timestamp;

public class VisitLog {

    private int LogId ;
    private String StudentRegNo ;
    private Timestamp inTime ;
    private Timestamp outTime ;
    private String StudentName ;

    public int getLogId() {
        return LogId;
    }

    public void setLogId(int logId) {
        LogId = logId;
    }

    public String getStudentRegNo() {
        return StudentRegNo;
    }

    public void setStudentRegNo(String studentRegNo) {
        StudentRegNo = studentRegNo;
    }

    public Timestamp getInTime() {
        return inTime;
    }

    public void setInTime(Timestamp inTime) {
        this.inTime = inTime;
    }

    public Timestamp getOutTime() {
        return outTime;
    }

    public void setOutTime(Timestamp outTime) {
        this.outTime = outTime;
    }

    public String getStudentName() {
        return StudentName;
    }

    public void setStudentName(String studentName) {
        StudentName = studentName;
    }
}
