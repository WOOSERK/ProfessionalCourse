package mvc2.controller;

import java.io.IOException;
import java.util.Enumeration;
import java.util.HashMap;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class FrontController extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	HashMap<String, BackController> services;
	
	@SuppressWarnings("rawtypes")
	public void init(ServletConfig config) throws ServletException
	{
		services = new HashMap<>();
		
		Enumeration<String> params = config.getInitParameterNames();
		ServletContext sc = config.getServletContext();
		String cp = sc.getContextPath(); // /MVC2 or /
		
		if(!cp.endsWith("/"))
		{
			cp = cp + "/";
		}
		
		while(params.hasMoreElements())
		{
			String paramName = params.nextElement();
			try
			{
				String classPath = config.getInitParameter(paramName);
				Class cls = Class.forName(classPath);
				services.put(cp + paramName, (BackController)cls.newInstance());
			}
			catch(ClassNotFoundException 
					| IllegalAccessException 
					| InstantiationException e)
			{
				e.printStackTrace();
			}
		}
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String uri = request.getRequestURI();
		
		services.get(uri).execute(request, response);
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		doGet(request, response);
	}

}
