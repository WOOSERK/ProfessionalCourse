package member.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;
import java.util.HashMap;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.service.IService;

@WebServlet("/ServletController")
public class ServletController extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	private HashMap<String, IService> services = new HashMap<>();
	
	public void init(ServletConfig config) throws ServletException
	{
		Enumeration<String> keys = config.getInitParameterNames();
		while(keys.hasMoreElements())
		{
			String key = keys.nextElement();
			String classPath = config.getInitParameter(key);
			try
			{
				Class c = Class.forName(classPath);
				services.put(key, (IService)c.newInstance());
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String uri = request.getRequestURI();
		uri = uri.substring(uri.indexOf("/", 1)+1);
		
		org.json.simple.JSONObject jObj = new org.json.simple.JSONObject();
		
		IService service = services.get(uri);
		if(uri.equals("Login.do"))
		{
			try
			{
				service.doService(request, response);
				jObj.put("errno", 0);
				jObj.put("message", "로그인 성공하였습니..");
			}
			catch(Exception e)
			{
				e.printStackTrace();
				jObj.put("errno", -1);
				jObj.put("message", "로그인 실패하였습니..");
			}
			/*
			 * response.setContentType("application/json");	
			 */
			response.setCharacterEncoding("utf-8");
			PrintWriter out = response.getWriter();
			out.println(jObj.toJSONString());			
		}
		else if(uri.equals("Logout.do"))
		{
			try
			{
				service.doService(request, response);
				jObj.put("errno", 0);
				jObj.put("message", "로그아웃 하였습니..");
			}
			catch(Exception e)
			{
				e.printStackTrace();
				jObj.put("errno", -1);
				jObj.put("message", "로그아웃 실패하였습니..");
			}
			response.setContentType("application/json");
			response.setCharacterEncoding("utf-8");
			PrintWriter out = response.getWriter();
			out.println(jObj.toJSONString());
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		doGet(request, response);
	}
}
