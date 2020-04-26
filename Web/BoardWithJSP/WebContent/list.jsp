<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.service.BoardService" %>
<%@ page import="kr.co.wooserk.vo.BoardVO" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<ul>
	<li>글번호</li>
	<li>제목</li>
	<li>작성자</li>
	<li>작성일자</li>
</ul>
<%
for(int i=0; i<((ArrayList<BoardVO>)request.getAttribute("list")).size(); i++)
{
	out.println(((ArrayList<BoardVO>)request.getAttribute("list")).get(i).getEmail() + "<br/>");
}
%>
</body>
</html>