<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="mvc2.service.BoardListService" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>게시판</title>
<link rel="stylesheet" href="../css/board.css"/>
<script src="../js/jquery-3.5.0.min.js"></script>
<script src="../js/pubscript.js"></script>
<script src="../js/board.js"></script>
</head>
<body>
<div class="checkForm">
	<div class="checkBox">
		<ul>
			<li>게시물은 작성자 본인에게만 허용됩니다.</li>
			<li>삭제를 하시려면 비밀번호를 입력하신 후 확인 버튼을 클릭해 주시기를 바랍니다.</li>
			<li><input type="text" id="password" placeholder='삭제하시려면 비밀번호를 입력하세요'></li>
			<li>
				<button type="button" id="btnOk">확인</button>
				<button type="button" id="btnCancel">취소</button>
			</li>			
		</ul>
	</div>
</div>
<div class="viewArea">
	<div class="viewBox">
		<ul>
			<li>작성자</li>
			<li id="writer">홍길동</li>
			<li>작성일자</li>
			<li id="regdate">2020년 05월 01일 11시 30분</li>
		</ul>
		<ul>
			<li>제목</li>
			<li id="title">여기에 제목이 출력됩니다.</li>
		</ul>
		<ul>
			<li>내용</li>
			<li id="content">여기에 내용이 출력됩니다.</li>
		</ul>
		<ul>
			<li>				
				<button type="button" id="btnUpdate">편집하기</button>
				<button type="button" id="btnDelete">삭제하기</button>
				<button type="button" id="btnClose">닫기</button>
			</li>
		</ul>
	</div>
</div>
<div class="inputArea">
	<div class="inputForm">
		<ul>
			<li>작성자</li>
			<li><input type="text" id="writer"></li>
		</ul>
		<ul>
			<li>비밀번호</li>
			<li><input type="password" id="password"></li>
		</ul>
		<ul>
			<li>비밀번호확인</li>
			<li><input type="password" id="password2"></li>
		</ul>
		<ul>
			<li>제목</li>
			<li><input type="text" id="title"></li>
		</ul>
		<ul>
			<li>내용</li>
			<li><textarea id="content"></textarea></li>
		</ul>
		<ul>
			<li>
				<button type="button" id="btnWrite">등록하기</button>
				<button type="button" id="btnCancel">취소하기</button>
			</li>
		</ul>
	</div>
</div>
<div class="wrap">
	<div class="row">
		<div class="container">
			<div class="navi">
				<ul>
					<li>사이트소개</li>
					<li>공지사항</li>
					<li>자유게시판</li>
					<li>묻고답하기</li>
				</ul>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="container">
			<div class="side">
				<div class="loginBox">
					<ul>
						<li>메일주소</li>
						<li><input type="text" name="email" id="email"></li>
					</ul>
					<ul>
						<li>비밀번호</li>
						<li><input type="password" name="password" id="password"></li>
					</ul>
					<ul>
						<li><button id="btnLogin" type="button">로그인</button></li>
						<li><button id="btnRegister" type="button">회원가입</button></li>
					</ul>
				</div>
			</div>
			<div class="main">
				<ul id="head">
					<li>글번호</li>
					<li>작성자</li>
					<li>작성일자</li>
					<li>제목</li>
					<li>조회수</li>
				</ul>
				<ul>
					<li>1</li>
					<li>작성자</li>
					<li>작성일자</li>
					<li>제목</li>
					<li>234</li>
				</ul>
				<ul>
					<li>2</li>
					<li>작성자</li>
					<li>작성일자</li>
					<li>제목</li>
					<li>43</li>
				</ul>
				<ul>
					<li>3</li>
					<li>작성자</li>
					<li>작성일자</li>
					<li>제목</li>
					<li>123</li>
				</ul>
				<ul id="action">
					<li><button type="button" id="btnNew">새글쓰기</button></li>
					<li>
						<button type="button" id="btnFirst">처음</button>
						<button type="button" id="btnPrev">이전</button>
						<button type="button" id="btnNext">다음</button>
						<button type="button" id="btnLast">끝</button>
					</li>
				</ul>				
				<ul id="search">
					<li>						
						&nbsp; 검색조건 &nbsp;						
						<select id="cond">
							<option value="">전체에서</option>
							<option value="<%=BoardListService.CONDITION_TITLE%>">제목에서</option>
							<option value="<%=BoardListService.CONDITION_CONTENT%>">내용에서</option>
						</select>
						&nbsp; 검색단어 &nbsp;
						<input type="text" id="word">
						<button type="button" id="btnSearch">검색</button>
					</li>
				</ul>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="container">
			<div class="footer">
			
			</div>
		</div>
	</div>
</div>
</body>
</html>