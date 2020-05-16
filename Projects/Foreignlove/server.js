const PORT = 80;
var express = require('express');
var mysql = require('mysql');
var bodyParser = require('body-parser');
var io = require('socket.io')(8080);

io.on('connection', function(socket)
{
	console.log(socket.id);
});

var app = express();
var conn = mysql.createConnection(
{
	host: 'localhost',
	user: 'nodejs',
	password: '1234',
	database: 'nodejs'
});

String.prototype.isEmpty = function()
{
	return (this.trim() == '');
}

app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static('.'));

app.listen(PORT, function()
{
	console.log(PORT + '포트로 서버를 구동하였습니다.');
});

// 회원 목록보기
app.get('/members', function(request, response)
{
	conn.query('SELECT * FROM members', function(error, result, fields)
	{
		return response.send(result);
	});
});

// 회원 등록하기
app.post('/members', function(request, response)
{
	let email = request.body.email;
	let nick = request.body.nick;
	let password = request.body.password;
	
	if (email.isEmpty())
	{
		response.send({ errno: 1, message: '전자메일 주소가 입력되지 않았습니다.'});
		return;
	}
	else if(nick.isEmpty())
	{
		response.send({ errno: 2, message: '별명을 입력하지 않았습니다.'});
		return;
	}
	else if(password.isEmpty())
	{
		response.send({errno: 3, message: '비밀번호가 입력되지 않았습니다.'});
		return;
	}

	let sql = 'INSERT INTO members(email, nick, keyString) VALUES(?, ?, password(?))';
	conn.query(sql, [email, nick, password], function(error)
	{
		if(error)
		{
			response.send({ errno: 9, message: 'SQL오류가 발생하였습니다.'});
			return;
		}
		io.emit('refresh', '회원목록 갱신요망');
		response.send({ errno: 0, message: '회원가입이 정상적으로 처리되었습니다.'})
	});
});

// 회원 삭제하기
app.delete('/members/:email', function(request, response)
{
	let sql = 'UPDATE members SET removeAt = current_timestamp() WHERE email = ?';
	let email = request.body.email;
	
	conn.query(sql, [email], function(error)
	{
		if(error)
		{
			response.send({ errno: 19, message: 'SQL오류가 발생하였습니다.'});
			return;
		}
		io.emit('refresh', '회원목록 갱신요망');
		response.send({ errno: 10, message: email + '의 회원탈퇴가 정상적으로 처리되었습니다.'})
	});
});

// 회원정보변경하기
app.post('/members/:email', function(request, response)
{
	let sql = 'UPDATE members SET nick = ?, keyString = ? WHERE email = ?';
	let nick = request.body.nick;
	let keyString = request.body.ketString;
	
	conn.query(sql, [nick, keyString], function(error)
	{
		if(error)
		{
			response.send({ errno: 19, message: 'SQL오류가 발생하였습니다.'});
			return;
		}
		io.emit('refresh', '회원목록 갱신요망');
		response.send({ errno: 10, message: email + '의 회원탈퇴가 정상적으로 처리되었습니다.'})
	});
});

// 회원정보보기
app.get('/members/:email', function(request, response)
{
	let sql = 'SELECT * FROM members where email = ?';
	let email = request.body.email;
	
	conn.query(sql, [email], function(error, result, fields)
	{
		return response.send(result);
	});
});

// 게시글 목록보기
app.get('/board', function(request, response)
{
	conn.query('SELECT * FROM board limit 20', function(error, result, fields)
	{
		return response.send(result);
	});
});

// 게시글 등록하기
app.get('/board', function(request, response)
{
	let sql = 'INSERT INTO board(b_writer, b_password, b_title, b_contents) VALUES(?, ?, ?, ?)';
	let writer = request.body.b_writer;
	let password = request.body.b_password;
	let title = request.body.b_title;
	let contents = request.body.b_contents;
	
	conn.query(sql, [writer, password, title, contents], function(error)
	{
		if(error)
		{
			response.send({ errno: 19, message: 'SQL오류가 발생하였습니다.'});
			return;
		}
		io.emit('refresh', '회원목록 갱신요망');
		response.send({ errno: 10, message: '게시글이 등록되었습니다.'})
	});
});