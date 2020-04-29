package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import member.dao.MemberDAO;
import member.exception.MemberException;
import member.vo.MemberVO;

public class LoginService implements IService
{
	private MemberDAO dao;
	
	public LoginService()
	{
		dao = new MemberDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, MemberException
	{
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		MemberVO member = dao.find(email, password);
		HttpSession session = request.getSession();
		session.setAttribute("loginUserInfo", member);
	}
}
