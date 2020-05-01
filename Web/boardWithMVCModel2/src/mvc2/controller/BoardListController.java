package mvc2.controller;

import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import mvc2.service.BoardListService;
import mvc2.service.IService;
import mvc2.vo.BoardVO;

public class BoardListController implements BackController
{
	IService service;
	
	public BoardListController()
	{
		service = new BoardListService();
	}
	
	@SuppressWarnings("unchecked")
	public void execute(HttpServletRequest request, HttpServletResponse response)
	{
		JSONObject obj = null;
		PrintWriter out = null;
		
		try
		{
			service.doService(request, response);
			obj = new JSONObject();
			obj.put("result", true);
			obj.put("message", "요청이 정상적으로 처리되었습니다.");
			
			int page = (Integer)request.getAttribute("page");
			String cond = (String)request.getAttribute("cond");
			String word = (String)request.getAttribute("word");
			int pageCount = (Integer)request.getAttribute("pageCount");
			ArrayList<BoardVO> boards = (ArrayList<BoardVO>)request.getAttribute("boards");
			
			//{"page":1, "cond":"title",...,"boards":[...]}
			obj.put("page", page);
			obj.put("cond", cond);
			obj.put("word", word);
			obj.put("pageCount", pageCount);
			
			JSONArray jAry = new JSONArray();
			for(BoardVO board : boards)
			{
				JSONObject jTemp = new JSONObject();
				jTemp.putAll(board.convertMap());
				jAry.add(jTemp);
			}
			obj.put("boards", jAry);
		}
		catch(Exception e)
		{
			obj = new JSONObject();
			obj.put("result", false);
			obj.put("message", "게시판 목록 취득에 실패하였습니다.");
		}
		
		response.setCharacterEncoding("utf-8");
		response.setContentType("application/json");
		
		try
		{
			out = response.getWriter();			
			out.print(obj.toJSONString());
		}
		catch(Exception e)
		{
			
		}
	}
}