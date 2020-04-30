package tag;

import java.io.IOException;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

public class ImageWriter extends SimpleTagSupport
{
	private String dir;
	private String file;
	
	public void setDir(String dir)
	{
		this.dir = dir;
	}
	
	public void setFile(String image)
	{
		this.file = image;
	}
	
	public void doTag() throws JspException, IOException
	{
		JspWriter out = null;
		try
		{
			out = this.getJspContext().getOut();
			out.println("<li><img src='" + dir + "/" + file + "'></li>");
		}
		catch(Exception e)
		{
			throw new JspException("ImageWriter : " + e.getMessage());
		}
	}
}
