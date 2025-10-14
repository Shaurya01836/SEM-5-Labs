package com.api.servlets.student;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("log/check-in")
public class CheckInServlet extends HttpServlet {

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException , IOException {


        String sql = "INSERT INTO visit_log (student_reg_no, in_time, out_time) VALUES (?, NOW(), NULL)";

    }
}
