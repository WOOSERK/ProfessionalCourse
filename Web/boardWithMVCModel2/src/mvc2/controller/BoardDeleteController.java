package mvc2.controller;

import java.io.PrintWriter;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONObject;

import mvc2.service.BoardDeleteService;
import mvc2.service.IService;

public class BoardDeleteController implements BackController
{
	private IService service;
	
	public BoardDeleteController()
	{
		service = new BoardDeleteService();
	}
	
	public void execute(HttpServletRequest request, HttpServletResponse response)
	{
		JSONObject jObj = null;
		PrintWriter out = null;
		
		try
		{
			service.doService(request, response);			
			jObj = new JSONObject();
			jObj.put("result", true);
			jObj.put("message", "��û�� ���������� ó���Ǿ����ϴ�.");
		}
		catch(Exception e)
		{
			jObj = new JSONObject();
			jObj.put("result", false);
			jObj.put("message", "�Խñ� ������ �����Ͽ����ϴ�.");
		}
		
		response.setCharacterEncoding("utf-8");
		response.setContentType("application/json");
		
		try
		{
			out = response.getWriter();
			out.print(jObj.toJSONString());
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}