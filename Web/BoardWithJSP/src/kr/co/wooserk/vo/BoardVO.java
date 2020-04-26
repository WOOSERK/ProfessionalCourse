package kr.co.wooserk.vo;

public class BoardVO
{
	private int id;
	private String email;
	private String title;
	private String content;
	private String wdate;
	private String ip;
	
	public BoardVO() {}
	
	public BoardVO(int id, String email, String title, String content, String wdate, String ip)
	{
		this.id = id;
		this.email = email;
		this.title = title;
		this.content = content;
		this.wdate = wdate;
		this.ip = ip;
	}
	
	public int getId()
	{
		return id;
	}
	
	public String getEmail()
	{
		return email;
	}
	
	public String getTitle()
	{
		return title;
	}
	
	public String getContent()
	{
		return content;
	}
	
	public String getWdate()
	{
		return wdate;
	}
	
	public String getIp()
	{
		return ip;
	}
	
	public void setId(int id)
	{
		this.id = id;
	}
	
	public void setEmail(String email)
	{
		this.email = email;
	}
	
	public void setTitle(String title)
	{
		this.title = title;
	}
	
	public void setContent(String content)
	{
		this.content = content;
	}
	
	public void setWdate(String wdate)
	{
		this.wdate = wdate;
	}
	
	public void setIp(String ip)
	{
		this.ip = ip;
	}
	
	public boolean equals(Object o)
	{
		if(o == null) return false;
		if(!(getClass().getName().equals(o.getClass().getName()))) return false;
		
		BoardVO obj = (BoardVO)o;
		
		if(id != obj.id) return false;
		
		if(email != null)
		{
			if(!(email.equals(obj.email))) return false;
		}
		else
		{
			if(obj.email != null) return false;
		}
		
		if(title != null)
		{
			if(!(title.equals(obj.title))) return false;
		}
		else
		{
			if(obj.title != null) return false;
		}
		
		if(content != null)
		{
			if(!(content.equals(obj.content))) return false;
		}
		else
		{
			if(obj.content != null) return false;
		}
		
		if(wdate != null)
		{
			if(!(wdate.equals(obj.wdate))) return false; 
		}
		else
		{
			if(obj.wdate != null) return false;
		}
		
		if(ip != null)
		{
			if(!(ip.equals(obj.ip))) return false;
		}
		else
		{
			if(obj.ip != null) return false;
		}
		
		return true;
	}
	
	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		
		result = prime * result + id;
		result = prime * result + (email == null ? 0 : email.hashCode());
		result = prime * result + (title == null ? 0 : title.hashCode());
		result = prime * result + (content == null ? 0 : content.hashCode());
		result = prime * result + (wdate == null ? 0 : wdate.hashCode());
		result = prime * result + (ip == null ? 0 : ip.hashCode());
		
		return result;
	}
}
