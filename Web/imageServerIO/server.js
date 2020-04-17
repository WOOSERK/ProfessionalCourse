const port = 80;
var express = require('express');
var app = express();
var io = require('socket.io')(8080);
var serverImages = ['a.jpg', 'b.jpg', 'c.jpg', 'd.jpg', 'e.jpg'];
var currentImages = ['a.jpg'];

app.listen(port, function()
{
	console.log('hi');
});

app.use(express.static('.'));

io.on('connection', function(socket)
{	
	socket.on('add', function(text)
	{
		for(var val in serverImages)
		{
			if(serverImages[val] == text)
			{
				currentImages.push(serverImages[val]);
				io.emit('addtrue', text);
				return;
			}
		}
		
		io.emit('false', text);
	});
	
	socket.on('del', function(text)
	{
		for(var val in currentImages)
		{
			if(currentImages[val] == text)
			{
				currentImages.splice(val, 1);
				io.emit('deltrue', text);
				return;
			}
		}
		
		io.emit('false', text);
	});
});