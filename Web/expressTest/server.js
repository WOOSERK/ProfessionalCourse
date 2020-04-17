const port = 80;

var express = require('express');
var app = express();
var parser = require('body-parser');


app.listen(port, function()
{
	console.log(port + '번 포트로 서버를 구동하였습니다.');
});

app.use(parser.urlencoded({ extended: false }));
app.use(express.static('.'));

app.post('/board', function(request, response)
{
	let name = request.body.name;
	let age = request.body.age;
	console.log('수신 데이터 : name : ' + name + ', age : ' + age);
	
	if(name != '홍길동')
	{
		response.send({ result: false, message: '이름이 일치하지 않습니다.' });
	}
	else if( age != 20 )
	{
		response.send({ result: false, message: '연령이 일치하지 않습니다.'});
	}
	else
	{
		response.send({ result: true, message: '정상적으로 로그인하였습니다.'});
	}
});

/*// http://localhost/board/3
app.get('/board/:type/:number', function(request, response)
{
	console.log(request.params.type + ' : ' + request.params.number);
	response.send(request.params.type + ' : ' + request.params.number);
});*/