const PORT = 80;
var express = require('express');
var mysql = require('mysql');
var bodyParser = require('body-parser');
var io = require('socket.io')(8080);

io.on('connection', function(socket)
{
	console.log(socket.id + '의 접속');
});

var app = express();
var conn = mysql.createConnection(
{
	host: 'localhost',
	user: 'nodejs',
	password: '1234',
	database: 'nodejs'
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static('.'));

app.listen(PORT, function()
{
	console.log(PORT + '번 포트로 서버를 구동하였습니다.');
});

app.get('/board', function(request, response)
{
	conn.query('SELECT * FROM board', function(error, result, fields)
	{
		return response.send(result);
	});
});

app.post('/board', function(request, response)
{
	let sql = 'INSERT INTO board(b_writer, b_password, b_title, b_contents) VALUES(?, ?, ?, ?)'
	let writer = request.body.b_writer;
	let password = request.body.b_password;
	let title = request.body.b_title;
	let contents = request.body.b_contents;
	
	conn.query(sql, [writer, password, title, contents], function(error)
	{
		if(error)
		{
			response.send({ errno: 10, message: '게시글 등록에 실패하였습니다.'});
		}
		io.emit('refresh', '게시글 목록 갱신 요청');
		response.send({ errno: 0, message: '게시글 등록에 성공하였습니다.'});
	});
});