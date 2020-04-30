package servlet;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

@WebServlet("/getList2")
public class ImageServlet2 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String strPage = request.getParameter("page");
		int intPage = 1;
		if(strPage != null)
		{
			intPage = Integer.parseInt(strPage);
		}

		/*서버에 올릴 때는 이 경로를 바꿔줘야 한다.*/
		String rp = request.getServletContext().getRealPath("/");
	//	String path = rp + "/WebContent/images";
		System.out.println(rp);
		String path = "C:\\JSPWorkspace\\MyProject\\WebContent\\images";
		File imgFolder = new File(path);
		File[] files = imgFolder.listFiles();
		ArrayList<String> list = new ArrayList<>();

		for (File f : files)
		{
			if(f.getName().toLowerCase().endsWith("jpg"))
			{
				list.add(f.getName());
			}
		}
		
		int spos = (intPage - 1) * 10;
		
		ArrayList<String> list2 = new ArrayList<>();
		for(int i=spos; i < list.size() && i < spos + 10; i++)
		{
			list2.add(list.get(i));
		}
		
		JSONArray jAry = new JSONArray();
		jAry.addAll(list2);
		JSONObject jObj = new JSONObject();
		jObj.put("list", jAry);
		
		response.setCharacterEncoding("utf-8");
		response.setContentType("application/json");
		PrintWriter out = response.getWriter();
		out.print(jObj.toJSONString());
	}
}