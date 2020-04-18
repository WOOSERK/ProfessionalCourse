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

app.get('/members', function(request, response)
{
	conn.query('SELECT * FROM members', function(error, result, fields)
	{
		return response.send(result);
	});

});

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

// 데이터를 가져옴
/*var mysql = require('mysql');

var conn = mysql.createConnection(
{
	host : 'localhost',
	user : 'nodejs',
	password : '1234',
	database : 'nodejs'
});

conn.query('SELECT * FROM members', function(error, result, fields)
{
	if (error)
	{
		console.log('SQL 실행 도중 에러가 발생하였습니다.');
		console.log(error);
	} 
	else
	{

		for(var r of result)
		{
			console.log('메일 : ' + r.email);
			console.log('별명 : ' + r.nick);
			console.log('가입일자 : ' + r.regDate);
			console.log('탈퇴일자 : ' + (r.removeAt == null ? '가입중' : r.removeAt));		
		}
	}
});*/