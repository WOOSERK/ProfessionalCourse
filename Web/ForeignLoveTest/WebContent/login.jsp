<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="kr.co.foreignlove.vo.MemberVO" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%=session.getAttribute("id") %>
<%
	if(session.getAttribute("id") != null)
	{
		request.getAttribute("result");%>님 어서오세요.
<%	}
	else
	{%>
	<form method="get" action="login"> 
		<div>아이디<input type="text" name="id"></div>
		<div>비밀번호<input type="text" name="pass"></div>	
		<button type="submit">제출</button>
	</form>
	
<%	}%>

</body>
</html>