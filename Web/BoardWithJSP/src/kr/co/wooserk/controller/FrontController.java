package kr.co.wooserk.controller;

import java.io.IOException;
import java.util.HashMap;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.service.BackService;
import kr.co.wooserk.service.BoardService;

@WebServlet
(
		name = "frontController",
		urlPatterns = "/board",
		initParams = 
		{
			@WebInitParam(name="/BoardProjectWithJSP/board",
				value="kr.co.wooserk.service.BoardService")
		}
)

public class FrontController extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	private HashMap<String, BackService> services;
	
	public void init(ServletConfig config)
	{
		services = new HashMap<>();
		
		services.put("/BoardProjectWithJSP/board", new BoardService());
		
		
		/*
		 * Enumeration<String> names = config.getInitParameterNames();
		 * 
		 * while(names.hasMoreElements()) { String name = names.nextElement();
		 * 
		 * try { Class cls = Class.forName(config.getInitParameter(name));
		 * services.put(name, (BackService)(cls.newInstance())); } catch(Exception e) {
		 * e.printStackTrace(); } }
		 */
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String uri = request.getRequestURI();
		
		if(services.containsKey(uri))
		{
			services.get(uri).doService(request, response);
			
			//response.sendRedirect((String)request.getAttribute("dest"));
			
			RequestDispatcher disp = request.getRequestDispatcher((String)request.getAttribute("dest"));
			disp.forward(request, response);
		}
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("UTF-8");
		doGet(request, response);
	}
}
	