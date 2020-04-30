package servlet;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/getList")
public class ImageServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String path = "C:\\JSPWorkspace\\MyProject\\WebContent\\images";
		File imgFolder = new File(path);
		File[] files = imgFolder.listFiles();
		
		ArrayList<String> fileList = new ArrayList<>();
		
		for (File f : files)
		{
			if(f.getName().toLowerCase().endsWith("jpg"))
			{
				fileList.add(f.getName());
			}
		}
		
		request.setAttribute("files", fileList);
		RequestDispatcher disp = request.getRequestDispatcher("image.jsp");
		disp.forward(request, response);
	}
}