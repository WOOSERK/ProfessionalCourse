<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.vo.BoardVO" %>
<%@ page import="kr.co.wooserk.dao.BoardDAO" %>
<%
	int pageNum = 1;
	try
	{
		pageNum = Integer.parseInt(request.getParameter("page"));
	}
	catch(Exception e) {}
	
	String mode = request.getParameter("mode");
	if(mode == null)
	{
		mode = "";
	}
	
	String condition = request.getParameter("condition");
	if(condition == null)
	{
		condition = "";
	}
	
	String word = request.getParameter("word");
	if(word == null)
	{
		word = "";
	}
	
	int id = 0;
	try
	{
		id = Integer.parseInt(request.getParameter("num"));
	}
	catch(Exception e)
	{
		response.sendRedirect("../error/error.jsp");
	}
	
	BoardVO board = new BoardDAO().getBoard(id);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<table style="margin: 0 auto">
	<tr>
		<th style="width: 100px">메일주소</th>
		<td style="width: 200px"><%=board.getEmail()%></td>
		<th style="width: 100px">작성일자</th>
		<td style="width: 200px"><%=board.getRegdate()%></td>
	</tr>
	<tr>
		<th>조회수</th>
		<td><%=board.getCnt()%></td>
		<th>첨부파일</th>
		<td><%=board.getAttached()%></td>
	</tr>
	<tr>
		<th>제목</th>
		<td colspan="3"><%=board.getTitle()%></td>
	</tr>
	<tr>
		<th>내용</th>
		<td colspan="3"><%=board.getContent()%></td>
	</tr>
</table>
<div style="text-align: center">
	[<a href="../board?type=list">목록보기</a>]
	[편집하기]
</div>
</body>
</html>