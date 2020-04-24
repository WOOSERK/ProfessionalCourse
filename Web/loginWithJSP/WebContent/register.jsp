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
	Member m = (Member)request.getAttribute("member");
	if(m == null)
	{
		out.println("회원가입에 실패하였습니다.");
	}
	else
	{
		out.println("다음과 같은 정보로 회원가입이 완료되었습니다.");
		out.println("메일주소 : " + m.getEmail() + "<br/>");
		out.println("별명 : " + m.getNick() + "<br/>");
		out.println("가입일자 : " + m.getRegdate() + "<br/>");
	}
%>
</body>
</html>