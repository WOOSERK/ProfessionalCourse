package kr.co.foreignlove.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.foreignlove.service.LoginService;

@WebServlet("/login")
public class FrontController extends HttpServlet
{
	public void init(ServletConfig config)
	{
	}
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		LoginService loginService = new LoginService();
		
		loginService.doService(request, response);
		
		RequestDispatcher disp = request.getRequestDispatcher((String)request.getAttribute("dest"));
		disp.forward(request, response);
	}
	
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		doGet(request, response);
	}
}