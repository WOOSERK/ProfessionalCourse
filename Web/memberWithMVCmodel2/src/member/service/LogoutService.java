package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import member.exception.MemberException;

public class LogoutService implements IService
{
	public void doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, MemberException
	{
		HttpSession session = request.getSession(false);
		if(session != null)
		{
			session.invalidate();
		}
	}
}
