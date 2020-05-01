package mvc2.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc2.dao.BoardDAO;
import mvc2.vo.BoardVO;

public class BoardViewService implements IService
{
	private BoardDAO dao;
	
	public BoardViewService()
	{
		dao = new BoardDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response) throws Exception
	{
		String strId = request.getParameter("id");
		
		int id = Integer.parseInt(strId);
		BoardVO board = dao.getBoard(id);
		request.setAttribute("board", board);	
	}
}