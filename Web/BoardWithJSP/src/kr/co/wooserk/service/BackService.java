package kr.co.wooserk.service;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public interface BackService
{
	public void doService(HttpServletRequest request, HttpServletResponse response) throws IOException;
}
