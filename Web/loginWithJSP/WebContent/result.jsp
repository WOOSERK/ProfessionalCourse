<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	String result = request.getParameter("result");
	if(result.equals("true"))
	{
		out.println("회원가입에 성공하였습니다.");
	}
	else
	{
		out.println("회원가입에 실패하였습니다.");
	}
%>
</body>
</html>