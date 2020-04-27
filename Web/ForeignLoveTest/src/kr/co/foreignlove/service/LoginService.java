package kr.co.foreignlove.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import kr.co.foreignlove.dao.MemberDAO;
import kr.co.foreignlove.vo.MemberVO;

public class LoginService implements BackService
{
	private MemberDAO dao;
	
	public LoginService()
	{
		dao = new MemberDAO();
	}
	
	public MemberDAO getDao()
	{
		return dao;
	}
	
	public void setDao(MemberDAO dao)
	{
		this.dao = dao;
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
	{
		String id = request.getParameter("id");
		String pass = request.getParameter("pass");
		
		MemberVO member = dao.find(id, pass);
		
		if(member != null)
		{
			HttpSession session = request.getSession();
			session.setAttribute("id", id);
			request.setAttribute("result", member);
		}
		
		request.setAttribute("dest", "login.jsp");
	}
}
