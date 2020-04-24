<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.vo.Member" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	Member member = (Member)session.getAttribute("member");
%>
<% 	if(member == null)
	{ %>
<form method="post" action="login">
	메일주소<input type="text" name="email" size="50"/><br />
	비밀번호<input type="password" name="password" size="50"/><br />
	<button type="submit">로그인</button>
</form>
<% 	}
	else
	{ %>
로그인 정보<br />	
메일주소 : <%=member.getEmail()%>
별명 : <%=member.getNick()%>
가입일자 : <%=member.getRegdate()%>
<%	} %>
</body>
</html>