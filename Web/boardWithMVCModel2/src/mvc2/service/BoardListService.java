package mvc2.service;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc2.dao.BoardDAO;
import mvc2.vo.BoardVO;

public class BoardListService implements IService
{
	public static final String CONDITION_TITLE = "title";
	public static final String CONDITION_CONTENT = "content";
	public static final int PAGESIZE = 20;
	
	private BoardDAO dao;
	
	public BoardListService()
	{
		dao = new BoardDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response) throws Exception
	{
		String strPage = request.getParameter("page");
		String mode = request.getParameter("mode");
		String cond = request.getParameter("cond");
		String word = request.getParameter("word");
		
		int page = 1;
		try
		{
			if(strPage != null) page = Integer.parseInt(strPage);			
		}
		catch(Exception e) {}
		
		mode = (mode == null) ? "" : mode;
		cond = (cond == null) ? "" : cond;
		word = (word == null) ? "" : word;
		
		int totalRecord = dao.getTotalRecord(cond, word);
		int pageCount = (int)Math.ceil((double)totalRecord / PAGESIZE);
		
		switch(mode)
		{
		case "first":
			page = 1;
			break;
		case "last":
			page = pageCount;
			break;
		case "prev":
			if(--page < 1) page = 1;
			break;
		case "next":
			if(++page > pageCount) page = pageCount;
			break;
		default:
			if(page < 1) page = 1;
			if(page > pageCount) page = pageCount;
		}
		
		ArrayList<BoardVO> boards = dao.getList(page, PAGESIZE, cond, word);
		request.setAttribute("page", page);
		request.setAttribute("cond", cond);
		request.setAttribute("word", word);
		request.setAttribute("pageCount", pageCount);
		request.setAttribute("boards", boards);
	}	
}