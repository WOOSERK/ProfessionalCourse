package kr.co.wooserk.controller;

import java.io.IOException;
import java.util.HashMap;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.service.BoardService;
import kr.co.wooserk.service.Service;

@WebServlet(name="frontController",
			urlPatterns = "/board")
public class FrontController extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	HashMap<String, Service> services = new HashMap<>();
	
	public void init(ServletConfig config) throws ServletException
	{
		String contextPath = config.getServletContext().getContextPath();
		services.put(contextPath + "/board", new BoardService());
	}
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String uri = request.getRequestURI();
		try
		{
			String nextURI = services.get(uri).doService(request, response);			
			response.sendRedirect(nextURI);
		}
		catch(NullPointerException e)
		{
			e.printStackTrace();
		}
	}
	
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		doGet(request, response);
	}
}
