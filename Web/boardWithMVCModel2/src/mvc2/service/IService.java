package mvc2.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public interface IService
{
	public abstract void doService(HttpServletRequest request, HttpServletResponse response)
		throws Exception;
}
