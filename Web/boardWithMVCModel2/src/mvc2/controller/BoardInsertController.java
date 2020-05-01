package mvc2.controller;

import java.io.PrintWriter;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONObject;

import mvc2.service.BoardInsertService;
import mvc2.service.IService;
import mvc2.vo.BoardVO;

public class BoardInsertController implements BackController
{
	IService service;
	
	public BoardInsertController()
	{
		service = new BoardInsertService();
	}
	
	public void execute(HttpServletRequest request, HttpServletResponse response)
	{
		JSONObject obj = null;
		
		try
		{
			service.doService(request, response);			
			BoardVO board = (BoardVO)request.getAttribute("board");
			obj = new JSONObject();
			obj.put("result", true);
			obj.put("message", "게시물 등록이 정상적으로 처리되었습니다.");
			obj.put("board", board.convertMap()); // 왜 맵으로 보내
		}
		catch(Exception e)
		{
			obj = new JSONObject();
			obj.put("result", false);
			obj.put("message", e.getMessage());
		}
		
		PrintWriter out = null;
		try
		{
			response.setCharacterEncoding("utf-8");
			response.setContentType("application/json");
			out = response.getWriter();
			out.print(obj.toJSONString());
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
