package kr.co.foreignlove.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public interface BackService
{
	public abstract void doService(HttpServletRequest request, HttpServletResponse response);
}
