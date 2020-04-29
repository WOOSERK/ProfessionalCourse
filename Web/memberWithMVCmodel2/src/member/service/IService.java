package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.exception.MemberException;

public interface IService
{
	void doService(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, MemberException;
}