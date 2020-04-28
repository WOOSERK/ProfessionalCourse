<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.dao.BoardDAO"%>
<%@ page import="kr.co.wooserk.vo.BoardVO"%>
<%@ page import="java.util.ArrayList"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%
	BoardDAO dao = new BoardDAO();
	ArrayList<BoardVO> boards = dao.getList(1, 20, "", "");
	pageContext.setAttribute("boards", boards);
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
		<th style="width: 60px">글번호</th>
		<th style="width: 100px">게시자</th>
		<th style="width: 120px">게시일자</th>
		<th style="width: 460px">제목</th>
		<th style="width: 60px">조회수</th>
	</tr>
	<c:forEach var="board" items="${boards}">
	<tr>
		<td>${board.id}</td>
		<td>${board.email}</td>
		<td>${board.regdate}</td>
		<td>${board.title}</td>
		<td>${board.cnt}</td>
	</tr>
	</c:forEach>
</table>
</body>
</html>