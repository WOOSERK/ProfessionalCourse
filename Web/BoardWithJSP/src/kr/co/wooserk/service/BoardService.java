package kr.co.wooserk.service;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.dao.BoardDAO;
import kr.co.wooserk.vo.BoardVO;

public class BoardService implements BackService
{
	final static int PAGESIZE = 20;
	private BoardDAO dao;
	
	public BoardService()
	{
		dao = new BoardDAO();
	}
	
	public BoardDAO getDao()
	{
		return dao;
	}
	
	public void setDao(BoardDAO dao)
	{
		this.dao = dao;
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		String type = request.getParameter("type");
		
		if(type != null)
		{
			switch(type)
			{
			case "insert":
				insert(request, response);
				break;
			case "delete":
				delete(request, response);
				break;
			case "list":
				getList(request, response);
				break;
			case "view":
				getBoard(request, response);
				break;
			case "update":
				getUpdate(request, response);
			default:
				break;
			}
		}
	}
	
	public void insert(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		
	}
	
	public void delete(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		request.setAttribute("result", dao.delete(new BoardVO()));
	}
	
	public void getList(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		request.setAttribute("list", 
				dao.getList(Integer.parseInt(request.getParameter("page")), 
							PAGESIZE, 
							request.getParameter("cond"), 
							request.getParameter("word")));

		request.setAttribute("dest", "list.jsp");
	}
	
	public void getBoard(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		
	}
	
	public void getUpdate(HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		request.setAttribute("result", "update.jsp");
	}
}
