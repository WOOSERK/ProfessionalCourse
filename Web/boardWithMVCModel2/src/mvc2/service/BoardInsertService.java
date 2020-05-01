package mvc2.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc2.dao.BoardDAO;
import mvc2.vo.BoardVO;

public class BoardInsertService implements IService
{
	BoardDAO dao;
	
	public BoardInsertService()
	{
		dao = new BoardDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
		throws Exception
	{
		String writer = request.getParameter("writer");
		String password = request.getParameter("password");
		String password2 = request.getParameter("password2");
		String title = request.getParameter("title");
		String content = request.getParameter("content");
		
		if(writer == null || writer.trim().equals(""))
		{
			throw new Exception("게시자 이름이 입력되지 않았습니다.");
		}
		
		if(password == null || password.trim().equals(""))
		{
			throw new Exception("비밀번호가 입력되지 않았습니다.");
		}
		
		if(password2 == null || !password2.equals(password))
		{
			throw new Exception("비밀번호와 비밀번호 확인이 일치하지 않습니다.");
		}
		
		if(title == null || title.trim().equals(""))
		{
			throw new Exception("게시글의 제목이 입력되지 않았습니다.");
		}
		
		if(content == null || content.trim().equals(""))
		{
			throw new Exception("게시글의 내용이 작성되지 않았습니다.");
		}
		
		BoardVO b = new BoardVO();
		java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		java.util.Calendar calendar = java.util.Calendar.getInstance();
		String now = sdf.format(calendar.getTime());
		
		b.setWriter(writer);
		b.setPassword(password);
		b.setTitle(title);
		b.setContent(content);
		b.setRegdate(now);
		
		if(dao.insert(b))
		{
			request.setAttribute("board", b);
		}
		else
		{
			throw new Exception("게시물 등록에 실패하였습니다.");
		}
	}
}
