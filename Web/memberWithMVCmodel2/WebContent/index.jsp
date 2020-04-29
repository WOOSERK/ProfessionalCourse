<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script src="scripts/jquery-3.5.0.min.js"></script>
<script src="scripts/public.js"></script>
<script src="scripts/index.js"></script>
</head>
<body>
<c:choose>
	<c:when test="${empty loginUserInfo}">
		<form>
			<ul>
				<li>메일주소</li>
				<li><input type="text" name="email"></li>
			</ul>
			<ul>
				<li>비밀번호</li>
				<li><input type="text" name="password"></li>
			</ul>
			<ul>
				<li><button type="button" id="btnLogin">로그인</button>
				<li><button type="button" id="btnRegister">회원가입</button>
			</ul>
		</form>
	</c:when>
	<c:otherwise>
		<form>
			<ul>
				<li>${loginUserInfo.nick}님 좋 하~</li>
			</ul>
			<ul>
				<li><button type="button" id="btnLogout">로그아웃</button></li>
				<li><button type="button" id="btnChangeInfo">정보변경</button></li>
			</ul>
		</form>
	</c:otherwise>
</c:choose>
</body>
</html>