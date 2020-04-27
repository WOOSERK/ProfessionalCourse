package kr.co.wooserk.service;

import java.io.File;
import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.oreilly.servlet.MultipartRequest;
import com.oreilly.servlet.multipart.DefaultFileRenamePolicy;

import kr.co.wooserk.dao.BoardDAO;
import kr.co.wooserk.vo.BoardVO;

public class BoardService implements Service
{
	public static final String CONDITION_TITLE = "title";
	public static final String CONDITION_CONTENT = "content";
	public static final int PAGESIZE = 10;
	private BoardDAO dao = new BoardDAO();

	public String doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{

		if(request.getContentType() == null)
		{
			String type = request.getParameter("type");
			if(type.equals("delete"))
			{
				return delete(request, response);
			}
			else if(type.equals("view"))
			{
				return view(request, response);
			}
			else
			{
				return list(request, response);
			}
		}
		else
		{
			MultipartRequest multi = new MultipartRequest
					(request,
					"C:/JSPWorkspace/AttachedBoardProject/WebContent/upload",
					10 * 1024 * 1024,
					"utf-8",
					new DefaultFileRenamePolicy());
			String type = multi.getParameter("type");
			if(type.equals("insert"))
			{
				return insert(multi);
			}
			else
			{
				return update(multi);
			}
		}
	}

	public String insert(MultipartRequest multi)
	{
		BoardVO board = new BoardVO();
		board.setEmail(multi.getParameter("email"));
		board.setTitle(multi.getParameter("title"));
		board.setContent(multi.getParameter("content"));
		File f = multi.getFile("attached");
		board.setAttached(f.getName());
		
		if(dao.insert(board))
		{
			return "./board/view.jsp?num=" + board.getId();
		}
		else
		{
			return "./error/error.jsp";
		}
	}

	public String delete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		return null;
	}

	public String update(MultipartRequest multi)
	{
		return null;
	}

	public String view(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		int page = 1;
		try
		{
			page = Integer.parseInt(request.getParameter("page"));
		}
		catch(Exception e) {}
		
		String mode = request.getParameter("mode");
		if(mode == null) mode = "";
		
		String condition = request.getParameter("condition");
		if(condition == null) condition = "";
		
		String word = request.getParameter("word");
		if(word == null) word = "";
		
		String num = request.getParameter("num");
		return "board/view.jsp?page=" + page 
				+ "&mode=" + mode 
				+ "&condition=" + condition 
				+ "&word=" + word
				+ "&num=" + num;
	}

	public String list(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		int page = 1;
		try
		{
			page = Integer.parseInt(request.getParameter("page"));
		}
		catch(Exception e) {}
		
		String mode = request.getParameter("mode");
		if(mode == null) mode = "";
		
		String condition = request.getParameter("condition");
		if(condition == null) condition = "";
		
		String word = request.getParameter("word");
		if(word == null) word = "";
		
		int totalRecord = dao.getTotalRecord(condition, word);
		int totalPage = (int)Math.ceil((double)totalRecord / PAGESIZE);
		
		switch(mode)
		{
		case "first":
			page = 1;
			break;
		case "last":
			page = totalPage;
			break;
		case "prev":
			if(--page < 1) page = 1;
			break;
		case "next":
			if(++page > totalPage) page = totalPage;
		}
		
		return "board/list.jsp?page=" + page 
				+ "&mode=" + mode 
				+ "&condition=" + condition 
				+ "&word=" + word
				+ "&totalPage=" + totalPage
				+ "&totalRow=" + totalRecord;
	}
}
