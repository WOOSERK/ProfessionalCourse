package member.vo;

import java.util.HashMap;

public class MemberVO
{
	private String email;
	private String password;
	private String nick;
	private String regdate;
	private String removeAt;
	private String picture;

	public String getEmail()
	{
		return email;
	}

	public void setEmail(String email)
	{
		this.email = email;
	}

	public String getPassword()
	{
		return password;
	}

	public void setPassword(String password)
	{
		this.password = password;
	}

	public String getNick()
	{
		return nick;
	}

	public void setNick(String nick)
	{
		this.nick = nick;
	}

	public String getRegdate()
	{
		return regdate;
	}

	public void setRegdate(String regdate)
	{
		this.regdate = regdate;
	}

	public String getRemoveAt()
	{
		return removeAt;
	}

	public void setRemoveAt(String removeAt)
	{
		this.removeAt = removeAt;
	}

	public String getPicture()
	{
		return picture;
	}

	public void setPicture(String picture)
	{
		this.picture = picture;
	}

	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		result = prime * result + ((email == null) ? 0 : email.hashCode());
		result = prime * result + ((nick == null) ? 0 : nick.hashCode());
		result = prime * result + ((password == null) ? 0 : password.hashCode());
		result = prime * result + ((picture == null) ? 0 : picture.hashCode());
		result = prime * result + ((regdate == null) ? 0 : regdate.hashCode());
		result = prime * result + ((removeAt == null) ? 0 : removeAt.hashCode());
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
		MemberVO other = (MemberVO) obj;
		if (email == null)
		{
			if (other.email != null)
				return false;
		} else if (!email.equals(other.email))
			return false;
		if (nick == null)
		{
			if (other.nick != null)
				return false;
		} else if (!nick.equals(other.nick))
			return false;
		if (password == null)
		{
			if (other.password != null)
				return false;
		} else if (!password.equals(other.password))
			return false;
		if (picture == null)
		{
			if (other.picture != null)
				return false;
		} else if (!picture.equals(other.picture))
			return false;
		if (regdate == null)
		{
			if (other.regdate != null)
				return false;
		} else if (!regdate.equals(other.regdate))
			return false;
		if (removeAt == null)
		{
			if (other.removeAt != null)
				return false;
		} else if (!removeAt.equals(other.removeAt))
			return false;
		return true;
	}
	
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		
		sb.append("{");
		sb.append("email : '" + email + "', ");
		sb.append("password : '" + password + "', ");
		sb.append("nick : '" + nick + "', ");
		sb.append("regdate : '" + regdate + "', ");
		sb.append("remove_at : '" + removeAt + "', ");
		sb.append("picture : '" + picture + "'");
		sb.append("}");
		
		return sb.toString();
	}
	
	public HashMap<String, Object> getMemberMap()
	{
		HashMap<String, Object> map = new HashMap<>();
		
		map.put("email", email);
		map.put("password", password);
		map.put("nick", nick);
		map.put("regdate", regdate);
		map.put("remove_at", removeAt);
		map.put("picture", picture);
		
		return map;
	}
}