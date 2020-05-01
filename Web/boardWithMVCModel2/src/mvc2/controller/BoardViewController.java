package mvc2.controller;

import java.io.PrintWriter;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONObject;

import mvc2.service.BoardViewService;
import mvc2.service.IService;
import mvc2.vo.BoardVO;

public class BoardViewController implements BackController
{
	private IService service;
	
	public BoardViewController()
	{
		service = new BoardViewService();
	}
	
	public void execute(HttpServletRequest request, HttpServletResponse response)
	{
		PrintWriter out = null;
		JSONObject jObj = null;
		
		try
		{
			service.doService(request, response);
			BoardVO board = (BoardVO)request.getAttribute("board");
			
			jObj = new JSONObject();
			jObj.put("result", true);
			jObj.put("message", "��û�� ���������� ó���Ǿ����ϴ�.");
			JSONObject jTemp = new JSONObject();
			jTemp.putAll(board.convertMap());
			jObj.put("board", jTemp);
		}
		catch(Exception e)
		{
			jObj = new JSONObject();
			jObj.put("result", false);
			jObj.put("message", "��û ó���� �����Ͽ����ϴ�.");
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