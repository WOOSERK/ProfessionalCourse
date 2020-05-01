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
			throw new Exception("�Խ��� �̸��� �Էµ��� �ʾҽ��ϴ�.");
		}
		
		if(password == null || password.trim().equals(""))
		{
			throw new Exception("��й�ȣ�� �Էµ��� �ʾҽ��ϴ�.");
		}
		
		if(password2 == null || !password2.equals(password))
		{
			throw new Exception("��й�ȣ�� ��й�ȣ Ȯ���� ��ġ���� �ʽ��ϴ�.");
		}
		
		if(title == null || title.trim().equals(""))
		{
			throw new Exception("�Խñ��� ������ �Էµ��� �ʾҽ��ϴ�.");
		}
		
		if(content == null || content.trim().equals(""))
		{
			throw new Exception("�Խñ��� ������ �ۼ����� �ʾҽ��ϴ�.");
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
			throw new Exception("�Խù� ��Ͽ� �����Ͽ����ϴ�.");
		}
	}
}
