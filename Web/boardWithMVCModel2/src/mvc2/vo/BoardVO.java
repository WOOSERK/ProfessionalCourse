package mvc2.vo;

import java.util.HashMap;

public class BoardVO
{
	private int id;
	private String writer;
	private String password;
	private String title;
	private String content;
	private String regdate;
	private int cnt;
	
	public BoardVO() {}
	
	public int getId()
	{
		return id;
	}
	
	public void setId(int id)
	{
		this.id = id;
	}
	
	public String getWriter()
	{
		return writer;
	}
	
	public void setWriter(String writer)
	{
		this.writer = writer;
	}
	
	public String getPassword()
	{
		return password;
	}
	
	public void setPassword(String password)
	{
		this.password = password;
	}
	
	public String getTitle()
	{
		return title;
	}
	
	public void setTitle(String title)
	{
		this.title = title;
	}
	
	public String getContent()
	{
		return content;
	}
	
	public void setContent(String content)
	{
		this.content = content;
	}
	
	public String getRegdate()
	{
		return regdate;
	}
	
	public void setRegdate(String regdate)
	{
		this.regdate = regdate;
	}
	public int getCnt()
	{
		return cnt;
	}
	
	public void setCnt(int cnt)
	{
		this.cnt = cnt;
	}

	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		result = prime * result + cnt;
		result = prime * result + ((content == null) ? 0 : content.hashCode());
		result = prime * result + ((writer == null) ? 0 : writer.hashCode());
		result = prime * result + ((password == null) ? 0 : password.hashCode());
		result = prime * result + id;
		result = prime * result + ((regdate == null) ? 0 : regdate.hashCode());
		result = prime * result + ((title == null) ? 0 : title.hashCode());
		return result;
	}

	public boolean equals(Object obj)
	{
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		BoardVO other = (BoardVO) obj;
		if (cnt != other.cnt)
			return false;
		if (content == null)
		{
			if (other.content != null)
				return false;
		} else if (!content.equals(other.content))
			return false;
		if (password == null)
		{
			if (other.password != null)
				return false;
		} else if (!password.equals(other.password))
			return false;
		if (id != other.id)
			return false;
		if (regdate == null)
		{
			if (other.regdate != null)
				return false;
		} else if (!regdate.equals(other.regdate))
			return false;
		if (title == null)
		{
			if (other.title != null)
				return false;
		} else if (!title.equals(other.title))
			return false;
		return true;
	}
	
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		
		sb.append("{ ")
			.append("id: ").append(id).append(", ")
			.append("writer: '").append(writer).append("', ")
			.append("password: '").append(password).append("', ")
			.append("title: '").append(title).append("', ")
			.append("content: '").append(content).append("', ")
			.append("regdate: '").append(regdate).append("', ")
			.append("cnt: ").append(cnt).append(", ")
			.append(" }");
		
		return sb.toString();
	}
	
	public HashMap<String, Object> convertMap()
	{
		HashMap<String, Object> map = new HashMap<>();
		map.put("id", id);
		map.put("writer", writer);
		map.put("password", password);
		map.put("title", title);
		map.put("content", content);
		map.put("regdate", regdate);
		map.put("cnt", cnt);
		return map;
	}
}
