package mvc2.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc2.dao.BoardDAO;

public class BoardDeleteService implements IService
{
	private BoardDAO dao;
	
	public BoardDeleteService()
	{
		dao = new BoardDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response) throws Exception
	{
		String strId = request.getParameter("id");
		String password = request.getParameter("password");
		
		int id = Integer.parseInt(strId);
		boolean result = dao.delete(id, password);
		if(!result)
		{
			throw new Exception("게시글 삭제에 실패하였습니다.");
		}
	}
}
