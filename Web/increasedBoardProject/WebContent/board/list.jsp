<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.vo.BoardVO"%>
<%@ page import="kr.co.wooserk.dao.BoardDAO"%>
<%@ page import="java.util.ArrayList"%>
<%@ page import="kr.co.wooserk.service.BoardService" %>
<%
	int pageNum = Integer.parseInt(request.getParameter("page"));
	String mode = request.getParameter("mode");
	String condition = request.getParameter("condition");
	String word = request.getParameter("word");
	int totalRow = Integer.parseInt(request.getParameter("totalRow"));
	int totalPage = Integer.parseInt(request.getParameter("totalPage"));
	ArrayList<BoardVO> list = new BoardDAO().getList(pageNum, BoardService.PAGESIZE, condition, word);
%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script src="../js/jquery-3.5.0.min.js"></script>
<script>
	$(document).ready(function()
	{
		$('select[name=condition]').val('<%=condition%>').attr('selected', 'selected');
		$('input[name=word]').val('<%=word%>');
		
		$('#btnSearch').click(function()
		{
			let url = "list.jsp?page=1&mode=";
			url += "&condition=" + $('select[name=condition]>option:selected').val();
			url += "&word=" + $('input[name=word]').val();
			location.href = url;
		});
	});
</script>
</head>
<body>
<div>
	<span style="display: inline-block; width: 800px; margin: 0 auto; text-align: right">
		전체 게시물 수 : <%=totalRow%>
	</span>
</div>
<table style="margin: 0 auto">
	<tr>
		<th style="width: 60px">글번호</th>
		<th style="width: 100px">게시자</th>
		<th style="width: 120px">게시일자</th>
		<th style="width: 460px">제목</th>
		<th style="width: 60px">조회수</th>
	</tr>
	<% for (BoardVO b : list) { %>
	<tr>
		<td style="text-align:center"><%=b.getId()%></td>
		<td style="text-align:center"><%=b.getEmail()%></td>
		<td style="text-align:center"><%=b.getRegdate().substring(0, 10)%></td>
		<td style="text-align:center"><a href="../board?type=view&page=<%=pageNum%>&mode=&condition=<%=condition%>&word=<%=word%>&num=<%=b.getId()%>"><%=b.getTitle()%></a></td>
		<td style="text-align:center"><%=b.getCnt()%></td>		
	</tr>
	<% } %>
</table>
<div>
	<table style="margin: 0 auto">
		<tr>
			<td style="width: 800px; text-align: center">
				<span style="display: inline-block; width: 100px">검색조건</span>
				<select name="condition" style="width: 100px; height: 24px">
					<option value="">전체에서</option>
					<option value="title">제목에서</option>
					<option value="content">내용에서</option>
				</select>
				<span style="display: inline-block; width: 100px">검색단어</span>
				<input type="text" name="word" style="width: 100px; height: 16px">
				<button type="button" id="btnSearch" style="width: 100px; height: 24px">검색하기</button>
			</td>
		</tr>		
	</table>
</div>
<div>
	<table style="margin: 0 auto">
		<tr>
			<td style="width: 400px">
				[새글쓰기]
			</td>			
			<td style="width: 400px; text-align: right">
				[<a href="../board?type=list&page=<%=pageNum%>&mode=first&condition=<%=condition%>&word=<%=word%>&totalPage=<%=totalPage%>&totalRow=<%=totalRow%>">처음</a>]
				[<a href="../board?type=list&page=<%=pageNum%>&mode=prev&condition=<%=condition%>&word=<%=word%>&totalPage=<%=totalPage%>&totalRow=<%=totalRow%>">이전</a>]
			<%
				for (int i=pageNum-2; i<=pageNum+2; i++)
				{
					if(i >= 1 && i <= totalPage)
					{
						out.println(" <a href='list.jsp?page=" + i + "&mode=&condition=" + condition + "&word=" + word + "&totalPage=" + totalPage + "&totalRow=" + totalRow +"'>" + i + "</a> ");
					}
				}
			%>	
				[<a href="../board?type=list&page=<%=pageNum%>&mode=next&condition=<%=condition%>&word=<%=word%>&totalPage=<%=totalPage%>&totalRow=<%=totalRow%>">다음</a>]
				[<a href="../board?type=list&page=<%=pageNum%>&mode=last&condition=<%=condition%>&word=<%=word%>&totalPage=<%=totalPage%>&totalRow=<%=totalRow%>">마지막</a>]			
			</td>
		</tr>		
	</table>
</div>
</body>
</html>