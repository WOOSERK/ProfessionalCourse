<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="com.oreilly.servlet.MultipartRequest"%>
<%@ page import="com.oreilly.servlet.multipart.DefaultFileRenamePolicy"%>
<%@ page import="org.json.simple.JSONObject"%>
<%@ page import="member.service.MemberUpdateService"%>
<%@ page import="member.vo.MemberVO"%>

<%
	String path = application.getContextPath();

	MultipartRequest multi = new MultipartRequest(request,
			"C:\\JSPWorkspace\\MemberProject\\WebContent\\pictures",
			10 * 1024 * 1024,
			"utf-8",
			new DefaultFileRenamePolicy());
	
	String email = multi.getParameter("email");
	String password = multi.getParameter("password");
	String password2 = multi.getParameter("password2");
	String nick = multi.getParameter("nick");
	String picture = multi.getFilesystemName("picture");
	boolean change = Boolean.parseBoolean(multi.getParameter("change"));
	JSONObject jObj = new JSONObject();
	
	if(email == null || email.trim().equals(""))
	{
		jObj.put("errno", 1);
		jObj.put("message", "메일주소를 입력하지 않았습니다.");
		out.println(jObj.toJSONString());
		return;
	}
	
	MemberVO loginMember = (MemberVO)session.getAttribute("loginUserInfo");
	if(loginMember == null)
	{
		jObj.put("errno", 9);
		jObj.put("message", "로그인 하신 후 사용해주시기 바랍니다.");
		out.println(jObj.toJSONString());
		return;
	}
	
	if(!email.equals(loginMember.getEmail()))
	{
		jObj.put("errno", 10);
		jObj.put("message", "올바르지 않은 처리 요청입니다.");
		out.println(jObj.toJSONString());
		return;
	}
	
	if(password == null || password.trim().equals(""))
	{
		jObj.put("errno", 2);
		jObj.put("message", "비밀번호를 입력하지 않았습니다.");
		out.println(jObj.toJSONString());
		return;
	}
	
	if(password2 == null)
	{
		jObj.put("errno", 3);
		jObj.put("message", "비밀번호 확인을 입력하지 않았습니다.");
		out.println(jObj.toJSONString());
		return;
	}
	else
	{
		if(!password.equals(password2))
		{
			jObj.put("errno", 4);
			jObj.put("message", "비밀번호와 비밀번호 확인이 일치하지 않습니다.");
			out.println(jObj.toJSONString());
		}
	}
	
	if(nick == null || nick.trim().equals(""))
	{
		jObj.put("errno", 5);
		jObj.put("message", "별명을 입력하지 않았습니다.");
		out.println(jObj.toJSONString());
		return;
	}
	
	if(change)
	{
		if(picture != null)
		{
			java.io.File f = multi.getFile("picture");
			if(f.length() == 0)
			{
				f.delete();
				jObj.put("errno", 6);
				jObj.put("message", "비어 있는 파일이 업로드되었습니다.");
				out.println(jObj.toJSONString());
				return;
			}
			String mimeType = multi.getContentType("picture");
			if(!mimeType.startsWith("image"))
			{
				f.delete();
				jObj.put("errno", 7);
				jObj.put("message", "첨부한 파일은 이미지 파일이 아닙니다.");
				out.println(jObj.toJSONString());
				return;
			}
		}
	}
	else
	{
		picture = loginMember.getPicture();
	}
	
	request.setAttribute("email", email);
	request.setAttribute("nick", nick);
	request.setAttribute("password", password);
	request.setAttribute("picture", picture);
	
	try
	{
		MemberUpdateService service = new MemberUpdateService();
		service.doService(request, response);			
		jObj.put("errno", 0);
		jObj.put("message", "회원정보 변경이 완료되었습니다.");
		loginMember.setNick(nick);
		loginMember.setPassword(password);
		loginMember.setPicture(picture);
		out.println(jObj.toJSONString());
	}
	catch(Exception e)
	{
		jObj.put("errno", -1);
		jObj.put("message", e.getMessage());
		out.println(jObj.toJSONString());
	}
%>